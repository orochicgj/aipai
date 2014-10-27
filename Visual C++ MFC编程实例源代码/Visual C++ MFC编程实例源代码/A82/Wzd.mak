# Microsoft Developer Studio Generated NMAKE File, Based on Wzd.dsp
!IF "$(CFG)" == ""
CFG=Wzd - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Wzd - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Wzd - Win32 Release" && "$(CFG)" != "Wzd - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Wzd.mak" CFG="Wzd - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Wzd - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Wzd - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Wzd - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Wzd.lib"


CLEAN :
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Wzdstat.obj"
	-@erase "$(OUTDIR)\Wzd.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\Wzd.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Wzd.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Wzd.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Wzdstat.obj"

"$(OUTDIR)\Wzd.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Wzd - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Wzd.lib"


CLEAN :
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Wzdstat.obj"
	-@erase "$(OUTDIR)\Wzd.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\Wzd.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Wzd.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Wzd.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Wzdstat.obj"

"$(OUTDIR)\Wzd.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Wzd.dep")
!INCLUDE "Wzd.dep"
!ELSE 
!MESSAGE Warning: cannot find "Wzd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Wzd - Win32 Release" || "$(CFG)" == "Wzd - Win32 Debug"
SOURCE=.\Wzdstat.c

"$(INTDIR)\Wzdstat.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

