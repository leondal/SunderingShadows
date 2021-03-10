#include <std.h>
#include "../../ud_ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_name("inside a small shrine");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^ORANGE%^inside a small %^BOLD%^shrine%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^A disturbing sight greets you, just within the "
        "entrance to this small stone shrine. All around you lie scattered "
        "dozens of small %^WHITE%^skeletons%^BLACK%^, seemingly "
        "%^RESET%^%^RED%^slain %^BOLD%^%^BLACK%^on the spot. Several of them "
        "seem to have died reaching out to one of the half dozen "
        "%^RESET%^%^ORANGE%^s%^WHITE%^t%^ORANGE%^o%^WHITE%^n%^ORANGE%^e "
        "s%^WHITE%^t%^ORANGE%^a%^WHITE%^t%^ORANGE%^u%^WHITE%^e%^ORANGE%^s "
        "%^BOLD%^%^BLACK%^set into alcoves along the wall, while others seem to "
        "have been protecting a group of smaller bodies, off in one corner. Most "
        "of the exits from this chamber have caved in, and a short path into "
        "what looks like an altar room is your only viable path forward."
        "%^RESET%^"
    );
    set_smell("default", "The air smells of earth and ash.");
    set_listen("default", "The cavern winds carry a mournful tone through the room.");
    set_exits(([
        "west" : ROOMS"cliff/shrine2",
        "out" : ROOMS"cliff/cliff_2",
    ]));
    set_items(([
        (("statues","alcoves","statue")) :
            "%^ORANGE%^Inset into the chamber walls at regular intervals are "
            "ix small alcoves, each of them looking to be quite carefully "
            "crafted and solid despite the otherwise rough materials making up "
            "the shrine as a whole. Upon a small pedestal in each sits a statue "
            "of an %^GREEN%^old gnome%^ORANGE%^, dressed in light armor. His "
            "eyes are crafted from bits of carefully-polished "
            "%^BOLD%^t%^RESET%^%^ORANGE%^o%^BOLD%^p%^RESET%^%^ORANGE%^a"
            "%^BOLD%^z%^RESET%^%^ORANGE%^, and he wields a "
            "%^BOLD%^%^WHITE%^battle-axe %^RESET%^%^ORANGE%^in one hand, "
            "while the other holds a well-used "
            "%^BOLD%^%^BLACK%^pickaxe%^RESET%^%^ORANGE%^. Before the statues "
            "are several burned-down candles and incense.%^WHITE%^",
        ({"skeletons","corpses"}) :
            "The %^BOLD%^skeletal %^RESET%^bodies strewn about the shrine tell a "
            "myriad of different stories, though there is little to identify what "
            "might have ultimately led them to this fate. Broken "
            "%^BOLD%^%^BLACK%^weapons %^RESET%^are discarded next to some "
            "skeletons, who still wear the dried and cracked remains of "
            "%^ORANGE%^leather armor%^WHITE%^, while others are curled up in "
            "corners, with no signs of having put up a resistance. Their "
            "apparent causes of death look to be equally varied - some of the "
            "remains leave no marks behind at all, while other skeletons seem to "
            "have been completely crushed."
        ]));
}

void block_west() {
    if (query_exit("west") == "/d/shadowgate/void") { return; }
    tell_room(TO,
        "%^BOLD%^%^BLACK%^The western exit is suddenly blocked by an "
        "%^WHITE%^impenetrable %^BLACK%^darkness!"
    );
    remove_exit("west");
}

void unblock_west() {
    if (!(query_exit("west") == "/d/shadowgate/void")) { return; }
    tell_room(TO,
        "%^BOLD%^%^BLACK%^The darkness blocking the western exit dissipates."
    );
    add_exit(ROOMS"cliff/shrine2","west");
}
