
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


#endif // CONFIGURATION_H



