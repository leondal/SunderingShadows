//forest31.c

#include "../../newbie.h"

inherit FOREST"inherit/forestberries";
//inherit the base room for the main forest w/berries
object ob;

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest23",
       "northeast":FOREST"forest24",
       "east":FOREST"forest32",
       "southeast":FOREST"forest42",
       "south":FOREST"forest41",
       "southwest":FOREST"forest40",
       "west":FOREST"forest30",
       "northwest":FOREST"forest22",
   ]));
   ob = new("/d/newbie/obj/misc/1sign.c");
   ob->set_file("/d/newbie/obj/misc/sign5.txt");
   ob->move(TO);
}
