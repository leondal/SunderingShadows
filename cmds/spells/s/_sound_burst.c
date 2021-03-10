#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int mod, is_sm;

void dest_effect();

void create() {
    ::create();
    set_spell_name("sound burst");
    set_spell_level(([ "bard" : 2, "cleric" : 2, "inquisitor" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS sound burst on TARGET");
    set_description("This spell enhances a simple click of the fingers, reaching the target with an ear-shattering pitch "
"that can cause serious damage.  It may also harm those standing nearest the target in question, though a quick opponent "
"may manage to avoid the worst of this damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({"sonic"}) );
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" raises a hand, fingertips touching.";
}

void spell_effect(int prof)
{
    int num, damage, size, i;
    object *attackers, *inven, *hits, *ownparty, *SpellMasterySpells;

    hits = ({});
    ownparty = ({});

    if(!objectp(caster)) {
        dest_effect();
        return;
    }

    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here.");
        dest_effect();
        return;
    }

    ownparty = ob_party(caster);

    spell_successful();
    damage = sdamage;

    tell_room(place, "%^CYAN%^%^BOLD%^"+caster->QCN+" snaps "+caster->QP+" fingers clearly in a gesture towards "
        +target->QCN+", who staggers back and clutches "+target->QP+" ears!",({caster, target}) );
    tell_object(caster, "%^CYAN%^%^BOLD%^You snap your fingers clearly with a gesture towards "+target->QCN+", who "
        "staggers back and clutches "+target->QP+" ears!");
    tell_object(target, "%^CYAN%^%^BOLD%^"+caster->QCN+" snaps "+caster->QP+" fingers clearly in a gesture towards you, "
        "and the sound echoes in your ears magnified a hundred times!");
    damage_targ(target, target->return_target_limb(), damage,"sonic");

    inven = all_inventory(environment(caster));

    attackers = target_selector();
    hits = attackers;
    hits -= ({caster});
    hits -= ({ target });


    size = random(clevel);
    for (i = 0;i < sizeof(hits);i++) {
        if(!objectp(hits[i])) continue;
        if(random(2)) continue;
        damage = sdamage;
	  if(is_sm) damage = sdamage / 2;
        if(do_save(hits[i],0)) {
          if(evade_splash(hits[i])) continue;
          damage = to_int(sdamage/2);
        }

        tell_room(place,"%^CYAN%^"+hits[i]->QCN+" winces as echoes of the sound ring in "+hits[i]->QP+" ears!",hits[i]);
        tell_object(hits[i],"%^CYAN%^An echo of the snap rings in your ears, jarring your senses!");
        damage_targ(hits[i], hits[i]->return_target_limb(), damage,"sonic");
        if (!size) break;
    }
    dest_effect();
}

void dest_effect() {
	object *SpellMasterySpells;
      if(objectp(caster))
	{
		if(sizeof(SpellMasterySpells = caster->query_property("spellmastery_spells")))
		{
			if(member_array(TO, SpellMasterySpells) != -1)
			{
				SpellMasterySpells -= ({TO});
				caster->remove_property("spellmastery_spells");
				if(sizeof(SpellMasterySpells))
				{
					caster->set_property("spellmastery_spells",
					SpellMasterySpells);
				}
			}
		}
	}
    	::dest_effect();
      if(objectp(TO)) TO->remove();
}
