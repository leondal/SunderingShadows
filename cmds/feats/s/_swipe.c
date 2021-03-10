#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Duelist");
    feat_name("swipe");
    feat_prereq("Opportunity strikes");
    feat_syntax("swipe [TARGET]");
    feat_desc("With this characters can perform a tactical swipe, aming their weapon at an opponent with precision and strength put into strike.

If used without an argument this feat will pick up a random attacker.
");
    set_save("reflex");
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
    if (!FEATS_D->has_feat(ob, "opportunity strikes")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_swipe(string str)
{
    object feat;
    object wielded;

    if (!objectp(TP)) {
        return 0;
    }
    if ((int)TP->is_wearing_type("shield")) {
        tell_object(TP, "%^RESET%^%^BOLD%^You can't be wearing a shield.%^RESET%^");
        return 1;
    }
    wielded = (object*)TP->query_wielded();
    if (!sizeof(wielded) == 1) {
        tell_object(TP, "%^RESET%^%^BOLD%^You must be wielding a single one-handed weapon.%^RESET%^");
        return 1;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

int check_can_use()
{
    object* weapons;
    int x;
    if (!objectp(caster)) {
        return 0;
    }
    weapons = caster->query_wielded();
    if (sizeof(weapons) != 1 ||
        caster->is_wearing_type("shield")) {
        tell_object(caster, "%^BOLD%^%^GREEN%^You must be using one single-handed weapon without shield!");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    object* weapons;
    int x;
    ::execute_feat();
    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using swipe");

    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to swipe.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_object(caster, "You cannot use swipe on yourself!");
        dest_effect();
        return;
    }

    if (!objectp(target)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (!present(target, ENV(caster))) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    if (!check_can_use()) {
        dest_effect();
        return;
    }
    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);

    tell_object(caster, "%^BOLD%^%^BLUE%^You position yourself to strike at " + target->QCN + "%^BOLD%^%^BLUE%^ with precision!%^RESET%^");
    tell_object(target, caster->QCN + "%^BOLD%^%^BLUE%^ positions to strike you with precision!%^RESET%^");

    return;
}

void execute_attack()
{
    int damage, timerz, i, DC;
    object* keyz, shape, * weapons, myweapon;
    mapping tempmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "Your target has eluded you!");
        dest_effect();
        return;
    }
    if (!check_can_use()) {
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using swipe");
    if (!mapp(tempmap)) {
        tempmap = ([]);
    }
    if (tempmap[target]) {
        map_delete(tempmap, target);
    }
    keyz = keys(tempmap);
    for (i = 0; i < sizeof(keyz); i++) {
        if (!objectp(keyz[i])) {
            map_delete(tempmap, keyz[i]);
        }
    }

    timerz = time() + 25;
    delay_subject_msg(target, 25, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^swiped%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target:timerz ]);
    caster->remove_property("using swipe");
    caster->set_property("using swipe", tempmap);

    weapons = caster->query_wielded();
    if (sizeof(weapons)) {
        myweapon = weapons[0];
    }

    if (!thaco(target, 0, 1)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You miss your strike on " + target->QCN +
                    "%^BOLD%^%^WHITE%^!%^RESET%^");
        tell_object(target, caster->QCN + "%^BOLD%^%^WHITE%^ launches a precise strike at you, " +
                    "but you manage to avoid it just in time!%^RESET%^");
        if (objectp(environment(caster))) {
            tell_room(environment(caster), caster->QCN + "%^BOLD%^%^WHITE%^ launches a precise " + "strike at " + target->QCN + "%^BOLD%^%^WHITE%^ but " + target->QS + " manages to avoid it, " + "just in time!%^RESET%^", ({ caster, target }));
        }
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^WHITE%^Your precise strike slams into " + target->QCN + "!%^RESET%^");

    tell_object(target, caster->QCN + "%^BOLD%^%^CYAN%^ manages to find weakness in your defenses and slams into you!%^RESET%^");

    if (objectp(environment(caster))) {
        tell_room(environment(caster), caster->QCN + "%^BOLD%^%^WHITE%^ manages to find a weakness in " + target->QCN + "%^BOLD%^%^WHITE%^ defenses and strikes with precision!%^RESET%^", ({ caster, target }));
    }
    damage = roll_dice(clevel, 10);
    damage += (int)caster->query_damage_bonus();
    damage += weapons[0]->query_damage();
    damage += "/daemon/bonus_d"->damage_bonus(max(({ caster->query_stats("dexterity"),
                        caster->query_stats("strength") })));

    if (target->query_property("weapon resistance")) {
        if ((int)weapons[0]->query_property("enchantment") < (int)target->query_property("weapon resistance")) {
            damage = 0;
        }
    }
    tell_object(target, "%^BOLD%^%^RED%^You feel immense pain!%^RESET%^");
    target->set_paralyzed(roll_dice(2, 6), "%^BOLD%^%^RED%^You feel immense pain!%^RESET%^");

    caster->cause_typed_damage(target, target->return_target_limb(), damage, weapons[0]->query_damage_type());

    if (target->is_npc() || userp(target)) {
        if (target->query_deaths_door() && (userp(caster) || caster->query_property("knock unconscious"))) {
            target->cease_all_attacks();
            target->remove_attacker(caster);
            caster->remove_attacker(target);
            tell_object(caster, "%^BOLD%^%^RED%^" + target->QCN + " falls unconscious " +
                        "from the force of your swipe!");
        }
    }
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
