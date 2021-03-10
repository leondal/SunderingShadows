#include <std.h>
inherit CROOM;

void create(){
    set_monsters( ({"/d/shadow/room/mountain/mons/worker",
"/d/shadow/room/mountain/mons/dwarf"}), ({2,1}) );
    ::create();
   set_repop(50);
   set_terrain(NAT_TUNNEL);
   set_travel(DIRT_ROAD);
    set_property("light" , 0);
    set_property("indoors" , 1);
    set_short("Inside Echoes Mountains");
    set_long(
@GRAYHAWK
%^YELLOW%^Inside Echoes Mountains
%^RESET%^You're moving deeper in a cave somewhere in Echoes Mountains.  The
cave walls are naturally carved.  From here, the tunnel turns sharply to the 
north and seems to begin to rise steadily.
GRAYHAWK
    );
    set_items(([
        "walls" : "The walls look naturally carved.",
        "cave":"Darkness, total and complete."
        ]));
 
    set_exits(([
        "east" : "/d/shadow/room/mountain/cave18",
        "north" : "d/shadow/room/kildare/rooms/cave1.c"
        ]));
   set_listen("default","You hear the reverberance of echoes throughout the
caves.");

}

void reset() {
  ::reset();
/* changing to use CROOM for control of wandering mobs over longer reboots
*Styx* 11/29/02
  if(!present("mountain dwarf")) {
    new("/d/shadow/room/mountain/mons/worker")->move(TO);
    new("/d/shadow/room/mountain/mons/worker")->move(TO);
  }
  if(!present("guard")) {
   if(sizeof(children("/d/shadow/room/mountain/mons/dwarf")) < 10) 
    new("/d/shadow/room/mountain/mons/dwarf")->move(TO);
  }
*/
}
