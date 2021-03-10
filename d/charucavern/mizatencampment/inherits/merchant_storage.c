#include <std.h>
#include "area_stuff.h"
inherit "/d/common/inherit/gs_storage";

void create() 
{
    ::create();
    set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : MROOMS+"merchant"]) );
}

void reset() 
{
    ::reset();
    if(!present("waterskin 3") && !random(2)) 
    {
        new("/d/antioch/antioch2/obj/waterskin")->move(TO);
    }
    if(!present("waterskin 3") && !random(2)) 
    {
        new("/d/antioch/antioch2/obj/waterskin")->move(TO);
    }
    if(!present("waterskin 3") && !random(2)) 
    {
        new("/d/antioch/antioch2/obj/waterskin")->move(TO);
    }
    if(!present("tent 2") && !random(2))
    {
        new(MOB+"tent")->move(TO);
    }
    if(!present("tent 2") && !random(2))
    {
        new(MOB+"tent")->move(TO);
    }
}
