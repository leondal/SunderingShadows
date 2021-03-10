#include <std.h>
#include <daemons.h>
inherit ROOM;

string query_time_of_day();

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_name("An old warehouse");
    set_short("%^RESET%^%^ORANGE%^An old warehouse%^RESET%^");
    set_long(""+query_short()+"\n%^RESET%^%^ORANGE%^This warehouse is much the same as the rest up and down the docks of Torm.  "
"Old and run-down, it seems not to have seen much use lately, and dust is settled all over the %^RESET%^crates%^ORANGE%^ and "
"boxes that crowd the area.  The %^RESET%^floors%^ORANGE%^ are also in need of replacement.  The wooden %^RESET%^walls%^ORANGE%^ are darkened with age, and damp from the sea air.%^RESET%^\n");
    set_smell("default","The thick, musty smell of the disused building tickles at your nose.");
    set_listen("default","You can hear the lap of the waves against the boardwalk outside.");

    set_exits(([
      "out" : "/d/dagger/Torm/city/c58",
      "south" : "/d/dagger/Torm/city/thieves/vethor_trophy"
    ]));
set_items(([
	"floors" : "They are old, wooden, and creak underfoot as you tread over them.",
	"walls" : "The walls are darkened from age, staining the wood.  The %^ORANGE%^southern wall%^RESET%^ has been strangely cleared of crates and boxes.",
	({"crates","boxes"}) : "Crates and boxes are scattered around the room, covered in a thick layer of dust.",
	({"south wall", "southern wall"}): "The south wall, unlike the rest, is completely bare of any obstructions and looks very plain.  There is something about it you can't quite put your finger on.",
]));

    add_invis_exit("south");
    add_pre_exit_function("south", "go_south");
    add_post_exit_function("south", "runes_light");

    set_search("default","Where do you want to search?");
    set_search("wall",(:TO,"search":));
    set_search("south wall",(:TO,"search":));
}

void init() {
  ::init();
  add_action("search","search");
}

int search (string str) {
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(str == "wall") {
    write("Search which wall?");
    return 1;
  }
  if(str != "south wall") {
    write("You search the "+str+" and find nothing.");
    return 1;
  }
  write("You search the wall and find a hidden passage to the south.\n");
  tell_room(ETP,TPQCN+" searches the south wall and finds a hidden passage.", TP);
  return 1;
}

int go_south() {
  write("You push the false wall aside and proceed south.");
  tell_room(ETP,TPQCN+" moves south through the false wall.", TP);
  return 1;
}

string query_time_of_day() {
	string str;
	str = EVENTS_D->query_time_of_day();
	return str;
}

void runes_light() {
	if(query_time_of_day() == "dawn" || query_time_of_day() == "twilight")
	write("%^BOLD%^The east wall is now covered with blazing orange and red runes!");
}
