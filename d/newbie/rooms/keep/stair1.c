#include <std.h>
#include "../inherit/keep.h"
inherit CROOM;

void create() {
   set_monsters(({MONS+"spider"}),({1}));
   ::create();
   set_repop(40);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("Stairway of a ruined keep");
   set_short("%^CYAN%^Stairway of a ruined keep%^RESET%^");
   set_long("%^CYAN%^Stairway of a ruined keep%^RESET%^\n"
"You are standing at the bottom of spiral of %^BOLD%^%^BLACK%^stone stairs "
"%^RESET%^that lead upwards to another floor of the keep.  The %^BOLD%^"
"%^BLACK%^stairs %^RESET%^themselves are in surprisingly good condition, "
"despite being a bit dusty.  A line of old ragged %^GREEN%^carpet %^RESET%^"
"has been rolled down the centre, while a metal %^BOLD%^%^WHITE%^railing "
"%^RESET%^runs around the curved edge, amidst which are tangled several "
"%^BLUE%^spiderwebs%^RESET%^.  It's hard to tell from here what might be on "
"the second floor.  Just through to the south is the main hallway.\n");
   set_smell("default","The smell of age-old decay hangs in the air.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
     ({"stairs","steps","stairway"}) : "%^BOLD%^%^BLACK%^The stone stairs "
"leading up in a spiral to the second floor of the keep are in fairly good "
"condition.  They're very dusty though, and obviously haven't been used "
"much in a long time.",
     "carpet" : "%^GREEN%^A strip of old, faded carpet winds down the "
"circle of the stairs.  It is soft enough underfoot to ward the rough feel "
"of stone beneath, but whiffs of dust are occasionally stirred by footsteps "
"upon it.%^RESET%^",
     ({"railing","metal railing","spiderwebs","webs"}) : "%^BOLD%^%^WHITE%^"
"A tarnished metal railing encircles the spiral of stairs as it winds "
"upwards to the next floor.  Visibly aged over time, it still seems sturdy "
"enough to prevent an accidental fall.  A few spiderwebs lie tangled "
"between the metallic struts.%^RESET%^",
   ]));
   set_exits(([
     "south" : ROOMS"keep11",
     "up" : ROOMS"stair2",
   ]));
}
