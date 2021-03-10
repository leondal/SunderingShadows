//minor update by ~Circe~ 5/8/08 - this room had no reset, so the 
//priest spawned only once per boot.  With longer reboots, a lot of 
//people can get stuck in the underdark

#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
   set_property("light",1);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_name("Room of the well");
   set_short("%^BLUE%^Room of the well%^RESET%^");
   set_long(
	"%^BOLD%^%^CYAN%^This room is completly bare of any furnishings "
	"or decorations. The only object in the room is a well located "
	"directly in the center of the floor. Faint wisps of smoke "
	"rise out of the well.%^RESET%^"
    );
    set_listen("default","It is dead silent here.");
    set_smell("default","The room is void of all smells.");
    set_items(([
	"floor":"There is a well in the floor.",
	"smoke":"Faint wisps of smoke float in the well's opening and slowly "
	"spill out onto the floor.",
	"well":"%^CYAN%^You cannot see what is within the well because of the "
   "smoke filling its opening.%^RESET%^"
    ]));
    set_exits(([
    	"down":"/d/dagger/drow/rooms/tower4"
    ]));
//    new("/d/tharis/barrow/mon/priest")->move(TO); moving this to reset
}

void reset(){
   ::reset();
   if(!present("drow priest")){
      new("/d/tharis/barrow/mon/priest")->move(TO);
   }
}

void init() {
    ::init();
    add_action("enter_well","enter");
}

int enter_well(string str) {
   if(str !="well") {
      notify_fail("Enter what?");
      return 0;
   }
   tell_object(TP,"%^CYAN%^You try to enter the well, but the smoke "
      "pushes you back!%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TPQCN+" attempts to enter the well, but "
      "the smoke prevents "+TPQO+" from doing so.%^RESET%^",TP);
   return 1;
}
