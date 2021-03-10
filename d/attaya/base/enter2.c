
#include <std.h>

inherit "/d/attaya/base/spec/oubliette";

void create(){
	::create();
	set_name("Arrrrgh Death, man");
	set_short("LAST RESORT");
	set_property("indoors",0);
	set_property("light",2);
        set_long("
    At long last, you stand before the enterance to the infamous Tower of the Black Dawn!  The city walls before you mearly make up the southeast support for the Crystalline Tower which rises out of view above you!  
    The tower is at a scale you could have never imagined possible and is made mostly of glass and crystal.  High stone walls stand before you, however, and you will have to search through them unhtil you can find a way up to the tower itself.
    The cold air up here is taking it's toll on you, and you can no longer feel your legs.
    The gates to the city walls are open and seem deceptively inviting.
");
    set_items(([
     "gates" : "The massive golden gates hang as well as the day they were constructed.  This fortresss seems to never have aged.",
     "tower" : "The magnificent crystalline tower stands above you and vanishes out of view in all directions!  It is beyond belief.",
     "ground" : "It is stained with blood!"
				]));
	set_exits(([
				"enter":"/d/attaya/base/wall1",
                                "south":"/d/attaya/cliff45"
				]));
         set_listen("default","You can hear metallic footfalls within the city walls.");
	find_object_or_load("/d/attaya/base/enter");
	set_trap_functions(({"enter"}),({"skullboss"}),({"enter"}));
}

int skullboss(){
        write("%^BOLD%^%^GREEN%^Several undead warriors storm into the room",TP);
tell_room("%^BOLD%^%^GREEN%^Several undead warriors storm into the room",TP);
	toggle_trap("enter");
	call_out("slam",1,TP);
	return 1;
}



void slam(object targ){
	object ob;
	if(objectp(targ)){
		if(present(targ->query_name())){
                        write("%^RED%^One of the warriors hits you in the temple with the hilt of his sword!");
			tell_room(TO,"%^BOLD%^%^RED%^One of the warriors smashes "+targ->query_name()+" in the temple with the hilt of their sword, knocking "+targ->query_objective()+" out cold.",targ);
			targ->do_damage(targ->return_target_limb(),roll_dice(2,10));
			targ->set_paralyzed(20,"You are out cold");
			targ->add_attacker(TO);
			targ->continue_attack();
			ob=new("/d/attaya/mon/uwarrior");
			ob->move(TO);
                        ob->kill_ob(targ,1);
                       ob=new("/d/attaya/mon/uwarrior");
                        ob->move(TO);
                         ob->kill_ob(targ,1);
                      ob=new("/d/attaya/mon/uwarrior");
                       ob->move(TO);
                        ob->kill_ob(targ,1);
                       ob=new("/d/attaya/mon/archer");
                       ob->move(TO);
                       ob->kill_ob(targ,1);
		}
	}
}
			
void reset(){
	::reset();

	if(!trapped("enter"))
		toggle_trap("enter");
}
