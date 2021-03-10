//tomb  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;
int lanternx;

void create() {
//    pick_critters();
    set_repop(70);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	lanternx=0;
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_name("Grave room");
    set_short("Gnoll grave room.");
    set_long((:TO,"long_desc":));
    set_smell("default","%^RED%^It smells badly of death and decay!%^RESET%^");
    set_listen("default","%^GREEN%^It is so silent that the bugs crawling around makes more sound than your own breathing.%^RESET%^");
	set_exits((["up":ROOMS"20"]));
    set_items
    (([	
        ({"floor", "ground"}) : "Gnoll corpses lie scattered all around. Not very burial like. And all of them in full armor and weapons.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls are made from polished granite, impossible to climb.",
        ({"ladder"}) : "%^GREEN%^ The ladder is still here. Thankfully!",
		({"northern wall"}) : "There is a shadow on the northen wall. It appears like a metal rod protruding from the wall. Perhaps you should search the wall more closely?"
    ]));
	
	set_search("floor","%^MAGENTA%^That sticky stuff on the floor .. It is dried blood! Could this be a scene of a battle more than just a grave?");
	set_search("corpse","All these gnoll corpses. They weren't just thrown down here. There are obvious signs of combat on all of them.");
	set_search("walls","You admire the smoothness of the walls, someone really spend a lot of energy on this ... You notice a shadow on the northern wall.");
	set_search("northern wall","It looks to be a lantern hanger. It has the %^BOLD%^%^ORANGE%^sigil of Asgard %^RESET%^on it.");
	
}	




void init(){
	::init();
	add_action("hang","hang");
}

int hang(string str){
	object lanternobj;
	lanternobj = present("lantern",TP);
	if(str != "lantern onto hanger"){notify_fail("Hang what onto where?"); return 0;}
	if(lanternx){notify_fail("It looks like the lantern is already hanging on the hanger."); return 0;}
	if(!objectp(lanternobj)){ notify_fail("You don't have a lantern."); return 0;}
	if(base_name(lanternobj) != OBJ"lantern"){notify_fail("This lantern doesn't seem to fit onto the hanger."); return 0;}
	lanternx=1;
	tell_object(TP,"%^BOLD%^%^BLACK%^As you hang the %^ORANGE%^lantern %^BLACK%^onto the hanger, the northern wall %^MAGENTA%^sh%^CYAN%^i%^MAGENTA%^mm%^CYAN%^e%^MAGENTA%^rs %^BLACK%^and %^RESET%^%^CYAN%^disappears!");
	tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TP->QCN+" hangs the %^ORANGE%^lantern %^BLACK%^onto the hanger, the northern wall %^MAGENTA%^sh%^CYAN%^i%^MAGENTA%^mm%^CYAN%^e%^MAGENTA%^rs %^BLACK%^and %^RESET%^%^CYAN%^disappears!",TP);
	set_exits((["up":ROOMS"20","north":ROOMS"d2"]));
	lanternobj->remove();
	tell_object(TP,"%^BOLD%^%^BLACK%^You suddenly hear movement behind you. As you turn you see a %^RESET%^%^ORANGE%^Gr%^BOLD%^a%^RESET%^%^ORANGE%^n%^BOLD%^i%^RESET%^%^ORANGE%^te G%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^m %^BOLD%^%^BLACK%^emerging from %^RESET%^%^ORANGE%^the wall%^BOLD%^%^BLACK%^!");
	tell_room(ETP,"%^BOLD%^%^BLACK%^You suddenly hear movement behind you. As you turn you see a %^RESET%^%^ORANGE%^Gr%^BOLD%^a%^RESET%^%^ORANGE%^n%^BOLD%^i%^RESET%^%^ORANGE%^te G%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^m %^BOLD%^%^BLACK%^emerging from %^RESET%^%^ORANGE%^the wall%^BOLD%^%^BLACK%^!",TP);
	new(MOBS"golem")->move(TO);
		return 1;}
	

