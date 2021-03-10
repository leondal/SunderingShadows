
#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(JUNGLE);
    set_travel(DIRT_ROAD);
	set_name("Arrrrgh Death, man");
	set_short("A dark jungle altar");
	set_property("indoors",0);
	set_property("light",1);
    set_long("/daemon/crayon_d"->color_string("You have come to a strange clearing in the canopy.  A stone altar peeks out from beneath various vines and leaves. A strange feeling of dread fills you suddenly!","green"));
	set_items((["altar":"As you clear away some of the vines, you notice a strange series of pictograms.",
                "pictograms" : "%^RED%^They depict a giant skull floating over screaming people just before invisible monsters appear and kill them!",
				"ground":"You notice a large trigger block that will recess if you step upon it when you leave.",
				"block":"It is the trigger to some form of trap."
                   ]));
	set_exits(([
                   "north":"/d/attaya/jungle/jun42",
                   ]));
    set_listen("default","It is strangely quiet here.");
	find_object_or_load("/d/attaya/jungle/jun40");
	set_trap_functions(({"north"}),({"skullboss"}),({"north"}));
}

int skullboss(){
        write("%^BOLD%^%^RED%^As you exit the room, you step on a trigger block hidden beneath the leaves on the jungle floor",TP);
	tell_room(TO,"%^BOLD%^As "+TPQCN+" walks north "+TP->query_possessive()+" left foot steps upon a trigger block.",TP);
	toggle_trap("north");
	call_out("skull",1,TP);
	return 1;
}



void skull(object targ){
	object ob;
	if(objectp(targ)){
		if(present(targ->query_name())){
			tell_room(TO,"%^BOLD%^%^BLUE%^A dark shadow suddenly falls upon you.  You look up to see a giant floating skull decending into the clearing.");
                        write("%^BOLD%^The skull's jaw opens and it turns to face you!");
			tell_room(TO,"%^BOLD%^%^CYAN%^The skull opens it's jaw and turns to face "+targ->query_name(),targ);
                     write("%^BOLD%^%^RED%^A beam of red light from the mouth of the giant skull slams into you, stunning you!");
			tell_room(TO,"%^BOLD%^%^RED%^The giant skull blasts "+targ->query_name()+" with a beam of red light, leaving "+targ->query_objective()+" incapacitated.",targ);
			targ->do_damage(targ->return_target_limb(),roll_dice(5,10));
			targ->set_paralyzed(20,"You cannot move");
			targ->add_attacker(TO);
			targ->continue_attack();
			tell_room(TO,"%^BOLD%^%^GREEN%^A shadowy presence slips into the room!");
                        ob=new("/d/attaya/mon/solstice");
			ob->move(TO);
		}
	}
}
			
void reset(){
	::reset();

	if(!trapped("north"))
		toggle_trap("north");
}
