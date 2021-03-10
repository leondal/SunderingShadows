#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
      object ob;
	::create();
	set_name("nightmare shadow");
	set_short("A flickering shadow");
	set_id(({"shadow","flickering shadow","nightmare","nightmare shadow","shade","dreammon"}));
	set_long(
         "%^BOLD%^%^BLACK%^This hideous shadow flickers and "+
         "writhes, constantly shifting shape.  Hidden within "+
         "its depths, you find the stuff of your worst "+
         "nightmares!  It seems to have no definite form, nor "+
         "does it seem to have the senses we do.  It exists "+
         "for one purpose alone - to terrify the one it sets "+
         "its sights upon!"
	);
	set_gender("neuter");
	set_race("nightmare");
	set_body_type("human");
	set_hd(16,5);
	set_max_hp(250+random(75));
	set_hp(query_max_hp());
	set_alignment(9);
	set_max_level(25);
	set_overall_ac(-10);
	set_class("fighter");
	set_mlevel("fighter",16);
	set_level(16);
	set_exp(4000);
	set_stats("strength",18);
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set_mob_magic_resistance("average");
	set_property("magic",1);
      set_funcs(({"weird"}));
      set_func_chance(50);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("dream fragment");
      ob->move(TO);
    }
}

void weird(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   if(!present(targ)) return;
   if(targ->query_paralyzed()) return;
   if(!SAVING_D->saving_throw(targ,"spell",-2)){
      tell_object(targ,"%^BOLD%^%^RED%^The nightmare shade "+
         "stretches forth and horrendous images fill your "+
         "mind, freezing you in terror!");
      tell_room(ETO,"%^RED%^The nightmare shade stretches "+
         "toward "+targ->QCN+", and "+targ->QS+" freezes!",targ);
      targ->set_paralyzed(roll_dice(3,4),"You are quivering in fear!");
      return;
   }else{
      tell_object(targ,"%^RED%^The nightmare shade reaches "+
         "for you, but you resist his touch!");
      tell_room(ETO,"%^RED%^The nightmare shade stretches "+
         "toward "+targ->QCN+", but "+targ->QS+" resists!",targ);
      return;
   }
}