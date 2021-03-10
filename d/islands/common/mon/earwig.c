#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("giant earwig scorpion");
    set_id(({"giant earwig scorpion","scorpion","earwig", "earwig scorpion"}));
    set_short("Giant earwig scorpion");
    set_long("
     One of the most feared creatures of the desert is the Earwig Scorpion.  The Earwig Scorpion builds large sandtraps in the desert that catch pray that happen to wander into the area.  They grapple their pray with enormous twenty foot pincers and pull them under the sand.  They also have a scorpion like sting.
");
    set_race("earwig scorpion");
    set_hd(21,10);
    set_level(30);
    set_size(5);
    set_overall_ac(-8);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_max_hp(310);
    set_hp(310);
    set_wielding_limbs(({"right pincer","left pincer"}));
       add_limb("right pincer","right pincer",96,1,4);
       add_limb("left pincer","left pincer",96,1,4);
      add_limb("tail","tail",96,1,4);
      add_limb("stinger","stinger",96,1,4);
    set_attacks_num(2);
set_attack_limbs(({"left pincer", "tail", "right pincer"}));
   set_base_damage_type("piercing");
    set_funcs(({"sting"}));
    set_func_chance(25);
    set_damage(2,8);
    set_body_type("arachnid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",20);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(6000);
    set_alignment(5);
}
void die(object ob) {
    message("environment",
    "Giant earwig scorpion's pincers release you.\n""%^RED%^Giant earwig scorpion slips back into the sands."
    ,environment(TO));
    :: die(ob);
}
int aggfunc() {
	TP->kill_ob(TO,0);
      force_me("emote rises from the sands and grapples you with its pincers, pulling you down into a pit!");
}
void sting(object targ) {
    string dam;
   if("daemon/saving_d"->saving_throw(targ,"paraylzation_poison_death")) {
       dam="wounding";
    } else {
       dam="poisoning";
    }
    tell_object(targ,
    "%^RED%^Giant earwig scorpion pierces you in the torso with its stinger, "+dam+" you!"
  );
    tell_room(environment(targ),
  "%^BLUE%^Giant earwig scorpion pierces "+targ->query_cap_name()+" in the torso with its stinger, "+dam+" "+targ->query_objective()+"!"
   ,targ);
    if(dam=="poisoning") {
        targ->do_damage("torso",roll_dice(2,6));
        targ->add_poisoning(20);
        tell_object(targ,
   "You feel a horrible numbness in your body as the poison takes effect.");
        targ->set_paralyzed(random(30)+10,
   "You are paralyzed.");
   } else {
        targ->do_damage("torso",roll_dice(2,6));
    }
return 1;
}
