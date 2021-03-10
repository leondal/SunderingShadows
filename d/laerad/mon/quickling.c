//Coded by Bane//
//Jade sword added by Crystal, tweaks to make them at least somewhat dangerous
//made by Styx.  Note:  Be SURE they stay above level 20 so they can wield the
//swords.  Some of them couldn't before because it has a min. level of 20
//even though it's only +3.

#include <std.h>
inherit "/d/laerad/mon/wander/wander3";

void create(){
    ::create();
    set_id(({"brownie","quickling","Brownie","Quickling"}));
    set_name("Quickling");
    set_short("A Quickling");
    set_long("All you can see is a blur of movement.");
    set_race("brownie");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_hd(random(6)+20,8);
    set_hp(120+query_hd());
    set_overall_ac(-8);
    set_alignment(9);
    set_exp(8000);
    set_class("thief");
    set_mlevel("thief",query_hd()); 
    set_guild_level("thief",query_hd());
    set_mob_magic_resistance("average");
    set_stats("strength",17);
    set_stats("dexterity",22);
    set_stats("charisma",18);
    set_thief_skill("move silently",70);
    set_thief_skill("hide in shadows",70);
    set("aggressive","backstab");
    set_wielding_limbs(({"right hand","left hand"}));
   if(!random(10)) {
      new("/d/laerad/obj/jade_short")->move(TO);
      command("wield sword");
   }
   else {
      new("/d/common/obj/weapon/dagger")->move(TO);
      command("wield dagger");
   }
   new("/d/common/obj/weapon/longsword")->move(TO);
   command("wield sword");
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}

void backstab(){
    int thac, AC, roll, dam, damage;
    cease_all_attacks();
    TP->remove_attacker(TO);
    command("stab "+TP->query_name());
}