//hidden01.c
#include <std.h>
#include "../../kildare.h"

inherit HIDDEN;
int items;

void create(){
items = 1;
  ::create();
   set_long(
      "%^YELLOW%^A Secret Hideaway\n"+
      "%^RESET%^The short track sprouting from the %^GREEN%^abandoned trail "+
      "%^RESET%^turns abruptly behind an enormous boulder and ends abruptly "+
      "here, in a hidden alcove within a %^YELLOW%^ring of boulders%^RESET%^.  The "+
      "tall outcroppings block the wind, creating a safe, comfortable "+
      "spot to rest.  Here, the %^GREEN%^grass %^RESET%^is much softer "+
      "and longer and is very healthy despite growing in the shadows.  "+
      "A small circle of stones forms a likely place for a %^RED%^campfire %^RESET%^in "+
      "the center of this hideaway, and many of the boulders have been "+
      "well-worn to provide comfortable supports."
   );
   set_items(([
      (({"alcove","hideaway"})) : "This small, comfortable hideaway "+
         "is set off the mountain trail, safe from prying eyes and "+
         "ears.  The boulders provide some protection against the wind, "+
         "but would offer no shelter from the rain.",
      (({"boulder","boulders","ring of boulders"})) : "The wide ring "+
         "is formed of boulders reaching over fifteen feet in height.  "+
         "Looking around at the base, it seems that some of them have "+
         "been left with a recess between them.",
      (({"recess","recesses"})) : "The space between the boulders is "+
         "filled in most places with dirt packed in to keep the wind "+
         "away.  However, you notice one spot in particular that has "+
         "been left with a recess large enough to hide something.",
      "grass" : "The grass here is soft and a vibrant green.",
      (({"stones","circle of stones","campfire","fire"})) : "The small "+
         "circle in the center of this hideaway is taken up by a "+
         "ring of rough gray stones.  It looks like a likely place "+
         "to build a safe campfire to ward off the chill mountain "+
         "air."
   ]));
   set_search("boulder", (: TO, "search_recess" :) );
   set_search("boulders", (: TO, "search_recess" :) );
   set_search("recess", (: TO, "search_recess" :) );
   set_exits(([
      "trail" : ROADS"wroad08",
      ]));
}
void search_recess() 
{
  if((items > 0)) { 
      switch (random(5)){
         case 0:
            tell_object(TP,"You don't find anything hidden within the recess.");
            tell_room(ETP,""+TPQCN+" searches between the boulders but "+
               "looks disappointed.",TP);
            break;
         case 1:
            tell_object(TP,"You stick your hand between the boulders and "+
               "find something hidden!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "between the boulders and finds something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"rand");
            break;
          case 2:
            tell_object(TP,"You stick your hand between the boulders and "+
               "find something hidden!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "between the boulders and finds something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"coins");
            break;
          case 3:
            tell_object(TP,"You stick your hand between the boulders and "+
               "find something hidden!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "between the boulders and finds something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"stuff");
            break;
          case 4:
            tell_object(TP,"You stick your hand between the boulders and "+
               "find something hidden!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "between the boulders and finds something!",TP);
            new(OBJ"hunterhatchet")->move(TO);
            break;
         }
      items = 0;
      return;
  }           
    else {
        write("It looks like this has been thoroughly searched recently.");
        }
}
void reset() {
        ::reset();
        if(random(4) < 3)
        if (!items) items=1;
}
