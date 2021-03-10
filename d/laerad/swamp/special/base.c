//Coded by Bane - base inheritable for swamp rooms//
#include <std.h>
inherit ROOM;
int roll, roll2;

void create(){
   ::create();
   set_terrain(SWAMP);
   set_travel(FRESH_BLAZE);
}

void check_hole();
void init(){
    ::init();
    roll = random(50);
    if(roll < 7){
	if(!interactive(TP)) return 1;
	if(wizardp(TP)) return 1;
	tell_object(TP,"You take a step through the water and right into a hole!");
	TP->do_damage(TP->return_target_limb(), roll_dice(1,2));
	check_hole();
	return 1;
    }
}
void check_hole(){
    roll2 = random(20);
    if(roll2 < 5){
	tell_object(TP,"You sink quickly and disappear into the water!");
	tell_room(TO,TPQCN+" sinks quickly into the water and disappears!",TP);
	TP->do_damage(TP->return_target_limb(),roll_dice(1,2));
	TP->move("/d/laerad/swamp/special/quicksand");
	return 1;
    }
}
