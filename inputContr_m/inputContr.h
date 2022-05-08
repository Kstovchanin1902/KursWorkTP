#ifndef INPUTCONTRH
#define INPUTCONTRH

#include <string>
#include <limits>
#include <iostream>

class inputContr
{
private:
    static void ignore_input() ;
public:
    static int num ( std::string msg ) ;
    static int p_num( std::string msg ) ;
    static int n_num( std::string msg ) ;
} ;
#endif
