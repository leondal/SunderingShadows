//caves2.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES;

int items;

void create() {
items = 1;
    	::create();
    	set_short("In a dark smelly cave");
    	set_name("In a dark smelly cave");
    	set_long(
         "The cave is dark here, but despite the poor lighting, "+
         "signs of occupation are evident.  %^ORANGE%^Matted fur rugs %^RESET%^line "+
         "the floor and %^BOLD%^gnawed bones %^RESET%^lie in the %^RED%^dust%^RESET%^.  "+
         "Several %^YELLOW%^weapons%^RESET%^ "+
         "in various stages of repair are scattered around the "+
         "stone floor of the %^BOLD%^%^BLACK%^cave%^RESET%^.  A few "+
         "%^BOLD%^%^BLUE%^whetstones %^RESET%^and bits of "+
         "%^ORANGE%^cording %^RESET%^lie in the dust as well, giving the impression that "+
         "the inhabitants of this cave are not very careful with "+
         "their gear."+
         "\n"
    	);
    	set_exits(([
       	"west" : KCAVES"caves1",
       	"east" : KCAVES"caves3"
    	] ));
    	set_items(([
         ({"wall","walls","cave"}) : "The solid rock walls of the cavern are deep "+
            "gray and worn smooth.  Faint watermarks reveal that the stream was probably "+
            "the origin of this cave system.  The walls curve smoothly overhead, and "+
            "no stalagmites or stalagtites have formed here.",
         ({"shadow","shadows"}) : "Deep shadows line the cavern walls and cast "+
            "much of the floor into darkness.",
         ({"bones","scraps","floor","dust"}) : "A thick layer of dust and "+
            "crumbled stone lines the floor of the cave.  Mixed with it are "+
            "rancid scraps and mangled bones, which have been gnawed beyond "+
            "recognition.  Some larger piles of dust seem as though they might "+
            "conceal something beneath.",
         ({"whetstone","whetstones","weapon","weapons","cording","cord"}) : "Lying "+
            "in the dust of the cave floor are several weapons in need of repair.  "+
            "Spear hafts mixing the head are tangled in cording while swords with "+
            "broken hilts lie near the whetstones.",
         ({"rug","rugs","fur rugs"}) : "The matted rugs seem to be animal hides which "+
            "have been poorly skinned and tanned.  They are serving as beds, apparently, "+
            "and look as though they might house more than one type of parasite."
    	] ));
      set_search("default","A small rug lying near the northern wall of the cave catches your attention.");
      set_search("rug", (: TO, "search_rug" :) );
}

void search_rug(){
   if(!items){
      tell_object(TP,"The rug has been moved as if someone searched there recently.");
      return;
   }
   switch(random(6)){
      case 0..2:  tell_object(TP,"You don't find anything of use under the rug, just some maggoty old bread.");
                  tell_room(ETP,""+TPQCN+" lifts the rug and searches underneath.",TP);
                  break;
      case 3:  tell_object(TP,"You lift the rug and find something shiney underneath!");
               tell_room(ETP,""+TPQCN+" lifts the rug and searches underneath.",TP);
               new(KOBJ"koenig_gem")->move(TO);
               break;
      case 4:  tell_object(TP,"You lift the rug and find something hidden underneath!");
               tell_room(ETP,""+TPQCN+" lifts the rug and searches underneath.",TP);
               "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"random");
               break;
      case 5:  tell_object(TP,"You lift the rug and find something hidden underneath!");
               tell_room(ETP,""+TPQCN+" lifts the rug and searches underneath.",TP);
               "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"kit");
               break;
   }
   items = 0;
   return;
}