#include "data/mtvec.h"
#include "smp/pointy.h"
#include<iostream>

int main()
{
    pointy<int> p(false);

    int a = 15;

    p.pointer = &a;

    std::cout<<"p 0: "<<*p.pointer<<std::endl;

    pointy<int> p2(true);

    p2.pointer = new int[3]{1, 2, 3};

    std::cout<<"p 0: "<<p2.pointer[0]<<std::endl;

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
