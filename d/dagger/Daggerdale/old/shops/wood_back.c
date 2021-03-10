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
set_short("Woodwright's");
  set("long",
@SIA
%^ORANGE%^The workroom is very clean and organized.
The floors have been swept clean and tools are hanging on the north wall.
The east wall has large bins which hold the different types of woods needed
to make all types of furniture. Sturdy benches stand in the middle of the
room. One of them has the beginnings of a breadboard the apprentice
is attempting to create.  The south wall is strangely bare.
SIA
);
set_smell("default", "You smell sawdust and varnish.");
set_listen("default", "You hear the murmur of voices.");
set_items(([
	"floors" : "Not a speck of dust can be seen on the polished red oak.",
	"tools" : "They are organized in size and are very well cared for.",
	"bins" : "These are made from oak and hold wood waiting to be turned into masterpieces.",
	"wood" : "Red and black oak, pine and various other types.",
	"benches" : "Waist height, they are made from oak and various tools lie "
		"neatly on the worn surface.",
	"breadboard" : "Octagonal shaped, it will be a fine breadboard, worthy of "
		"any kitchen.",
	({"south wall", "southern wall", "wall"}): "The south wall, unlike the rest, "
		"is completely bare of any obstructions and looks very plain.  There is "
		"something about it you can't quite put your finger on.",
]));

  set_exits(([
	"out" : "/d/dagger/Daggerdale/shops/woodwright",
	"stairs" : "/d/dagger/Daggerdale/shops/wood_apprent",
//        "south" : "/d/dagger/Daggerdale/shops/vethor_trophy"
  ]));
//  add_invis_exit("south");
//  add_pre_exit_function("south", "go_south");
//  add_post_exit_function("south", "runes_light");
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
  write("You search the wall and find only the remains of a few scratches there.\n");
  tell_room(ETP,TPQCN+" searches the south wall.", TP);
//  write("You search the wall and find a hidden passage to the south.\n");
//  tell_room(ETP,TPQCN+" searches the south wall and finds a hidden passage.", TP);
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
