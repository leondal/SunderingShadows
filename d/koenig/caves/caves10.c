//caves10.c - updated 11/29/03 by Circe
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
         "even an orc's tastes.  This cave has obviously been used as a dumping "+
         "ground for all manner of things, from waste to bodies.  There is a "+
         "%^ORANGE%^wooden ladder%^RESET%^ rising up out of a hole through the ceiling."+
         "\n"
    	);
     	set_smell("default","The smell of limestone is overwhelming.");
     	set_listen("default","You hear a faint drip of water in the cave.");
    	set_exits(([
       	"up" : KCAVES"caves8",
    	] ));
    	set_items(([
         ({"cave","here","room"}) : "The cave walls are made of deep gray limestone that "+
            "was once worn smooth by water.  Now it is covered in the filth of the orcs.",
         ({"bone","bones","corpse","corpses","bodies","body"}) : "The corpses of the "+
            "dead villagers lie scattered around the cavern.  In places they are piled rather "+
            "high, and it seems something has been feeding on them.  Unlike the caverns above, "+
            "several orc corpses are mixed here with the human villagers.",
         ({"mold","food"}) : "Bits of maggoty bread lie molding on the floor.  Bright green "+
            "mold has begun growing over everything, making footing treacherous in some places.",
         ({"ladder","wooden ladder"}) : "This rickety ladder leading up into the caverns above "+
            "seems to be falling apart."
    	] ));
      set_search("default","You're quite sure there's probably something hidden down in the rancid pile.");
      set_search("corpses","Perhaps you should try searching the pile.");
      set_search("pile",(:TO,"search_pile":));
}

void search_pile(){
   if(!items){
      tell_object(TP,"Your hands slip on mold and more disgusting things, but "+
         "unfortunately, someone has already searched here.");
      return;
   }
   switch(random(20)){
      case 0..5:  tell_object(TP,"You delve deep into the corpses but don't find anything.");
                  tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
                  break;
      case 6:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"edgeds",10,1);
               break;
      case 7:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"edgedm",10,1);
               break;
      case 8:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",10,1);
               break;
      case 9:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",10,1);
               break;
      case 10:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"clubm",10,1);
               break;
      case 11:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"blunts",10,1);
               break;
      case 12:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"bluntm",10,1);
               break;
      case 13:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",10,1);
               break;
      case 14:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->arm_me(TO,"tool",10,1);
               break;
      case 15:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",10,1);
               break;
      case 16:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"armornp",10,1);
               break;
      case 17:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"armorpl",10,1);
               break;
      case 18:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"armorcl",10,1);
               break;
      case 19:  tell_object(TP,"You delve deep into the corpses and pull something up from underneath.");
               tell_room(ETP,""+TPQCN+" reaches into the corpses up to "+TP->query_possessive()+" elbows.",TP);
               "/d/common/daemon/randgear_d"->armor_me(TO,"shield",10,1);
               break;
   }
   items = 0;
   return;
}