#include <std.h>
#include "../farm.h"

inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Inside the wheelhouse");
   set_short("Inside the wheelhouse");
   set_long("This is the ground floor of the wheel house, the "+
      "building which houses the %^ORANGE%^water wheel%^RESET%^.  "+
      "The floor here has been kept swept clear, and it is made "+
      "of %^ORANGE%^pine boards%^RESET%^.  The wooden planks "+
      "match the walls of the building, and they have been fitted "+
      "using an ingenious tongue-and-groove system.  No nails "+
      "have been used in the construction at all, quite a "+
      "remarkable feat.  A massive %^ORANGE%^beam %^RESET%^"+
      "runs the width of the room, fitted into several supports "+
      "and a system of %^YELLOW%^cogs%^RESET%^.  The %^YELLOW%^"+
      "cogs %^RESET%^vary in size and even shape, and they form "+
      "a complex machine with %^BOLD%^pipes%^RESET%^ and "+
      "%^BOLD%^%^BLUE%^wires %^RESET%^leading up to the top "+
      "floor.  A simple %^ORANGE%^wooden ladder %^RESET%^rests on "+
      "the eastern side of the room, leading up to the floor "+
      "overhead.  Looking up, you see that the ceiling is actually "+
      "only a half ceiling with a railing allowing those up top "+
      "to look down on what might be where you stand.\n");
   set_items(([
      ({"floor","planks","boards","ground","pine boards"}) : "The "+
         "light blonde pinewood planks have been fitted together to "+
         "form a seamless floor that is kept swept free of debris.  "+
         "Even the joints with the wall have been crafted ingeniously "+
         "to negate the need for nails or pegs.",
      ({"beam","supports"}) : "The beam is held by supports of thick "+
         "oak, and both beam and supports have been oiled and fitted "+
         "into well-made sockets to allow for easy turning.  The "+
         "beam is in constant motion, the energy generated from the "+
         "rushing water outside.",
      ({"cogs","cog"}) : "Cogs made of all manner of metal - from mithril "+
         "and adamantite to iron and copper - and in all sizes crowd the "+
         "small room.  They are attached to pipes and wires, some "+
         "leading to other cogs and some leading upstairs.  Looking "+
         "at the contraption for too long almost makes you feel "+
         "%^YELLOW%^d%^GREEN%^i%^YELLOW%^z%^GREEN%^z%^YELLOW%^y%^RESET%^.",
      ({"wires","pipes"}) : "Thin wires and metal pipes are attached "+
         "between the cogs at various points though some very cleverly "+
         "constructed rings.  There is no telling why the pipes "+
         "and wires are here.",
      ({"ladder","wooden ladder"}) : "The ladder is just tall enough "+
         "to reach the upper floor.  If is very narrow and sized for a "+
         "gnome, though it looks sturdy enough to hold a large "+
         "individual."
   ]));
   set_smell("default","The clean scent of pine is mixed with an "+
      "acrid odor of flame.");
   set_listen("default","The turning of the water wheel masks other sounds.");
   set_exits(([
      "south" : PATHS"bridge",
      "up" : PATHS"wheelhouse2"
   ]));
   set_door("door",PATHS"bridge","south",0);
   set_door_description("door","The door is made of thick pine planks "+
      "bound with iron and stained a deep brown.  The color makes it "+
      "stand in stark contrast to the silvered building around it, and "+
      "it bears a thick iron lock.");
   set_lock_description("door","lock","From this side, the lock has "+
      "a simple turnkey, allowing it to open with ease.");
   set_locked("door",1,"lock");
}