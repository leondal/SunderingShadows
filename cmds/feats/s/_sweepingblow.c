#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("TwoHandedWeapons");
    feat_name("sweepingblow");
    feat_prereq("Strength 13");
    feat_desc("The SweepingBlow feat will send your weapon in a large arc out in front of you, trying to hit any attackers that stand in your way");
    feat_syntax("sweepingblow");
    set_save("reflex");
    set_target_required(0);
    set_required_for(({ "blade block", "impale", "light weapon", "strength of arm" }));
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
    if ((int)ob->query_base_stats("strength") < 13) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_sweepingblow(string str)
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
    object* weapons;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if ((int)caster->query_property("using sweeping blow") > time() && !FEATS_D->usable_feat(caster, "wade through")) {
        tell_object(caster, "It's too soon to use sweeping blow again yet!");
        dest_effect();
        return;
    }

    weapons = caster->query_wielded();
    if (!caster->validate_combat_stance("two hander")) {
        tell_object(caster, "You need to be wielding a two handed weapon to use this feat.");
        dest_effect();
        return;
    }
    if (weapons[0]->is_lrweapon()) {
        tell_object(caster, "That weapon is not designed for such an attack.");
        dest_effect();
        return;
    }
    if (!sizeof(caster->query_attackers())) {
        tell_object(caster, "You're not fighting anything, so you swing your weapon "
                    "in a wild arc for fun!");
        tell_room(place, "" + caster->QCN + " grins and swings " + caster->QP + " weapon in "
                  "a wild arc!", caster);
        dest_effect();
        return;
    }

    ::execute_feat();

    tell_object(caster, "%^BOLD%^%^GREEN%^You growl as you swing your weapon in "
                "a wide sweeping arc, trying to hit everything in front of you!%^RESET%^");
    tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " growls as " + caster->QS + " swings " + caster->QP + " weapon in a sweeping arc in front of " + caster->QO + "!%^RESET%^", caster);

    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;

}

void execute_attack()
{
    object* weapons, * attackers;
    int i, dam, mod, num, reaping, diff, res;
    string dtype;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");

    caster->remove_property("using sweeping blow");
    caster->set_property("using sweeping blow", (time() + 35));
    if (!FEATS_D->usable_feat(caster, "wade through")) {
        delay_messid_msg(35, "%^BOLD%^%^WHITE%^You can %^CYAN%^sweepingblow%^WHITE%^ again.%^RESET%^");
    }

    ::execute_attack();

    attackers = (object*)caster->query_attackers();
    weapons = caster->query_wielded();

    if (!caster->validate_combat_stance("two hander")) {
        tell_object(caster, "You need to be wielding a two handed weapon to use this feat!");
        dest_effect();
        return;
    }
    if (weapons[0]->is_lrweapon()) {
        tell_object(caster, "That weapon is not designed for such an attack.");
        dest_effect();
        return;
    }
    if (!sizeof(attackers)) {
        tell_object(caster, "You have nothing to hit with your weapon and "
                    "your momentum spins you around and nearly drops you onto the ground!");
        tell_room(place, "" + caster->QCN + " spins around wildly and nearly falls onto the ground!", caster);
        dest_effect();
        return;
    }

    if (FEATS_D->usable_feat(caster, "the reaping")) {
        reaping = 1;
    }

    attackers = shuffle(attackers);

    for (i = 0; i < sizeof(attackers) && i < 8; i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        dam = weapons[0]->query_wc();
        dam = roll_dice(clevel, 4) + dam;
        if (reaping) {
            dam = roll_dice(clevel, 8) + dam;
        }
        if ((res = thaco(attackers[i])) > 0) {

            num = 1;
            tell_object(attackers[i], "%^BOLD%^%^CYAN%^" + caster->QCN + "'s weapon slams "
                        "into you as it sweeps by!%^RESET%^");
            attackers[i]->cause_typed_damage(attackers[i],attackers[i]->return_target_limb(), dam, weapons[0]->query_damage_type());
            if (reaping && !attackers[i]->reflex_save(clevel) && !attackers[i]->query_property("no knockdown") && !attackers[i]->query_property("no trip")) {
                tell_object(attackers[i], "%^BOLD%^%^GREEN%^" + caster->QCN + "'s weapon hits you with "
                            "such force that it knocks you flat onto the ground!");
                attackers[i]->set_tripped(clevel / 10, "%^BOLD%^%^GREEN%^You are trying to get up!");
            }
        }else if (res == -1) {
            if (!num) {
                num - 1;
            }
            if (stringp(caster->query("featMiss"))) {
                tell_object(caster, caster->query("featMiss") + " " + query_feat_name() + "!");
                caster->delete("featMiss");
            }
        }
        continue;
    }

    if (!num) {
        tell_object(caster, "%^BOLD%^Your wild swing doesn't hit anything at all, leaving you "
                    "off balance!%^RESET%^");
        tell_room(place, "%^BOLD%^" + caster->QCN + "'s wild swing doesn't hit anything at all "
                  "and it leaves " + caster->QO + " off balance!%^RESET%^", caster);
        caster->set_paralyzed(roll_dice(1, 4), "%^BOLD%^You are struggling to regain your balance!%^RESET%^");
    }else if (num > 0) {
        if (reaping) {
            mod = clevel * 4;

            if (caster->query_hp() < caster->query_max_hp()) {
                diff = caster->query_max_hp() - caster->query_hp();
                if (diff >= mod) {
                    caster->add_hp(mod);
                    mod = 0;
                }else {
                    caster->add_hp(diff);
                    mod = mod - diff;
                }
            }
            if (mod && (caster->query_extra_hp() < mod)) {
                caster->add_extra_hp(mod - caster->query_extra_hp());
            }

            tell_object(caster, "%^BOLD%^%^RED%^You are filled with bloodlust and eagerness for battle as you reap your foes!");
        }

        attackers += ({ caster });
        tell_object(caster, "%^BOLD%^%^CYAN%^Your " + weapons[0]->query_short() + " slams into your opponents as it sweeps by!%^RESET%^");
        tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s weapon slams into " + caster->QP + " opponents as it sweeps by!%^RESET%^", attackers);
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
