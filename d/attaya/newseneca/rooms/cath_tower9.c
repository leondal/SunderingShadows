//cath_tower9 - bell tower for new Seneca
//from here, players may ring the bells to sound alarms,
//celebrate occasions, etc.
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nThe bases of the thick %^ORANGE%^"+
      "brass bells %^RESET%^are just above your head here, "+
      "and it looks as though they may be sounded by use "+
      "of a %^BOLD%^rope %^RESET%^that dangles between them "+
      "and has been looped around a hook in the sandstone "+
      "walls.  A small %^ORANGE%^plaque %^RESET%^has been placed "+
      "just beside the hook.\n");
   set_exits(([
      "down" : ROOMS"cath_tower8",
      "up" : ROOMS"cath_tower10"
   ]));
   add_item("bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("brass bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("bell","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("beam","%^ORANGE%^The thick wooden beam runs into "+
      "the very sandstone of the walls, making the structure "+
      "stable.  Standing here, you can see that what looks to "+
      "be one solid beam is actually two.  A clever design "+
      "allows the main support to run directly into the walls, "+
      "while a second yoke is attached to the bells, giving "+
      "them free movement when the rope is pulled.%^RESET%^");
   add_item("hook","The hook has been pounded into the wall and "+
      "is attached to a wooden back for a finished look.  It "+
      "is large enough that the thick rope can be looped around "+
      "it and kept safely out of the way.");
   add_item("plaque","The brass plaque bears a message you should "+
      "probably read");
   add_item("rope","The thick rope is made from braided silk, "+
      "most unlike the cheaper hemp.  It is soft and silky to "+
      "the touch, and you might <pull> it to ring the bells.  "+
      "%^BOLD%^Be sure you heed the message on the plaque before "+
      "you do!%^RESET%^");
}

void init(){
   ::init();
   add_action("ring_em","ring");
   add_action("ring_em","sound");
   add_action("ring_em","pull");
   add_action("read_em","read");
}

int ring_em(string str){
   if(!str) return 0;
   if(str == "bells" || str == "bell" || str == "rope"){
      tell_object(TP,"%^BOLD%^You tug on the thick rope and set "+
         "the great %^YELLOW%^bells %^WHITE%^in motion.%^RESET%^");
      tell_room(TO,"%^BOLD%^"+TPQCN+" %^BOLD%^%^WHITE%^tugs on "+
         "the thick rope and sets "+
         "the great %^YELLOW%^bells %^WHITE%^in motion.%^RESET%^",TP);
      tell_room(TO,"%^YELLOW%^The tolling of the %^RESET%^%^ORANGE%^"+
         "brass bells %^YELLOW%^is almost unbearable this close!%^RESET%^");
      broadcast_area("/d/attaya/newseneca/rooms", "%^BOLD%^%^WHITE%^"+
         "The great bells of Seneca ring out over the land!%^RESET%^");
      return 1;
   }
   return 0;
}

int read_em(string str){
   if(!str) return 0;
   if(str == "plaque" || str == "the plaque"){
      tell_object(TP,"%^YELLOW%^\n"+
"     Be Ye Forewarned - \n"+
"Let Not the Bells of Seneca \n"+
" Ring Idly Over the Lands,\n"+
"   Let Them Ring Only in\n"+
"    Times of Celebration\n"+
"     Or Greatest Peril\n"+
"    So All May Know the\n"+
"      Bells Ring True%^RESET%^\n");
      if(!TP->query_invis()){
         tell_room(TO,""+TPQCN+" reads the plaque.",TP);
      }
      return 1;
   }
   return 0;
}