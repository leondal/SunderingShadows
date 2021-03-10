//hidden04.c
#include <std.h>
#include "../../kildare.h"

inherit HIDDEN;
int items;

void create(){
items = 1;
  ::create();
    set_indoors(1);
   set_long(
      "%^YELLOW%^A Secret Hideaway\n"+
      "%^BOLD%^%^GREEN%^Strangely, the large evergreen that was standing "+
      "near the side of the abandoned trail proves to be this wonderful "+
      "hollowed out shelter.  It seems much larger on the inside than "+
      "it looked from outside, and it is accessible though a %^RESET%^%^ORANGE%^door "+
      "%^BOLD%^%^GREEN%^cleverly designed to look like the bark of the tree.  Inside "+
      "here, the trunk seems almost like a cabin, complete with two "+
      "narrow %^RESET%^%^GREEN%^cots %^BOLD%^and a %^BLUE%^woven mat "+
      "%^GREEN%^on the floor.  Two small %^RESET%^%^ORANGE%^knotholes "+
      "%^BOLD%^%^GREEN%^hidden from outside view by limbs provide "+
      "pleasant fresh air."
   );
   set_items(([
      (({"cabin","tree","hideaway"})) : "The inside of the tree "+
         "proves to be much like a wooden cabin.  It is well-protected "+
         "from the elements and would provide a wonderful place to "+
         "rest easy for awhile.",
      (({"door","bark","bark door"})) : "The smooth, rounded door is "+
         "cut from the tree itself and set on silent wooden hinges.  It "+
         "is nearly impossible to spot from the outside, and from the "+
         "inside, it blends rather well with the smooth walls.",
      (({"cot","cots"})) : "The narrow cots are made of green canvas "+
         "stretched over a wooden frame.  They do not look overly "+
         "comfortable, but would at least keep you off the floor.",
      (({"mat","woven mat","blue mat"})) : "The woven mat on the "+
         "floor was once a deep blue color but has now faded with "+
         "time and wear.  Thin patches reveal the floor in places, "+
         "and it almost seems something might be hidden beneath the "+
         "mat.",
      (({"knothole","knotholes","window","windows"})) : "Two knotholes "+
         "well-hidden from outside view provide a breath of fresh air "+
         "into this place, which would otherwise likely become quite "+
         "stuffy."
   ]));
   set_search("mat", (: TO, "search_rug" :) );
   set_search("woven mat", (: TO, "search_rug" :) );
   set_search("rug", (: TO, "search_rug" :) );
   set_exits(([
      "trail" : ROADS"wroad18",
      ]));
}
void search_rug() 
{
  if((items > 0)) { 
      switch (random(6)){
         case 0:
            tell_object(TP,"You don't find anything under the rug.");
            tell_room(ETP,""+TPQCN+" lifts the mat and looks underneath.",TP);
            break;
         case 1:
            tell_object(TP,"You lift the mat and find a piece of paper hidden "+
               "underneath!");
            tell_room(ETP,""+TPQCN+" lifts the mat and finds something underneath.",TP);
            new(OBJ"note1")->move(TO);
            break;
          case 2:
            tell_object(TP,"You lift the mat and find a piece of paper hidden "+
               "underneath!");
            tell_room(ETP,""+TPQCN+" lifts the mat and finds something underneath.",TP);
            new(OBJ"note2")->move(TO);
            break;
          case 3:
            tell_object(TP,"You lift the mat and find a piece of paper hidden "+
               "underneath!");
            tell_room(ETP,""+TPQCN+" lifts the mat and finds something underneath.",TP);
            new(OBJ"note3")->move(TO);
            break;
          case 4:
            tell_object(TP,"You lift the mat and find a piece of paper hidden "+
               "underneath!");
            tell_room(ETP,""+TPQCN+" lifts the mat and finds something underneath.",TP);
            new(OBJ"note4")->move(TO);
            break;
          case 5:
            tell_object(TP,"You lift the mat and find a piece of paper hidden "+
               "underneath!");
            tell_room(ETP,""+TPQCN+" lifts the mat and finds something underneath.",TP);
            new(OBJ"note5")->move(TO);
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
