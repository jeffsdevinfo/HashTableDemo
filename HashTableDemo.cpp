#include <iostream>
#include "Base.h"
#include "LinearProbingHashTable.h"

int main()
{
    Base* runPtr = nullptr;
    runPtr = new LinearProbingHashTableExecutor();
    runPtr->Run();
}