//updated by Circe 6/2/04 with color, etc.
// Greene Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// greene2.c
// added jail cell stuff *Styx* 10/05

#include <std.h>
#include "../include/tabor.h"

inherit VAULT;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Greene Street, Tabor");
  set_short("Greene Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Greene Street, Tabor%^RESET%^
You are standing outside the %^BOLD%^%^BLACK%^Tabor Gaol %^RESET%^on %^GREEN%^Greene Street%^RESET%^. The %^BOLD%^%^BLACK%^prison %^RESET%^is
a squat, ugly looking building that looks like it needs a serious
cleaning.  Heavy %^BOLD%^%^BLACK%^iron bars %^RESET%^cover the few windows in the walls and you
can see some people looking out of the basement cells at the people
passing by. 

%^GREEN%^Greene Street %^RESET%^continues to the north and southeast.
The main entrance to the %^BOLD%^%^BLACK%^Gaol %^RESET%^is to the west.
TABOR
    );
  set_exits(([
    "west" : ROOMDIR+"jail",
    "southeast" : ROOMDIR+"greene1",
    "north" : ROOMDIR+"greene3",
    "window" : ROOMDIR+"jail_cell"
  ]));
   set_invis_exits(({ "window"}));
   set_pre_exit_functions(({ "window"}),({"GoThroughDoor"}));
  set_listen("default","You hear the muffled sounds of a busy town all around you.");
  set_smell("default","You pick up the great stench of the unwashed bodies to the west.");
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

void init() {
   ::init();
   add_action("peer_in", "peer");
   if(userp(TP) && !random(15))
	tell_object(TP, "You catch a glimpse of movement at the %^BOLD%^"
	  "%^BLACK%^iron-barred window%^RESET%^ of the jail cell.  Perhaps "
	  "you want to peer in to see who is in custody.");
}

int peer_in(string str) {
   string where = "/d/darkwood/tabor/room/jail_cell";
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "window" || str == "through window" || str == "in window" || str == "cell") {
      	tell_object(TP,"You step up to the window and peer "+
               "into the cell.\n");
      	tell_room(ETP,TPQCN+" steps up to the window and "+
               "peers into the jail cell.\n",TP);
      	tell_room(where,"%^BOLD%^You hear a scratching at the %^BLACK%^jail "
	       "window %^WHITE%^and catch a glimpse of movement outside.\n",TP);
	write(where->query_long());
      	TP->force_me("peer window 1");
    		return 1;
   }
   return 0;
}

int GoThroughDoor() {
   if(query_verb() == "window") {  
     write("%^ORANGE%^Why would you want to go in??? Even if you did truly want "
	"to, the window has heavy bars!");
     tell_room(ETP, TPQCN+" seems to be trying to get into the cell through the window!",TP);
     return 0;
   }
//need to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}