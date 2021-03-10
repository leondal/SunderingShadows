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
You appear to have reached the back of the cave.
The southern wall feels %^CYAN%^%^BOLD%^frigid%^RESET%^.
You barely notice the slight movements towards
the east as well as from the west of you.

STOP
);
       set_smell("default","There is definitly some horrific stinch in the"
                +" atmosphere.");
       set_listen("default","You continue to hear two separate faint noises" 
                  +" in this cave.\n"
                   +" One coming from the east while the other is coming" 
                   +" from the west.");
       set_exits((["north":"/d/cursed/cave1/cave1-2.c",
                   "west":"/d/cursed/cave1/cave1-4.c",
                   "east":"/d/cursed/cave1/cave1-5.c"]));
                  
}

