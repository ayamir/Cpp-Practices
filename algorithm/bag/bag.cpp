#include "bag.h"
#include <iostream>
#include <algorithm>

Bag::Bag() {
  std::cout << "请分别输入物品数量和背包大小：";
  std::cin >> this->num >> this->vol;
  for (int i = 0; i < this->num; i++) {
    std::cout << "请分别输入第" << i+1 << "个物品的重量和价值：";
    good one;
    std::cin >> one.weight >> one.value;
    one.ave = one.weight / one.value;
    one.flag = false;
    goods.push_back(one);
  }
}

void Bag::getRes() {
  for (int i = 0; i < this->num; i++) {
    if (goods[i].flag) {
      way.push_back(1);
    } else {
      way.push_back(0);
    }
  }
  std::cout << "最高的价值是：" << res;
  std::cout << "取法是：[";
  for (auto &&i : way) {
    std::cout << i << ",";
  }
  std::cout << "]" << std::endl;
}

double compare(const void *a, const void *b) {
  return (*(double*)a - *(double*)b);
}

void Bag::analysis() {
  qsort(goods, num, sizeof(good), compare);
}


int main() {
  Bag bag;
  bag.analysis();

  return 0;
}
