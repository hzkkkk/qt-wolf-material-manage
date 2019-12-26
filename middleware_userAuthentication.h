#ifndef MIDDLEWARE_USERAUTHENTICATION_H
#define MIDDLEWARE_USERAUTHENTICATION_H

#include <qstring.h>

class middleware_userAuthentication
{
public:
    middleware_userAuthentication();
private:
    static QString s_token;
    static QString s_authority;

};

#endif // MIDDLEWARE_USERAUTHENTICATION_H
