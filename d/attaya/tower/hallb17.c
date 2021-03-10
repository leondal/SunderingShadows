
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
	set_name("Arrrrgh Death, man");
	set_short("A dark presentation stage");
	set_property("indoors",1);
	set_property("light",1);
        set_long("
    This is a dark stage within the grand ballroom.  In the shadows above, you can squint to make out several sandbags and ropes.  The walls are hidden behind burgundy curtains and the floor is built of wood planks.
    A metal ladder at the back of the room descends into unknown blackened depths.  You get very bad feelings from that hole.
");
	set_items((["floor":"The wooden planks that make up the floor are heavily scuffed and scratched from use.",
    "curtains" : "The curtains run from ceiling to floor and are theatrical grade.  They are a deep velvet, burgundy in color.",
    "ceiling" : "It is shrouded in darkness.",
    "hole" : "The hole beneath the ladder is completely dark.",
    "sandbags" : "They sway far above in the darkness.",
    "ladder" : "The metal ladder descends into unknown darkness.",
				]));
	set_exits(([
				"east":"/d/attaya/tower/hallb16",
               "ladder":"/d/attaya/tower/hallb18",
				]));
         set_listen("default","You don't like to stand so close to that dark hole...  You hear your own heartbeat racing.");
	find_object_or_load("/d/attaya/tower/hallb17");
	set_trap_functions(({"east"}),({"sandbag"}),({"east"}));
}

int sandbag(){
        write("%^BOLD%^%^CYAN%^You hear a snap above you.",TP);
       tell_room(TO,"%^BOLD%^%^CYAN%^You hear a snap above you.",TP);
	toggle_trap("east");
	call_out("skull",1,TP);
	return 1;
}



void skull(object targ){
	object ob;
	if(objectp(targ)){
		if(present(targ->query_name())){
             tell_room(TO,"%^BOLD%^%^RED%^A sandbag falls from the darkness above!");
                        write("%^BOLD%^%^RED%^You are right beneath it!");
			tell_room(TO,"%^BOLD%^%^CYAN%^The sandbag slams into "+targ->query_name(),targ);
                 write("%^BOLD%^%^RED%^The sandbag slams into you with tremendous force!");
			targ->do_damage(targ->return_target_limb(),roll_dice(5,10));
			targ->set_paralyzed(20,"You are out cold");
			targ->add_attacker(TO);
			targ->continue_attack();
                   tell_room(TO,"%^CYAN%^From the depths behind you, something is clambering up the ladder!");
                 tell_room(TO,"%^BOLD%^%^RED%^A horrible towering creature peers out!");
			ob=new("/d/attaya/mon/tyrant");
			ob->move(TO);
		}
	}
}
			
void reset(){
	::reset();

	if(!trapped("east"))
		toggle_trap("east");
}
