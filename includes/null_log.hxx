#ifndef NULL_LOG_LIBRARY_NULL_LOG_HXX
#define NULL_LOG_LIBRARY_NULL_LOG_HXX

#include "QString"
#include "QDebug"
#include "iostream"
#include "null_log_export.hxx"

#define COLOR_BLUE_BOLD "\033[34;1m"
#define COLOR_GREEN_BOLD "\x1b[32;1m"
#define COLOR_YELLOW_BOLD "\x1b[33;1m"
#define COLOR_RED_BOLD "\x1b[31;1m"
#define COLOR_UNDERLINE "\x1b[39;4m"
#define COLOR_RESET "\033[0m"

class NULL_LOG_UTIL NullLog {
    public:
        static void setIsColorEnabled(bool result);
        static bool getIsColorEnabled(void);

    static QString info(const QString& tag, const QString& content);
    static QString info(const QString& tag, const QString& title, const QString& content);
    static QString ok(const QString& tag, const QString& content);
    static QString ok(const QString& tag, const QString& title, const QString& content);
    static QString warn(const QString& tag, const QString& content);
    static QString warn(const QString& tag, const QString& title, const QString& content);
    static QString error(const QString& tag, const QString& content);
    static QString error(const QString& tag, const QString& title, const QString& content);

    private:
        static bool isColorEnabled;
};

#endif //NULL_LOG_LIBRARY_NULL_LOG_HXX