#pragma once
#include "Stack.h"
#include "ConsoleIO.h"

class StackIO {
public:
    static void InputElement(Stack& stack);
    static void FillStack(Stack& stack);
    static void ShowTop(const Stack& stack);
    static void Output(const Stack& stack);
    static void ShowMenu(Stack& stack);
};