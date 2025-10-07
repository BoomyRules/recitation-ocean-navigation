#include "ocean_navigation.hpp"

std::vector<int> OceanNavigation::FindSafestPath(unsigned int starting_row) {
  // TODO
  return {};
}

OceanNavigation::OceanNavigation(const std::string& file_path,
                                 unsigned int rows,
                                 unsigned int cols):
    ocean_(rows, std::vector<int>(cols)), rows_(rows), cols_(cols) {
  std::ifstream input(file_path);
  if (!input) {
    std::cerr << "Error: Unable to open file: " << file_path << std::endl;
    return;
  }
  for (unsigned int r = 0; r < rows_; r++) {
    for (unsigned int c = 0; c < cols_; c++) {
      input >> ocean_[r][c];
    }
  }
}

std::vector<std::vector<int>> OceanNavigation::GetOcean() { return ocean_; }