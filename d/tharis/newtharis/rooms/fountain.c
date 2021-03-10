#include <std.h>
#include "../tharis.h"
inherit STORAGE"bazaar.c";

void create(){
    ::create();
    set_name("Centre of the city bazaar");
    set_short("%^BOLD%^%^CYAN%^Centre of the city bazaar%^RESET%^");
    set_long(::query_long()+"\n%^BOLD%^%^BLACK%^In the middle of the bazaar stands a tall obsidian statue of a man.%^RESET%^\n");
    set_exits(([
      "southwest" : ROOMS"square4",
      "west" : ROOMS"square3",
      "south" : ROOMS"square5",
      "northeast" : ROOMS"square8",
      "northwest" : ROOMS"square2",
      "southeast" : ROOMS"square6",
      "north" : ROOMS"square1",
      "east" : ROOMS"square7",
    ]));
    add_item(({"statue","obsidian statue"}),"%^BOLD%^%^BLACK%^In the middle of the bazaar stands "
"an obsidian statue of a tall, slender man in archaic robes. The statue towers over the tents and "
"shops, standing at least twenty feet high. A book is held in his left hand, while his right is "
"raised as if in the act of invoking a spell. At his throat hangs a plain circular pendant. The "
"statue is an impressive sight, the obsidian gaining an eerie sheen from the town's lights as it "
"stands watch in the perpetual twilight. A plaque at the bottom of the statue reads '"
"%^BOLD%^%^WHITE%^High Lord Valaerius, who guides us safely through the darkness"
"%^BOLD%^%^BLACK%^'.%^RESET%^"); 
}

// or eyphah, meaning darkness/gloomy