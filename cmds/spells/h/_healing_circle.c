// taken directly from formulae for mass cure moderate wounds, to offer a useful spell.
#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>
inherit SPELL;

int calculate_healing();

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("healing circle");
    set_spell_level(([ "bard" : 6 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS healing circle");
    set_description("This spell causes healing energy to flare outwards from the caster, touching all friendly targets "
"and renewing their vitality.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^BLUE%^You press your hands together as you begin a low chant.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" begins a low chant as "+caster->QS+" preses "+caster->QP+" hands together.",caster);
    return "display";
}

void spell_effect(int prof) {
    string party;
    int i;
    object *party_members = ({}),*attackers = ({}),*living = ({}),*targets = ({});

    party = (string)caster->query_party();
    if(party) party_members = (object *)PARTY_OB->query_party_members(party);
    attackers = caster->query_attackers();
    living = all_living(place);

    target = caster;
    targets = party_members;

    targets += ({ caster });
    targets = distinct_array(targets);

    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" opens "+caster->QP+" hands, radiating a wave of healing "
        "energy.",caster);

	if(sizeof(targets)) {
		for(i=0;i<sizeof(targets);i++) {
			if(!objectp(targets[i])) continue;
			if(!present(targets[i],place)) continue;
			if(targets[i]->query_property("berserked"))
            {
			    tell_object(targets[i],"%^RED%^The rage fights off the healing!%^RESET%^");
                continue;
            }
			else if(targets[i] == caster)	
            {
                tell_object(targets[i], "%^BOLD%^%^BLUE%^A soft blue glow envelopes you.");
			}
			else 
            {
                tell_room(place,"%^BOLD%^%^BLUE%^A blue field radiates out from"+
				    " "+targets[i]->QCN+" as "+caster->QCN+" releases a wave "+
				    "of energy.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^BLUE%^A blue field radiates out "+
				    "from "+targets[i]->QCN+ " as you release a wave of energy.");
                tell_object(targets[i],"%^BOLD%^%^BLUE%^A blue field radiates out"+
				    " from you as "+caster->QCN+" casts a spell.");
			}
            damage_targ(targets[i], targets[i]->return_target_limb(), calculate_healing(), "positive energy");
		}
	}

	spell_successful();
    dest_effect();
    return;
}

int calculate_healing() {
    int num, max;
    max = 50; // max amount of damage the spell can heal, for ease of adjustment -Ares
    num = roll_dice(2,8) + (clevel*2);
//    if(num > max) num = max; //uncapping heal spells for useful. N, 5/11.
    return num;
}


void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
