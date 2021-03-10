//	Balance and Statistics Board Room
//	Thorn@Shadowgate
//	9/28/94
//	Immortal Sector
//	stat

#include <std.h>

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("Balance and Statistics Board Room");
set_long(
@THORN
This room is where the balance charts and the statistics required for
building monsters, objects, weapons, etc. are posted.  Please post
balance tables and any stat changes here!  Down is the square, out is 
the immortal board.
THORN
);
    set_exits(
              (["down" : "/d/standard/square",
                "east" : "/d/standard/adv_inner"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "stat board" }) );
    ob->set_board_id("stat");
    ob->set_max_posts(30);
    ob->set_location("/d/standard/stat");
    ob->set("short", "Statistics and Balance Board");
    ob->set("long", "Please post the stats and any stat changes
here!\n");

}
