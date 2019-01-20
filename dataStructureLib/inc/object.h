#ifndef OBJECT_H
#define OBJECT_H

namespace yixi {

//#define bitsize unsigned int
#define bitsize  long unsigned int
//#define nullptr NULL

class Object
{
public:
    void* operator new(bitsize size) throw();
    void operator delete(void* p);
    void* operator new[](bitsize size) throw();
    void operator delete[](void* p);
    virtual ~Object() = 0;

    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
};

}


#endif // OBJECT_H
