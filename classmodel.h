#ifndef CLASSMODEL_H
#define CLASSMODEL_H

#include <QAbstractListModel>
#include <vector>

struct ScheduleClassItem {
    QString name;
    QString location;
    QString startTime;
    QString endTime;
};

class classmodel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit classmodel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

};

#endif // CLASSMODEL_H
