#include "classmodel.h"

enum Roles {
    Name = Qt::UserRole,
    Location,
    StartTime,
    EndTime
};

classmodel::classmodel(QObject *parent)
    : QAbstractListModel{parent}
{}

int classmodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return -1;
    return m_data.size();
}

QVariant classmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};
    switch(role) {
    case Name:
        return m_data[index.row()].name;
    case Location:
        return m_data[index.row()].location;
    case StartTime:
        return m_data[index.row()].startTime;
    case EndTime:
        return m_data[index.row()].endTime;
    }

    return {};
}

QHash<int, QByteArray> classmodel::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { Name, "_name" },
        { Location, "_location" },
        { StartTime, "_startTime" },
        { EndTime, "_endTime" }
    };
    return roles;
}
