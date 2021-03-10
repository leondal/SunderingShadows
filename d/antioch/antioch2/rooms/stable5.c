#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("A storage room");
    set_long(
        "%^WHITE%^This is a room in the Antioch stables where the %^ORANGE%^grain%^WHITE%^ and hay are stored. There are %^ORANGE%^bags%^WHITE%^ of different sorts of grains and oats along the %^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^loors%^WHITE%^ and piles of hay. There are also treats for horses here. You notice sugar cubes, carrots, and a few %^GREEN%^a%^RED%^pple%^GREEN%^s%^RED%^.%^WHITE%^ The stable boys probably hide them here and sneak them to the horses for good behavior. You notice that this is the only room with a door, and it is probably to keep the horses from smelling the treats, or getting in here and gorging on grain in the off chance that they get loose. Spare %^ORANGE%^saddles%^BOLD%^%^BLACK%^,%^RESET%^ %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^dles,%^WHITE%^ saddle pads, %^BOLD%^%^BLACK%^buck%^BLACK%^e%^BLACK%^ts,%^RESET%^%^WHITE%^ ropes, %^ORANGE%^h%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^lters,%^WHITE%^ and grooming brushes are also kept here.
"
        );
    set_smell("default", "This room smells of grain and hay and the" +
              " faint scent of horses.");
    set_listen("default", "You can hear the horses stomping about in" +
               " the northern stalls.");
    set_items(([
                   ({ "ground", "floor", "dirt" }) : "The floor here is simply dirt so" +
                   " that the horses won't hurt their feet.",
                   "ceiling" : "The ceiling is high with an arched roof. Chains" +
                   " hang down from it that hold light stones.",
                   ({ "light", "stone", "enchanted stone", "light stone", "enchanted stones", "light stones", "stones" }) : "%^BOLD%^Stones that have been enchanted" +
                   " with a continual light spell are hung from the ceiling. It gives" +
                   " easy and constant light to the area without having to worry" +
                   " about the possibilities of fires.",
                   "door" : "The door looks pretty sturdy, a horse couldn't kick it" +
                   " down very quickly at all. It is probably there to keep the" +
                   " horses out of this room.",
                   ({ "grain", "grains", "oat", "oats" }) : "There are many different" +
                   " types of grains here. Some of them are softer, others harder," +
                   " some are mixed with oats or are simply different types. A few" +
                   " look to be more sugary and some have a vitamin smell to them.",
                   ({ "bags", "grain bags" }) : "Bags of grain are piled about the" +
                   " room.",
                   "hay" : "%^YELLOW%^Hay is heaped in stacks on the left side of" +
                   " the room. It looks pretty fresh, it's probably refilled every" +
                   " morning.",
                   ({ "shelf", "shelves" }) : "There are shelves on the right hand side" +
                   " of the room that are stocked with different things, mostly" +
                   " little treats for the horses.",
                   ({ "apple", "apples", "treat", "treats", "sugar cubes", "carrots", "carrot", "sugar cube" }) : "It is a treat for the" +
                   " good horses that the stable hands probably sneak to them from" +
                   " time to time.",
                   ({ "saddle", "saddles" }) : "Several different types of saddles are" +
                   " stored in the back of the room.",
                   ({ "saddle pad", "saddle pads" }) : "The saddle pads are kept next" +
                   " to the saddles in the back of the room.",
                   ({ "halter", "ropes", "halters" }) : "Halters and ropes are stacked" +
                   " in neat piles with the ropes carefully coiled so as not to get" +
                   " tangled.",
                   ({ "bridle", "bridles" }) : "Different types of bridles with various" +
                   " bits are hung along the back wall of the room.",
                   ({ "brushes", "grooming brushes", "tack" }) : "Extra grooming items" +
                   " are stored in the back of the room here.",
                   ({ "bucket", "buckets" }) : "The spare grain buckets are stored in" +
                   " the back of this room.",
               ]));
    set_exits(([
                   "north" : ROOMS + "stable3",
               ]));
    set_door("door", ROOMS + "stable3", "north", 0);
    if (query_night() != 1) {
        new(MONS + "mellany")->move(TO);
    }
}
