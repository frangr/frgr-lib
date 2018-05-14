#ifndef POINTY_H_INCLUDED
#define POINTY_H_INCLUDED

template<typename T>
class pointy
{
public:
    pointy(bool ap, T* pt = nullptr);
    ~pointy();
    T* pointer;
private:
    bool ArrayPointer;
};

template<typename T>
pointy<T>::pointy(bool ap, T* pt):pointer(pt), ArrayPointer(ap){}

template<typename T>
pointy<T>::~pointy()
{
    if(ArrayPointer)
        delete [] pointer;
    else
        delete pointer;
}

#endif // POINTY_H_INCLUDED
