#include "null_log.hxx"

bool NullLog::isColorEnabled = true;

void NullLog::setIsColorEnabled(bool result) {
    NullLog::isColorEnabled = result;
}

bool NullLog::getIsColorEnabled() {
    return NullLog::isColorEnabled;
}

QString NullLog::info(const QString& tag, const QString& content) {
    QString result;
    if(!isColorEnabled) result = "[INFO] " + tag + ": " + content;
    else result = "\x1b[34;1m[INFO] " + tag + "\x1b[0m: " + content;
    qDebug() << result;
    return result;
}