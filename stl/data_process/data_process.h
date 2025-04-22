#pragma once
#include <string>
#include <vector>

class DataProcessor
{
public:
    std::vector<std::string> data_;
    DataProcessor(std::vector<std::string> data);
    // std::vertor<std::string> sort_by_length();
    auto sort_by_length() const -> std::vector<std::string>;
    auto filter_by_prefix(const std::string &prefix) const -> std::vector<std::string>;
};