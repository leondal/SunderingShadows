#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel rises slightly to the "+
      "northeast and continues straight west from here.\n");
   add_item("crack","Upon closer examination, it looks as if you "+
      "might be able to squeeze through this crack to get out of "+
      "these hellish tunnels.");
   set_search("default","A small crack in the wall near the ceiling "+
      "catches your attention.");
   set_search("crack","It looks as though you might be about to "+
      "squeeze through the crack to get out!");
   set_exits(([
      "northeast" : ROOMS"tunnel13",
      "west" : ROOMS"tunnel11"
   ]));
}

void init(){
   ::init();
   add_action("squeeze_em","squeeze");
}

int squeeze_em(string str){
   int mysize;
   object dest,mob;
   dest = find_object_or_load("/d/shadow/room/kildare/rooms/nest2");
   if(!str){
      tell_object(TP,"What are you trying to squeeze?");
      return 1;
   }
   if(str != "crack" && str != "through crack" && str != "through the crack"){
      tell_object(TP,"You cannot squeeze through there!");
      return 1;
   }
   if(mob = present("kildare_mon",TO)){
      tell_object(TP,"The "+mob->query_race()+" seems to be blocking your way!");
      return 1;
   }
   mysize = TP->query_size();
   switch(mysize){
      case 1:  tell_object(TP,"You easily slip through the opening "+
                  "in the wall to the cave above.");
               if(!TP->query_invis()){
                  tell_room(TO,""+TPQCN+" slips through the opening "+
                     "in the wall easily.",TP);
                  tell_room(dest,""+TPQCN+" climbs up through a "+
                     "crack in the floor.",TP);
               }
               break;
      case 3:  tell_object(TP,"You struggle and push, nearly getting "+
                  "stuck permanently before you make it through the "+
                  "crack in the wall.");
               if(!TP->query_invis()){
                  tell_room(TO,""+TPQCN+" huffs and puffs as "+TP->QS+" "+
                     "struggles, nearly getting stuck before making "+
                     "it through the crack in the wall.",TP);
                  tell_room(dest,""+TPQCN+" labors and struggles "+
                     "but finally comes up through a crack in the "+
                     "floor.",TP);
               }
               break;
      default: tell_object(TP,"You suck in your chest and squeeze "+
                  "through the crack in the wall.");
               if(!TP->query_invis()){
                  tell_room(TO,""+TPQCN+" sucks in "+TP->QP+" chest "+
                     "and squeezes through the crack in the wall.",TP);
                  tell_room(dest,""+TPQCN+" squeezes through a "+
                     "crack in the floor.",TP);
               }
               break;
   }
   TP->move_player(dest);
   return 1;
}