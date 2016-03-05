#ifndef SERVERSSETTINGS_H
#define SERVERSSETTINGS_H

#include "settingsmanager.h"
#include <QObject>


class ServersSettings : public SettingsManager
{
    Q_OBJECT
    friend class SettingsCache;

public:
    QStringList getDefaultHosts() {
       return QStringList()
              << "cockatrice.woogerworks.com"
              << "vps.poixen.com"
              << "chickatrice.net";
    }

    bool getDlgConnectShouldCheckPreviousHost();
    QStringList getKnownHosts();
    int getPreviousHostIndex();
    QString getPort(QString defaultPort = "");
    QString getPlayerName(QString defaultName = "");
    QString getPassword();
    bool shouldSavePassword();
    bool shouldAutoconnect();
    std::tuple<QString, int> getMostRecentServerConnectionInfo();

    void setPreviousHostLogin(int previous);
    void setKnownHosts(QStringList list);
    void setPreviousHostIndex(int index);
    void setHostName(QString hostname);
    void setPort(QString port);
    void setPlayerName(QString playerName);
    void setPassword(QString password);
    void setShouldSavePassword(bool shouldSavePassword);
    void setShouldAutoconnect(int autoconnect);

signals:

public slots:

private:
    ServersSettings(QString settingPath, QObject *parent = 0);
    ServersSettings( const ServersSettings& /*other*/ );
    ServersSettings( ServersSettings& /*other*/ );
    ServersSettings( volatile const ServersSettings& /*other*/ );
    ServersSettings( volatile ServersSettings& /*other*/ );

};

#endif // SERVERSSETTINGS_H
