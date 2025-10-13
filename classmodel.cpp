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
    case Schedule:
        return m_data[index.row()].name;
    case Days:
        return QVariant::fromValue(m_data[index.row()].days);
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
