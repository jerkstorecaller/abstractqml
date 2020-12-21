#ifndef IDEVICELINK_H
#define IDEVICELINK_H

#include <QObject>
#include <QtQml>

//Abstract interface for all subclasses
class IDeviceLink: public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(QString deviceName READ deviceName NOTIFY deviceNameChanged)
    Q_PROPERTY(uint uptime READ uptime NOTIFY uptimeChanged);

    bool m_connected;

    QString m_deviceName;

    uint m_uptime;

public:
    Q_INVOKABLE virtual void connect() = 0;
    Q_INVOKABLE virtual void doPoll() = 0;



signals:
    void connectionEstablished();
    void connectionLost();
    void pollCompleted();

    void connectedChanged(bool connected);

    void deviceNameChanged(QString deviceName);

    void uptimeChanged(uint uptime);

protected:
    explicit IDeviceLink(QObject* parent = nullptr): QObject(parent) {}

    virtual bool connected() const
    {
        return m_connected;
    }

    virtual QString deviceName() const
    {
        return m_deviceName;
    }

    virtual uint uptime() const
    {
        return m_uptime;
    }
};

//Concrete implementation example
class SimDeviceLink: public IDeviceLink
{
    Q_OBJECT

public:
    explicit SimDeviceLink(QObject* parent = nullptr): IDeviceLink(parent) {}

Q_INVOKABLE virtual void connect() { emit connectionEstablished(); }
Q_INVOKABLE virtual void doPoll() { emit pollCompleted(); }

    virtual bool connected() const { return true; }
    virtual QString deviceName() const { return "sim"; };
    virtual uint uptime() const { return 123; }

signals:
    void connectionEstablished();
    void connectionLost();
    void pollCompleted();

    void connectedChanged(bool connected);
    void deviceNameChanged(QString deviceName);
    void uptimeChanged(uint uptime);
};



#endif // IDEVICELINK_H
