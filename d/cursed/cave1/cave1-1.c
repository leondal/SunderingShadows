#include <std.h>

inherit ROOM;

void create()
{
        ::create();
                set_property("indoors",1);
                set_property("light",0);
                set_short("A Cave in the Cursed Lands.");
                set_long(

@STOP
You are inside a small cave.  It is dark and
you barely take notice of anything here.  You
shiver, as the atmoshpere in here is a cold and
dreary one.
STOP
);
       set_smell("default","There is definitly some horrific stinch in the"
                +" atmosphere.");
       set_listen("default","You various cries towards the south.");
       set_exits((["out":"/d/cursed/cursed4.c",
                   "south":"/d/cursed/cave1/cave1-2.c"]));
                  
}

