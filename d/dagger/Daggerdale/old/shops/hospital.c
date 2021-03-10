#include <std.h>
#include <money.h>
#include <move.h>

inherit HEALER;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_short("Quincy's Emergency Room"); 
     set_long("You have entered Quincy's Emergency Room. The odors of various "
	    "salves and poultices assault your nose as soon as you enter. "
	    "Though the shop seems a bit disorganized, it is extraordinarily "
        "clean. Many patients lie on cots, as Quincy rushes to tend to "
	    "them all.");
    set_smell("default", "The strong odor of herbs and balms turns your stomach.");
    set_listen("default", "You hear occasional moans and groans from Quincy's patients.");
    set_exits( ([
        "south" : "/d/dagger/Daggerdale/streets/street24",
	] ));
	set_name("Quincy");
}

void reset(){
    ::reset();
//    if(!present("quincy"))
//       find_object_or_load("/d/dagger/Daggerdale/shops/npcs/quincy")->move(TO);
}
