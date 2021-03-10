//viento51 - Circe 11/10/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"A gorgeous %^BOLD%^columned library %^RESET%^"+
      "accessible by wide marble stairs stands to the north, while a "+
      "peaceful %^GREEN%^park %^RESET%^opens to the south.\n");
   set_exits(([
      "west" : ROOMS"viento50",
      "east" : ROOMS"viento52",
      "north" : ROOMS"library",
      "south" : ROOMS"park"
   ]));
   set_door("library door","/d/attaya/newseneca/rooms/library","north",0,0);
   set_door_description("library door","Visible through the colonnade, the "+
      "library door is an oversized, fifteen-foot-high construction of thick "+
      "%^BOLD%^%^BLACK%^mahogany%^RESET%^ and %^ORANGE%^bronze reinforcements"+
      "%^RESET%^.");
   set_door("gate","/d/attaya/newseneca/rooms/park","south",0);
   set_door_description("gate","%^BOLD%^%^BLACK%^The wrought-iron "+
      "gate to the south leads through a matching fence into a "+
      "%^RESET%^%^GREEN%^peaceful park%^BOLD%^%^BLACK%^.%^RESET%^");
   add_item("library","%^BOLD%^%^WHITE%^A construction of great beauty, "+
      "the library has a wide marble staircase climbing only a few steps "+
      "to the marble colonnade.  Each of the twelve columns features an "+
      "urn-shaped capital decorated with lines of sculpted leaves, and "+
      "a series of %^ORANGE%^lanterns %^WHITE%^hangs along the wall "+
      "to light the way to the impressive %^BLACK%^mahogany door%^WHITE%^.  "+
      "To the right of the door, a %^ORANGE%^brass plaque %^BOLD%^%^WHITE%^"+
      "has been set into the wall, bearing a message.%^RESET%^");
   add_item("park","%^GREEN%^The park to the south is large enough for "+
      "a few %^WHITE%^picnic tables %^GREEN%^as well as scattered %^BOLD%^"+
      "%^BLACK%^benches %^RESET%^%^GREEN%^and a bubbling %^CYAN%^fountain"+
      "%^GREEN%^.  It is bounded by an %^BOLD%^%^BLACK%^iron fence "+
      "%^RESET%^%^GREEN%^with %^RESET%^stone columns%^GREEN%^.%^RESET%^");
   add_item("fence","%^BOLD%^%^BLACK%^The iron picket fence has "+
      "fleur-de-lis caps and is set with %^RESET%^stone columns %^BOLD%^"+
      "%^BLACK%^at intervals.  An ornamental gate in the northern side "+
      "of the fence offers entry to the park.%^RESET%^");
   add_item("plaque","%^ORANGE%^The brass plaque is rectangular and "+
      "about three feet by two feet.  It bears a message engraved and "+
      "blackened to make it easy to read.%^RESET%^");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str != "plaque" && str != "brass plaque") return 0;
   tell_object(TP,"\n"+
"    %^BOLD%^%^RED%^################\n"+
"    #%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
"    #%^BLUE%^@@%^YELLOW%^\\|/%^BLUE%^@@@@%^YELLOW%^\\|/%^BLUE%^@@%^RED%^#\n"+
"    #%^BLUE%^@@%^YELLOW%^~T~%^BLUE%^@@@@%^YELLOW%^~T~%^BLUE%^@@%^RED%^#\n"+
"    #%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
"    #%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
"    #%^BLUE%^@@@@@%^YELLOW%^\\|/%^BLUE%^@@@@@@%^RED%^#\n"+
"     #%^BLUE%^@@@@%^YELLOW%^~T~%^BLUE%^@@@@@%^RED%^#\n"+
"      #%^BLUE%^@@@@@@@@@@%^RED%^#\n"+
"       #%^BLUE%^@@@@@@@@%^RED%^#\n"+
"         ######%^RESET%^\n\n"+
"%^BOLD%^%^BLACK%^Public Library of Seneca\n"+
"Gifted to the People of\n"+
"  Attaya by a Generous\n"+
" Donation from the Bard\n"+
"Academy of Seneca and the\n"+
"     Clergy of Oghma%^RESET%^\n"
   );
   if(!TP->query_invis()) tell_room(TO,""+TPQCN+" reads the plaque.",TP);
   return 1;
}
