#include <std.h>
inherit MONSTER;
#include "../lgnoll.h"


void create() {
    object obj;
	::create();
	
    set_name("bloodfang");
    set_id( ({"gnoll", "Gnoll", "warrior", "Warrior", "hero","Hero","bloodfang"}) );
    set_short("%^BOLD%^%^RED%^BloodFang%^RESET%^%^RED%^, a m%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^ss%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^ve %^BOLD%^%^BLACK%^a%^RESET%^%^RED%^rmor%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d gn%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^ll%^RESET%^");
    set_long("%^BOLD%^%^RED%^BloodFang %^BLACK%^is a massive %^RESET%^%^ORANGE%^Gnoll %^BOLD%^%^BLACK%^and "+
			"even by %^RESET%^%^ORANGE%^Gnollish %^BOLD%^%^BLACK%^standards he is impressive! It adds to his "+
			"impressive bulk that he is dressed in %^WHITE%^impr%^ORANGE%^e%^WHITE%^ss%^ORANGE%^i%^WHITE%^ve "+
			"pl%^ORANGE%^a%^WHITE%^t%^ORANGE%^e%^WHITE%^m%^ORANGE%^a%^WHITE%^il%^BLACK%^, obviously stolen from "+
			"the ruins of %^ORANGE%^Asgard%^BLACK%^. Or perhaps from a refugee caravan unlucky enough to fall prey "+
			"to the %^RESET%^%^ORANGE%^gnolls. %^BOLD%^%^BLACK%^His bl%^RESET%^a%^BOLD%^%^BLACK%^ck "+
			"e%^RESET%^y%^BOLD%^%^BLACK%^es sh%^RESET%^i%^BOLD%^%^BLACK%^ne with unnatural %^RESET%^%^RED%^hunger "+
			"%^BOLD%^%^BLACK%^and %^RESET%^%^RED%^hatred %^BOLD%^%^BLACK%^and his upper lip has been scarred in "+
			"such a way as to raise his lip in a permanent %^RED%^bl%^BLACK%^oo%^RED%^dth%^BLACK%^i%^RED%^rst%^BLACK%^y "+
			"%^RED%^sn%^BLACK%^a%^RED%^rl%^BLACK%^. His %^WHITE%^shield %^BLACK%^is astonishing and %^WHITE%^embroidered "+
			"%^BLACK%^with the symbol of %^ORANGE%^Asgard%^BLACK%^. He wields an %^RESET%^%^CYAN%^impressive hammer "+
			"%^BOLD%^%^BLACK%^with old %^CYAN%^m%^RESET%^a%^BOLD%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^c%^RESET%^a%^BOLD%^%^CYAN%^l "+
			"s%^RESET%^y%^BOLD%^%^CYAN%^mb%^RESET%^o%^BOLD%^%^CYAN%^ls %^BLACK%^carved into it.\n");
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
    set_hp(500+(random(200)));
    set_max_hp(query_hp());
    set_property("full attacks", 3);
    add_money("gold", random(250));
	
	obj = new(OBJ"commandoplate");
	if(random(5))obj->set_property("monsterweapon",1);
	obj->move(TO);

	obj = new(OBJ"asgaardshield");
	if(random(2)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new("/d/common/obj/armour/helm");
	obj->set_property("enchantment",2);
	if(random(2)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new(OBJ"commandohammer");
	if(random(5)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield hammer");
	command("wearall");
	set("aggressive","berserk");
	set_funcs(({"bite"}));
	set_func_chance(30);
	
	   set_monster_feats(({
      "parry",
	 "counter",
     "deflection",
     "reflection",
     "shieldbash",
     "shieldwall", 
	 "powerattack",
	  
   }));
					   
}

int berserk(object target){
	force_me("emoteat "+TPQN+" %^BOLD%^%^BLACK%^BloodFang glares at you%^RESET%^");
	force_me("emote %^BOLD%^%^RED%^speech growls hungry%^RESET%^");
	force_me("say %^BOLD%^%^BLACK%^Meat is here guys ... %^RED%^Kill the Meat!%^RESET%^");
     tell_room(ETO,"%^RED%^The BloodFang goes into berserk!%^RESET%^\n");
	force_me("kill "+TP->query_name());
	new("/cmds/spells/b/_berserker")->use_spell(TO,"gnoll warrior",45,100,"cleric");
	return 1;
	
	
}	
	
void bite(object targ){
	
	switch(random(2)){
		case 0:
		force_me("say %^BOLD%^%^BLACK%^You need some tenderizing!");
		force_me("shieldbash attacker");
		break;

		case 1:
	if(!present(targ)) return;
	force_me("say %^BOLD%^%^RED%^Tonight, I feast on you!");
	tell_object(targ, "%^BOLD%^%^BLACK%^The gnoll suddenly jumps at you with its %^RESET%^%^RED%^jaws %^BOLD%^%^BLACK%^wide open!%^RESET%^\n",targ);
	tell_room (environment(targ), "The gnoll jumps at "+targ->QCN+" with its jaws wide open!\n",targ);
	if(targ->query_stats("dexterity")>random(25)){
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
}
}







