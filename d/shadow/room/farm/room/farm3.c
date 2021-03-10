#include <std.h>
#include <move.h>
#include "../farm.h"

inherit BARNYARD;

int hag,sword;

void create(){
   ::create();
   set_long(::query_long()+"\nA narrow %^ORANGE%^wooden bridge "+
      "%^RESET%^is positioned above the %^BOLD%^%^BLUE%^stream "+
      "%^RESET%^here, leading to the %^ORANGE%^building %^RESET%^"+
      "housing the %^ORANGE%^water wheel%^RESET%^.  One side "+
      "of the %^CYAN%^farmhouse %^RESET%^stands looming over you "+
      "to the east.\n");
   set_exits(([
      "north" : PATHS"bridge",
      "west" : PATHS"farm2",
      "southwest" : PATHS"farm6"
   ]));
   add_item(({"bridge","wooden bridge"}),"The wooden bridge is "+
      "narrow and weathered to a light silver, just like the "+
      "water wheel.  It looks perfectly natural - making it "+
      "seem all the more unnatural in this weird farmyard.");
   set_search("default",(:TO,"search_here":));
   set_search("water",(:TO,"search_water":));
   set_search("water's edge",(:TO,"search_water":));
   set_search("edge",(:TO,"search_water":));
   hag = 1;
   sword = 0;
}

int search_here(){
   if(sword == 1){
      tell_object(TP,"%^CYAN%^A sparkling along the %^BOLD%^water's "+
         "edge %^RESET%^%^CYAN%^catches your attention.  %^BOLD%^It "+
         "has an almost sword-like shape!");
      tell_room(TO,""+TPQCN+" searches around.",TP);
      return 1;
   }else{
      tell_object(TP,"You search around but find nothing odd.");
      tell_room(TO,""+TPQCN+" searches around.",TP);
      return 1;
   }
}

int search_water(){
object obj;
   if(hag == 1){
      tell_object(TP,"%^BOLD%^%^BLUE%^You search along the water's "+
         "edge and jump back when a putrid figure rises up from "+
         "beneath!\n%^RED%^Dammit, she's in the way of your search!");
      tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" searches along the "+
         "water's edge and stirs up a putrid figure!",TP);
      new(MON"sea_hag")->move(TO);
      hag = 0;
      sword = 1;
      return 1;
   }
   if(sword == 1){
      if(present("muirgena")){
         tell_object(TP,"The hag is not going to let you do that right now!");
         return 1;
      }else{
         tell_object(TP,"%^CYAN%^You search along the water's edge "+
            "and pull up a magnificent sword!");
         tell_room(TO,"%^CYAN%^"+TPQCN+" searches along the water's "+
            "edge and finds a beautiful sword!",TP);
         obj = new(OBJ"zweihander");
         if(obj->move(TP) != MOVE_OK){
            obj->move(ETP);
         }
         sword = 0;
         return 1;
      }
   }
   tell_object(TP,"You search along the water's edge but don't find anything.");
   return 1;
}

void reset(){
   ::reset();
   if(!random(3)) hag = 1;
   if(!present("goose") && !random(3)){
      new(MON"goose")->move(TO);
   }
}