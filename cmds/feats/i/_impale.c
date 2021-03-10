#include <std.h>
#include <daemons.h>
inherit FEAT;

#define FEATTIMER 35

int in_shapeshift;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("TwoHandedWeapons");
    feat_name("impale");
    feat_syntax("impale TARGET");
    feat_prereq("Sweeping Blow, Blade block or Parry");
    feat_desc("The Impale feat has a chance of impaling your target or staggering them back into another attacker. Both targets will take damage and have a chance to be stunned.

If used without an argument this feat will pick up a random attacker. Be aware that this power affects multiple targets.

A druid with the 'mastery of fang and claw' feat may also use this feat while in dragon form, even if it has not been purchased directly.");
    set_save("fort");
    set_required_for(({ "light weapon", "strength of arm" }));
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
    if (!FEATS_D->has_feat(ob, "blade block") && !FEATS_D->has_feat(ob, "parry")) {
        dest_effect();
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "sweepingblow")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_impale(string str)
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
    object* weapons;
    string type;
    mapping tempmap;

    ::execute_feat();
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using impale");
    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to impale.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if (caster->query_property("shapeshifted") && !caster->query_property("altered")) {
        in_shapeshift = 1;
    }else {
        in_shapeshift = 0;
    }
    if (!in_shapeshift) {
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
    }

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "You don't have a target!");
        dest_effect();
        return;
    }

    if (target == caster) {
        tell_object(caster, "Impale yourself?  You would have to be as dumb as an ogre to do that!");
        dest_effect();
        return;
    }

    if (in_shapeshift) {
        tell_object(caster, "%^BOLD%^%^BLACK%^You rush and impale " + target->QCN + " onto your claws!");
    } else {
        tell_object(caster, "%^BOLD%^%^BLACK%^You step back and quickly thrust your weapon at " + target->QCN + " with all of your might!%^RESET%^");
        tell_object(target, "%^BOLD%^%^BLACK%^" + caster->QCN + " steps back and quickly thrusts " + caster->QP + " weapon at you with all of " + caster->QP + " might!%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " steps back and quickly thrusts " + caster->QP + " weapon at " + target->QCN + " with all of " + caster->QP + " might!%^RESET%^", ({ caster, target }));
    }

    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;
}

