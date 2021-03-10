#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the east, south, and northwest.%^RESET%^");
    set_exits( ([ "east" : FFGTR"11", "south" : FFGTR"14", "northwest" : FFGTR"9"]) ); 
}