string long_desc(){
	
	if(lanternx){
	return("%^BOLD%^%^BLACK%^This appears to be a %^RESET%^%^RED%^mass-grave %^BOLD%^%^BLACK%^for the "+
	"%^RESET%^%^ORANGE%^gnolls%^BOLD%^%^BLACK%^. Down here you can see that the hole is a square of "+
	"%^RESET%^60 %^BOLD%^%^BLACK%^times %^RESET%^60 %^BOLD%^%^BLACK%^feet. The ground is littered with "+
	"%^RESET%^%^RED%^corpses %^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^gnolls%^BOLD%^%^BLACK%^. Most of "+
	"the %^RESET%^%^RED%^corpses %^BOLD%^%^BLACK%^seem to have been here for quite a while with "+
	"%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^s %^BOLD%^%^BLACK%^picked "+
	"almost clean by %^RESET%^%^MAGENTA%^bugs %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^creeps%^BOLD%^%^BLACK%^. "+
	"Some of the %^RESET%^%^RED%^corpses %^BOLD%^%^BLACK%^are slightly fresher but still at least a "+
	"few months old. The floor here is %^GREEN%^s%^BLACK%^t%^GREEN%^i%^BLACK%^ck%^GREEN%^y %^BLACK%^and "+
	"%^GREEN%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^GREEN%^i%^RESET%^%^MAGENTA%^v%^BOLD%^%^GREEN%^e %^BLACK%^with "+
	"%^RESET%^%^MAGENTA%^maggots%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^beetles %^BOLD%^%^BLACK%^and "+
	"%^RESET%^%^MAGENTA%^other bugs%^BOLD%^%^BLACK%^. The %^RESET%^walls %^BOLD%^%^BLACK%^however are"+
	"made of %^RESET%^%^ORANGE%^gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^CYAN%^e "+
	"%^RESET%^%^ORANGE%^br%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^cks %^BOLD%^%^BLACK%^and "+
	"%^RESET%^p%^BOLD%^o%^RESET%^l%^BOLD%^i%^RESET%^sh%^BOLD%^e%^RESET%^d sm%^BOLD%^oo%^RESET%^th%^BOLD%^%^BLACK%^, "+
	"not something a %^RESET%^%^ORANGE%^gnoll %^BOLD%^%^BLACK%^would concern itself with. The only exits "+
	"seem to be upwards using the ladder you used to get down here with, and now also %^BLUE%^north "+
	"%^BLACK%^as the %^CYAN%^i%^RESET%^%^CYAN%^ll%^BOLD%^u%^RESET%^%^CYAN%^s%^BOLD%^i%^RESET%^%^CYAN%^on "+
	"%^BOLD%^%^BLACK%^of the wall has been %^RESET%^%^CYAN%^dispelled%^BOLD%^%^BLACK%^.%^RESET%^\n");
	}
	
	return("%^BOLD%^%^BLACK%^This appears to be a %^RESET%^%^RED%^mass-grave "+
	"%^BOLD%^%^BLACK%^for the %^RESET%^%^ORANGE%^gnolls%^BOLD%^%^BLACK%^. Down "+
	"here you can see that the hole is a square of %^RESET%^60 %^BOLD%^%^BLACK%^times "+
	"%^RESET%^60 %^BOLD%^%^BLACK%^feet. The ground is littered with %^RESET%^%^RED%^corpses "+
	"%^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^gnolls%^BOLD%^%^BLACK%^. Most of the "+
	"%^RESET%^%^RED%^corpses %^BOLD%^%^BLACK%^seem to have been here for quite a "+
	"while with %^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^s "+
	"%^BOLD%^%^BLACK%^picked almost clean by %^RESET%^%^MAGENTA%^bugs %^BOLD%^%^BLACK%^and "+
	"%^RESET%^%^MAGENTA%^creeps%^BOLD%^%^BLACK%^. Some of the %^RESET%^%^RED%^corpses "+
	"%^BOLD%^%^BLACK%^are slightly fresher but still at least a few months old. The floor "+
	"here is %^GREEN%^s%^BLACK%^t%^GREEN%^i%^BLACK%^ck%^GREEN%^y %^BLACK%^and "+
	"%^GREEN%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^GREEN%^i%^RESET%^%^MAGENTA%^v%^BOLD%^%^GREEN%^e "+
	"%^BLACK%^with %^RESET%^%^MAGENTA%^maggots%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^beetles "+
	"%^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^other bugs%^BOLD%^%^BLACK%^. The %^RESET%^walls "+
	"%^BOLD%^%^BLACK%^however are made of %^RESET%^%^ORANGE%^gr%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^CYAN%^e "+
	"%^RESET%^%^ORANGE%^br%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^cks %^BOLD%^%^BLACK%^and "+
	"%^RESET%^p%^BOLD%^o%^RESET%^l%^BOLD%^i%^RESET%^sh%^BOLD%^e%^RESET%^d sm%^BOLD%^oo%^RESET%^th%^BOLD%^%^BLACK%^, "+
	"not something a %^RESET%^%^ORANGE%^gnoll %^BOLD%^%^BLACK%^would concern itself with. "+
	"The only exit seem to be upwards using the ladder you used to get down here with.%^RESET%^\n");
	
}

void reset(){
   ::reset();
   lanternx=0;
   switch(random(6)){
     case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^The granite flakes in the walls %^BOLD%^%^WHITE%^shimmers%^BLACK%^ in the dim light");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^You hear noise from the guard room high above you");
               break;
      case 5:  tell_room(TO,"%^MAGENTA%^A loud %^BOLD%^%^BLACK%^CRACK %^RESET%^%^MAGENTA%^comes from one of the granite walls. But there are no damage to be seen anywhere");
               break;
			   }
}


//void pick_critters(){
//   switch(random(6)){
//         case 0:   set_monsters(
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

