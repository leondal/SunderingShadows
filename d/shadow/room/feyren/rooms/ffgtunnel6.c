#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTTE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel comes to an "+
    "end. An opening leads out to the south.%^RESET%^");
    set_exits( ([ "south" : FFGTR"5"]) ); 
}
