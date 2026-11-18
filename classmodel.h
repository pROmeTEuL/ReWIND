#ifndef CLASSMODEL_H
#define CLASSMODEL_H

#include <QAbstractListModel>
#include <QtQml/qqmlengine.h>
#include <vector>

struct ScheduleClassItem {
    QString name;
    QString location;
    QString startTime;
    QString endTime;
};

class ClassModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit ClassModel(QObject *parent = nullptr);

public slots:

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    void retreiveData();

private:
    std::vector<ScheduleClassItem> m_data;

};

#endif // CLASSMODEL_H
