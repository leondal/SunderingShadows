#include <std.h>
inherit "std/monster";
string gender_poss,gender_Subj, gender_subj, gender_obj;

void create(){
      object obj;
      ::create();
	set_name("fey'ri");
	set_id(({"fey'ri","feyri","trapper","elven trapper","elf","argmon"}));
	set_short("%^RED%^A svelte fey'ri %^RESET%^");
	  if (random(2)){
        set_gender("male");
        gender_poss = "his";
        gender_Subj = "He";
        gender_subj = "he";
        gender_obj = "him";
      } else {
        set_gender("female");
        gender_poss = "her";
        gender_Subj = "She";
        gender_subj = "she";
        gender_obj = "her";
      }
	set_long("%^GREEN%^With %^RED%^fiery red%^GREEN%^ skin this elf has a "+
		"demonic appearance to "+gender_poss+".  Brushing"+
		" "+gender_poss+" shoulder is a mane of %^BOLD%^%^BLACK%^raven black"+
		" %^RESET%^%^GREEN%^hair with tiny braids woven into the voluminous "+
		"mass.  %^BOLD%^%^BLACK%^Black%^RESET%^%^GREEN%^"+
		" soulless eyes blaze with a fiendish "+
		"fire, revealing the demonic ancestry of this elf.  "+
		"A long pointed tail whips around "+gender_obj+" in "+
		"an agitated manner.  Possessing the famous lithe "+
		"elven body type, "+gender_subj+" has an effortless"+
		" graceful way of moving.  Dressed in a mixture of "+
		"%^CYAN%^elven%^GREEN%^ and %^RED%^fiendish%^GREEN%^"+
		" garments, "+gender_subj+" looks "+
		"as if "+gender_subj+" is torn between two cultures.\n");
	set_race("elf");
	set_body_type("elf");
	set_hd(30+(random(14)),12);
	set_stats("strength",20);
	set_stats("intelligence",14);
	set_stats("dexterity",18);
	set_stats("charisma",12);
	set_stats("constitution",16);
	set_stats("wisdom",random(5)+15);
	set_overall_ac(-10);
	set_property("full attacks",1);
	set_size(2);
        avoid_traps(1);
        add_attack_bonus(random(10)+5);
	set_alignment(9);
	set_mob_magic_resistance("average");
		switch(random(6)){
case 0:
	set_class("fighter");
     	set_mlevel("fighter",query_hd());
     	set_guild_level("fighter",query_hd());
	add_search_path("/cmds/fighter");
        set_stats("strength",25);
	set_parrying(1);
        switch(random(6)){
        case 0..3:
	obj=new("/d/islands/argentrock/obj/jet_scythe.c");
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
        break;
        default:
        obj=new("/d/islands/argentrock/obj/jet_scythe2.c");
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
        break;
        }
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/raven_plate.c");
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/r_helm.c");
		obj->set_property("enchantment",2);
		if(random(2)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield scythe");
	force_me("wearall");
break;
case 1:
     	set_class("thief");
	set_mlevel("thief",query_hd());
	set_guild_level("thief",query_hd());
	add_search_path("/cmds/thief");
	set_class("fighter");
     	set_mlevel("fighter",query_hd());
     	set_guild_level("fighter",query_hd());
	add_search_path("/cmds/fighter");
	set_parrying(1);
	set_thief_skill("hide in shadows",95);
     	set_thief_skill("move silently",95);
	set_stats("dexterity",18);
     	set_stats("constitution",17);
	set_scrambling(1);
        switch(random(6)){
        case 0..3:
	obj=new("/d/islands/argentrock/obj/diamond_short.c");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/diamond_short.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
        break;
        default:
        obj=new("/d/islands/argentrock/obj/tortured_blade.c");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/tortured_blade.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
        break;
        }
	obj=new("/d/islands/argentrock/obj/purple_hide.c");
		if(random(3))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/rand_leath_head.c");
		obj->set_property("enchantment",2);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield sword");
	command("wield sword 2");
	command("wearall");
break;
case 2:
     	set_class("cleric");
     	set_mlevel("cleric",query_hd());
     	set_guild_level("cleric",query_hd());
     	add_search_path("/cmds/cleric");
        set_class("fighter");
     	set_mlevel("fighter",query_hd());
     	set_guild_level("fighter",query_hd());
	add_search_path("/cmds/fighter");
	set_diety("bane");
	set_spell_chance(70);
	set_spells( ({ "unholy orb",
			"fear",
			"flame strike",
			"cause critial wounds",
			"dispel magic",
			"unholy orb"}) );
	obj=new("/d/islands/argentrock/obj/needle_flail.c");
		if(random(4)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/raven_plate.c");
		if(random(5)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/r_helm.c");
		obj->set_property("enchantment",2);
		if(random(4)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
      obj=new("/d/islands/argentrock/obj/shd_glassy.c");
           obj->set_property("enchantment",1);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield flail");
	force_me("wearall");
break;
case 3:
     	set_class("mage");
     	set_mlevel("mage",query_hd());
    	set_guild_level("mage",query_hd());
    	add_search_path("/cmds/wizard");
	set_class("fighter");
     	set_mlevel("fighter",query_hd());
    	set_guild_level("fighter",query_hd());
    	add_search_path("/cmds/fighter");
	set_parrying(1);
     	set_stats("intelligence",18);
     	set_stats("wisdom",16);
	set_spell_chance(85);
	set_spells( ({
		"acid breath",
		"powerword stun",
		"acid orb",
		"powerword stun",
		"scorcher",
		"magic missile",
		"greater shout",
		"dispel magic"}) );
	obj=new("/d/common/obj/rand/mage_robes.c");
           obj->set_property("enchantment",3);
		if(random(5))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
        switch(random(6)){
        case 0..3:
	obj=new("/d/islands/argentrock/obj/golden_whip.c");
		if(random(4)){
			obj->set_property("monsterweapon",1);
		}
        obj->move(TO);
        break;
        default:
        obj=new("/d/islands/argentrock/obj/demon_tail.c");
		if(random(4)){
			obj->set_property("monsterweapon",1);
		}
        obj->move(TO);
        break;
        }
	obj=new("/d/common/obj/rand/rand_leath_head.c");
		obj->set_property("enchantment",2);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
   	if(random(5) < 1){
      	obj = new("/d/magic/scroll");
      	obj->set_av_spell(9-random(3));
      	obj->move(TO);
   	}
   		obj = new("/d/magic/scroll");
   		obj->set_av_spell(6-random(2));
   		obj->move(TO);
	command("wield whip");
	command("wearall");
break;
case 4:
     	set_class("ranger");
     	set_mlevel("ranger",query_hd());
     	set_guild_level("ranger",query_hd());
     	add_search_path("/cmds/ranger");
     	set_stats("strength",17);
     	set_stats("dexterity",18);
	switch(random(6)){
        case 0..1:
        obj=new("/d/islands/argentrock/obj/demon_claws.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
        obj=new("/d/islands/argentrock/obj/demon_claws.c");
		if(!random(3))
		{
		obj->set_property("monsterweapon",1);
		}
        obj->move(TO);
        break;
        case 2..3:
        obj=new("/d/islands/argentrock/obj/bonebow.c");
		if(!random(3))
		{
		obj->set_property("monsterweapon",1);
		}
        obj->move(TO);
        break;
        default:
        obj=new("/d/islands/argentrock/obj/hellfire_coil.c");
        obj->set_property("monsterweapon",1);
	obj->move(TO);
        obj=new("/d/islands/argentrock/obj/hellfire_coil.c");
		if(!random(3))
		{
		obj->set_property("monsterweapon",1);
		}
        obj->move(TO);
        break;
        }
	obj=new("/d/islands/argentrock/obj/purple_hide.c");
		if(random(3))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/rand_leath_head.c");
		obj->set_property("enchantment",2);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield claws");
	command("wield claws 2");
	command("wield bow");
	command("wearall");
break;
default:
     	set_class("mage");
     	set_mlevel("mage",query_hd());
     	set_guild_level("mage",query_hd());
	set_class("fighter");
     	set_mlevel("fighter",query_hd());
     	set_guild_level("fighter",query_hd());
	add_search_path("/cmds/fighter");
	set_class("thief");
     	set_mlevel("thief",query_hd());
     	set_guild_level("thief",query_hd());
	add_search_path("/cmds/thief");
	set_scrambling(1);
	set_parrying(1);
     	set_stats("charisma",18);
     	set_stats("dexterity",19);
	set_spell_chance(85);
	set_spells( ({
		"acid breath",
		"ball lightning",
		"scorcher",
		"prismatic spray",
		"acid orb",
		"powerword stun",
		"hideous laughter",
		"magic missile",
		"greater shout",
		"dispel magic"}) );
	obj=new("/d/islands/argentrock/obj/purple_hide.c");
		if(random(4))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/psiblade.c");
		if(random(3))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/islands/argentrock/obj/psiblade.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/rand/rand_leath_head.c");
		obj->set_property("enchantment",2);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield knife");
	command("wield knife 2");
	command("wearall");
	if(random(5) < 1){
      	obj = new("/d/magic/scroll");
      	obj->set_av_spell(9-random(4));
      	obj->move(TO);
   	}
   		obj = new("/d/magic/scroll");
   		obj->set_av_spell(6-random(1));
   		obj->move(TO);
break;
}
	//obj = new("/d/common/obj/potion/healing");
   	//obj->move(TO);
   	//obj->set_uses(random(15)+15);
    set_property("add kits",random(15)+15);
	set_size(2);
	add_money("gold",random(400));
	add_money("silver",random(200));
	add_money("platinum",random(80));
	add_money("electrum",random(300));
	set_hp(800+(random(150)));
        set_property("swarm",1);
        set("aggressive",25);
	set_speed(30);
        set("aggressive","aggfunc");
	set_funcs(({"special"}));
	set_func_chance(35);
        set_property("no bow",1);
	set_property("no dominate",1);
	set_property("no trip",1);
	set_property("no paralyze",1);
	set_exp( 400*query_hd() );
        set_max_level(36);
	set_languages( ({ "elven" }) );
    if(!random(9)) {
      obj = new("/d/common/obj/brewing/herb_special_inherit");
      obj->set_herb_name("corrupted fey lifeblood");
      obj->move(TO);
    }
}
int aggfunc() {
   force_me("watch");
   force_me("stab "+TPQN+"");
   force_me("kill "+TPQN+ "");
}

void special(object target) {
   tell_room(ETO,"%^RED%^The fey'ri reaches out with a taloned hand to "+target->QCN+","+
		" sending "+target->QO+" screaming in agony!",target);
   tell_object(target,"%^RED%^The fey'ri lays its hand on"+
		" you.  You feel your blood start to boil as a cold sweat breaks out!");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(6,3))+10);
   TO->remove_property("magic");
}
void heart_beat(){
        ::heart_beat();

	if(!objectp(TO) || !objectp(ETO)) return;
      /*if(query_hp()< 140 && present("vial",TO)){
      	force_me("open vial");
      	force_me("quaff vial");
      	force_me("offer bottle");
		force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        	force_me("quaff vial");
        	force_me("offer bottle");
        }*/
}
