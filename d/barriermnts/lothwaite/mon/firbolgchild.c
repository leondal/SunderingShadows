#include <std.h>
#include "../lothwaite.h"
inherit MONSTER;

void create()
{
	::create();
	set_name("firbolg child");	
	set_id(({"ghost","undead","monster","firbolg","giant","firbolg ghost","giant ghost","child","firbolg child","spirit","firbolg child spirit"}));
	set_short("A firbolg child spirit");
	set_gender(random(2)?"male":"female");
	set_size(random(3)+1);
      set_long(
         "Though still quite tall, the slighter stature "+
         "of this spirit combined with the cherubic "+
         "softness of its cheeks hint that this firbolg "+
         "died as a young child.  The spirit is still "+
         "clad in translucent remnants of the attire it "+
         "wore in life - a simple tunic over short breeches.  "+
         "The spirit is barefoot and carries no visible weapons, "+
         "wandering these lonely halls with a woeful expression."
      );
	set_property("undead",1);
	set_hd(7,3);
	set_max_level(10);
	set_body_type("firbolg");
	set_overall_ac(0);
	set_alignment(4);
	set_race("ghost");
	set_max_hp(random(50)+50);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",7);
      set_stats("strength",14);
	set_level(7);
	set_funcs(({"touch","drain","scare"}));
      set_func_chance(10);
	set_exp(300+random(200));
 	add_money("platinum",random(20));
	set("aggressive",3);
      remove_property("swarm");
	set_property("weapon resistance",2);
	set_mob_magic_resistance("average");
      set_moving(1);
      set_speed(60);
      set_nogo(({"/d/barriermnts/lothwaite/rooms/b1", "/d/barriermnts/lothwaite/rooms/stones2"}));
    	set_emotes(1,({
         "The firbolg child spirit stares with woeful eyes.",
         "The firbolg child spirit floats a foot above the "+
         "ground, gliding down the passage.",
         "The firbolg child spirit looks on solemnly."
    	}),0);
      set_achats(3, ({
         "The firbolg child spirit cries out in a silent scream.",
         "The firbolg child spirit's pale eyes are filled with horror.",
         "The firbolg child spirit raises its arms as if to defend itself."
      }) );
      force_me("message in drifts in");
      force_me("message out floats $D");
}

int touch(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^CYAN%^The ghost reaches "+
                    "out and touches your cheek, draining your strength!");
			tell_room(ETO,"%^BOLD%^%^CYAN%^The ghost"+
			" touches "+targ->query_cap_name()+"'s cheek and seems to drain"+
			" "+targ->query_objective()+" of "+targ->query_possessive()+""+
			" strength.",targ);
			targ->add_stat_bonus("strength",-1);
			return 1;
		}
		else {
			tell_object(targ,"You successfully resist the icy"+
			" touch of the ghost.");
			tell_room(ETO,"The ghost touches "+targ->query_cap_name()+","+
			" but "+targ->query_subjective()+" seems to be alright.",targ);
			return 1;
		}
		return 1;
}

int drain(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^The ghost seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^The ghost seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     targ->resetLevelForExp(-(random(500)+500));
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^The ghost attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The ghost tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
}

int scare(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes and you feel yourself "+
                     "frozen in fear!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" looks "+
                     "terrified as "+targ->QS+" gazes at the ghost!",targ);
                  targ->set_tripped(3,"%^BOLD%^You are frozen in fear of the ghost.");
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes, but you resist its power!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^The ghost stares "+
                     "at "+targ->QCN+" but nothing happens.",targ);
			return 1;
		}
		return 1;
}

void die(mixed ob){
   tell_room(ETO,"%^BOLD%^The firbolg child collapses, then "+
      "dissipates as a haunting wail fills the air.");
   ::die(ob);
}