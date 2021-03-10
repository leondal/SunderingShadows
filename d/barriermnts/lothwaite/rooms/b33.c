//b33.c - Lothwaite barrows.  Circe 4/29/04
//This will be the hidden entrance/exit
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long("%^RESET%^%^BLUE%^This vast %^ORANGE%^chamber "+
      "%^BLUE%^has been chiseled out of the %^RESET%^mountain "+
      "%^BLUE%^itself.  The %^BOLD%^%^BLACK%^deep gray stone "+
      "%^RESET%^%^BLUE%^is shot through with %^BOLD%^%^BLACK%^v"+
      "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
      "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
      "%^YELLOW%^gold%^RESET%^%^BLUE%^, which %^RESET%^s%^BOLD%^h"+
      "%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r %^BLUE%^"+
      "in the faint %^YELLOW%^light %^RESET%^%^BLUE%^of a few "+
      "%^ORANGE%^torches%^BLUE%^.  Strangely, many of the "+
      "%^YELLOW%^torches %^RESET%^%^BLUE%^here seem to have "+
      "gone %^BOLD%^%^BLACK%^dark%^RESET%^%^BLUE%^, leaving "+
      "this whole area in %^BOLD%^%^BLACK%^deep shadow%^RESET%^"+
      "%^BLUE%^.  The %^BOLD%^%^BLACK%^walls "+
      "%^RESET%^%^BLUE%^are flawlessly sleek, making a passageway "+
      "that would rival the %^RESET%^stonework %^BLUE%^of the "+
      "most adept dwarves.  The %^BOLD%^%^BLACK%^ceilings %^RESET%^"+
      "%^BLUE%^arch to a point much like an onion dome, and "+
      "%^ORANGE%^columned supports %^BLUE%^have been carved in "+
      "relief, marching down the meandering hallways.  The "+
      "%^CYAN%^chill air %^BLUE%^of the barrows moves in an "+
      "endless breeze, making the %^ORANGE%^torchlight %^MAGENTA%^"+
      "fli%^BLUE%^ck%^MAGENTA%^er %^BLUE%^and %^MAGENTA%^d"+
      "%^BLUE%^a%^MAGENTA%^n%^BLUE%^c%^MAGENTA%^e%^BLUE%^.  "+
      "The passageway ends here, while opening back west.%^RESET%^\n");
   set_exits(([
      "west" : PATHEXIT"bt3",
   ]));
   set_search("default","As you search around in the darkness, "+
      "you notice what looks like a strange alcove, much too "+
      "small for a firbolg to have made.");
   set_search("alcove",(:TO,"search_alcove":));
}

int search_alcove(){
   tell_object(TP,"Upon searching the alcove, you notice it is "+
      "actually a small tunnel that leads to what looks like "+
      "another room!  You might be able to <enter> here if "+
      "you try.");
   tell_room(TO,""+TPQCN+" peers deep into the shadows for a "+
      "moment, searching around.",TP);
   return 1;
}

void init(){
   ::init();
   add_action("enter","enter");
}

int enter(string str){
   if(!str){
      tell_object(TP,"What are you trying to enter?");
      return 1;
   }
   if(str == "alcove" || str == "the alcove"){
      tell_object(TP,"%^BOLD%^%^BLACK%^You slip into the "+
         "shadowy alcove.");
      tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" steps forward "+
         "and disappears into the shadows!",TP);
      TP->move(PATHEXIT"hidden1");
      TP->force_me("look");
      return 1;
   }
   return 0;
}