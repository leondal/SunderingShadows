#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_long("%^MAGENTA%^You are traveling a small path in the mountains.%^RESET%^\n"
        "All around you the treacherous peaks of the Thoradin Range rise up "
        "like daggers through the clouds. Right now you are traveling between "
        "the peaks in no particular direction, trying your best to keep your "
        "footing. Here the trail splits in two, one part winds down the mountain "
        "into the marshy depths below. The other trail seems to circle around "
        "one of the Thoradin Range's highest peaks, you lose sight of the trail "
        "as it passes through the clouds.");
 
    set_exits(([
        "east"      :MTS+"room59",
        "northwest" :MTS+"room61",
        "southwest" :MTS+"room66"
             ]));

}
