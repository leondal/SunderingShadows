#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("peryton");
   set_short("Peryton");
   set_id(({"monster","peryton"}));
   set_long(
      "This twisted creature is surely the stuff of nightmares.  Seemingly "+
      "a giant, %^RESET%^%^GREEN%^dark green %^CYAN%^eagle with a twenty foot "+
      "wingspan, he has the head of a %^BLUE%^blue-black %^CYAN%^stag.  His "+
      "unearthly eyes glow an empty %^BOLD%^%^RED%^red-orange%^RESET%^%^CYAN%^, "+
      "while his wickedly sharp horns glitter %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^as "+
      "the abyss.  Contrasting sharply with the dark body, his chest is alight with "+
      "light blue feathers, and his sharp claws are %^BOLD%^%^WHITE%^bone white.  "+
      "%^RESET%^%^CYAN%^Strangely, the beast seems to cast a shadow of a humanoid "+
      "figure rather than his own shape."
   );
   set_gender("male");
   set_race("peryton");
   set_body_type("fowl");
   add_limb("mouth","head",0,0,0);
   add_limb("horns","head",0,0,0);
   remove_limb("beak");
   set_attack_limbs(({"right claw","left claw","mouth","horns"}));
   set_size(2);
   set_alignment(9);
   set_overall_ac(0);
   set_hd(10,6);
   set_level(10);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_hp(random(75)+125);
   set_max_hp(query_hp());
   set_damage(1,6);
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_property("swarm",1);
   set("aggressive",18);
   set_stats("strength",17);
   set_max_level(15);  // added by *Styx* 9/24/06
   set_exp(3000);   // was 3500
   add_money("gold",random(150)+25);
   set_mob_magic_resistance("average");
   set_funcs(({"gore","rend","rend","rend"}));
   set_func_chance(20);
   set_achats(7, ({
      "%^BOLD%^%^RED%^The peryton circles low in the air before striking again!",
      "%^BOLD%^%^YELLOW%^The peryton screeches and roars in rage!"
   }) );
}

int rend(object victim){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(2)) {
      tell_object(victim,"%^BOLD%^%^GREEN%^The peryton's %^RED%^eyes %^GREEN%^flash as he "+
         "tears into you with both claws!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^GREEN%^The peryton's %^RED%^eyes %^GREEN%^flash "+ 
         "as he tears into "+victim->query_cap_name()+" with both claws!%^RESET%^", ({victim}));
      victim->do_damage("torso",random(10)+5);
      return 0;
   }
   else return 0;
}

void gore(object targ)
{
switch(random(20)) 
  {
    case 0..4:
      tell_object(targ,"%^CYAN%^The peryton dives at you, but you manage to jump aside!%^RESET%^");
      tell_room(ETO,"%^CYAN%^"+targ->query_cap_name()+" jumps out of the way just as the peryton "+
         "dives at "+targ->query_objective()+".%^RESET%^",targ);
    break;
    case 5..15:
      tell_object(targ,"%^CYAN%^The peryton takes to the air, then swoops down, "+
         "impaling you with his horns!%^RESET%^");
      tell_room(ETO,"%^CYAN%^The peryton climbs in the air, then swoops down "+
         "on "+targ->query_cap_name()+" impaling "+targ->query_objective()+" with his horns!%^RESET%^",targ);
    targ->do_damage("torso",roll_dice(2,6));
    break;
    case 16..19:
      tell_object(targ,"%^CYAN%^The peryton rises high in the air and dives at you, "+
         "knocking you down as his horns impale you!%^RESET%^");
      tell_room(ETO,"%^CYAN%^The peryton climbs high in the air and dives straight at "+
         ""+targ->query_cap_name()+" knocking "+targ->query_objective()+" down and impaling "+
         ""+targ->query_objective()+" with his horns!%^RESET%^",targ);
    targ->set_paralyzed(2+random(2),"You're recovering from your chest being impaled!");
    targ->do_damage("torso",roll_dice(3,6));
    break;      
  }
}
