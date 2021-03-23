// tidal surge
//adjusted to be a damage spell since this is 8th level
//brought in line with windstorm and stormrage by
//~Circe~ 5/6/08 with the rebalancing of domains

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("tidal surge"); // Tsunami
    set_spell_level(([ "druid" : 9, "mage" : 9, "oracle" : 9 ]));
    set_mystery("waves");
    set_spell_sphere("conjuration_summoning");
    set_domains(({ "moon" }));
    set_syntax("cast CLASS tidal surge on TARGET");
    set_description("This spell will draw all of the water in the atmosphere for miles and miles around to a place above "
                    "and behind the caster.  The water is condensed into the form of a massive wave that is directed at the target.  The wave "
                    "may knock the target down as well as force him to drop his weapons.  The force of the water may also keep him from "
                    "moving until he regains his senses.  Because of the size of the wave, nearby targets may be hit as well.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
    splash_spell(2);
}

int preSpell()
{
    if (!objectp(target)) {
        tell_object(caster, "This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLUE%^A low roar caresses your ears " +
                "as you begin to intone the words of this prayer.%^RESET%^");
    tell_room(place, "%^BOLD%^%^BLUE%^A low roar can be heard as " + caster->QCN + " " +
              "begins to intone the words of a flowing prayer.%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    int dam, i;
    string* ids;
    object* weapons, * foes, * ownparty;

    if (!objectp(target) || !objectp(caster)) {
        dest_effect();
        return;
    }
    foes = ({});
    ownparty = ({});
    dam = sdamage;
    tell_object(caster, "%^CYAN%^As your continue to chant, you can feel the water "
                "for miles and miles being pulled from the very air to heed your call!");
    tell_room(place, "%^BOLD%^%^CYAN%^Your mouth begins to feel dry as " + caster->QCN + " "
              "continues to chant.", caster);
    tell_object(caster, "%^CYAN%^As you complete the " +
                "chant, you send your arms foward, " +
                "directing the path of a tremendous wave!%^RESET%^", caster);
    tell_room(place, "%^CYAN%^As " + caster->QCN + " completes the " +
              "chant, " + caster->QS + " sends " + caster->QP + " arms foward, " +
              "directing the path of a tremendous wave!%^RESET%^", caster);
    tell_object(place, "%^BOLD%^The %^BLUE%^wave%^WHITE%^ widens, " +
                "striking all in its path!%^RESET%^");

    if (do_save(target, 0)) {
        tell_object(target, "%^BOLD%^Thankfully, you manage to keep your " +
                    "footing!%^RESET%^");
        tell_room(place, "%^BOLD%^" + target->QCN + " manages to keep " +
                  "" + target->QP + " footing!%^RESET%^", target);
        damage_targ(target, (string)target->return_target_limb(), (dam / 2), "bludgeoning");
    }else {
        tell_object(target, "%^BOLD%^%^CYAN%^You are swept beneath the " +
                    "wave!%^RESET%^");
        tell_room(place, "%^BOLD%^%^CYAN%^" + target->QCN + " is swept " +
                  "beneath the wave!%^RESET%^", target);
        if (!random(3)) {
            target->set_tripped(roll_dice(1, 4), "You are " +
                                "trying to recover from the wave!", 2); //capping duration 2 rounds. N, 5/11.
        }
        if (!random(3)) {
            weapons = target->query_wielded();
            if (sizeof(weapons) && !target->query_property("no disarm")) {
                tell_object(target, "%^BOLD%^%^WHITE%^Your weapons fly " +
                            "from your grasp!");
                tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + " " +
                          "loses " + target->QP + " weapons!%^RESET%^", target);
                for (i = 0; i < sizeof(weapons); i++) {
                    ids = weapons[i]->query_id();
                    if (weapons[i]->query_property("enchantment") < 0) {
                        continue;
                    }
                    target->force_me("unwield " + ids[0] + "");
                    target->remove_property("disarm time");
                    target->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, 4)));
                }
            }
        }
        damage_targ(target, (string)target->return_target_limb(), dam, "bludgeoning");
    }

    foes += target_selector();
        foes -= ({ target });

    for (i = 0; i < sizeof(foes); i++) {
        if (!objectp(foes[i])) {
            continue;
        }
        if (!present(foes[i], place)) {
            continue;
        }
        if (do_save(foes[i], 0)) {
            tell_object(foes[i], "%^BOLD%^Thankfully, you avoid the brunt " +
                        "of the wave!%^RESET%^");
            tell_room(place, "%^BOLD%^" + foes[i]->QCN + " avoids the worst " +
                      "of the wave!%^RESET%^", foes[i]);
            damage_targ(foes[i], (string)foes[i]->return_target_limb(), (dam / 2), "bludgeoning");
        }else {
            tell_object(target, "%^BOLD%^%^CYAN%^You are hit with the force " +
                        "of the wave!%^RESET%^");
            tell_room(place, "%^BOLD%^%^CYAN%^" + foes[i]->QCN + " is hit with " +
                      "the force of the wave!%^RESET%^", foes[i]);
            damage_targ(foes[i], (string)foes[i]->return_target_limb(), (dam), "bludgeoning");
            if (!random(3)) {
                target->set_tripped(roll_dice(1, 4), "You are " +
                                    "trying to recover from the wave!", 2); //capping duration 2 rounds. N, 5/11.
            }
        }
        if (!sizeof(foes)) {
            break;
        }
    }
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
