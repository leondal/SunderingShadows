inherit "/std/room";

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The LPC and MudOS Room");
    set("long",
	"Immortals come here to discuss coding problems.  "
	"The Hall of Immortals is north of here.");
    set_exits( 
	      (["north" : "/d/standard/adv_inner"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "irreality board" }) );
    ob->set_board_id("coding");
    ob->set_max_posts(20);
    ob->set_location("/d/standard/lpc_inner");
    ob->set("short", "the LPC and MudOS Irreality Board");
    ob->set("long", "Post your questions about coding here.\n");
}

