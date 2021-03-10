#include <std.h>

inherit ROOM;

void create()
{
        ::create();
                set_property("outdoors",1);
                set_property("light",1);
                set_short("Cursed Land's entrance to shop.");
                set_long(

@STOP
You have just ventured into the cursed lands.
You realize that you can't leave the same way
you came in.  You begin to wonder if there is
any way out.  You also notice that there is a shop
hidden within this dark and gloomy atmosphere.

STOP
);
       set_smell("default","You smell the stinch of %^RED%^%^BOLD%^DEATH!%^RESET%^");
       set_listen("default","You hear whimpering cries for help all around you.");
       set_exits((["shop":"/d/cursed/cursedshop.c",
                  "west":"/d/cursed/cursed2.c",
                  "north":"/d/cursed/cursed3.c"]));
}

