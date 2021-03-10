#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"common_ground.c";

void create(){
   ::create();
   set_exits(([
      "east":ROOMS"36",
	  "west" : ROOMS"38",
      //"north" : ROOMS"26",
	  //"south" : ROOMS"25"
   ]));

}

void reset(){
	::reset();
	if(!present("khamvani")){
		new(MOBS"wemic")->move(TO);
		}
}