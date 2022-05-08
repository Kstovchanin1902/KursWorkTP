#ifndef PLCONTRH
#define PLCONTRH

#include <iostream>
#include <limits>
#include <string> 
#include <cmath>
#include "plLogic_m/plLogic.h"
#include "../../inputContr_m/inputContr.h"

class plContr
{
private:

    int* input_crd( int size , std::string msg ) ;
    int* input_start_mv_crd( bool color , field &fldIn ) ;
    int* input_end_mv_crd( int* &scrCrd , bool color , field &fldIn ) ;
    int* input_start_crd( int size , bool color ,
                                std::string msg ) ;

protected:
    plLogic plLg ;
    int* moving( player &plIn , field &fldIn ) ;

    int kill_enemy_fgs( int* &srcCrd , field &fldIn ) ;
    int check_to_die( int* &srcCrd , field &fldIn ) ;
    int check_to_set( int* &srcCrd , int* &resCrd ,
                        field &fldIn ) ;

    int calc_local_min_crd( int count , int src ) ;
    int calc_local_max_crd( int count , int src , int size ) ;

public:
    plContr() {} ;

    int set_start_figure( player &plIn , field &fldIn ) ;

    int set_figure( int* &setCrd , player &plIn , field &fldIn ) ;

    int move( player &plIn , field &fldIn , int* &setCrd ) ;

} ;
#endif
