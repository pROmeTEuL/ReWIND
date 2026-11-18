#include "schedulemodel.h"

enum Roles {
    Schedule = Qt::UserRole,
    Days
};

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
    switch(role) {
    case Schedule:
        return m_data[index.row()].name;
    case Days:
        return QVariant::fromValue(m_data[index.row()].days);
    }

    return {};
}

QHash<int, QByteArray> ScheduleModel::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { Schedule, "_schedule" },
        { Days, "_days" }
    };
    return roles;
}

void ScheduleModel::retreiveData()
{
    /// TODO: Implement data retrieval from database
}
