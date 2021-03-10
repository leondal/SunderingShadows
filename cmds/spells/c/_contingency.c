#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
object cont;

void create() {
  ::create();
    set_spell_name("contingency");
    set_spell_level(([ "mage" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS contingency on SPELL_NAME [on SPELL_ARGS]");
    set_description("This spell allows you to put a spell in reserve, and call upon it at any time with the command <now>. The target of the reserved spell is always the caster, but arguments can be specified for spells that require them. You must carry a likeness of yourself, usually a small statue, when casting this spell.

Example of usage:  cast contingency on teleport on LOCATION");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_casting_time(2);
    set_components(([
      "mage" : ([ "quicksilver":1, "eyelash of ogre-mage":1, ]),
    ]));
}

string query_cast_string() {
  return caster->QCN+" throws whispers silently then starts another spell.";
}

int preSpell() {
  if (!present("statue of "+capitalize(caster->query_name()),caster)) {
    tell_object(caster,"You need to have a likeness of yourself to cast upon.");
    return 0;
  }
  return 1;
}

void spell_effect(int prof) {
  string spell, args, *comp_names, orgSpell, newtype;
  int x, spellProf, spelllevel;
  object spellObj;


  if (!ARG) {
    dest_effect();
    return;
  }

  if (sscanf(ARG,"%s on %s",spell,args) != 2) {
    spell = ARG;
    args = 0;
  }

  orgSpell = spell;
  newtype = spell_type;

  spell = replace_string(spell," ","_");
  spell = "/cmds/spells/"+spell[0..0]+"/_"+spell;
  if (!file_exists(spell+".c")) {
    tell_object(caster,"That spell does not exist.");
    dest_effect();
    return;
  }

  if(spell_type == "sorcerer") newtype = "mage";
  spelllevel = spell->query_spell_level(newtype);
  if(spell_type == "sorcerer") orgSpell = "level "+spelllevel;

  if (!caster->query_memorized(spell_type,orgSpell)) {
    tell_object(caster,"You don't have that spell memorized.");
    dest_effect();
    return;
  }

  if (stringp(args) && !spell->query_arg_needed()) {
    args = 0;
  }

  caster->forget_spell(spell_type,orgSpell);
  spellObj = new(spell);
  spellObj->set_caster(caster);
  spellProf = spellObj->calculate_prof_state();
  cont= new("/d/magic/obj/contingency");

  cont->set_clevel(clevel);
  cont->set_spell(spell);
  cont->set_args(args);
  cont->move(caster);
  tell_room(place,"%^BOLD%^%^RED%^You hear a sucking noise in the background as if some magic has been sucked into a bottle.");
  tell_object(caster,"Type, <now> to activate");
  // Changed by Garrett to actually be dismissable and dispellable.
  // The spell is WAY overpowered if it's not dispellable.
  // Garrett
  // Changed by ilmarinen to make int not dispellable.
  // The spell is WAY underpowered if it is dispellable.
  // Ilmarinen
  set_heart_beat(15);
  addSpellToCaster();
  //  dest_effect();
}

void dest_effect(){
  if (objectp(cont)) {
    tell_room(environment(caster),"%^BOLD%^%^RED%^You hear a slight pop and crackle.");
    cont->remove(0);
  }
  if (!objectp(caster)) {
    remove();
    return;
  }
  caster->remove_property_value("spelled", ({TO}) );
  removeSpellFromCaster();
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}

void heart_beat() {
  //  ::heart_beat();
  if (!objectp(cont)){
    if(objectp(TO)) TO->dest_effect();
  }
}
