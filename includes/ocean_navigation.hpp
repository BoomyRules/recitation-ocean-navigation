#ifndef OCEAN_NAVIGATION_HPP
#define OCEAN_NAVIGATION_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class OceanNavigation {
public:
  OceanNavigation(const std::string& file_path,
                  unsigned int rows,
                  unsigned int cols);
  std::vector<int> FindSafestPath(unsigned int starting_row);
  std::vector<std::vector<int>> GetOcean();

private:
  std::vector<std::vector<int>> ocean_;
  unsigned int rows_;
  unsigned int cols_;
};

#endif  // OCEAN_NAVIGATION_HPP
