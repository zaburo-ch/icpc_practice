#include "message_printer.h"
#include <iostream>

using namespace std;

message_printer::message_printer(): x(0), y(0) {
    cout << "construct" << endl;
}

message_printer::~message_printer(){
    cout << "destruct" << endl;
}
