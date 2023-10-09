#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <qstring.h>

class MySingleton
{
private:
    static MySingleton* instance;
    QString accountId;

public:
    static MySingleton* getInstance();

    QString getAccountId() const;
    void setAccountId(const QString &newAccountId);
};

#endif // MYSINGLETON_H
