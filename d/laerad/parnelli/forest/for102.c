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
	"that you just don't ever want to leave.  You notice that there are "+
	"alot of leaves covering the ground."
    );
    set_items(([
	({"leaves"}):"There are small piles of leaves near the south and east exits."
    ]));
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for090",
	"east":"/d/laerad/parnelli/forest/for114",
	"north":"/d/laerad/parnelli/forest/for101",
	"south":"/d/laerad/parnelli/forest/for103"
    ]) );
    set_trap_functions(({"east","south"}),({"snare1","snare2"}),({"east","south"}));
}
int snare1(){
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^GREEN%^As you take a step to the east you hear a click under your foot.");
    tell_object(TP,"%^BOLD%^A searing pain runs up your leg as a snare clamps down on it!");
    tell_room(ETO,"%^BOLD%^"+TPQCN+" screams out in pain as a snare clamps down on "+TP->query_possessive()+" leg!",TP);
    TP->do_damage(TP->return_target_limb(),roll_dice(5,10));
    TP->set_paralyzed(20,"You are busy trying to pry the snare open!");
    toggle_trap("east");
    return 1;
    }
}
int snare2(){
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^GREEN%^As you take a step to the south you hear a click under your foot.");
    tell_object(TP,"%^BOLD%^A searing pain runs up your leg as a snare clamps down on it!");
    tell_room(ETO,"%^BOLD%^"+TPQCN+" screams out in pain as a snare clamps down on "+TP->query_possessive()+" leg!",TP);
    TP->do_damage(TP->return_target_limb(),roll_dice(5,10));
    TP->set_paralyzed(20,"You are busy trying to pry the snare open!");
    toggle_trap("south");
    return 1;
    }
}
void reset(){
    ::reset();
    if(!trapped("east")){
	toggle_trap("east");
    }
    if(!trapped("south")){
	toggle_trap("south");
    }
}
