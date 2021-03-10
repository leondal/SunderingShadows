//updated by Circe with color, etc.  5/30/04
// Inside the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// tgate.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Inside the Tower of the Arcane, Tabor");
    set_short("Inside the Tower of the Arcane, Tabor");
    set_long(
"%^BOLD%^Inside the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^"+
"c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^\n"+
"%^BOLD%^%^BLACK%^This is the main foyer of the great %^CYAN%^"+
"Tower of the Arcane %^BLACK%^in Tabor.  The room has walls of "+
"%^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k ma%^BOLD%^%^BLACK%^rb"+
"%^RESET%^le %^BOLD%^%^BLACK%^with %^RESET%^%^CYAN%^la%^BOLD%^"+
"%^BLUE%^p%^RESET%^%^CYAN%^is %^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^"+
"az%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^li inserts %^BOLD%^%^BLACK%^"+
"in the shape of %^YELLOW%^lightning bolts%^BLACK%^.  The floor, "+
"like the tower in Shadow, is of gr%^WHITE%^an%^BLACK%^i%^WHITE%^t"+
"%^BLACK%^e mined in the %^RESET%^%^ORANGE%^Charu Mountains %^BOLD%^"+
"%^BLACK%^to the north.  This is the ancient home of %^CYAN%^magic "+
"%^BLACK%^in this part of the realms, but had been disused for "+
"centuries while Tabor was an obscure petty kingdom.  Now that "+
"the Kingdom has regained a lot of its former power, magi have "+
"rediscovered this center of magic.\n\n"+
"%^RESET%^The large entrance to the tower lies to the south. "+
"There are two carved %^CYAN%^archways %^RESET%^on the east and "+
"north walls.  The north archway leads to what seems to be a "+
"%^ORANGE%^long hall%^RESET%^.  The east archway, however, leads "+
"to a store filled with what you recognize as %^GREEN%^spell "+
"components%^RESET%^.\n"
	);
    set_property("light",2);
    set_property("indoors",1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_smell("default","You can smell some acrid air flowing in "+
        "through the entrance.");
    set_listen("default","You can hear the shuffling of "+
        "the magi who pass through here.");
    set_items( ([
        ({"floor","ground","granite","sparkling granite"}): "The "+
            "floor is made of sparkling granite, giving the room a "+
            "magestic feel, despite the dull gray stone walls.  The "+
            "floor seems astoundingly clean and unworn, obviously "+
            "magically protected.",
        ({"wall","walls","marble"}) : "%^BOLD%^%^BLACK%^The smooth "+
            "walls of the tower are made of fantastic %^BLUE%^blue-"+
            "v%^BLACK%^e%^BLUE%^i%^BLACK%^n%^BLUE%^e%^BLACK%^d marble "+
            "set with %^YELLOW%^lightning bolts %^BLACK%^made of "+
            "%^RESET%^%^CYAN%^la%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^is "+
            "%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^az%^BOLD%^%^BLUE%^u"+
            "%^RESET%^%^CYAN%^li%^BOLD%^%^BLACK%^.",
        ({"archway","archways"}): "The archways chiselled from the "+
            " stone are intricately carved in an assortment of beasts.  "+
            "There are two archways, one in the north wall, and one "+
            "in the east wall.",
    ]) );
    set_exits( ([
        "north" : ROOMDIR+"tfloor1",
        "store" : ROOMDIR+"compstore1",
        "exit"  : ROOMDIR+"tgate",
    ]) );
}
