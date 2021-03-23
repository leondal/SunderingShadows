#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit "/cmds/spells/p/_prismatic_spray";

int flag, roll, theProf;


void create()
{
    ::create();
    set_spell_name("prismatic burst");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS prismatic burst");
    set_damage_desc("random chance to roll one of 8 rays at all attackers");
    set_description("This spell functions exactly like prismatic spray, but creates beam for each attacker.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_target_required(0);
}


void spell_effect(int prof)
{
    object *attackers,*targs=({}),tmp;
    int i,hits;

    attackers = target_selector();

    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^Prismatic rays fail to connect to any targets.");
    }

    targs = attackers;

    for (i = 0; i < sizeof(targs); i++) {
        if (!objectp(targs[i])) {
            continue;
        }
        tell_object(caster, "%^BOLD%^A rainbow of colors flash from your hand striking " + targs[i]->QCN + "!");
        tell_object(targs[i], "%^BOLD%^A rainbow of colors flash from " + caster->QCN + "'s hand striking you!");
        tell_room(place, "%^BOLD%^A rainbow of colors flash from " + caster->QCN + "'s hand striking " + targs[i]->QCN + "!", ({ caster, targs[i] }));

        if (targs[i]->query_level() < clevel * 4 / 5) {
            targs[i]->set_temporary_blinded(2);
        }

        flash(targs[i], 0);
    }

    spell_successful();
    dest_effect();
}
