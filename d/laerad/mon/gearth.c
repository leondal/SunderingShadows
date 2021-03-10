//Octothorpe (8/29/09)
//Modified from Amulet of Earth Control mob, took out heartbeat and die overrides.
//Underdark Mining Caverns, Amulet of Earth Control Earth Elemental Inherit

#include <std.h>
#include <daemons.h>
//#include "../defs.h"
inherit WEAPONLESS;

int timer;

void create(){
   object ob;
   ::create();
   set_name("earth elemental");
   set_id(({"earth elemental","elemental","eele"}));
   set_short("%^ORANGE%^hulking earth elemental%^RESET%^");
   set_long("%^ORANGE%^This creature amounts to little more than a "+
      "large mound of rock and precious stones. The elemental resembles "+
      "a vaguely humanoid shape, complete with thick legs and arms as "+
      "large as tree trunks. Two large, sparkling %^RED%^ru%^BOLD%^bi"+
      "%^RESET%^%^RED%^es %^ORANGE%^serve as eyes for this creature. "+
      "It is an amalgam of sedimentary and metamorphic rocks, with "+
      "chunks of %^BOLD%^%^WHITE%^gra%^BLACK%^ni%^WHITE%^te%^RESET%^"+
      "%^ORANGE%^, sandstone, %^BOLD%^%^WHITE%^limestone%^RESET%^"+
      "%^ORANGE%^, and %^RESET%^basalt %^ORANGE%^found in different "+
      "places on its body.%^RESET%^");
   set_race("earth elemental");
   set_alignment(5);
   set_gender("neuter");
   set_body_type("human");
   set_hd(20,2+random(10));
   set_overall_ac(-13);
   set_size(4);
   set_max_level(21);
   set_max_hp(300+random(150));
   set_hp(query_max_hp());
   set("aggressive",20);

   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_damage(2,10);
   set_stats("strength",23);
   set_stats("dexterity",8);
   set_stats("constitution",19);
   set_stats("intelligence",5);
   set_stats("wisdom",11);
   set_stats("charisma",11);
   set_exp(13500);
   set_func_chance(15);
   set_funcs(({"smash","throw","smash"}));
   //timer = 20+random(5);
    if(!random(3)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("living stone");
      ob->move(TO);
    }
}

void die(object ob){
/*
   int i,j;
   object *inven;
   object *live;
   inven = all_living(ETO);
   live = filter_array(inven, "is_non_immortal_player",FILTERS_D);
   j = sizeof(live);

   for(i=0;i<j;i++){
      if(!objectp(live[i])) continue;
      if(live[i] == TO) continue;
      if(!objectp(TO)) return;
      if(live[i]->query_protector("eele")){
         remove_protector("eele");
      }
   }
*/
   tell_room(ETO,"%^ORANGE%^The earth elemental can no longer resist "+
      "the call of the Elemental Plane of Earth, and is seemingly drawn "+
      "into the ground, leaving behind no trace of its existence.%^RESET%^");
   TO->remove();
}

void smash(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^ORANGE%^The earth elemental raises its arms "+
      "above its head and then swings them down with great force, "+
      "smashing you!%^RESET%^");
   tell_room(ETO,"%^ORANGE%^"+targ->QCN+" is pummelled by the earth "+
      "elemental as it brings its arms crashing down on "+targ->QS+""+
      "!%^RESET%^",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+20);
   return;
}

void throw(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^ORANGE%^The earth elemental tears a chunk of "+
      "rock out of its torso and throws it at your head!%^RESET%^");
   tell_room(ETO,"%^ORANGE%^The earth elemental tears a chunk of rock "+
      "out of its torso and throws it at "+targ->QCN+"'s "+
      "head!%^RESET%^",targ);
   targ->do_damage("head",15+random(15));
   targ->set_tripped(1,"%^BOLD%^%^RED%^You are dazed by the blow to "+
      "your head!%^RESET%^");
   return(random(3)+1);
}
