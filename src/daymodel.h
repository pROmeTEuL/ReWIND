#ifndef DAYMODEL_H
#define DAYMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>

class DayModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit DayModel(QObject *parent = nullptr);
};

#endif // DAYMODEL_H