void execute_attack()
{
    object* weapons, * attackers, * okattackers, target_two;
    string type, * keyz, theweapon;
    int i, dam, mod, enchant, timerz, mult, reaping, diff, res;
    mapping tempmap, newmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    ::execute_attack();
    weapons = caster->query_wielded();
    if (caster->query_property("shapeshifted") && !caster->query_property("altered")) {
        in_shapeshift = 1;
    }else {
        in_shapeshift = 0;
    }
    if (!in_shapeshift) {
        if (sizeof(weapons) < 2) {
            tell_object(caster, "You need to be wielding a two handed weapon to use this feat!");
            dest_effect();
            return;
        }
        if (weapons[0] != weapons[1]) {
            tell_object(caster, "You need to be wielding a two handed weapon to use this feat!");
            dest_effect();
            return;
        }
        if (weapons[0]->is_lrweapon()) {
            tell_object(caster, "That weapon is not designed for such an attack.");
            dest_effect();
            return;
        }
    }
    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "Your target is no longer here!");
        dest_effect();
        return;
    }

    if (in_shapeshift) {
        type = "blunt";
    }else {
        type = weapons[0]->query_type();
    }
    if (!stringp(type) || !type || type == "") {
        type = "sharp";
    }
    if (strsrch(type, "slash") == -1 && strsrch(type, "pierc" == -1)) {
        type = "blunt";
    }else {
        type = "sharp";
    }

    if (sizeof(weapons)) {
        enchant = (int)weapons[0]->query_property("enchantment");
    }else {
        enchant = 0;
    }

    tempmap = caster->query_property("using impale"); // adding per-target tracking. -N, 9/10.
    if (!mapp(tempmap)) {
        tempmap = ([]);
    }
    if (tempmap[target]) {
        map_delete(tempmap, target);
    }

    attackers = (object*)caster->query_attackers();
    okattackers = ({});
    if (sizeof(attackers)) {
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }
            if (attackers[i] == target) {
                continue;
            }
            if (tempmap[attackers[i]] > time()) {
                continue;
            }
            okattackers += ({ attackers[i] });
            break;
        }
    }
    if (sizeof(okattackers)) {
        target_two = okattackers[0];                     // pick up only attackers who have not been impaled. -N, 9/10.
    }
    newmap = ([]);
    keyz = keys(tempmap);
    if (sizeof(keyz)) {
        for (i = 0; i < sizeof(keyz); i++) {
            if (objectp(keyz[i])) {
                newmap += ([ keyz[i] : tempmap[keyz[i]] ]);
            }
        }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target:timerz ]);
    delay_subject_msg(target, FEATTIMER, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^impaled%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using impale");
    caster->set_property("using impale", newmap);
    if (!(res = thaco(target, enchant))) {
        tell_object(caster, "%^BOLD%^%^MAGENTA%^" + target->QCN + " sidesteps your thrust at the "
                    "last instant, leaving you open to attack!%^RESET%^");
        tell_object(target, "%^BOLD%^%^MAGENTA%^You sidestep " + caster->QCN + "'s attack at the "
                    "last instant, leaving " + caster->QO + " open to attack!%^RESET%^");
        tell_room(place, "%^BOLD%^%^MAGENTA%^" + target->QCN + " sidesteps " + caster->QCN + "'s attack "
                  "at the last instant, leaving " + caster->QP + " open to attack!%^RESET%^", ({ caster, target }));
        caster->set_paralyzed(roll_dice(1, 6), "%^YELLOW%^You are trying to get back into "
                              "position!%^RESET%^");
        dest_effect();
        return;
    }else if (res == -1) {
        if (stringp(caster->query("featMiss"))) {
            tell_object(caster, caster->query("featMiss") + " " + query_feat_name() + "!");
            caster->delete("featMiss");
        }else {
            tell_object(caster, "%^RED%^" + target->QCN + " is totally unaffected!%^RESET%^");
            tell_room(place, "%^RED%^" + target->QCN + " is totally unaffected!%^RESET%^", ({ target, caster }));
        }
        dest_effect();
        return;
    }
    if (FEATS_D->usable_feat(caster, "the reaping")) {
        reaping = 1;
    }

    mult = 8; // this was 4, which was average damage of about 60 hitpoints at level 50, average of about 24 damage at level 20...
    if (reaping) {
        mult = 16;
    }

// picking up 12 as a benchmark for druid shift, two-hand sword equiv
    if (sizeof(weapons)) {
        dam = weapons[0]->query_wc();
    }else {
        dam = 12;
    }
    dam = ((clevel - 1) / 10 + 1) * (dam / 2); //let it scale properly in 10-level blocks. -N, 9/10
    if (sizeof(weapons)) {
        dam += roll_dice(mult, dam) + weapons[0]->query_wc();
    }else {
        dam += roll_dice(mult, dam) + 12;
    }
    dam += "/daemon/bonus_d"->damage_bonus(caster->query_stats("strength"));
    dam += (int)caster->query_damage_bonus();
    mod = dam * -1;

    if (!in_shapeshift) {
        theweapon = weapons[0]->query_short();
    }else {
        theweapon = "body";
    }

    switch (type) {
    case "sharp":
        tell_object(caster, "%^BOLD%^%^RED%^You impale " + target->QCN + " with your " + theweapon + ", "
                    "running " + target->QO + " through violently!%^RESET%^");
        tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + " impales you with " + caster->QP + " "
                    "" + theweapon + ", running you through violently!%^RESET%^");
        tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " impales " + target->QCN + " with " + caster->QP + " "
                  "" + theweapon + ", running " + target->QO + " through violently!%^RESET%^", ({ target, caster }));
        break;

    case "blunt":
        tell_object(caster, "%^BOLD%^%^BLUE%^You slam your " + theweapon + " into "
                    "" + target->QCN + " brutally, staggering " + target->QO + " backwards!%^RESET%^");
        tell_object(target, "%^BOLD%^%^BLUE%^" + caster->QCN + " slams " + caster->QP + " "
                    "" + theweapon + " into you, staggering you backwards!%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " slams " + caster->QP + " "
                  "" + theweapon + " into " + target->QCN + ", staggering " + target->QP + " "
                  "backwards!%^RESET%^", ({ target, caster }));
        break;
    }

    if (!do_save(target, mod)) {
        tell_object(caster, "%^BOLD%^%^GREEN%^Your attack leaves " + target->QCN + " stunned and "
                    "unable to move!%^RESET%^");
        tell_object(target, "%^BOLD%^%^GREEN%^" + caster->QCN + "'s attack leaves you stunned and "
                    "unable to move!%^RESET%^");
        tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + "'s attack leaves " + target->QCN + " stunned "
                  "and unable to move!%^RESET%^", ({ target, caster }));
        target->set_paralyzed(roll_dice(2, 4), "%^YELLOW%^You are struggling to move!%^RESET%^");
    }

    if (objectp(target_two)) {
        switch (type) {
        case "sharp":
            tell_object(caster, "%^BOLD%^%^YELLOW%^Your " + theweapon + " penetrates "
                        "all the way through " + target->QCN + " and hits, " + target_two->QCN + "!%^RESET%^");
            tell_object(target_two, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s " + theweapon + " "
                        "penetrates all the way through " + target->QCN + " and hits you!");
            tell_object(target, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s " + theweapon + " "
                        "penetrates all the way through you and hits " + target_two->QCN + "!%^RESET%^");
            tell_room(place, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s " + theweapon + " "
                      "penetrates all the way through " + target->QCN + " and hits " + target_two->QCN + "!%^RESET%^",
                      ({ target, caster, target_two }));
            break;

        case "blunt":
            tell_object(caster, "%^BOLD%^%^CYAN%^Your attack staggers " + target->QCN + " back, slamming "
                        "" + target->QO + " into " + target_two->QCN + "!%^RESET%^");
            tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s attack staggers you back into "
                        "" + target_two->QCN + "!%^RESET%^");
            tell_object(target_two, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s attack staggers " + target->QCN + " "
                        "backwards into you!%^RESET%^");
            tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s attack staggers " + target->QCN + " back "
                      "into " + target_two->QCN + "!%^RESET%^", ({ target, target_two, caster }));
            break;
        }

        if (!do_save(target_two, mod)) {
            tell_object(target_two, "%^BOLD%^%^YELLOW%^The attack staggers you, knocking you off "
                        "balance!%^RESET%^");
            tell_room(place, "%^BOLD%^%^YELLOW%^" + target_two->QCN + " is staggered and knocked out "
                      "of balance!%^RESET%^", target_two);
            target_two->set_paralyzed(roll_dice(2, 4), "%^YELLOW%^You are trying to regain "
                                      "your balance!%^RESET%^");
        }
    }

    {

        string dtype;

        if (sizeof(weapons)) {
            if (objectp(weapons[0])) {
                dtype = weapons[0]->query_damage_type();
            }
        }

        dtype = dtype ? dtype : "piercing";

        if (target->query_property("weapon resistance")) {
            if (enchant < (int)target->query_property("weapon resistance")) {
                target->cause_typed_damage(target, target->return_target_limb(), 0, dtype);
            }
        }else {
            target->cause_typed_damage(target, target->return_target_limb(), dam, dtype);
        }

    }

    if (objectp(target_two)) {
        if (caster->query_property("shapeshifted") && caster->query_unarmed_wc() >= target_two->query_property("weapon resistance")) {
            target_two->cause_typed_damage(target_two, target_two->return_target_limb(), dam, "piercing");
        }else if (target_two->query_property("weapon resistance")) {
            if (enchant < (int)target_two->query_property("weapon resistance") && sizeof(weapons)) {
                target_two->cause_typed_damage(target_two, target_two->return_target_limb(), 0, weapons[0]->query_damage_type());
            }
        }else {
            if (sizeof(weapons)) {
                target_two->cause_typed_damage(target_two, target_two->return_target_limb(), dam, weapons[0]->query_damage_type());
            }
        }

        newmap += ([ target_two:timerz ]);
    }


    if (reaping) {
        if (objectp(target_two)) {
            mod = clevel * 3;
        }else {
            mod = to_int(clevel * 1.5);
        }

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

    caster->remove_property("using impale");
    caster->set_property("using impale", newmap);
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
