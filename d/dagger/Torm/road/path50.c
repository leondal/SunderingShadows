#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_short("Rocky outcropping on the Dagger Sea");
   set_long("%^CYAN%^The rocky outcropping comes to an end here "
      "at the foot of a temple. Enormous pale %^RESET%^stone blocks "
      "%^CYAN%^form tall walls that rise high overhead, nearly blotting "
      "out the sun this close up. Carved into their surface are "
      "%^BOLD%^symbols%^RESET%^%^CYAN%^ and %^ORANGE%^figures %^CYAN%^"
      "that wrap around as far as the eye can see. Far to the southeast "
      "the walls of Torm can still be seen, but it means so very little across so much sea.%^RESET%^\n");
   set_items(([
      ({"temple","walls","blocks","stone blocks"}) : "Each block is "
         "about the height of an average dwarf and fashioned from "
         "pale stone worn smooth by the elements. Symbols and "
         "figures are carved into the surface, perhaps giving some hint "
         "as to this building's purpose.",
      ({"figures","symbols"}) : "Images representing %^RED%^f%^BOLD%^i"
         "%^YELLOW%^r%^RESET%^%^RED%^e%^RESET%^, %^CYAN%^w%^BOLD%^a%^WHITE%^t"
         "%^CYAN%^e%^RESET%^%^CYAN%^r%^RESET%^, %^ORANGE%^ea%^YELLOW%^r%^BOLD%^"
         "%^BLACK%^t%^RESET%^%^ORANGE%^h%^RESET%^, and %^BOLD%^%^BLUE%^a%^CYAN%^i"
         "%^BLUE%^r%^RESET%^ decorate the surface of the wall, interspersed with "
         "alchemical symbols for the elements and depictions of elementals and "
         "their genasi kin.",
      ({"torm","Torm"}) : "The walls of the city are barely visible far in the "
         "distance, dwarfed by the wide sea and the imposing walls of the temple."
   ]));
   set_exits(([
      "northwest":ROAD+"path49",
      "temple":"/d/magic/temples/seija/seija"
   ]));

   set_listen("default","The area is rather serene with only the sound of waves and occasional seabirds.");
   set_smell("default","The air here is crisp and clean, carrying a hint of salt.");
}
