#ifndef OPTIONSXML_H
#define OPTIONSXML_H

#include <QObject>
#include <QDomElement>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QSettings>

class OptionsXML : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16 port READ getPort WRITE setPort NOTIFY portChanged)
public:
    OptionsXML();

public slots:
    void persistConfig();
    void readConfig();
    qint16 getPort(){ return m_port; }
    void setPort(qint16 port){
        m_port = port;
        emit portChanged();
    }

signals:
    void portChanged();
private:
    static const QString APPPORT;
    QSettings m_options;
    qint16 m_port;
};

#endif // OPTIONSXML_H