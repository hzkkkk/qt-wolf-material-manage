#ifndef MIDDLEWARE_USERAUTHENTICATION_H
#define MIDDLEWARE_USERAUTHENTICATION_H

#include <qstring.h>
#include "config_configuration.h"

class UserAuthentication
{
public:
    UserAuthentication();
private:
    //organization组织
    QString m_organization;
    //apartment 部门 ( parent : organization)
    QString m_apartment;
    //identify 身份 (parent : apartment)
    QString m_identify;
    //user group 用户组
    QString m_userGroup;
    // custom authentication 自定义权限列表


    bool operator==(UserAuthentication &temp_authe);

};

#endif // MIDDLEWARE_USERAUTHENTICATION_H
