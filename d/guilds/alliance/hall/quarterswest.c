/*
   quarterswest.c

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
    set_short("%^YELLOW%^Yellow Quarters%^RESET%^");
    set_long("\n\
%^YELLOW%^Yellow Quarters - Squad Bay%^RESET%^\n" +
             "This is a large room meant to house up to twelve people in relative comfort. It is a squad bay setup with two rows of three bunks, complete with footlockers. There is a small stone fireplace on the far wall with a mantle holding the crest of the Alliance Reborn. Around the fire is a set of simple wooden chairs. ");
    set_exits(([
                   "east" : "/d/guilds/alliance/hall/common",
               ]));

    set_door("yellow door", "/d/guilds/alliance/hall/common", "east");
}
