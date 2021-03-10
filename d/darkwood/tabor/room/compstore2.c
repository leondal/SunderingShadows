//updated by Circe 5/31/04 with color, etc.
// The Amber Fulcrum, Tabor
// Thorn@ShadowGate
// 010206
// Tabor
// compstore2.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create()
{
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_name("%^ORANGE%^The Amber Fulcrum%^RESET%^");
	set_short("%^ORANGE%^The Amber Fulcrum%^RESET%^");
	set_long(
"%^BOLD%^The Amber Fulcrum, Tabor%^RESET%^\n"+
"%^ORANGE%^This room is abolutely jam packed with the weirdest "+
"items you have ever seen.  Strangely, this room is not made of "+
"marble like the rest of the tower.  It seems, rather, that the "+
"owner feels more at home in wood.  Lightly scented %^WHITE%^pine "+
"%^ORANGE%^has been brought in from the %^GREEN%^forest%^ORANGE%^, "+
"and fashioned into a comfortable, if cluttered, shop.  This is "+
"obviously a %^CYAN%^components shop %^ORANGE%^for %^BOLD%^%^CYAN%^"+
"magi%^RESET%^%^ORANGE%^, and probably has every %^CYAN%^component "+
"%^ORANGE%^that you will ever need.  Of course, in all of this "+
"clutter, it's likely that the proprietor will only be able to find "+
"a small number of these items on demand.  The wooden walls are lined "+
"with deep %^WHITE%^shelves%^ORANGE%^, all of them piled high with "+
"%^YELLOW%^crates %^RESET%^%^ORANGE%^and %^BOLD%^%^BLUE%^jars"+
"%^RESET%^%^ORANGE%^.  In the northeastern part of the room, jammed "+
"into the corner, is a small %^WHITE%^counter%^ORANGE%^.\n\n"+
"%^RESET%^You can see that an archway to the west will allow you "+
"to exit the store and escape this mess.\n\n"+
"<help shop> will give you help on how to use the shop.\n"
	);
	set_smell("default","You smell the odor of what appears to "+
		"be bat guano.");
	set_listen("default","A creaking that sounds like overstrained shelves.");
    set_items( ([
        ({"components","store","shelf","shelves"}):
            "On the shelves covering the walls behind the "+
            "main counter, there are all sorts of jars and "+
            "crates containing foul-smelling components.  "+
            "You see bits of everything, and many components "+
            "are in more than one place.  What a mess!",
        ({"counter","main counter","small counter"}) : "A small, "+
            "almost-square counter is crammed into the northeastern "+
            "corner of the room.  The floor around it is filled "+
            "with various other components in the process of being "+
            "sorted...unfortunately, most look like they've been "+
            "there for a very long time.",
        ({"crates","jars"}) : "Crates and jars are piled onto "+
            "the shelves, some falling into another crate or jar.  "+
            "The jars look rather cloudy and crusty, but the "+
            "components in them seem in working order.  Some of "+
            "the crates seem covered in mold, but perhaps that's "+
            "just Cirtwith's way of cultivating new components?",
    ]) );
    set_exits( ([
        "west" : ROOMDIR+"tfloor2"
    ]) );
    new(MONDIR+"cirtwith")->move(TO);
}
