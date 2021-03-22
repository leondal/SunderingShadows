#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;
string element;
mapping shortmap, colormap;
shortmap = ([
                "fire" : " %^BOLD%^%^BLACK%^(%^RESET%^%^RED%^bathed in flames%^BOLD%^%^BLACK%^)%^RESET%^",
                "cold" : " %^BOLD%^%^BLACK%^(%^RESET%^%^CYAN%^in an icy haze%^BOLD%^%^BLACK%^)%^RESET%^",
                "electricity" : " %^BOLD%^%^BLACK%^(%^RESET%^%^ORANGE%^engulfed in stormbolts%^BOLD%^%^BLACK%^)%^RESET%^",
                "acid" : " %^BOLD%^%^BLACK%^(%^RESET%^%^GREEN%^in acid fog%^BOLD%^%^BLACK%^)%^RESET%^",
                ]);
colormap = ([
                "fire" : "%^BOLD%^%^RED%^",
                "cold" : "%^BOLD%^%^BLUE%^",
                "electricity" : "%^BOLD%^%^YELLOW%^",
                "acid" : "%^BOLD%^%^GREEN%^",
                ]);


string* valid_forms()
{
    return ({ "fire", "cold", "electricity", "acid" });
}

void create()
{
    ::create();
    set_spell_name("elemental aura");
    set_spell_level(([ "mage" : 3, "oracle" : 3, "magus" : 3, "cleric" : 3 ]));
    set_domains("elements");
    set_mystery("elemental");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS elemental aura on [acid|cold|electricity|fire]");
    set_damage_desc("based on argument");
    set_description("This spell surrounds the caster with elemental energy that will harm everything that attacks them. Quick enough enemies might evade some of the damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_helpful_spell(1);
    set_arg_needed(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^WHITE%^%^Circling your hands before " + "you, you begin to evoke the element of " + element + ".");
    tell_room(place, "%^BOLD%^%^RED%^Circling " + caster->QP + " hands " + "before " + caster->QO + ", " + caster->QCN + " begins to evoke " + "the element of " + element + ".", caster);
}

int preSpell()
{
    if (caster->query_property("elemental aura")) {
        tell_object(caster, "You are already protected by an elemental aura.");
        return 0;
    }
    if (member_array(arg, valid_forms()) == -1) {
        element = "fire";
    }else {
        element = arg;
    }
    return 1;
}

void spell_effect(int prof)
{
    tell_room(place, colormap[element] + caster->QCN + " completes " + caster->QP + " evocation and is surrounded by " + element + "!", caster);
    tell_object(caster, colormap[element] + "You complete your evocation and are surrounded by " + element + "!");
    caster->set_property("elemental aura", 1);
    caster->set_property("spelled", ({ TO }));
    caster->set_property("added short", ({ shortmap[element] }));
    addSpellToCaster();
    spell_successful();
    counter = 7 * clevel;
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

void execute_attack()
{
    object* foes = ({}), targ;
    int i, dam;

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
        define_base_damage(0);//reroll each turn
        tell_room(place, colormap[element] + capitalize(element) + " around " + caster->QCN + " scorches " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, colormap[element] + "The elemental aura scorches your enemies!");

        define_base_damage(0);

        for (i = 0; i < sizeof(foes); i++) {
            dam = sdamage;

            if (!objectp(foes[i])) {
                continue;
            }

            if (do_save(foes[i], 0)) {
                dam /= 2;
            }

            tell_object(foes[i], colormap[element] + "You are burned by a shield of flames as you strike "
                        "" + caster->QCN + "!");
            damage_targ(foes[i], foes[i]->return_target_limb(), dam, element);
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_room(ENV(caster), colormap[element] + "The elemental aura around " + caster->QCN + " fades away.", caster);
        tell_object(caster, colormap[element] + "The elemental aura around you fades away.", caster);
        caster->remove_property("elemental aura");
        caster->remove_property_value("added short", ({ shortmap[element] }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
