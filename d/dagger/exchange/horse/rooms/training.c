#include <std.h>
#include "../horse.h"

inherit ROOM;

object horse_edit, buyer;
int open_race, current_race_id;

void init() {
    ::init();
    add_action("buy_horse", "buy");
	add_action("train_horse", "train");
	add_action("reset_training", "reset_the_training");
	add_action("research_stuff", "research");
	add_action("kill_a_horse", "disown");
	add_action("reinvest", "reinvest");
	add_action("withdraw", "withdraw");

    horse_edit =find_object_or_load(STORAGE"horse_edit.c");
}

void reset()
{
    ::reset();
    if(!present("sign")){
        new(OBJ"sign2.c")->move(TO);
    }
    if(!present("master trainer")){
        new(MOBS"master_trainer.c")->move(TO);
    }
}

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
	set_property("light",2);
    set_name("owners lobby");
    set_short("%^RESET%^%^ORANGE%^owners lobby%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^this room is quieter then the betting parlor but only "+
	"by a small margin. Trainers run back and forth looking at their books and speaking "+
	"with the master trainer to go to the courses themselves and various horse owners "+
	"speaking amongst themselves. A group of comfortable chairs are arranged near some "+
	"manuals set out on a table and a desk with a clerk is off to the western wall where "+
	"horses are bought.\n%^RESET%^");
	open_race = 0;	
	current_race_id = 0;
    set_exits(([
    "north" : ROOMS"hall",
    ]));
    set_items(([
        ({"walls"}) : "%^ORANGE%^The walls here are bare and panelled in fine wood.",
        ({"ceiling"}) : "T%^RESET%^%^ORANGE%^he ceiling rises high above you, the "+
        "rafters large enough to be keels of galleons.%^RESET%^",
        ({"floor"}) : "%^RESET%^%^ORANGE%^The hardwood floor here spotless.%^RESET%^",
        ({"chandeliers"}) : "%^BLACK%^%^BOLD%^three chandeliers hang from the ceiling, "+
        "providing light through %^RESET%^%^ORANGE%^numerous candles%^RESET%^",
		({"manuals"}) : "%^RESET%^%^ORANGE%^Set out on a private table, "+
		"several manuals about how to train your horse are arranged. People leaf "+
		"through them as they sit on comfortable couches",
    ]));

set_smell("default","%^BLACK%^%^BOLD%^The air is filled with acrid pipe smoke.%^RESET%^");
set_listen("default","The whole area is filled with the calls of those betting on horses.");
	
}

void research_stuff(string str)
{
    if(!str){
	    tell_object(TP,"%^RESET%^%^ORANGE%^You can't research that here. "+
	"Try either %^BOLD%^'speed'%^RESET%^%^ORANGE%^ %^YELLOW%^"+
	"'acceleration'%^RESET%^%^ORANGE%^ or %^BOLD%^'jockey'%^RESET%^\n");
        return 1;
    }
	if(str == "jockey"){
	    tell_object(TP,"%^RESET%^%^ORANGE%^You flip through the manual until you "+
		"come to the section on training your jockey.\n\n%^YELLOW%^Jockey%^RESET%^"+
		"\n\n%^ORANGE%^Horses get quite attached to their jockey and the jockey "+
		"creates a bond with the horse. We have already chosen the best jockey "+
		"available for your horse so its up to you to provide them resources to "+
		"get better at the job. A jockey is important for ensuring the horse is "+
		"running as best as they can, and especially for dealing with dangers on "+
		"the track. A good jockey can not only steer away from danger, but create "+
		"situations where the other horses are put into danger.\n%^RESET%^");
		        return 1;
	}
	
	if(str == "speed"){
	    tell_object(TP,"%^RESET%^%^ORANGE%^You flip through the manual until you "+
		"come to the section on training your horse for speed.\n\n%^YELLOW%^Speed"+
		"%^RESET%^\n\n%^ORANGE%^The core to a good race horse is of course how fast "+
		"they can run. Training your horse for speed helps it maintain a top speed "+
		"longer and is key for winning long races. A slow race horse won't see "+
		"the winner's circle many times.\n%^RESET%^");
		        return 1;
	}
	
	if(str == "acceleration"){
	    tell_object(TP,"%^RESET%^%^ORANGE%^You flip through the manual until you "+
		"come to the section on training your horse for acceleration.\n\n%^YELLOW%^"+
		"Acceleration%^RESET%^\n\n%^ORANGE%^Having a fast horse sometimes isn't "+
		"enough. Training your horse for a quick start can be even more "+
		"important then it's top speed as it will have the opportunity to "+
		"leap ahead of the pack and avoid danger and win shorter races.\n%^RESET%^");
		        return 1;
	}

    tell_object(TP,"%^RESET%^%^ORANGE%^You can't research that here. "+
	"Try either %^BOLD%^'speed'%^RESET%^%^ORANGE%^ %^YELLOW%^"+
	"'acceleration'%^RESET%^%^ORANGE%^ or %^BOLD%^'jockey'%^RESET%^\n");
	    return 1;	
	
}

int buy_horse(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");
    if(!str) {
        return 0;
    }
    if(str != "horse"){
        tell_object(TP,"buy what?\n");
        return 1;
    }
            horse_edit->add_horse_name();
            return 1;
			
}

int kill_a_horse(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");
    if(!str) {
        tell_object(TP,"%^RESET%^%^RED%^disown what? Do you want to '%^BOLD%^disown horse%^RESET%^%^RED%^'?\n");
		return 1;
    }
    if(str != "horse"){
        tell_object(TP,"%^RESET%^%^RED%^disown what? Do you want to '%^BOLD%^disown horse%^RESET%^%^RED%^'?\n");
        return 1;
    }
            horse_edit->kill_a_horse();
            return 1;
			
}

int reset_training(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");

	horse_edit->clear_all_training();
            return 1;
			
}

int reinvest(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");

	horse_edit->reinvest();
            return 1;
			
}

int withdraw(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");

	horse_edit->withdraw1();
            return 1;
			
}

int train_horse(string str)
{
    object horse_edit;
    horse_edit =find_object_or_load(STORAGE"horse_edit.c");
    if(!str) {
        tell_object(TP,"%^RESET%^%^ORANGE%^train what? Do you want to '%^BOLD%^train horse%^RESET%^%^ORANGE%^'?%^RESET%^\n");
        return 1;
    }
    if(str != "horse"){
        tell_object(TP,"%^RESET%^%^ORANGE%^train what? Do you want to '%^BOLD%^train horse%^RESET%^%^ORANGE%^'?%^RESET%^\n");
        return 1;
    }
            horse_edit->train_horse();
            return 1;
			
}
