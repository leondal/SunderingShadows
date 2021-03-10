//Coded by Bane//
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
	"that you just don't ever want to leave.  You notice that there are a "+
	"large number of leaves covering the ground."
    );
    set_items(([
	({"leaves"}):"There are small piles of leaves near the north and east exits."
    ]));
    set_exits( ([
	"southwest":"/d/laerad/parnelli/forest/for027",
	"east":"/d/laerad/parnelli/forest/for046",
	"north":"/d/laerad/parnelli/forest/for034",
	"south":"/d/laerad/parnelli/forest/for036"
    ]) );
    set_trap_functions(({"east","north"}),({"pit_fall1","pit_fall2"}),({"east","north"}));
}
int pit_fall1(){
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^As you attempt to leave the room you walk onto a hidden pit trap!");
    tell_room(ETP,"%^BOLD%^"+TPQCN+" starts to walk away then disappears into the ground!",TP);
    TP->move("/d/laerad/parnelli/forest/pittrap1");
    toggle_trap("east");
    return 1;
    }
}
int pit_fall2(){
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^As you try to leave the room you walk onto a hidden pit trap!");
    tell_room(ETP,"%^BOLD%^"+TPQCN+" starts to walk away then disappears into the ground!",TP);
    TP->move("/d/laerad/parnelli/forest/pittrap2");
    toggle_trap("north");
    return 1;
    }
}
void reset(){
    ::reset();
    if(!trapped("north")){
	toggle_trap("north");
    }
    if(!trapped("east")){
	toggle_trap("east");
    }
}
