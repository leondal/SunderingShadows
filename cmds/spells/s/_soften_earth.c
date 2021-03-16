
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("soften earth");
    set_spell_level(([ "druid" : 2, "oracle" : 2, "cleric" : 2 ]));
    set_spell_sphere("alteration");
    set_domains("earth");
    set_mystery("stone");
    set_syntax("cast CLASS soften earth");
    set_damage_desc("trips targets");
    set_description("When this spell is cast, all natural, undressed earth or stone in the spell's area is softened. Wet earth becomes thick mud, dry earth becomes loose sand or dirt, and stone becomes soft clay that is easily molded or chopped. Creatures in mud that succed reflex save are not affected, others become prone.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(2);
}
string query_cast_string()
{
    tell_object(caster, "%^ORANGE%^You feel the ground turning into a soft mud as you chant.");
    tell_room(place, "%^ORANGE%^You feel the ground turns into a soft mud as " + caster->QS + " chants.", caster);
    return "display";
}
void spell_effect(int prof)
{
    object* attackers;
    int i, dmg;
    attackers = target_selector();

    tell_room(place, "%^ORANGE%^The earth turns into a mud!%^RESET%^");
    if (!sizeof(attackers)) {
        dest_effect();
        return;
    }
    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }

        dmg = sdamage;
        if (!do_save(attackers[i], -2)) {
            attackers[i]->set_tripped(roll_dice(1, 4));
            tell_object(attackers[i], "%^BOLD%^%^MAGENTA%^You slip and trip in the mud!%^RESET%^");
            tell_room(attackers[i], "%^BOLD%^%^MAGENTA%^" + attackers[i]->QCN + " slips and trips in the mud.%^RESET%^", attackers[i]);
        }else  {
            tell_room("%^ORANGE%^" + attackers[i]->QCN + " jumps off mud puddle just in time!");
        }
    }
    spell_successful();
    dest_effect();
}
void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
