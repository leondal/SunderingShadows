#include <std.h>
#include "../witchlair.h"
inherit VAULT;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set_property("no sticks",1);
  set_property("no teleport",1);
  set_property("no starve",0);
  set_property("no magic",0);
  set_property("no steal",0);
  set_short("%^RESET%^%^ORANGE%^Inside of a large hut");
  set_long("%^BOLD%^%^BLACK%^Little light makes it into "
"this room, as all of the windows have been partially covered "
"in leathers and canvas, but you can see well enough to determine"
" that someone wizardly lives here. %^RESET%^%^ORANGE%^Shelves "
"%^BOLD%^%^BLACK%^line half the walls, filled with various "
"writing implements and mediums. Stacks of books are placed "
"haphazardly everywhere, making walking a challenge. Bundles of "
"%^RESET%^%^GREEN%^d%^ORANGE%^r%^WHITE%^i%^GREEN%^ed he"
"%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^bs %^BOLD%^%^BLACK%^and slain"
" game hang from racks in the ceiling, and one has to take care "
"not to walk into them. Twin tables are set in opposite corners "
"of the room, one covered in alchemical equipment and apparently "
"ingredients, while the other bears a single chair and seems to "
"be for meals. A bed lies at the base of a small incline in the "
"%^RESET%^%^ORANGE%^dirt %^BOLD%^%^BLACK%^floor, surrounded on "
"all sides by books and scrolls.%^RESET%^");
  set_smell("default","Earthen scents tickle your nose.");
  set_listen("default","The sounds of the wood outside are "
"muted in here.");
  set_items(([
    ({"herbs","racks","game","bundles","dried herbs"}):"Several"
" circular %^BOLD%^%^BLACK%^cast-iron %^RESET%^racks dangle every"
" six feet or so from the ceiling, bearing assorted small game "
"and dried plants. Whoever lives here at least knows how to "
"cook.",
    "bed":"It actually looks quite comfortable - a blanket of "
"soft, brownish-gray rabbit fur covers the mattress, and a "
"cushy cotton pillow -probably filled with down- rests atop "
"the blanket.",
    "shelves":"%^RESET%^%^ORANGE%^Made of oak wood, they're "
"filled with an assortment of gemstones, plants and mushrooms, "
"jars of perserved animal parts...all the things an alchemist "
"would need.",
    ({"books","stacks","piles"}):"It seems whoever owns this "
"library either had no space to better organize these, or had "
"no desire to. Why put something in storage if you might need"
" to refer to it later?",
    "tables":"You can look either of them over, you know.",
    "table 1":"%^RESET%^%^ORANGE%^It's cluttered with all "
"manner of alchemical tools, from a mortar and pestle to "
"several %^WHITE%^beakers %^ORANGE%^filled with "
"%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n"
"%^MAGENTA%^i%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^t"
"%^GREEN%^e%^BOLD%^%^GREEN%^r%^RESET%^%^ORANGE%^-looking "
"%^BOLD%^%^BLUE%^li%^RESET%^%^ORANGE%^q%^YELLOW%^u"
"%^RESET%^%^ORANGE%^i%^BOLD%^%^BLUE%^ds%^RESET%^%^ORANGE%^.",
    "table 2":"%^RESET%^%^ORANGE%^Pretty nondescript, all "
"that takes up its surface is a trio of bowls, two empty, "
"the third filled with a pleasant-smelling %^RED%^s"
"%^WHITE%^t%^RED%^ew%^ORANGE%^.",
  ]));
  set_exits(([
    "outside":"/d/dagger/marsh/witchlair/rooms/hutentry.c",
  ]));
  set_door("oaken door",ROOMS"hutentry","outside",0);
  set_door_description("oaken door","%^RESET%^%^ORANGE%^Heavy "
"oaken planks run horizontally rather than vertical. Quite "
"thick from the looks of it, it would take a lot to attempt "
"breaking in - precisely what the owner would seem to want."
"%^RESET%^");
}
void reset() {
  ::reset();
  if(present("akhkserin")){
  TO->remove_exit("portal");
  }
  if(!present("ahkserin")){
    new(MON"witch.c")->move(TO);
  }
}
