#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFH;

void adjust_room(int state)
{
    string mycol;
    switch(state)
    {		
        case 0:	
            mycol = "%^BOLD%^%^WHITE%^";
            break;
        case 1:			
            mycol = "%^BOLD%^%^MAGENTA%^";
            break;
    }
    set_long(TO->query_original_long()+mycol+" You stand before "+
    "what was once the exit of the house. It has been boarded up and "+
    "magically sealed. The hallway continues north, east, and west.%^RESET%^");

}

void create() 
{
    ::create();
	
    set_exits((["north" : FFROOMS+"35", "east" : FFROOMS+"2", "west" : FFROOMS+"34" ]));		
}
