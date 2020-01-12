#ifndef MIDDLEWARE_USERAUTHENTICATION_H
#define MIDDLEWARE_USERAUTHENTICATION_H

#include <qstring.h>
#include <QtSql>
#include <QtWidgets>
#include "config_configuration.h"

class UserAuthentication
{
public:
    UserAuthentication();

    UserAuthentication(QString currentRole);


    //用户身份认证
    //Attention : it should be used in a authority system (R(resource)BAC)
    // to waste less time, I use isPermisiionAllow() instead.
    static int8 isAuthorityAllow(QString currentTable, QString neededOperation, qint16 currentRoleID);

private:
    //organization组织
    QString m_organization;
    //apartment 部门 ( parent : organization)
    QString m_apartment;
    //identify 身份 (parent : apartment)
    QString m_identify;
    //user group 用户组
    qint16 m_userGroup;
    // custom authentication 自定义权限列表


    //授权
    boolean isPermisiionAllow(qint16 currentUserGroup);

};

#endif // MIDDLEWARE_USERAUTHENTICATION_H
