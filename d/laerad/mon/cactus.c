//Updated description and mechanics - Octothorpe 10/28/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"cactus","vampire","Vampire Cactus", "laeradmon"}));
    set_name("vampiric cactus");
    set_short("%^RESET%^%^GREEN%^an unusually large c%^YELLOW%^a%^RESET%^"+
	   "%^GREEN%^ctus%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This strange plant stands almost five feet "+
	   "tall, and has twelve fleshy leaves and numerous needles over "+
	   "its surface.  The leaves are a rusty green with a narrow band "+
	   "of %^YELLOW%^y%^ORANGE%^e%^YELLOW%^ll%^ORANGE%^o%^YELLOW%^w "+
	   "%^RESET%^%^GREEN%^around their margins. The needles are "+
	   "mostly %^WHITE%^wh%^BOLD%^i%^RESET%^t%^BOLD%^i%^RESET%^sh "+
	   "%^GREEN%^in color, but you notice that the tips are stained "+
	   "with a %^RED%^reddish %^GREEN%^hue.%^RESET%^");
    set_race("cactus");
    set_body_type("snake");
    set_gender("neuter");
    set_size(2);
    set_hd(15,20);      // was 5,20
    set_max_level(20); // was 15
    set_hp(190);        // was 60
    set_alignment(8);
    set_exp(9000);
    set_overall_ac(5);
    set("aggressive",0);
    set("swarm", 1);       // added this
    remove_limb("head");
    remove_limb("tail");
    remove_limb("mouth");
    add_limb("stalk", "torso", 0, 0, 0);
    add_limb("roots", "torso", 0, 0, 0);
    add_limb("leaf1", "torso", 0, 0, 0);
    add_limb("leaf2", "torso", 0, 0, 0);
    add_limb("leaf3", "torso", 0, 0, 0);
    add_limb("leaf4", "torso", 0, 0, 0);
    add_limb("leaf5", "torso", 0, 0, 0);
    add_limb("leaf6", "torso", 0, 0, 0);
    add_limb("leaf8", "torso", 0, 0, 0);
    add_limb("leaf9", "torso", 0, 0, 0);
    add_limb("leaf10", "torso", 0, 0, 0);
    add_limb("leaf11", "torso", 0, 0, 0);    
    add_limb("leaf12", "torso", 0, 0, 0);
    set_attack_limbs(({"leaf1","leaf2","leaf3","leaf4","leaf5","leaf6","leaf7","leaf8","leaf9","leaf10","leaf11","leaf12"}));
    set_attacks_num(12);
    set_base_damage_type("piercing");
    set_damage(1,4);    // was 1,2
    set_stats("strength",16);
    set_stats("dexterity",2);
    set_stats("intelligence",2);
    set_stats("wisdom",2);
    set_stats("constitution",16);
    set_stats("charisma",2);
	set_funcs(({"blood"}));
	set_func_chance(15);
        set_emotes(10,({"The %^RESET%^%^GREEN%^cactus %^RESET%^sways "+
	   "slightly in the light breeze."}),0);	
}

void blood(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^RESET%^%^GREEN%^The cactus draws %^BOLD%^"+
      "%^RED%^blood %^RESET%^%^GREEN%^with one of its needles, and "+
	  "begins to suck in the %^BOLD%^%^RED%^blood %^RESET%^%^GREEN%^"+
	  "through the needle as if it's a straw!%^RESET%^");
   tell_room(ETO,"%^RESET%^%^GREEN%^The cactus begins to ingest "+
      ""+targ->QCN+"'s %^BOLD%^%^RED%^blood%^RESET%^%^GREEN%^!",targ);
   targ->do_damage(targ->return_target_limb(),random(20)+4);
   TO->add_hp(random(20)+4);
   TO->add_attack_bonus(1);
   return;
}
   
