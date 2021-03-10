//caves6.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES2;

int items;

void create() {
items = 1;
    	::create();
    	set_short("In a dank cave");
    	set_name("In a dank cave");
    	set_long(
         "This limestone cave was originally created by an underground river "+
         "which has long since dried up.  Now, it is home to a %^YELLOW%^den %^RESET%^"+
         "of %^RED%^orcs%^RESET%^, which are not at all picky about their living "+
         "conditions.  All along the floor, %^GREEN%^mold %^RESET%^is growing on "+
         "pieces of discarded %^ORANGE%^food %^RESET%^that became too rancid for "+
         "even an orc's tastes.  This deep in the cave, the number of %^RED%^corpses "+
         "%^RESET%^has decreased, but several still lie scattered along the floor.  "+
         "The cave comes to an abrupt end here with a smooth wall just to the west.  "+
         "A few scattered %^RED%^rags %^RESET%^suggest that some of the orcs must lair here."+
         "\n"
    	);
    	set_exits(([
       	"east" : KCAVES"caves6"
    	] ));
    	set_items(([
         ({"cave","here","room"}) : "The cave walls are made of deep gray limestone that "+
            "was once worn smooth by water.  Now it is covered in the filth of the orcs.",
         ({"bone","bones","corpse","corpses","bodies","body"}) : "The corpses of the "+
            "dead villagers lie scattered around the cavern.  In places they are piled rather "+
            "high, and it seems something has been feeding on them.  A few, however, seem "+
            "strangely undisturbed.",
         ({"mold","food"}) : "Bits of maggoty bread lie molding on the floor.  Bright green "+
            "mold has begun growing over everything, making footing treacherous in some places.",
         ({"rag","rags"}) : "A few rags have been scattered about this cavern.  From the "+
            "looks of them, they might have once been bedrolls or blankets, but now are "+
            "little more than a home for vermin and a bed for orcs."
    	] ));
      set_search("default","Perhaps something could be hidden beneath the rags, if you dare to look.");
      set_search("rag",(:TO,"search_rags":));
      set_search("rags",(:TO,"search_rags":));
}

void search_rags(){
   if(!items){
      tell_object(TP,"It looks like someone was already brave enough to look there.");
      return;
   }
   switch(random(4)){
      case 0:  tell_object(TP,"You search the rags but don't find anything hidden there.");
               break;
      case 1:  tell_object(TP,"%^BOLD%^As you bend down to search the rags, an orc comes charging in!");
               tell_room(ETP,"%^BOLD%^An orc comes charging in just as "+TPQCN+" leans down to "+
                  "ssearch the rags!",TP);
               new(KMON"orccaptain")->move(TO);
               break;
      case 2..3:  tell_object(TP,"Lifting the rags, you find something hidden beneath!");
                  tell_room(ETP,""+TPQCN+" searches among the rags.",TP);
                  "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",15,1);
                  break;
   }
   items = 0;
   return;
}