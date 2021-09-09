#include <std.h>
#include "../tharis.h"
inherit STORAGE"trade";

void create(){
   ::create();
    set_long("%^RESET%^%^CYAN%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^CYAN%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. Below, the citizens of the city go "
"about their day-to-day activities, a constant stream of feet passing over the well-kept "
"%^ORANGE%^cobblestones%^CYAN%^. To either side rise what appear to be relatively new buildings, some "
"not even quite complete and clearly still under construction. Only a few steps further southwards, the "
"city comes abruptly to its end at a pair of %^BLUE%^looming %^CYAN%^iron gates, beyond which lie the "
"foothills of the mountains beyond. A wide path ascends to the pinnacle of the nearest rise, where you can "
"see a tall and %^BOLD%^%^BLACK%^ominous %^RESET%^%^CYAN%^ structure, lying deep within the gloom cast by "
"the fortress far above. A small but constant stream of people seem to be coming from it, or heading towards "
"it.%^RESET%^\n");
   set_exits(([
      "north" : ROOMS"north5",
      "west" : "/d/tharis/newtharis/rooms/jail_main",
      "southeast" : "/d/magic/temples/lord_shadow/lord_shadowentry",
   ]));
   add_item("buildings","%^CYAN%^The buildings here seem to be quite new, some not even entirely "
"complete just yet. It looks as though this section of the city is being gradually rebuilt. A few "
"sections of rubble still remain between the existing structures, likely remnants of whatever "
"buildings once stood here and are now being replaced. A few teams of builders can be spotted "
"in and around some of the structures, hard at work even as you watch.%^RESET%^");
}