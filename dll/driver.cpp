#include "dll.h"
using namespace std;

int main()
{
    DLL aList;
    aList.insertAtHead("FIRST");
    aList.insertAtHead("SECOND");
    aList.insertAtHead("THIRD");
    aList.addInBetween("THIRD", "FOURTH");
    aList.addInBetween("SECOND", "EXCEPTION");
      aList.insertAtHead("FIRST");
    aList.insertAtHead("SECOND");
    aList.insertAtHead("THIRD");
    aList.addInBetween("THIRD", "FOURTH");
    aList.addInBetween("SECOND", "EXCEPTION");
    aList.dump();
    cout << endl;
    return 0;
}