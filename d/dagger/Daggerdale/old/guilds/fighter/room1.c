#include <std.h>

inherit ROOM;

void create() {
    object ob;
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("no teleport", 1);
    set_short("%^BOLD%^Gathering place of the Fighters");
    set_long(
      "You have entered a great hall tucked away in the back corners of Daggerdale, and well hidden from unwanted eyes.  In this room, pictures of great warrors battling the great monsters of the lands cover the walls, along with items of the fighters, from simple shields, to replicas of great weapons and armors."
    );
    set_items( ([
	"paintings" : "The faces of the warriors are difficult to make out as they are engrossed in combat with powerful monsters.  More amazing is that as you look at the paintings, they are changing slowly as the battle progresses, within the battle, and as the battle changes, the faces and the monsters also slowly change.  It is interesting to just sit and watch the paintings change.",
	"armor" : "They are not real, made from cheap thin tin.",
	"armors" : "They are not real, made from cheap thin tin.",
	"weapon" : "They are not real, made from cheap thin tin.",
	"weapons" : "They are not real, made from cheap thin tin.",
      ]));
    set_exits(([
    "north" : "/d/dagger/Daggerdale/guilds/fighter/arenaheal",
	"out" : "/d/dagger/Daggerdale/shops/inn_ward.c",
      ]));

    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board", "fighter board"}));
    ob->set_board_id("Dagger_fighter_board");
    ob->set_max_posts(30);
    ob->set_location("/d/dagger/Daggerdale/guilds/fighter/room1.c");
    ob->set_short("Fighter's board of glorious deeds");
    ob->set_long("Fighter's board of glorious deeds, and other things");
}
