#ifndef MAIN_H
#define MAIN_H

const char Logo[] = { 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 
                      0x5F, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 
                      0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x5C, 
                      0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x7C, 0x20, 
                      0x20, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 
                      0x20, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x7C, 
                      0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x0A, 0x20, 
                      0x7C, 0x20, 0x20, 0x5F, 0x20, 0x20, 0x2F, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 
                      0x2F, 0x20, 0x7C, 0x2F, 0x20, 0x5F, 0x5F, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x5C, 
                      0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x5C, 0x20, 0x5C, 0x7C, 
                      0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x7C, 0x20, 
                      0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x7C, 0x5F, 0x7C, 0x5F, 0x5F, 0x5C, 0x5F, 0x5C, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 
                      0x20, 0x7C, 0x5F, 0x7C, 0x5F, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 0x5C, 0x5F, 0x5F, 0x5F, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x7C, 0x5F, 
                      0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x7C, 
                      0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20,
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x5F, 0x5F, 
                      0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 
                      0x20, 0x20, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 
                      0x7C, 0x20, 0x7C, 0x20, 0x27, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x5C, 0x2F, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 
                      0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x29, 0x20, 
                      0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 0x5C, 0x5F, 0x5F, 0x5F, 
                      0x2F, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x7C, 0x5F, 0x2E, 0x5F, 0x5F, 0x2F, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x5F, 0x2F, 
                      0x5C, 0x5F, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20};

#endif