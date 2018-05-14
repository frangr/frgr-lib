#include "mtvec.h"
#include "pointy.h"
#include<iostream>

void pf(pointy<int> pi)
{
    std::cout<<"pointer: "<<*pi.pointer<<std::endl;
}

int main()
{
    int* c = new int(500);
    pointy<int> pft(false, c);
    pointy<int> pft1(false, new int(7));
    pointy<int> pft2(true, new int[3]{1, 2, 3} );

    pf(pft);
    pf(pft1);
    pf(pft2);

    int a = 15;

    pointy<int> pi(false, &a);

    std::cout<<"pi: "<<*pi.pointer<<std::endl;

    pointy<int> p(false);

    p.pointer = &a;

    std::cout<<"p 0: "<<*p.pointer<<std::endl;

    pointy<int> p2(true);

    p2.pointer = new int[3]{1, 2, 3};

    std::cout<<"p 0: "<<p2.pointer[0]<<std::endl;

    std::cout<<std::endl<<"---MTVEC---"<<std::endl;

    mtvec mv;

    int   a1 = 5;
    float a2 = 23.4;

    struct a3
    {
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
