#include "null_log.hxx"

bool NullLog::isColorEnabled = true;

void NullLog::setIsColorEnabled(bool result) {
    NullLog::isColorEnabled = result;
}

bool NullLog::getIsColorEnabled() {
    return NullLog::isColorEnabled;
}

QString NullLog::info(const QString& tag, const QString& content) {
    if(!isColorEnabled) qInfo().noquote() << "[INFO] " + tag + ": " + content;
    else qInfo().noquote() << COLOR_BLUE_BOLD "[INFO] " + tag +  COLOR_RESET + ": " + content;
    return "[INFO] " + tag + ": " + content;
}

QString NullLog::info(const QString& tag, const QString& title, const QString& content) {
    if(!isColorEnabled) qInfo().noquote() << "[INFO] " + tag + " - " + title + ": " + content;
    else qInfo().noquote() << COLOR_BLUE_BOLD "[INFO] " + tag + " - " + COLOR_UNDERLINE + title + COLOR_RESET +  ": " + content;
    return "[INFO] " + tag + " - " + title + ": " + content;
}

QString NullLog::ok(const QString& tag, const QString& content) {
    if(!isColorEnabled) qInfo().noquote() << "[ OK ] " + tag + ": " + content;
    else qInfo().noquote() << COLOR_GREEN_BOLD "[ OK ] " + tag +  COLOR_RESET + ": " + content;
    return "[ OK ] " + tag + ": " + content;
}

QString NullLog::ok(const QString& tag, const QString& title, const QString& content) {
    if(!isColorEnabled) qInfo().noquote() << "[ OK ] " + tag + " - " + title + ": " + content;
    else qInfo().noquote() << COLOR_GREEN_BOLD "[ OK ] " + tag + " - " + COLOR_UNDERLINE + title + COLOR_RESET +  ": " + content;
    return "[ OK ] " + tag + " - " + title + ": " + content;
}

QString NullLog::warn(const QString& tag, const QString& content) {
    if(!isColorEnabled) qWarning().noquote() << "[WARN] " + tag + ": " + content;
    else qWarning().noquote() << COLOR_YELLOW_BOLD "[WARN] " + tag +  COLOR_RESET + ": " + content;
    return "[WARN] " + tag + ": " + content;
}

QString NullLog::warn(const QString& tag, const QString& title, const QString& content) {
    if(!isColorEnabled) qWarning().noquote() << "[WARN] " + tag + " - " + title + ": " + content;
    else qWarning().noquote() << COLOR_YELLOW_BOLD "[WARN] " + tag + " - " + COLOR_UNDERLINE + title + COLOR_RESET +  ": " + content;
    return "[WARN] " + tag + " - " + title + ": " + content;
}

QString NullLog::error(const QString& tag, const QString& content) {
    if(!isColorEnabled) qCritical().noquote() << "[ERROR] " + tag + ": " + content;
    else qCritical().noquote() << COLOR_RED_BOLD "[ERROR] " + tag +  COLOR_RESET + ": " + content;
    return "[ERROR] " + tag + ": " + content;
}

QString NullLog::error(const QString& tag, const QString& title, const QString& content) {
    if(!isColorEnabled) qCritical().noquote() << "[ERROR] " + tag + " - " + title + ": " + content;
    else qCritical().noquote() << COLOR_RED_BOLD "[ERROR] " + tag + " - " + COLOR_UNDERLINE + title + COLOR_RESET +  ": " + content;
    return "[ERROR] " + tag + " - " + title + ": " + content;
}