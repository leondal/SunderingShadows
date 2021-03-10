#include <std.h>
inherit VAULT;

void create() {
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Room That Isn't a Closet");
  set_long("%^ORANGE%^You step through the closet and shove aside some dusty, old "+
  "%^MAGENTA%^finery %^ORANGE%^to find yourself in another room entirely. It is dim, "+ 
  "lit only by a few %^BOLD%^candles%^RESET%^%^ORANGE%^. There is not much to see in "+ 
  "this strange and secret room, except for a tussled up bed and some smoke curling up from "+
  "an incense burner hanging from the ceiling. You, trespasser, are startled to find that you are "+
  "not alone!%^WHITE%^\n");
  set_smell("default", "The air is thick with the smell of burning incense.");
  set_listen("default", "So this is where the chanting was coming from...");
  set_exits( ([
     "door" : "/d/koenig/town/house10"
]) );
  set_door("door", "/d/koenig/town/house10", "door" );
  set_open("door", 1);
  "/d/koenig/town/house10"->set_open("closet door", 1);
  set_items(([
    "bed" : "Some ratty old blankets are piled upon other even more ratty blankets.",
    "candles" : "They've almost burned down to their bottoms.",
	"incense" : "Wispy smoke cuts strange shapes in the air."]));
}

void reset() {
  ::reset();
  if(!present("concubine") && !present("snakeman")) {
  new("/d/koenig/town/mon/concubine.c")->move(this_object());
  new("/d/koenig/town/mon/mansnake.c")->move(this_object());
  }
}
