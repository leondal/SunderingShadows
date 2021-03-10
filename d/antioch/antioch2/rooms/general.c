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
    set_short("%^BOLD%^The Winged %^YELLOW%^Griffin%^RESET%^");
    set_long(
        "%^WHITE%^From the looks of this place, this must be the general store. Various nicknacks cover the %^ORANGE%^shelves%^WHITE%^ along the walls, everything from a bit of string, cloth sacks, to climbing tools, torches and lanterns. All your basic adventuring requirements can be found in this shop. There is a large counter in the center of the room with a large wooden rocking %^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^air%^WHITE%^ behind it that the owner of the shop sits in. You can see %^ORANGE%^st%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^irs%^WHITE%^ in the back that probably lead up to his bedroom. The %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ are kept fairly clean here, though a bit of dirt has been tracked in by customers. This entire house and everything in it is made from %^ORANGE%^pine %^ORANGE%^wood.%^WHITE%^ There are different types, ranging from a pale white color to a golden brown. All the wood gives off that fresh pine scent, making this a pleasant little store to visit.
"
        );
    set_smell("default", "The pine wood smell that surrounds you is" +
              " pleasantly refreshing.");
    if (query_night() == 1) {
        set_listen("default", "You can hear snoring coming from the" +
                   " bedroom upstairs.");
    }else {
        set_listen("default", "You can hear the sounds of shoppers" +
                   " outside the door.");
    }
    set_items(([
                   "floor" : "This is a sturdy pine wood floor that is relatively" +
                   " dirt free.",
                   ({ "pine", "wood", "pine wood" }) : "Various types of pine wood" +
                   " make up all the furniture in the store, including the store" +
                   " itself. They range in color from the golden shade that the" +
                   " floor is made of, to the pale white of some of the shelves.",
                   "stairs" : "Stairs in the back of the room lead up to the bedroom" +
                   " but you can't get to them.",
                   "counter" : "A large pine counter sits in the center of the room," +
                   " behind it is a big rocking chair.",
                   ({ "chair", "rocking chair" }) : "This large rocking chair looks" +
                   " quite comfortable. It would easily fit a very large man and" +
                   " is used by the owner to relax.",
                   ({ "shelf", "shelves" }) : "There are many shelves all over the room," +
                   " they hold various pieces of adventuring or mundane items.",
                   ({ "equipment", "items" }) : "Many items stock the shelves of the" +
                   " general store.",
               ]));
    set_exits(([
                   "south" : ROOMS + "street19",
               ]));
    set_door("pine door", ROOMS + "street19", "south", 0);
}

void reset()
{
    ::reset();
    if (!present("gralibard")) {
        new(MONS + "gralibard")->move(TO);
    }
}
