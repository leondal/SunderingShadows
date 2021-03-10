//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("dark road");
    set_short("Dark road");
    set_long(
	"%^BOLD%^A dark road%^RESET%^
You are on a small dark road.  The road leads west back "+
	"towards the central market square and east towards a dark looming "+
	"tower.  You can see the backs of tall buildings and warhouses "+
	"to the north and south.  The sky above is very dark, clouds rolling "+
	"through the atmosphere at an astonishing pace."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_property("no attack",1);
    set_property("no bump",1);
   set_pre_exit_functions( ({"east"}),({"GoThroughDoor"}) );
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","Silence dominates this road.");
*/
    set_exits( ([
//        "east":"/d/laerad/parnelli/asgard/castle01",  was bugging mobs ignoring the pre-exit and trying to go to the non-existent room  *Styx*  4/6/03
	"west":"/d/laerad/parnelli/asgard/as74"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("guard")){
	new("/d/laerad/mon/rguard")->move(this_object());
	new("/d/laerad/mon/rguard")->move(this_object());
    }
}
int GoThroughDoor()
{
    if(present("guard")){
	write("%^MAGENTA%^Guard says%^RESET%^: You cannot enter the tower at this time.");
	return 0;
    }
   write("The tower is not open at this time.");
   return 0;
}
*/