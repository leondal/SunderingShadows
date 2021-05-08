//Octothorpe (6/2/16)
//Shadow, Melistel Avenue F

//Added street light -- Yves 6/29/19

#include <std.h>
#include "../defs.h"

//inherit INH+"melistel";
inherit VAULT;

void create(){
   ::create();
    set_property("indoors", 0);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_short("%^RESET%^%^CYAN%^Melistel Avenue, Shadow%^RESET%^");
    set_long((INH+"melistel")->query_long()+"The ancient %^BOLD%^Puente Zincharo "+
      "%^RESET%^crosses over the %^BOLD%^%^BLUE%^Sarcosta River "+
      "%^RESET%^to the north. To the east a large tower houses the "+
      "%^RESET%^%^CYAN%^Library of the Consortium%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"melistele",
      "south" : ROOMS"southcross",
      "east" : "/d/guilds/consortium/hall/library",
   ]));
   set_door("door","/d/guilds/consortium/hall/library","east","library key");
   set_open("door",0);
   set_locked("door",0);
   "/d/guilds/consortium/hall/library"->set_open("door",0);
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
   new("/d/common/obj/misc/street_light")->move(TO);
}
