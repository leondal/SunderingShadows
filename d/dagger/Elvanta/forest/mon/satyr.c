//satyr.c

#include <std.h>

inherit MONSTER;

int pipes;
object *charmed;

void charm(object targ);
void fear(object targ);
void sleep(object targ);
void screw_up();

void create(){
	object ob;
	::create();
	set_name("satyr");
set_id(({"satyr", "statue", "Satyr"}));
set_short("A statue of a Satyr");
	set("long",
@OLI
	This little creature is half goat, half human. Small horns protrude 
from it's head. Having a bare top is sharply contrasted by the thick 
coat of brown hair on covering the lower portion. 
While it is carved from a creamy gold soapstone, it looks as if ready to play its magic upon the pipes it carries.
OLI
);
	set_body_type("human");
	remove_limb("right foot");
	remove_limb("left foot");
	add_limb("right hoof","right leg",0,0,0);
	add_limb("left hoof","left leg",0,0,0);
	set_race("satyr");
	if(random(2) < 1)
		set_gender("male");
	else
		set_gender("female");
	set_overall_ac(2);
	set_mob_magic_resistance("average");
	set_hd(8,8);
	set_hp(45);
	set_exp(1100);
	set_thief_skill("pick pocket",85);
	toggle_steal();
	ob = new("/d/shadow/obj/weapon/longsword");
	if(random(100) < 20)
		ob->set_property("enchantment",1);
	ob->move(TO);
	command("wield sword in right hand");
	if(random(100) < 40){
		set_funcs(({"butt","magic"}));
		ob = new(OBJECT);
		ob->set_long("Small pipes played by the satyr, only useful to the satyr.");
		ob->set_short("A small set of pipes");
		ob->set_name("pipes");
		ob->set_id(({"pipes","Pipes","satyr's pipes"}));
		ob->weight(2);
		ob->set_value(100);
		ob->move(TO);
	} else
		set_funcs(({"butt"}));
	set_func_chance(50);
	charmed = ({});
	add_money("gold",random(500));
	add_money("platinum",random(50));
	set_property("swarm",1);
}
	
void butt(object targ){
	tell_room(ETO,"%^BOLD%^There in front of you the satyr lowers "+query_possessive()+" head and thrusts toward "+targ->query_cap_name()+" with his powerful hindlegs!",targ);
	tell_object(targ,"%^BOLD%^The satyr suddenly lowers "+query_possessive()+" head and thrusts toward you with his powerful hind legs!\n");
	
	if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd()) )-(int)(targ->query_ac())){
		tell_room(ETO,"%^BOLD%^%^RED%^The satyr thrusts "+query_possessive()+" head into the middle portion of "+targ->query_cap_name()+", it's small horns breaking the skin!",targ);
		tell_object(targ,"%^BOLD%^%^RED%^The satyr thrusts "+query_possessive()+" head into you midle section, it's small horns breaking the skin!");
		targ->do_damage(targ->return_target_limb(),roll_dice(2,4));
	} else {
		tell_room(ETO,"%^BOLD%^As the satyr thrusts, "+targ->query_cap_name()+" side steps the attack!",targ);
		tell_object(targ,"%^BOLD%^As the satyr thrusts, you side step the attack!");
	}
}

void magic(object targ){
	if(!present("pipes")) return;
	
	if("daemon/saving_d"->saving_throw(targ,"spell",0)){
		screw_up();
		return;
	} else {
		switch (random(3)){
			case 0:
				charm(targ);
				break;
			case 1:
				fear(targ);
				break;
			case 2:
				sleep(targ);
				break;
			}
		}
	}

void screw_up(){
	tell_room(ETO,"%^BOLD%^%^CYAN%^The satyr plays a small tune on "+query_possessive()+" pipes!");
	tell_room(ETO,"%^BOLD%^%^CYAN%^You feel a pull on your mind from the music but you push it from your mind!");
	}

