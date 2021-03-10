#include <std.h>
#include "/d/common/common.h"
inherit "/std/room";

void create()
{
    ::create();
    set_property("no teleport", 1);
    set_exits((["up" : "/d/shadow/city/room/assassinscrolls"]));
}

void reset()
{
    int i;
    object scroll, wand;

    for (i = 0; i < roll_dice(4, 6); i++) {
        if (!present("parchment " + i)) {
            new("/d/tharis/obj/parchment")->move(TO);
        }
    }
    for (i = 0; i < roll_dice(5, 20); i++) {
        if (!present("scroll " + i)) {
            scroll = new("/d/magic/safe_scroll");
            scroll->move(TO);
            scroll->set_spell(random(9) + 1);
        }
    }
    for (i = 0; i < roll_dice(2, 6); i++) {
        if (!present("wand " + i)) {
            wand = new("/d/magic/obj/r_wand");
            wand->move(TO);
        }
    }
}
