#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into the "+
    "courtyard far below if you were so inclined.%^RESET%^");   
    
    set_exits((["west" : RROOMS+"29", "south" : RROOMS+"25", "southwest" : RROOMS+"24"]));

    if(!random(2)) set_property("jump_destination", "north");		
    else set_property("jump_destination", "east");

}

void reset()
{
    ::reset();
    if(random(4)) 
    {
        if(!present("husk of zhour", TO)) new(HHMON+"zhour_husk")->move(TO);
    }
}