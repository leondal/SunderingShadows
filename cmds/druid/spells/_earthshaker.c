// spell to make the elemental work!
#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("earthshaker");
    set_spell_level(([ "druid" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast <classname> earthshaker");
    set_description("This spell is called upon by greater elementals to shake the ground beneath them.");
}

void spell_effect(int prof) {
    	int i;
      object *inven;

    	inven = all_living(environment(caster));
    	inven -= ({caster});
    	inven = filter_array(inven,"is_non_immortal",FILTERS_D);
    	if(FEATS_D->usable_feat(caster,"perfect caster")) inven = filter_array(inven,"perfect_filter",TO);

   	tell_room(environment(caster),"%^BOLD%^%^BLUE%^The earth beneath your feet trembles and shakes!%^RESET%^");
    	for(i=0;i<sizeof(inven);i++) {
      	if(!objectp(inven[i])) { continue; }
        	if(random((int)inven[i]->query_stats("dexterity") + 1) < roll_dice(1,30)) {
			tell_object(inven[i],"%^CYAN%^You lose your footing and stumble!");
			tell_room(place,"%^CYAN%^"+inven[i]->QCN+" stumbles and loses "+inven[i]->QP+" footing!",inven[i]);
			inven[i]->set_tripped(roll_dice(1,2),"%^BOLD%^%^CYAN%^You're regaining your balance!%^RESET%^",2);
            	continue;
        	}
    	}
    	spell_successful();
      dest_effect();
}

void dest_effect() {
    	::dest_effect();
    	TO->remove();
}