#ifndef _VOLUME_H
#define _VOLUME_H

#include <CGAL/basic.h>
#include <CGAL/Object.h>
#include <CGAL/Timer.h>


#include "surface.h"
#include "binary_image.h"

#include <boost/multi_array.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/format.hpp>

#include <queue>
#include <vector>
#include <iterator> // std::back_inserter

#include <QString>
#include <QFileInfo>

class QTreeWidgetItem;

// kernel
// #include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel1;

#include <CGAL/Point_with_psc_localisation.h>
struct Kernel : public Kernel1 {
  typedef CGAL::Point_with_psc_localisation<Kernel::Point_3,
                                            const QTreeWidgetItem*> Point_3;
};

typedef Kernel::FT FT;
typedef Kernel::Point_3 Point;
typedef Kernel::Sphere_3 Sphere;
typedef Kernel::Vector_3 Vector;
typedef Kernel::Triangle_3 Triangle_3;
typedef Kernel::Segment_3 Segment_3;

typedef CGAL::Triple<Triangle_3,Vector,const QTreeWidgetItem*> Facet;

typedef CBinary_image_3<FT,Point> Binary_image;

// surface mesher
// #define CGAL_MESHES_NO_OUTPUT
#define CGAL_SURFACE_MESHER_VERBOSE
#include <CGAL/Surface_mesh_vertex_base_3.h>
#include <CGAL/Surface_mesh_cell_base_3.h>
#include <CGAL/Triangulation_cell_base_with_circumcenter_3.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/Surface_mesh_complex_2_in_triangulation_3.h>
#include <CGAL/Surface_mesh_default_criteria_3.h>
#include <CGAL/make_surface_mesh.h>
#include <CGAL/Implicit_surface_3.h>
#include <CGAL/Surface_mesh_traits_generator_3.h>
typedef CGAL::Surface_mesh_vertex_base_3<Kernel> Vb;
typedef CGAL::Surface_mesh_cell_base_3<Kernel> Cb;
typedef CGAL::Triangulation_cell_base_with_circumcenter_3<Kernel, Cb> Cb2;
typedef CGAL::Triangulation_data_structure_3<Vb, Cb2> Tds;
typedef CGAL::Delaunay_triangulation_3<Kernel, Tds> Tr;
typedef CGAL::Surface_mesh_complex_2_in_triangulation_3<Tr> C2t3;
typedef CGAL::Implicit_surface_3<Kernel, Binary_image> Surface_3;

#include <mc/MarchingCubes.h>

class MainWindow;
class QDoubleSpinBox;
class Viewer;
class Isovalues_list;

class Volume : public Surface
{
  Q_OBJECT
public:
  Volume(MainWindow* mw);
  ~Volume() {}

private:
  Binary_image m_image;

  // options
  FT m_sm_angle;
  FT m_sm_radius;
  FT m_sm_distance;
  double m_relative_precision;

  // visualization
  bool m_view_surface;
  bool m_view_mc;
  bool m_draw_triangulation;
  QColor m_triangulation_color;
  bool m_inverse_normals;
  bool two_sides;
  bool draw_triangles_edges;
  bool use_gouraud;

  std::vector<Facet> m_surface;
  std::vector<Facet> m_surface_mc;
  MarchingCubes<unsigned char> mc ;
  std::vector<int> nbs_of_mc_triangles;
  Tr del;            // 3D-Delaunay triangulation
  C2t3 c2t3;         // 2D complex in 3D triangulation

  MainWindow* mw;
  QFileInfo fileinfo;
  Isovalues_list* isovalues_list;
  QDoubleSpinBox* spinBox_radius_bound;
  QDoubleSpinBox* spinBox_distance_bound;

  GLuint list_draw_marching_cube;
  bool list_draw_marching_cube_is_valid;
  std::vector<GLuint> lists_draw_surface;
  bool lists_draw_surface_is_valid;
  std::vector<GLuint> lists_draw_surface_mc;
  bool lists_draw_surface_mc_is_valid;

  CGAL::Timer sm_timer;
  CGAL::Timer mc_timer;
  int sm_total_time;
  int mc_total_time;
private:
  template <typename Iterator>
  void gl_draw_surface(Iterator begin, Iterator end, const QTreeWidgetItem* = 0);

  template <typename PointsOutputIterator, typename TransformOperator>
  void search_for_connected_components(PointsOutputIterator, TransformOperator);

public:
  void gl_draw_surface();
  void gl_draw_surface_mc();
  void gl_draw_marchingcube();
private:
  void gl_draw_one_marching_cube_vertex(int);

signals:
void new_bounding_box(double, double, double, double, double, double);

public slots:
  void set_inverse_normals(const bool);
  void set_two_sides(const bool);
  void set_draw_triangles_edges(const bool);
  void set_triangulation_edges_color();
  void set_draw_triangulation(const bool);
  void set_use_gouraud(const bool);
  void open(const QString& filename);
#ifdef CGAL_USE_VTK
  void open_vtk(const QString& filename);
#endif
  void opendir(const QString& dirname);
  void finish_open();
  void export_off();
  void check_can_export_off();
  void draw();
  void get_bbox(float& /*xmin*/, float& /*ymin*/, float& /*zmin*/,
		float& /*xmax*/, float& /*ymax*/, float& /*zmax*/) {}
  void close() {}
  void display_marchin_cube();
  void display_surface_mesher_result();
  void set_radius_bound(double);
  void set_distance_bound(double);
  void changed_parameters();
private:
  void status_message(QString);
  void busy() const;
  void not_busy() const;
};

