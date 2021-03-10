#include <std.h>
#include "../keep.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  set_name("spider");
  set_id(({"spider","hairy spider"}));
  set_short("A hairy spider");
  set_long("Crawling around your feet is a vicious looking spider.  "+
	"It is less than a foot across, but its large head and fangs "+
	"seem imposing.  Long, hairy legs come together upon a small, "+
	"furry body.");
  set_race("spider");
  set_body_type("arachnid");
  set_gender("neuter");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  set_level(3);
  set_class("fighter");
  set_mlevel("fighter",3);
   set_max_hp(25+random(7));
   set_hp(query_max_hp());
   set_exp(80);
   set_max_level(3);
   set_damage(1,4);
  set_attacks_num(1);
  set_base_damage_type("piercing");
  set_attack_limbs(({"right pincer","left pincer","mouth"}));
  set_hit_funcs((["mouth":(:TO,"bite":)]));
  set_ac(5);
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
    targ->do_damage("torso",random(5)+3);
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
