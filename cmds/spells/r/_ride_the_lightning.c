// help updated to reflect damage isn't maxed at level 10, last change 5/2001 *Styx* 8/2003
// Lightning Bolt
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

string element;
void dest_effect();

void create()
{
    ::create();
    set_spell_name("ride the lightning");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS ride the lightning on TARGET");
    set_damage_desc("electricity or versatile arcanist");
    set_description("Developed by archmage Ramius, this spell, when cast, transforms you into a mass of living lightning and propels you toward your foes.  A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
                        "mage" : ([ "disc of bronze" : 1, ]),
                    ]));
    set_immunities(({ "electricity" }));
    set_save("reflex");
}

string query_cast_string()
{
    return caster->QCN + " rubs a disc of bronze while muttering some words.";
}

spell_effect(int prof)
{
    int num;
    string target_limb;
    spell_successful();

    if (environment(caster) != environment(target)) {
        tell_object(caster, "Your target has left your range.\n");
        dest_effect();
        return;
    }
    target_limb = target->return_target_limb();

    element = (string)caster->query("elementalist");
    switch (element) {
    case "acid":
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^GREEN%^You feel yourself transform into a bolt of living acid and streak forth towards " + target->QO + ".");
            tell_object(target, "%^BOLD%^%^GREEN%^" + caster->QCN + " is suddenly transformed into a bolt of living acid and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " is suddenly transformed into a bolt of living acid and streaks forward towards " + target->QCN + "!", ({ caster, target }));
        } else {
            tell_object(target, "%^BOLD%^%^GREEN%^" + caster->QCN + " is suddenly transformed into a bolt of living acid and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " is suddenly transformed into a bolt of living acid and streaks forward towards " + target->QCN + "!", target);
        }
        break;

    case "cold":
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^CYAN%^You feel yourself transform into a bolt of living frost and streak forth towards " + target->QO + ".");
            tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living frost and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living frost and streaks forward towards " + target->QCN + "!", ({ caster, target }));
        } else {
            tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living frost and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living frost and streaks forward towards " + target->QCN + "!", target);
        }
        break;

    case "fire":
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^RED%^You feel yourself transform into a bolt of living flame and streak forth towards " + target->QO + ".");
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living flame and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living flame and streaks forward towards " + target->QCN + "!", ({ caster, target }));
        } else {
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living flame and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living frost and streaks forward towards " + target->QCN + "!", target);
        }
        break;

    case "sonic":
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^CYAN%^You feel yourself transform into a bolt of living sound and streak forth towards " + target->QO + ".");
            tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living sound and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living sound and streaks forward towards " + target->QCN + "!", ({ caster, target }));
        } else {
            tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living sound and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " is suddenly transformed into a bolt of living sound and streaks forward towards " + target->QCN + "!", target);
        }
        break;

    default:
        element = "electricity";
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^RED%^You feel yourself transform into a bolt of living lightning and streak forth towards " + target->QO + ".");
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living lightning and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living lightning and streaks forward towards " + target->QCN + "!", ({ caster, target }));
        } else {
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living lightning and streaks forward towards you!");
            tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " is suddenly transformed into a bolt of living lightning and streaks forward towards " + target->QCN + "!", target);
        }
        break;
    }
    if (do_save(target, 0)) {
        if (evade_splash(target)) {
            dest_effect();
            return;
        }
        switch (element) {
        case "acid":
            tell_object(target, "%^GREEN%^The bolt of living acid grazes your " + target_limb + ".");
            tell_room(environment(caster), "%^GREEN%^The bolt of living acid " + target->QCN + "'s " + target_limb + ".", ({ target }));
            break;

        case "cold":
            tell_object(target, "%^CYAN%^The bolt of living frost grazes your " + target_limb + ".");
            tell_room(environment(caster), "%^CYAN%^The bolt of living frost grazes " + target->QCN + "'s " + target_limb + ".", ({ target }));
            break;

        case "fire":
            tell_object(target, "%^RED%^The bolt of living flame scorches your " + target_limb + ".");
            tell_room(environment(caster), "%^RED%^The bolt of living flame scorches " + target->QCN + "'s " + target_limb + ".", ({ target }));
            break;

        case "sonic":
            tell_object(target, "%^CYAN%^The bolt of living sound %^BOLD%^%^BLACK%^g%^CYAN%^r%^BLACK%^a%^CYAN%^z%^BLACK%^e%^WHITE%^s %^RESET%^%^CYAN%^your " + target_limb + "!");
            tell_room(environment(caster), "%^CYAN%^The bolt of living sound %^BOLD%^%^BLACK%^g%^CYAN%^r%^BLACK%^a%^CYAN%^z%^BLACK%^e%^WHITE%^s %^RESET%^%^CYAN%^" + target->QCN + "'s " + target_limb + "!", ({ target }));
            break;

        default:
            tell_object(target, "%^ORANGE%^The bolt of living lightning scorches your " + target_limb + ".");
            tell_room(environment(caster), "%^ORANGE%^The bolt of living lightning scorches " + target->QCN + "'s " + target_limb + ".", ({ target }));
            break;
        }
        damage_targ(target, target_limb, to_int(sdamage / 2), element);
    }else {
        switch (element) {
        case "acid":
            tell_object(target, "%^WHITE%^%^BOLD%^The bolt of living acid strikes you, burning into your " + target_limb + ".");
            tell_room(environment(caster), "%^WHITE%^%^BOLD%^The bolt of living acid strikes " + target->QCN + ", burning into " + target->QP + " " + target_limb + ".", ({ target }));
            break;

        case "cold":
            tell_object(target, "%^WHITE%^%^BOLD%^The bolt of living frost strikes you, chilling your " + target_limb + ".");
            tell_room(environment(caster), "%^WHITE%^%^BOLD%^The bolt of living frost strikes " + target->QCN + ", chilling " + target->QP + " " + target_limb + ".", ({ target }));
            break;

        case "fire":
            tell_object(target, "%^WHITE%^%^BOLD%^The bolt of living flame strikes you, searing into your " + target_limb + ".");
            tell_room(environment(caster), "%^WHITE%^%^BOLD%^The bolt of living flame strikes " + target->QCN + ", searing into " + target->QP + " " + target_limb + ".", ({ target }));
            break;

        case "sonic":
            tell_object(target, "%^CYAN%^The bolt of living sound %^BOLD%^%^BLACK%^t%^CYAN%^h%^BLACK%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^s %^RESET%^%^CYAN%^into you, %^BOLD%^b%^ORANGE%^l%^WHITE%^a%^CYAN%^st%^WHITE%^i%^ORANGE%^n%^CYAN%^g %^RESET%^%^CYAN%^your " + target_limb + "!");
            tell_room(environment(caster), "%^CYAN%^The bolt of living sound %^BOLD%^%^BLACK%^t%^CYAN%^h%^BLACK%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^s %^RESET%^%^CYAN%^into " + target->QCN + ", %^BOLD%^b%^ORANGE%^l%^WHITE%^a%^CYAN%^st%^WHITE%^i%^ORANGE%^n%^CYAN%^g %^RESET%^%^CYAN%^" + target->QP + " " + target_limb + "!", ({ target }));
            break;

        default:
            tell_object(target, "%^WHITE%^%^BOLD%^The bolt of living lightning strikes you, electrifying your " + target_limb + ".");
            tell_room(environment(caster), "%^WHITE%^%^BOLD%^The bolt of living lightning strikes " + target->QCN + ", electrifying " + target->QP + " " + target_limb + ".", ({ target }));
            break;
        }
        damage_targ(target, target_limb, sdamage, element);
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
