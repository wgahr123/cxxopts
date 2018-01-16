#include <iostream>
#include <optional>

#include "cxxopts.hpp"

// TODO: refactor this into a proper test to run on Travis

int main(int argc, char** argv)
{
  std::optional<std::string> optional;
  cxxopts::Options options("optional", " - tests optional");
  options.add_options()
    ("optional", "an optional option", cxxopts::value<std::optional<std::string>>(optional));

  options.parse(argc, argv);

  if (optional.has_value())
  {
    std::cout << *optional << std::endl;
  }

  return 0;
}
