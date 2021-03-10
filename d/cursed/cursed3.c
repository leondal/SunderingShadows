#include <std.h>

inherit ROOM;

void create()
{
        ::create();
                set_property("outdoors",1);
                set_property("light",1);
                set_short("Southern part of the Cursed Lands.");
                set_long(

@STOP
You are in the southern Cursed Lands.  Like the rest
of the Cursed Lands, it is dark and eerie here as well.
Even though there doesn't appear to have any living
entities around here, you have this strange feeling you
are being watched.  There is a huge dark black barrier
further towards the south.  But towards the north you
notice a cave.

STOP
);
       set_smell("default","You smell the stinch of %^RED%^%^BOLD%^DEATH!%^RESET%^");
       set_listen("default","You hear whimpering cries for help all around you.");
       set_exits((["south":"/d/cursed/cursed1.c",
                   "north":"/d/cursed/cursed4.c"]));
                  
}

