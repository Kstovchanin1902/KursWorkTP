#ifndef GVIEWH
#define GVIEWH

#include <iostream>
#include <string>
#include "../../player_m/player.h"
#include "../../field_m/field.h"
#include "../../field_m/fieldMask_m/fieldMask.h"

class gView
{
private:
    static void print_underline ( int num ) ;
public:
    static const int countFCircle = 2 ;
    static const int countSCircle = 5 ;
    static const int countTCircle = 2 ;

    //function print commands of first circle
    static void print_f_cmds () ;

    //function print commands of second circle
    static void print_s_cmds () ;

    //function print commands of third circle
    static void print_t_cmds () ;

    //function print game info namely of field and players
    static void print_info_game ( field &fldIn , player &pl1In ,
                                    player &pl2In ) ;

    //finction print info of player
    static void print_info_player ( player &plIn ) ;

    //function print info of field
    static void print_info_field ( field &fldIn ) ;

    //function of messaging of winner player
    static void print_winner ( short int colorIn , player &plIn ) ;

    //function of print whose is turn
    static void print_whose_turn ( bool chPlayerIn ,
                                    player &plIn ) ;

} ;

    static const std::string fCircle[gView::countFCircle] = 
    {
        "10 - start game          ",
        "0  - exit                "
    } ;

    static const std::string sCircle[gView::countSCircle] =
    {
        "1  - move                ",
        "19 - surrend             ",
        "81 - print info of game  ",
        "82 - print info of player",
        "83 - print info of field ",
    } ;

    static const std::string tCircle[gView::countTCircle] =
    {
        "1 - set figure           ",
        "3 - surrend              "
    } ;

#endif
