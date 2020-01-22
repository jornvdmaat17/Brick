
namespace Brick {

    class Logger {

        static void logClientInfo(const char *msg, ...);
        static void logClientWarn(const char *msg, ...);
        static void logClientError(const char *msg, ...);

        static void logBrickInfo(const char *msg, ...);
        static void logBrickWarn(const char *msg, ...);
        static void logBrickError(const char *msg, ...);
    };

}