#include "evFunc.h"
//Private Section







//Public Section

int evFunc::ev_function ( int countFODFrnd , int countFODEnem ,
                            int countAFgsFrnd ,
                            int countAFgsEnem ) 
{
    int subFOD = countFODFrnd - countFODEnem ;
    int countResFrnd = countAFgsFrnd - countFODFrnd ;
    int countResEnem = countAFgsEnem - countFODEnem ;
    int subRes = countResFrnd - countResEnem ;

    return 5*subFOD - subRes ;
}
