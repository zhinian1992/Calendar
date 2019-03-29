#ifndef MONTHSUMMARY_H
#define MONTHSUMMARY_H

#include <QDate>
#include <vector>
#include <string>

class MonthSummary
{
public:
    MonthSummary(QDate date);

    std::string getSummaryByDay(int iDayInMonth);

private:
    void getMonthSummary();

private:
    QDate m_Date;                            //当前查询日期
    std::vector<std::string> m_SummaryList;  //任务概要(按日存)
};

#endif // MONTHSUMMARY_H
