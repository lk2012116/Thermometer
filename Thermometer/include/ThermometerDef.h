#ifndef __THERMOMETERDEF_H__
#define __THERMOMETERDEF_H__

#include <QtCore/qglobal.h>

#if defined(THERMOMETER_LIB)
#define LIB_THERMOMETER_EXPORT Q_DECL_EXPORT
#else
#define LIB_THERMOMETER_EXPORT Q_DECL_IMPORT
#endif

#endif // __THERMOMETERDEF_H__