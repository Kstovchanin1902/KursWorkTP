#ifndef PLLOGICH
#define PLLOGICH

#include <string>
#include <iostream>
#include "../../../field_m/fieldMask_m/fieldMask.h"
#include "../../../player_m/player.h"

class plLogic
{
private:
    int dec_vect ( int sub , int res ) ;
public:
    bool check_step ( int* &srcCrd , int* &resCrd , field &fldIn) ;

    int check_out_of_range ( int num , int size ,
                                std::string &eMsg) ;
    int check_opt_out_of_range ( int num , int min , int max ,
                                std::string &eMsg ) ;
    int check_crd_out_of_range ( int* &crd , int size ) ;
    int check_crd_opt_out_of_range ( int* &crd , int min ,
                                int max ) ;
    int check_s_out_of_range ( int* &crd , int size ,
                                bool color ) ;
    int check_crd_color ( int* &crd , std::string &eMsg ) ;

    //Checked the conditions to equals of
    //count lives figures and count figures on the desk
    //return false if needed in figures
    //else return true
    bool check_of_needed_in_fg ( player &plIn ) ;

    bool check_color_fg ( int* &crd , bool color , field &fldIn ) ;

    bool check_condit_st_mv ( int* &crd , bool color ,
                                    field &fldIn ) ;
    bool check_condit_end_mv ( int* &srcCrd , int* &resCrd ,
                                    bool color , field &fldIn ) ;

    std::string choise_str_color ( bool color ) ;
} ;
#endif
