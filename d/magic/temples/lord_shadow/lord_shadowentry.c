//Temple of Lord Shadow - created by Nienne 2/18
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_terrain(HILLS);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_name("Standing before a forbidding temple");
   set_short("%^BOLD%^%^CYAN%^Standing before a forbidding temple%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Standing before a forbidding temple%^RESET%^\n"
"%^CYAN%^You stand upon a path ascending the first of the %^GREEN%^Tharisian foothills%^CYAN%^, with taller mountains rising to all "
"sides but the north, and the looming bulk of the hovering %^BLUE%^Shadovar %^CYAN%^fortress far in the sky above.  Back to the south, "
"you can see the city gates, and the streets of the city beyond laid out in an orderly fashion.  Off to the side of the path, a small "
"opening leads into a cavern within the mountains, its depths quickly lost to %^BLUE%^darkness%^CYAN%^.  A short distance further up, "
"at the pinnacle of this hill, stands a tall and %^BOLD%^%^BLACK%^ominous %^RESET%^%^CYAN%^ structure of classical Zin'Charu architecture, "
"raised upon a high podium of %^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k m%^BOLD%^%^BLACK%^arb%^RESET%^le%^CYAN%^.  Orderly columns "
"surround a wide portico, and lift to the pediment which has been filled with statuary of %^RED%^terrible %^CYAN%^creatures that leer "
"and snarl down upon any that dare ascend the temple steps.\n%^RESET%^");
   set_smell("default","The air is clear and fresh.");
   set_listen("default","There is a heavy silence here, occasionally broken by the murmurs of passersby.");
   set_exits(([
      "northwest": "/d/tharis/newtharis/rooms/north6",
      "enter": "/d/magic/temples/shar_path5",
      "temple": "/d/magic/temples/lord_shadow/lord_shadow",
   ]));
}