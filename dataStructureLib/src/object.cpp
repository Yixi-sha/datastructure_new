#include "../inc/object.h"
#include <cstdlib>

namespace yixi {


void* Object::operator new(bitsize size) throw()
{
    return malloc(size);
}

void Object::operator delete(void* p)
{
    free(p);
}

void* Object::operator new[](bitsize size) throw()
{
    return malloc(size);
}

void Object::operator delete[](void* p)
{
    free(p);
}


bool Object::operator == (const Object& obj)
{
    return (&obj == this);
}

bool Object::operator != (const Object& obj)
{
    return (&obj != this);
}

Object::~Object()
{

}

}
