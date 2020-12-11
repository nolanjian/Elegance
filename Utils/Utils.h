// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UTILS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UTILS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UTILS_EXPORTS
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

#include "osg/Image"

namespace Elegance
{
	namespace Utils
	{
		UTILS_API osg::ref_ptr<osg::Image> LoadImageFromMemory(unsigned char* pcBuffer);
		UTILS_API osg::ref_ptr<osg::Image> LoadImageFromPath(const std::string& path);
	}
}