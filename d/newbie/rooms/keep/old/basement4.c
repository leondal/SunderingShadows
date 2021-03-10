#include <std.h>
#include "keep.h"
inherit ROOM;

int FLAG;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A hidden laboratory");
   set_long(
   "This appears to be a mage's laboratory, though it is very old and dusty."+
   " You doubt anyone has been in here in quite some time. The room is"+
   " mostly bare, with a desk and chair in one corner and a large but empty"+
   " iron chest against the eastern wall. There is a large circle carved"+
   " into the center of the floor, as well as a pentagram, making it even"+
   " easier for the mage to create protections. There are a few scorch marks"+
   " about the room, and some claw marks on the floor. You can't even begin"+
   " to imagine what things have been summoned in this room or what spells"+
   " have gone wrong."
   );
   set_smell("default","The room is dusty, with a faint sulfuric tinge.");
   set_listen("default","The silence is complete.");
   set_items(([
   "floor" : "The floor is made of solid stone and is rather dusty. There"+
   " are some scorch marks, and even a few deep claw marks in places. In the"+
   " very center a perfect circle has been carved into the floor, as well as"+
   " a pentagram. This makes it easier for the mage to get the lines for"+
   " protection spells as close to perfect as possible.",
   "ceiling" : "The ceiling is unremarkable. It is made of plain stone and"+
   " has a few scorch marks here and there, and apparently even soot from"+
   " candles that must once have been burning here.",
   ({"walls","wall"}) : "The walls of the room are made of thick, solid"+
   " stone. There is a stone archway on the west that leads back out into"+
   " the hallway.",
   "desk" : "There is a simple wooden desk in the northeastern corner that"+
   " has some rather decayed pieces of parchment on top, along with an ink"+
   " well. That must have been where the mage kept notes.",
   "chair" : "There is a wooden chair next to the desk, though it is so old"+
   " you doubt it could support anyone's weight now.",
   "chest" : "There is a large but apparently empty iron chest on the western wall. Spellbooks or"+
   " components might once have been stored in there.",
   ]));
   set_search("chest",(:TO,"search_chest":));
   set_exits(([
   "west" : ROOMS+"basement2",
   ]));
   if(!random(6)) {
      new(OBJ2+"staff")->move(TO);
   }
   set_post_exit_functions(({"west"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   FLAG = 0;
}

int search_chest(string str)
{
   object obj;
   int num;

   if(FLAG == 1) {
      tell_object(TP,"You search around in the chest but don't seem to find anything.");
      tell_room(ETP,""+TPQCN+" searches the chest.",TP);
      return 1;
   }
   tell_room(ETP,""+TPQCN+" searches the chest.",TP);
   switch(random(8)) {
      case 0:
         str = "powdered silver";
         num = random(3)+1;
         break;
      case 1:
         str = "powdered rhubarb leaf";
         num = random(10)+1;
         break;
      case 2:
         str = "talc";
         num = random(2)+1;
         break;
      case 3:
         str = "pearl";
         num = random(3)+1;
         break;
      case 4:
         str = "phosphorescent moss";
         num = random(3)+1;
         break;
      case 5:
         str = "sulfur";
         num = random(4)+1;
         break;
      case 6:
         str = "piece of iron";
         num = random(15)+1;
         break;
      case 7:
         str = "colored sand";
         num = random(30)+1;
         break;
   }
   tell_object(TP,"You find some "+str+" in the bottom of the chest.");
   obj = new("/d/magic/store_comp.c");
   obj->set_name(str);
   obj->set_id(({str,"component"}));
   obj->set_short(capitalize(str)+" (a spell component)");
   obj->set_long("     "+num+" "+str+""+
   ""+obj->query_long());
   obj->set_comp_quantity(num);
   obj->move(ETP);
   FLAG = 1;
   return 1;
}

int GoThroughDoor()
{
   tell_object(TP,"The stone portal closes behind you.");
   if(member_array("east","/d/newbie/rooms/keep/basement2"->query_exits()) != -1) {
      tell_room("/d/newbie/rooms/keep/basement2","The stone portal closes.");
      "/d/newbie/rooms/keep/basement2"->remove_exit("east");
   }
   return 1;
}
