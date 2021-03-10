inherit "/std/room";

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Planning Room");
    set("long", (: this_object(), "go_away" :));
    set_exits( 
	      (["west" : "/d/standard/adv_inner",
  "east" : "project",
		"up" : "/d/standard/arch"]) );
    set_invis_exits( ({ "up" }) );
    set_pre_exit_functions( ({ "up" }), ({ "do_check" }) );
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "planning board" }) );
    ob->set_board_id("planning");
    ob->set_max_posts(30);
    ob->set_location("/d/standard/planning_room");
    ob->set("short", "the Planning Our Reality Board");
    ob->set("long", "A board for posting ideas so that others "
	    "will not use them.\n");
}

int do_check() { return archp(this_player()); }

string go_away() {
    string str;

    if(archp(this_player())) str = "The arch meeting room is upstairs. ";
    else str = "";
    str += "This is where you post ideas for our MUD.";
    return str;
}

