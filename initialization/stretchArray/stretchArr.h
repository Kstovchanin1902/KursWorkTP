#ifndef STRETCHARR
#define STRETCHARR

#include "../init.h"

class stretchArr
{
private :
public :
    //long long
    static long long* rsz_arr_once_ll ( long long* src , int &iM ) ;
    static long long* rsz_add_arr_once_ll ( long long* src ,
            long long data , int &iM ) ;
    static long long** rsz_arr_twice_ll ( long long** src ,
            int &iM , int &jM ) ;
    static long long** rsz_add_arr_twice_ll ( long long** src ,
            long long* data , int &iM , int &jM ) ;
    //int
    static int* rsz_arr_once_int ( int* src , int &iM ) ;
    static int* rsz_add_arr_once_int ( int* src , int data , int &iM ) ;
    static int** rsz_arr_twice_int ( int** src , int &iM , int &jM ) ;
    static int** rsz_add_arr_twice_int ( int** src , int* data , int &iM ,
            int &jM ) ;
    //short int
    static short int* rsz_arr_once_sh ( short int* src , int &iM ) ;
    static short int* rsz_add_arr_once_sh ( short int* src ,
            short int data , int &iM ) ;
    static short int** rsz_arr_twice_sh ( short int** src ,
            int &iM , int &jM ) ;
    static short int** rsz_add_arr_twice_sh ( short int** src ,
            short int* data , int &iM , int &jM ) ;
    //double
    static double* rsz_arr_once_db ( double* src , int &iM ) ;
    static double* rsz_add_arr_once_db ( double* src ,
            double data , int &iM ) ;
    static double** rsz_arr_twice_db ( double** src ,
            int &iM , int &jM ) ;
    static double** rsz_add_arr_twice_db ( double** src ,
            double* data , int &iM , int &jM ) ;
    //float
    static float* rsz_arr_once_fl ( float* src , int &iM ) ;
    static float* rsz_add_arr_once_fl ( float* src ,
            float data , int &iM ) ;
    static float** rsz_arr_twice_fl ( float** src ,
            int &iM , int &jM ) ;
    static float** rsz_add_arr_twice_fl ( float** src ,
            float* data , int &iM , int &jM ) ;
    //bool
    static bool* rsz_arr_once_bl ( bool* src , int &iM ) ;
    static bool* rsz_add_arr_once_bl ( bool* src , bool data , int &iM ) ;
    static bool** rsz_arr_twice_bl ( bool** src , int &iM , int &jM ) ;
    static bool** rsz_add_arr_twice_bl ( bool** src , bool* data , int &iM ,
            int &jM ) ;
    //string
    static std::string* rsz_arr_once_str ( std::string* src ,
            int &iM ) ;
    static std::string* rsz_add_arr_once_str ( std::string* src ,
            std::string data , int &iM ) ;
    static std::string** rsz_arr_twice_str ( std::string** src , int &iM , int &jM ) ;
    static std::string** rsz_add_arr_twice_str ( std::string** src ,
            std::string* data , int &iM , int &jM ) ;
} ;

#endif
