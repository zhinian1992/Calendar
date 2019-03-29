#include "MonthSummary.h"
#include "StorageHandler.h"

MonthSummary::MonthSummary(QDate date):m_Date(date)
{
    m_SummaryList.clear();
}

std::string MonthSummary::getSummaryByDay(int iDayInMonth)
{
    if(m_SummaryList.empty())
        getMonthSummary();
    return m_SummaryList[iDayInMonth - 1];

}

void MonthSummary::getMonthSummary()
{
    StorageHandler sHandle;
    m_SummaryList = sHandle.readSummaryByMonth(m_Date);
    return;
}
