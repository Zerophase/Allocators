cmake_minimum_required(VERSION 3.2)
project(Allocators)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Allocators ${SOURCE_FILES} DoubleEndedLinearAllocator.cpp DoubleEndedLinearAllocator.h Allocator.cpp Allocator.h Types.h PointerMath.h MemoryManager.cpp MemoryManager.h Singleton.h main.h AllocationSchemas.h Vehicle.h Car.cpp Car.h Truck.cpp Truck.h)