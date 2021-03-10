#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(1);
   set_indoors(1);
   set_short("A Hallway");
   set_long("%^BOLD%^%^WHITE%^You made it out of the kitchen. Ooo, I am impressed. "
      "You are now on the %^RESET%^third floor%^BOLD%^%^WHITE%^ of the tower, and the atmosphere "
      "here is, hmmm... shall we say, rather civilized? You appear to be "
      "standing in a small hallway with %^MAGENTA%^tapestries%^BOLD%^%^WHITE%^ hanging from the "
      "walls and %^BOLD%^%^BLACK%^weapons%^BOLD%^%^WHITE%^ to add a special touch to the decor. There "
      "is even a complete set of %^RESET%^armor%^BOLD%^%^WHITE%^ here, strictly for decoration. "
      "Looking around, you notice that the hallway seems to lead you "
      "to a large open room.%^RESET%^\n");
   set_smell("default", "You can still smell the odors of the kitchen strongly here.");
   set_listen("default", "You can hear the commotion you left behind in the kitchen.");
   set_exits( ([
      "down" : "/d/koenig/town/kitchen4",
      "west" : "/d/koenig/town/tower12"
   ]) );
   set_items(([
      "tapestries" : "There are three tapestries here. You might try looking at them individually.",
      "tapestry 1" : "This one dipicts the communion of humans with numerous other "
         "creatures in both innocent and not so innocent ways.",
      "tapestry 2" : "This one depicts the a very beautiful woman and her creature child.",
      "tapestry 3" : "This one is an image of this tower. Strangely, the picture "
         "seems to move and waver the longer you look at it.",
      "weapons" : "The weapons are in excellant condition and carry a very sharp "
         "edge. Too bad they are bolted to the wall.",
      "armor" : "This armor is strange in shape but looks to have been made for "
         "someone ALMOST human. It is darker than a moonless night and makes "
         "you think of an endless void."
   ]));
}
