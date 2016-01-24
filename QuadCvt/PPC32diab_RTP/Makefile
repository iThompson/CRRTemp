# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC32diab_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/git/QuadCvt



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCEH:rtp
LIBPATH = 
LIBS = -lstlstd

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO 
DEBUGFLAGS_C++-Compiler = -XO 
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO 
endif


#Project Targets
PROJECT_TARGETS = QuadCvt/$(MODE_DIR)/QuadCvt.vxe


#Rules

# QuadCvt
ifeq ($(DEBUG_MODE),1)
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
QuadCvt/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO 
endif
QuadCvt/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
QuadCvt/$(MODE_DIR)/% : IDE_LIBRARIES = 
QuadCvt/$(MODE_DIR)/% : IDE_DEFINES = 
QuadCvt/$(MODE_DIR)/% : PROJECT_TYPE = RTP
QuadCvt/$(MODE_DIR)/% : DEFINES = 
QuadCvt/$(MODE_DIR)/% : DO_STRIP = 0
QuadCvt/$(MODE_DIR)/% : EXPAND_DBG = 0
QuadCvt/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
QuadCvt/$(MODE_DIR)/% : CPU = PPC32
QuadCvt/$(MODE_DIR)/% : TOOL_FAMILY = diab
QuadCvt/$(MODE_DIR)/% : TOOL = diab
QuadCvt/$(MODE_DIR)/% : TOOL_PATH = 
QuadCvt/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCEH:rtp
QuadCvt/$(MODE_DIR)/% : LIBPATH = 
QuadCvt/$(MODE_DIR)/% : LIBS = -lstlstd
QuadCvt/$(MODE_DIR)/% : OBJ_DIR := QuadCvt/$(MODE_DIR)

QuadCvt/$(MODE_DIR)/Objects/QuadCvt/Cvt.o : $(PRJ_ROOT_DIR)/Cvt.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_QuadCvt = QuadCvt/$(MODE_DIR)/Objects/QuadCvt/Cvt.o

QuadCvt/$(MODE_DIR)/QuadCvt.vxe : $(OBJECTS_QuadCvt)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dplus $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xansi -Xforce-declarations  -Xmake-dependency=0xd  -o "$@" $(OBJECTS_QuadCvt) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(WIND_BASE)/target/usr/lib/ppc/PPC32/common $(ADDED_LIBPATH) $(ADDED_LIBS)   && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && stripppc -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

QuadCvt/$(MODE_DIR)/QuadCvt_compile_file : $(FILE) ;

_clean :: QuadCvt/$(MODE_DIR)/QuadCvt_clean

QuadCvt/$(MODE_DIR)/QuadCvt_clean : 
	$(TRACE_FLAG)if [ -d "QuadCvt" ]; then cd "QuadCvt"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := QuadCvt/$(MODE_DIR)/Objects/QuadCvt/Cvt.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
