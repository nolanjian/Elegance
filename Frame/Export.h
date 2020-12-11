#pragma once

#ifdef WXFRAME_EXPORTS
#define WXFRAME_API __declspec(dllexport)
#else
#define WXFRAME_API __declspec(dllimport)
#endif