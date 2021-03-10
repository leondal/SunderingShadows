#include <std.h>
#include <daemons.h>

inherit MONSTER;

object ob;

void create(){
   	::create();
    	set_name("clay golem");
    	set_short("Terra Cotta Statue");
    	set_id( ({"statue", "terra cotta statue","golem","clay golem"}) );
    	set_long("%^RESET%^%^ORANGE%^"+
    		"Standing eight feet tall this statue is made of terra cotta.  It "+
    		"was made by a very skilled artisan and no detail was spared.  The "+
    		"statue is a representation of a very well endowed male elf wearing "+
    		"only a long tunic.  In his hands are two large hammers crossed over "+
    		"his chest.  He is standing at attention.\n"+
		"%^RESET%^"
    	);
    	set_body_type("humanoid");
    	set_race("golem");
    	set_overall_ac(-10);
    	set_hd(30, 10);
    	set_class("ranger");
    	set_mlevel("ranger", 30);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_gender("male");
    	set_size(3);
    	ob = new("/d/common/obj/weapon/hammer_lg");
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
   		ob->set_property("monsterweapon",1);
		command("wield hammer");
  	ob = new("/d/common/obj/weapon/hammer_lg");
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
   		ob->set_property("monsterweapon",1);
		command("wield hammer");

    	set_stats("strength",20);
    	set_stats("dexterity", 16);
    	set_stats("intelligence", 0);
    	set_stats("wisdom", 0);
    	set_stats("constitution", 20);
    	set_stats("charisma", 18);
     	set_property("swarm",1);
     	set_max_hp(500);
    	set_hp(query_max_hp());
    	add_search_path("/cmds/ranger");
    	set_mob_magic_resistance("average");
	set_property("magic",1);
	set_property("no steal",1);
	set_property("no stab",1);
 	set_property("no hold",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
     	set_exp(18500);
      set_property("full attacks",1);
      set_max_level(25);
    	set_funcs(({"berserk"}));
    	set_func_chance(30);
}
void init(){
    	::init();
  	add_action("kill_em", "destroy");
	add_action("pick_em","pick");
}
int kill_em(string str) {
  	string fool,mname;
  	fool = str;
  	mname = TP->query_name();
  	if(!avatarp(TP))return notify_fail("The statue ignores you");
  	if(!str)return notify_fail("Who do you want the golem to destroy?");
 	if(!present(fool, ETO))return notify_fail("Try picking someone in the room!");
 	tell_room(ETO,"The statue suddenly comes to life and attacks!");
 	command("kill " + fool);
      return 0;
}
// no idea what action you might want here, thought this was to go in a garden, but can be changed
int pick_em(string str) {
  	if(str == "flower" || str == "lock"){
 		tell_room(ETO,"The statue suddenly comes to life and attacks!");
    		command("kill " + TP->query_name());
      }
      return 0;
}
void berserk(object targ){
   	int i, j;
   	object *inven;

   	inven = all_living(TO);
   	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^%^ORANGE%^The golem suddenly goes berserk and slams "+
		"his hammers repeatedly into the ground!\n");
	tell_room(ETO,"%^BOLD%^%^ORANGE%^The ground rises up and buckles beneath "+
		"your feet!\n");

   	for(i=0;i<j;i++) {
      	if(!objectp(inven[i])) continue;
      	if(inven[i] == TO) continue;
      	if(inven[i] == TP) continue;
 		if(!inven[i]->query_stats("dexterity")>random(20)){
         		tell_object(inven[i],"%^BOLD%^%^YELLOW%^You are thrown from "+
         			"your feet and land hard on the ground!");
         		inven[i]->do_damage("torso",random(20)+10);
      	}
      	else {
         		tell_object(inven[i],"%^ORANGE%^The ground tosses you around, but "+
         			"you manage to remain on your feet with little damage.");
         		inven[i]->do_damage("torso",random(10)+5);
      	}
      	inven[i]->add_attacker(TO);
      	inven[i]->continue_attack();
      	inven[i]->remove_attacker(TO);
   	}
  	if(!targ->query_stats("dexterity")>random(20)){
         	tell_object(targ,"%^BOLD%^%^YELLOW%^You are thrown from "+
         		"your feet and land hard on the ground!");
      	targ->do_damage("torso",random(30)+10);
      	targ->add_attacker(TO);
      	targ->continue_attack();
      	targ->remove_attacker(TO);
      	return 1;
   	}
      tell_object(targ,"%^ORANGE%^The ground tosses you around, but "+
      	"you manage to remain on your feet with little damage.");
   	targ->do_damage("torso",random(15)+10);
   	targ->add_attacker(TO);
   	targ->continue_attack();
   	targ->remove_attacker(TO);
   	return 0;
}