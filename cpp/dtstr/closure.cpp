#include <iostream>
#include <functional>

std::function<void(void)> closureWrapper1() {
    int x = 10;
    return [x](){std::cout << "Value in the closure: " << x << std::endl;};
}

std::function<void(void)> closureWrapper2() {
    int x = 10;
    return [&x](){x += 1; std::cout << "Value in the closure: " << x << std::endl;};
}

std::function<void(void)> ctCls(int& ct) {
    return [&ct]() {
        ct += 1; 
        std::cout << "Counter value is: " << ct << std::endl;
    };
} 

int main() {
    int x = 10;
    auto func0 = [&x](){x += 1; std::cout << "Value in the closure: " << x << std::endl;};
    std::function<void(void)> func1 = closureWrapper1();
    std::function<void(void)> func2 = closureWrapper2();
    func0();
    func0();
    func0();
    std::cout << "-------------------------" << std::endl;
    func1();
    func1();
    func1();
    std::cout << "-------------------------" << std::endl;
    func2();
    func2();
    func2();
    std::cout << "-------------------------" << std::endl;
    int ct = 0;
    std::function<void(void)> incCt = ctCls(ct);
    incCt();
    incCt();
    incCt();
}
