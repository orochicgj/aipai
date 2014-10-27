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
!MESSAGE "Wzd - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Wzd - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Wzd - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Wzd.exe"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Wzd.obj"
	-@erase "$(INTDIR)\Wzd.pch"
	-@erase "$(INTDIR)\Wzd.res"
	-@erase "$(INTDIR)\WzdDoc.obj"
	-@erase "$(INTDIR)\WzdTlBar.obj"
	-@erase "$(INTDIR)\WzdView.obj"
	-@erase "$(OUTDIR)\Wzd.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Wzd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Wzd.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Wzd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Wzd.pdb" /machine:I386 /out:"$(OUTDIR)\Wzd.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Wzd.obj" \
	"$(INTDIR)\WzdDoc.obj" \
	"$(INTDIR)\WzdTlBar.obj" \
	"$(INTDIR)\WzdView.obj" \
	"$(INTDIR)\Wzd.res"

"$(OUTDIR)\Wzd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Wzd - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Wzd.exe"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\Wzd.obj"
	-@erase "$(INTDIR)\Wzd.pch"
	-@erase "$(INTDIR)\Wzd.res"
	-@erase "$(INTDIR)\WzdDoc.obj"
	-@erase "$(INTDIR)\WzdTlBar.obj"
	-@erase "$(INTDIR)\WzdView.obj"
	-@erase "$(OUTDIR)\Wzd.exe"
	-@erase "$(OUTDIR)\Wzd.ilk"
	-@erase "$(OUTDIR)\Wzd.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Wzd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Wzd.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Wzd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Wzd.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Wzd.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Wzd.obj" \
	"$(INTDIR)\WzdDoc.obj" \
	"$(INTDIR)\WzdTlBar.obj" \
	"$(INTDIR)\WzdView.obj" \
	"$(INTDIR)\Wzd.res"

"$(OUTDIR)\Wzd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Wzd.dep")
!INCLUDE "Wzd.dep"
!ELSE 
!MESSAGE Warning: cannot find "Wzd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Wzd - Win32 Release" || "$(CFG)" == "Wzd - Win32 Debug"
SOURCE=.\ChildFrm.cpp

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Wzd - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Wzd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Wzd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Wzd - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\Wzd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Wzd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Wzd.cpp

"$(INTDIR)\Wzd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"


SOURCE=.\Wzd.rc

"$(INTDIR)\Wzd.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\WzdDoc.cpp

"$(INTDIR)\WzdDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"


SOURCE=.\WzdTlBar.cpp

"$(INTDIR)\WzdTlBar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"


SOURCE=.\WzdView.cpp

"$(INTDIR)\WzdView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Wzd.pch"



!ENDIF 

