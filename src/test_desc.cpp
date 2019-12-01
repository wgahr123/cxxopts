// format_help
//

#include "cxxopts.hpp"

int main(int argc, char* argv[])
{
  // grep value of option "-w" for .set_width()
  // 

  size_t width = 60;
  bool expansion = false;

  for (int i = 1; i < argc; ++i)
  {
    if (std::string(argv[i]) == "-w" && i < argc)
    {
      width = abs(atoi(argv[i + 1]));
    }
    if (std::string(argv[i]) == "-e")
    {
      expansion = true;
    }
  }

  // test for .set_width()
  // test for multiline descriptions
  // test for tabs in description
  // test for properly handling whitespace
  // test for lines with words longer than the line
  // test for optional expansion of tabs

  cxxopts::Options options(argv[0], "Check the formatting of help descriptions");

  options
    .positional_help("[optional args]")
    .show_positional_help()
    .allow_unrecognised_options()
    .set_width(width)
    .set_tab_expansion(expansion)
    .add_options()
    ("h,help", "Print help")
    ("w,width", "Set length of helplines")
    ("e,expandtabs", "Expand tabs in descriptions")

    ("a,aaaa", "a23456789 b23456789 c23456789 d23456789 e23456789 f23456789.")
    ("b,bbbb", "123456789.123456789.123456789.123456789.123456789.123456789.")
    ("c,cccc", "a234 b789 c234 d789 e234 f789 g234 h789 i234 j789 k234 l789.")
    ("x,xxxx", " the whitespace  in   this    sentence     grows     ")
    ("y,yyyy", "This text\nhas many\nmany many\n\nlines.")
    ("z,tabs", "This text checks the tab expansion, it\n"
               "has many\t(option -e: skip 8 after 8 chars)\n"
               "lines and\t(option -e: skip 7 after 9 chars)\n"
               "tabs...\t(option -e: skip 1 after 7 chars)\n")
    ;

  auto result = options.parse(argc, argv);

  if (result.count("help"))
  {
    std::cout << options.help() << std::endl;
    std::cout << "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789" << std::endl;
    exit(0);
  }
}
