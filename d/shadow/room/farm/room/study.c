#include <std.h>
#include "../farm.h"
inherit ROOM;

void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Study");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Study");
   	set_long("%^CYAN%^A %^RED%^brick %^CYAN%^fireplace "+
		"gives a warm cozy feeling to this section of the"+
		" home.  Logs of wood are piled sloppily in a small"+
		" metal %^RESET%^crate%^CYAN%^ next to the "+
		"fireplace.  Above the crate an iron hook is poised"+
		" ready to grab and log and dump it into the fireplace"+
		", in a fashion only a gnome could create.  A ratty "+
		"tattered %^BOLD%^%^BLUE%^p%^RED%^l%^YELLOW%^a%^RED%^i%^BLUE%^"+
		"d%^RESET%^%^CYAN%^ chair rests in front of the fireplace."+
		"  Tossed over the arm of the chair is a %^ORANGE%^earthen"+
		" colored %^CYAN%^wool blanket.  Stacks of books are "+
		"scattered about the chair, some with empty tea cups "+
		"resting on them. A squirrel shaped window rests off"+
		" to the side of the chimney.%^RESET%^\n");
	set_smell("default","A woody smokey scent hangs in the air");
   	set_listen("default","The sound of gears turning can be heard.");
  	set_items(([
      	({"chair","blanket"}) : "%^YELLOW%^The ratty chair looks "+
			"like it has seen better days. The cushion of the "+
			"chair sags in the center, showing that someone has"+
			" spent many hours sitting here.  Tossed over the arm"+
			" of the chair is a worn earthen colored wool blanket.",
      	({"fireplace","crate","crane","wood"}) : "%^RED%^Built into "+
			"the wall is the red brick fireplace and chimney.  The"+
			" fireplace is thick with soot right now.  A metal box"+
			" rests near the fireplace with various logs of wood "+
			"tossed in.  Above the crate an iron crane stands ready"+
			" to grab an log and deposit it in the fireplace.  The "+
			"crane is connected to a mechanical apparatus featuring"+
			" gears, glowing crystals and glass tubes.  The design "+
			"of it just screams Gnome.",
		({"books","book","teacup","pile"}) : "%^BLUE%^Stacks of books"+
			" crowd the plaid sofa, looking to be in various states"+
			" of reading.  Subjects ranging from academic to just"+
			" plain silly (to someone who is not a gnome at least) "+
			"can be found here.  Four tea stained teacups rests on "+
			"some of the stacks."
		]));
		set_exits(([ "southeast" : ROOMDIR"foyer",
				 "northeast" : ROOMDIR"bedroom"
		 ]));

}