#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFUT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^GREEN%^A glimmer "+
    "of hope is offered here as you can swim up "+
    "and emerge from this flooded tunnel or you can "+
    "continue into darkness to the south.%^RESET%^");
    set_exits( ([ "up" : FFTR"13", "south" : FFUR"2"]) ); 
}
