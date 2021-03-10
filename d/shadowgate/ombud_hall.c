inherit "std/room";

void create() {
   object ob;

    ::create();
    set_property("no teleport", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("%^BOLD%^Someplace you don't belong any more.  Please leave immediately.");
    set_long("This used to be the complaints dept. but is now retired.  Please leave now!");
//    set("short", "Comment Department");
/*
    set("long",
      "You are in a dark, musty room.  This is the official "
      "ShadowGate complaints department.  Post any gripes, questions, or comments "
      "you have that you wish for the wizards to address on the board.");
*/
   set_exits( 
      ([
     "up":"/d/shadowgate/adv_main",
//   "down":"/d/shadowgate/abyss"
     ]));
/*
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "comments board", "board" }) );
     ob->set_ooc_board(1);
    ob->set_board_id("ombud");
    ob->set_max_posts(30);
    ob->set_edit_ok( ({ "nialson" }) );
   ob->set_location("/d/shadowgate/ombud_hall");
   ob->set("short", "the ShadowGate Comment Board");
   ob->set("long", "People of this reality come here to post their "
	   "comments and questions for the immortals who control "
	   "the fate of all reality.\n");
  set_property("no castle", 1);
*/
}
init() {
	::init();
}

