inherit "std/room";

void create() {
   object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Complaint Department");
    set("long",
      "You are in a dark, musty room.  This is the official "
      "Nightmare complaints department.  Post any gripes, questions, or comments "
      "you have that you wish for the wizards to address on the board.");
   set_exits( 
	     (["up" : "/d/standard/adv_main"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "comments board", "board" }) );
    ob->set_board_id("ombud");
    ob->set_max_posts(30);
    ob->set_edit_ok( ({ "nialson" }) );
   ob->set_location("/d/standard/ombud_hall");
   ob->set("short", "the Nightmare Comment Board");
   ob->set("long", "People of this reality come here to post their "
	   "comments and questions for the immortals who control "
	   "the fate of all reality.\n");
  set_property("no steal", 1);
  set_property("no attack", 1);
  set_property("no castle", 1);
}

