# Microsoft Developer Studio Generated NMAKE File, Based on WzdDMFC.dsp
!IF "$(CFG)" == ""
CFG=WzdDllMFC - Win32 Debug
!MESSAGE No configuration specified. Defaulting to WzdDllMFC - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WzdDllMFC - Win32 Release" && "$(CFG)" != "WzdDllMFC - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WzdDMFC.mak" CFG="WzdDllMFC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WzdDllMFC - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WzdDllMFC - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WzdDllMFC - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\WzdDMFC.dll"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WzdDMFC.obj"
	-@erase "$(INTDIR)\WzdDMFC.pch"
	-@erase "$(INTDIR)\WzdDMFC.res"
	-@erase "$(INTDIR)\WzdDMFCx.obj"
	-@erase "$(OUTDIR)\WzdDMFC.dll"
	-@erase "$(OUTDIR)\WzdDMFC.exp"
	-@erase "$(OUTDIR)\WzdDMFC.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\WzdDMFC.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\WzdDMFC.pdb" /machine:I386 /def:".\WzdDMFC.def" /out:"$(OUTDIR)\WzdDMFC.dll" /implib:"$(OUTDIR)\WzdDMFC.lib" 
DEF_FILE= \
	".\WzdDMFC.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WzdDMFC.obj" \
	"$(INTDIR)\WzdDMFCx.obj" \
	"$(INTDIR)\WzdDMFC.res"

"$(OUTDIR)\WzdDMFC.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WzdDllMFC - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\WzdDMFC.dll"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WzdDMFC.obj"
	-@erase "$(INTDIR)\WzdDMFC.pch"
	-@erase "$(INTDIR)\WzdDMFC.res"
	-@erase "$(INTDIR)\WzdDMFCx.obj"
	-@erase "$(OUTDIR)\WzdDMFC.dll"
	-@erase "$(OUTDIR)\WzdDMFC.exp"
	-@erase "$(OUTDIR)\WzdDMFC.ilk"
	-@erase "$(OUTDIR)\WzdDMFC.lib"
	-@erase "$(OUTDIR)\WzdDMFC.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\WzdDMFC.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\WzdDMFC.pdb" /debug /machine:I386 /def:".\WzdDMFC.def" /out:"$(OUTDIR)\WzdDMFC.dll" /implib:"$(OUTDIR)\WzdDMFC.lib" /pdbtype:sept 
DEF_FILE= \
	".\WzdDMFC.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WzdDMFC.obj" \
	"$(INTDIR)\WzdDMFCx.obj" \
	"$(INTDIR)\WzdDMFC.res"

"$(OUTDIR)\WzdDMFC.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
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
!IF EXISTS("WzdDMFC.dep")
!INCLUDE "WzdDMFC.dep"
!ELSE 
!MESSAGE Warning: cannot find "WzdDMFC.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WzdDllMFC - Win32 Release" || "$(CFG)" == "WzdDllMFC - Win32 Debug"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "WzdDllMFC - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\WzdDMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WzdDllMFC - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /Fp"$(INTDIR)\WzdDMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\WzdDMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WzdDMFC.cpp

"$(INTDIR)\WzdDMFC.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WzdDMFC.pch"


SOURCE=.\WzdDMFC.rc

"$(INTDIR)\WzdDMFC.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\WzdDMFCx.cpp

"$(INTDIR)\WzdDMFCx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WzdDMFC.pch"



!ENDIF 

