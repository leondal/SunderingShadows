// /d/guilds/alliance/hall.c

#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(2);
    //set_property("no teleport",1);
set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("Front hallway of the castle");
    set_long("%^CYAN%^Front hallway of the castle%^RESET%^\n " +
             "%^BOLD%^%^WHITE%^You are standing in the hallway inside the " +
             "castle. One end of the hallway leads into the large main hall " +
             "and at the other end you see the large oak door that leads to " +
             "the courtyard. On each side of the hallway the body armour " +
             "of %^CYAN%^knights%^BOLD%^%^WHITE%^ are set up to symbolize " +
             "guards. On the walls magical torches are burning and the floor " +
             "is covered with a weathered %^RED%^red%^RESET%^%^BOLD%^%^WHITE%^ " +
             "carpet.\n");
    set_listen("default", "The sound of your own steps echoes through the hallway.");
    set_smell("default", "You smell a mixture of old armour and torches burning.");
    set_exits(([
                   "north" : "/d/guilds/alliance/hall/main.c",
                   "south" : "/d/guilds/alliance/hall/yard.c",
                   "west" : "/d/guilds/alliance/hall/common.c",
               ]));
    set_items(([
                   "knight" : "%^CYAN%^This is the armour of noble warriors. It has been polished and looks like it is in fine condition. You see armour similar to this one standing all along both sides of the hallway. The gauntlets of these armours are placed on the hilts of two handed swords and it almost looks like these armours are real living guards standing ready to defend the castle.",
               ]));
}
