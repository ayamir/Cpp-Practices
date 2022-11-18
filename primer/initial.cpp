#include <iostream>

int default_initialize(int);

int main(int argc, char *argv[]) {
    int units_sold0 = 0;
    int units_sold2(0);

    int units_sold1 = {0};
    int units_sold3{0};

    long double pi = 3.1415926536;
    /* int a0{pi}, b0 = {pi}; // 错误：没有执行类型转换，因为可能丢失信息 */
    int a1(pi), b1 = pi; // 正确：执行了隐式类型转化，丢失了信息

    // 不对a进行初始化
    int a;
    // 输出的值随机
    std::cout << default_initialize(a) << std::endl;

    return 0;
}

int default_initialize(int a) {
    // 因为a定义在函数外部且a是内置类型，虽然没有初始化，但是输出的值必定是0
    std::cout << a << std::endl;
    int b;
    return b;
}
