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
You are at the back of the cave.
The southern wall feels %^CYAN%^%^BOLD%^frigid%^RESET%^.
There is movement coming from the east.
You're not quite sure what it is.
STOP
);
       set_smell("default","There is some toxic stinch in the"
                +" atmosphere.");
       set_listen("default","You here something lurking around towards"
                  +" the east.");
       set_exits((["west":"/d/cursed/cave1/cave1-3.c",
                   "east":"/d/cursed/cave1/msroom.c"]));
                  
}

