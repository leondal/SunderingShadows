//caves5.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES2;

int items;

void create() {
    	::create();
    	set_short("In a small alcove");
    	set_name("In a small alcove");
    	set_long(
         "This shallow alcove is cut off from the rest of the %^YELLOW%^den%^RESET%^.  "+
         "There is a %^ORANGE%^straw mat %^RESET%^lying on the floor here that seems "+
         "to be crawling with %^BOLD%^%^BLACK%^lice%^RESET%^.  No corpses line the floor of "+
         "the alcove, but it could hardly be called clean.  Strings of %^BOLD%^bones %^RESET%^"+
         "and %^BOLD%^teeth %^RESET%^hang from %^ORANGE%^pegs %^RESET%^pounded into the "+
         "stone walls.  Various %^GREEN%^herbs %^RESET%^hang among strange "+
         "%^CYAN%^feathers %^RESET%^and bits of %^ORANGE%^fur%^RESET%^.  All together, "+
         "it suggests some sort of magic user must live here."+
         "\n"
    	);
    	set_exits(([
       	"west" : KCAVES"caves4"
    	] ));
    	set_items(([
         ({"mat","straw mat"}) : "The tan straw mat was once tightly-woven and well-made.  "+
            "Now, however, it has seen much use and is infested with lice.  It is slightly "+
            "bulky, as if it might be hiding something.",
         ({"lice","vermin"}) : "Tiny silvery bugs are crawling all over the mat.",
         ({"strings","bones","teeth","pegs"}) : "What could only be called necklaces "+
            "of bones and teeth are strung around the small alcove, handing from crude "+
            "wooden pegs.",
         ({"herbs","feathers","fur","assortment"}) : "Hanging between the necklaces are a "+
            "strange assortment of components, including feathers, fur, and herbs."
    	] ));
	set_search("default","Just your luck...the only thing that seems promising "+
         "is the lice-infested mat in the corner.");
	set_search("mat",(:TO,"search_mat":));
	items = 1;
}

void search_mat(){
   if(!items){
      tell_object(TP,"You start to search the mat, but luckily realize it's been "+
         "disturbed recently before you get too close.");
      return;
   }
   switch(random(10)){
      case 0..3:  tell_object(TP,"How vile!  You search the mat, making lice crawl "+
                  "up your arms, and you still don't find anything!");
                  tell_room(ETP,""+TPQCN+" searches the mat, making lice crawl up "+
                  ""+TP->query_possessive()+" arms!",TP);
                  break;
      case 4..5:  tell_object(TP,"How vile!  You search the mat, making lice crawl "+
                  "up your arms, but you do find something!");
                  tell_room(ETP,""+TPQCN+" searches the mat, making lice crawl up "+
                  ""+TP->query_possessive()+" arms!",TP);
                  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"potion",1);
                  break;
      case 6..7:  tell_object(TP,"How vile!  You search the mat, making lice crawl "+
                  "up your arms, but you do find something!");
                  tell_room(ETP,""+TPQCN+" searches the mat, making lice crawl up "+
                  ""+TP->query_possessive()+" arms!",TP);
                  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"kit",random(4)+2);
                  break;
      case 8:  tell_object(TP,"How vile!  You search the mat, making lice crawl "+
                  "up your arms, but you do find something!");
                  tell_room(ETP,""+TPQCN+" searches the mat, making lice crawl up "+
                  ""+TP->query_possessive()+" arms!",TP);
                  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"component",random(4)+2);
                  break;
      case 9:  tell_object(TP,"How vile!  You search the mat, making lice crawl "+
                  "up your arms, but you do find something!");
                  tell_room(ETP,""+TPQCN+" searches the mat, making lice crawl up "+
                  ""+TP->query_possessive()+" arms!",TP);
                  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"stuff");
                  break;
   }
   items = 0;
   return;
}