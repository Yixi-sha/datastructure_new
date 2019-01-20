#include "../inc/exception.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>


namespace yixi
{

void Exception::init(const char* message, const char* file, int line)
{
    i_message=(message ? strdup(message) : NULL);

        if(file != NULL)
        {
            char sl[16] = {0};
            for(int i = 0; i < 16; i++)
            {
                sl[i] = 'a';
            }
            snprintf(sl, strlen(sl), "%d", line);


            i_location=static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));

            if(i_location != nullptr)
            {
                i_location = strcpy(i_location,file);
                i_location = strcat(i_location,":");
                i_location = strcat(i_location,sl);
            }
        }
        else
        {
            i_location=NULL;
        }
}

Exception::Exception(const char *message)
{
    init(message,NULL,0);
}

Exception::Exception(const char *file,int line)
{
    init(NULL,file,line);
}

Exception::Exception(const char *message,const char *file,int line)
{
    init(message,file,line);
}

Exception::Exception(const Exception& obj)
{
    i_message=strdup(obj.i_message);
    i_location=strdup(obj.i_location);
}

Exception& Exception::operator = (const Exception &obj)
{
    if(this != &obj)
    {
        free(i_message);
        free(i_location);

        i_message=strdup(obj.i_message);
        i_location=strdup(obj.i_location);
    }
    return *this;
}

const char* Exception::message() const
{
    return i_message;
}
const char* Exception::location() const
{
    return i_location;
}

Exception::~Exception()
{
    free(i_message);
    free(i_location);
}

}

