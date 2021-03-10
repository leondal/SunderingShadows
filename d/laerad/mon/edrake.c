//Updated description and mechanics - Octothorpe 11/10/09
//Changed from only being earth drake to elemental drake, based on one of the elemental planes
//Based upon class creation code from hordlings
///d/laerad/mon/hordling.c
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon *Styx* 12/20/03, last change 8/19/99

#include <std.h>
inherit WEAPONLESS;

void make_me();
void create(){
    ::create();
    set_name("elemental drake");
    set_body_type("dragon");
    set_race("drake");
    set_gender("male");
    set_size(3);
    set_hd(27,150);
    set_max_level(26);
    set_hp(600);
    set_exp(20000);
    set_overall_ac(-8);
    set("aggressive",24);
    set_mob_magic_resistance("average");
    set_attack_limbs(({"right foreclaw","left foreclaw","head","tail"}));
    set_attacks_num(4);
    set_base_damage_type("slashing");
    set_damage(2,20);
    set_stats("strength",23);
    set_stats("dexterity",13);
	set_guild_level("cleric",27);
    add_money("gold",random(2000)+3000);
    add_money("silver",random(1000)+1500);
    add_money("copper",random(200)+350);
    add_money("electrum",random(400)+600);
    add_money("platinum",random(10)+5);
    set_funcs(({"shake"}));
	add_search_path("/cmds/priest");
    set_func_chance(40);
    if(!random(20)) new("/d/laerad/obj/wand_para.c")->move(TO);
	set_moving(1);
	set_speed(70);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
    make_me();
}

void make_me(){
    object ob;
    int i;
    i = random(4);
    switch(i){
       case(0): 
	      set_id(({"elemental drake","drake","earth drake","laeradmon"}));
	      set_short("%^RESET%^%^GREEN%^f%^ORANGE%^ie%^GREEN%^rc"+
		     "%^ORANGE%^e ea%^GREEN%^rth dr%^ORANGE%^a%^GREEN%^k"+
			 "%^ORANGE%^e%^RESET%^");
	      set_long("%^RESET%^%^GREEN%^This creature resembles a "+
		     "gigantic iguana, measuring around twenty feet long, and "+
			 "seven feet tall.  It is powerfully built, with sturdy "+
			 "legs bearing clawed toes that can latch onto rocky "+
			 "terrain.  The drake's skin is hardened into a patchwork "+
			 "of scales and flesh.  The head is somewhat draconic in "+
			 "nature, but lacks the characteristic ridges and horns "+
			 "typically found, although the drake's maw is full of "+
			 "sharp teeth which makes the resemblance close "+
			 "enough.%^RESET%^");
		  set_alignment(2);
		  remove_limb("right wing");
          remove_limb("left wing");
		  set_spells(({"earth reaver","maw of stone","earthquake"}));
              ob = new("/d/common/obj/brewing/herb_special_inherit");
              ob->set_herb_name("living stone");
              ob->move(TO);
        break;
		case(1):
		   set_id(({"elemental drake","drake","fire drake","laeradmon"}));
		   set_short("%^RESET%^%^RED%^f%^BOLD%^ie%^RESET%^%^RED%^rc"+
		      "%^BOLD%^e %^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^r"+
			  "%^BOLD%^e %^RESET%^%^RED%^dr%^BOLD%^a%^RESET%^%^RED%^"+
			  "k%^BOLD%^e%^RESET%^");
		   set_long("%^RESET%^%^RED%^This creature resembles a "+
		     "small dragon, measuring around twenty feet long, and "+
			 "seven feet tall.  It is powerfully built, with sturdy "+
			 "legs bearing clawed toes that can latch onto rocky "+
			 "terrain.  The drake's skin is hardened into a patchwork "+
			 "of scales and flesh.  The head is somewhat draconic in "+
			 "nature, but lacks the characteristic ridges and horns "+
			 "typically found, although the drake's maw is full of "+
			 "sharp teeth which makes the resemblance close "+
			 "enough.%^RESET%^");	  
		   set_alignment(6);
		   set_spells(({"flameburst","handfire","fire storm"}));
		break;
                case(2):
		   set_id(({"elemental drake","drake","ice drake","laeradmon"}));
		   set_short("%^BOLD%^%^WHITE%^f%^RESET%^%^CYAN%^ie%^BOLD%^%^WHITE%^rc"+
		      "%^RESET%^%^CYAN%^e i%^BOLD%^%^WHITE%^c%^RESET%^%^CYAN%^e "+
			  "%^BOLD%^%^WHITE%^dr%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^k"+
			  "%^RESET%^%^CYAN%^e%^RESET%^");
		   set_long("%^BOLD%^%^WHITE%^This creature resembles a "+
		     "small dragon, measuring around twenty feet long, and "+
			 "seven feet tall.  It is powerfully built, with sturdy "+
			 "legs bearing clawed toes that can latch onto rocky "+
			 "terrain.  The drake's skin is hardened into a patchwork "+
			 "of scales and flesh.  The head is somewhat draconic in "+
			 "nature, but lacks the characteristic ridges and horns "+
			 "typically found, although the drake's maw is full of "+
			 "sharp teeth which makes the resemblance close "+
			 "enough.%^RESET%^");	  
		   set_alignment(9);
		   set_spells(({"frost breath","hypothermia","frozen breath"}));
		break;
                case(3):
		   set_id(({"elemental drake","drake","air drake","laeradmon"}));
		   set_short("%^BOLD%^%^CYAN%^fierce %^WHITE%^ai%^CYAN%^r drake%^RESET%^");
		   set_long("%^BOLD%^%^CYAN%^This creature resembles a "+
		     "small dragon, measuring around twenty feet long, and "+
			 "seven feet tall.  It is powerfully built, with sturdy "+
			 "legs bearing clawed toes that can latch onto rocky "+
			 "terrain.  The drake's skin is hardened into a patchwork "+
			 "of scales and flesh.  The head is somewhat draconic in "+
			 "nature, but lacks the characteristic ridges and horns "+
			 "typically found, although the drake's maw is full of "+
			 "sharp teeth which makes the resemblance close "+
			 "enough.%^RESET%^");	  
		   set_alignment(8);
		   set_spells(({"airbolt","windstorm"}));
	}
	set_spell_chance(40);
}

