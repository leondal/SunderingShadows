#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("biting wind");
    set_spell_level(([ "mage" : 1, "oracle" : 1 ]));
    set_mystery("wind");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS biting wind");
    set_damage_desc("cold");
    set_description("A stream of cold releases out from you in all directions, biting everything in sight with cold.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(3);
    set_save("fortitude");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^WHITE%^You can feel %^BLUE%^c%^CYAN%^h%^WHITE%^il%^CYAN%^l %^WHITE%^i%^BLUE%^n %^WHITE%^t%^CYAN%^h%^BLUE%^e %^CYAN%^a%^WHITE%^ir %^BLUE%^a%^WHITE%^s you chant.%^RESET%^");
    tell_room(place, "%^BOLD%^%^WHITE%^A %^BLUE%^c%^CYAN%^h%^WHITE%^il%^CYAN%^l winds surround " + caster->QCN + " as " + caster->QS + " begins to chant.", caster);
    return "display";
}

void spell_effect(int prof)
{
    object* attackers;
    int i, dam;

    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^WHITE%^The power of c%^CYAN%^o%^WHITE%^l%^CYAN%^d e%^BLUE%^b%^WHITE%^b%^BLUE%^s %^WHITE%^from you into all directions.%^RESET%^");

    if (!sizeof(attackers)) {
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        tell_object(attackers[i], "%^WHITE%^%^BOLD%^Biting c%^BLUE%^o%^WHITE%^l%^BLUE%^d %^WHITE%^painfully %^CYAN%^c%^WHITE%^hil%^CYAN%^l%^WHITE%^s you.");

        dam = sdamage;

        if (do_save(attackers[i], 0)) {
            dam /= 2;
        }
        damage_targ(attackers[i], attackers[i]->return_target_limb(), dam, "cold");
    }

    spell_successful();
    dest_effect();
}
