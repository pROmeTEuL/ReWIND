#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractListModel>
#include <vector>

class ScheduleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ScheduleModel();

public slots:
    void addSchedule(const QString &item);
    void removeSchedule(int index);


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    void retreiveData();

private:
    struct ScheduleClassItem {
        QString name;
        QString location;
        QString startTime;
        QString endTime;
    };
    struct ScheduleDayItem {
        QString day;
        std::vector<ScheduleClassItem> classes;
    };
    struct ScheduleItem {
        QString name;
        std::vector<ScheduleDayItem> days;
    };
    std::vector<ScheduleItem> m_data;
};

#endif // SCHEDULEMODEL_H
