// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       :
// release_date  :
// 
// file          : include/CGAL/Arithmetic_filter/predicates/sign_of_determinant.h
// package       : Interval_arithmetic
// author(s)     : Sylvain Pion <Sylvain.Pion@sophia.inria.fr>
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec@sophia.inria.fr>)
// ======================================================================

// This file is automatically generated by the script
// examples/Interval_arithmetic/filtered_predicate_converter.

#ifndef CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H
#define CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant2x2(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11)
{
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant2x2(
		a00.interval(),
		a01.interval(),
		a10.interval(),
		a11.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant2x2(
		a00.exact(),
		a01.exact(),
		a10.exact(),
		a11.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant3x3(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22)
{
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant3x3(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant3x3(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant4x4(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33)
{
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant4x4(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant4x4(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant5x5(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a04,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a14,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a24,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a34,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a40,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a41,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a42,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a43,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a44)
{
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant5x5(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant5x5(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant6x6(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a04,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a05,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a14,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a15,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a24,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a25,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a34,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a35,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a40,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a41,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a42,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a43,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a44,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a45,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a50,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a51,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a52,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a53,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a54,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a55)
{
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant6x6(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a05.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a15.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a25.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a35.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval(),
		a45.interval(),
		a50.interval(),
		a51.interval(),
		a52.interval(),
		a53.interval(),
		a54.interval(),
		a55.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant6x6(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a05.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a15.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a25.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a35.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact(),
		a45.exact(),
		a50.exact(),
		a51.exact(),
		a52.exact(),
		a53.exact(),
		a54.exact(),
		a55.exact());
  }
}

CGAL_END_NAMESPACE

#endif // CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H
