#include "../../newbie.h"
inherit INH"townmove.c";

object ob;

void create() {
   ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
   set_name("South Crossroads in Offestry");
   set_short("South Crossroads in Offestry");
   set_long(
@NEWBIE
You are at the crossroads of the South Street of the city and the street 
that marks the south border. A wooden palisade runs along this street. 
You see many people, both citizens and travelers, walking and riding to
their destinations. 
NEWBIE
   );
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "buildings":"The buildings are a jumble of style and types. They hold the citizens, businesses and adventure of this small city.",
      "palisade":"The palisade stands around 12 feet high, surrounding the city. You notice a few archers and guardsman patrolling.",
   ]));
   set_exits(([
      "north":MAINTOWN"sstreet2",
      "east":MAINTOWN"eroad6",
      "west":MAINTOWN"wroad6",
   ]));
/*
   ob->set_board_id("main_board");
   ob->set("short", "The ShadowGate Reality Board");
   ob->set("long", "An old cork board where the adventurers who pass "
     "through ShadowGate post and get information on the reality they have "
     "discovered.  Note:  This board is strictly ooc.  Several copies "
     "exist around the realms since it often carries very important news.\n");
   ob->set_max_posts(50);
   ob->set_ooc_board(1);
   ob->set_location("/d/newbie/rooms/town/sstreet3");
*/
   ob = new("/d/newbie/obj/misc/1sign.c");
   ob->set_file("/d/newbie/obj/misc/sign1.txt");
   ob->move(TO);
}
void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
