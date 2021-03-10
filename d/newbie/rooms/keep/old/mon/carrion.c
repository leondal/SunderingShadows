#include <std.h>
#include "../keep.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  set_name("young carrion crawler");
  set_id(({"crawler","carrion crawler","young carrion crawler","young crawler"}));
  set_short("A young carrion crawler");
  set_long(
  "This carrion crawler is still quite young, but is already several feet"+
  " in length and has eight deadly tentacles that it uses to grab its prey."+
  " Carrion crawlers are usually just scavengers, but this one appears to"+
  " have been stuck here for a while and seems willing to try and eat just"+
  " about anyone. You wonder how it might have gotten itself in here at"+
  " all, actually."
  );
  set_race("worm");
  set_body_type("snake");
  set_gender("neuter");
  set_size(2);
  set("aggressive",25);
  set_property("swarm",1);
  set_level(7);
  set_class("fighter");
  set_mlevel("fighter",7);
  set_max_hp(40);
  set_hp(100);
  set_exp(1500);
  set_damage(1,2);
  set_attacks_num(8);
  add_limb("tentacles","head",0,0,0);
  set_base_damage_type("slashing");
  set_attack_limbs(({"tentacles"}));
  set_stats("strength",16);
  set_stats("dexterity",16);
  set_ac(7);
  set_alignment(9);
  set_funcs(({"charge"}));
  set_func_chance(20);
  add_money("silver",random(1300)+300);
  add_money("gold",random(50)+20);
}

void charge(object targ)
{
  if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",1))
  {
    tell_object(targ,"%^ORANGE%^The young carrion crawler's tentacle "+
	"lashes out and finds a section of bare skin on you.  You feel "+
	"entire body goes numb! %^RESET%^");
    tell_room(ETO,"%^ORANGE%^"+TQCN+" "+
      "seems to slump over as a tentacle lashes across "+
	""+targ->query_possessive()+" bare skin."+
	"%^RESET%^",targ);
    targ->set_paralyzed(random(5)+5,"Your entire body feels numb!");
    return 1;
  }
  else 
  {
    tell_object(targ,"%^ORANGE%^The young carrion crawler lashes "+
	"out with its tentacles, but bounces harmlessly off of your "+
	"clothing.");
    return 1;
  }
}
