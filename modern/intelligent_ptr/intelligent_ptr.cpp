#include <iostream>
#include <memory> // for intelligent ptr
#include <ostream>

void foo(std::shared_ptr<int> i) { (*i)++; }

struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) { std::cout << "f(const Foo &)" << std::endl; }

struct A;
struct B;

struct A {
    std::shared_ptr<B> pointer;
    ~A() { std::cout << "A is destroyed" << std::endl; }
};

struct B {
    std::weak_ptr<A> pointer;
    ~B() { std::cout << "B is destroyed" << std::endl; }
};

int main() {
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer;
    auto pointer3 = pointer;
    int *p = pointer.get();
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

    pointer2.reset();
    std::cout << "reset pointer2" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

    pointer3.reset();
    std::cout << "reset pointer3" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    // std::unique_ptr<int> ptr2 = ptr; // error: unique_ptr is exclusive

    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    // p1 isn't empty
    if (p1)
        p1->foo();
    {
        std::unique_ptr<Foo> p2(std::move(p1));
        // p2 isn't empty
        f(*p2);
        // p2 isn't empty
        if (p2)
            p2->foo();

        if (p1)
            p1->foo();
        p1 = std::move(p2);
        if (p2)
            p2->foo();
        std::cout << "p2 is destroyed" << std::endl;
    }
    if (p1)
        p1->foo();

    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;

    return 0;
}
