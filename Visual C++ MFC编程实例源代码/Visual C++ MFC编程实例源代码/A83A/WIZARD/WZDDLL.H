/* WzdDll.h : Non-MFC Dll
 *
 *************************************************************/

#if !defined WZDDLL_H
#define WZDDLL_H

#ifdef __cplusplus
extern "C" {
#else
#endif  /* __cplusplus */


#ifdef WZDDLL_BLD
#define DLL __declspec( dllexport )
#else
#define DLL
#endif

void DLL WzdMessageBox(LPSTR pszString);
void DLL DestroyWzdWindow(HWND hWnd);
void DLL WzdFunc3(BOOL b);

#ifdef __cplusplus
}
#endif

#endif
