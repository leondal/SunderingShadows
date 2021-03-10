//wroad stuff
//updated by ~Circe~ 7/21/19 to mention the temple of Kreysneothosies
#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
   ::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
   set_short("Crossroads of the Empires");
   set_long("%^BOLD%^%^YELLOW%^Crossroads of the Empires%^RESET%^\n"
      "This intersection branches off into roads leading to three major cities "
      "of the realms. To the east, a long, straight road runs to the wealthy "
      "trading city of Tharis, while the northern road leads through dense "
      "forests to Tabor. The Tsarven empire stretches to the west and south, "
      "where a broad road paves the way to the gates of Azha, an outpost of "
      "the grand empire. Standing just to the west of the crossroads is a %^BOLD%^%^CYAN%^domed "
      "%^RESET%^temple featuring %^MAGENTA%^twin minarets %^RESET%^reaching toward the "
      "sky and a vaulted %^ORANGE%^iwan%^RESET%^ leading to the door.\n\n"
      "Rumors abound about the Tsarven empire and what might lurk in "
      "the mountains to the south. Some even say a grand elven civilization lies "
      "hidden in the forest.\n");
   set_exits(([
      "temple":"/d/magic/temples/kreysneothosies/kreysneothosies",
      "southeast":"/d/azha/town/wroad",
      "east":"/d/tharis/road/wroad29",
      "north" : "/d/darkwood/tabor/road/road28"
   ]));
   set_items(([
      "temple" : "The temple is crafted of %^RESET%^%^ORANGE%^earthy stone "
         "%^RESET%^that contrasts the %^BOLD%^%^CYAN%^sky-blue dome %^RESET%^at "
         "the temple\'s center. Twin %^MAGENTA%^minarets %^RESET%^spire up toward "
         "the sky, and the building sprawls to the west, hinting that the walls "
         "conceal more than a single room.",
      "iwan" : "The iwan or entryway is a three-sided hallway with a vaulted "
         "ceiling towering overhead. The front is shaped into a pointed archway "
         "and decorated with geometric etchings filled with glittering gold."
   ]));
   set_smell("default","The dusty road combines with the fragrances of the forest.");
   set_listen("default","The wind rustles the leaves as the murmur of voice drifts on the breeze.");
}
