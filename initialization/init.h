#ifndef INIT
#define INIT
#include <string>
#include <iostream>
#include <type_traits>

class init
{
public:
    //long long
    static long long* init_one_dimension_ll ( int iM ) ;
    static long long** init_two_dimension_ll ( int iM , int jM ) ;

    //int
    static int* init_one_dimension_int ( int iM ) ;
    static int** init_two_dimension_int ( int iM , int jM ) ;

    //short int
    static short int* init_one_dimension_sh ( int iM ) ;
    static short int** init_two_dimension_sh ( int iM , int jM ) ;

    //double
    static double* init_one_dimension_db ( int iM ) ;
    static double** init_two_dimension_db ( int iM , int jM ) ;

    //float
    static float* init_one_dimension_fl ( int iM ) ;
    static float** init_two_dimension_fl ( int iM , int jM ) ;

    //bool
    static bool* init_one_dimension_bl ( int iM ) ;
    static bool** init_two_dimension_bl ( int iM , int jM ) ;

    //std::string
    static std::string* init_one_dimension_str ( int iM ) ;
    static std::string** init_two_dimension_str ( int iM , int jM ) ;
} ;

#endif
