#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;


void create()
{
      object ob;
  	::create();
  	set_name("shadow");
  	set_id(({"shadow","dream mon"}));
  	set_short("A shadow");
  	set_long("%^BOLD%^%^BLACK%^You can just barely detect "+
		"something moving about you.  "+
        	"As you look towards the movement, everything seems suddenly "+
        	"still.  You stare ahead, and begin to make out the outline "+
        	"of humanoid, blending in completely with the darkness.");
  	set_property("undead",1);
  	set_race("shadow");
  	set_body_type("human");
  	set_gender("male");
  	set_hd(25,2);
  	set_class("fighter");
  	set_mlevel("fighter",25);
  	set_attack_limbs(({"right hand","left hand"}));
  	set_attacks_num(2);
  	set_base_damage_type("slashing");
  	set_damage(1,6);
  	set_stats("dexterity",18);
  	set_hit_funcs((["left hand":(:TO,"drainem":)]));
  	set_overall_ac(-3);
  	set_alignment(9);
	set("aggressive",25);
  	set_hp(random(20)+270);
      set_property("swarm",1);
	set_speed(30);
	set_nogo(({ROOMDIR"pedestal"}));
	set_exp(3000);
	set_max_level(32);
  	add_search_path("/realms/cythera/dreams/mons");
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("dream fragment");
      ob->move(TO);
    }
}

int drainem(object targ)
{
  	string str = targ->query_name();
  	force_me("drainstr "+str);
}
