//Updated description and mechanics - Octothorpe 10/20/09
//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"mara","Mara","laeradmon","hulk","hulking mass of stone","mass","stone"}));
    set_name("mara");
    set_short("%^RESET%^h%^BOLD%^u%^RESET%^lk%^BOLD%^i%^RESET%^ng m"+
	   "%^BOLD%^a%^RESET%^ss %^BOLD%^o%^RESET%^f st%^BOLD%^o%^RESET%^n"+
	   "%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^This roughly humanoid mass of st%^BOLD%^o%^RESET%^n"+
	   "%^BOLD%^e %^RESET%^is known as a mara.  It stands over "+
	   "twenty feet in height, and is almost nearly as wide as it "+
	   "is tall.  The mara is nothing more than a walking torso atop "+
	   "two stubby legs.  Almost hidden between its shoulders, the "+
	   "mara's head is awash by a demonic %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d "+
	   "%^RESET%^glow from its eyes, which also illuminates its "+
	   "fearsome hooked beak.");
    set_body_type("human");
    set_race("mara");
    set_gender("neuter");
    set_size(3);
    set_alignment(9);
    set_hd(20,20);   // was 10,20
    set_max_level(20); // was 15
    set_max_hp(350);  // was 100
    set_hp(query_max_hp());     
    set_attack_bonus(4);
    set_exp(14200);
    set_overall_ac(-6);
	set_moving(1);
	set_speed(80);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
    set_mob_magic_resistance("average");
    set_property("strength","paralyzed");
    set("aggressive",19);
    set_attack_limbs(({"right hand","left hand","head"}));
    set_attacks_num(3);
    set_base_damage_type("bludgeoning");
    set_damage(4,8);
    set_stats("strength",22);
    set_stats("dexterity",16);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("constitution",22);
    set_stats("charisma",12);
	set_funcs(({"smash"}));
	set_func_chance(15);
}

int smash(object targ){
   if(!objectp(targ)) return 0;
   tell_room(ETO,"%^RED%^The mara smashes one of its claws into the "+
      "ground with great force, causing "+targ->QCN+" to get "+
	  "knocked to the ground!%^RESET%^",targ);
    tell_object(targ,"%^RED%^The mara smashes the ground next to you "+
	  "with one of its claws, causing you to lose your balance!%^RESET%^");
    targ->set_tripped(random(3)+1, "%^RED%^You are stunned "+
	   "by the concussion!%^RESET%^");
   return 1;
}

void heart_beat(){
   string tod;
   ::heart_beat();
   tod = EVENTS_D->query_time_of_day();
   if(!objectp(TO)) return;
   if(query_attackers() != ({})) return;
   if(tod == "day"){
      tell_room(ETO,"%^YELLOW%^The mara flees from the encroaching "+
	     "rays of the sun.%^RESET%^");
      TO->remove();
   }
}
