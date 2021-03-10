#include <std.h>
#include "../inherit/keep.h"
inherit CVAULT;

void create() {
   ::create();
   set_repop(60);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A ruined hall");
   set_short("%^CYAN%^A ruined hall%^RESET%^");
   set_long("%^CYAN%^A ruined hall%^RESET%^\n"
"%^RESET%^You are standing in a great hall on the second floor of "
"a ruined keep.  A few ruined %^BOLD%^%^WHITE%^paintings %^RESET%^and "
"%^ORANGE%^tapestries %^RESET%^still hang upon the walls, and the occasional "
"%^BOLD%^%^BLACK%^statue %^RESET%^can be seen resting on a pedestal.  Grand "
"%^BOLD%^%^CYAN%^windows %^RESET%^once looked out upon the forests surrounding "
"the keep, but they have long since been broken.  In a few places the "
"%^ORANGE%^walls %^RESET%^and %^ORANGE%^roof %^RESET%^have crumbled over the "
"years, allowing a few rays of light to spill across the cracked %^CYAN%^tile "
"%^RESET%^floor.");
   set_smell("default","The smell of age-old decay hangs in the air.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
     ({"floor","tiles"}) : "%^ORANGE%^The floor might once have been beautiful, "
"judging by the hints of color in the faded tiles.  They are damaged and "
"shattered beyond recognition, however, by the tread of many feet and the "
"passing of the years.%^RESET%^",
     ({"paintings","tapestries"}) : "%^BOLD%^%^WHITE%^Damaged tapestries and "
"paintings still adorn the walls, though many are now only shredded remains or "
"faded tatters of their former glory.  You can't make out what they might have "
"once depicted.%^RESET%^",
     ({"statues","statue","pedestal","pedestals"}) : "%^BOLD%^%^BLACK%^A few "
"pedestals spot the room, though most have been knocked over or broken.  They "
"perhaps once held statues, but only a few now remain, some depicting people "
"and one shaped as a leaping dragon.%^RESET%^",
     ({"walls","roof"}) : "%^CYAN%^The walls and roof of the keep are aged, the "
"stone that forms them having crumbled and degraded over the years.  In a few "
"places, holes have formed, allowing rays of light and the occasional trickle "
"of moisture to gain access to the keep.%^RESET%^",
     ({"windows","forest","forests"}) : "%^BOLD%^%^CYAN%^Grand windows encircle "
"the hall, once likely to have allowed spectacular lighting to the hall, and a "
"view of the forests beyond the keep.  Now they are shattered and open to the "
"air, with grimy tattered curtains to border them.%^RESET%^",
   ]));
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons) mons = ([]);
      set_monsters(({MONS"xvart"}),({random(3)+1}));
   }
   ::reset();
}
