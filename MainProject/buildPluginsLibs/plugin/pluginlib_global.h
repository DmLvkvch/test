#ifndef PLUGINLIB_GLOBAL_H
#define PLUGINLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGINLIB_LIBRARY)
#  define PLUGINLIB_EXPORT Q_DECL_EXPORT
#else
#  define PLUGINLIB_EXPORT Q_DECL_IMPORT
#endif


#endif // PLUGINLIB_GLOBAL_H
