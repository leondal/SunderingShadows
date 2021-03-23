#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;


void create()
{
    ::create();
    set_spell_name("stinking cloud");
    set_spell_level(([ "mage" : 3, "magus" : 3, "cleric" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS stinking cloud");
    set_domains("creation");
    set_description("This spell creates a cloud of sickening fumes that perpetually causes everyone in the area to be sickened.");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_save("fort");
    set_aoe_message("%^BOLD%^%^BLACK%^(covered %^RESET%^%^GREEN%^i%^GREEN%^n%^BOLD%^ %^RESET%^%^GREEN%^s%^GREEN%^t%^GREEN%^i%^BOLD%^%^BLACK%^nky %^BLACK%^c%^RESET%^%^GREEN%^l%^GREEN%^o%^GREEN%^u%^BOLD%^%^BLACK%^ds)%^RESET%^");
}

void spell_effect(int prof)
{
    tell_object(caster, "%^BOLD%^%^BLACK%^You draw your hands forward, causing %^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^lo%^RESET%^%^GREEN%^u%^GREEN%^d%^BOLD%^%^BLACK%^s %^BLACK%^o%^RESET%^%^GREEN%^f%^BOLD%^ %^BLACK%^s%^RESET%^%^GREEN%^t%^GREEN%^i%^BOLD%^%^BLACK%^nk%^RESET%^%^GREEN%^y%^BOLD%^ %^BLACK%^f%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^m%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^s%^BLACK%^ to materialize in the area.%^RESET%^");
    tell_room(place, "%^GREEN%^" + caster->QCN + "%^BOLD%^%^BLACK%^materializes few %^BLACK%^clo%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^ds %^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^f %^BLACK%^sti%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^ky %^RESET%^%^GREEN%^f%^BOLD%^%^BLACK%^umes%^BLACK%^ in the area!%^RESET%^", caster);
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object* foes = ({}), targ;
    int i, dam;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0) {
        dest_effect();
        return;
    }

    foes = target_selector();
    foes -= ({ caster });

    for (i = 0; i < sizeof(foes); i++) {
        if (!objectp(targ = foes[i])) {
            continue;
        }
        if (do_save(targ, 4)) {
            continue;
        }
        "/std/effect/status/sickened"->apply_effect(targ,2);
    }
    counter--;
    place->addObjectToCombatCycle(TO, 1);
}

void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^GREEN%^S%^BOLD%^%^BLACK%^ti%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^ky %^BLACK%^cl%^RESET%^%^GREEN%^o%^GREEN%^u%^GREEN%^d%^GREEN%^s%^BOLD%^%^BLACK%^ finally disappear!%^RESET%^");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
