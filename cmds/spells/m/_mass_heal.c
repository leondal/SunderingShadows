#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("mass heal");
    set_spell_level(([ "cleric" : 9, "oracle" : 9 ]));
    set_mystery("life");
    set_domains("renewal");
    set_affixed_spell_level(6);
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS mass heal on TARGET");
    set_damage_desc("positive energy");
    set_description("This is a stronger version of the priest spell, heal.  When cast without a target or on the caster "
                    "or any party member, it will heal the caster and any party members of the caster who are present in the area.  When cast "
                    "on a hostile, it will hit all hostiles in the immediate area, healing those that are living, and hurting those that are "
                    "undead.  When cast on a neutral creature that is neither in the caster's party or hostile to the caster, it will hit all "
                    "creatures in the area, healing those that are living and hurting those that are undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
    splash_spell(1);
}

int preSpell()
{
    if (!objectp(target)) {
        tell_object(caster, "You must specify a target for this spell.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^CYAN%^Your voice rings out as you begin to " +
                "chant a powerful prayer, gathering your divine energy into your hands.");
    tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s voice rings out as they" +
              " begin to chant a powerful prayer.  Cupping " + caster->QP + " hands, " +
              "" + caster->QS + " starts to gather divine energy.", caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;
    object* party_members = ({}), * attackers = ({}), * living = ({}), * targets = ({}), * followers = ({});

    set_helpful_spell(0);
    party_members = ob_party(caster);
    attackers = target_selector();
    followers = caster->query_followers();
    living = all_living(place);

    if (!objectp(target)) {
        target = caster;
    }

    if (target == caster ||
        member_array(target, party_members) != -1 ||
        member_array(target, followers) != -1) {
        targets = filter_array(distinct_array(party_members + (followers - attackers) + ({ caster })),
                               (: !$1->query_property("negative energy affinity") :));
        set_helpful_spell(1);
    }else if (member_array(target, attackers) != -1) {
        set_helpful_spell(0);
        targets = filter_array(attackers, (: $1->query_property("negative energy affinity") :));
    }else {
        targets = ({ target });
    }

    targets = distinct_array(targets);

    tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " opens " +
              "" + caster->QP + " hands, releasing a brilliant wave of" +
              " energy as " + caster->QS + " shouts out the final words " +
              "of the prayer.", caster);

    if (sizeof(targets)) {
        int healamnt = calculate_healing();
        for (i = 0; i < sizeof(targets); i++) {
            if (!objectp(targets[i])) {
                continue;
            }
            if (!present(targets[i], place)) {
                continue;
            }
            if (targets[i]->query_property("negative energy affinity")) {
                if (targets[i] == caster) {
                    continue;
                    tell_object(targets[i], "You shouldn't do that to yourself.");
                }
                set_helpful_spell(0);
            }else {
                set_helpful_spell(1);
            }

            if (targets[i] == caster) {
                tell_object(targets[i], "%^BOLD%^%^CYAN%^A brilliant " +
                            "wave moves through you, carrying with it the essence of life.");
            }else {
                tell_room(place, "%^BOLD%^%^CYAN%^A brilliant wave moves through" +
                          " " + targets[i]->QCN + " carrying with it the essence of " +
                          "life, as " + caster->QCN + " voice rings out.", ({ targets[i], caster }));
                tell_object(caster, "%^BOLD%^%^CYAN%^A brilliant " +
                            "wave moves through " + targets[i]->QCN + ", carrying with it the essence of life.");
                tell_object(targets[i], "%^BOLD%^%^CYAN%^A brilliant " +
                            "wave moves through you, carrying with it the essence of life.");
            }
            damage_targ(targets[i], targets[i]->return_target_limb(), healamnt, "positive energy");

            if (query_spell_name() == "mass heal") {
                if (member_array(targets[i], caster->query_attackers()) == -1) {
                    "/std/magic/cleanse"->cleanse(targets[i]);
                }
            }
        }
    }

    spell_successful();
    dest_effect();
    return;
}

int calculate_healing(object targ)
{
    return sdamage * 7 / 6;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
