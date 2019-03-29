#ifndef DATECELLDETAIL_H
#define DATECELLDETAIL_H

#include <QDate>
#include <vector>
#include "MonthSummary.h"


class DateCellDetail
{
public:
    DateCellDetail(QDate date);

    ~DateCellDetail();

    std::string getSummaryByDay(int iDayInMonth);

private:


private:
    QDate m_Date;

    MonthSummary *m_MonSum;
};

#endif // DATECELLDETAIL_H
