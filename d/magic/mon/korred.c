//korred.c

#include "summoned_monster.h"

inherit MONSTER;

int hair;

void create(){
	object ob;
	::create();
	
	set_name("korred");
	set_id(({"korred","Korred"}));
	set_short("A small Korred");
	set_long(
@OLI
	This small creature has a dwarflike stout body and short goatlike
legs.  The remarkable thing about this creature is its hair.  The hair 
looks more massive than the creature itself and is without a doubt much
bigger.  Used to a life of love and dancing and fun, you realize that this 
creature is fully capable of battle simply by the way it leans on its staff.
OLI
	);
	set_hd(8,8);
	set_hp(64);
	set_race("korred");
	set_body_type("human");
	set_gender("male");
	set_class("thief");
	set_mlevel("thief", 15);
	set_size(1);
	remove_limb("left foot");
	remove_limb("right foot");
	add_limb("left hoof","left leg",0,0,0);
	add_limb("right hoof","right leg",0,0,0);
	set_mob_magic_resistance("average");
	set_property("swarm",1);
	set_exp(1700);
	ob = new(WEAPON);
	ob->set_long("A stout cudgel, that could be mistaken for a piece of firewood!");
	ob->set_short("A stout cudgel");
	ob->set_name("cudgel");
	ob->set_id(({"cudgel","Cudgel","stout cudgel"}));
	ob->set_wc(1,7);
	ob->set_large_wc(1,6);
	ob->set_property("enchantment",3);
   ob->set_weight(5);
	ob->set_type("bludgeoning");
	ob->set("value", 50);
	ob->move(TO);
	set_overall_ac(1);
	set_funcs(({"stones","hair"}));
	set_func_chance(60);
	add_money("gold",random(100));
	add_money("silver",random(1000));
	set_property("swarm",1); 
	set_stats("strength",25);
	set_alignment(8);
   command("wield cudgel");
}

void stones(object targ){	
	
	tell_room(ETO,"%^BOLD%^The korred finds a large boulder around him and picks it up and heaves it at "+targ->query_cap_name()+"!",targ);
	tell_object(targ,"%^BOLD%^The korred finds a large boulder around him and picks it up and heaves it at you!");
	if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd()) ) - (int)(targ->query_ac())){
 		tell_room(ETO,"%^The boulder flies almost lightly through the air and smacks "+targ->query_cap_name()+" fully in the mid-section!",targ);
 		tell_object(targ,"The boulder flies at you and you realize how strong this little creature is as it wacks you in the mid-section!");
 		targ->do_damage(targ->return_target_limb(),roll_dice(2,8));
 	} else {
 	
 		tell_room(ETO,"%^BOLD%^The Rock flies by "+targ->query_cap_name()+" but you realize the strength contained in that little body!",targ);
 		tell_object(targ,"%^BOLD%^The Rock flies by you but you realize the strength contained in that little body!");
 	}
 }
 
 void hair(object targ){
 	if(hair) {
 		set_func_chance(0);
 		execute_attack();
 		set_func_chance(60);
 	 	return;
 	 }
 	 tell_room(ETO,"%^BOLD%^%^RED%^Suddenly the korred whirls around in a fluid motion you are sure you couldn't repeat and throws a great mass of hair at "+targ->query_cap_name()+"!",targ);
 	 tell_object(targ,"%^BOLD%^%^RED%^Suddenly the korred whirls around in a fluid montion you are sure you couldn't repeat and throws a great mass of hair at you!\n");
 	 if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",0)){
 	 	tell_room(ETO,"%^BOLD%^The strands of hair fly throught the air but they all miss any target and the korred ends again facing battle!");
 	 	return;
 	 } else {
 	 	tell_room(ETO,"%^BOLD%^%^RED%^The strands of hair whirl around and the heavy tips wrap around "+targ->query_cap_name()+" much like a bola, entangling "+targ->query_objective()+" badly!",targ);
 	 	tell_object(targ,"%^BOLD%^%^RED%^The strands of hair whirl around and the heavy tips wrap around you much like a bola, entangling you badly!");
 	 	tell_room(ETO,"%^BOLD%^%^YELLOW%^You are amazed by how the korred can still move freely with a person trapped in it's hair!");
 		targ->set_paralyzed(60,"You are trying to break free of the korreds hair!");
 	 	call_out("cutting",30);
 	 	hair = 1;
 	}
 }
 
 void cutting(object targ,int i)
 {
     if(!objectp(targ) || !objectp(TO)) return;
 	if(!catch(targ->query_name())){
 		tell_object(targ,"You struggle to are gradually freeing yourself from the hair!");
 	}
 }
 
 	
