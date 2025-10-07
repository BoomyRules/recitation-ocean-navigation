#include "heat_map.hpp"

#include <fstream>
#include <limits>

HeatMap::HeatMap(const std::vector<std::vector<int>>& ocean): ocean_(ocean) {}

void HeatMap::GenerateHeatMap(const std::string& output_file,
                              std::vector<int>* safe_path) const {
  if (ocean_.empty() || ocean_[0].empty()) {
    return;
  }
  int rows = ocean_.size();
  int cols = ocean_[0].size();
  int min_val = std::numeric_limits<int>::max();
  int max_val = std::numeric_limits<int>::min();
  for (const auto& row : ocean_) {
    for (int val : row) {
      min_val = std::min(min_val, val);
      max_val = std::max(max_val, val);
    }
  }
  std::ofstream ofs(output_file);
  if (!ofs) {
    return;
  }
  ofs << "P3\n" << cols << " " << rows << "\n255\n";
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (safe_path != nullptr && c < static_cast<int>(safe_path->size()) &&
          (*safe_path)[c] == r) {
        ofs << "255 0 255 ";  // Green for the safest path
      } else {
        double normalized = (max_val == min_val)
                                ? 0.0
                                : static_cast<double>(ocean_[r][c] - min_val) /
                                      (max_val - min_val);
        int red = 0, green = 0, blue = 0;
        if (normalized < 0.2) {
          red = 255;
          green = static_cast<int>(normalized * 5 * 50);
          blue = 0;
        } else if (normalized < 0.4) {
          red = 255;
          green = static_cast<int>(50 + (normalized - 0.2) * 5 * 100);
          blue = 0;
        } else if (normalized < 0.6) {
          red = static_cast<int>(255 - (normalized - 0.4) * 5 * 100);
          green = 255;
          blue = 0;
        } else if (normalized < 0.8) {
          red = static_cast<int>(255 - (normalized - 0.6) * 5 * 255);
          green = 255;
          blue = static_cast<int>((normalized - 0.6) * 5 * 255);
        } else {
          red = 0;
          green = static_cast<int>(255 - (normalized - 0.8) * 5 * 255);
          blue = 255;
        }
        ofs << red << " " << green << " " << blue << " ";
      }
    }
    ofs << "\n";
  }
  ofs.close();
}
