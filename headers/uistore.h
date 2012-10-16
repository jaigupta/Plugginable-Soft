#ifndef UISTORE_H
#define UISTORE_H

#include "cmenu.h"

class UiStore
{
public:
    UiStore();
    CMenu* RootMenu;
    CMenu* getRootMenu();
};

#endif // UISTORE_H
