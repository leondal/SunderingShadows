//ZAKNAIFEN'S REPLACEMENT FOR d/standard/sewer
//To Allow access to Zaknaifen's sewer area.  10/4/93

inherit "std/vault";

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_door("grate", "/realms/zaknaifen/sewer/rooms/room3.c",
              "east", "obsidian key");
    set_open("grate", 0);
    set_locked("grate", 0);
    set("short", "A disgusting sewer");
    set("long",
	"These sewers under Praxis are filled with slime. "
	"A grate is set in the east wall, near the ceiling. ");
    set_items(
	(["sewers" : "The disgusting tunnels of human waste under Praxis.",
	  "slime" : "Nasty, nasty.",
	  ({"wall", "east wall"}) : "A disgusting slime-coated wall.",
	  "ceiling" : "A disgusting slime-coated ceiling.",
	  "grate" : (: this_object(), "look_at_grate" :) ]) );
      set_exits(
	      (["west" : "/d/standard/sewer_ent", 
		"east" : "/realms/zaknaifen/sewer/rooms/room3"]) );
      set_invis_exits( ({"east"}) );
      set_pre_exit_functions( ({"east"}), ({"go_east"}) );
}
void look_at_grate() {
  if(query_open("grate"))
    write("The grate is old and rusty. It is set far up on "
	  "the east wall. The grate is open."); 
  else write("The grate is old and rusty. It is set far up on "
	     "the east wall and looks as if it will open easily. "
	     "The grate is closed."); 
}

int go_east() {
  string abe;
  abe=this_player()->query_race();
  if(abe=="kender" || abe=="halfling" || abe=="hobbit" || abe=="gnome" ||
     abe=="faerie" || abe=="rat" || abe=="goblin") {
    if(query_open("grate")) {
    write("You climb the wall and squeeze through the grate.\n");
    say(this_player()->query_cap_name()+" climbs the wall and "
	"enters the grate.");
    return 1;
  }
    write("You climb the wall and bump your head against the grate.\n");
    say(this_player()->query_cap_name()+" climbs the wall and bumps "+
     possessive(this_player())+" head on the grate.");
   return 0;
  }
   write("You try to squeeze through the small opening and get stuck!"
	 "Luckily you manage to pull yourself out.");
    message("other_action", sprintf("%s gets stuck in a grate.  Luckily "
      "%s manages to pull free.", (string)this_player()->query_cap_name(),
      nominative(this_player())),environment(this_player()),({this_player()}));
    return 0;
}
