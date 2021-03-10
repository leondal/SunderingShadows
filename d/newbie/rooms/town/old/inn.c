#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("indoors",1);
	set_short("The Ironwood Inn");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_long(
   "You are standing in the Ironwood Inn, just off the center square of Offestry."+
   " It is a quiet little place with tables scattered about the common room and a"+
" few patrons chatting about old times as they eat and drink."+
   " At the back of the room are"+
	" stairs leading up to the guest rooms. Most of the inn seems to be made"+
	" out of a hard, dark wood known as ironwood, which is obviously how this"+
   " place got its name. You can type %^BOLD%^help hotel%^RESET%^ for a list of commands."
	);
   set_listen("default","You can hear the snores of the resting adventurers.");
  set_smell("default","You can smell the clean linen sheets.");
	set_property("light",2);
	set_items(([
	({"chairs","chair","table","tables"}) : "There're several chairs and tables"+
	" scattered about the room. Some of them are occupied, but there are still"+
	" a couple that are empty if you would like a seat.",
	"floor" : "The floor of the inn is made of hard ironwood, but it has still"+
	" sustained several scuff marks that simply wouldn't rub out. It is kept"+
	" fairly clean, but the dust from travellers has been tracked in.",
	]));
	set_exits(([
	"north" : MAINTOWN"estreet1",
            "west":MAINTOWN"sstreet1",
	]));
/*   set_rooms(([
   "singleroom":1,
   "doubleroom":2,
   "queensroom":3,
   "kingsroom":4,
   "suite":5,
   "bunks":6,
   ]));
   set_cost(10); */
}

void init()
{
	::init();
	add_action("read_menu","read");
}

void read_menu(string str)
{
	if(str == "menu") {
		tell_room(ETP,""+TP->query_cap_name()+" reads over the menu.",TP);
		tell_object(TP,"There does not appear to be anything on the menu right now.");
		return 1;
	}
}
