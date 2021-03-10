#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_long("%^GREEN%^You enter into a large chamber of some kind%^RESET%^\n"
        "%^MAGENTA%^It is incredibly dark in here, but from the faint glimmer "
        "of torch light that reaches out into the darkness you can see many "
        "terrible sights. All around you are statues with horrid expressions "
        "etched into their faces. So incredibly life like it must have been "
        "a master artisan who crafted them. At the far end of the chamber you "
        "see a large altar, with a statue of an incredible snake's head. As "
        "you are looking at that you think you see something almost human "
        "move into the shadows. What could it be?");
    
    set_exits(([
        "east"      :MTS+"lair25"
             ]));

    new(MON"medusa")->move(TO);

}
