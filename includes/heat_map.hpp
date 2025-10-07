#ifndef HEAT_MAP_HPP
#define HEAT_MAP_HPP

#include <fstream>
#include <limits>
#include <string>
#include <vector>

class HeatMap {
public:
  explicit HeatMap(const std::vector<std::vector<int>>& ocean);

  void GenerateHeatMap(const std::string& output_file,
                       std::vector<int>* safe_path = nullptr) const;

private:
  std::vector<std::vector<int>> ocean_;
};

#endif  // HEAT_MAP_HPP
