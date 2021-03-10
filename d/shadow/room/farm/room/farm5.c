#include <std.h>
#include "../farm.h"

inherit BARNYARD;

int item;

void create(){
   ::create();
   set_long(::query_long()+"\nA tall leaning %^YELLOW%^"+
      "haystack %^RESET%^stands here.\n");
   set_exits(([
      "north" : PATHS"farm1",
      "northeast" : PATHS"farm2",
      "east" : PATHS"farm6",
      "southeast" : PATHS"farm9",
      "south" : PATHS"farm8",
      "southwest" : PATHS"farm7",
      "west" : PATHS"farm4"
   ]));
   add_item(({"stack","haystack"}),"%^YELLOW%^The leaning "+
      "haystack seems ordinary enough, though it has a few "+
      "patchy places.  It seems maybe the one who pitches "+
      "the hay is a bit sporadic.");
   set_search("default","You search around the area and "+
      "realize the towering haystack could definitely "+
      "be concealing something.");
   set_search("haystack",(:TO,"search_hay":));
   set_search("stack",(:TO,"search_hay":));
   set_search("hay",(:TO,"search_hay":));
   item = 1;
}

int search_hay(){
   if(item){
      switch(random(7)){
      case 0..2:  tell_object(TP,"%^BOLD%^%^MAGENTA%^You "+
                  "find...something the old gnome must "+
                  "have lost hidden in the haystack.");
                  "/d/common/daemon/randtreasure_d"->find_stuff(TO,"stuff");
                  break;
      case 3..4:  tell_object(TP,"%^BOLD%^You find a piece "+
                  "of cloth hidden in the haystack.");
                  new("/d/antioch/antioch2/obj/r_hchief")->move(TO);
                  break;
      case 5:  tell_object(TP,"%^YELLOW%^You find a tiny "+
                  "needle hidden in the haystack!  Remarkable!");
               new(OBJ"needle")->move(TO);
               break;
      case 6:  tell_object(TP,"%^BOLD%^%^BLACK%^You find a key "+
                  "hidden in the haystack!");
               new(OBJ"key")->move(TO);
               break;
      default: break;
      }
      tell_room(TO,"%^BOLD%^"+TPQCN+" searches the haystack "+
         "and pulls something out!",TP);
      item = 0;
      return 1;
   }
   tell_object(TP,"%^YELLOW%^You stick your head in the haystack "+
      "but find nothing.");
   tell_room(TO,"%^YELLOW%^"+TPQCN+" sticks "+TP->QP+" head "+
      "in the haystack and comes out covered in hay.",TP);
   return 1;
}

void reset(){
   ::reset();
   if(!item && !random(2)) item = 1;
}