cmake_minimum_required(VERSION 3.17)
project(cpu_raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpu_raytracer src/main.cpp
			   src/Bitmap.h
			   src/Bitmap.cpp
               src/Camera.h
		       src/Light.h
		       src/Math.h
		       src/Math.cpp
		       src/Object.h
		       src/PerspectiveCamera.h
		       src/PerspectiveCamera.cpp
		       src/Plane.h
		       src/Plane.cpp
		       src/Ray.h
		       src/Ray.cpp
		       src/Sphere.h
		       src/Sphere.cpp
		       src/SceneObject.h
			   src/Vector2.h
			   src/Vector2.cpp
			   src/Vector3.h
			   src/Vector3.cpp)
