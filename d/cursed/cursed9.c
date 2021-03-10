#include <std.h>

inherit ROOM;

void create()
{
        ::create();
                set_property("outdoors",1);
                set_property("light",1);
                set_short("Southern most part of Cursed Lands.");
                set_long(

@STOP
You are at the southwestern part of the Cursed Lands.
The area appears uninhabited.  There is nothing around
as far as you can see, except for this %^GREEN%^fortress%^RESET%^
towards the southwest.

STOP
);
       set_smell("default","You smell the stinch of %^RED%^%^BOLD%^DEATH!%^RESET%^");
       set_listen("default","You hear whimpering cries for help all around you.");
       set_exits((["northeast":"/d/cursed/cursed8.c",
                   "southwest":"/d/cursed/cursed12.c",
                   "west":"/d/cursed/cursed10.c",
                   "south":"/d/cursed/cursed11.c"]));
                  
}

