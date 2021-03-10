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
You are in a small dark cave.
There is a dim light towards the north.
But as you look all around you, you notice
that the cave is pretty eerie. You wonder
what hideous creature would be lurking around 
in here.

STOP
);
       set_smell("default","There is definitly some horrific stinch in the"
                +" atmosphere.");
       set_listen("default","You hear two separate noises in this cave.\n"
                   +" One coming from the southeast, and the other from" 
                   +" the southwest.");
       set_exits((["north":"/d/cursed/cave1/cave1-1.c",
                   "south":"/d/cursed/cave1/cave1-3.c"]));
                  
}

