#include "schedulemodel.h"

ScheduleModel::ScheduleModel()
{

}

void ScheduleModel::addSchedule(const QString &item)
{

}

void ScheduleModel::removeSchedule(int index)
{

}

int ScheduleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return -1;
    return m_data.size();
}

QVariant ScheduleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};
    return {};
}

QHash<int, QByteArray> ScheduleModel::roleNames() const
{
    static const QHash<int, QByteArray> roles {

    };
    return roles;
}

void ScheduleModel::retreiveData()
{

}
