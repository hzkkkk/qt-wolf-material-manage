
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

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
#define Manager 5
#define Member 2
#define Visitor 1

//---------------------------------//

//---------------------------------//

#define M_MATERIAL_CATEGORY_TABLE "m_material_category"
#define M_MATERIAL_TABLE "m_material"
#define M_STORAGE_ROOM_TABLE "m_storage_room"
#define M_STORAGE_TABLE "m_storage"
#define M_ROLE_TABLE "m_role"

//---------------------------------//


#define SETPUSHBUTTON(tyleSheet) ()


#endif // CONFIGURATION_H



