
#include "../outpost.h"
#include <std.h>
#include <money.h>
#include <move.h>

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Outpost healer");
    set_long("Torm Outpost healing clinic\n"+
    "%^BOLD%^%^WHITE%^This is still a rough house where many of the inside walls still only consist of rough wooden boards. The walls "+
	"are full of shelves with countless of vials, bottles and various herbs. In the end of the room a large table. serving both as counter "+
	"and as operation table are places and right behind it is the owner of the clinic%^RESET%^.\n");
    set_smell("default","The clinic smells of astringents and herbs.");
    set_listen("default","You can hear the groans of some of the patients.");
    set_exits( ([
        "south" : ROOMS"11"
    ] ));
    set_name("Clinic");
}

void reset(){
  ::reset();
  if(!present("healer")){
  new(MOBS"healer")->move(TO);
  }
}