#ifndef SCRIPTLOADHELPERS_GLOBAL_H
#define SCRIPTLOADHELPERS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SCRIPTLOADHELPERS_LIBRARY)
#  define SCRIPTLOADHELPERSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SCRIPTLOADHELPERSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SCRIPTLOADHELPERS_GLOBAL_H