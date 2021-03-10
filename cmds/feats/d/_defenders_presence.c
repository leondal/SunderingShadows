#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;


void create()
{
    ::create();
    feat_type("instant");
    feat_category("ImmortalDefender");
    feat_name("defenders presence");
    feat_prereq("Immortal defender L1");
    feat_syntax("defenders_presence");
    feat_desc("The immortal defender can project his presence to his nearby allies. Any fighting on the side of the immortal defender will be inspired. The wounds of the immortal defender and his allies will slowly heal while in battle and the defender and his allies will be inspired to new heights of vigor while in combat.");
    set_target_required(0);
    set_required_for(({ "shield charge", "shield master" }));
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if (ob->query_class_level("immortal_defender") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_defenders_presence(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    if (FEATS_D->is_active(caster, "defenders presence")) {
        tell_object(caster, "Defender's Presence is already active.");
        dest_effect();
        return;
    }

    if (!caster->is_wearing_type("shield")) {
        tell_object(caster, "You must be wearing a shield to use defender's presence.");
        dest_effect();
        return;
    }

    ::execute_feat();

    if (sizeof(caster->query_wielded())) {
        tell_object(caster, "%^RESET%^%^RED%^You slam your weapon on your shield and inspire any nearby allies!");
    }else {
        tell_object(caster, "%^RESET%^%^RED%^You slam your fist on your shield and inspire any nearby allies!");
    }

    caster->set_property("active_feats", ({ TO }));

    return;
}

int protecting_count(object obj)
{
    object* inven;
    int i, count = 1;

    if (!objectp(obj) || !objectp(environment(obj))) {
        return 0;
    }

    inven = all_living(environment(obj));
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (member_array(obj, inven[i]->query_protectors()) != -1) {
            count++;
        }
    }

    return count;
}

// works like an AoE warrior's constitution, with greater bonuses the more people
// the immortal defender is protecting
void execute_attack()
{
    object* party = ({}), healed = ({});
    string party_name;
    int i, damage, count;

    if (!objectp(caster) || caster->query_ghost()) {
        dest_effect();
        return;
    }

    if (!caster->is_wearing_type("shield")) {
        tell_object(caster, "You must be wearing a shield to use defenders presence.");
        dest_effect();
        return;
    }

    place = environment(caster);
    party = ob_party(caster);
    count = protecting_count(caster); // the more people the caster is protecting, the better the aura works
    if (count < 2) {
        count = 2;
    }
    //count = 100;
    if (!sizeof(party)) {
        party = ({ caster });
    }

    for (i = 0; i < sizeof(party); i++) {
        if (!objectp(caster) || caster->query_ghost()) {
            dest_effect();
            return;
        }

        if (caster->query_unconscious()) {
            continue;
        }
        if (!objectp(party[i])) {
            continue;
        }
        if (environment(party[i]) != environment(caster)) {
            continue;
        }

        // don't do anything while we're not in combat
        if (!sizeof(caster->query_attackers())) {
            continue;
        }

        damage = clevel * count;

        if (party[i]->query_hp_percent() < 100) {
            // token amount of healing while in combat and below full health
            party[i]->cause_typed_damage(party[i], party[i]->return_target_limb(), -(roll_dice(clevel, 2) + 10), "untyped");
            if (party[i] != caster) {
                tell_object(party[i], "%^RESET%^%^BOLD%^%^GREEN%^You feel inspired by " + caster->QCN + "'s "
                            "extraodinary defense and your courage lends strength to your wounds!%^RESET%^");
            }else {
                tell_object(party[i], "%^RESET%^%^BOLD%^%^GREEN%^Your wounds heal as you skillfully maneuver behind "
                            "your shield!%^RESET%^");
            }
        }else {
            if (party[i]->query_extra_hp() < damage) {
                if (party[i] != caster) {
                    tell_object(party[i], "%^RESET%^%^BOLD%^%^RED%^" + caster->QCN + "'s extraordinary defense inspires you!");
                }else {
                    tell_object(party[i], "%^RESET%^%^BOLD%^%^RED%^Your skill behind the shield fills you with the vigor of battle!");
                }
                party[i]->add_extra_hp(damage);
            }
        }
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
    return;
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^BOLD%^Your defenders presence deactivates.");
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
