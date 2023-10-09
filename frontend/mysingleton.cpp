#include "mysingleton.h"

MySingleton* MySingleton::instance = nullptr;

QString MySingleton::getAccountId() const
{
    return accountId;
}

void MySingleton::setAccountId(const QString &newAccountId)
{
    accountId = newAccountId;
}

MySingleton* MySingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MySingleton();
    }

    return instance;
}


