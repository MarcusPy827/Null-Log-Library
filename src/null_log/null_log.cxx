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
    else result = COLOR_BLUE_BOLD "[INFO] " + tag +  COLOR_RESET + ": " + content;
    qInfo().noquote() << result;
    return result;
}

QString NullLog::info(const QString& tag, const QString& title, const QString& content) {
    QString result;
    if(!isColorEnabled) result = "[INFO] " + tag + " - " + title + ": " + content;
    else result = COLOR_BLUE_BOLD "[INFO] " + tag + " - " + COLOR_UNDERLINE + title + COLOR_RESET +  ": " + content;
    qInfo().noquote() << result;
    return result;
}