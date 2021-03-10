//stealdragon.c
//moved attack limb stuff to below body type set & added mouth as a body part 
//(didn't exist for dragon) because he wasn't fighting back any more.  Also 
//added the set guild levels so he'll cast the mage spells.
//Garrett & Styx 7/31/01

#include <std.h>

inherit WEAPONLESS;

string *encountered;
string *bencountered;

void create(){
	::create();
	set_name("steel dragon");
	set_id(({"dragon","Dragon","steeldragon","steel dragon","steel"}));
	set_short("A steel dragon");
	set_long(
@OLI
	%^BOLD%^%^CYAN%^This enormous creature stands before you in an awe inspiring rage. 
Rarely will the Steel Dragon return to its true form, and only when 
angered to the point of violence. Its body is close to 80 feet in length
with a tail at least 50 feet long. The steel blue scales cover the body
in a shimmering splendor. 
OLI
	);

	set_hd(29,8);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
	set_mlevel("mage",28);
	set_mlevel("cleric",28);
	set_mlevel("fighter",28);
	set_guild_level("cleric",20);
	set_guild_level("mage",20);
	set_guild_level("fighter",28);
	set_hp(300);
	set_mob_magic_resistance("average");
	set_exp(30000);
	set_overall_ac(-7);
	set_size(4);
    set_max_level(30);
 	set_race("dragon");
	set_body_type("dragon");
	add_limb("mouth", "head", 0, 0, 0);
	set_attack_limbs(({"right foreclaw","mouth","left foreclaw"}));
	set_attacks_num(3);
	set_damage(2,8);
	set_base_damage_type("slashing");
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",10);
	set_stats("wisdom",10);
	set_stats("charsima",0);
	set_stats("constitution",25);
	set_gender("male");
	set_funcs(({"attack"}));
	set_func_chance(102);
	set_guild_level("mage",28);
	set_spells(({"lightening bolt","cone of cold","magic missile","scorcher","fireball"}));
	set_spell_chance(0);
    add_money("gold",500);
	add_money("platinum",random(50));
	add_money("silver",random(8000));
	add_money("electrum",random(5000));
	set_property("no steal",1);
	set_alignment(1);
	set_property("alignment adjustment",-20);
	bencountered = ({});
	encountered = ({});
	}
	
void attack(object targ){
	
	tell_room(ETO,"%^BOLD%^%^B_GREEN%^A thick cloud of smoke is spewn into the fight.");
	tell_room(ETO,"%^BOLD%^%^B_GREEN%^Somehow the dragon has shaped it into a cube to exactly surround "+targ->query_cap_name()+".",targ);
	tell_object(targ,"%^BOLD%^%^B_GREEN%^Somehow the dragon has shaped it into a cube to exactly surround you!\n");
		
    if((!targ->query_property("strength") || (targ->query_property("strength") && !stringp(targ->query_property("strength"))) && (member_array("breath weapon",targ->query_property("strength")) == -1 )))
    {
    	if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-3))
        {
	    	tell_object(targ,"%^BOLD%^%^RED%^You breath in the noxous fumes and feel it seeping into your skin.");
			tell_object(targ,"%^BOLD%^%^RED%^You feel the poison cutting off all the feeing in your body.");
			tell_object(targ,"%^BOLD%^%^RED%^You are dying.");
            set_property("magic",1);
			targ->do_damage(targ->return_target_limb(),roll_dice(29,10)+29);
			tell_room(ETO,"%^BOLD%^%^YELLOW%^You can almost feel the pain of death that "+targ->query_cap_name()+" is going through.");
            remove_property("magic");
	        set_func_chance(25);
	        set_spell_chance(50);
			return;
		}

        tell_object(targ,"%^BOLD%^You some how survive the massive ammounts of poison being obsorbed by your skin.");
		tell_object(targ,"%^BOLD%^But it still does much damage.");
		tell_room(ETO,"%^BOLD%^You see pain crease the face of "+targ->query_cap_name()+"!",targ);
        set_property("magic",1);
		targ->do_damage(targ->return_target_limb(),roll_dice(7,4));
        remove_property("magic");
	    set_func_chance(25);
	    set_spell_chance(50);
		return;
	}
	    
    tell_object(targ,"%^BOLD%^You can feel the cube of smoke passing over you, but are somehow protected!");
    tell_room(ETO,"%^BOLD%^You see "+targ->QCN+" wince as the cube passes over them, then sigh in relief!",targ);
	
	set_func_chance(25);
	set_spell_chance(50);
	return;
}		
	
void die(object thing){
	object ob;
	
	ob = new("std/obj/body_part");
	ob->set_limb("Steel Dragon","head");
	ob->set_id(({"limb","head","dragon head","Forest Quest","good head"}));
	ob->move(ETO);
	return ::die(thing);
}

void set_encountered(string *input){
	encountered = input;
	}

void set_bencountered(string *input){
	bencountered = input;
	}
	

void heart_beat(){
	::heart_beat();
	
	if(query_attackers() == ({}) && find_call_out("come_back") == -1)
		call_out("come_back",60);
}

void come_back(){
	object ob;
	
	if(query_attackers() != ({}))
		return;
	tell_room(ETO,
@OLI
	%^BOLD%^%^B_CYAN%^The swirling mist over comes the dragon
As it clears it reveals the old leader returned
OLI
	);
	ob = new("/d/tharis/monsters/old_leader");
	ob->set_hp(query_hp());
	ob->set_encountered(encountered);
	ob->set_bencountered(bencountered);
	ob->move(ETO);
      ob=present("questob",TO);
      if (objectp(ob)) ob->remove();
	remove();
}

void init(){
	::init();
	if(ALIGN->is_evil(TP) || member_array(TPQN,bencountered) != -1)
		kill_ob(TP,1);
}

void set_paralyzed(int time,string message){
	return 1;
}