template <typename PointsOutputIterator, typename TransformOperator>
void Volume::search_for_connected_components(PointsOutputIterator it, TransformOperator transform)
{
  const unsigned int nx = m_image.xdim();
  const unsigned int ny = m_image.ydim();
  const unsigned int nz = m_image.zdim();

  typedef unsigned char Marker;
  typedef typename TransformOperator::result_type Label;

  boost::multi_array<Marker, 3> visited(boost::extents[nx][ny][nz]);
  typedef boost::tuple<int, int, int> Indices;
  typedef std::queue<Indices> Indices_queue;
  typedef std::vector<Indices> Border_vector;

  int number_of_connected_components = 0;
  for(unsigned int i=0;i<nx;i++)
    for(unsigned int j=0;j<ny;j++)
      for(unsigned int k=0;k<nz;k++)
      {
        if(visited[i][j][k]>0)
          continue;
        const Label current_label = transform(m_image.value(i, j, k));
        if(current_label == Label()) {
          visited[i][j][k] = 3;
          continue;
        }

        // if we reach here, (i, j, k) is a new connected component
        ++number_of_connected_components;
        std::cerr << boost::format("Found new connected component (#%5%) "
                                   "at voxel (%1%, %2%, %3%), value=%4%, volume id=%6%\n")
          % i % j % k
          % m_image.value(i, j, k) 
          % number_of_connected_components
          % (int)current_label;

        int nb_voxels = 0;

        Indices_queue queue;
        Indices indices(i, j ,k);
        queue.push(indices);

        Border_vector border;

        /*
         * First pass is a BFS to retrieve all the connected component, and
         * its border.
         * Second pass is a BFS initialized with all voxel of the border.
         * The last voxel of that BFS is used as the seed.
         */
        int pass = 1; // pass will be equal to 2 in second pass

        Indices bbox_min = indices;
        Indices bbox_max = indices;

        while(!queue.empty()) // walk through the connected component
        {
          Indices indices = queue.front();
          queue.pop();

          // warning: those indices i, j and k are local to the while loop
          const int i = boost::get<0>(indices);
          const int j = boost::get<1>(indices);
          const int k = boost::get<2>(indices);

          if(visited[i][j][k] < pass)
          {
            visited[i][j][k] = pass;
            if(pass == 1 )
            {
              ++nb_voxels;
              boost::get<0>(bbox_min) = (std::min)(i, boost::get<0>(bbox_min));
              boost::get<0>(bbox_max) = (std::max)(i, boost::get<0>(bbox_max));
              boost::get<1>(bbox_min) = (std::min)(j, boost::get<1>(bbox_min));
              boost::get<1>(bbox_max) = (std::max)(j, boost::get<1>(bbox_max));
              boost::get<2>(bbox_min) = (std::min)(k, boost::get<2>(bbox_min));
              boost::get<2>(bbox_max) = (std::max)(k, boost::get<2>(bbox_max));
            }

            static const int neighbors_offset[6][3] = { { +1,  0,  0 },
                                                        { -1,  0,  0 },
                                                        {  0, +1,  0 },
                                                        {  0, -1,  0 },
                                                        {  0,  0, +1 },
                                                        {  0,  0, -1 } };
            bool voxel_is_on_border = false;

            // Visit neighbors.
            // (i_n, j_n, k_n) are indices of neighbors.
            for(int n = 0; n < 6; ++n)
            {
              const int i_n = i + neighbors_offset[n][0];
              const int j_n = j + neighbors_offset[n][1];
              const int k_n = k + neighbors_offset[n][2];
              if(i_n < 0 || i_n >= static_cast<int>(nx) ||
                 j_n < 0 || j_n >= static_cast<int>(ny) ||
                 k_n < 0 || k_n >= static_cast<int>(nz))
              {
                voxel_is_on_border = true;
                continue;
              }
              else
              {
                if(transform(m_image.value(i_n, j_n, k_n)) == current_label)
                {
                  if(visited[i_n][j_n][k_n] < pass) {
                    Indices indices(i_n, j_n, k_n);
                    queue.push(indices);
                  }
                }
                else
                  voxel_is_on_border = true;
              }
            } // end for neighbors

            if(pass == 1 && voxel_is_on_border)
              border.push_back(indices);
          } // end if voxel not already visited

          if(queue.empty()) {
            if(pass == 1)
            { // End of first pass. Begin second pass with the voxels of
              // the border.
              for(typename Border_vector::const_iterator
                    border_it = border.begin(), border_end = border.end();
                  border_it != border_end; ++border_it)
                queue.push(*border_it);
              pass = 2;
            }
            else // end of second pass, return the last visited voxel
            {
              *it++ = m_image.point(i, j, k);
              std::cerr << boost::format("Found seed %5%, which is voxel (%1%, %2%, %3%), value=%4%\n")
                % i % j % k %  m_image.value(i, j, k) % m_image.point(i, j, k);
            }
          } // end if queue.empty()
        } // end while !queue.empty() (with local indices i, j, k)

        std::cerr << boost::format("There was %1% voxel(s) in that component.\n"
                                   "The bounding box is (%2% %3% %4%, %5% %6% %7%).\n"
                                   "%8% voxel(s) on border\n")
          % nb_voxels
          % boost::get<0>(bbox_min) % boost::get<1>(bbox_min) % boost::get<2>(bbox_min)
          % boost::get<0>(bbox_max) % boost::get<1>(bbox_max) % boost::get<2>(bbox_max)
          % border.size();
      } // end for i,j,k
} // end function Volume::search_for_connected_components()

#endif // _VOLUME_H
