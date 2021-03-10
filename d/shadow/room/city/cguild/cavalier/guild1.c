#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_light(2);
    set_property("indoors",1);
//set_property("no teleport", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_id("tack room");
	set_short("Tack Room");
	set_long(
@RIDERS
%^CYAN%^%^BOLD%^The Tack Room%^RESET%^
This room is where all the tack is stored.  You notice rows of
pegs on one side of the room.  From each peg hangs a bridle.
On the other side of the room you notice a wall full of saddles,
each saddle is resting on a rounded length of wood sticking out
of the wall.  All around the room there are trunks that you
figure must contain the various brushes and medicines that belong
to the owners of some of the horses.  The walls are all finished
with wood paneling, and the floor is cleanly swept.
RIDERS
	);
	set_exits(([
		"out": "/d/shadow/city/room/stable",
		"door" : "/d/shadow/room/city/cguild/cavalier/enter1",
	]));
	add_invis_exit("door");
	set_items(([
       "bridles":"The bridles are all various sizes and styles.  Over each bridle is a sign with the name of a horse.",
       "saddles":"The saddles are all neatly stored on the racks.  You see english, western, and an occasional australian saddle.",
       "trunks":"Each trunk has the owners name written on the front. You suspect that only the owner has the key to each trunk.",
       "walls":"The walls are made up of interlocking wood panels.  There appears to be a door in one wall that you could enter.",
       "wall" : "Perhaps you can knock and open the door.",
       "door":"This looks like a secret door you could enter even though there is no doorknob."
    ]));
   set_smell("default","You smell clean leather and saddle soap.");
   set_listen("default","You hear the occasional sound from out in the aisle.");
   set_search("default","One wall catches your attention.");
	set_search("wall","You notice a section of paneling that looks like it might open like a door.");
}

void reset() {
   ::reset();
 	add_invis_exit("door");
}

void init(){
  ::init();
  add_action("go_enter","open");
  add_action("go_enter","knock");
}

int go_enter(string str) {
  if(!str) notify_fail("Open or knock what?\n");
  if(str!="door" && str != "wall") return 0;
      write("%^BLUE%^You rap on a section of the paneling and it opens a door!");
      tell_room(ETP,"%^GREEN%^You see "+TPQCN+" knock "
        "on a section of the wall and open a door.",TP);
      remove_invis_exit("door");
      return 1;
}
