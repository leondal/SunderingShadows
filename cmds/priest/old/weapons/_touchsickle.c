//_touchsickle.c

#include <std.h>

inherit SPELL;

void create() {
   ::create();

   set_spell_name("touchsickle");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_diety("eldath");
   set_verbal_comp();
   set_somatic_comp();
}

int preSpell() {
   object *arm;
   int i, j;

   if(caster->query_property("touchsickle")){
      tell_object(caster,"Your sickles cannot morph further.");
      return 0;
   }
   arm = caster->query_armour("right hand");
   j = sizeof(arm);
   for(i=0;i<j;i++) {
      if(arm[i]->query_property("enchantment"))
         if((int)arm[i]->query_property("enchantment") < 0) continue;
      caster->remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
      arm[i]->set_not_equipped();
   }
   arm = caster->query_armour("left hand");
   j = sizeof(arm);
   for(i=0;i<j;i++) {
      if(arm[i]->query_property("enchantment"))
         if((int)arm[i]->query_property("enchantment") < 0) continue;
      caster->remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
      arm[i]->set_not_equipped();
   }
   if(sizeof(caster->query_armour("right hand"))) {
      write("You have cursed armour on your right hand.");
      return 0;
   }
   if(sizeof(caster->query_armour("left hand"))) {
      write("You have cursed armour on your left hand.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
   int droll;
   tell_object(caster,"%^BOLD%^%^GREEN%^Your hands lengthen and sharpen into a pair of enchanted wooden sickles. ");
   tell_room(place,"%^BOLD%^%^GREEN%^"+caster->query_cap_name()+"'s hands lengthen and sharpen into a pair of enchanted wooden sickles.",caster);
   caster->remove_limb("right hand");
   caster->remove_limb("left hand");
   caster->set_attack_limbs(({"right sickle","left sickle"}));
   caster->add_limb("right sickle","",0,0,0);
   caster->add_limb("left sickle","",0,0,0);
   droll = (int)caster->query_guild_level("cleric")/5;
   if(droll < 4) droll = 4;
   if(droll > 6) droll = 6;
   caster->set_attacks_num(droll);
   caster->set_damage(2,droll);
   caster->set_base_damage_type("slashing");
   caster->set_hit_funcs((["right sickle +2":({"/daemon/specials_d", "touchsickle"}),"left sickle +2":({"/daemon/specials_d", "touchsickle"})]));
   caster->set_property("spelled",({TO}));
   caster->add_attack_bonus(2);
   caster->set_property("touchsickle",1);
   call_out("dest_effect",8*clevel);
}

void dest_effect() {
   if(objectp(caster)) {
      caster->remove_limb("right sickle");
      caster->remove_limb("left sickle");
      caster->add_attack_bonus(-2);
      caster->set_attacks_num(0);
      caster->set_attack_limbs(({}));
      caster->add_limb("right hand","",0,0,0);
      caster->add_limb("left hand","",0,0,0);
      caster->set_wielding_limbs(({"right hand","left hand"}));
      write("%^GREEN%^Your hands return to their natural form.");
      caster->toggle_polymorphed();
      caster->remove_property_value("spelled", ({TO}) );
      caster->remove_property("touchsickle");
   }
   TO->remove();
}

string query_cast_string() {
   return "%^GREEN%^With a a low sigh, the normally peace loving "+caster->query_cap_name()+" prays that "+caster->query_possessive()+" god will aid him in using strength to preserve peace.";
}

int help() {
   write(
@HELP
Spell  : Touchsickle
Level  : 5th Level
Sphere : Alteration
Deity  : Eldath
Syntax : chant touchscikle

This spell will transform your hands into great
enchanted wooden sickles great for destroying your enemies.
HELP
   );
   return 1;
}
