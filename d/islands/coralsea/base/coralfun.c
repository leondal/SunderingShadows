#include <std.h>
#include "../defs.h"
inherit WATER;

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
	add_action("panic_attack","surface");
	add_action("say_function","say");
	add_action("say_function","whisper");
	add_action("say_function","yell");
}


// Function to stop players from talking under water
int say_function(string str){
    if(!TP->query_true_invis()){
	tell_object(TP,"%^BOLD%^%^CYAN%^You go to speak and realize only "+
		"too late that you're underwater!  You swallow water and feel "+
		"your lungs burning in %^RED%^pain%^CYAN%^!%^RESET%^ \n"+
		"%^BOLD%^%^WHITE%^Maybe you should have gestured instead."+
		"%^RESET%^"),
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TP->QCN+" gets a startled, then "+
		"frightened look on their face as they inhale water when they "+
		"try to speak!",TP),
	TP->do_damage("torso",random(20)+20);
	return 1;
	}
}

// Funcation allows a player to escape the water and surface 
// but causes them to abandon gear for the sake of reaching the air quickly.
int panic_attack(){
	object ob;
	
		if(base_name(ETP) == ROOMS"coral_t1" || 
			base_name(ETP) == ROOMS"coral_t2" || 
			base_name(ETP) == ROOMS"coral_t3" || 
			base_name(ETP) == ROOMS"coral_t4" || 
			base_name(ETP) == ROOMS"coral_w1" || 
			base_name(ETP) == ROOMS"coral_w2" || 
			base_name(ETP) == ROOMS"coral_w4" || 
			base_name(ETP) == ROOMS"coral_b1" ||
			base_name(ETP) == ROOMS"coral_b2" ||
			base_name(ETP) == ROOMS"coral_b3" ||
			base_name(ETP) == ROOMS"coral_b4" ||
			base_name(ETP) == ROOMS"coral_b5" ||
			base_name(ETP) == ROOMS"coral_b6" ||
			base_name(ETP) == ROOMS"coral_b7" ||
			base_name(ETP) == ROOMS"coral_b8" ||
			base_name(ETP) == ROOMS"coral_b9"){
		tell_object(TP,"%^BOLD%^%^CYAN%^You realize just in time "+
			"that there is something above you and avoid "+
			"knocking yourself out.%^RESET%^");
		return 1;
		}
		
		if(base_name(ETP) == ROOMS"coral_w7" ||
			base_name(ETP) == ROOMS"coral_w6" ||
			base_name(ETP) == ROOMS"coral_w5" ||
			base_name(ETP) == ROOMS"coral_w3"){
		tell_object(TP,"%^GREEN%^The kelp is too thick here "+
			"to make a break for the surface!%^RESET%^");
		return 1;
		}

	tell_object(TP,"%^BOLD%^%^CYAN%^You feel your lungs burning.  "+
		"Panic sets in!  Casting off some of your heavy equipment "+
		"you swim for the surface and the fresh air!");
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TP->QCN+" panics and swims "+
		"for the surface!",TP);
		
		while(present("sack",TP)){
			ob = present("sack",TP);
			ob->move(TO);
		}
		
		while(present("chest",TP)){
			ob = present("chest",TP);
			ob->move(TO);
		}
		
		switch(random(10)){
			case 0:
				TP->move(ROOMS"coral_s10");
			break;
			case 1:
				TP->move(ROOMS"coral_s1");
			break;
			case 2:
				TP->move(ROOMS"coral_s2");
			break;
			case 3:
				TP->move(ROOMS"coral_s3");
			break;
			case 4:
				TP->move(ROOMS"coral_s4");
			break;
			case 5:
				TP->move(ROOMS"coral_s5");
			break;
			case 6:
				TP->move(ROOMS"coral_s6");
			break;
			case 7:
				TP->move(ROOMS"coral_s7");
			break;
			case 8:
				TP->move(ROOMS"coral_s8");
			break;
			case 9:
				TP->move(ROOMS"coral_s9");
			break;
		}
	return 1;
}

