//inn_main.c by ~Circe~ 1/17/09
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Stairway of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "This portion of the inn is dominated by a large %^ORANGE%^"+
      "stairway%^RESET%^ with a bannister made of unfinished %^BOLD%^driftwood%^RESET%^ "+
      "that leads up to the second floor.  To the east, a comfortable "+
      "%^CYAN%^lounge %^RESET%^provides seating for travelers while an archway "+
      "in the west wall leads into a small %^MAGENTA%^bar %^RESET%^outfitted "+
      "with a %^ORANGE%^stage%^RESET%^.  A doorway to the left "+
      "of the stairs leads south into the inn's %^ORANGE%^bakery"+
      "%^RESET%^.  The room is filled with the soft %^BOLD%^glow %^RESET%^of "+
      "the many decorative %^BOLD%^%^GREEN%^g%^BLUE%^l%^CYAN%^a"+
      "%^WHITE%^s%^GREEN%^s%^BLUE%^ g%^CYAN%^l%^WHITE%^o%^GREEN%^b"+
      "%^BLUE%^e%^CYAN%^s%^RESET%^ that dangle from the ceiling.\n");
   set_smell("default","The light fragrance of the sea seems to linger here.");
   set_listen("default","Voices engaged in conversation reach your ears.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      "bakery" : "The bakery to the south seems to do a brisk "+
         "business at all hours.  It is outfitted much like the rest "+
         "of the inn, but you catch the fragrance of fresh pastry and cinnamon.",
      "bar" : "A lively bar with a cozy stage is just visible "+
         "past the stairway to the west.",
      ({"stairs","stairway"}) : "A stairway tiled in the same "+
         "stone as the rest of the floor is visible to the "+
         "west.  It likely leads to the rooms for rent.",
      ({"bannister","driftwood","driftwood bannister"}) : "The roughly finished "+
         "bannister is worn smooth in places from countless hands.  It is "+
         "bleached white from the sun, echoing the floor tiles."
   ]));
   set_exits(([
      "east" : ROOMS"inn_entrance",
      "south" : ROOMS"inn_restaurant",
      "west" : ROOMS"inn_bar",
      "up" : ROOMS"inn_stairs"
   ]));
}