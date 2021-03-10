//adjusting psychokinetic weapon to use a monster instead of an
//animated object until/unless the animate bug can be tracked down.
//With an animated object, the mob eats half the caster's exp. ~Circe~ 12/7/15

#include "summoned_monster.h"

inherit WEAPONLESS;
object caster;

void create(){
   ::create();
   set_name("ectoplasmic broad sword");
   set_id(({"summoned monster","broad sword","ectoplasmic sword","ectoplasmic broad sword","sword","greater summon"}));
   set_short("%^RESET%^%^MAGENTA%^an e%^CYAN%^c%^MAGENTA%^to"
       "%^BOLD%^p%^RESET%^%^MAGENTA%^la%^BOLD%^%^CYAN%^s%^RESET%^"
       "%^MAGENTA%^mi%^CYAN%^c %^RESET%^%^MAGENTA%^broad sword%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This e%^CYAN%^c%^MAGENTA%^to"
       "%^BOLD%^p%^RESET%^%^MAGENTA%^la%^BOLD%^%^CYAN%^s%^RESET%^"
       "%^MAGENTA%^mi%^CYAN%^c %^RESET%^%^MAGENTA%^has been shaped "
       "to look like a broad sword. The slender blade shines dully, "
       "encased in %^RESET%^i%^CYAN%^r%^MAGENTA%^id%^BOLD%^e%^RESET%^"
       "%^MAGENTA%^sc%^BOLD%^%^WHITE%^e%^RESET%^%^MAGENTA%^n%^CYAN%^c"
       "%^MAGENTA%^e that makes it look deceptively fragile.%^RESET%^");
   set_race("golem");
   remove_limb("neck");
   remove_limb("right foot");
   remove_limb("left hand");
   remove_limb("right leg");
   remove_limb("left foot");
   remove_limb("left leg");
   remove_limb("waist");
   remove_limb("head");
   remove_limb("right arm");
   remove_limb("right hand");
   remove_limb("left arm");
   add_limb("blade","blade",50,0,2);
   add_limb("hilt","hilt",0,0,0);
   set_attack_limbs(({"blade"}));
   set_base_damage_type("slashing");
   set_gender("sexless");
}

void die(object obj){
   if(!objectp(caster)){
      ::die(obj);
      return;
   }else{
      caster->remove_property("has_elemental");
      ::die(obj);
      return;
   }
}

void set_caster(object whom){ caster = whom; return;}
object query_caster() { return caster; }
