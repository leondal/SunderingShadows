inherit "/std/room";

void init() {
  ::init();
    if(!archp(this_player()))
      this_player()->move_player("/d/standard/planning_room", "down");
}

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Arch's Room");
    set("long",
	"This is where the arches decide the fate of Nightmare.");
    set_exits( 
	      (["down" : "/d/standard/planning_room"]) );

    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board" }) );
    ob->set_board_id("arch");
    ob->set_max_posts(20);
    ob->set_location("/d/standard/arch");
    ob->set("short", "the Arch Immortal's Board");
    ob->set("long", "A board for utter nonsense.\n");
}


