//mtnroad10.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROADOUT"mtnroad9";

void create(){
   ::create();
   set_exits(([
       "gate":ROADOUT"mtnroad9",
       "southeast":ROADOUT"mtnroad11",
   ]));
   set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
   set_door("gate",ROADOUT"mtnroad9","gate",0);
  	dest = ROADOUT"mtnroad9";
}

int GoThroughDoor(){
	if(query_verb() != "gate") {
		if(query_open("gate")) {
			tell_room(TP,"The gate swings shut with an ominous clang just as you move on.\n");
			tell_room(TO,"The gate swings shut of its own volition just as "+TPQCN+" moves on.", TP);
			set_open("gate", 0);
			dest->set_open("gate", 0);
			tell_room(dest, "The gate swings shut with a clang as footsteps fade into the distance.");
		}
		if((newbiep(TP) && TP->query_level() < 5) || avatarp(TP)) {
		tell_room(TP,"Thoughts race through your head as you begin to move on.\n"+
		"Are you sure you're ready to venture beyond and begin the journey"+
		" to join the harsher world?  Perhaps you should turn back and gain"+
		" some more experience in the ways of adventuring first.");
		}
            TP->force_me("more /d/newbie/roadout_warning");
		return 1;
	}	
	return 1;
}
