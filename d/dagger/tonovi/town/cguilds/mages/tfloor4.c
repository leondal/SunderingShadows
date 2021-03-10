//updated by Circe 5/31/04 with color, etc.
// Level 4 Landing in the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010306
// Tabor
// tfloor4.c

#include <std.h>
#include "../include/tabor.h"

inherit VAULT;

void create()
{
    ::create();
    set_name("Floor 4");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Level 4 Landing in the Tower of the Arcane, Tabor");
    set_short("Level 4 Landing in the Tower of the Arcane, Tabor");
    set_long(
@TOWER
%^BOLD%^Level 4 Landing in the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^
%^BOLD%^%^BLACK%^This is the fourth level of the Tower of the Arcane.  From here 
you can look down a fine %^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k ma%^BOLD%^%^BLACK%^rb%^RESET%^le%^BOLD%^%^BLACK%^ staircase to the third level.  
This staircase also leads up to the roof.

%^RESET%^To the north, there is a door with a sign that at first seemed to be 
garbled, but suddenly changed to read "%^CYAN%^Public Laboratory%^RESET%^", in your 
native language.  To the south, there appears to be what looks like 
simply a little store with a bunch of %^ORANGE%^bags %^RESET%^and %^ORANGE%^leather-bound books%^RESET%^.
TOWER
    );
    set_property("light",2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_property("indoors",1);
    set_smell("default","A number of strange smells are coming from the north.");
    set_listen("default","You hear some muted explosions behind the door to the north.");
    set_exits( ([
        "north" : ROOMDIR+"tlab",
        "south" : ROOMDIR+"tstuff",
        "down"  : ROOMDIR+"tfloor3",
        "up"    : ROOMDIR+"roof"
    ]) );
    set_door("door","/d/darkwood/tabor/room/tlab","north");
    set_open("door", 0);
    "/d/darkwood/tabor/room/tlab"->set_open("door", 0);
}
