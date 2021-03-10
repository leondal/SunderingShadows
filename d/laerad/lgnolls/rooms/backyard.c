//backyard  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;
int searchx;

void create() {

    set_repop(70);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	searchx = 0;
	set_property("outdoor",1);
    set_property("light",1);
    set_name("backyard");
    set_short("Gnoll backyard.");
    set_long("%^ORANGE%^This is probably a backyard belonging to one of the more important members "+
	"of the pack. For everyone else this is a place of %^RED%^death%^ORANGE%^. The ground is soaked "+
	"with %^RED%^blood %^ORANGE%^and has transformed the soil into %^BOLD%^%^BLACK%^st%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^RED%^y "+
	"%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^. %^WHITE%^B%^BOLD%^o%^RESET%^n%^BOLD%^e%^RESET%^s %^ORANGE%^with "+
	"%^MAGENTA%^r%^GREEN%^o%^MAGENTA%^tt%^GREEN%^i%^MAGENTA%^ng m%^GREEN%^ea%^MAGENTA%^t-scr%^GREEN%^a%^MAGENTA%^ps %^ORANGE%^are littered all "+
	"over the place and the place %^GREEN%^sm%^RED%^e%^GREEN%^lls %^ORANGE%^absolutely %^GREEN%^r%^RED%^a%^GREEN%^nc%^RED%^i%^GREEN%^d%^ORANGE%^!"+
	" The air is alive with %^MAGENTA%^flies %^ORANGE%^buzzing all over the place. All non-edible items have been collected in a huge pile "+
	"standing nearly 5 feet tall in the corner of this grizzly backyard, but besides that there is nothing but %^RED%^blood-splattered %^ORANGE%^walls "+
	"and the %^CYAN%^sky %^ORANGE%^above you.%^RESET%^\n");
    set_smell("default","%^RED%^It smells badly of death and decay!%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^There is a constant buzzing from the swarms of flies.%^RESET%^");
	set_exits((["hut":ROOMS"hut"]));
    set_items
    (([	
        ({"floor", "ground"}) : "%^RED%^The earth here is mushy and soaked with blood. Even the grass has a red taint to it.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The outer-walls of the surrounding huts makes this backyard a closed off slaughter pit.",
        ({"pile","items"}) : "%^MAGENTA%^This pile is almost 5 feet tall containing various non-edible items, such as broken armors, clothings, weapons, and building materials. Nothing looks to be really useable at first glance.",	
    ]));
	
	set_search("ladder","%^MAGENTA%^This ladder looks useful, perhaps you should 'take' it with you.");
	set_search("pile",(:TO,"pilez":));
	set_search("items",(:TO,"pilez":));
	
	
}	

void reset(){
   ::reset();
   searchx=0;
   switch(random(5)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnolls' victims can he hear from somewhere in the camp.");
               break;
         }
}



string pilez(){
	if(searchx){
		write("%^ORANGE%^The pile mostly contains a lot of useless or destroyed items.");
	return 1;}
	write("%^ORANGE%^The pile mostly contains a lot of useless or destroyed items. But you also find a collapsible ladder in very good condition.");
	return 1;}

void init(){
		::init();
		
	add_action("take","take");
}	
		
int take(string str){
	if(!str){notify_fail("What do you want to take?"); return 0;}
	if(str != "ladder"){notify_fail("That you cannot take with you"); return 0;}
	if(searchx){notify_fail("If there ever were a ladder here, it is gone now."); return 0;}
	searchx=1;
	tell_object(TP,"%^MAGENTA%^You take the ladder out from the pile of items and put it on the ground.");
	tell_room(ETP,TP->QCN+" %^MAGENTA%^takes a ladder out of the pile of items and puts it on the ground.",TP);
	new(OBJ"ladder")->move(TO);
	return 1;
}



