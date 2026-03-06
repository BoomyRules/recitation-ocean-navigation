#include "ocean_navigation.hpp"

std::vector<int> OceanNavigation::FindSafestPath(unsigned int starting_row) {
  if (starting_row >= rows_) {
    throw std::runtime_error("Starting row is out of bounds.");
  }

  std::vector<int> path;
  unsigned int current_row = starting_row;
  path.push_back(current_row);

  for (unsigned int col = 0; col < cols_ - 1; col++) {
    unsigned int next_row = current_row;
    int best_value = ocean_[current_row][col + 1];

    // top option //
    if (current_row > 0) {
      int top_value = ocean_[current_row - 1][col + 1];
      if (top_value > best_value) {
        best_value = top_value;
        next_row = current_row - 1;
      }
    }

    // bottom option //
    if (current_row < rows_ - 1) {
      int bottom_value = ocean_[current_row + 1][col + 1];
      if (bottom_value > best_value) {
        best_value = bottom_value;
        next_row = current_row + 1;
      }
    }
    current_row = next_row;
    path.push_back(current_row);
  }
  return path;
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