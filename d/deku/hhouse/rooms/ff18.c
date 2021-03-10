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
    set_long(TO->query_original_long()+mycol+" The hallway continues east, south, and west.%^RESET%^");

}

void create() 
{
    ::create();
	
    set_exits((["south" : FFROOMS+"42", "east" : FFROOMS+"17", "west" : FFROOMS+"19" ]));		

}