// Function calls Aysu for when high level players are mucking around
// in the area that is not designed for them. 
int GoThroughDoor(){
	object ob;
	if(!TP->query_true_invis()){
		if(TP->query_highest_level()>=30){
			if(random(1000) < 20){
			TP->set_paralyzed(2,"You're trying to see past the bubbles!");
			tell_object(TP,"%^BOLD%^%^WHITE%^Threatened by your "+
				"power, a %^BLUE%^creature of the abyss %^WHITE%^"+
				"rises from its lair and attacks you!%^RESET%^");
			tell_object(TP,"%^BOLD%^%^RED%^You feel teeth biting down "+
				"into your tender flesh!");
			tell_object(TP,"%^BOLD%^%^CYAN%^Water rushes past you!");
			tell_object(TP,"%^BOLD%^%^WHITE%^You struggle and manage "+
				"to break free!  But, where are you?");
			tell_room(TO,"%^BOLD%^%^WHITE%^A flood of bubbles fills "+
				"your vision as %^CYAN%^Aysu%^BLUE%^, %^BLACK%^"+
				"Terror %^BLUE%^of the N%^BLACK%^i%^BLUE%^g%^BLACK%^"
				"h%^BLUE%^t %^BLACK%^S%^BLUE%^e%^BLACK%^a%^WHITE%^ "+
				"attacks "+TP->QCN+", dragging them off into the "+
				"darkness!%^RESET%^",TP);
			TP->move(ROOMS"coral_t4");
			return 0;
			}
		return 1;
		}
		if(TP->query_highest_level() > 26 && 
		TP->query_highest_level() < 30){
			if(random(1000) < 50){
			tell_object(TP,"%^BOLD%^%^WHITE%^Threatened by your "+
				"power, a %^BLUE%^creature of the abyss %^WHITE%^"+
				"rises from its lair and drags you off toward "+
				"the surface!%^RESET%^");
			tell_room(TO,"%^BOLD%^%^WHITE%^A flood of bubbles fills "+
				"your vision.  When they clear, "+TP->QCN+" has "+
				"vanished!%^RESET%^",TP);
			TP->move(ROOMS"coral_s3");
			return 1;
			}
		return 1;
		}
	}
	return 1;
}


// Function selects monsters to spawn in various rooms.
void pick_mon(){
	int monsters;
	monsters = has_mobs();
	if(!monsters){
		if(mons){ mons = ([]); }
			switch(random(20)){
				case 0..1:
				set_monsters(({MON"coral_shark.c"}),({random(2)+1}));
				monster_party(20);
				break;
					
				case 2..4:
				tell_room(ETO,"%^BOLD%^%^BLUE%^A swam of %^RESET%^"+
					"%^RED%^b%^ORANGE%^r%^RED%^igh%^ORANGE%^t%^RED%^"+
					"ly c%^ORANGE%^o%^RED%^lo%^ORANGE%^r%^RED%^ed "+
					"%^BLUE%^%^BOLD%^fish dart away quickly.%^RESET%^");
				break;
			
				case 5..10:   
				set_monsters(({MON"coral_fish.c"}),({random(2)+1}));
				monster_party(20);
				break;
		
				case 11..13:
				set_monsters(({MON"coral_pirate.c"}),({1}));
				set_monsters(({MON"coral_shark.c"}),({1}));
				monster_party(30);
				break;
			
				case 14..15:
				tell_room(ETO,"%^BOLD%^%^CYAN%^The current shifts, "+
					"pushing you along.%^RESET%^");
				break;

				case 16..17:
				set_monsters(({MON"coral_pirate.c"}),({random(2)+1}));
				monster_party(15);
				break;

				case 18..19:
				set_monsters(({MON"coral_fish.c"}),({random(3)+1}));
				monster_party(20);
				break;
		}
	}
	return 1;
}