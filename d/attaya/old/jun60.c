
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(RUINS);
      set_travel(FOOT_PATH);
	set_name("Arrrrgh Death, man");
	set_short("Tomb of the Intruder");
	set_property("indoors",0);
	set_property("light",2);
        set_long("
    Before you lies the resting place of Intruder, the Warrior General of the ancient Kinnesaruda legions that terrorized the world in the name of order.  It was supposed to be his final resting place while his soul suffered eternal damnation and suffering.
    The trees around the tomb are all dead, and sunlight pours into the room through the clearing made by their absence.  The bones of small woodland critters litter the ground beneath your feet.  
    %^BLUE%^This is evil ground.  Tainted by one of the most powerful dark forces in history.
");
	set_items((["tomb":"It is a massive stone monolith, imbedded in a base of granite.  The front of the toom is a door with the carving of a shield upon it..",
           "bones" : "They are all that remains of the unfortunate animals that entered this clearing.  %^CYAN%^You start to get a really bad feeling.",
           "ground" : "It is littered with the remains of dead animals.  All plant life as well has been destroyed by an unseen power.",
           "door" : "The tomb door is marked by the carving of a shield.  It is impossible for you to move!",
           "trees" : "The trees are all dead in this area."
				]));
	set_exits(([
				"east":"/d/attaya/jun61",
				]));
         set_listen("default","You hear your own heart pounding.");
	find_object_or_load("/d/attaya/jun60");
	set_trap_functions(({"east"}),({"ghost"}),({"east"}));
}

int ghost(){
   write("%^BOLD%^A bolt of lightning strikes the tomb!",TP);
       tell_room(TO,"%^BOLD%^As "+TPQCN+" turns to leave, a bolt of lightning strikes the tomb!",TP);
	toggle_trap("east");
	call_out("doom",1,TP);
	return 1;
}



void doom(object targ){
	object ob;
	if(objectp(targ)){
		if(present(targ->query_name())){
             tell_room(TO,"%^BOLD%^%^BLUE%^The door to the tomb flies off!");
               write("%^BOLD%^Another bolt of lightning, this one from the tomb itself strikes you in the head!");
          tell_room(TO,"%^BOLD%^%^CYAN%^A lightning bolt streaks from the open tomb and blasts "+targ->query_name(),targ);
              write("%^BOLD%^%^RED%^An ancient evil spirit slips from the darkness within and takes the shape of a spectre.");
			tell_room(TO,"%^BOLD%^%^RED%^An ancient evil spirit slips from the darkness and floats toward "+targ->query_name()+" it takes on the form of a spectre beside "+targ->query_objective()+" and grins.",targ);
			targ->do_damage(targ->return_target_limb(),roll_dice(2,10));
			targ->set_paralyzed(10,"You struggle to get out from underneath the tomb door");
			targ->add_attacker(TO);
			targ->continue_attack();
			ob=new("/d/attaya/mon/intruderII");
			ob->move(TO);
			ob->kill_ob(targ,1);
		}
	}
}
			
void reset(){
	::reset();

	if(!trapped("east"))
		toggle_trap("east");
}
