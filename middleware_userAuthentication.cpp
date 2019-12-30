#include "middleware_userAuthentication.h"

UserAuthentication::UserAuthentication()
{

}

UserAuthentication::UserAuthentication(QString currentRole)
{
    if(currentRole == "Manager")
        m_userGroup = MANAGER;
}


//Attention : it should be used in a authority system (R(resource)BAC)
// to waste less time, I use isPermisiionAllow() instead.
//用户身份认证
boolean UserAuthentication::isAuthorityAllow(qint16 currentRole)
{
    if(m_userGroup > currentRole)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//授权
boolean UserAuthentication::isPermisiionAllow(qint16 currentUserGroup)
{
    if(m_userGroup > currentUserGroup)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


