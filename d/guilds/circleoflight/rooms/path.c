#include <std.h>
#include "../defs.h"
inherit CVAULT;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(LIGHT_FOREST);
   set_travel(PAVED_ROAD);
   set_name("A pathway through the forest");
   set_short("%^RESET%^%^GREEN%^A pathway through the forest%^RESET%^");
   set_long("%^RESET%^%^GREEN%^A pathway through the forest%^RESET%^\n"
"This simple pathway leads away from the main road, into a small %^CYAN%^c%^GREEN%^le%^CYAN%^ar%^GREEN%^in%^CYAN%^g "
"%^RESET%^in the surrounding forest.  %^GREEN%^Tall t%^BOLD%^r%^RESET%^%^GREEN%^ees %^RESET%^rise up to either side, "
"obscuring vision within a short distance by their thick foliage and undergrowth.  Within the clearing itself lies a "
"%^ORANGE%^stone building%^RESET%^, larger than most of human construction.  Two small steps lead up to the portico, "
"partially obscured by a screen of four stone pillars, behind which is visible a pair of %^ORANGE%^he%^RED%^av%^ORANGE%^y "
"double doors%^RESET%^.  Above the portico, the inset section of the pediment is marked by a perfectly carved circle, "
"embossed and decorated in %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^.  A collonade of identical pillars lines "
"each side of the path in progressive pairs, forming a lead up to the building itself.%^RESET%^\n");
   set_smell("default","A fresh breeze stirs your hair.");
   set_listen("default","The soft sounds of the forest carry on the air.");
   set_items(([
   ]));
   set_exits(([
     "enter":ROOMS"foyer",
     "southeast":"/d/darkwood/tabor/road/road16",
   ]));
    set_door("double doors",ROOMS"foyer","enter",0);
    set_door_description("double doors","%^ORANGE%^This pair of oaken doors fit the massive doorway leading outside, so "
"large that even a giant could pass through unhindered.  Thick metal bars reinforce them in several places, leaving the "
"impression that they would be terribly difficult to damage.%^RESET%^");
}