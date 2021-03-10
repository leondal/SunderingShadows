#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark dreary cave. The ceiling hangs very low, "+
	"you have to hunch over to avoid hitting your head. This room has "+
	"an overabundance of bugs. Spiders, centipedes, beetles, and other "+
	"various insects covers the floor and walls. With the dim lighting it "+
	"almost seems as if the cave itself lives."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The smell of decaying flesh drifts through the cavern.");
    set_listen("default","Squirming insects can be heard from all over the cave.");
    set_exits( ([
	"west":"/d/tharis/caverns/cavern21",
	"north":"/d/tharis/caverns/cavern25"
    ]) );
}
void init(){
    ::init();
    add_action("bugs","look");
}
int bugs(string str){
    if(!str || str !="at bugs") return 0;
    tell_object(TP,"You bend over to take a close look at the insects and they swarm onto your body!");
    TP->do_damage("torso",roll_dice(2,10));
    tell_room(environment(TP),""+TP->query_cap_name()+" bends over to look at the insects and they swarm onto "+TP->query_possessive()+" body!",TP);
    tell_object(TP,"You quickly beat them off of you!");
    tell_room(environment(TP),""+TP->query_cap_name()+" quickly beats the insects off of "+TP->query_possessive()+" body!",TP);
	return 1;
}
