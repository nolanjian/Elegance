// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GLTF_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GLTF_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GLTF_EXPORTS
#define GLTF_API __declspec(dllexport)
#else
#define GLTF_API __declspec(dllimport)
#endif

// This class is exported from the dll
class GLTF_API CGLTF {
public:
	CGLTF(void);
	// TODO: add your methods here.
};

extern GLTF_API int nGLTF;

GLTF_API int fnGLTF(void);