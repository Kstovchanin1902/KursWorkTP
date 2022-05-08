#ifndef AIH
#define AIH

#include <vector>
#include "../../field_m/fieldMask_m/fieldMask.h"
#include "../player.h"
#include "../../step_m/step.h"

class ai : public player
{
private:
    std::vector<step> stepVec ; //vector of step
protected:
    /*
        figure* fgs ; //figures array
        int number ; //number of player
        //count figures on the desk on the start game moment
        int countFgsOnD ; 
        int countFgs ; //count figures in the reserve
        bool color ; //figures color
    */


    //processing steps of figure
    //add all variable steps of single figure to stepVec
    //with using function push_back
    void prcssng_steps_fg ( figure &fgIn , fldMask &fMaskIn ,
                            int &size ) ;

public:
    ai () ;
    ~ai () ;

    int get_size_vect () override ;
    std::vector<step> get_vect_steps () override ;

    void refresh_steps ( field &fldIn ) override;
} ;
#endif
