#include "../defs.h"

inherit VAULT;

void create()
{
    set_short("%^BOLD%^%^BLACK%^Standing Atop a Sunken Tower%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Standing Atop a Sunken Tower%^RESET%^
%^RESET%^%^ORANGE%^From the tip of the emerging %^WHITE%^tower%^ORANGE%^, you have a much better view of the shallows around %^MAGENTA%^Shadow%^ORANGE%^. Broken buttresses and buildings that have slid away into the shoreline form a makeshift breakwall against what little current still makes it this far from the sea. The tumbled heaps of masonry almost look like a warped, sunken reflection of the city, complete with towers that rise just above the surface of the water. There is a %^CYAN%^hatch %^ORANGE%^built into the stonework at your feet.%^WHITE%^
");
    set_smell("default","%^BOLD%^%^GREEN%^Decaying fish and stagnant water invade your senses.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^The languid swell of water and the sharp cries of seagulls fill your ears.%^WHITE%^");
    set_items(([
                   ({"shallows","water"}) : "%^BOLD%^%^BLUE%^All manner of aquatic life has conquered the ruins beneath the waves, as small schools of minnows weave their way through submerged columns and masonry.%^RESET%^",
                   ]));
    set_exits(([
                   "down":ROOMS+"/assassinentr",
                   ]));
    set_door("hatch",ROOMS+"/assassinentr","down",0,0);
    set_door_description("hatch","%^RESET%^%^ORANGE%^The hatch is worn and weathered, and constructed of stout oak. A strange series of sigils line the periphery, occasionally flickering with obscene colors.%^WHITE%^");
}

void init()
{
    ::init();
    add_action("swim_to","swim");
}

int swim_to(string str)
{
    tell_room(TO,"%^BLUE%^"+TP->QCN+" quickly descends into water and swims away.",TP);
    write("%^BLUE%^You quickly descend into water and make your way to the docks through the shallow water.");
    TP->move(ROOMS+"/dock3");
    TP->force_me("look");
    return 1;
}
