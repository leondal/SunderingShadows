// Imperial Headquarters, Shadow
// Thorn@ShadowGate
// 000602
// City of Shadow - Invasion 2000
// hq1.c

#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit VAULT;

void create() {
	::create();
// making no teleport because I don't think it's even in game *Styx* 12/24/03
    set_property("no teleport", 1);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("Imperial Headquarters, Shadow");
  	set_long(
@SHADOW
%^BOLD%^CYAN%^Inside Imperial Headquarters, Shadow%^RESET%^
  You are in the Headquarters building of the Tsarvani Imperial
Government in Shadow.  The building is small, but functional.  
Messages for the Military Governor can left on the board in this
anteroom.  
  There is a flight of stairs to the second level of the building
with a door at the top.  
  The exit to Garrison Road is out.
  
SHADOW
    );
    set_exits(([
			"out" : "/d/shadow/room/main/garrison5",
//			"up" : "/d/shadow/room/main/hq2"
// the hq2 file doesn't even exist in th
  	] ));
  	set_listen("default","You hear the sounds of the city outside.");
//	set_door("door","/d/shadow/room/main/hq2","up",0);
//    set_open("door",0);
//    set_locked("door",0);
}

void reset(){
	::reset();
    if(!present("trooper")) {
    	new("/d/azha/mon/itrooper")->move(TO);
	}
    if(!present("trooper 2")) {
    	new("/d/azha/mon/itrooper")->move(TO);
	}
}
