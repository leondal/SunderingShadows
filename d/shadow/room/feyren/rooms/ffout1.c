#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues east and "+
    "west. "+
    "A badly dilapidated %^RESET%^%^ORANGE%^gate%^RESET%^%^GREEN%^"+
    " offers a way out of here to the north.%^RESET%^");
    set_exits( ([ "north" : OA,"east" : FFOR"12", "west" : FFOR"2"]) );
    set_door("gate",OA,"north");
    set_door_description("gate","%^RESET%^%^ORANGE%^This gate is composed of a dark "+
    "wood that has badly dilapidated over time. It still functions, but "+
    "barely. It has scrawled into the center of it, "+
    "in a barely legible script, the initials %^BOLD%^%^RED%^FF%^RESET%^%^ORANGE%^.%^RESET%^");
}
