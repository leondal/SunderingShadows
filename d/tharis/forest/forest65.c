//forest65.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();

    set_properties((["light":2,"indoors":0]));
    set_short("Small clearing in the forest");

    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_long(
       "%^BOLD%^%^GREEN%^This is a small clearing in the forest%^RESET%^\n"
       "In the center of this clearing is an ancient stump. Tall "
       "grass waves lightly in the breeze a certain freshness and "
       "tranquility exists here. The lovely air surrounds you "
       "peacefully. You can feel that good has a strong influence here."
    );
    set_smell("default","The wonderful fragrances of nature abound here.");
    set_listen("default","You can almost hear the cheery sounds of nature as the wind caresses your face.");
    set_exits(([
        "north":"/d/tharis/forest/forest64",
        "enter":"/d/tharis/forest/hole1"
        ]));
    set_items(([
        "grass":"This is a thick, green grass not uncommon to meadows.",
        "stump":"This grand old stump is apparently some work of magic.\n As you look closer you see a hole in the base where you can %^BOLD%^enter.",
        "hole":"It is quite dark down in there, but it is plainly made for humanoids to use."

        ]));
        set_invis_exits(({"enter"}));
}


