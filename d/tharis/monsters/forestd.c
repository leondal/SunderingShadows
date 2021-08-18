//forestd.c
//moved attack limb stuff to below body type set & added mouth as a body part 
//(didn't exist for dragon) because he wasn't fighting back any more.  Also 
//added the set guild levels so he'll cast the mage spells.
//Garrett & Styx 7/31/01

#include <std.h>

inherit WEAPONLESS ;

int flag;

void create(){
	::create();
	set_name("forest linnorm");
	set_id(({"dragon","Dragon","forestd","forest dragon","forest", "linnorm", "forest linnorm"}));
	set_short("A forest Linnorm");
	set_long(
@OLI
	This long, snakelike creature is more commonly known as a dragon.
Its molted green and brown skin is broken only by the spots where 
its legs used to be. This enormous creature has a body length of
about 85 feet and a tail that must be 170 feet long. The sheer size of 
this creature makes you shiver. What truly sends fear through you is the
gaze that he gives!
OLI
	);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
	set_mlevel("mage",28);
	set_mlevel("cleric",28);
	set_mlevel("fighter",28);
	set_guild_level("cleric",20);
	set_guild_level("mage",20);
	set_guild_level("fighter",28);
	set_hd(28,8);
    set_level(28);
	set_hp(300);
	set_mob_magic_resistance("average");
	set_exp(30000);
	set_overall_ac(-7);
	set_size(3);
	set_race("linnorm");
	set_body_type("dragon");
	remove_limb("right wing");
	remove_limb("left wing");
	remove_limb("right foreleg");
	remove_limb("right foreclaw");
	remove_limb("left foreleg");
	remove_limb("left foreclaw");
	remove_limb("right rear leg");
	remove_limb("left rear leg");
	remove_limb("right rear claw");
	remove_limb("left rear claw");
    set_max_level(25);
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",10);
	set_stats("wisdom",10);
	set_stats("charisma",10);
	set_stats("constitution",25);
	set_gender("male");
	set_attacks_num(3);
	set_damage(2,8);
	set_base_damage_type("slashing");
	add_limb("mouth", "head", 0, 0, 0);
	set_attack_limbs(({"mouth"}));
	set_funcs(({"attack"}));
	set_func_chance(102);
	set_spells(({"magic missile","fireball","lightning bolt","scorcher"}));
	set_spell_chance(0);
    add_money("gold",200);
	add_money("platinum",random(50));
	add_money("silver",random(800));
	add_money("electrum",random(5000));
	set_property("no steal",1);
	set_alignment(9);
	set_property("alignment adjustment",20);
	flag = 0;
	}

void attack(object targ){

	if(!flag){
		new("/cmds/spells/s/_sticks_into_snakes")->use_spell(TO,targ->query_name(),23,100,"cleric");
		flag = 1;
		call_out("reset_flag",1000);
	}

	tell_room(ETO,"%^BOLD%^%^GREEN%^The Linnorm releases a huge spout of horrible looking acid into the fight!");
	if(random(10) < 7)
    {
		if((targ->query_property("strength") && !stringp(targ->query_property("strength"))) && (member_array("breath weapon",targ->query_property("strength")) != -1 || member_array("acid",targ->query_property("strength")) != -1))
        {
	        tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->query_cap_name()+" is overwhelmed with a torrent of acid!",targ);
			tell_object(targ,"%^BOLD%^%^GREEN%^You are overwhelmed by the horrible river of acid. But you are left unharmed!");
		    set_func_chance(25);
	        set_spell_chance(50);
            return;
		}
	    tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->query_cap_name()+" is overwhelmed with a torrent of acid!",targ);
	    tell_object(targ,"%^BOLD%^%^GREEN%^You are overwhelmed by the horrible river of acid. You feel it burning at you! It seems to infest you!\n");
	    targ->do_damage(targ->return_target_limb(),(roll_dice(28,4)+12));
	    targ->add_poisoning(10);
	    set_func_chance(25);
	    set_spell_chance(50);
	    return;
    }
	 
    else { tell_room(ETO,"%^BOLD%^%^GREEN%^Somehow the acid splashes into the fight without hitting anyone!");	}

	set_func_chance(25);
	set_spell_chance(50);
    return;
}

void reset_flag(){
	flag = 0;
	}


void die(object thing){
	object ob, hammer, room;
    
    room = environment(this_object());

	ob = new("std/obj/body_part");
	ob->set_limb("Forest Linnorm","head");
	ob->set_id(({"limb","head","dragon head","Forest Quest","evil head"}));
	ob && room && ob->move(room);
    
    hammer = new("/d/tharis/obj/verdant_hammer");
    hammer && hammer->move(environment(this_object());
    
	return ::die(thing);
}

void set_paralyzed(int time,string message){
	return 1;
}
