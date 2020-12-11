// Utils.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Utils.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "Utils/stb_image.h"

namespace Elegance
{
	namespace Utils
	{
		osg::ref_ptr<osg::Image> Elegance::Utils::LoadImageFromMemory(unsigned char* pcBuffer)
		{
			if (!pcBuffer)
			{
				return nullptr;
			}
			size_t bufferSize = sizeof(pcBuffer);
			int width = 0, height = 0, nrChannels = 0;
			unsigned char* imgObj = stbi_load_from_memory(pcBuffer, bufferSize, &width, &height, &nrChannels, STBI_rgb_alpha);
			if (imgObj)
			{
				osg::ref_ptr<osg::Image>	osgIMG = new osg::Image();
				osgIMG->setImage(width, height, 1, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, imgObj, osg::Image::USE_MALLOC_FREE);
				return osgIMG;
			}
			return nullptr;
		}

		osg::ref_ptr<osg::Image> LoadImageFromPath(const std::string& path)
		{
			int width = 0, height = 0, nrChannels = 0;
			unsigned char* imgObj = stbi_load(path.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
			if (imgObj)
			{
				osg::ref_ptr<osg::Image>	osgIMG = new osg::Image();
				osgIMG->setImage(width, height, 1, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, imgObj, osg::Image::USE_MALLOC_FREE);
				return osgIMG;
			}
			return nullptr;
		}
	}
}
