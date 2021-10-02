#include <iostream>
#include <string>

using std::cout;

const std::string authorName("Scott Meyers");

class GamePlayer {
private:
  static const int NumTurns = 5;
};

int main(int argc, char *argv[]) {
  cout << authorName << std::endl;
  return 0;
}
