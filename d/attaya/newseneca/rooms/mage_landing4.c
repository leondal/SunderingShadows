//~Circe~ 1/2/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the east here is a room with a "+
      "%^MAGENTA%^sign %^RESET%^hanging beside the %^BOLD%^doorway%^RESET%^.\n");
   add_item("sign","%^MAGENTA%^The sign has been attached to the "+
      "wall beside the doorway and bears a message you could read.%^RESET%^");
   set_exits(([
      "down" : ROOMS"mage_landing3",
      "up" : ROOMS"mage_landing5",
      "east" : ROOMS"mage_lab"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/mage_lab","east",0,0);
   set_door_description("door","The door in the eastern wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str != "sign") return 0;
   tell_object(TP,"\n"+
"%^BOLD%^%^MAGENTA%^      Arcane Laboratory \n\n"+
"       %^CYAN%^~~~~~~~~~~~~~~\n\n"+
"  %^WHITE%^Provided for the Use of\n"+ 
"  All Members of the Tower%^RESET%^\n");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" reads the sign.",TP);
   }
   return 1;
}