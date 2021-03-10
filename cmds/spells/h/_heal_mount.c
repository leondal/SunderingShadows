// --==** /cmds/priest/_heal.c **==--
// Modified by Pator@ShadowGate
// August 25 1995
#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("heal mount");
    set_spell_level(([ "paladin" : 3 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS heal mount on TARGET");
    set_description("This spell will allow the caster to cure the target of all (hp) damage from wounds and disease, but "
"only works on riding mounts.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_casting_time(15);
	set_helpful_spell(1);
}

string query_cast_string() {
  string cast;
  if (interactive(CASTER))
    cast = CASTER->QCN+" folds "+CASTER->QP+
      " hands as "+CASTER->QS+" prays for a divine spell!\n";
  else
    cast = CASTER->QCN+" calls for a divine spell!\n";
  return "\n"+cast;
}

spell_effect(int prof) {
  if(target->query_vehicle_type() != "riding animal") {
    tell_room(PLACE,"The spell of healing fizzles and fails.");
    dest_effect();
    return;
  }
  tell_object(CASTER, "You reach out and touch a hand to "+target->QCN+", healing it completely.");
  tell_object(target,YOU+" touches a hand to you, and you are healed completely.");
  tell_room(PLACE,YOU+" reaches out and touches a hand to "+target->QCN+", healing it completely.",({ CASTER, target}) );

  if((int)target->query_hp() <=(int)target->query_max_hp())
    damage_targ(target, target->return_target_limb(), (int)target->query_max_hp() - (int)target->query_hp(), "positive energy");

  target->remove_paralyzed();
  target->set_poisoning((-1)*(int)target->query_poisoning());
  dest_effect();
}

void dest_effect() {
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}