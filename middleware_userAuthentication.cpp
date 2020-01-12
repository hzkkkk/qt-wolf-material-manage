#include "middleware_userAuthentication.h"

UserAuthentication::UserAuthentication()
{

}

UserAuthentication::UserAuthentication(QString currentRole)
{

}


// Attention : it should be used in a authority system (R(resource)BAC)
//     to waste less time, I use isPermisiionAllow() instead.
//用户身份认证
int8 UserAuthentication::isAuthorityAllow(QString neededTable, QString neededOperation, qint16 currentRoleID)
{
    QSqlQuery queryIdentityAuthority;
    QString sql = QString("select %1 from m_identity_authority where IdentityID = '%2'")
            .arg(neededTable + neededOperation)
            .arg(currentRoleID);

    if(queryIdentityAuthority.exec(sql))
    {
        if(queryIdentityAuthority.next())
        {
            //获取当前行的记录
            QSqlRecord record = queryIdentityAuthority.record();
            qDebug() << neededTable + neededOperation;
            if(record.value(neededTable + neededOperation).toString() == "Y")
            {
                // 执行成功
                return G_TRUE;
            }
            else if(record.value(neededTable + neededOperation).toString() == "N")
            {
                // 没有删除的权限
                return G_FALSE;
            }
            else
            {
                // 数据库的数据不是规定的  "Y" 或 "N"
                return G_WARNING;
            }
        }
        else
        {
            // 找不到这个人
            // TODO : 需要在查询前确保有这个人
            return G_NOTICE;
        }
    }
    else
    {
        // 执行失败, 数据库初始化不成功?
        qDebug() << queryIdentityAuthority.lastError().text();
        return G_WARNING;
    }
}

//授权
boolean UserAuthentication::isPermisiionAllow(qint16 currentUserGroup)
{
    if(m_userGroup > currentUserGroup)
    {
        return G_TRUE;
    }
    else
    {
        return G_FALSE;
    }
}


