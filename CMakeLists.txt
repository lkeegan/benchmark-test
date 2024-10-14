cmake_minimum_required(VERSION 3.16)
project("bench")

include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.1)
FetchContent_MakeAvailable(Catch2)

add_executable(bench)
target_sources(bench PRIVATE bench.cpp)
target_link_libraries(bench Catch2::Catch2WithMain)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/DCATCH_CONFIG_ENABLE_BENCHMARKING>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-DCATCH_CONFIG_ENABLE_BENCHMARKING>
)
