//用来生成动态库需要的信息

#pragma once

#ifndef DXF_DLL
#ifdef WIN32
#ifdef DXF_EXPORT
#	define DXF_DLL __declspec(dllexport)
#elif DXF_IMPORT
#	define DXF_DLL __declspec(dllimport)
#else
#	define DXF_DLL
#endif
#else
#	define DXF_DLL
#endif //WIN32
#endif //DXF_DLL

#define DXF_NAMESPACE DXF
#define DXF_NAMESPACE_BEGIN namespace DXF_NAMESPACE{
#define DXF_NAMESPACE_END }
#define DXF_USING_NAMESPACE using namespace DXF_NAMESPACE;