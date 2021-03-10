#include <std.h>
inherit WEAPONLESS;

void create()
{
   object ob;
   ::create();
   set_name("blink dog");
   set_short("A little yellow dog");
   set_id(({"dog","blink dog","monster","yellow dog","little dog","little yellow dog"}));
   set_long(
   "The wild dog is a bit stockier and more well muscled than most. Its"+
   " hide is a %^YELLOW%^yellowish%^RESET%^%^CYAN%^ shade. It appears to"+
   " be sleek and well muscled. There is something not quite right about"+
   " the animal, however."
   );
   set_gender("male");
   set_race("dog");
   set_body_type("quadruped");
   set_size(2);
   set_alignment(1);
   set_hd(6,5);
   set("aggressive",10);
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   //set_level(10);
   //set_class("fighter");
   //set_mlevel("fighter",10);
   set_hp(random(20)+65);
   set_stats("intelligence",18);
   set_exp(275);
   set_overall_ac(6);
   add_limb("mouth","head",0,0,0);
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
   set_hit_funcs((["mouth" : "The dog bites you viciously."]));
   set_emotes(2,({
   "The dog sniffs you curiously.",
   "The dog issues a series of low growls.",
   "The dog yaps happily.",
   "The dog surveys his surroundings.",
   "The dog perks his ears up.",
   "The dog wags his tail.",
   }),0);
   set_max_level(12);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

int query_blinking() {
   return 1;
}
