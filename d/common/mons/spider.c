#include <std.h>
inherit WEAPONLESS;

void create()
{
  ::create();
  set_name("spider");
  set_id(({"spider","hairy spider","staff_spider","giant spider"}));
  set_short("A giant spider");
  set_long("This massive spider has a body nearly a foot wide.  Its "+
     "long legs are covered in short, spiky hairs, and each leg ends "+
     "in a tiny hook.  The underbelly of the spider reveals a distinctive "+
     "red hourglass that hints at the danger waiting in the spider's "+
     "wide mouth.");
  set_race("spider");
  set_body_type("arachnid");
  set_gender("neuter");
  set_size(1);
  set_property("swarm",1);
  set_level(8);
  set_class("fighter");
  set_mlevel("fighter",8);
   set_max_hp(100+random(50));
   set_hp(query_max_hp());
   set_exp(40);
   set_max_level(8);
   set_damage(1,6);
  set_attacks_num(2);
  set_base_damage_type("piercing");
  set_attack_limbs(({"right pincer","left pincer","mouth"}));
  set_hit_funcs((["mouth":(:TO,"bite":)]));
  set_ac(-2);
  set_alignment(9);
  set_emotes(6,({
	"%^CYAN%^The hairy spider darts between your feet, trying "+
	"to climb up your legs!%^RESET%^",
	"%^CYAN%^The hairy spider bends back on just four of its legs, "+
	"raising the front four up aggressively and hisses "+
	"loudly at you.%^CYAN%^"
  }),1);
}

int bite(object targ)
{
  if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",2))
  {
    tell_object(targ,"%^RED%^The spider darts up the wall then leaps towards "+
	"your face, biting at your face and neck!");
    tell_room(ETO,"%^RED%^The spider darts up the wall and leaps towards "+
	""+targ->query_cap_name()+", biting at "+
	""+targ->query_possessive()+" face!%^RESET%^",targ);
    tell_object(targ,"%^RED%^The spider's weak poison burns your flesh for "+
	"few moments before the pain subsides.%^RESET%^");
    targ->do_damage("torso",random(6)+5);
    return 1;
  }
  else 
  {
    tell_object(targ,"%^RED%^The spider darts up the wall then leaps towards "+
	"your face, biting at your face and neck!%^RESET%^");
    tell_room(ETO,"%^RED%^The spider darts up the wall and leaps towards "+
	""+targ->query_cap_name()+", biting at "+
	""+targ->query_possessive()+" face!%^RESET%^",targ);
    return 1;
  }
}
