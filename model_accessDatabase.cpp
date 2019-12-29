#include "config_configuration.h"
#include "model_accessDatabase.h"


QSqlDatabase model_Database::s_db = QSqlDatabase::addDatabase(DATABASEDRIVER);

model_Database::model_Database()
{}

QSqlError model_Database::initDatabase()
{
    if (!QSqlDatabase::drivers().contains(DATABASEDRIVER))
        QMessageBox::critical(NULL, "Unable to load database", "This demo needs the SQLITE driver");

    if(DATABASEDRIVER == "QSQLITE")
    {
        //内存数据库
        s_db.setDatabaseName(":memory:");

        if (!s_db.open())
        {
            QMessageBox::critical(NULL, QObject::tr("Database open Error"), s_db.lastError().text());
            return s_db.lastError();
        }

        QStringList tables = s_db.tables();

        //判断是否存在重复的数据库
        if (tables.contains("m_material_category", Qt::CaseInsensitive)
                && tables.contains("m_material", Qt::CaseInsensitive)
                && tables.contains("m_storage_room", Qt::CaseInsensitive))
            return QSqlError();

        QSqlQuery q;
        //物资分类表
        if (!q.exec(QLatin1String(
                        "CREATE TABLE m_material_category("
                        "CategoryID integer NOT NULL primary key,"
                        "CategoryName varchar NOT NULL)")))
            return q.lastError();

        //物资种类表
        if (!q.exec(QLatin1String("CREATE TABLE m_material("
                                  "MaterialID  integer NOT NULL primary key,"//'物资id'
                                  "MaterialName varchar NOT NULL ,"// '物资名称'
                                  "CategoryID integer DEFAULT NULL ,"// '物资种类id'
                                  "MaterialNote varchar DEFAULT NULL ,"// '物资备注'
                                  "MaterialState varchar DEFAULT NULL ,"// '物资状态'
                                  "FOREIGN KEY (CategoryID) REFERENCES  m_material_category(CategoryID)"
                                  " ON UPDATE CASCADE)")))
            return q.lastError();
        //库房表
        if (!q.exec(QLatin1String("CREATE TABLE  m_storage_room("
                                  "StorageRoomID  integer NOT NULL primary key,"//   '库房id'
                                  "StorageRoomName  varchar NOT NULL,"//'库房名字'
                                  "StorageRoomArea  varchar NOT NULL)")))//'库房面积'
            return q.lastError();

        //库存信息
        if (!q.exec(QLatin1String("CREATE TABLE  m_storage  ("
                                  " StorageID   integer NOT NULL primary key  ,"// '库存记录id'
                                  " StorageRoomID   integer NOT NULL ,"// '库房id'
                                  " MaterialID   integer NOT NULL ,"// '物资种类id'
                                  " StorageNumber   integer NOT NULL  ,"//'库存数量'
                                  "FOREIGN KEY ( StorageRoomID ) REFERENCES  m_storage_room  ( StorageRoomID ) "
                                  "ON UPDATE CASCADE,"
                                  "FOREIGN KEY ( MaterialID ) REFERENCES  m_material  ( MaterialID ) "
                                  "ON UPDATE CASCADE)")))
            return q.lastError();

        //用户表
        if (!q.exec(QLatin1String("CREATE TABLE  m_role  ("
                                  " RoleID   integer NOT NULL  primary key ,"//  '用户id'
                                  " RoleName  varchar NOT NULL ,"// '名称'
                                  " RoleSex  varchar DEFAULT NULL ,"// '性别'
                                  " RolePassword  varchar NOT NULL,"//  '密码'
                                  " RoleApartment  varchar NOT NULL  ,"//'部门'
                                  " RolePermission  varchar NOT NULL  ,"//'权限'
                                  " RolePhone  varchar NOT NULL)")))//'手机号'
            return q.lastError();

        //物资操作记录
        if (!q.exec(QLatin1String("CREATE TABLE  m_material_operateLog ("
                                  " ID integer NOT NULL primary key ,"// '物资操作记录'
                                  " MaterialID integer NOT NULL ,"// '物资id'
                                  " StorageRoomID   integer NOT NULL  ,"//'库房id'
                                  " RoleID   integer NOT NULL ,"// '用户id'
                                  " MaterialOperateNumber  varchar NOT NULL ,"// '更改数量'
                                  " MaterialOperateTime  varchar NOT NULL ,"// '物资更改时间'
                                  " MaterialOperateNote  varchar DEFAULT NULL,"//  '更改解释'
                                  "FOREIGN KEY ( MaterialID ) REFERENCES m_material  ( MaterialID )"
                                  " ON UPDATE CASCADE,"
                                  "FOREIGN KEY ( StorageRoomID ) REFERENCES  m_storage_room  ( StorageRoomID ) "
                                  "ON UPDATE CASCADE,"
                                  "FOREIGN KEY (`RoleID`) REFERENCES `m_role` (`RoleID`) "
                                  "ON UPDATE CASCADE)")))
            return q.lastError();

        //物资分类表
        //QLatin1String不支持中文
        if (!q.exec(QString("INSERT  INTO  m_material_category ( CategoryID , CategoryName ) VALUES (1,'电脑'),(2,'内存条'),(3,'显卡')")))
            return q.lastError();
        //物资种类表
        if (!q.exec(QString("INSERT  INTO  m_material ( MaterialID , MaterialName , CategoryID , MaterialNote , MaterialState ) VALUES (1,'Mac',1,'辣鸡dell','available'),(2,'dell',1,'辣鸡dell','available'),(3,'lenovo',1,'辣鸡Lenovo','available'),(4,'惠普',1,'辣鸡惠普 ','available'),(5,'三星',2,'三星牛逼','available'),(6,'Kingston',2,'金士顿牛逼','available'),(7,'嘤伟达',3,'intel','available'),(8,'RTX2080Ti',3,'充钱','available')")))
            return q.lastError();
        //库房表
        if (!q.exec(QString("INSERT  INTO  m_storage_room ( StorageRoomID , StorageRoomName , StorageRoomArea ) VALUES (1,'库房1','100m^2'),(2,'库房2','100m^2'),(3,'库房3','100m^2')")))
            return q.lastError();
        //库存信息
        if (!q.exec(QString("INSERT  INTO  m_storage ( StorageID , StorageRoomID , MaterialID , StorageNumber ) VALUES (1,1,1,100),(2,2,2,200),(3,3,3,300)")))
            return q.lastError();
        //用户表
        if (!q.exec(QString("INSERT  INTO  m_role ( RoleID , RoleName , RoleSex , RolePassword , RoleApartment , RolePermission , RolePhone ) VALUES (1,'hzk','男','hzk','背锅组','admin','110'),(2,'wzx','男','wzx','丢锅组','admin','110'),(3,'jyd','男','jyd','摸鱼组','admin','110')")))
            return q.lastError();
        //物资操作记录
//        if (!q.exec(QLatin1String("")))
//            return q.lastError();

//        if (!q.prepare(QLatin1String("insert into authors(name, birthdate) values(?, ?)")))
//            return q.lastError();
//        QVariant asimovId = addAuthor(q, QLatin1String("Isaac Asimov"), QDate(1920, 2, 1));
//        QVariant greeneId = addAuthor(q, QLatin1String("Graham Greene"), QDate(1904, 10, 2));
//        QVariant pratchettId = addAuthor(q, QLatin1String("Terry Pratchett"), QDate(1948, 4, 28));

//        if (!q.prepare(QLatin1String("insert into genres(name) values(?)")))
//            return q.lastError();
//        QVariant sfiction = addGenre(q, QLatin1String("Science Fiction"));
//        QVariant fiction = addGenre(q, QLatin1String("Fiction"));
//        QVariant fantasy = addGenre(q, QLatin1String("Fantasy"));

//        if (!q.prepare(QLatin1String("insert into material(title, year, author, genre, rating) values(?, ?, ?, ?, ?)")))
//            return q.lastError();
//        ads_dbook(q, QLatin1String("Foundation"), 1951, asimovId, sfiction, 3);


        //QDateTime::currentDateTime()
        return QSqlError();
    }
    else if(DATABASEDRIVER == "QMYSQL")
    {
        //本地数据库
        s_db.setDatabaseName("materialhouse");
        return QSqlError();
        //...//

    }
    else
    {
        return QSqlError("hzk: Driver not defined in Configuration.h");
    }

}


