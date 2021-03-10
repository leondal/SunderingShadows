//forest30.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest
object ob;

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest22",
       "northeast":FOREST"forest23",
       "east":FOREST"forest31",
       "southeast":FOREST"forest41",
       "south":FOREST"forest40",
       "southwest":FOREST"forest39",
       "west":FOREST"forest29",
       "northwest":FOREST"forest21",
   ]));
   ob = new("/d/newbie/obj/misc/1sign.c");
   ob->set_file("/d/newbie/obj/misc/sign6.txt");
   ob->move(TO);
}
