#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("Blink Roach");
   set_short("A big cockroach");
   set_id(({"bug","blinkroach","monster","cockroach","big roach","roach"}));
   set_long(
    "This fist sized bug looks disgusting.  It has six legs and "+
    "antenna sticking out of the head.  Most of the body is various "+
    "shades of brown.  It has grown large for a bug.  It is about one"+
	" foot long and looks to weigh about 5 pounds.  However, there seems to be a magical "+
    "aura about this bug.  It almost seems to glow.");
   set_gender("male");
   set_race("cockroach");
   set_body_type("insectoid");
   set_size(1);
   set_alignment(5);
   set_stats("strength",8 + random(2));
   set_stats("intelligence",3);
   set_stats("wisdom",3);
   set_stats("dexterity",20);
   set_stats("charisma",3);
   set_stats("constitution",16);   
   set_hd(6,5);
   set("aggressive",10);
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   set_level(10);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_hp(random(100)+65);
   set_property("damage resistance",5);
   //set_exp(1000);
   set_new_exp(10,"very low");
   set_overall_ac(6);
   add_limb("mouth","head",0,0,0);
   set_damage(1,4);
   set_attacks_num(1);
   set_base_damage_type("slashing");
   //set_attack_limbs(({"mouth","mandibles"}));
   set_hit_funcs((["mouth" : "%^BOLD%^The bug bites through"+
      " an opening your armor."]));
   set_emotes(2,({
   "The roach crawls around looking for food.",
   "The roach eats something soft and gross.",
   "The bug shimmers with a %^YELLOW%^yellow light.",
   "The bug crawls up on the wall.",
   "The roach searches for other bugs.",
   "The roach makes some strange sounds.",
   }),0);
   set_max_level(12);
   add_attack_bonus(10+random(5));
   set_base_damage_type("slashing"); 

}

int query_blinking() {
   return 1;
}

void heart_beat() {
    ::heart_beat();


    if(!objectp(TO)) return;

    if((int)TO->query_hp() < 50) {
        TO->force_me("emote %^BOLD%^scurries away");
        TO->force_me("flee");
        return;
    }
}
