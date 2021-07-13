#include <std.h>
inherit MONSTER;
#include "../lgnoll.h"


void create() {
    object obj;
	::create();
	
    set_name("gnoll hunter");
    set_id( ({"gnoll", "Gnoll", "hunter", "Hunter"}) );
    set_short("%^BOLD%^%^RED%^A tall slender gnoll");
    set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll %^RESET%^%^ORANGE%^is taller "+
	"than most of the others, but also more slender and he seems to have perfect control over his movements. Another difference "+
	"is that he does not make any unwanted noise, but rather seems content at observing his surroundings with a %^RED%^deadly "+
	"hunger %^ORANGE%^in his %^BOLD%^%^BLACK%^black eyes%^RESET%^%^ORANGE%^. He is dressed in "+
	"e%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rth%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lor%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d "+
	"l%^BOLD%^%^BLACK%^ea%^RESET%^%^ORANGE%^th%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r arm%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r "+
	"and seems to blend perfectly in with his surroundings. There is no doubt that this %^BOLD%^%^BLACK%^gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll "+
	"%^RESET%^%^ORANGE%^is far more deadly than he appears to be.\n");
    set_gender("male");
    set("race", "gnoll");
    set_body_type("gnoll");
    set_overall_ac(-5);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 25);
	set_class("cleric");
	set_mlevel("cleric", 20);
    set_hd(25,10);
    set_attack_bonus(10);
    set_exp(5000);
    set_stats("strength", 25);
    set_stats("dexterity", 16);
    set_stats("constitution", 20);
    set_stats("intelligence", 14);
    set_stats("wisdom", 14);
    set_stats("charisma", 10);
    //set_speed(20);
    //    set_nogo( ({}) );
    set("aggressive", 20);
    set_alignment(9);
    set_size(2);
    set_hp(300+(random(300)));
    set_max_hp(query_hp());
    set_property("full attacks", 3);
    add_money("gold", random(250));
	
	obj = new("/d/common/obj/potion/extra_heal");
    obj->set_uses(30);
    obj->move(TO);
	
	obj=new(OBJ"gnollhide")->move(TO);
    
	if(obj && roll_dice(1,4)<2) obj->set_property("monsterweapon",1);
	
	obj = new("/d/common/obj/armour/helm");
	obj->set_property("enchantment",2);
	if(roll_dice(1,4)<2) obj->set_property("monsterweapon",1);
	obj->move(TO);
	new("/d/common/obj/lrweapon/limitlessquiver")->move(TO);
	
	obj = new(OBJ"warbow");
	obj->move(TO);
	command("wield bow");
	command("wearall");
	set_funcs(({"bite"}));
	set_func_chance(30);
	
	   set_monster_feats(({
     "deadeye",                       
     "manyshot",                      
     "point blank shot",              
     "preciseshot",
	 "parry",
     "shot on the run" 
	  
   }));
					   
}


	
void bite(object targ){
	
	switch(random(3)){
		case 0:
		force_me("say %^BOLD%^%^RED%^I will eat your beating heart!");
		force_me("preciseshot attacker");
		break;

		case 1:
	    if(!present(targ)) return;
	    force_me("say %^BOLD%^%^RED%^Tonight, I feast on you!");
	    tell_object(targ, "%^BOLD%^%^BLACK%^The gnoll suddenly jumps at you with its %^RESET%^%^RED%^jaws %^BOLD%^%^BLACK%^wide open!%^RESET%^\n",targ);
	    tell_room (environment(targ), "The gnoll jumps at "+targ->QCN+" with its jaws wide open!\n",targ);
	    if(targ->query_stats("dexterity")>random(25))
        {
	        tell_object(targ,"%^BOLD%^%^BLACK%^The gnoll bites into your arm with his powerful jaws and tears a %^RESET%^%^RED%^ch%^MAGENTA%^u%^RED%^nk %^BOLD%^%^BLACK%^of %^RESET%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^out of you!%^RESET%^\n",targ);
	        tell_room (environment(targ),"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll warrior has caught " +targ->QCN+ " in his jaws and %^RED%^rips %^BOLD%^%^BLACK%^out a %^RED%^c%^RESET%^%^RED%^h%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^k %^BOLD%^%^BLACK%^of %^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh%^BOLD%^%^BLACK%^!%^RESET%^\n",targ);
	        tell_object(targ,"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll %^RESET%^%^MAGENTA%^wolfs %^BOLD%^%^BLACK%^down the %^BOLD%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^it tore from your arm and licks the %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^from his %^RED%^l%^BOLD%^i%^RESET%^%^RED%^ps.%^RESET%^\n",targ); 
	        tell_room (environment(targ),"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll %^RESET%^%^MAGENTA%^wolfs %^BOLD%^%^BLACK%^down the %^BOLD%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^it tore from " +targ->QCN+ "'s arm and licks the %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^from his %^RED%^l%^BOLD%^i%^RESET%^%^RED%^ps.\n",targ);
	        targ->do_damage("torso",(2,20)+20);
	        TO->add_hp(random(40)+10);
	    }
	    else
	    {
	        tell_object(targ, "%^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK! %^RESET%^%^MAGENTA%^The gnoll's jaws slam shut just %^GREEN%^i%^MAGENTA%^nc%^GREEN%^h%^MAGENTA%^es from your arm!%^RESET%^",targ);
	        tell_room (environment(targ), "%^ORANGE%^You hear a loud %^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK %^RESET%^%^ORANGE%^as the gnoll's jaws miss "+targ->QCN+"'s arm!",targ);
        }
	    break;
	
	    case 2:
	    force_me("say %^BOLD%^%^BLACK%^ Run my prey. Make me work for it!");
	    force_me("manyshot");
	    break;
	}
}

void heart_beat(){
	::heart_beat();
	if(query_hp()<query_max_hp()/2){
		force_me("drink vial");
force_me("drink vial");
force_me("drink vial");
force_me("drink vial");
force_me("drink vial");
	}
}




