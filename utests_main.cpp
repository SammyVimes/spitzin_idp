#include <QtTest/QtTest>
#include <QFile>
#include "dataprovider.h"

class UTests: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testDbOpen();
    void testDbClose();
    void testDbCreate();
    void testDbInsert();
    void testDbSelect();
    void testRandom();
};


//инициализация "среды" тестирования
void UTests::initTestCase()
{
    QFile("test_db.sqlite").remove();
}


//удаляем всё, созданное во время тестирования
void UTests::cleanupTestCase()
{
    QFile("test_db.sqlite").remove();
}


/**
 * Тест соединения с SQLite базой данных
 * @brief UTests::testDbOpen
 */
void UTests::testDbOpen()
{
    DataProvider* dataProvider = new DataProvider();
    dataProvider->init("test_db.sqlite");
    {
        QSqlDatabase db = dataProvider->_getDatabase();
        bool isOpen = db.open();
        QCOMPARE(isOpen, true);
    }

    QString connectionName = dataProvider->close();
    delete dataProvider;
    QSqlDatabase::removeDatabase(connectionName);
}

/**
 * Тест закрытия соединения
 * @brief UTests::testDbClose
 */\
void UTests::testDbClose()
{
    DataProvider* dataProvider = new DataProvider();
    dataProvider->init("test_db.sqlite");

    QString connectionName = dataProvider->close();
    delete dataProvider;
    QSqlDatabase::removeDatabase(connectionName);
    bool contains = QSqlDatabase::contains(connectionName);
    QCOMPARE(contains, false);
}

/**
 * Тест создания таблицы "events" в базе данных
 * @brief UTests::testDbCreate
 */
void UTests::testDbCreate()
{
    DataProvider* dataProvider = new DataProvider();
    dataProvider->init("test_db.sqlite");
    {
        QSqlDatabase db = dataProvider->_getDatabase();
        bool initSuccess = false;
        if (db.tables().contains(QLatin1String("events"))) {
            initSuccess = true;
        }
        QCOMPARE(initSuccess, true);
    }

    QString connectionName = dataProvider->close();
    delete dataProvider;
    QSqlDatabase::removeDatabase(connectionName);
}

/**
 * Тест вставки события в таблицу events
 * @brief UTests::testDbInsert
 */\
void UTests::testDbInsert()
{
    DataProvider* dataProvider = new DataProvider();
    dataProvider->init("test_db.sqlite");
    MSISDN msisdn("+79215988738");
    QString txt("Text");
    QDateTime dTime(QDate(2015, 12, 12), QTime(12, 12));
    dataProvider->insertVal(StatEvent(msisdn, txt, dTime));
    QList<StatEvent> stats = dataProvider->selectByDateAndMsisdn(msisdn, dTime);
    QCOMPARE(stats.size(), 1);

    QString connectionName = dataProvider->close();
    delete dataProvider;
    QSqlDatabase::removeDatabase(connectionName);
}


/**
 * Тест выборки из базы данных
 * @brief UTests::testDbSelect
 */
void UTests::testDbSelect()
{
    QFile("test_db.sqlite").remove();
    DataProvider* dataProvider = new DataProvider();
    dataProvider->init("test_db.sqlite");
    MSISDN msisdn("+79215988738");
    QString txt("Text");
    QDateTime dTime(QDate(2015, 12, 12), QTime(12, 12));
    dataProvider->insertVal(StatEvent(msisdn, txt, dTime));
    QList<StatEvent> stats = dataProvider->selectByDateAndMsisdn(msisdn, dTime);
    StatEvent e = stats.at(0);
    QString loadedText = e.getEventText();
    QCOMPARE(loadedText, txt);

    QString connectionName = dataProvider->close();
    delete dataProvider;
    QSqlDatabase::removeDatabase(connectionName);
}

/**
 * Тест рандома
 * @brief UTests::testRandom
 */
void UTests::testRandom()
{
    QVERIFY(random(0, 1000) != random(0, 1000));
}

QTEST_MAIN(UTests)
#include "utests_main.moc"
