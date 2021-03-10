#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFOBR;

void create() 
{
    ::create();
    set_exits( ([ "exit" : FFOR"3"]) );
}
