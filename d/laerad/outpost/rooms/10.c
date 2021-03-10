#include <std.h>
#include "../outpost.h"

inherit STORAGE"road";

void create(){
   ::create();
   set_exits(([
      //"southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  //"south" : ROOM"9",
	  "west" : ROOMS"11",
	  "east" : ROOMS"9",
   ]));

}