//  Created by Grolim, for ShadowGate
//  Coded 18 Jun, 1995
//  Forest around Antioch
//  Modified by Crystal to add in Moonstone Vale
//  Modified by Styx to add entrance to Abrahil's home 3/17/02
//  Modified by Circe when Eldath's temple became just a grove 4/19/04

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_climate("mountain");
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no castle", 1);
    set("short", "A trail");
    set("long", "This is a trail leading through a dense forest.  Although "
        "the area in general is quite unsettling, there is a slightly different "
        "feel here.  Trees and heavy brush line the trail but open to a temple to "
        "the northwest.  A tree that used to block the trail to the northeast has "
        "been chopped down and moved to the side.  The trail northeast looks very "
        "dark and foreboding.\n"
        );
    set_exits(([
                   "south" : FOREST + "trail5",
                   "grove" : "/d/magic/temples/eldath",
                   "northeast" : "/d/antioch/valley/rooms/dt1",
                   "brush" : "/d/player_houses/abrahil/yard",
               ]));
    add_invis_exit("brush");
    add_pre_exit_function("go_thru", "brush");
    set_search("brush", "The brush to the west looks like you could get through "
               "it.");
    set_search("default", "You notice the brush to the west looks thinner than "
               "the rest.");
    set_smell("default", "A soft breeze from the west smells fresh and clean.");
    set_listen("default", "You hear the sounds of a bubbling brook nearby.");
    set_items((["brush" : "The brush looks thinner to the west.",
                "trees" : "Trees, which have been here for years are thinner to the west.",
                "tree" : "Just a tree blown down by the wind that" +
                " has been chopped up and moved to the west side of the trail.",
                "birds" : "All types and varieties, singing and flying around.",
                "flowers" : "It seems as if they had grown here forever.",
                "flower" : "A nice looking one.",
                ({ "forest", "east" }) : "A mystical forest of pure evil.",
               ]));
}

int go_thru()
{
    tell_object(TP, "The brush parts easily as you move westward through it.");
    tell_room(ETP, "The brush to the west seems to part easily as " + TPQN + " moves "
              "through it.");
    return 1;
}

void reset()
{
    ::reset();
    if (!present("sign")) {
        new("/d/common/obj/areas/darktrail_sign.c")->move(TO);
    }
}
