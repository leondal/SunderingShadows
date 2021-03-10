#include <std.h>
#include "/d/common/common.h"
#include "keep.h"
inherit ROOM;

int FLAG, OPEN;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret room");
   set_long(
   "The secret passage has lead to this hidden room. This place is similar to a"+
   " lounge, or perhaps a study. There is a worn out couch against the northern"+
   " wall and a tiny desk in the southwestern corner. The floor is covered in"+
   " numerous overlapping rugs and there is an oil lamp on a stand to the south."+
   " There is a small iron chest against the western wall, flanked by two granite"+
   " pedestals."
   );
   set_smell("default","The sulfuric scent from the passage lingers in this room.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   ({"floor","rugs"}) : "%^ORANGE%^Several thick rugs cover the entire floor,"+
   " preventing you from having to walk on the cold stone blocks beneath.",
   "desk" : "There is a tiny writing desk in the southwestern corner. A journal is"+
   " on top of it. A cushioned chair is next to the desk.",
   "journal" : "This is a well worn, leather-bound journal that probably belonged"+
   " to the mage. It has a few notes about spells and traps, but nothing that's very decipherable or of much interest.",
   "chair" : "This is a comfortable looking chair. Whoever used this place sure liked"+
   " comfort.",
   "couch" : "%^YELLOW%^This is a very cozy looking couch. It appears to have gotten"+
   " a lot of use, and was probably used as a bed more than once.",
   ({"lamp","oil lamp"}) : "There is an oil lamp with a pretty stained glass lamp"+
   " shade on the night stand on the south side of the room.",
   ({"stand","night stand"}) : "The night stand is made of ebony and was probably"+
   " on the expensive side. Whoever used this place must have been rich.",
   "chest" : "There is a simple iron chest against the west wall of the room, flanked"+
   " by two granite pedestals. You could probably attempt to open it.",
   ({"pedestal","granite pedestal","pedestals"}) : "The pedestals are ornately"+
   " worked granite, which is unusual by itself. But what is more unusual are the"+
   " flat tops where a statue or some other item might be set that is completely"+
   " empty.",
   ]));
   set_exits(([
   "east" : ROOMS+"floor7",
   ]));
}

void reset() {
   ::reset();
   if(!random(4)) {
      OPEN = 0;
      FLAG = 0;
      add_item("chest", "There is a simple iron chest against the west wall of the room, flanked by two granite pedestals. You could probably attempt to open it.");
   }
}

void init()
{
   ::init();
//   add_action("read","read");
   add_action("open","open");
}

void open(string str)
{
   object obj, obj2, obj3, obj4;

   if(str != "chest") {
      tell_object(TP,"Open what?");
      return 1;
   }
   if(OPEN == 1) {
      tell_object(TP,"The chest has already been opened.");
      return 1;
   }
   if(FLAG != 1) {
      tell_object(TP,"As you move towards the chest two monsters appear and attack you!");
      tell_room(ETP,"As "+TPQCN+" moves toward the chest two monsters appear and attack!",TP);
      new(MONS+"mephit")->move(TO); 
      new(MONS+"mephit")->move(TO); 
      FLAG = 1;
      return 1;
   }
   if(present("steam mephit")) {
      tell_object(TP,"The mephit prevents you from opening the chest!");
      return 1;
   }
   else {
      tell_object(TP,"You open the chest and discover a key and some other items inside.");
      tell_room(ETP,""+TPQCN+" opens the chest and finds a few things.",TP);
      new(OBJ2+"key")->move(TO);
/* changing to have fewer scrolls and more chances of other items *Styx*, 12/28/03, lc 12/29/01
      obj = new("/d/magic/scroll");
      obj->set_spell(1);
      obj->move(TO);
*/
      switch(random(8)) {
         case 0:
            obj2 = new("/d/magic/scroll");
            obj2->set_spell(2);
            obj2->move(TO);
	    break;
         case 1:
//            obj3 = new("/d/magic/scroll");
//            obj3->set_spell(3);
//            obj3->move(TO);
	    RANDSTUFF->find_stuff(TO, "component", random(5)+1);      
	    break;
         case 2:
//            obj4 = new("/d/magic/scroll");
//            obj4->set_spell(random(2)+1);
//            obj4->move(TO);
	    RANDSTUFF->find_stuff(TO, "coins", random(50)+10);      
            break;
	 case 3..4:
	    RANDSTUFF->find_stuff(TO, "kit", random(5)+1);
	    break;
	 case 5..7:
	    RANDSTUFF->find_stuff(TO, "random");
	    break;	
      }
      add_item("chest","The large iron chest appears to be open and cleaned out.");
      OPEN = 1;
      return 1;
   }      
}

/*
void read(string str)
{
   if(str == "journal") {
      tell_object(TP,"You browse through the pages of the journal, reading the mage's"+
      " story.");
      tell_room(ETP,""+TPQCN+" reads the journal on the desk.");
      //journal stuff
      return 1;
   }
}
*/
