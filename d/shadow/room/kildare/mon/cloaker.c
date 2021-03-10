#include <std.h>
#include "../kildare.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("cloaker");
	set_id(({"cloaker","black cape","cape","kildare_mon"}));
	set_short("A menacing cloaker");
	set_long("%^BOLD%^%^BLACK%^Looking like nothing so much as a "+
         "length of black cloth at first, this menacing creature is "+
         "in fact a cloaker.  It has a %^WHITE%^pristine white "+
         "underbelly %^BLACK%^and 'wings' like a ray's.  The "+
         "wings unfurl and flap as a %^RED%^cloak %^BLACK%^would "+
         "in the %^CYAN%^wind%^BLACK%^.  Its harmless appearance "+
         "ends there, however, as it opens its %^RED%^gaping "+
         "maw %^BLACK%^to reveal rows of %^WHITE%^sinister teeth"+
         "%^BLACK%^.  Its eyes are pupiless %^RED%^red slits%^BLACK%^,"+
         "and it has a %^RESET%^whip-like tail %^BOLD%^%^BLACK%^"+
         "stretching below.%^RESET%^");
	set_race("cloaker");
	set_gender("neuter");
	set_body_type("snake");
	set_hd(10,4);
	set_max_level(15);
	set_size(2);
	set_overall_ac(-3);
	set("aggressive",25);
	set_property("swarm",1);
	set_alignment(8);
	set_level(10);
	set_class("fighter");
	set_mlevel("fighter",10);
      add_limb("right fold","torso",0,0,0);
      add_limb("left fold","torso",0,0,0);
	set_attack_limbs(({"mouth","right fold","left fold"}));
	set_attacks_num(2);
      set_hit_funcs((["right fold":(:TO,"engulf":), "left fold":(:TO,"engulf":)]));
	set_damage(1,6);
	set_base_damage_type("slashing");
	set_exp(2000);
      set_hp(random(75)+125);
      set_max_hp(query_hp());
	force_me("message in hovers in the air");
      force_me("message hovers $D");
	set_emotes(10,({
         "%^BOLD%^%^RED%^The cloaker's whip-like tail lashes back and forth!%^RESET%^",
         "%^BOLD%^%^WHITE%^The cloaker hovers just out of reach!%^RESET%^"
	}),1);
}

int engulf(object targ){
   if(!random(3)){
      tell_object(targ,"%^BOLD%^%^WHITE%^The cloaker wraps itself around "+
         "your head, squeezing you mercilessly!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^WHITE%^The cloaker suddenly wraps itself around "+
         ""+targ->QCN+"'s head and squeezes!%^RESET%^",targ);
      targ->do_damage("head",(6+random(13)));
      if(!random(2)) {
         targ->set_paralyzed(2,"You're trying to free yourself from the cloaker!");
      }
   }
   return 5;
}

void die(object obj) {
object stuff;
	switch(random(10)){
         case 0..2:  new("/d/common/obj/misc/gem")->move(TO);
                     break;
         case 3..4:  new("/d/common/obj/misc/gem")->move(TO);
                     new("/d/common/obj/misc/gem")->move(TO);
                     break;
         case 5..6:  add_money("gold",50+random(76));
                     break;
         case 7:  stuff = new("/d/common/obj/rand/cloak");
                  stuff->move(TO);
                  if(!random(10)) stuff->set_property("enchantment",1);
                  break;
         default:  break;
	}
	tell_room(ETO,"%^BOLD%^%^BLACK%^The cloaker falls to the "+
         "the floor and looks simply like a cloak once more.%^RESET%^");
    	::die(obj);
}

