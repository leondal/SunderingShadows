#include "../defs.h"

inherit INH+"assassin";

void create()
{
    set_short("%^BOLD%^%^BLACK%^A Shop of General Wares%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A Shop of General Wares%^RESET%^
%^RESET%^%^ORANGE%^Tucked away in a small alcove, this shop is host to an imposing collection of %^BOLD%^%^BLACK%^clutter%^RESET%^%^ORANGE%^. Ranging from the very valuable treasures to outright junk, the goods take up every last bit of shelf space, and sits in shifting stacks on the damp floor. A shoddy %^BOLD%^%^BLACK%^wooden counter %^RESET%^%^ORANGE%^divides the room, and hides some additional overflow of pawned things that have been stashed away in boxes. A couple %^BOLD%^hanging lanterns %^RESET%^%^ORANGE%^provide some dim light to the squalid space. Typing %^WHITE%^<help shop> %^ORANGE%^will tell you what you can do here.%^WHITE%^
");
    set_smell("default","%^RESET%^%^CYAN%^The air is heavy with the scent of decay.%^WHITE%^");
    set_listen("default","%^RESET%^%^MAGENTA%^Quiet negotiations and the exchange of coins are heard.%^WHITE%^");
    set_items(([({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^Dark stones, resilient but old, hold together this sunken tower. The persistent dampness from the flowing river outside of the crumbling walls allows for %^BOLD%^%^GREEN%^gr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n m%^RESET%^%^GREEN%^o%^ORANGE%^s%^BOLD%^%^GREEN%^s %^RESET%^%^ORANGE%^to flourish between the cracks. %^CYAN%^Water %^ORANGE%^trickles in and pools in the corners of the uneven floors, making every slippery step seem perilous.%^WHITE%^",
                ({"boxes","shelf","shelves"}) :"%^RESET%^%^ORANGE%^Roughly-hewn but sturdy old shelves line the walls, bearing the weight of an overwhelming amount of clutter. Old boxes made from wood sit behind the counter and against the cold, damp walls. They are filled with gems and scrolls, swords and scarves. Bones and crowns. Anything anyone could possibly desire is probably stashed away here.%^WHITE%^",
                "counter" : "%^RESET%^%^ORANGE%^A wooden counter stands here and its main purpose seems to be separating you from the shopkeep, who does not look happy to serve you today.%^WHITE%^"]));
    set_indoors(1);
    set_property("no teleport",1);
    set_exits(([
                   "south":ROOMS+"/assassinhall",
                   ]));
}

void init()
{
      ::init();
      if(!present("premeria",TO))
         find_object_or_load(MON+"/premeria")->move(TO);
}
