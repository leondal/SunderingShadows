//Coded by Bane//
//added pre-exits to keep Commandos in to eliminate the need for their wander
//inherit - Styx 12/29/01  Changed commando wandering - Styx 1/12/02

#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";

void create(){
    ::create();
    set_long(
	"%^BOLD%^GREEN%^The Parnelli Forest%^RESET%^\n"+
	"You have walked into a magical forest.  The trees sway back and forth "+
	"as if hypnotized.  Leaves dance around happily in the wind.  The brush "+
	"looks as if it is glowing with pure energy.  You notice the occasional "+
	"firefly or pixie flitter through the air.  The sky above is the most "+
	"beautiful blue you have ever seen.  You feel such a serene peace here "+
	"that you just don't ever want to leave.  The city of Asgard is to "+
	"the west."
    );
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for081",
	"west":"/d/laerad/parnelli/asgard/as59"
    ]) );
//    set_pre_exit_functions( ({"east"}),({"GoThroughDoor"}) );
}
/*
int GoThroughDoor(){
    if(TP->id("commando"))  return 0;
    return 1;
}
*/