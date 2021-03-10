#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light" , 1);
  set_property("indoors" , 1);
  set_short("The d'Arcy Family Crypt");
  set_long(
@DARKWOOD
%^BOLD%^The d'Arcy Family Crypt%^RESET%^ 
  You have entered the d'Arcy Family crypt.  The ancestors of
the Marquis d'Arcy lay in coffins that are in turn laid in niches in
the walls.  In the middle of the room is a sarcopagus with a lid of
heavy stone on top of it that looks like it needed 20 men to manuver
into place.  As you might expect, the quarters are cramped and the
air is musty. But lest you forget you you are, there also is a
building fear inside you about standing in a home of the dead.

DARKWOOD
);
  set_smell("default","This place smells of old rot and decay.");
  set_listen("default","It is so quiet, you could hear the sounds of the dead stirring.");
  set_exits(([
    "north"  :  ROOMDIR+"cgate"
  ]));
  set_items( ([ 
  	"coffins": "Large iron caskets with the remains of the dead.", 
  	"niches": "The indentations in the thick walls each hold one iron coffin.", 
  	"sarcopagus": "This stone tomb is a prominently located in the center of the crypt.", 
  	"lid": "The stone lid of this tomb looks to weigh nearly a ton.  "+
  	"There is an inscription on it.", 
  	"inscription": "It reads: \nKryyyshk, Elder of Shadow, \n"+
  	"'Darkness and Death lie below me forever.'" 
  ]) );
  set_pre_exit_functions( ({"down" }), ({"go_down"}) );
}

void init(){
  ::init();
  
  add_action("lift", "lift");	
  do_random_encounters(({ MONDIR+"cmerc" }),70,2);
  do_random_encounters(({ MONDIR+"cmerc" }),30,1);
  do_random_encounters(({ MONDIR+"cmerc" }),30,1);
}


int go_down() 
{
	if(!present("knights blade", TP)) 
		return notify_fail("This is not your quest, "+TP->query_cap_name()+".\n");
	return write("You descend into the passage inside the sarcopagus "+
	"to meet your destiny.  Good luck, "+TP->query_cap_name()+".\n");
}

int lift(string str)
{
	if(str != "lid") return 0;
	if(!present("knights blade", TP)) 
		return write("This is not your quest, "+TP->query_cap_name()+".\n");
	write("You lift the lid with unbelievable ease, revealing a secret stair inside!");
	add_exit(ROOMDIR+"secret1", "down");
	return 1;
}

