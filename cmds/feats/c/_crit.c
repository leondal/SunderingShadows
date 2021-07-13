#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Assassin");
    feat_name("crit");
    feat_syntax("crit [TARGET]");
    feat_prereq("Assassin L1");
    feat_classes("base_class");
    feat_desc("You perform a devastating attack that has a chance to kill your enemy instantly. The save throw gets a bonus from your intelligence score. If your target succeeds the save, either by being warded against death or by being sturdy, they will still suffer greatly.

If used without an argument this feat will pick up a random attacker.");
    set_save("fortitude");
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((int)ob->query_class_level("assassin") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_crit(string str)
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
    mapping tempmap;
    int x;
    int damage, timerz, i, bonusdc;
    object *keyz, qob;
    ::execute_feat();

    tempmap = caster->query_property("using crit");
    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to crit.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
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
        tell_object(caster, "There are better ways to kill yourself!");
        dest_effect();
        return;
    }
    if (!objectp(target)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }
    if (!present(target, place)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (FEATS_D->usable_feat(target, "undead graft")) {
        tell_object(TP, "%^BOLD%^%^WHITE%^" + target->QCN + " glares at you as you were about to phase behind " + target->QO + ".");
        return;
    }


    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }

    caster->set_property("using instant feat",1);


    tell_object(caster, "%^BOLD%^%^WHITE%^You study the place and your target, preparing yourself for a jump.%^RESET%^");
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
        continue;
    }
    timerz = time() + 90;
    delay_subject_msg(target,90,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^crit%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target : timerz ]);
    caster->remove_property("using crit");
    caster->set_property("using crit",tempmap);

    tell_object(caster, "%^RESET%^You find vulnerable spot to attack "+target->QCN+" at.%^RESET%^");

    bonusdc = BONUS_D->query_stat_bonus(caster, "intelligence");

    spell_kill(target, caster);
    if (target->query_property("no death") ||
        target->is_undead() ||
        do_save(target, bonusdc)) {
        int todamage;
        tell_object(target, "%^BOLD%^%^WHITE%^The immense pain spreads from your back!!%^RESET%^");
        tell_room(place, "%^BOLD%^%^WHITE%^You almost didn't see a shadow behind " + target->QCN + "'s back!", ({ target, caster }));
        tell_object(caster, "%^BOLD%^%^WHITE%^You phase quickly behind " + target->QCN + ", but " + target->QS + " withstands your assault.");
        if (target->query_max_hp() < caster->query_max_hp()) {
            todamage = roll_dice(flevel, 10);
        } else{
            todamage = roll_dice(flevel + BONUS_D->query_stat_bonus(caster, "intelligence"), 10);
        }
        target->cause_typed_damage(target, target->return_target_limb(), todamage, "untyped");
    } else {
        tell_object(target, "%^BOLD%^%^WHITE%^Wait, what?! How did it happen?!%^RESET%^");
        tell_room(place, "%^BOLD%^%^WHITE%^You almost didn't see a shadow behind " + target->QCN + "'s back!", ({ target, caster }));
        tell_object(caster, "%^BOLD%^%^WHITE%^You phase quickly behind " + target->QCN + " and put an end to them with a swift motion.");
        target->cause_typed_damage(target, target->return_target_limb(), target->query_max_hp() * 2, "untyped");
    }
    spell_kill(target,caster);
    return;
}

void execute_attack()
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    ::execute_attack();

    caster->remove_property("using instant feat");
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
