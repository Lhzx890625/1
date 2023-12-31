set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
  URL_HASH SHA256=24564E3B712D3EB30AC9A85D92F7D720F60CC0173730AC166F27DDA7FED76CB2
)

FetchContent_MakeAvailable(googletest)

add_executable(Tests GlobalContextInstance.cpp HelpersTests.cpp SafeAddressTests.cpp SortFilterTests.cpp)
add_subdirectory(HelpersTests)
add_subdirectory(InventoryChanger)
add_subdirectory(MemoryAllocation)
add_subdirectory(MemorySearchTests)
add_subdirectory(Platform)
add_subdirectory(UtilsTests)
target_link_libraries(Tests gtest_main gmock Threads::Threads OsirisOBJ)
target_include_directories(Tests PRIVATE .)

include(GoogleTest)
gtest_discover_tests(Tests DISCOVERY_TIMEOUT 60)
