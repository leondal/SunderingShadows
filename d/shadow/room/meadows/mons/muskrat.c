#include <std.h>
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
   object ob;
   ::create();
   set_name("muskrat");
   set_short("A fuzzy brown rodent");
   set_id(({"monster","muskrat","rodent","brown rodent","fuzzy rodent","fuzzy brown rodent"}));
   set_long(
   "This little muskrat is rather cute with a %^ORANGE%^rich brown%^CYAN%^"+
   " coat and a %^RESET%^silvery%^CYAN%^ belly and a %^BOLD%^%^MAGENTA%^pink"+
   " nose%^RESET%^%^CYAN%^ with whiskers that are constantly twitching. At"+
   " the same time it is rather ugly, with a long scaly %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ tail. It is"+
   " a strange animal."
   );
   set_gender("female");
   set_race("muskrat");
   set_body_type("quadruped");
   set_size(1);
   set_alignment(5);
   set_hd(8,5);
   set("aggressive",10);
   set_property("swarm",1);
   //set_class("fighter");
   //set_mlevel("fighter",8);
   //set_hp(random(10)+50);
   set_overall_ac(7);
   set_stats("strength",13);
   set_damage(1,3);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_attack_limbs(({"right forepaw","left forepaw"}));
   set_new_exp(5,"normal");
   set_emotes(8,({
   "The muskrat cleans her face.",
   "The muskrat twitches her tail.",
   "The muskrat twitches her whiskers.",
   "The muskrat sniffs about for food.",
   }),0);
   set_max_level(12);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

void die(object obj)
{
   if(!random(2)) {
      new(OBJ+"pelt")->move(TO);
   }
   ::die(obj);
}
