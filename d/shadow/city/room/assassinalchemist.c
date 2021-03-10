#include "../defs.h"

inherit INH+"assassin";

void create()
{
    set_short("%^BOLD%^%^BLACK%^An Alchemy Shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^An Alchemy Shop%^RESET%^
%^RESET%^%^ORANGE%^Shelves stacked high with jars line the %^BOLD%^%^BLACK%^damp %^RESET%^%^ORANGE%^walls. A solid stone table sits in the middle of the room, doubling as a counter from which to do business. At any given time the table is strewn with %^MAGENTA%^pungent powders%^ORANGE%^, %^RED%^colorful liquids%^ORANGE%^, %^GREEN%^plant pieces %^ORANGE%^and the various %^WHITE%^implements %^ORANGE%^used to crush, stir and weigh them. The alchemist pays you little heed, busy at work as she is. Typing %^WHITE%^<help shop> %^ORANGE%^will tell you what you can do here.%^WHITE%^
");
    set_smell("default","%^RESET%^%^CYAN%^Dozens of pungent odors almost mask the decaying scent of the tower.%^WHITE%^");
    set_listen("default","%^BOLD%^%^BLACK%^You hear the scurrying of little rat feet.%^RESET%^");
    set_indoors(1);
    set_items(([
                   ({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^Dark stones, resilient but old, hold together this sunken tower. The persistent dampness from the flowing river outside of the crumbling walls allows for %^BOLD%^%^GREEN%^gr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n m%^RESET%^%^GREEN%^o%^ORANGE%^s%^BOLD%^%^GREEN%^s %^RESET%^%^ORANGE%^to flourish between the cracks. %^CYAN%^Water %^ORANGE%^trickles in and pools in the corners of the uneven floors, making every slippery step seem perilous.%^WHITE%^",
                   ({"jars","powders","liquids","counter"}) : "%^MAGENTA%^Nothing here seems particularly safe to touch or taste. Some work is better left to the professionals.%^WHITE%^",
                   ]));
    set_property("no teleport",1);
    set_exits(([
                   "north":ROOMS+"/assassinhall",
                   ]));
}

void init()
{
      ::init();
      if(!present("tercera",TO))
         find_object_or_load(MON+"/tercera")->move(TO);
}
