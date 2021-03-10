/*
   quartersnorth.c

   Written for the new guild Alliance Reborn.

   -- Tlaloc -- 3.24.20
 */

#include <std.h>

inherit VAULT;

void create()
{
    ::create();

    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(3);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("%^RESET%^%^GREEN%^Green Quarters%^RESET%^");
    set_long("\n\
%^GREEN%^Green Quarters%^RESET%^\n" +
             "This is a simple, yet comfortable room with two spacious beds with night stands, a wooden dresser and a small closet. On the wall opposite from the beds is a small stone fireplace, and a nice, warm fire crackles, making this a very homey space.");
    set_exits(([
                   "south" : "/d/guilds/alliance/hall/common",
               ]));

    set_door("green door", "/d/guilds/alliance/hall/common", "south");
}
