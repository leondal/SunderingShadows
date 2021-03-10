#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_short("Torm's clinic");
  set_property("light",2);
  set_name("pojo");
  set_door("door",TCITY+"c32","west","masterkey");
  set_property("indoors",1);
  set_long(
    "Torm's clinic.\n"
  "  This is a very clean neat clinic."
  "  There are a great number of beds here and you can see a few of the guards of the army of the Dagger reaches here recovering from their patrols."
   "  There are jars of herbs and poultices stashed in careful crates in one corner of the room."
   "  The windows are kept open to let the clean air in, and there is a potted plant on the north window sill that brings a little cheer to the place."
  );
   set_smell("default","The clinic smells of astringents and herbs.");
    set_listen("default","You can hear the groans of some of the patients.");
   set_items(([
   "beds" : "There are several beds in this room, most of which are taken up by groaning soldiers. All the beds are cleanly dressed in white linen to help prevent transference of disease.",
   ({"jars","herbs","poultices"}) : "There are several jars of herbs and poultice mixtures stashed in crates in one corner of the room.",
   "crates" : "There are a couple of crates of jars of herbs and such stashed in the southeast corner of the room, out of the way.",
   "windows" : "There are two windows, one on the north and one on the south. Both are kept open most of the time, except for when there is bad weather. They let the fresh air and take the smell of disease out of the room. On the north window sill is a potted plant that seems to be growing a lone daisy that brings a bit of cheer to the room.",
   ({"potted plant","plant"}) : "On the northern window sill is a single potted plant growing a daisy. The flower looks fairly lonely, and it is almost too big for the small pot, but it is growing determinedly none the less.",
   ({"daisy","flower"}) : "%^YELLOW%^There is a single daisy growing determinedly in the potted plant on the north window sill. It seems to be struggling a bit, and is probably rather neglected what with all the patients, but it seems to be doing well and adds a bit of cheer to the room.%^RESET%^",
   ]));
  set_exits(([
  "west":TCITY+"c32",
  "east":TCITY+"c33b",
  ]));
}
void reset(){
  ::reset();
  if(!present("guard")) new(MON+"guardin")->move(TO);
}
