//Octothorpe (12/13/09)
//Attaya, Poltergeist
//Original by Thundercracker

#include <std.h>
inherit WEAPONLESS;

create(){
   ::create();
   set_name("poltergeist");
   set_id( ({"poltergeist","shadow"}) );
   set_short("%^BOLD%^%^BLACK%^mischievious p%^RESET%^o%^BOLD%^%^BLACK%^"+
      "ltergeist%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Poltergeists are mischevious spirits that "+
      "usually don't have enough power to assume a physical form on the Prime "+
	  "Material Plane.  This spirit bears the appearance of a deranged "+
	  "humanoid, seemingly paranoid by its own shenanigans, as the "+
	  "living are.  They are usually common in places of great spiritual "+
	  "energy and unrest.%^RESET%^");
   set_race("undead");
   set_moving(1);
   set_property("magic",1);
   set_speed(5);
   set_body_type("human");
   set_property("swarm",1);
   set_hd(30,1);
   set_overall_ac(-4);
   set_size(2);
   set_stats("strength",25);
   set_stats("intelligence",25);
   set_stats("dexterity",19);
   set_stats("charisma",6);
   set_stats("wisdom",25);
   set_class("fighter");
   set_guild_level("fighter",30);
   set_damage(3,10);
   set_attacks_num(4);
   set("aggressive",25);
   set_alignment(6);
   set_invis();
   set_max_hp(100+random(250));
   set_hp(query_max_hp());
   set_new_exp(33,"normal");
   set_funcs(({"circle"}));
   set_func_chance(65);
   command("message in floats in.");
   command("message out floats to the $D.");
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^With an angry howl, the poltergeist "+
      "disperses into nothingness.%^RESET%^");
   TO->remove();
}

void circle(object targ){
   if(!targ) return;
   if("/daemon/saving_throw_d.c"->reflex_save(targ,-30)){
      tell_object(targ,"%^BOLD%^%^BLACK%^You are sheared in the back "+
	     "with a claw!%^RESET%^");
      targ->do_damage("torso",random(20)+20);
	  return;
   }
   else{
      tell_object(targ,"%^BOLD%^%^BLACK%^You feel something pass "+
	     "through your body.");
   }
}