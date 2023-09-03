#ifndef PENCILSETTINGS_H
#define PENCILSETTINGS_H

#include "pencildef.h"
#include <QObject>
#include <QSettings>

QSettings &pencilSettings();
void restoreToDefaultSetting();

void restoreShortcutsToDefault();
void checkExistingShortcuts();

#endif//PENCILSETTINGS_H