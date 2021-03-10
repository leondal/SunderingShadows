/*Removing Xeryl and obsidian gem from the game due to its unoriginal copypasta - Octothorpe 1/26/17*/

#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "south":MTS+"room96",

      //"down":"/d/undead/rooms/xerylhome.c"
   ]));
  // set_pre_exit_functions(({"down"}),({"GoThroughDoor"}));
}

/*void init(){
   ::init();

   add_action("challenge","challenge");
}
int challenge(string str){
   object ob;
   if(!str) return 0;
   if(str != "xeryl" && str != "dragon" && str != "obsidian dragon") return 0;


   write("You issue your challenge.");
   tell_room(TO,TPQCN+" yells a challenge down to the dragon.",TP);
   write("Someone whispers to you: Are you sure?.");

   call_out("sac",2,TP);
   return 1;
}
void sac(object ob){
   object obj;
   if(obj = present("dragon",find_object_or_load("d/undead/rooms/xerylhome.c"))){

      tell_room(TO,"With a scream of fury a great dragon streaks up from below and attacks!");
      obj->move(TO);
      obj->kill_ob(ob,1);
   }


}

int GoThroughDoor(){
   write("That is much to steep for you.");
   return 0;
}*/