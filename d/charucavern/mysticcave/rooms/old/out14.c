#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["north" : CRROOMS+"out13", "northeast" : CRROOMS+"out18", "northwest" : CRROOMS+"out15"]));		

}

void reset()
{
    ::reset();
    if(!present("chest"))
    {
        new(!random(2) ? "/d/hm_quest/chests/chest11" : "/d/hm_quest/chests/chest27")->move(TO);
    }
}
