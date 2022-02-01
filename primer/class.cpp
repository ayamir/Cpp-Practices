#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class Sales_data {
public:
  Sales_data() = default;
  Sales_data(const std::string &s) : book_no(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : book_no(s), units_sold(n), revenue(p) {}

private:
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string book_no;
};

class Screen {
public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  char get(pos ht, pos wd) const;
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &move(pos r, pos c);
  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline char Screen::get(pos r, pos c) const {
  pos row = r + width;
  return contents[row + c];
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
  contents[r * width + c] = ch;
  return *this;
}

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);
  ScreenIndex addScreen(const Screen &);

private:
  std::vector<Screen> screens{Screen{24, 80, ' '}};
};

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
  screens.push_back(s);
  return screens.size() - 1 ;
}
