BASEDIR =.

include $(ROOT)/include/make/comdef.mak

BASENAME = simple
INSTALLDIR0 = $(BINDIR)
CPPSOURCES = $(BASENAME).C
CPPSOURCES+= $(BASEDIR)/../../../include/CGAL/Bench_option_parser.C
CPPSOURCES+= $(BASEDIR)/../../../include/CGAL/Bench.C
TARGET0 = $(BASENAME)

LCPPINCS = -I$(BASEDIR)/../../../include
LCPPINCS+= -I$(CGALROOT)/include
LCPPINCS+= -I$(CGALROOT)/include/CGAL/config/i686_Linux-2.6_g++-3.3.5
LCPPINCS+= $(CGALINCS)

LLDLIBS = -lboost_program_options

include $(MAKEINCDIR)/basedir.mak
include $(MAKEINCDIR)/comrul.mak
include $(MAKEINCDIR)/bison.mak
include $(MAKEINCDIR)/comp.mak
include $(MAKEINCDIR)/targlink.mak
