// originally a ranger command
// reverted to a feat with damage realigned roughly to tabletop as ranger-levels are now irrelevant
// Nienne, 04/10.
#include <std.h>
#include <daemons.h>
inherit FEAT;

void display_messages(object targ, object player);

int in_shapeshift;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("TwoWeapons");
    feat_name("whirl");
    feat_syntax("whirl");
    feat_prereq("Ambidexterity or Weapon Finesse");
    feat_desc("Whirl is an instant combat feat that can be used to execute a strike against each foe in reach. The command requires at least one target to work, and will use a small amount of stamina.

 A druid with the 'mastery of fang and claw' feat may also use this feat while in cat form, even if it has not been purchased directly.");
    set_target_required(0);
    set_required_for(({ "two weapon fighting", "improved two weapon fighting", "unassailable parry" }));
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
    if (!FEATS_D->has_feat(ob, "ambidexterity") && !FEATS_D->has_feat(ob, "weapon finesse")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_whirl(string str)
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
    int attack_count;
    object* weapons;

    if ((int)caster->query_property("using whirl") > time() && !FEATS_D->usable_feat(caster, "whirling dervish")) {
        tell_object(caster, "You can't try to whirl again so soon!");
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", TP);
        dest_effect();
        return;
    }
    ::execute_feat();
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (!sizeof(caster->query_attackers())) {
        tell_object(caster, "%^YELLOW%^You're not fighting anyone!\n");
        dest_effect();
        return;
    }
    if (caster->query_property("shapeshifted") && !caster->query_property("altered")) {
        in_shapeshift = 1;
    }else {
        in_shapeshift = 0;
    }
    weapons = caster->query_wielded();
    if (!in_shapeshift) {
        if (!caster->validate_combat_stance("dual wield")) {
            tell_object(caster, "%^YELLOW%^You need to be dual-wielding in order to use this feat!\n");
            dest_effect();
            return;
        }
        if (weapons[0]->is_lrweapon() || weapons[1]->is_lrweapon()) {
            tell_object(caster, "%^YELLOW%^You cannot whirl while using ranged weapons!\n");
            dest_effect();
            return;
        }
    }
    if (in_shapeshift) {
        tell_object(caster, "%^BOLD%^You unleash a flurry of teeth and claws!\n%^RESET%^");
        tell_room(environment(caster), "%^MAGENTA%^" + caster->QCN + " unleashes a flurry of teeth and claws!\n%^RESET%^", caster);
    }else {
        tell_object(caster, "%^BOLD%^You center yourself and drop into a rhythmic spin, whirling your weapons impossibly fast!\n%^RESET%^");
        tell_room(environment(caster), "%^MAGENTA%^" + caster->QCN + " seems to focus " + caster->QO + "self and drops into a spin, " + caster->QP + " weapons begin to whirl impossibly fast!\n%^RESET%^", caster);
    }
    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;
}

void execute_attack()
{
    object* weapons, * attackers;
    int i, udam, dam, num, enchant, hit, res;
    string damtype;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", TP);
        dest_effect();
        return;
    }

    attackers = (object*)caster->query_attackers();
    if (caster->query_property("shapeshifted") && !caster->query_property("altered")) {
        in_shapeshift = 1;
    }else {
        in_shapeshift = 0;
    }
    weapons = caster->query_wielded();
    if (!sizeof(attackers)) {
        tell_object(caster, "%^YELLOW%^You're not fighting anyone!\n");
        dest_effect();
        return;
    }
    if (!in_shapeshift) {
        if (!caster->validate_combat_stance("dual wield")) {
            tell_object(caster, "%^YELLOW%^You need to be dual-wielding in order to use this feat!\n");
            return 1;
        }
        if (weapons[0]->is_lrweapon() || weapons[1]->is_lrweapon()) {
            tell_object(caster, "%^YELLOW%^You cannot whirl while using ranged weapons!\n");
            dest_effect();
            return;
        }
    }

    caster->remove_property("using whirl");
    caster->set_property("using whirl", time() + 35);
    if (!FEATS_D->usable_feat(caster, "whirling dervish")) {
        delay_messid_msg(35, "%^BOLD%^%^WHITE%^You can %^CYAN%^whirl%^WHITE%^ again.%^RESET%^");
    }

    attackers = shuffle(attackers);

    if (sizeof(weapons) && objectp(weapons[0])) {
        enchant = weapons[0]->query_property("enchantment");
        udam = weapons[0]->query_damage();
        damtype = weapons[0]->query_damage_type();
    }else {
        enchant = 0;
    }

    if(!damtype)
    {
        damtype = "slashing";
    }

    udam += caster->query_damage_bonus();

    for (i = 0; i < sizeof(attackers) && i < 8; i++) {

        if (!objectp(attackers[i])) {
            continue;
        }

        dam = udam;
        dam += roll_dice(clevel, 5) + roll_dice(2, 8);

        if (!present(attackers[i], environment(caster))) {
            tell_object(caster, "%^RED%^That target is no longer in range!%^RESET%^");
            continue;
        }

        if (sizeof(weapons)) {
            if (!(res = thaco(attackers[i]))) {
                tell_object(attackers[i], "%^CYAN%^" + caster->QCN + " sends a barrage of attacks your way, but you dodge quickly out of the way!%^RESET%^");
                continue;
            }
        }else {
            if (!(res = thaco(attackers[i]))) {
                tell_object(attackers[i], "%^CYAN%^" + caster->QCN + " sends a barrage of attacks your way, but you dodge quickly out of the way!%^RESET%^");
                continue;
            }
        }

        if (attackers[i]->query_property("weapon resistance") || res == -1) {
            if (!hit) {
                hit = -1;
            }
            if (stringp(caster->query("featMiss"))) {
                tell_object(caster, caster->query("featMiss") + " " + query_feat_name() + "!");
                caster->delete("featMiss");
                continue;
            }
            if (enchant < attackers[i]->query_property("weapon resistance")) {
                tell_object(attackers[i], "%^BOLD%^" + caster->QCN + " hits you with an ineffective barrage of attacks.%^RESET%^");
                continue;
            }
        }
        display_messages(attackers[i], caster);
        caster->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), dam, damtype);
        hit = 1;
    }
    if (!hit) {
        if (in_shapeshift) {
            tell_object(caster, "%^BOLD%^You fail to land a strike on anything, and nearly trip over your own paws in your frenzy!");
            tell_room(environment(caster), "%^BOLD%^" + caster->QCN + " almost trips over " + caster->QP + " own paws in " + caster->QP + " frenzy!", caster);
            if (!FEATS_D->usable_feat(caster, "improved whirl")) {
                caster->set_paralyzed(roll_dice(1, 6), "%^BOLD%^You are getting your paws back under you!");
            }
        }else {
            tell_object(caster, "%^BOLD%^You fail to land a strike on anything, and nearly drop your weapon in the process!");
            tell_room(environment(caster), "%^BOLD%^" + caster->QCN + " almost drops " + caster->QP + " weapon and has to scramble to hold on to it!", caster);
            if (!FEATS_D->usable_feat(caster, "improved whirl")) {
                caster->set_paralyzed(roll_dice(1, 6), "%^BOLD%^You are trying to grip your weapon!");
            }
        }
    }else if (hit > 0) {
        switch (random(5)) {
        case 0:
            tell_object(caster, "%^BOLD%^%^GREEN%^You execute a flurry of attacks upon your foes!");
            tell_room(environment(caster), "%^BOLD%^%^GREEN%^" + caster->QCN + " executes a flurry of attacks on " + caster->QP + " foes!", ({ target, caster }));
            break;

        case 1:
            tell_object(caster, "%^BOLD%^%^BLUE%^You quickly turn and hit your foes with a series of deadly accurate attacks!");
            tell_room(environment(caster), "%^BOLD%^%^BLUE%^" + caster->QCN + " turns quickly and hits " + caster->QP + " foes with a series of deadly accurate attacks!", ({ target, caster }));
            break;

        case 2:
            tell_object(caster, "%^RESET%^%^GREEN%^You pick up speed as you hit your zone and attack your opponents with deadly accuracy!");
            tell_room(environment(caster), "%^RESET%^%^GREEN%^" + caster->QCN + " seems to pick up speed as " + caster->QS + " attacks " + caster->QP + " opponents with deadly accuracy!", ({ target, caster }));
            break;

        case 3:
            if (in_shapeshift) {
                tell_object(caster, "%^BOLD%^%^MAGENTA%^You dance deftly around your opponents as you lash out with your claws in graceful, fluid motions!");
                tell_room(environment(caster), "%^BOLD%^%^MAGENTA%^" + caster->QCN + " dances deftly around " + caster->QP + " opponents as " + caster->QS + " lashes out with " + caster->QP + " claws in graceful, fluid motions that seem to never stop!", ({ target, caster }));
            }else {
                tell_object(caster, "%^BOLD%^%^MAGENTA%^You dance deftly around your opponents as you swing your weapons in graceful, fluid motions!");
                tell_room(environment(caster), "%^BOLD%^%^MAGENTA%^" + caster->QCN + " dances deftly around " + caster->QP + " opponents as " + caster->QS + " swings " + caster->QP + " weapons in graceful, fluid motions that seem to never stop!", ({ target, caster }));
            }
            break;

        case 4:
            if (in_shapeshift) {
                tell_object(caster, "%^RESET%^%^BLUE%^You suddenly turn and aim attacks at your enemies! You become a blur of fangs and claws as you hit one foe after another!");
                tell_room(environment(caster), "%^RESET%^%^BLUE%^" + caster->QCN + " suddenly turns and directs " + caster->QP + " attacks at " + caster->QP + " enemies...  " + caster->QS + " becomes a blur of fangs and claws as " + caster->QS + " hits one after another!", ({ target, caster }));
            }else {
                tell_object(caster, "%^RESET%^%^BLUE%^You suddenly turn and aim attacks at your enemies! Your weapons blur as you hit one after another!");
                tell_room(environment(caster), "%^RESET%^%^BLUE%^" + caster->QCN + " suddenly turns and directs " + caster->QP + " attacks at " + caster->QP + " enemies...  " + caster->QP + " weapons blur as " + caster->QS + " hits one after another!", ({ target, caster }));
            }
            break;

        default:
            break;
        }
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

void display_messages(object targ, object player)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(player)) {
        return;
    }

    switch (random(5)) {
    case 0:
        tell_object(targ, "%^BOLD%^%^GREEN%^" + player->QCN + " executes a flurry of attacks on you!");
        break;

    case 1:
        tell_object(targ, "%^BOLD%^%^BLUE%^" + player->QCN + " turns quickly and hits you with a series of deadly accurate attacks!");
        break;

    case 2:
        tell_object(targ, "%^RESET%^%^GREEN%^" + player->QCN + " seems to pick up speed as " + player->QS + " attacks you witth deadly accuracy!");
        break;

    case 3:
        if (in_shapeshift) {
            tell_object(targ, "%^BOLD%^%^MAGENTA%^" + player->QCN + " dances deftly around you as " + player->QS + " swings " + player->query_possessive() + " weapons in graceful, fluid motions that seem to never cease coming!");
        }else {
            tell_object(targ, "%^BOLD%^%^MAGENTA%^" + player->QCN + " dances deftly around you as " + player->QS + " swings " + player->query_possessive() + " weapons in graceful, fluid motions that seem to never cease coming!");
        }
        break;

    case 4:
        if (in_shapeshift) {
            tell_object(targ, "%^RESET%^%^BLUE%^" + player->QCN + " suddenly turns and directs " + player->QP + " attacks at you...  " + player->QP + " becomes a blur of fangs and claws as " + caster->QS + " hits you!");
        }else {
            tell_object(targ, "%^RESET%^%^BLUE%^" + player->QCN + " suddenly turns and directs " + player->QP + " attacks at you...  " + player->QP + " weapons blur as they hit you!");
        }
        break;

    default:
        break;
    }
}
