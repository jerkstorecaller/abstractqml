#ifndef MAINAPP_H
#define MAINAPP_H

#include <QObject>
#include "Definitions.h"

class MainApp : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON


    //The list of connections this app tries to maintain.
    Q_PROPERTY(QList<IDeviceLink*> links READ getLinks NOTIFY linksChanged)

    QList<IDeviceLink*> m_links;

public:
    explicit MainApp(QObject *parent = nullptr);

    QList<IDeviceLink*> getLinks() const
    {
        return m_links;
    }


    Q_INVOKABLE void createLink() {
        auto l = new SimDeviceLink;
        m_links.push_back(l);
        emit linksChanged(m_links);
    }

signals:

    void linksChanged(QList<IDeviceLink*> links);
};

#endif // MAINAPP_H
