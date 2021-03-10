#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

int CHEST, CIRCLE;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A hidden laboratory");
   set_short("%^RESET%^%^ORANGE%^A hidden laboratory%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A hidden laboratory%^RESET%^\n"
"This appears to have once been a wizard's laboratory, though it has long since been "
"abandoned.  The room is mostly bare, with a %^RED%^desk %^RESET%^and %^RED%^chair "
"%^RESET%^in one corner and a large iron %^BLUE%^chest %^RESET%^against the eastern "
"wall.  Taking up most of the floor space is a large %^BOLD%^%^CYAN%^circle %^RESET%^"
"enclosing a pentagram, all of which is actually carved into the stone floor.  There "
"are a few scorched %^RED%^marks %^RESET%^about the room and across the %^BLUE%^walls"
"%^RESET%^ and %^ORANGE%^ceiling%^RESET%^, and some claw marks on the %^BLUE%^floor"
"%^RESET%^, leaving your imagination to run wild as to what could have happened here"
".\n");
   set_smell("default","The room smells stale, with a faint sulfuric tinge.");
   set_listen("default","The silence is eerie.");
   set_items(([
     "floor" : ((:TO,"floor_desc":)),
     ({"ceiling","roof"}) : "%^ORANGE%^The ceiling is fairly unremarkable. It is "
"made of plain stone and has a few scorch marks here and there, and apparently even "
"soot from candles that must once have been burnt here.%^RESET%^",
     ({"walls","wall"}) : "%^BLUE%^The walls of the room are made of thick, solid "
"stone that has been marred in some places by scorch marks.  There is a stone "
"archway within the western wall that leads back out into the hallway.",
     "desk" : "%^RED%^There is a simple wooden desk in the northeastern corner that "
"has some rather decayed pieces of parchment on top, along with a dried-up ink well"
".%^RESET%^",
     "chair" : "%^RED%^There is a simple wooden chair next to the desk, though it is "
"so old and fragile you doubt it could support anyone's weight now.%^RESET%^",
     ({"marks","scorches","scorched marks","claw marks"}) : "%^RED%^Scorch marks are "
"scattered across the walls, ceiling and floor, testament to some previous violence "
"or accident perhaps.  Light scratches mar the floor in places, making you wonder what "
"sort of creature might have left them.%^RESET%^",
     "chest" : ((:TO,"chest_desc":)),
     ({"circle","pentagram"}) : ((:TO,"circle_desc":)),
   ]));
   set_search("default","%^GREEN%^You take a close look around the room.  The only "
"things that appear to be of any interest are the iron chest, and the circle upon "
"the floor.%^RESET%^");
   set_search("chest",(:TO,"search_chest":));
   set_exits(([
     "west" : ROOMS+"basement2",
   ]));
   set_post_exit_functions(({"west"}),({"GoThroughDoor"}));
}

void reset() {
   ::reset();
   CHEST = 0;
   CIRCLE = 0;
}

void init() {
   ::init();
   add_action("complete_fun","complete");
}

int search_chest(string str) {
   object obj;
   int num;

   if(CHEST) {
      tell_object(TP,"%^BLUE%^You look through the chest, but it seems to be empty "
"of anything of value.%^RESET%^");
      tell_room(ETP,"%^BLUE%^"+TPQCN+" searches the chest, but it seems to be empty"
".%^RESET%^",TP);
      return 1;
   }
   tell_room(ETP,"%^BLUE%^"+TPQCN+" searches the chest and seems to find a few things.%^RESET%^",TP);
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
         str = "rose petals";
         num = random(15)+1;
         break;
   }
   tell_object(TP,"%^CYAN%^You find some "+str+" in the chest.%^RESET%^");
   obj = new("/d/magic/store_comp.c");
   obj->set_name(str);
   obj->set_id(({str,"component"}));
   obj->set_short(capitalize(str)+" (a spell component)");
   obj->set_long("     "+num+" "+str+""+
   ""+obj->query_long());
   obj->set_comp_quantity(num);
   obj->move(ETP);
   CHEST = 1;
   return 1;
}

