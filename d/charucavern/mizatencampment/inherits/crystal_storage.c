#include <std.h>
#include "area_stuff.h"
inherit ROOM;

void create() 
{
    ::create();
    set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : MROOMS+"crystal_merchant"]) );
}

void reset() 
{
    ::reset();
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("dark yellow crystal 6")) 
    {
        new(MOB"dark_yellow_crystal")->move(TO);
    }
    if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
    if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
     if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
    if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
     if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
    if(!present("bright pink crystal 6")) 
    {
        new(MOB"bright_pink_crystal")->move(TO);
    }
    
}
