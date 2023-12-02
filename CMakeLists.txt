cmake_minimum_required(VERSION 3.26)
project(vulkantutorial)

set(CMAKE_CXX_STANDARD 17)



add_executable(vulkantutorial src/main.cpp
        src/main.cpp)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
#include_directories(
        #"C:/Libraries/glfw"
        #"C:/VulkanSDK/1.3.268.0/Include"
        #"C:/Libraries/glm-0.9.9.8/glm"
#)

set(VULKAN_SDK_PATH C:/Libraries/vulkantutorial/thirdpartyVulkanSDK/1.3.268.0)
set(Vulkan_INCLUDE_DIRS "${VULKAN_SDK_PATH}/Include")
set(Vulkan_LIBRARIES "${VULKAN_SDK_PATH}/Lib")
target_link_libraries(${PROJECT_NAME} "$ENV{VULKAN_SDK}/Lib/vulkan-1.lib")

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

#find_package(PkgConfig REQUIRED MODULE)
set(GLM_DIR C:/Libraries/vulkantutorial/thirdparty/glm/cmake/glm)
find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLM_LIBRARY_DIRS})


add_subdirectory("thirdparty/glfw")
target_link_libraries(${PROJECT_NAME} glfw)
#add_subdirectory("thirdparty/glm")
#add_subdirectory("thirdparty/VulkanSDK/")



