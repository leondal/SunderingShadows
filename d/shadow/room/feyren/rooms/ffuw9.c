#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFUT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^GREEN%^A glimmer "+
    "of hope is offered here as you can swim up "+
    "and emerge from this flooded tunnel or you can "+
    "continue into darkness to the north.%^RESET%^");
    set_exits( ([ "up" : FFGTR"29", "north" : FFUR"8"]) ); 
}
