// /d/guilds/alliance/holy.c

#include <std.h>

inherit ROOM;

void create()
{
    object ob;

    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_indoors(1);
    set_light(2);
    set_short("Holy room");
    set_long(
        "%^CYAN%^ Holy room %^RESET%^BOLD%^"+
        "This is the holy room of the castle, here the warriors come"+
        "to strengthen thier faith and to remember their lost friends"+
        "and loved ones.  In the end of the room you see a large altar"+
        "filled with white candles, you also see holy symbols and torches"+
        "on the walls.%^RESET%^"  );
    set_listen("default", "The silence dominates this room.");
    set_smell("default", "You smell candles.");
    set_exits(([
                   "west" : "/d/guilds/alliance/hall/yard.c",
               ]));
}