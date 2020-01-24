
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>

#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "src/Logger.h"

#ifdef BRICK_ENABLE_ASSERTS
	#define BRICK_ASSERT(x, ...) { if(!(x)) { BRICK_ASSERT("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BRICK_CORE_ASSERT(x, ...) { if(!(x)) { BRICK_CORE_ASSERT("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BRICK_ASSERT(x, ...)
	#define BRICK_CORE_ASSERT(x, ...)
#endif