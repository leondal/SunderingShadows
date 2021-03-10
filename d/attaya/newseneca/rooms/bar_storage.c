//bar_storage - for new Seneca ~Circe~ 11/19/07
#include <std.h>
#include "../seneca.h"

#define THIEF "/d/attaya/newseneca/cguilds/thief/"+

inherit VAULT;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(WOOD_BUILDING);
   set_name("Storage Room of the Salt Merchant, Seneca");
   set_short("Storage Room of the Salt Merchant, Seneca");
   set_property("indoors",1);
   set_property("light",3);
   set_long("%^YELLOW%^Shelves %^RESET%^line three of the four walls "+
      "in this room.  The eastern wall, in which the %^ORANGE%^door "+
      "%^RESET%^is set, has been left bare.  There, %^BOLD%^%^BLACK%^"+
      "iron-bound %^RESET%^%^ORANGE%^casks%^RESET%^ are stacked in "+
      "various sizes, all presumably holding refills of the bar's "+
      "popular drinks.  Topping the %^YELLOW%^shelves %^RESET%^are "+
      "various stores, from %^ORANGE%^crates %^RESET%^of %^BOLD%^"+
      "champagne %^RESET%^to %^BOLD%^bottles of liquor%^RESET%^.  "+
      "Some shelves hold %^CYAN%^jars %^RESET%^of various "+
      "%^GREEN%^spices %^RESET%^for use in the dishes served here.  "+
      "The %^BOLD%^floor %^RESET%^here seems to be swept somewhat "+
      "regularly, as you don't notice the sand found in most of "+
      "Seneca.\n");
   set_items(([
      ({"shelves","shelf"}) : "Wooden shelves are spaced floor-to-ceiling "+
         "on three of the four walls.  They are filled with all sorts of "+
         "supplies needed for the bar.",
      ({"wall","walls"}) : "Three of the four walls here are masked "+
         "by shelves.  On the eastern wall, the doorway is braced "+
         "by stacks of barrels.",
      "floor" : (:TO,"look_floor":),
      ({"casks","cask","barrel","barrels"}) : "%^ORANGE%^Each of the casks "+
         "near the eastern wall is made of wooden staves bound with "+
         "%^BOLD%^%^BLACK%^iron%^RESET%^%^ORANGE%^.  It looks as though "+
         "the full barrels are stacked on the left of the door, while the "+
         "empty ones waiting to be returned are on the right.%^RESET%^",
      ({"stores","crates","champagne","bottles","liquor","jars","spices"}) : 
         "The shelves are somewhat organized, with wooden crates holding "+
         "bottles of champagne stacked together on the bottom shelves.  "+
         "Just above them, in easy reach, are various spices needed for "+
         "the dishes cooked here.  Finally, bottles of hard liquor used "+
         "to make many of the drinks are kept on the upper shelves."
   ]));
   set_search("default","There doesn't seem to be anything of interest here.");
   set_search("floor",(:TO,"search_floor":));
   set_search("panel",(:TO,"search_panel":));
   set_smell("default","The dusty smell of the storage room far outweighs the aromas from the bar.");
   set_listen("default","The storage room is blessedly quiet compared to the bar.");
   set_exits(([
      "east" : ROOMS"bar_cards"
   ]));
   set_door("storage door","/d/attaya/newseneca/rooms/bar_cards","east",0);
   set_door_description("storage door","This side of the door has been "+
      "left its natural color, causing it to stand out a bit from the "+
      "dingy white walls.");
}

void init(){
   ::init();
   add_action("stomp_em","stomp");
}

int look_floor(){
   if(!TP->is_class("thief") && !TP->is_class("bard") && random(5)){
      tell_object(TP,"You notice the wooden floor seems to be swept clean.  "+
         "Jericho must like a tidy storage room.");
      if(!TP->query_invis()) tell_room(TO,""+TPQCN+" looks over the floor.",TP);
      return 1;
   }else{
      tell_object(TP,"Your keen eyes notice that some of the sand "+
         "has gathered lightly in a straight line that does not "+
         "match the seams in the wooden floor near the northern wall.");
      if(!TP->query_invis()) tell_room(TO,""+TPQCN+" looks over the floor.",TP);
      return 1;
   }
}

int search_floor(string str){
   if(str != "floor") return 0;
   if(!TP->is_class("bard") && !TP->is_class("thief") && random(6)){
      tell_object(TP,"You feel a little silly as you run your hand along "+
         "the floor but don't find anything of interest.");
      if(!TP->query_invis()) tell_room(TO,""+TPQCN+" looks silly as "+TP->QS+" "+
         "runs "+TP->QP+" hands along the floor.  What in the world?",TP);
      return 1;
   }else{
      tell_object(TP,"%^BOLD%^Upon searching around, you find that there is a loose "+
         "panel in the floor near the eastern wall.%^RESET%^");
      if(!TP->query_invis()) tell_room(TO,""+TPQCN+" looks over the floor.",TP);
      return 1;
   }
}

int search_panel(string str){
   if(str != "panel") return 0;
   tell_object(TP,"Searching the panel, you find that the layer "+
      "of dust around it is lighter than the surrounding ones.  "+
      "The way it moves makes you think you could <stomp> on it, "+
      "though who knows what would happen then?");
   if(!TP->query_invis()) tell_room(TO,""+TPQCN+" looks silly as "+TP->QS+" "+
      "runs "+TP->QP+" hands along the floor.  What in the world?",TP);
   return 1;
}

int stomp_em(string str){
   if(str != "panel") return 0;
   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   tell_object(TP,"You stomp on the loose panel, and it flips open, "+
      "dumping you in the room below");
   if(!TP->query_invis()) tell_room(TO,""+TPQCN+" stomps on "+
      "the floor, and a panel flips open, dumping "+TP->QO+" "+
      "into a room below.",TP);
   TP->move(THIEF"2thief9");
   TP->force_me("look");
   return 1;
}
