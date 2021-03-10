#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("peryton guard");
  setenv("MIN", "$N swoops in with a screech.");
  setenv("MOUT", "$N flies to the $D in a rush of wings.");
  set_id(({"peryton","beast","magical beast" }));
  set_short("%^BOLD%^%^GREEN%^Peryton%^RESET%^");;
  set_long("%^RESET%^%^CYAN%^This large winged beast has feathers of "+
      "%^RESET%^%^GREEN%^dark green %^CYAN%^with a chest of %^BOLD%^bright "+
      "blue feathers%^RESET%^%^CYAN%^.  Almost like an eagle, his appearance "+
      "is twisted by the stag's head atop his body, complete with long, curved "+
      "horns the color of %^BOLD%^%^BLACK%^polished jet%^RESET%^%^CYAN%^.  His "+
      "sharp claws and pointed fangs give him quite a fearsome appearance, as does "+
      "the strange humanoid shadow he casts.%^RESET%^"
      );
  set_hd(10+random(6),1);
  set_hp((query_hd()*10)+50);
  set_level(10);
  set_class("fighter");
  set_mlevel("fighter",10);
  set_race("peryton");
  set_body_type("fowl");
  add_limb("mouth","head",0,0,0);
  add_limb("right horn","head",0,0,0);
  add_limb("left horn","head",0,0,0);
  remove_limb("beak");
  set_attack_limbs(({"right claw","left claw","mouth","right horn","left horn"}));
  set_size(2);
  set_alignment(9);
  set_overall_ac(4);
  set_exp(1500);    // was only 500
  set_max_level(15);  // added by *Styx* 9/24/06
  set_attacks_num(2);
  set_damage(1,6);
  set_base_damage_type("slashing");
  set_stats("strength",16);
  set_hit_funcs((["right claw":(:TO,"rend":), "left claw":(:TO,"rend":)]));
}

int rend(object victim){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(2)) {
      tell_object(victim,"%^BOLD%^%^RED%^The peryton swoops down on you and "+
         "tears into you with both claws!%^RESET%^");
      tell_room(environment(ETO),"%^BOLD%^%^RED%^The peryton swoops down on
         "+victim->query_cap_name()+" and tears into "+ETO->query_objective()+" "+
         "with both claws!%^RESET%^", ({ETO,victim}));
      victim->do_damage("torso",random(8)+2);
      return 0;
   }
   else return 0;
}
