#include <std.h>
#include "../dragon.h";

inherit VAULT;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set_terrain(SHALLOW_WATER);
   set_travel(DECAYED_FLOOR);
   set_property("no teleport", 1);
   set_short("%^BOLD%^%^RED%^Old cellar%^RESET%^");
   set_long(
      "%^BOLD%^%^BLACK%^This looks like an old and abandoned storage"+
      " cellar for some huge complex. The paint on the stone walls has"+
      " peeled off long ago, but the structure seems sturdy, despite all"+
      " the apparent water damage. Water covers the floor and is about"+
      " twelve inches deep. This hall connect with a series of"+
      " other hallways, with doors leading into some of the marked storage rooms."
   );
   set_items(([
      "walls" : "The walls are cold and bare. The stone seems very sturdy.",
      "water" : "The water is dark, murky, and has a bad stagnant smell.",
      "hallways" : "Hallways run all the way around this storage areas and some have doors.",
      "ceiling" : "The ceiling looks sturdy, but neglected.",
      "doors" : "There are various doors lined up along the walls of the hallways.",
   ]));
   set_listen("default","%^RESET%^%^GREEN%^The sound of dripping water rings out again and again.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The smell of stagnant water fills the hallways.%^RESET%^");
}
