/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: matega
 *
 * Created on 16 February 2023, 10:37
 */

#include <cstdlib>
#include <sys/io.h>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
void ECRamWriteWM2(unsigned short address, unsigned char data) {
    unsigned char reg_addr = 78;
    unsigned char reg_data = 79;
    
    unsigned char addr_upper = (unsigned char)(address >> 8 & 255);
    unsigned char addr_lower = (unsigned char)(address & 255);
    
    outb(46, reg_addr);
    outb(17, reg_data);
    outb(47, reg_addr);
    outb(addr_upper, reg_data);
    
    outb(46, reg_addr);
    outb(16, reg_data);
    outb(47, reg_addr);
    outb(addr_lower, reg_data);
    
    outb(46, reg_addr);
    outb(18, reg_data);
    outb(47, reg_addr);
    outb(data, reg_data);
}

int main(int argc, char** argv) {
    #define GPDW2_ECRAM 78

    if(argc != 2) exit(-1);
    
    int x = atoi(argv[1]);
    
    if(argv[1][0] != 'a' && (x < 0 || x > 255)) {
        exit(-1);
    } 

    if (ioperm(GPDW2_ECRAM, 2, 1)) {
        cout << "Failed to request access\n";
        exit(-1);
     /* handle error */
    }
    
    if(argv[1][0] == 'a') {
        cout << "Setting auto fan" << endl;
        ECRamWriteWM2(629,0);
    } else {
        cout << "Setting fan speed " << to_string(x) << endl;
        ECRamWriteWM2(629,1);
        ECRamWriteWM2(6153,x);
    }

    if (ioperm(GPDW2_ECRAM, 2, 0)) {
        cout << "Failed to release access\n";
        exit(-1);
     /* handle error */
    }

    return 0;
}

