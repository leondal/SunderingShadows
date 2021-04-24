#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_spell_name("shield of dawn");
    set_spell_level(([ "bard" : 4, "cleric" : 4, "paladin":4, "ranger":4]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS shield of dawn");
    set_description("This spell will surround the caster's body in a roaring shield of flames that will harm all opponents.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_object(caster, "%^YELLOW%^%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^oa%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^g %^BOLD%^%^BLACK%^f%^RESET%^%^RED%^l%^BOLD%^a%^ORANGE%^me%^RED%^s r%^RESET%^%^RED%^a%^BOLD%^i%^RESET%^%^RED%^se %^BOLD%^a%^RESET%^%^RED%^round and %^BOLD%^en%^RESET%^%^RED%^cir%^BOLD%^c%^RESET%^%^RED%^l%^BOLD%^e %^RESET%^%^RED%^yo%^BOLD%^u%^RESET%^%^RED%^!%^WHITE%^");
    tell_room(place, "%^YELLOW%^%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^oa%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^g %^BOLD%^%^BLACK%^f%^RESET%^%^RED%^l%^BOLD%^a%^ORANGE%^me%^RED%^s r%^RESET%^%^RED%^a%^BOLD%^i%^RESET%^%^RED%^se %^BOLD%^a%^RESET%^%^RED%^round and %^BOLD%^en%^RESET%^%^RED%^cir%^BOLD%^c%^RESET%^%^RED%^l%^BOLD%^e " + caster->QCN + "!%^WHITE%^", caster);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ "%^BOLD%^%^BLACK%^(%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^%^RED%^cir%^BOLD%^c%^RESET%^%^RED%^led by f%^BOLD%^l%^ORANGE%^a%^RED%^m%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^)%^RESET%^" }));
    addSpellToCaster();
    spell_successful();
    counter = 2 * clevel;
    execute_attack();
    call_out("room_check", ROUND_LENGTH);
}

void room_check()
{
    if (!objectp(caster) || !objectp(ENV(caster))) {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check", ROUND_LENGTH * 2);
    return;
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = ENV(caster);

    if (!objectp(caster) || !objectp(place) || counter < 0) {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();

    if (sizeof(foes)) {
        define_base_damage(0);         //reroll each turn
        tell_room(place, "%^BOLD%^%^RED%^Flames around " + caster->QCN + " burn " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^RED%^Flames burn your enemies!");

        define_base_damage(0);
        for (i = 0; i < sizeof(foes); i++) {
            if (SAVING_D->saving_throw(foes[i], "spell", 0)) {
                continue;
            }
            tell_object(foes[i], "%^RED%^Y%^BOLD%^o%^RESET%^%^RED%^u a%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^e b%^BOLD%^u%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^e%^BOLD%^d %^RESET%^%^RED%^by t%^BOLD%^h%^RESET%^%^RED%^e fl%^BOLD%^a%^ORANGE%^m%^RED%^e%^RESET%^%^RED%^s as %^BOLD%^%^BLACK%^y%^RESET%^%^RED%^ou s%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^ri%^BOLD%^%^BLACK%^k%^RESET%^%^RED%^e %^WHITE%^" + caster->QCN + "!");
            //damage_targ(foes[i], foes[i]->return_target_limb(), sdamage, "fire");
            foes[i]->cause_typed_damage(foes[i], foes[i]->return_target_limb(), sdamage, "fire");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_object(caster, "%^RED%^Roaring flames flicker and fades away.");
        tell_room(environment(caster), "%^RED%^Roaring flames flicker and fade away, leaving " + caster->QCN + " vulnerable once again.", caster);
        caster->remove_property_value("added short", ({ "%^BOLD%^%^BLACK%^(%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^%^RED%^cir%^BOLD%^c%^RESET%^%^RED%^led by f%^BOLD%^l%^ORANGE%^a%^RED%^m%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^)%^RESET%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
