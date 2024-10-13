#pragma once
#include <iostream>
using namespace std;

class AVN {
public:
    virtual ~AVN() {

    }
    virtual void NhapAVN() = 0;
    virtual void XuatAVN() = 0;
};
