#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "heat_map.hpp"
#include "ocean_navigation.hpp"

int main(int argc, char* argv[]) {
  if (argc != 5 && argc != 6) {
    std::cerr
        << "Usage: " << argv[0]
        << " <file_path> <starting_row> <rows> <cols> <output_file_path>\n"
        << argv[0] << "<file_path> <rows> <cols> <output_file_path>\n";
    return 1;
  }
  std::string output_file;
  if (argc == 5) {
    output_file = argv[4];
    OceanNavigation ocean_nav(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
    HeatMap visualizer(ocean_nav.GetOcean());
    visualizer.GenerateHeatMap(argv[4], nullptr);
  } else {
    output_file = argv[5];
    OceanNavigation ocean_nav(argv[1], std::stoi(argv[3]), std::stoi(argv[4]));
    HeatMap visualizer(ocean_nav.GetOcean());
    std::vector<int> safe_path = ocean_nav.FindSafestPath(std::stoi(argv[2]));
    visualizer.GenerateHeatMap(argv[5], &safe_path);
  }
  std::cout << "Heat map generated as '" << output_file << "'.\n";
  return 0;
}
