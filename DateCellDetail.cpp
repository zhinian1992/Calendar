#include "DateCellDetail.h"

DateCellDetail::DateCellDetail(QDate date):m_Date(date),m_MonSum(NULL)
{

}

DateCellDetail::~DateCellDetail()
{
    delete m_MonSum;
    m_MonSum = NULL;
}

std::string DateCellDetail::getSummaryByDay(int iDayInMonth)
{
    if(m_MonSum == NULL)
        m_MonSum = new MonthSummary(m_Date);
    return  m_MonSum->getSummaryByDay(iDayInMonth);
}
