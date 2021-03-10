#include <std.h>
#include <rooms.h>

#include "/d/stella/short.h"

inherit ROOM; 

void reset(){
        ::reset();
        if (!present("mundanoid")) new(MPATH "mund_nw.c")->move(TO);
        }

void create() {
	::create(); 

	set_light(1);
	set_indoors(1);
	set_no_steal(1);
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_short("The Planetarium");
	set_long(
		 "You find yourself in a large, dark dome shaped room.  There "
		 "are a variety of sofas and comfy chairs scattered around the "
		 "room.  In the center of the room, there is a sophisticated "
		 "projection system which is the only source of illumination. "
		 "As your eyes adjust to the dark, you realize that the walls "
		 "and ceiling are covered in a breathtaking simulation of the "
		 "night sky.  You can see stars, galaxies, and the occasional "
		 "meteorite."
	     );

	set_smell("default", "You smell a faint hint of vanilla.");
	set_listen("default", "You can hear some soft music in the background.");

	set_items(([
	  "projector": "This is a sophisticated projection device which projects "
		    "a representation of the night sky into the dome-shaped room.",
          "stars": "The stars are so realistic, they appear to twinkle.  After "
		    "watching the stars for a while, you think you might almost "
		    "recognize some constellations!",
	  "constellations":"That's strange, as you focus on a prominent constellation "
		    "you think you can see faint white lines connecting the stars.",
	  ({"lines", "line", "white line"}): "You focus on the lines, and one seems "
		    "to grow and become wider.  You feel almost as if you could follow "
		    "it!",
	  "galaxies": "You can see many small galaxies, and the long faint star "
		    "cloud formed by looking at our galaxy edge on.",
	  "meteorite": "You occasionally see a shooting star streak accross the sky."
	]));

	set_exits(([
		    "north": RPATH "court3"
	]));
}

	
void init() {
	:: init();
	add_action("follow_line", "follow");
}

int follow_line(string str) {
	string where;

	if (!str) {
	  notify_fail("Follow what?\n");
	  return 0; }

	if (str=="line") {
	  if (present("mundanoid",ETP)){
	    say("The Mundanoid prevents "+TPQCN+" from following a white line!\n",TP);
	    tell_object(TP,"The mundanoid prevents you from following the line!\n");
	  } else {
	    say(TPQCN +" walks off into the darkness following a white line!\n",TP);
	    tell_object(TP,"You follow the line and find yourself in another place!\n");
	    TP->move_player( MAZEPATH "peg1.c");
	  }
	}
	return 1;
}
