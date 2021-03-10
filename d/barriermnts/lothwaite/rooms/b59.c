//b59.c - Lothwaite barrows.  Circe 5/1/04
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^The normally twisting "+
      "passageway leads relatively straight west here.  Strangely, "+
      "the passage ends abruptly to the east with a sheer rock "+
      "wall.  An image of a door seems to be carved into it, though "+
      "you cannot see so much as a crack around it.\n");
   set_exits(([
      "west" : PATHEXIT"b58"
   ]));
   add_item("door","You cannot tell if a door is actually there.  "+
      "If there is, it seems so well made as to close perfectly with "+
      "the wall around it.  Surely, you would need some sort of key "+
      "to get in here, but...there's no keyhole.");
   add_item("wall","You cannot tell if a door is actually there.  "+
      "If there is, it seems so well made as to close perfectly with "+
      "the wall around it.  Surely, you would need some sort of key "+
      "to get in here, but...there's no keyhole.");
   set_search("default","The outline of the door catches your attention.");
   set_search("door","As you examine the door, a torch suddenly "+
      "%^YELLOW%^flares%^RESET%^, revealing an impression of a large "+
      "hand.  Hmm...perhaps if you placed your hand in it...?");
}

void init(){
   ::init();
   add_action("push_em","push");
   add_action("push_em","place");
}

int push_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to place where?");
      return 1;
   }
   if(str == "door" || str == "hand on door" || str == "wall" || str == "hand on wall" || str == "hand on impression" || str == "hand on the impression" || str == "hand in impression" || str == "hand in the impression"){
      if(member_array("east",ETP->query_exits()) != -1){
         tell_object(TP,"The door is already open!");
         return 1;
      }
      if(present("belt of giant strength",TP)){
         tell_object(TP,"You place your hand on the impression and "+
            "a crack begins to outline itself around the door.\n");
         tell_room(ETP,""+TPQCN+" places "+TP->QP+" hand on the "+
            "impression and a crack begins to outline itself around "+
            "the door.\n",TP);
         tell_room(ETP,"The door slowly swings open, revealing a "+
            "large chamber.");
         add_exit(PATHEXIT"b60","east");
         return 1;
      }
      tell_object(TP,"%^CYAN%^The door is sealed, save for the one "+
         "who bears the belt!  You must return it!");
      tell_room(ETP,"%^CYAN%^"+TPQCN+" places "+TP->QP+" hand "+
         "against the impression, but nothing happens.",TP);
      return 1;
   }
   tell_object(TP,"Try placing your hand on the impression.");
   return 1;
}