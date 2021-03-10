#include <std.h>
#include "../farm.h"

inherit BARNYARD;
int MEPHIT,steaming;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^CYAN%^farmhouse %^RESET%^is "+
      "directly east of here, its walls dotted with %^BOLD%^"+
      "portholes %^RESET%^in various shapes and heights.  A strange "+
      "%^ORANGE%^cart %^RESET%^rests here, its wheels overgrown "+
      "with %^GREEN%^grasses%^RESET%^.\n");
   set_exits(([
      "northwest" : PATHS"farm1",
      "north" : PATHS"farm2",
      "northeast" : PATHS"farm3",
      "west" : PATHS"farm5",
      "southwest" : PATHS"farm8",
      "south" : PATHS"farm9",
      "southeast" : PATHS"farm10"
   ]));
   add_item(({"cart","strange cart","wagon"}),"This cart has a "+
      "simple wooden base, rather like any cart.  Its wheels now "+
      "appear useless, overgrown with grass and rotted through in "+
      "places.  Strapped to the back of the wagon is an unusual "+
      "device.");
   add_item("device","The device is made of bronze and fashioned "+
      "to look rather like a tall still.  Tubes run in all directions, "+
      "many reinforced with layers of bronze.  A small plaque at the "+
      "base of the device proudly bears the name '%^YELLOW%^Patented "+
      "Steam Powered Steam Generator%^RESET%^'  A small %^BOLD%^%^RED%^"+
      "button %^RESET%^is just beside the sign.");
   add_item("button","The small button is red and looks as though "+
      "it's just begging to be pushed.  Goodness only knows what "+
      "might happen though, with the shape this thing is in.");
   MEPHIT = 1;
   steaming = 0;
}

void init(){
   ::init();
   add_action("press_it","push");
}

int press_it(string str){
   if(!str){
      tell_object(TP,"You might want to <push button> to see what "+
         "the machine might do.");
      return 1;
   }
   if(str == "button" || str == "red button" || str == "start button"){
      if(steaming){
         tell_object(TO,"The machine is already working!");
         return 1;
      }
      if(!random(4) && MEPHIT == 1){
         tell_object(TP,"%^BOLD%^You push the button on the machine, "+
            "and it begins to cough and sputter.");
         tell_room(TO,"%^BOLD%^"+TPQCN+" pushes the button on the "+
            "machine, and it begins to cough and sputter.",TP);
         tell_room(TO,"%^BOLD%^%^CYAN%^Suddenly, the machine "+
            "belches steam in a great heave, bringing with it a "+
            "wicked little creature!");
         new(MON"mephit")->move(TO);
         MEPHIT = 0;
         return 1;
      }
      if(!random(3)){
         tell_object(TP,"%^BOLD%^You push the button on the "+
            "machine, and it begins to cough and sputter.");
         tell_room(TO,"%^BOLD%^"+TPQCN+" pushes the button on the "+
            "machine, and it begins to cough and sputter.",TP);
         tell_room(TO,"%^CYAN%^Suddenly, a strange object "+
            "flies out and lands on the ground!");
         new(OBJ"key")->move(TO);
         return 1;
      }
      tell_object(TP,"%^BOLD%^You push the button on the machine, "+
         "and it begins to cough and sputter.");
      tell_room(TO,"%^BOLD%^"+TPQCN+" pushes the button on the "+
         "machine, and it begins to cough and sputter.",TP);
      tell_room(TO,"%^YELLOW%^The machine nearly chokes and dies "+
         "for a moment, then suddenly is puffing out little blasts "+
         "of steam every few sections.");
      steaming = 1;
      call_out("steam_end",3);
      return 1;
   }
   return 0;
}

int steam_end(){
   tell_room(TO,"%^BOLD%^%^BLUE%^All of a sudden, the machine gives "+
      "a wheeze, a cough, and then falls into silence, hinting at "+
      "reason it's still lying here.");
   steaming = 0;
   return 1;
}

void reset(){
   ::reset();
   if(!random(2)) MEPHIT = 1;
}