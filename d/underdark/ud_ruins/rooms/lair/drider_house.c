#include <std.h>
#include "../../ud_ruins.h"

inherit ROOM;

void create() {
    ::create();
    set_name("a forboding crevice");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    set_property("no teleport", 1);
    set_short(
        "%^CYAN%^a %^RED%^forboding %^CYAN%^crevice%^WHITE%^"
    );
    set_long(
        "%^RED%^This is a small crevice within the tunnel walls, roughly "
        "circular in shape and about thirty feet across. Something seems to "
        "dwell here, judging by the discarded piles of %^ORANGE%^junk "
        "%^RED%^against the walls, and, more worryingly, the numerous "
        "%^BOLD%^%^WHITE%^skeletons %^RESET%^%^RED%^hanging by webs from the "
        "ceiling.%^WHITE%^"
    );
    set_smell("default", "The stench of decay and mold fills the air.");
    set_listen("default", "A faint clattering can be heard from outside.");
    set_exits(([
        "south" : ROOMS"lair/lair_4",
    ]));
    set_items(([
        ({"walls","tunnels"}) :
            "%^BOLD%^%^BLACK%^The walls here are surprisingly smooth, looking "
            "to have been eroded away over the centuries. Taken with its high "
            "walls and the large deposits of loose sediment underfoot, it is "
            "likely that these tunnels were once part of some "
            "%^RESET%^%^CYAN%^subterranean river%^BOLD%^%^BLACK%^.",
        "skeletons" :
            "%^BOLD%^Judging by their poses, and the fractures to be found "
            "around their wrists, many of these corpses were still alive at "
            "the time of their hanging. The skeletons are slightly smaller and "
            "more slender than a human's, hinting at some kind of elven "
            "heritage, and most of the skeletons are heavily "
            "%^RED%^mutilated%^WHITE%^, bearing many splinters and puncture "
            "wounds.",
        "junk" :
            "%^RED%^Some of these objects may have been useful at some "
            "point - swords and armor and jewelry - but time and neglect has "
            "eroded them into little more than heaps of rust.",
        ]));
        new(MON"drider_recluse")->move(TO);
}

void reset() {
    ::reset();
    if(!present("drider recluse",TO)) {
        new(MON"drider_recluse")->move(TO);
    }
}
