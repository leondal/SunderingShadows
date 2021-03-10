#include <std.h>
#include "../farm.h"

inherit BARNYARD;
int flower;

void create(){
   ::create();
   set_long(::query_long()+"\nA round %^MAGENTA%^flower garden "+
      "%^RESET%^bordered by smooth %^BOLD%^river rocks %^RESET%^"+
      "lies here.  Several luxurious %^GREEN%^plants %^RESET%^"+
      "grow within, many of which you've never seen before.  In "+
      "the center is a tall, fragrant %^BOLD%^%^MAGENTA%^flower "+
      "%^RESET%^of %^BOLD%^%^CYAN%^azure %^RESET%^with %^BOLD%^"+
      "%^MAGENTA%^pink spots%^RESET%^.\n");
   add_item(({"flower","flowers","plant","plants"}),(:TO,"flower_desc":));
   set_exits(([
      "northwest" : PATHS"farm5",
      "north" : PATHS"farm6",
      "west" : PATHS"farm8",
      "east" : PATHS"farm10",
      "southwest" : PATHS"farm12",
      "south" : PATHS"farm13",
      "southeast" : PATHS"farm14"
   ]));
   set_search("default",(:TO,"search_here":));
   flower = 1;
}

int search_here(){
   if(flower == 1){
      tell_object(TP,"The flower garden seems to draw your attention, "+
         "and you feel an urge to <pick> the flower in its center.");
      tell_room(TO,""+TPQCN+" seems to be looking at the flower garden.",TP);
      return 1;
   }else{
      tell_object(TP,"The flower garden seems strangely unbalanced with "+
         "only a stalk in the center, surrounded by other beautiful "+
         "flowers.");
      tell_room(TO,""+TPQCN+" seems to be looking at the flower garden.",TP);
      return 1;
   }
}

string flower_desc(){
   if(flower == 1){
      return("The flowers in the garden seem to be simply a backdrop "+
         "to the beautiful lily standing in the center.  The lily "+
         "reaches a full three feet in height, where it sprouts into "+
         "a single, breath-taking blossom.  The %^BOLD%^%^CYAN%^azure "+
         "petals %^RESET%^spiral out from a %^BOLD%^%^MAGENTA%^pink "+
         "center%^RESET%^, with matching %^BOLD%^%^MAGENTA%^pink dots "+
         "%^RESET%^covering the length of the petals.  Something about "+
         "its beauty begs you to <pick> it.");
   }else{
      return("All the smaller flowers surround an oddly blank "+
         "place in the center.  It seems as if another flower "+
         "should be growing there, but perhaps the owner simply "+
         "forgot to plant it.");
   }
}

void init(){
   ::init();
   add_action("pick_em","pick");
}

int pick_em(string str){
   if(!str){
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(str != "flower" && str != "lily" && str != "flowers") return 0;
   if(flower == 1){
      tell_object(TP,"%^BOLD%^%^CYAN%^You lean down to pick the "+
         "flower.  As your hand gets close, it suddenly shudders "+
         "to life and wraps itself around your hand!");
      tell_room(TO,"%^BOLD%^%^CYAN%^As "+TPQCN+" leans in to "+
         "pick the flower, it suddenly shudders to life and wraps "+
         "itself around "+TP->QP+" hand!",TP);
      new(MON"flower")->move(TO);
      flower = 0;
      return 1;
   }else{
      tell_object(TP,"%^YELLOW%^You look around, but none of the "+
         "flowers seem to catch your attention.");
      tell_room(TO,"%^YELLOW%^"+TPQCN+" looks around at the flower "+
         "garden.",TP);
      return 1;
   }
}

void reset(){
   ::reset();
   if(!random(3)) flower = 1;
}