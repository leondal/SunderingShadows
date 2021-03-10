#include <std.h>
#include "/d/darkwood/darcy/darcy.h"

int warning;

inherit ROOM;

void init() {
    ::init();
    add_action("scramble","scramble");
    add_action("rush","scramble");
}

void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("%^BLUE%^A Cavern Under the Chateau%^RESET%^");
    set_long(
@DARKWOOD
%^BLUE%^BOLD%^A Cavern Under the Chateau%^RESET%^
  Even in the tiny amount of light that has penetrated into this
room, you can still see very little.  You now realize that the 
darkness of this room is not completely a lack of light, but rather
a yawning pit that sits in the middle of the cave, leaving precious 
little stable room to walk around the edge.

  Looking at the pit, you see a bridge over the pit with a short
platform in the center of the pit.  You somehow realize, without
having ever seen this room in your life, that this is where 
sacrifices are sent to some power that dwells in the depths.

DARKWOOD
    );
    set_listen("default",
        "You hear the sound of rushing air through the gloom."
    );
    set_smell("default",
        "There is a subtle hint of rot and decay in this room."
    );
    set_items(([
        "pit":"The pit in front of you is wide, dark, and probably "
        "bottomless.",
        "bridge":"The bridge is made of blackened iron and lead "
        "with no railings to prevent an accidental fall in the pit.",
        "railing":"Wishful thinking, no railing anywhere here.",
        "platform":"A wider section of the bridge that juts out into "
        "the middle of the pit.",
    ]));
    set_exits(([
        "south": ROOMDIR+"cav0"
    ]));
    warning = 0;
}

int scramble() 
{
	if(!warning && present("knight sword", TP)) {
		write("You get the idea that it would not be such a good idea"+
		      " to do that here.");
		warning = 1;
		return 1;
	}
	else if((random(20) - 4) < 1) {
		write("As you complete your manuver, you realize that there is no "+
		      "ground below your feet.  You are falling, helplessly into a "+
		      "pit.");
		TP->move_player("/d/tharis/barrow/rooms/pit.c");
		return 1;
	}
	else return 0;
}

void reset() 
{
    ::reset();
    
    warning = 0;
    if(!present("malgoroth")) {
        if(random(10) < 8) new(MONDIR+"malgoroth")->move(TO);
    }
}

