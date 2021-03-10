//ccenter Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;

//void pick_critters();



void create() {
 //   pick_critters();
    set_repop(50);
    ::create();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("Gnoll main camp");
    set_short("%^ORANGE%^gnoll main camp%^RESET%^");
    set_long("%^GREEN%^You are standing in what must be the %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls' "+
	"%^GREEN%^main-camp%^YELLOW%^. %^RESET%^%^GREEN%^A multitude of huts and crude leather tents litter the whole "+
	"area. The smell and sounds of %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^BOLD%^%^BLACK%^'%^RESET%^%^ORANGE%^communicating%^BOLD%^%^BLACK%^' %^RESET%^%^GREEN%^can be heard from "+
	"other places in the camp. Luckily the %^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^ts %^RESET%^%^GREEN%^and "+
	"%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nts %^RESET%^%^GREEN%^provide ample cover to move around unnoticed. "+
	"Often a %^BOLD%^%^BLACK%^fight %^RESET%^%^GREEN%^between two %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^GREEN%^or some %^CYAN%^poor victim %^GREEN%^of their appetite can be heard%^ORANGE%^, %^GREEN%^muffling out the "+
	"sound yo%^RED%^u %^GREEN%^might make%^YELLOW%^. %^RESET%^%^GREEN%^Walking around the camp one will have to watch "+
	"their steps%^YELLOW%^. %^RESET%^%^MAGENTA%^H%^RED%^a%^MAGENTA%^lf-e%^RED%^a%^MAGENTA%^ten %^CYAN%^victims %^GREEN%^of "+
	"various races lay spread all over the ground in various degrees of %^MAGENTA%^decomposition%^YELLOW%^.%^RESET%^\n");
	
    set_smell("default","%^ORANGE%^It smells badly of %^RED%^r%^MAGENTA%^o%^RED%^tt%^MAGENTA%^e%^RED%^n fl%^MAGENTA%^e%^RED%^sh %^ORANGE%^and %^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ly m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^sk%^RESET%^");
    set_listen("default","%^ORANGE%^You hear %^BOLD%^%^BLACK%^gnolls f%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ght%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^communicating %^RESET%^%^ORANGE%^all around you%^BOLD%^%^BLACK%^.%^RESET%^");

	set_exits(([
      "east":ROOMS"24",
	  "west" : ROOMS"22",
      "north" : ROOMS"28",
	  "south" : ROOMS"18"
   ]));
    set_items
    (([	
        ({"floor", "ground", "outcroppings"}) : "%^ORANGE%^The ground is littered with %^WHITE%^b%^BOLD%^o%^RESET%^nes %^ORANGE%^and %^MAGENTA%^rubbish %^ORANGE%^thrown from the huts. Tread carefully!%^RESET%^",
        ({"hut", "huts", "tent", "tent"}) : "%^ORANGE%^These living quarters of the gnolls offer little protection from the %^BOLD%^elements%^RESET%^%^ORANGE%^. But it is still roof over the head. Most of the huts don't even have doors.%^RESET%^ ",
        ({"dog", "dogs", "dog houses", "dog house"}) : "%^ORANGE%^These huts or houses are just as crude and primitive as the rest but they are still different. They are empty except for rotten meat in some of them.%^RESET%^",
		({"victim","victims","corpse","corpses"}):"%^ORANGE%^The half eaten victims seem to be of almost any race the gnolls have been able to catch. The majority consist of %^BOLD%^Thri-kreen %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^humans.%^RESET%^",
	]));
	
	set_search("hut","There is one hut here that is much larger than the other huts. Perhaps it would be worthwhile to enter the hut?");
	
	}

	void reset(){
   ::reset();
   if(!present("bloodfang")){new(MOBS"bloodfang")->move(TO);}
   switch(random(6)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnoll's victims can he hear from somewhere in the camp.");
               break;
         }
}
	
	
void init(){
		::init();
		add_action("enter","enter");
}

int enter(string str){
	if(!str){notify_fail("What do you want to enter?"); return 0;}
	if(str != "hut"){notify_fail("You cannot enter that"); return 0;}
	tell_object(TP,"You enter the large hut.");
	tell_room(ETP,TP->QCN+" enters the large hut.",TP);
	TP->move(ROOMS"hut");
	TP->describe_current_room(1);	
	return 1;
}
	
//void pick_critters(){
//   switch(random(6)){
//        case 0:   set_monsters(
//({MOBS" ",MOBS" "}),({random(2),random(2)}) );
//                   break;
//         case 1:   set_monsters(
//({MOBS"",MOBS""}),({random(2),random(1)}) );
//                   break;
//         case 2:   set_monsters(
//({MOBS"",MOBS""}),({1,random(1)+1,random(2)}) );
//                   break;
//         case 3:   set_monsters(
//({MOBS"",MOBS"",MOBS""}),({random(3),1,1}) );
//                   break;
//         case 4..5: break;
//   }
//}
