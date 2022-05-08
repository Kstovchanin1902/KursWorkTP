#ifndef PLAYERH
#define PLAYERH

#include <vector>
#include "../step_m/step.h"
#include "../field_m/field.h"
#include "../sprite_fabric_m/spriteFabric.h"

static int countPlayers = 0 ;

class player
{
private:
protected:
    figure* fgs ; //figures array
    int aiChecker ; //for Player = false , for AI = true
    int number ; //number of player
    //count figures on the desk on the start game moment
    int countFgsOnD ; 
    int countFgs ; //count figures in the reserve
    bool color ; //figures color

    bool check_all_conditions () ;
    void decr_count_fg () ;
    void free_fgs () ;
public:
    player () ;
    ~player () ;

    int get_count_lives_fgs () ;

    int get_count_fgs_on_d () ;
    void set_count_fgs_on_d ( int countIn ) ;

    int get_count_fgs () ;
    void set_count_fgs ( int countIn ) ;

    bool get_color () ;
    void set_color ( bool colorIn ) ;

    figure* get_point_fg ( int indxIn ) ;
    figure** get_point_fgs () ;
    bool kill_fg ( int indxIn ) ;

    virtual std::vector<step> get_vect_steps () ;
    virtual void refresh_steps ( field &fldIn ) {} ;
    virtual int get_size_vect () { return 0 ; } ;

    int get_indx_dead_fg () ;
    bool set_fg ( int indxIn , int* &crd ) ;

    bool get_check_ai () ;

    bool generate_fgs () ;

    int get_num () ;

    void print_info () ;
};
#endif
