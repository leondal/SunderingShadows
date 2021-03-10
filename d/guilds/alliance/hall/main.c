//Updated to reflect castle being unoccupied for nearly 50 years.
//Connected back up mage lab for shits and giggles to give players
//another mirror to use for PK.  Last update 4/6/03. - Octothorpe 1/2/09
// /d/guilds/alliance/main.c

#include <std.h>

inherit VAULT;

void create()
{
//   object ob;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(2);
    //set_property("no teleport",1);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("Main Hall in the Castle of the Alliance");
    set_long("%^CYAN%^Main Hall in the Castle of the Alliance%^RESET%^\n " +
             "%^BOLD%^This is the main hall of a once magnificent castle, on " +
             "the walls you see old paintings of the knights that once lived " +
             "in this castle.  The hall is lit by a handful of torches and " +
             "chandeliers, which appear to have been magically enchanted to " +
             "burn perpetually.  The floor is made of pure %^BOLD%^%^CYAN%^" +
             "marble %^WHITE%^that reflects the light from the torches.  You " +
             "notice the exits leading to the many rooms of the " +
             "castle.%^RESET%^\n");
    set_listen("default", "You almost think you can hear the echo of phantom voices clanging through the castle.");
    /*set_long(
       @DESC
       %^CYAN%^Main Hall in the Castle of the Alliance%^RESET%^
       %^BOLD%^%^WHITE%^You are standing in the main hall of the magnificent castle,
       on the walls you see old paintings of the knights that once
       lived in this castle. The hall is lit by many torches on the
       wall and many chandeliers hanging from the ceiling. The floor
       is made of pure %^BOLD%^%^CYAN%^marble%^RESET%^%^BOLD%^%^WHITE%^ that reflects the light from the torches.
       You also notice the exits leading to the many rooms of the
       castle. You see a giant posting board where the warriors of
       the %^CYAN%^Alliance%^RESET%^%^BOLD%^%^WHITE%^, gather to read and write about the news of the
       lands.
       DESC
       );
       set_listen("default","You hear the voices clanging through the castle.");*/
    set_smell("default", "You smell candles and torches burning.");
    set_exits(([
                   "north" : "/d/guilds/alliance/hall/stair1",
                   "south" : "/d/guilds/alliance/hall/hall",
                   "east" : "/d/guilds/alliance/hall/lab.c",
                   "west" : "/d/guilds/alliance/hall/leaders",
               ]));
    set_items(([
                   "marble" : "%^BOLD%^%^WHITE%^At first glance this marble floor doesn't look special in any way, but as you step backwards you see an image of something starting to take shape. In the fine marble floor you see a carved picture that represents two gauntlets shaking hands. This was the symbol of the %^CYAN%^Alliance.",
               ]));
/*  removing the unused boards entirely *Styx*  4/5/03
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "posting board", "alliance board" }) );
   ob->set_board_id("alliance_board");
   ob->set("short", "Posting board of the Alliance");
   ob->set("long", "A board for the members of the Alliance to share news of the lands.\n");
   ob->set_max_posts(30);
   ob->set_location("/d/guilds/alliance/hall/main.c");
 */
    set_door("door", "/d/guilds/alliance/hall/lab", "east", "alliance ring");
    set_open("door", 0);
    set_locked("door", 1);
    "/d/guilds/alliance/hall/lab"->set_open("door", 0);
}
