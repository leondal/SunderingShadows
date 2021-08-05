#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_name("channel");
    feat_prereq("Cleric L1 or Paladin L4");
    feat_classes(({"paladin", "cleric"}));
    feat_desc("This power allows divine caster to channel primal energies (negative or positive) at their allies and foes. The type of energy will depend on your affinity, e.g. undead will channel negative energy while living will channel positive energy. This feat will auto determine which type of energy is appliable to allies and enemies. This feat costs one Divine Grace point to use.");
    feat_syntax("channel");
    set_required_for(({"improved channel","extra grace","channel smite"}));
    set_target_required(0);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("cleric") ||
          ob->query_class_level("paladin") >= 4)) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_channel(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

void execute_feat()
{
    object *weapons;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if(!(int)USER_D->spend_pool(TP, 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to Channel Energy!");
        return;
    }
    /*
    else if ((int)caster->query_property("using channel") > time() &&
        !FEATS_D->usable_feat(caster, "supreme healer")) {
        tell_object(caster, "It's too soon to use channel again yet!");
        dest_effect();
        return;
    }
    */

    ::execute_feat();

    tell_object(caster,"%^BOLD%^%^WHITE%^You waver unevenly as you prepare to channel primal energies through yourself.%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" %^BOLD%^%^WHITE%^softly murmurs a prayer with arms held aloft.%^RESET%^",caster);

    caster->set_property("using instant feat",1);
    return;
}

void execute_attack()
{
    object *allies,*attackers;
    object ally, attacker;
    string energy_type;
    string color;
    int dam;
    int i;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");

    caster->remove_property("using channel");

    if(caster->query_class_level("cleric"))
    {
        caster->set_property("using channel",(time() + 35));

        if (!FEATS_D->usable_feat(caster, "supreme healer")) {
            delay_messid_msg(35, "%^BOLD%^%^WHITE%^You can %^CYAN%^channel%^WHITE%^ again.%^RESET%^");
        }
    }

    ::execute_attack();

    attackers = caster->query_attackers();

    allies = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    allies = filter_array(allies, (: environment($1) == $2:), environment(caster));
    allies = ({caster}) + allies;
    allies = distinct_array(allies);

    dam = flevel + (FEATS_D->usable_feat(caster, "improved channel") * 2);
    dam = roll_dice(dam, 10) + (member_array("sun", caster->query_divine_domain()) >= 0 ? caster->query_class_level("cleric") : 0);

    if (caster->query_property("negative energy affinity")) {
        energy_type = "negative energy";
        color = "%^BLACK%^";
    } else {
        energy_type = "positive energy";
        color = "%^WHITE%^";
    }

    tell_room(ENV(caster), "%^BOLD%^" + color + "The area is washed with divine energies!");

    allies = shuffle(allies);

    for (i = 0; i < sizeof(allies) && i < 8; i++) {
        ally = allies[i];

        if (!objectp(ally)) {
            continue;
        }

        if (energy_type == "negative energy" && !ally->query_property("negative energy affinity")) {
            continue;
        }

        if (energy_type == "positive energy" && ally->query_property("negative energy affinity")) {
            continue;
        }

        ally->cause_typed_damage(ally, ally->return_target_limb(), dam, energy_type);
        tell_object(ally, "%^BOLD%^" + color + "Waves of divine energy wash over you, healing your wounds!");
    }

    attackers = shuffle(attackers);

    for (i = 0; i < sizeof(attackers) && i < 8; i++) {
        attackers = attackers[i];
        if (!objectp(attacker)) {
            continue;
        }

        if (energy_type == "negative energy" && attacker->query_property("negative energy affinity")) {
            continue;
        }

        if (energy_type == "positive energy" && !attacker->query_property("negative energy affinity")) {
            continue;
        }

        attacker->cause_typed_damage(attacker, attacker->return_target_limb(), dam, energy_type);
        tell_object(attacker, "%^BOLD%^" + color + "Waves of divine energy wash over you, wounding you!");
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
