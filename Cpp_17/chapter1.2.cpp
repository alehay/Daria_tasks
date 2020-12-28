#include <iostream>
#include <map>

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        FG_WHITE    = 37,
        FG_DEFAULT  = 39,
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

int main(){
  // Исправить ошибку компиляции..
  
  Color::Modifier red(Color::FG_RED);
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier yellow(Color::FG_YELLOW);
  Color::Modifier blue(Color::FG_BLUE);
  Color::Modifier magenta(Color::FG_MAGENTA);
  Color::Modifier cyan(Color::FG_CYAN);

  Color::Modifier def(Color::FG_DEFAULT);
  
  using map_t = std::map<int, std::pair< Color::Modifier, std::string>>;
  map_t metro_map {
    {1, {red, "Сокольническая"}},
    {2, {green, "Замоскворецкая"}},
    {3, {blue, "Арбатско-Покровская"}},
    {4, {cyan, "Филевская"}},
    {7, {magenta, "Таганско-Краснопресненская"}},
    {8, {yellow, "Калининско-Солнцевская"}},
  };
  /*
  for(auto&& [number,color, name] : metro_map){
    std::cout << "#" << number << " -> "  << color << name << def << std::endl;
  }
  */

 // не допускается вложенная распаковка, надо вынести
  for(auto&& [number, pair] : metro_map){
    auto [color, name] = pair; 

    std::cout << "#" << number << " -> "  << color << name << def << std::endl;
  }


}
