#include <QtCore/QtGlobal>

#ifdef CORE_LIBRARY
#define PENCILCORE_EXPORT Q_DECL_EXPORT
#else
#define PENCILCORE_EXPORT Q_DECL_IMPORT
#endif