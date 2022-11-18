#ifndef __BAG_H_
#define __BAG_H_

#include <vector>

struct good {
    double value;
    double weight;
    double ave;
    bool flag;
};

class Bag {
  private:
    int num;
    int vol;
    double res;
    double tmpValue;
    double tmpWeight;
    std::vector<int> way;
    std::vector<good> goods;

  public:
    Bag();
    void getRes();
    void analysis();
};

#endif // __BAG_H_
