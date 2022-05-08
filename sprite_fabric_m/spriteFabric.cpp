#include "spriteFabric.h"

//Private section







//Public section

std::string spriteFabric::product_sprite ( int num )
{
    std::string result = "" ;
    result += "(" ;
    result += 48 + num ;
    result += ")" ;
    return result ;
}
