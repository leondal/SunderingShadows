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
are being watched.  You notice a %^YELLOW%^cave%^RESET%^
here.

STOP
);
       set_smell("default","There is some kind of undistinguishable smell coming"
                +" from the cave.");
       set_listen("default","You hear cackling laughter emanating from the cave.");
       set_exits((["south":"/d/cursed/cursed3.c",
                   "cave":"/d/cursed/cave1/cave1-1.c"]));
                  
}

