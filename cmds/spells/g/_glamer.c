// alter self duplicate for fey warlocks
#include <priest.h>
inherit SPELL;

void create() {
      ::create();
      set_author("nienne");
      set_spell_name("glamer");
      set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("illusion");
      set_syntax("cast CLASS glamer");
      set_description("This invocation creates an illusion to alter the warlock's features. It is "
"a drastic enough change that they become unrecognizable even to those they are familiar with. It "
"does not allow for such drastic changes as body size or overall shape; the caster would still be "
"quite recognizable as a creature of their race.\n\n"
"OOC: This spell does not alter details on your scoresheet (eyes, hair) but the caster may describe "
"their new form and features differently to these if they so choose. They must still maintain their "
"overall body shape (ie. race, general height and weight).\n\n"
"You can only have one altered form with this spell - repeat uses do not grant additional different "
"shapeshifts, but instead return you to the same secondary form. Adjective, description, speech, "
"messages etc will be remembered across castings, so they will only need to be set once in your "
"alternative form. Players will be able to recognise your 'other self' as a unique entity, separate "
"from your usual self.");
      set_verbal_comp();
      set_somatic_comp();
      set_peace_needed(1);
      set_helpful_spell(1);
      set_feats_required(([ "warlock" : "blooded", ]));
}

int preSpell(){
      object shape;
      if(objectp(shape = caster->query_property("shapeshifted")) || objectp(shape = caster->query_property("altered"))) {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
      }
      return 1;
}

string query_cast_string() {
	tell_object(caster,"%^GREEN%^You cast aside distractions and focus your thoughts upon a particular image, familiar and yet %^CYAN%^other%^GREEN%^.%^RESET%^");
    	tell_room(place,"%^GREEN%^"+caster->QCN+"'s face grows %^CYAN%^blank %^GREEN%^and expressionless.%^RESET%^",caster);
    	return "display";
}

void spell_effect(int prof) {
      if (!objectp(caster)){
        if(objectp(TO)) TO->remove();
        return;
      }
      new("/std/races/shapeshifted_races/spell_glamer.c")->init_shape(caster,""); 
      spell_successful();
      addSpellToCaster();
}

void dest_effect() {
      object shape;
	if(objectp(caster)) {
        if(objectp(shape = caster->query_property("altered"))) shape->reverse_shape(caster);
	}
    	::dest_effect();
      if(objectp(TO)) TO->remove();
}
