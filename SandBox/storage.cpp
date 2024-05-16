#include <iostream>
#include <string>

using namespace std;

class storage
{
private:
    string name;
    string bb;
    int cc;

public:
    storage(const string &a, const string &b, int c = 0)
    {
        name = a;
        bb = b;
        cc = c;
    }

    void name_set(const string &a)
    {
        name = a;
    }

    ~storage()
    {

        // TODO: Implement destructor
    }
};