void shake(object targ){
    int roll, ac;
    if(!objectp(targ)) return;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 0-ac){
	tell_object(targ,"%^BOLD%^RED%^The drake tears into you with its massive jaws!");
     	tell_room(ETO,"%^BOLD%^RED%^The drake tears into "+targ->QCN+" with its massive jaws!",targ);
	targ->do_damage("torso",roll_dice(4,12));
	if("/daemon/saving_throw_d.c"->reflex_save(targ,-20)){

	    tell_object(targ,"%^BOLD%^RED%^The drake grasps you firmly in its teeth!");
	    tell_room(ETO,"%^BOLD%^RED%^The drake grasps "+targ->QCN+" firmly in its teeth!",targ);
	    call_out("berserk",9,targ);
	} else {
	tell_object(targ,"%^BOLD%^RED%^You slip from the Earth Drakes teeth!");
	tell_room(ETO,"%^BOLD%^RED%^"+targ->QCN+" slips from the Earth Drakes teeth!",targ);
	return 1;
	}
    } else {
    tell_object(targ,"%^BOLD%^RED%^The drake bites at you viciously but misses!");
    tell_room(ETO,"%^BOLD%^RED%^The drake bites at "+targ->QCN+" viciously but misses!",targ);
    return 1;
    }
}
void berserk(object targ){
    if(!objectp(targ)) return;
	if(!objectp(TO)) return;
    tell_object(targ,"%^BOLD%^RED%^The drake shakes you back and "+
	   "forth violently in its teeth shreding you to pieces!");
    tell_room(ETO,"%^BOLD%^RED%^The drake shakes "+targ->QCN+" back "+
	   "and forth violently in its teeth shreding "+targ->QO+" to pieces!",targ);
    targ->do_damage("torso",roll_dice(3,12));
    return 1;
}
