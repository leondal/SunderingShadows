//forest34.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit base room for near the paths
object ob;

void create(){
	::create(); 
	set_exits(([
       "northeast":ROAD"efroad4",
       "west":FOREST"forest33",
       "northwest":FOREST"forest25",
   ]));
   ob = new("/d/newbie/obj/misc/1sign.c");
   ob->set_file("/d/newbie/obj/misc/sign4.txt");
   ob->move(TO);
}
