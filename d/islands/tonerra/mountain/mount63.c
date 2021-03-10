#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_short("Side of the volcano");
   set_long(
@DESC
   This is a weathered old wooden stand on. From here you can see
straight down into the mouth of the volcano. A small chair scarred
with long scrapes and tears sits in the middle of the balcony.
This must be where the natives send "volunteers" to be sacrificed
to the god of the volcano. What could possibly answer such an
offer? The chair stands empty, you see it full of the brave who
would die to protect from what?
DESC
   );
   set_light(2);
   set_indoors(0);
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_listen("default","The slight breeze stirs the small plants.");
   set_smell("default","The land has a charred smell about it.");
   set_items((["chair":"This chair looks like a sacraficial seat. The chair is meant to be sat it in."]));
   set_exits(([
      "northeast":MOUNTAIN+"mount62",
      "down":MOUNTAIN+"dhome"
   ]));
   set_pre_exit_functions(({"down"}),({"GoThroughDoor"}));
}

void init(){
   ::init();

   add_action("sit","sit");
}

int sit(string str){
   object ob;

   if(!str) return 0;
   if(str != "chair" && str != "in chair" && str != "on chair") return 0;


   write("You sit in the chair.");
   tell_room(TO,TPQCN+" sits in the chair.",TP);
   write("%^BOLD%^%^CYAN%^Someone whispers to you%^RESET%^: Thank you brave soul.");

   call_out("sac",2,TP);
   return 1;
}

void sac(object ob){
   object obj;
   if(obj = present("dragon",find_object_or_load(MOUNTAIN+"dhome"))){

      tell_room(TO,"%^GREEN%^With a scream of fury a great dragon streaks from the mouth of the volcano and attacks.");
      obj->move(TO);
      obj->kill_ob(ob,1);
   }

}

int GoThroughDoor(){
   write("That is much to steep for you.");
   return 0;
}
