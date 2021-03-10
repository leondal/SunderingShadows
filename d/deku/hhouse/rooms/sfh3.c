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
    set_long(TO->query_original_long()+mycol+" The hallway continues to the east and west. "+
             "A narrow rickety staircase leads up to the roof.%^RESET%^");
}

void create()
{
    ::create();

    set_exits((["east" : SFROOMS+"h4", "west" : SFROOMS+"h2", "up" : RROOMS+"3"]));
}
