#ifndef MTVEC_H_INCLUDED
#define MTVEC_H_INCLUDED

#include<vector>

class mtvec
{
public:
    template<typename type>
    void add(type&& obj);

    template<typename type>
    type& get(int idx);
private:
    std::vector<void*> obj;
};

template<typename type>
void mtvec::add(type&& obj)
{
    //push back the address of the 'type' object
    mtvec::obj.push_back(&obj);
}

template<typename type>
type& mtvec::get(int idx)
{
    //convert a 'void*' pointer to a 'type*' type, dereference it, then return the pointed object to a reference of type 'type'
    //int a = mtvec.get<int>(idx);
    //in a template context: T a = mtvec.get<T>(idx); <-dangerous
    return *( static_cast<type*>( obj[idx] ) );
}
#endif // MTVEC_H_INCLUDED
