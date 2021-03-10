//	Bug Board Room
//	Thorn@Shadowgate
//	10/7/94
//	Immortal Area
//	bug.c


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
This is the room where the almighty Bug Board is located.  
Post any bugs that you cannot handle on your own here or
bugs that are so serious that other wizards might be advised
to be wary of them.
THORN
);
    set_exits(
              (["northeast" : "/d/standard/adv_inner"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bug board" }) );
    ob->set_board_id("bug");
    ob->set_max_posts(30);
    ob->set_location("d/standard/bug");
    ob->set("short", "Bug Board");
    ob->set("long", "Post here any bugs that you are not able to fix yourself.\n");
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