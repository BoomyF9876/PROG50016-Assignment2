#pragma once

#ifndef _STANDARDINCLUDES_H_
#define _STANDARDINCLUDES_H_

#define SDL_MAIN_HANDLED
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cassert>
#include "json.hpp"
#include "SDL.h"
#include "SDL_image.h"

#define DEBUG_LOG(indent, log) std::cout << std::setw(indent) << "" << log << std::endl;

#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
	if(!_cond) { OutputDebugStringA(_msg); std::abort(); }
#endif

static json::JSON LoadJson(const std::string& _file_name)
{
	std::ifstream inputStream(_file_name);
	std::string str((std::istreambuf_iterator<char>(inputStream)),
		std::istreambuf_iterator<char>());

	return json::JSON::Load(str);
}

static json::JSON Get(json::JSON& _json, const std::string& _key)
{
	std::string err_msg = "Object does not have key: " + _key;
	M_ASSERT(_json.hasKey(_key), err_msg.c_str());
	return _json[_key];
}

#endif
