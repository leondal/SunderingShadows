// Saide@ShadowGate
// April 10 2004
// Updated by ~Circe~ 4/26/08 with the rebalancing of domains
// Made a bolt spell like other similar spells

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("saide");
    set_spell_name("searing light");
    set_spell_level(([ "cleric" : 3, "inquisitor" : 3, "innate" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("sun");
    set_syntax("cast CLASS searing light on TARGET");
    set_description("By using this spell you will accumulate sunlight in an open palm and then release it at the target"
                    ".  It will do slightly more damage to the undead.  In addition, nearby targets may be struck as well.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_damage_desc("divine damage, counts as two spell levels higher vs undead for damage calcs");
    set_immunities(({ "spell_immunity" }));
    set_save("reflex");
    splash_spell(1);
}

int preSpell()
{
    if (!objectp(target)) {
        tell_object(caster, "This spell requires a target.");
        return 0;
    }
    return 1;
}

spell_effect(int prof)
{
    int damage, i;
    object* attackers;

    if (!objectp(caster) || !objectp(target)) {
        dest_effect();
        return;
    }

    tell_room(place, "%^ORANGE%^" + caster->QCN + " opens " + caster->QP + " hand " +
              "and chants loudly as " + caster->QP + " palm begins " +
              "accumulating light!", caster);
    tell_object(caster, "%^ORANGE%^You open your hand and chant loudly " +
                "as your palm begins accumulating light!%^RESET%^");

    if (!present(target, place)) {
        tell_object(caster, "%^BOLD%^Your target is not in this area.");
        dest_effect();
        return 1;
    }
    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);

    if (sizeof(attackers)) {
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }
            define_base_damage(0);
            damage = sdamage;
            if (attackers[i]->query_property("undead") || (string)attackers[i]->query_race() == "undead") {
                define_base_damage(2);
                damage = sdamage;
            }
            if (attackers[i] == target) {
                tell_object(target, "%^YELLOW%^A ray of sunlight " +
                            "burns forth from " + caster->QCN + "'s palm, searing " +
                            "you!%^RESET%^");
                tell_object(caster, "%^YELLOW%^You channel the " +
                            "accumulated sunlight into a powerful ray, " +
                            "sending it forth to sear " + target->QCN + "!%^RESET%^");
                tell_room(place, "%^YELLOW%^A powerful ray of sunlight " +
                          "from " + caster->QCN + " sears " + target->QCN + "!" +
                          "%^RESET%^", ({ caster, target }));
                spell_kill(attackers[i], caster);
                if (!do_save(attackers[i], 0)) {
                    //if(!SAVING_D->saving_throw(attackers[i],"spell",0))
                    damage_targ(attackers[i], attackers[i]->return_target_limb(), damage, "divine");
                }else {
                    damage_targ(attackers[i], attackers[i]->return_target_limb(), damage / 2, "divine");
                }
            }else {
                if (!do_save(attackers[i], 0)) {
                    //if(!SAVING_D->saving_throw(attackers[i],"spell",0)){
                    tell_room(place, "%^YELLOW%^" + attackers[i]->QCN + " is struck by " +
                              "a ray of sunlight!%^RESET%^", attackers[i]);
                    tell_object(attackers[i], "%^YELLOW%^A ray of " +
                                "sunlight sears into your flesh!%^RESET%^");
                    damage_targ(attackers[i], attackers[i]->return_target_limb(), damage, "divine");
                    spell_kill(attackers[i], caster);
                }else {
                    tell_room(place, "%^YELLOW%^" + attackers[i]->QCN + " is " +
                              "grazed by the ray of sunlight!%^RESET%^", attackers[i]);
                    tell_object(attackers[i], "%^YELLOW%^The ray of " +
                                "sunlight grazes you!%^RESET%^");
                    damage_targ(attackers[i], attackers[i]->return_target_limb(), damage / 2, "divine");
                    spell_kill(attackers[i], caster);
                }
            }
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
