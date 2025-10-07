#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <string>
#include <vector>

#include "catch.hpp"
#include "ocean_navigation.hpp"

//////////////////////////////////////////////////////////////////
// Test Cases
//////////////////////////////////////////////////////////////////////////

TEST_CASE("Prompt Example", "[prompt]") {
  std::string filename = "tests/data/ocean10x10.txt";
  OceanNavigation nav(filename, 10, 10);

  SECTION("Starting from row 0") {
    auto path = nav.FindSafestPath(0);
    std::vector<int> expected = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    REQUIRE(path == expected);
  }
  SECTION("Starting from row 3") {
    auto path = nav.FindSafestPath(4);
    std::vector<int> expected = {4, 4, 4, 5, 5, 5, 5, 6, 6, 6};
    REQUIRE(path == expected);
  }

  SECTION("Starting from row 6") {
    auto path = nav.FindSafestPath(6);
    std::vector<int> expected = {6, 5, 4, 5, 5, 5, 5, 6, 6, 6};
    REQUIRE(path == expected);
  }
}
TEST_CASE("FindSafestPath on ocean5x5.txt", "[edge]") {
  std::string filename = "tests/data/ocean5x5.txt";
  OceanNavigation nav(filename, 5, 5);

  SECTION("Starting from top row (edge case)") {
    auto path = nav.FindSafestPath(0);
    std::vector<int> expected = {0, 1, 2, 1, 1};
    REQUIRE(path == expected);
  }

  SECTION("Starting from bottom row (edge case)") {
    auto path = nav.FindSafestPath(4);
    std::vector<int> expected = {4, 3, 3, 3, 4};
    REQUIRE(path == expected);
  }

  SECTION("Starting from middle with tie-breakers") {
    auto path = nav.FindSafestPath(2);
    std::vector<int> expected = {2, 1, 2, 1, 1};
    REQUIRE(path == expected);
  }
}