void charm(object targ){
	object ob;
	
	if(targ->query_property("charmed")) return;
	
	tell_room(ETO,"%^BOLD%^%^CYAN%^The satyr plays a small tune on "+query_possessive()+" pipes!");
	tell_room(ETO,"%^BOLD%^%^CYAN%^You feel a pull on your mind from the music but you push it from your mind!",targ);
	tell_object(targ,"%^BOLD%^%^YELLOW%^You feel your mind slipping from your body!!");
	tell_room(ETO,"%^BOLD%^You see a glazed look overcome "+targ->query_cap_name()+"'s face, "+targ->query_subjective()+" obviously has fallen to the spell of the pipes!",targ);
	
	ob = new("/d/tharis/monsters/stuff/charm");
	
	ob->move(targ);
	ob->start_charm();
	
	TO->remove_attacker(targ);
	targ->cease_all_attacks();
	if(query_attackers() != ({})){
		targ->set_attackers(query_attackers());
		call_out("fun_stuff",5,targ, ob);
	} else {
		ob->disable_me(1);
		targ->force_me("drop all");
		targ->run_away();
		targ->run_away();
		targ->run_away();
		targ->run_away();
		targ->run_away();
		ob->remove();
		}
	targ->set_property("charmed",1);
	command("get all");
	
}

void fear(object targ){
	
	tell_room(ETO,"%^BOLD%^%^CYAN%^The satyr plays a small tune on "+query_possessive()+" pipes!");
	tell_room(ETO,"%^BOLD%^%^CYAN%^You feel a pull on your mind from the music but you push it from your mind!",targ);
	tell_object(targ,"%^BOLD%^%^YELLOW%^You feel your mind being over come by emense fear!!");
	tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" is over come by an overwelming fear!",targ);
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	targ->run_away();
	
	}

void sleep(object targ){

	if(targ->query_paralyzed()){
		execute_attack();
		return;
	}
	tell_room(ETO,"%^BOLD%^%^CYAN%^The satyr plays a small tune on "+query_possessive()+" pipes!");
	tell_room(ETO,"%^BOLD%^%^CYAN%^You feel a pull on your mind from the music but you push it from your mind!",targ);
	tell_object(targ,"%^BOLD%^%^YELLOW%^You feel your mind slipping from your body, as consciousness leaves you!!");
	tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" is overcome by the charm and falls fast asleep!",targ);
	
	targ->set_paralyzed(90,"The effects of the satyr's piping are still upon you!");
}

void fun_stuff(object targ, object ob){
	if(!targ->query_property("charmed")) return;
	
	if(query_attackers() == ({})){
		
		ob->disable_me(1);
		targ->force_me("drop all");
		targ->run_away();
		targ->run_away();
		targ->run_away();
		targ->run_away();
		targ->run_away();
		ob->remove();
	}
	ob->disable_me(1);
	switch (random(50)){
		case 0:
			targ->force_me("dance");
			break;
		case 1:
			targ->force_me("sing");
			break;		
		case 2:
			targ->force_me("laugh");
			break;		
		case 3:
			targ->force_me("snicker");
			break;		
		case 4:
			targ->force_me("love satyr");
			break;		
		case 5:
			targ->force_me("emote twirls his sword");
			break;		
		case 6:
			targ->force_me("doh");
			break;		
		case 7:
			targ->force_me("rolf");
			break;		
		case 8:
			targ->force_me("welcome");
			break;		
		case 9:
			targ->force_me("cheer");
			break;		
		case 10:
			targ->force_me("smile");
			break;		
		case 11:
			targ->force_me("bonk");
			break;		
		case 12:
			targ->force_me("chortle");
			break;		
		case 13:
			targ->force_me("burp");
			break;		
		case 14:
			targ->force_me("flip");
			break;		
		case 15:
			targ->force_me("flutter");
			break;		
		case 16:
			targ->force_me("gaze");
			break;		
		case 17:
			targ->force_me("pace");
			break;		
		case 18:
			targ->force_me("punch");
			break;		
		case 19:
			targ->force_me("scream");
			break;		
		case 20:
			targ->force_me("snarl");
			break;		
		case 21:
			targ->force_me("sneer");
			break;		
		case 22:
			targ->force_me("snort");
			break;	
		case 23:
			targ->force_me("strangle");
			break;	
		case 24:
			targ->force_me("thank");
			break;	
		case 25:
			targ->force_me("weep");
			break;	
		case 26:
			targ->force_me("worship");
			break;	
		case 27:
			targ->force_me("whistle");
			break;	
		case 28:
			targ->force_me("chew");
			break;	
	}
	
	force_me("rotf");
	ob->disable_me(0);
	call_out("fun_stuff",10,targ,ob);
}
