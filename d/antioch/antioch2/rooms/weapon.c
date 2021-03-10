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
    set_short("The Serrated Mace");
    set_long(
        "%^WHITE%^This is a very clean, if somewhat small, %^WHITE%^w%^WHITE%^e%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^p%^BOLD%^%^WHITE%^ons%^RESET%^%^WHITE%^ shop. The oak wood has been painted with a finish to make the wood last longer and to give it a richer color. Towards the back of the shop in a smaller room you can see what looks likea work area that is much less clean than this one. Several different types of weapons are hung in racks around the room. A small oak %^ORANGE%^desk%^WHITE%^ is placed in the corner of the room with a comfortably padded %^BOLD%^%^BLACK%^chair%^RESET%^%^WHITE%^ behind it. The %^ORANGE%^floor%^WHITE%^ looks like it hasn't been swept in a while and there is even a broom that has started gathering cobwebs in the back. Soot stains are on the floor and some walls. The weapons, however, are kept very clean and rust free.
"
        );
    set_smell("default", "The smell of smelted iron hangs in the air.");
    if (query_night() == 1) {
        set_listen("default", "Everything is peacefully quiet at this" +
                   " time of night.");
    }else {
        set_listen("default", "The streets outside are busy with the" +
                   " sounds of shoppers.");
    }
    set_items(([
                   ({ "desk", "oak desk", "small desk" }) : "A small oak desk is" +
                   " positioned in the back right corner of the room with a" +
                   " comfortable looking chair behind it.",
                   ({ "chair", "comfortable chair", "padded chair", "oak chair" }) : "The" +
                   " oak chair appears to be built for a rather large man and it" +
                   " is padded for extra comfort. Soot stains cover the arms and" +
                   " there are a few stains on the back of the chair and the" +
                   " padding as well.",
                   "floor" : "The floor is made out of oak wood and needs to be" +
                   " swept rather badly. Dust and mud has been tracked in by" +
                   " customers and there are several soot stains on it.",
                   "ceiling" : "The ceiling is practically the only thing in here" +
                   " that hasn't been stained with soot. It is quite high and could" +
                   " easily accommodate a very tall man.",
                   ({ "weapons", "rack", "racks" }) : "All sorts of weapons are carefully" +
                   " hung in racks around the room. The blades are well polished" +
                   " and shine without a hint of rust on them.",
                   "back room" : "Straight to the north is a little room that" +
                   " contains a trough of water, black smith tools, and various" +
                   " stones used for sharpening weapons. That must be where the" +
                   " weapons smith works.",
                   ({ "door", "oak door" }) : "This sturdy door is made of oak and" +
                   " leads outside to %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
                   ({ "window", "windows" }) : "There are two small windows on the" +
                   " eastern side of the room, open to let the fresh air in.",
                   ]));
    set_exits(([
                   "south" : ROOMS + "street20",
                   "north" : ROOMS + "weap_forge",
                   ]));
    set_door("oak door", ROOMS + "street20", "south", 0);
}

void reset()
{
    ::reset();
    if (!present("felawyr")) {
        find_object_or_load(MONS + "felawyr")->move(TO);
    }
}
