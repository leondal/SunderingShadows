#include <std.h>
#include "../inherit/keep.h"
inherit CROOM;

void create(){ 
   ::create();
   set_repop(60);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("An abandoned kitchen");
   set_short("%^RESET%^%^CYAN%^An abandoned kitchen%^RESET%^");
   set_long("%^RESET%^%^CYAN%^An abandoned kitchen%^RESET%^\n"
"Before you lies the destroyed remains of a kitchen.  A massive stone "
"%^RED%^fireplace %^RESET%^was once set in the northern wall, but it has "
"crumbled with age and is full of debris.  Rusted %^BOLD%^%^BLACK%^pots "
"%^RESET%^and %^BLUE%^pans %^RESET%^and various %^CYAN%^cutlery "
"%^RESET%^implements lie strewn about the floor, and discarded in corners.  "
"%^CYAN%^Cupboards %^RESET%^and %^GREEN%^shelves %^RESET%^around the room "
"lie broken and fallen, long relieved of their edible contents.  A thick "
"wooden %^ORANGE%^bench %^RESET%^runs the length of the southern wall, worn "
"in places but still intact.  It seems something has taken up residence "
"upon it, as all sorts of rubbish and scraps have been piled into a "
"makeshift kind of %^BOLD%^%^WHITE%^nest%^RESET%^.\n");
   set_smell("default","The air is thick with the smell of mildew and decay.");
   set_listen("default","You can hear the scratching of claws on stone. ");
   set_exits(([
     "west" : ROOMS"keep15",
     "east" : ROOMS"keep17",
   ]));
   set_items(([
     "fireplace" : "%^RED%^A massive stone fireplace would once have taken "
"up the north wall, but age has worn away at the mortar between the stones, "
"leaving them partially tumbled.  It would certainly not be of any use "
"anymore.%^RESET%^",
     ({"pots","pans","cutlery"}) : "%^BLUE%^Broken cutlery lies strewn "
"across the floor and discarded in corners, between the rusted pots and "
"pans.%^RESET%^",
     ({"cupboards","shelves"}) : "%^CYAN%^Cupboards and shelves lie all "
"around the room, once storage for all the food that would've been prepared "
"here.  They are all broken and long since raided by scavengers, leaving "
"nothing edible behind.%^RESET%^",
     "bench" : "%^ORANGE%^An old wooden bench spans the southern length of "
"the room, worn but mostly intact.  Some creature seems to have set up a "
"%^BOLD%^%^WHITE%^nest %^RESET%^%^ORANGE%^upon it, judging by the mess of "
"rubbish and scraps piled up on it.%^RESET%^",
     "nest" : "%^BOLD%^%^WHITE%^A great mound of rubbish and scraps have "
"been piled up along the length of the bench.  It resembles a kind of rough "
"nest, hinting that some creature must be living in here.%^RESET%^",
   ]));
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons) mons = ([]);
      set_monsters(({MONS"xvarts",MONS"xvart"}),({1,random(2)+1}));
   }
   ::reset();
}
