/*
   yard.c

   Rewritten for the new guild Alliance Reborn.

   -- Tlaloc -- 01 - 20
 */

#include <std.h>

inherit ROOM;

void create()
{
    ::create();

    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_indoors(0);
    set_light(3);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("At the Castle Courtyard");
    set_long("\n\
%^CYAN%^Castle Courtyard%^RESET%^%^BOLD%^\n" +
             "This is the courtyard of the keep of the Alliance Reborn. Although there " +
             "seems to be a lot of wear and tear here, there is also what appeares to be " +
             "various construction workers affecting repairs. You see ladders set up against " +
             "walls and a myriad of tools strewn about on benches in the courtyard. On the " +
             "edges of the lower walls you see flocks of crows watching the people below.%^RESET%^");
    set_listen("default", "You hear the sounds construction work being done around you.");
    set_smell("default", "You smell a mix of sweat and the stables in the air.");
    set_exits(([
                   "north" : "/d/guilds/alliance/hall/hall",
                   "south" : "/d/guilds/alliance/hall/gate",
                   "west" : "/d/guilds/alliance/hall/stable",
                   "east" : "/d/guilds/alliance/hall/holy",
               ]));
}
