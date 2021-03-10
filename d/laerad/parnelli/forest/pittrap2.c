//Coded by Bane for use with for035.c//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(BARREN);
    set_travel(RUBBLE);
    set_name("Pit trap");
    set_short("Pit trap");
    set_long(
	"You are in a small dirty hole.  The top of the hole is about 10 feet "+
	"above ground.  The floor is littered with corpses and bones of the "+
	"beasts that have died down here.  There are a few wooden spikes that "+
	"were planted into the ground."
    );
    set_property("light",1);
    set_property("indoors",0);
    set_listen("default","The room is completely silent.");
    set_smell("default","Rotting and decaying flesh can be smelled down here.");
}
void init(){
    ::init();
    write("You fall to the ground very hard, landing in the midst of some wooden spikes!");
    TP->do_damage(TP->return_target_limb(),roll_dice(2,10));
    add_action("climb","climb");
}

int climb(string str){
    int roll;
    roll = roll_dice(1,20);
    if((TP->query_skill("athletics")+roll) > 25 || roll == 20){ // DC25 or critical success
      tell_object(TP,"You climb out of the hole.");
      tell_room(ETP,""+TPQCN+" climbs out of the hole.",TP);
      TP->move("/d/laerad/parnelli/forest/for035");
      return 1;
    }
    tell_object(TP,"You climb about half way up then slip and fall!");
    tell_room(ETP,""+TPQCN+" climbs about half way up the wall then slips and falls!",TP);
    TP->do_damage(TP->return_target_limb(),roll_dice(1,10));
    TP->add_attacker(TO);
    return 1;
}