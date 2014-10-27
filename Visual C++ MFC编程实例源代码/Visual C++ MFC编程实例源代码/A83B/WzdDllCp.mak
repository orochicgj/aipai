# Microsoft Developer Studio Generated NMAKE File, Based on WzdDllCp.dsp
!IF "$(CFG)" == ""
CFG=WzdDllCpp - Win32 Debug
!MESSAGE No configuration specified. Defaulting to WzdDllCpp - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WzdDllCpp - Win32 Release" && "$(CFG)" != "WzdDllCpp - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WzdDllCp.mak" CFG="WzdDllCpp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WzdDllCpp - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WzdDllCpp - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "WzdDllCpp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\WzdDllCp.dll"


CLEAN :
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WzdDllCp.obj"
	-@erase "$(OUTDIR)\WzdDllCp.dll"
	-@erase "$(OUTDIR)\WzdDllCp.exp"
	-@erase "$(OUTDIR)\WzdDllCp.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\WzdDllCp.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDllCp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\WzdDllCp.pdb" /machine:I386 /out:"$(OUTDIR)\WzdDllCp.dll" /implib:"$(OUTDIR)\WzdDllCp.lib" 
LINK32_OBJS= \
	"$(INTDIR)\WzdDllCp.obj"

"$(OUTDIR)\WzdDllCp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WzdDllCpp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\WzdDllCp.dll"


CLEAN :
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WzdDllCp.obj"
	-@erase "$(OUTDIR)\WzdDllCp.dll"
	-@erase "$(OUTDIR)\WzdDllCp.exp"
	-@erase "$(OUTDIR)\WzdDllCp.ilk"
	-@erase "$(OUTDIR)\WzdDllCp.lib"
	-@erase "$(OUTDIR)\WzdDllCp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "WZDDLL_BLD" /Fp"$(INTDIR)\WzdDllCp.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WzdDllCp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\WzdDllCp.pdb" /debug /machine:I386 /out:"$(OUTDIR)\WzdDllCp.dll" /implib:"$(OUTDIR)\WzdDllCp.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\WzdDllCp.obj"

"$(OUTDIR)\WzdDllCp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("WzdDllCp.dep")
!INCLUDE "WzdDllCp.dep"
!ELSE 
!MESSAGE Warning: cannot find "WzdDllCp.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WzdDllCpp - Win32 Release" || "$(CFG)" == "WzdDllCpp - Win32 Debug"
SOURCE=.\WzdDllCp.cpp

!IF  "$(CFG)" == "WzdDllCpp - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\WzdDllCp.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\WzdDllCp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WzdDllCpp - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "WZDDLL_BLD" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\WzdDllCp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

