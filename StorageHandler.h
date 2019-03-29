#ifndef STORAGEHANDLER_H
#define STORAGEHANDLER_H

#include <QDate>
#include <vector>
#include <string>

class StorageHandler
{
public:
    StorageHandler();

    std::vector<std::string> readSummaryByMonth(QDate date);

private:
    void ReadFromFile();
};

#endif // STORAGEHANDLER_H
