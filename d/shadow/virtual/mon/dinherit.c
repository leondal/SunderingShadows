//dinherit.c

#include <std.h>

inherit ROOM;


void create(){
   ::create();
   set_property("no teleport",1);

}

void reset(){
   int i,j;
   object ob;
   ::reset();

   if(present("small thing")) return;
   if(!random(15)){
      i = random(7)-2;
      for(j=0;j<i;j++){
	ob = new("/d/shadow/virtual/mon/smallu");
	ob->move(TO);
	ob->set_speed(20);

      }
   }
}

void init(){
   ::init();

   if((int)TP->query_size() == 3){
      write("You simply don't fit in there!");
      TP->move(TP->query_last_location());
   }
   if((int)TP->query_size() == 2){
      write("You knock your head on the ceiling here.");
      tell_room(TO,TPQCN+" knocks his head on the ceiling.",TP);
      TP->do_damage("torso",roll_dice(1,4));
   }
}
