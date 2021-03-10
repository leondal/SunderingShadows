//hidden03.c
#include <std.h>
#include "../../kildare.h"

inherit HIDDEN;
int items;

void create(){
items = 1;
  ::create();
   set_long(
      "%^YELLOW%^A Secret Hideaway\n"+
      "%^BLUE%^A small opening between the boulders to the south "+
      "opens into what can only be described as a %^RESET%^%^ORANGE%^cave"+
      "%^BOLD%^%^BLUE%^.  Though still above ground, judging from the "+
      "fitful clumps of %^GREEN%^grass %^BLUE%^growing here, this spot "+
      "is completely sheltered by boulders on all sides.  One is even "+
      "perched atop the others to form a roof.  In the northeastern "+
      "portion of the cave, a makeshift %^RESET%^%^RED%^fireplace"+
      "%^BOLD%^%^BLUE%^, complete with a chimney, has been built.  "+
      "A battered %^BOLD%^%^BLACK%^iron pot %^BLUE%^rests nearby, "+
      "ready to be used for heating water or a meal.  There are "+
      "no other furnishings here, but it is clear that this place "+
      "must have been used as a shelter many times in the past."
   );
   set_items(([
      (({"cave","hideaway"})) : "This small cave provides complete "+
         "protection from the elements.  The boulders have been packed "+
         "with mud to prevent the wind from reaching here, while the "+
         "roof is likewise sealed.",
      (({"grass","clumps of grass"})) : "Small tufts of coarse "+
         "grass grow throughout the cave, though most of it has "+
         "turned a brownish green.  It is prickly and not comfortable "+
         "but luckily does not cover the whole cave floor.",
      (({"boulder","boulders"})) : "Huge boulders form the walls and "+
         "ceiling of this cave.",
      (({"fireplace","fire place","chimney"})) : "Smaller rocks have been "+
         "used to build a crude fireplace in the northeastern part of the cave.  "+
         "A tall, winding chimney rises to the top of the cave and feeds out "+
         "somehow, keeping the room free of smoke.  A black iron pot rests "+
         "near the fireplace.",
      (({"iron pot","pot","black pot","black iron pot"})) : "%^BOLD%^%^BLACK%^The "+
         "black iron pot sitting at the foot of the fireplace in the "+
         "grass is small and round.  It looks as if it would hold enough "+
         "stew for one or two people, but the outside has rusted a bit.  "+
         "It seems there might be something left inside it."
   ]));
   set_search("pot", (: TO, "search_recess" :) );
   set_search("iron pot", (: TO, "search_recess" :) );
   set_search("black iron pot", (: TO, "search_recess" :) );
   set_exits(([
      "south" : ROADS"hidden02",
      ]));
}
void search_recess() 
{
  if((items > 0)) { 
      switch (random(5)){
         case 0:
            tell_object(TP,"You don't find anything in the pot.");
            tell_room(ETP,""+TPQCN+" looks into the black iron pot.",TP);
            break;
         case 1:
            tell_object(TP,"You lift the pot and look inside, finding "+
               "something hidden there!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "into the iron pot and seems to find something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"rand");
            break;
          case 2:
            tell_object(TP,"You lift the pot and look inside, finding "+
               "something hidden there!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "into the iron pot and seems to find something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"coins");
            break;
          case 3:
            tell_object(TP,"You lift the pot and look inside, finding "+
               "something hidden there!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "into the iron pot and seems to find something!",TP);
            "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"stuff");
            break;
          case 4:
            tell_object(TP,"You lift the pot and look inside, finding "+
               "something hidden there!");
            tell_room(ETP,""+TPQCN+" sticks "+TP->query_possessive()+" hand "+
               "into the iron pot and seems to find something!",TP);
            new(OBJ"headband")->move(TO);
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
