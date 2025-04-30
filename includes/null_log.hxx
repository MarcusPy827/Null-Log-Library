#ifndef NULL_LOG_LIBRARY_NULL_LOG_HXX
#define NULL_LOG_LIBRARY_NULL_LOG_HXX

#include "QString"
#include "QDebug"
#include "null_log_export.hxx"

class NULL_LOG_UTIL NullLog {
    public:
        static void setIsColorEnabled(bool result);
        static bool getIsColorEnabled(void);

        static void info(const QString& tag, const QString& content);
        static void info(QString tag, QString title, QString content);
        static void info(QString tag, QString title, QString subtitle, QString content);

    private:
        static bool isColorEnabled;
};

#endif //NULL_LOG_LIBRARY_NULL_LOG_HXX