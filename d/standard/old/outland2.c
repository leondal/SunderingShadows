inherit "std/room";

void create() {
  ::create();
    set_property("light", 2);
    set("short", "The outlands");
    set("long",
	"This small trails leads through a section of the jungle "
	"called the Outlands.  Only roguish types dare feel safe "
	"in these parts.");
    set_items(
	(["jungle" : "This is its heart.  Only the brave and the "
	    "stupid venture here.",
	  "trail" : "It snakes through the soul of the Outlands."]) );
    set_exits( 
	      (["southeast" : "/d/standard/outlands/fork",
		"northwest" : "/d/standard/outland1"]) );
    set_pre_exit_functions(
	({ "southeast"}), ({ "go_southeast" }) );
}

void reset() {
  ::reset();
    // if(!present("outlaw")) 
    //  new("/d/standard/obj/mon/outlaw")->move(this_object());
}

int go_southeast() {
  if(!present("outlaw")) return 1;
  if((string)this_player()->query_class() != "child" && 
     (string)this_player()->query_class() != "rogue") {
    write("The outlaw spits on you and slams you to the ground!");
    this_player()->add_hp(-(random(7)));
    return 0;
  }
  if((int)this_player()->query_alignment() > 100) {
    write("The outlaw sneers at you.\nHe says: You are such a loser.");
    say(this_player()->query_cap_name()+" is mocked by the outlaw "
	"for being a poor rogue.");
    return 0;
  }
  return 1;
}

