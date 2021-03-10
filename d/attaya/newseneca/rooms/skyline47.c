//skyline47
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To the west stands soaring %^BOLD%^bell tower "+
      "%^RESET%^of a majestic cathedral with %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s%^RESET%^.  To the east is a "+
      "small %^ORANGE%^adobe building %^RESET%^with three bunches of "+
      "%^GREEN%^dried herbs %^RESET%^hanging over the door.\n");
   set_exits(([
      "east" : ROOMS"herb_shop",
      "north" : ROOMS"skyline46",
      "south" : ROOMS"sstreet48"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/herb_shop","east",0);
   set_door_description("door","This rustic door is made of roughly "+
      "hewn wooden planks.  It has a simple latch that lifts to "+
      "provide entry.");
   add_item("tower","The bell tower of the cathedral to the west "+
      "towers over the city, casting a long shadow along the road.  "+
      "The bell is impossible to see from here, despite the open "+
      "archways you can see housing it.");
   add_item("bell tower","The bell tower of the cathedral to the west "+
      "towers over the city, casting a long shadow along the road.  "+
      "The bell is impossible to see from here, despite the open "+
      "archways you can see housing it.");
   add_item("cathedral","The cathedral to the west boasts towering "+
      "arches and vaulted ceilings, resplendent with %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^and a bell tower that "+
      "soars over all.  A path paved with %^BOLD%^pure white "+
      "cobblestones %^RESET%^leads to the cathedral's entrance.");
   add_item("shop","To the east is a small shop made of humble adobe "+
      "that seems well-kept.  The low roof is rather flatter than "+
      "most roofs, and it provides only a small overhang.  The door "+
      "is decorated by three bundles of %^GREEN%^dried herbs %^RESET%^"+
      "tied with simple hemp string.");
   add_item("building","To the east is a small shop made of humble adobe "+
      "that seems well-kept.  The low roof is rather flatter than "+
      "most roofs, and it provides only a small overhang.  The door "+
      "is decorated by three bundles of %^GREEN%^dried herbs %^RESET%^"+
      "tied with simple hemp string.");
   add_item("adobe building","To the east is a small shop made of humble adobe "+
      "that seems well-kept.  The low roof is rather flatter than "+
      "most roofs, and it provides only a small overhang.  The door "+
      "is decorated by three bundles of %^GREEN%^dried herbs %^RESET%^"+
      "tied with simple hemp string.");
}