int GoThroughDoor() {
   object *kritters;
   kritters = ({});
   kritters = all_living(TO);
   if(!sizeof(kritters)) {
     tell_object(TP,"The stone portal closes behind you.");
     if(member_array("east",ROOMS"basement2"->query_exits()) != -1) {
       tell_room(ROOMS"basement2","The stone portal closes.",TP);
        ROOMS"basement2"->remove_exit("east");
        ROOMS"basement2"->reset_stone();
     }
   }
   return 1;
}

string floor_desc() {
   if(!TP->is_class("mage")) return("%^BLUE%^The floor is made of solid stone and "
"is covered in a thin layer of dust.  There are some scorch marks scattered around, "
"and even a few deep claw marks in places.  In the very center a perfect circle "
"has been carved into the floor, enclosing a pentagram.%^RESET%^");
   return("%^BLUE%^The floor is made of solid stone and is covered in a thin layer "
"of dust.  There are some scorch marks scattered around, and even a few deep claw "
"marks in places.  In the very center a perfect circle has been carved into the "
"floor, enclosing a pentagram.  You recognize it as a wizard's summoning "
"circle.%^RESET%^");
}

string chest_desc() {
   if(CHEST) return("%^BLUE%^There is a large iron chest on the western wall, "
"perhaps where the wizard kept his spellbooks or components.  Unfortunately, it "
"seems to be empty of everything except the decaying remnants of a few "
"tomes.%^RESET%^");
   return("%^BLUE%^There is a large iron chest on the western wall, perhaps "
"where the wizard kept his spellbooks or components.  Perhaps if you "
"%^YELLOW%^search %^RESET%^%^BLUE%^through it, you might find something "
"valuable?%^RESET%^");
}

string circle_desc() {
   string myreturn;
   myreturn = "%^CYAN%^In the very center of the floor has been carved a perfect "
"circle, enclosing a pentagram.";
   if(TP->is_class("mage")) myreturn += "  You can tell from your studies that "
"this is a lesser summoning circle, that when complete would call forth a minor "
"creature of the planes.";
   if(CIRCLE) myreturn += "  The circle is filled with fine glittering dust, and "
"seems to have been recently completed, judging by the fresh scorches and claw marks "
"in the immediate vicinity.  Who knows what may have come out of it...%^RESET%^";
   else myreturn += "  The circle is filled with fine glittering dust, but seems "
"incomplete, with a small portion of the carved shape still empty.  Perhaps you "
"could %^YELLOW%^complete the circle%^RESET%^%^CYAN%^, if you dared, but who knows "
"what might come out...%^RESET%^";
   return myreturn;
}

int complete_fun(string str) {
   if(!str) return notify_fail("What do you want to complete?\n");
   if(str != "the circle") return notify_fail("You can't complete that.\n");
   if(CIRCLE) {
     tell_object(TP,"%^YELLOW%^The circle seems to have been already completed, "
"and recently at that.%^RESET%^");
     return 1;
   }
   CIRCLE = 1;
   tell_object(TP,"%^CYAN%^You reach down and smudge some of the "
"%^BOLD%^glittering dust %^RESET%^%^CYAN%^across the empty portion of the "
"circle.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" reaches down and smudges some of the "
"%^BOLD%^glittering dust %^RESET%^%^CYAN%^across the empty portion of the "
"circle.%^RESET%^",TP);
   tell_room(TO,"%^BOLD%^%^WHITE%^The circle and enclosed pentagram flare "
"brightly with %^YELLOW%^light%^WHITE%^, nearly blinding you.  You're forced to "
"blink and turn away as the air takes on an %^CYAN%^i%^WHITE%^c%^CYAN%^y "
"%^WHITE%^chill, and by the time you turn back there is a creature standing in "
"the circle.  It snarls and lunges forward in attack!%^RESET%^");
   new(MONS"imephit")->move(TO);
   return 1;
}
