#pragma once

#include <QLoggingCategory>

#ifdef DEBUG_LOG_CANVASPAINTER
Q_DECLARE_LOGGING_CATEGORY(logCanvasPainter)
    #define CANVASPAINTER_LOG(...) qCDebug(logCanvasPainter, __VA_ARGS__)
#else
    #define CANVASPAINTER_LOG(...) ((void) 0)
#endif

#ifdef DEBUG_LOG_FILEMANAGER
Q_DECLARE_LOGGING_CATEGORY(logFileManager)
    #define FILEMANAGER_LOG(...) qCDebug(logFileManager, __VA_ARGS__)
#else
    #define FILEMANAGER_LOG(...) ((void) 0)
#endif

void initLogCategory();