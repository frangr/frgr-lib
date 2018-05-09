#include "mtvec.h"
//#include "pointy.h"
#include<iostream>

int main()
{
    /*
    pointy<int> p;

    int a;

    p.pt = &a;
    */

    mtvec mv;

    int   a1 = 5;
    float a2 = 23.4;
    struct a3
    {
        public:
        int a;
        void f()
        {
            a = 15;
            std::cout<<"func"<<std::endl;
        }
    };

    a3 s3;

    mv.add(a1);
    mv.add(a2);
    mv.add(s3);

    std::cout<<mv.get<int>(0)<<std::endl;
    std::cout<<mv.get<float>(1)<<std::endl;

    mv.get<a3>(2).f();
    std::cout<<mv.get<a3>(2).a;
}
