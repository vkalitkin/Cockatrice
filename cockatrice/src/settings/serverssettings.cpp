#include "serverssettings.h"

ServersSettings::ServersSettings(QString settingPath, QObject *parent)
        : SettingsManager(settingPath + "servers.ini", parent)
{
}

void ServersSettings::setPreviousHostLogin(int previous)
{
    setValue(previous, "previoushostlogin", "server");
}

bool ServersSettings::getDlgConnectShouldCheckPreviousHost()
{
    return getValueWithDefault("previoushostlogin", true, "server").toBool();
}

void ServersSettings::setKnownHosts(QStringList list)
{
    setValue(list, "previoushosts", "server");
}

QStringList ServersSettings::getKnownHosts()
{
    const QStringList &hosts = getValue("previoushosts", "server").toStringList();
    if (hosts.isEmpty())
        return getDefaultHosts();
    return hosts;
}

void ServersSettings::setPreviousHostIndex(int index)
{
    setValue(index, "previoushostindex", "server");
}

int ServersSettings::getPreviousHostIndex()
{
    return getValue("previoushostindex", "server").toInt();
}

void ServersSettings::setHostName(QString hostname)
{
    setValue(hostname, "hostname", "server");
}

void ServersSettings::setPort(QString port)
{
    setValue(port, "port", "server");
}

QString ServersSettings::getPort(QString defaultPort)
{
    return getValueWithDefault("port", defaultPort, "server").toString();
}

void ServersSettings::setPlayerName(QString playerName)
{
    setValue(playerName, "playername", "server");
}

QString ServersSettings::getPlayerName(QString defaultName)
{
    return getValueWithDefault("playername", defaultName, "server").toString();
}

void ServersSettings::setPassword(QString password)
{
    setValue(password, "password", "server");
}

QString ServersSettings::getPassword()
{
    return getValue("password", "server").toString();
}

void ServersSettings::setShouldSavePassword(bool save)
{
    setValue(save, "save_password", "server");
}

bool ServersSettings::shouldSavePassword()
{
    return getValueWithDefault("save_password", false, "server").toBool();
}

void ServersSettings::setShouldAutoconnect(int autoconnect)
{
    setValue(autoconnect, "auto_connect", "server");
}

bool ServersSettings::shouldAutoconnect()
{
    return getValueWithDefault("auto_connect", false, "server").toBool();
}

std::tuple<QString, int> ServersSettings::getMostRecentServerConnectionInfo()
{
    QString host = getKnownHosts().at(getPreviousHostIndex());
    int port = 4747;
    return std::make_tuple(host, port);
};

