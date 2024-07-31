#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Book.h"
#include "Reader.h"

class InputHandler {
public:
    static Book inputBook();
    static Reader inputReader();
};

#endif // INPUTHANDLER_H
