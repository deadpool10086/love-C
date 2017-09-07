    #include <iostream>
    using namespace std;
     
    template <int N>
    struct Fibonacci
    {
        enum { value = Fibonacci<N - 2>::value + Fibonacci<N - 1>::value };
    };
     
    template <>
    struct Fibonacci<0>
    {
        enum { value = 0 };
    };
    template <>
    struct Fibonacci<1>
    {
        enum { value = 1 };
    };
     
    void foo()
    {
        int x = Fibonacci<2>::value; 
        int y = Fibonacci<3>::value; 
        cout << x << endl;
        cout << y << endl;
    }
     
    int main() {
        foo();
        // GCC及VC编译器在调试模式下会暂停，便于查看运行结果
    #if ( defined(__DEBUG__) || defined(_DEBUG) )
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    #endif
        return 0;
    }
