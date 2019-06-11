#ifndef HAVE_FILE_H
#define HAVE_FILE_H
#include <string>
using namespace std;
class have_file
{
protected:
    string ID;
public:
   virtual long double total_price()=0;
    virtual ~have_file(){}
};

#endif // HAVE_FILE_H
