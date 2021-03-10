#include <config.h>

inherit "/std/room";

void create() {
    object ob;

    ::create();
    set_light(2);
    set_indoors(1);
    set_short("The Hall of the Immortals");
set_long(
@THORN
This is the meeting green room of the immortals of Shadowgate. In this
room, matters of mud policy and events are discussed by all Shadowgate
immortals so that everyone might know what is going on.  There is a room
for discussing LPC south and a planning room east where immortals post
their plans for areas domains, guilds, and quests.  The Statistics and
Balance Board Room is to the west.  The Mudlib board is up.  The Bug
Board is SW.
THORN
);
    set_exits(
              (["up" : "/d/standard/mudlib",
			    "southwest" : "/d/standard/bug",
                "north" : "/d/standard/adv_main",
                "south" : "/d/standard/lpc_inner",
                "west" : "/d/standard/stat",
                "east" : "/d/standard/planning_room"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "reality board" }) );
    ob->set_board_id("immortal");
    ob->set_max_posts(30);
    ob->set_location("d/standard/adv_inner");
    ob->set("short", "Immortal's Reality Board");
    ob->set("long", "Posts any notes concerning the mud which do "
            "not belong out in a public forum among players "
            "here for immortal discussion.\n");
    set_property("no steal", 1);
}

int receive_objects() {
  if(!previous_object()->is_player())
    return 1;
  if(!wizardp(previous_object())) {
    message("my_action", "You are not permitted to enter "
            "this area.\n", previous_object());
    return 0;
  }
  return 1;
}
