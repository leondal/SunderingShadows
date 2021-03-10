
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("Arrrrgh Death, man");
	set_short("%^RESET%^%^ORANGE%^An archway of %^BOLD%^%^ORANGE%^san%^RESET%^%^ORANGE%^d%^BOLD%^%^ORANGE%^st%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^ne%^RESET%^");
	set_property("indoors",0);
	set_property("light",2);
    set_long("%^RESET%^%^ORANGE%^An archway of %^BOLD%^%^ORANGE%^san%^RESET%^%^ORANGE%^d%^BOLD%^%^ORANGE%^st%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^ne%^RESET%^
%^RESET%^%^ORANGE%^You stand beneath a strange sandstone %^BOLD%^%^RED%^a%^RESET%^%^RED%^r%^BOLD%^%^RED%^chway.%^RESET%^%^ORANGE%^ It has been hand carved and somehow hoisted all the way up here to sit aimlessly on this ledge. You cannot possibly fathom why anyone would partake in such a seemingly useless endeavour! The ledge drops off here to a distance of several hundred feet, so moving any further to the east would be very unpleasant.%^RESET%^
");
    set_items(([
     "archway" : "The archway is crafted of sandstone and has long grooves carved in it's sides.  It stands directly over you.",
     "grooves" : "The grooves run the full height of the arch.  You think you may be able to see a silvery cord inside them!",
     "cord" : "It may be a trigger to a trap!",
     "ground" : "It is stained with blood!"
				]));
	set_exits(([
				"west":"/d/attaya/cliff68",
				]));
         set_listen("default","The wind makes a peculiar howling sound as it passes through the archway.");
	find_object_or_load("/d/attaya/cliff69");
	set_trap_functions(({"west"}),({"skullboss"}),({"west"}));
}

int skullboss(){
        write("%^BOLD%^%^RED%^As you exit the room, a silvery cord slips around your foot and pulls you up into the air",TP);
	tell_room(TO,"%^BOLD%^As "+TPQCN+" walks east "+TP->query_possessive()+" body is snared by a silvery cord from the arch and liften into the air.",TP);
	toggle_trap("west");
	call_out("skull",1,TP);
	return 1;
}



void skull(object targ){
	object ob;
	if(objectp(targ)){
		if(present(targ->query_name())){
			tell_room(TO,"%^BOLD%^%^BLUE%^A giant skull rises from below and floats over the ledge.");
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

	if(!trapped("west"))
		toggle_trap("west");
}
