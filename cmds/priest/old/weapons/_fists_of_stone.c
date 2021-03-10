//_touchsickle.c

#include <std.h>

inherit SPELL;

void create() {
   ::create();

   set_spell_name("fists of stone");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_diety("grumbar");
   set_verbal_comp();
   set_somatic_comp();
}

int preSpell() {
   object *arm;
   int i, j;

   if(caster->query_property("fists of stone")){
      tell_object(caster,"Your fists cannot morph further.");
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
   tell_object(caster,"%^BOLD%^%^ORANGE%^You clench your fists "+
   "and give praise to %^YELLOW%^"+caster->query_diety()+
   "%^BOLD%^%^ORANGE%^ as they begin transforming into "+
   "%^BOLD%^%^WHITE%^hardened stone!%^RESET%^");
      
   tell_room(place,"%^BOLD%^%^ORANGE%^"+caster->QCN+" clenches "+
   caster->QP+" fists and gives praise to %^YELLOW%^"+
   caster->query_diety()+"%^BOLD%^%^ORANGE%^"+
   " as they begin transforming into %^BOLD%^%^WHITE%^"+
   "hardened stone!%^RESET%^",caster);
      
   caster->remove_limb("right hand");
   caster->remove_limb("left hand");
   caster->set_attack_limbs(({"right stone fist","left stone fist"}));
   caster->add_limb("right stone fist","",0,0,0);
   caster->add_limb("left stone fist","",0,0,0);
   addSpellToCaster();
   droll = (int)caster->query_guild_level("cleric")/5;
   if(droll < 4) droll = 4;
   if(droll > 6) droll = 6;
   caster->set_attacks_num(droll);
   caster->set_damage(2,droll);
   caster->set_base_damage_type("bludgeon");
   caster->set_hit_funcs((["right stone fist":({"/daemon/specials_d", "stonefists"}),"left stone fist":({"/daemon/specials_d","stonefists"})]));
   caster->set_property("spelled",({TO}));
   //caster->add_attack_bonus(2);
   caster->add_damage_bonus(2);
   caster->set_property("fists of stone",1);
   call_out("dest_effect",8*clevel);
}

void dest_effect() {
   if(objectp(caster)) {
      caster->remove_limb("right stone fist");
      caster->remove_limb("left stone fist");
      //caster->add_attack_bonus(-2);
      caster->add_damage_bonus(-2);
      caster->set_attacks_num(0);
      caster->set_attack_limbs(({}));
      caster->add_limb("left hand","",0,0,0);
      caster->add_limb("right hand","",0,0,0);
      caster->set_wielding_limbs(({"left hand", "right hand"}));
      write("%^BOLD%^%^ORANGE%^Your hands return to their "+
      "natural form.%^RESET%^");
      caster->toggle_polymorphed();
      caster->remove_property_value("spelled", ({TO}) );
      caster->remove_property("fists of stone");
   }
   TO->remove();
}

string query_cast_string() {
   return "%^ORANGE%^With a loud roar "+caster->QCN+
   " prays to "+caster->query_possessive()+" god for the strength "+
   "of stone!%^RESET%^";
}

int help() {
   write(
@HELP
Spell  : Fists of Stone
Level  : 5th Level
Sphere : Alteration
Deity  : Grumbar
Syntax : chant fists of stone

This spell will transform your hands into hardened chunks of 
stone that can be used to bludgeon your enemy.
HELP
   );
   return 1;
}
