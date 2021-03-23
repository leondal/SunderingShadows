#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("frostfield");
    set_spell_level(([ "mage" : 2, "druid" : 2, "oracle" : 2, "magus" : 2, "cleric" : 2 ]));
    set_mystery("winter");
    set_domains("cold");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS frostfield");
    set_damage_desc("tripped for 1d4 rounds");
    set_description("A stream of cold releases out from you in all directions, biting everything in sight with cold.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("reflex");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^CYAN%^You can feel %^BLUE%^c%^WHITE%^h%^CYAN%^il%^WHITE%^l %^CYAN%^i%^BLUE%^n %^CYAN%^t%^WHITE%^h%^BLUE%^e %^WHITE%^a%^CYAN%^ir %^BLUE%^a%^CYAN%^s you chant.%^RESET%^");
    tell_room(place, "%^BOLD%^%^CYAN%^A %^BLUE%^c%^WHITE%^h%^CYAN%^il%^WHITE%^l winds surround " + caster->QCN + " as " + caster->QS + " begins to chant.", caster);
    return "display";
}

void spell_effect(int prof)
{
    object* attackers;
    int i;

    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^CYAN%^The power of c%^WHITE%^o%^CYAN%^l%^WHITE%^d e%^BLUE%^b%^CYAN%^b%^BLUE%^s %^CYAN%^from you, freezing the ground.%^RESET%^");

    if (!sizeof(attackers)) {
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }

        if (do_save(attackers[i], 0)) {
            tell_object(attackers[i],"%^BOLD%^%^WHITE%^You manage to remain standing on the ice!");
            tell_room(place, "%^BOLD%^%^WHITE%^" + attackers[i]->QCN + " manages to remain standing on the ice!");
            continue;
        }
        tell_object(attackers[i],"%^BOLD%^%^CYAN%^You slips on the ice, unable to stand!");
        tell_room(place, "%^BOLD%^%^CYAN%^" + attackers[i]->QCN + " slips on the ice, and falls down!");
        attackers[i]->set_tripped(roll_dice(1, 4));
    }

    spell_successful();
    dest_effect();
}
