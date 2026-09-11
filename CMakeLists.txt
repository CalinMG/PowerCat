cmake_minimum_required(VERSION 3.20)
project(BatteryPlanApp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BatteryPlanApp main.cpp)

# Link the Windows Power Profile library from the Windows SDK
target_link_libraries(BatteryPlanApp PRIVATE PowrProf)