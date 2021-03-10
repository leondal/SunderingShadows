//rockypath3.c - ~Circe~ 6/8/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit RPATH;

void create(){
   ::create();
   set_long(::query_long()+"The wall of %^ORANGE%^bedrock %^RESET%^"+
      "rises to the north here, blocking off most of the view of "+
      "the city.  This short pathway ends here at a %^BOLD%^white "+
      "stucco building %^RESET%^with a pristine %^BOLD%^%^RED%^"+
      "red tile roof%^RESET%^.  There is a small sign just beside "+
      "the %^ORANGE%^door%^RESET%^ that you could read.  Should "+
      "you wish to return to the city, the pathway leads upwards "+
      "to the west here.\n");
   set_exits(([
      "east" : ROOMS"restaurant2",
      "west" : ROOMS"rockypath2"
   ]));
   add_item(({"building","stucco building"}),"%^BOLD%^%^WHITE%^"+
      "The building here is finished with %^BOLD%^white stucco "+
      "%^RESET%^with a %^BOLD%^%^RED%^red tile roof%^RESET%^.  "+
      "It looks to offer a fantastic view of the ocean, and there "+
      "is a small %^ORANGE%^wooden sign%^RESET%^ set just beside "+
      "the door that you could read.");
   add_item(({"sign","wooden sign"}),"%^ORANGE%^The wooden sign "+
      "is reserved in design, a simple oval affair with a message "+
      "painted in %^BOLD%^%^RED%^red %^RESET%^%^ORANGE%^that you "+
      "could read.%^RESET%^");
   set_door("door","/d/attaya/newseneca/rooms/restaurant2","east",0,0);
   set_door_description("door","%^ORANGE%^The thick door of the "+
      "restaurant has %^BOLD%^%^BLACK%^iron-bound%^RESET%^%^ORANGE%^ "+
      "planks and rises to an arch at the top.  A large glassless "+
      "window set near the top has a matching %^BOLD%^%^BLACK%^iron "+
      "grate%^RESET%^%^ORANGE%^.%^RESET%^");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign" || str == "wooden sign"){
      tell_object(TP,"\n"+
"  %^RESET%^%^ORANGE%^ ------------\n"+
" /              \\\n"+
"|   %^BOLD%^%^RED%^El Pescado  %^RESET%^%^ORANGE%^ |\n"+
" \\              /\n"+
"   ------------%^RESET%^\n"
      );
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" reads the sign.",TP);
      }
      return 1;
   }
   return 0;
}