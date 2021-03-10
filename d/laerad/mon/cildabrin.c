//Updated description and mechanics - Octothorpe 11/10/09
//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"cildabrin","Cildabrin","laeradmon","magical beast"}));
    set_name("cildabrin");
    set_short("%^BOLD%^%^BLACK%^sc%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^"+
	   "rp%^RESET%^%^CYAN%^io%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^i"+
           "%^BOLD%^%^BLACK%^c cildabrin%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This creature measures thirteen feet "+
	   "across and is appears to be a cross between a tarantula and "+
	   "a scorpion.  Its body is black and furry like that of a "+
	   "tarantula, but the instead of having two normal front legs, "+
	   "it has the pincers of a scorpion. The cildabrin also has the "+
	   "characteristic tail of a scorpion, which ends in a fearsome "+
	   "stinger that is nearly a foot in length.%^RESET%^");
    set_body_type("arachnid");
    set_race("cildabrin");
    set_gender("male");
    set_size(3);
    set_alignment(6);
    set_overall_ac(-3);
    set("aggressive",21);
    set_class("mage");
    set_guild_level("mage",21);
    set_hd(21,32);    // was 11
    set_max_level(22);
    set_hp(220);
    set_attack_bonus(6);
    set_exp(14500);
    set_spells(({"web","darkness"}));
    set_spell_chance(15);
    set_attack_bonus(8);
    set_mob_magic_resistance("average");
    add_limb("tail","abdomen", 0, 0, 0);
    set_attack_limbs(({"tail","right pincer","left pincer"}));
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(2,8);
	set_hit_funcs((["tail":(:TO,"poison":)]));
    set_stats("strength",22);
    set_stats("dexterity",16);
    set_stats("intelligence",10);
    set_stats("wisdom",10);
    set_stats("constitution",15);
    set_stats("charisma",6);
	set_moving(1);
	set_speed(55);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
}

void poison(object targ){
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
        if("/daemon/saving_throw_d.c"->fort_save(targ,-29)){
	   tell_object(targ,"%^BOLD%^The %^BOLD%^%^BLACK%^cildabrin "+
	      "%^WHITE%^impales you with its stinger, injecting %^RESET%^"+
		  "%^GREEN%^poison %^BOLD%^%^WHITE%^into your body!%^RESET%^");
	   tell_room(ETO,"%^BOLD%^The %^BOLD%^%^BLACK%^cildabrin %^WHITE%^"+
	      "impales "+targ->QCN+" with its stinger!%^RESET%^",targ);
	   targ->add_poisoning(10);
	}
	return;
}
