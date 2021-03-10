#include <std.h>
#include "../inherits/area_stuff.h"
inherit SFH;

void adjust_room(int state)
{
    string mycol;
    switch(state)
    {		
        case 0:	
            mycol = "%^RESET%^%^ORANGE%^";
            break;
        case 1:			
            mycol = "%^RESET%^%^GREEN%^";
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues to the south and east. "+
    "Directly east there is a collapsed exit and %^BOLD%^%^BLACK%^ruins%^RESET%^"+mycol+
    " of what was once another section of this floor are visible.%^RESET%^");

    TO->add_item(({"ruins", "ruins"}), "%^BOLD%^%^RED%^The ruins of what was once another "+
    "portion of the house are visible here. You cannot go in that direction at all.%^RESET%^");
}

void create() 
{
    ::create();
    set_exits((["south" : SFROOMS+"h20", "east" : SFROOMS+"h18"]));		
}
