#include "schedulemodel.h"

enum Roles {
    Name = Qt::UserRole,
    Days
};

ScheduleModel::ScheduleModel(QObject *parent)
    : QAbstractListModel(parent)
{
    retreiveData();
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
    case Name:
        return m_data[index.row()].name;
    case Days:
        return QVariant::fromValue(m_data[index.row()].days);
    }

    return {};
}

QHash<int, QByteArray> ScheduleModel::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { Name, "_name" },
        { Days, "_days" }
    };
    return roles;
}

void ScheduleModel::retreiveData()
{
    // Using dummy values for testing purposes
    m_data.push_back(ScheduleItem {
        "Schedule 1"
    });
    m_data.push_back(ScheduleItem {
        "Schedule 2"
    });
}
