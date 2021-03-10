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
You are at the back end of the cave.
The southern wall feels %^CYAN%^%^BOLD%^frigid%^RESET%^.
You notice some movement in the west.
But you're not sure what it is.

STOP
);
       set_smell("default","There is some undescribable stinch in the"
                +" atmosphere.\n It smells like various forms of life"
                +" nearby.");
       set_listen("default","You hear two noises coming from the west.");
       
       set_exits((["east":"/d/cursed/cave1/cave1-3.c",
                   "west":"/d/cursed/cave1/improom.c"]));
                  
}

