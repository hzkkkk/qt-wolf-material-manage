
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//---------------------------------//

//https://www.cnblogs.com/xiaoqi254789/articles/7050871.html
#define TRUE 1
#define FALSE 0
#define WARNING -1

typedef  unsigned char      boolean;     /* Boolean value type. */
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
typedef  signed long int    int32;       /* Signed 32 bit value */
typedef  signed short       int16;       /* Signed 16 bit value */
typedef  signed char        int8;        /* Signed 8  bit value */

//---------------------------------//

#define OFFLINE //ONLINE  OFFLINE

#ifdef ONLINE
#define DATABASEDRIVER "QMYSQL"
#endif

#ifdef OFFLINE
#define DATABASEDRIVER "QSQLITE"
#endif

//---------------------------------//

#define ADMIN 9
#define MANAGER 5
#define MEMBER 2
#define VISITOR 1

//---------------------------------//

#define M_MATERIAL_CATEGORY_TABLE "m_material_category"
#define M_MATERIAL_TABLE "m_material"
#define M_STORAGE_ROOM_TABLE "m_storage_room"
#define M_STORAGE_TABLE "m_storage"
#define M_ROLE_TABLE "m_role"

//---------------------------------//

#define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

//---------------------------------//

#define SETPUSHBUTTON(tyleSheet) ()

//---------------------------------//



//---------------------------------//
#endif // CONFIGURATION_H



