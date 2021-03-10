#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
        ::create();
        set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
        set_short("Training Area, Offestry");
        set_long(
@NROHT
%^CYAN%^BOLD%^Training Arena, Offestry%^RESET%^
You are in the training arena in Offestry.  This is where adventurers
come to be trained in the weapons that they have chosen to try and use. 
The %^CYAN%^walls%^RESET%^ are padded to help prevent injuries, and even the %^CYAN%^floor%^RESET%^ seems
rather soft.  There are practice %^CYAN%^dummies%^RESET%^ around the room, and racks of
weapons for the %^CYAN%^students%^RESET%^.  You can see a few young would-be fighters
practicing even now.

To the north, you can see the archery range where you could train with
bows and other ranged weapons.
NROHT
        );
        set_property("light",2);
        set_smell("default","There is a strong smell of sweat that permeates the room.");
        set_listen("default","You can hear the clang of weapons as the students"+
        " practice about the room.");
        set_items(([
        ({"wall","walls"}) : "The walls here are padded to help prevent injuries"+
        " during practice.",
        "floor" : "The floor is somehow softer than normal, it has a certain give"+
        " to it that would help to lessen the impact.",
        "students" : "There are a few young would-be fighters practicing with"+
        " wooden dummies at the edges of the room.",
        "dummies" : "There are several practice dummies lined up about the room to"+
        " help young fighters get the feel of their weapons.",
        ]));
        set_exits(([
                "north" : MAINTOWN"archery",
        "south" : MAINTOWN"estreet2",
        ]));
}

void reset(){
   ::reset();
   if(!present("mortius"))  find_object_or_load("/d/newbie/mon/mortius")->move(TO);
}
