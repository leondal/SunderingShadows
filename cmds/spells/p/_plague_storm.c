#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;

string potential_diseases = ({ "blinding sickness", "cackle fever", "filth fever", "mindfire", "red ache", "shakes", "slimy doom" });

void create()
{
    ::create();
    set_spell_name("plague storm");
    set_spell_level(([ "cleric" : 6, "mage" : 7, "druid" : 6, ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS plague storm");
    set_description("This spell works exactly like contagion, but is an aoe.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fortitude");
    evil_spell(1);
    aoe_spell(1);
    set_aoe_message("%^GREEN%^(%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^f%^RESET%^%^GREEN%^u%^BOLD%^s%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d %^RESET%^%^GREEN%^w%^BOLD%^it%^BLACK%^h p%^RESET%^%^GREEN%^l%^BOLD%^a%^BLACK%^gu%^RESET%^%^GREEN%^e %^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^l%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^s)%^WHITE%^");
}

void spell_effect(int prof)
{
    tell_object(caster, "%^GREEN%^You swiftly wave your hand and invoke a hi%^BOLD%^d%^BLACK%^e%^RESET%^%^GREEN%^o%^BOLD%^u%^RESET%^%^GREEN%^s %^BOLD%^green %^RESET%^%^GREEN%^clo%^BOLD%^u%^RESET%^%^GREEN%^d, infused with %^BOLD%^d%^RESET%^%^GREEN%^is%^BOLD%^e%^BLACK%^a%^GREEN%^se%^RESET%^%^GREEN%^s.%^WHITE%^");
    tell_room(place, "%^GREEN%^" + caster->QCN + " swiftly waves " + caster->QP + " hand and invokes a hi%^BOLD%^d%^BLACK%^e%^RESET%^%^GREEN%^o%^BOLD%^u%^RESET%^%^GREEN%^s %^BOLD%^green %^RESET%^%^GREEN%^clo%^BOLD%^u%^RESET%^%^GREEN%^d, infused with %^BOLD%^d%^RESET%^%^GREEN%^is%^BOLD%^e%^BLACK%^a%^GREEN%^se%^RESET%^%^GREEN%^s.%^WHITE%^", ({ caster }));
    counter = clevel / 6 + 1;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object* foes = ({}), targ;
    int i;
    object disease;
    string * diseases, * targ_infections, dname, dfile;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0) {
        dest_effect();
        return;
    }

    message("info", "%^RESET%^%^BOLD%^%^GREEN%^Hideous cloud envelopes everyone in the area!", place);
    foes = target_selector();
    foes -= ({ caster });

    for (i = 0; i < sizeof(foes); i++) {
        if (!objectp(targ = foes[i])) {
            continue;
        }

        targ_infections = filter_array(all_inventory(foes[i]), (: $1->is_disease() :))->query_name();
        diseases = potential_diseases - targ_infections;
        if (!sizeof(diseases)) {
            continue;
        }
        dfile = "/std/diseases/diseases/" + replace_string(diseases[random(sizeof(diseases))], " ", "_") + ".c";
        if (!file_exists(dfile)) {
            continue;
        }
        disease = dfile->infect(foes[i], clevel);
        if (objectp(disease)) {
            disease->advance_disease();
            tell_room(place, "%^BOLD%^%^GREEN%^" + foes[i]->QCN + " inhales the diseaseous cloud.");
            spell_kill(foes[i], caster);
        }
    }

    counter--;
    place->addObjectToCombatCycle(TO, 1);
}

void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^RESET%^%^GREEN%^%^BOLD%^The diseasous cloud disperses, leaving everyone relieved.");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
