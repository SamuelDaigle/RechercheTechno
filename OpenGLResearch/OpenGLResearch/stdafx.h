#include "Dependencies/glew/glew.h"
#include "Dependencies/glew/wglew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\glm\glm.hpp"
#pragma comment(lib, "glew32.lib")

#include <vector>
#include "Color.h"
#include "DynamicArray.h"
#include "IObject.h"

using namespace glm;

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }