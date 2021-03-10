//strider.c

#include <std.h>

inherit "/std/riding_animal";

void create(){
   ::create();

   set_riding_level(20);
   set_name("strider");
   set_short("%^BOLD%^%^BLACK%^Giant strider");
   set_id(({"strider","Strider","giant","Giant strider"}));
   set_long(
@OLI
   This bird shaped creature thrives in the hot flames of the
volcanic regions here. It has a saddle on its back with straps
around the girth. Two long thin but well muscled legs support
the creature.The long neck supports a disporportionately large
beaklike head. Huge teeth jut up and down from the mouth into
which they don't fit. The thin tail sways back and forth with
the creature's movements
OLI
 );

 set_race("strider");
 set_body_type("fowl");
 remove_limb("left wing");
 remove_limb("right wing");
 add_limb("neck","torso",0,0,0);
 set_damage(1,10);
 set_attacks_num(2);
 set_funcs(({"fireball"}));
 set_hd(10+random(10),10);
 set_exp(query_hd()*200);
set_max_level(36);
 set_base_damage_type("slashing");
 set_func_chance(25);
 set_attack_limbs(({"right claw","left claw","beak"}));
 set_hit_funcs((["beak":(:TO,"mouth":),]));
 set_overall_ac(-14);
 set_hp(query_hd()*16);
// set_property("swarm",1);
//taken out to stop them from attacking the rider.  Circe 7/27/04
 set_stats("strength",18);
 set_new_exp(35,"normal");
}

int mouth(object targ){
   return random(10);
}

void fireball(object targ){
   int i;

   if(!objectp(targ)) return;

   tell_room(ETO,"%^ORANGE%^The strider releases two fireballs from holes above its nose into the battle.");
   i = random(sizeof(query_attackers()));
   if(objectp(query_attackers()[i]))
      new("/cmds/spells/f/_fireball")->use_spell(TO,query_attackers()[i]->query_name(), 15,100,"mage");
   i = random(sizeof(query_attackers()));
   if(objectp(query_attackers()[i]))
     new("/cmds/spells/f/_fireball")->use_spell(TO,query_attackers()[i]->query_name(), 15,100,"mage");


}
