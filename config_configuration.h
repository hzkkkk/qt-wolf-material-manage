
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//---------------------------------//

//https://www.cnblogs.com/xiaoqi254789/articles/7050871.html

#define G_TRUE 1
#define G_FALSE 0
#define G_FALSE 0

//#NOTICE   不暂停脚本执行
#define G_NOTICE -1
//#WARNING    不暂停脚本执行
#define G_WARNING -2
//#EXCEPTION   在指定的错误发生时改变脚本的正常流程
#define G_EXCEPTION -3
//#ERROR    终止程序执行
#define G_ERROR -4



typedef  unsigned char      BOOLEAN;     /* Boolean value type. */
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
typedef  signed long int    int32;       /* Signed 32 bit value */
typedef  signed short       int16;       /* Signed 16 bit value */
typedef  signed char        int8;       /* Signed 16 bit value */
//---------------------------------//

//#define OFFLINE_MYSQL
#define  OFFLINE_MYSQL

#ifdef ONLINE_MYSQL
#define DATABASEDRIVER "QMYSQL"
#endif

#ifdef OFFLINE_MYSQL
#define DATABASEDRIVER "QMYSQL"
#endif

#ifdef OFFLINE_LOCAL
#define DATABASEDRIVER "QSQLITE"
#endif

//---------------------------------//

#define ADMIN 9
#define MANAGER 5
#define MEMBER 2
#define VISITOR 1

//---------------------------------//


#define M_MATERIAL_CATEGORY_TABLE "m_material_category"
#define MATERIAL_CATEGORY_COLUMN "MaterialCategory"

#define M_MATERIAL_TABLE "m_material"
#define MATERIAL_COLUMN "Material"

#define M_STORAGE_ROOM_TABLE "m_storage_room"
#define STORAGE_ROOM_COLUMN "StorageRoom"

#define M_STORAGE_TABLE "m_storage"
#define STORAGE_COLUMN "Storage"

#define M_ROLE_TABLE "m_role"
#define ROLE_COLUMN "Role"

//---------------------------------//

#define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

//---------------------------------//

#define SETPUSHBUTTON(tyleSheet) ()

//---------------------------------//



//---------------------------------//
#endif // CONFIGURATION_H



