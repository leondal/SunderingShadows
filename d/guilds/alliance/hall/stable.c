// /d/guilds/alliance/stable.c

#include <std.h>

inherit "/d/common/inherit/hitching_post";

void create()
{
    object ob;

    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_indoors(1);
    set_light(2);
    set_short("Stables");
    set_long("%^CYAN%^Stables%^ORANGE%^\n " +
             "This is the stables, where the different mounts of the warriors " +
             "were kept. Aside from the old, musty smell this building is in " +
             "good shape. This looks like a good place to keep your mount.\n");
    set_listen("default", "You hear people working and steeds neighing.");
    set_smell("default", "You smell a mixture of straw, hay, and old manure.");
    set_exits(([
                   "east" : "/d/guilds/alliance/hall/yard.c",
               ]));
}
