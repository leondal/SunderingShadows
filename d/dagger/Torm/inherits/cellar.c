#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light",2);
  set_short("Dark cell");
  set_long(
  "This dark, cold cell is for the prisoners of the city of Torm. It is"+
  " well built out of dull gray stone that has been carefully fitted"+
  " together to prevent even the slightest of cracks on the outside. You"+
  " doubt more could get through the walls than air or water. Strangely"+
  " enough all the cells seem to be empty. It's almost as if there is"+
  " never any crime, or perhaps the punishment isn't imprisonment but work"+
  " crews?"
  );
  set_smell("default","A slightly musty oder hangs in the air.");
  set_listen("default","You hear the footsteps of guards patrolling the halls.");
  set_items(([
  "nothing" : "It's nothing at all.",
  "walls" : "The walls are made of dull grey stone.",
  "floor" : "The floors are made of dull grey stone.",
  ({"ceiling","roof"}) : "The ceiling is made of dull grey stone that is"+
  " roughly finished.",
  "door":"It's a sturdy cell door."
  ]));
}
