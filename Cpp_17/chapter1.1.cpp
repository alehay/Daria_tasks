#include <iostream>
#include <vector>

struct settings_t {
  int area_width;
  int area_height;

  std::string font_path;
};

int main(){

  //  решено с подсказки Дарьи ))) это 20 стандарт )))
  settings_t s{.area_width = 10, .area_height = 20, .font_path = "font.ttf"};

  std::vector<settings_t> v (10, s);
  
  for(const auto & [area_width, area_height, font_path] : v){
    std::cout << "width: " << area_width << " height: " << area_height
              << " path: " << font_path << std::endl; 
  }
}