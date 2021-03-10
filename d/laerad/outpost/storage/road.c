//coastline Template  - Essyllis - 04-2015


#include <std.h>
#include "../outpost.h"


inherit CROOM;

object ob;



void create() {


    set_repop(45);
    ::create();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("outpostroad");
    set_short("%^ORANGE%^outpost road%^RESET%^");
    set_long("%^ORANGE%^Walking between the unfinished buildings you are protected from the "+
	"%^CYAN%^howling winds %^ORANGE%^which normally dominate this island. Even the smell of "+
	"%^BOLD%^sawdust %^RESET%^%^ORANGE%^and %^BOLD%^fresh wood %^RESET%^%^ORANGE%^helps to make "+
	"the island smell more bearable. Small fences have been made to mark the building areas for "+
	"the different buildings as well as make sure people are out of harms way if a building accident should occur.%^RESET%^\n");
	
    set_smell("default","%^RESET%^%^ORANGE%^The smell resembling %^BOLD%^rotten eggs%^RESET%^%^ORANGE%^ are not nearly as bad here by the ocean.");
    set_listen("default","%^RESET%^You hear %^BOLD%^%^BLACK%^construction noises%^RESET%^ over the constant %^CYAN%^howling of the wind.%^RESET%^");

    set_items
    (([	
        ({"floor", "ground"}) : "The ground here is made from grounded rocks which provides good stability for heavy loaded carts.",
        ({"building", "buildings", "houses", "house"}) : "Most of all the buildings here are half-finished. Some even just a skeletal frame. Only a few stands complete.",
		
	]));

	}

	
void reset(){
   ::reset();

	if(random(1000)<200){
		if(!present("worker")){new(MOBS"worker")->move(TO);}
	}
	if(random(1000)<200){
		if(!present("guard")){new(MOBS"outpostguard")->move(TO);}
	}
   switch(random(6)){
      case 0..2:  tell_room(TO,"%^MAGENTA%^There is a constant calling and yelling from the constructions crew.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^The constant sounds of %^BOLD%^%^BLACK%^construction work%^RESET%^%^ORANGE%^ is almost soothing compared to the howling winds");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A steady stream of %^YELLOW%^carts%^BLACK%^ with %^RESET%^%^ORANGE%^building materials%^BOLD%^%^BLACK%^ or %^RESET%^%^GREEN%^food %^BOLD%^%^BLACK%^and %^CYAN%^water%^BLACK%^ is going either to or from the docks.");
               break;
         }
}
