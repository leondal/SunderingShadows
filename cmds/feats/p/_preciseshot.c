#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define FEATTIMER 35

void create()
{
    ::create();
    feat_type("instant");
    feat_category("RangedCombat");
    feat_name("preciseshot");
    feat_prereq("Deadeye");
    feat_syntax("preciseshot TARGET");
    feat_desc("The character can attempt to fire a shot at a foe with as much of their accuracy behind it as they can, in the hope of dealing heavier damage and making them stumble. Holding a weapon in one position requires some amount of dexterity, as well as proper aiming. Weapon might slip and thus lead to misfire!

If used without an argument this feat will pick up a random attacker.");
    set_save("reflex");
    set_required_for(({ "shot on the run" }));
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "deadeye")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_preciseshot(string str)
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
    object* weapons, ammo;
    ::execute_feat();
    tempmap = caster->query_property("using preciseshot");

    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }

        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody can be affected.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", TP);
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_object(caster, "Don't shoot yourself!");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if (!sizeof(weapons)) {
        tell_object(caster, "%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
        dest_effect();
        return;
    }
    if (!weapons[0]->is_lrweapon() && !weapons[1]->is_lrweapon()) {
        tell_object(caster, "%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
        dest_effect();
        return;
    }
    if (caster->query_property("shapeshifted")) {
        tell_object(caster, "%^YELLOW%^You can't do that while shapeshifted!\n");
        dest_effect();
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (weapons[0]->is_lrweapon()) {
        ammo = present(weapons[0]->query_ammo(), caster);
    }
    if (sizeof(weapons) > 1 && weapons[1]->is_lrweapon()) {
        ammo = present(weapons[1]->query_ammo(), caster);
    }
    if (!objectp(ammo) || !ammo->use_shots()) {
        tell_object(caster, "%^YELLOW%^You haven't got any ammo!\n");
        dest_effect();
        return;
    }
    if (!objectp(target)) {
        tell_object(caster, "Nobody to shoot at.");
        dest_effect();
        return;
    }

    caster->use_stamina(roll_dice(1, 6));
    tell_object(caster, "%^BOLD%^%^BLUE%^You drop to one knee and level your weapon, putting all your strength into a shot fired at " + target->QCN + "!");
    tell_object(target, "%^BOLD%^%^BLUE%^" + caster->QCN + " drops to one knee and levels " + caster->QP + " weapon, putting all " + caster->QP + " strength into a shot fired at you!");
    tell_room(environment(caster), "%^BOLD%^%^BLUE%^" + caster->QCN + " drops to one knee and levels " + caster->QP + " weapon, putting all " + caster->QP + " strength into a shot fired at " + target->QCN + "!", ({ caster, target }));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;
}

void execute_attack()
{
    int damage, timerz, i, res;
    object* weapons, * keyz, weapon;
    mapping tempmap, newmap;

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
    if (!sizeof(caster->query_wielded())) {
        tell_object(caster, "You lower your weapon too soon, and the shot skitters uselessly along the ground!");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if (!weapons[0]->is_lrweapon() && !weapons[1]->is_lrweapon()) {
        tell_object(caster, "%^YELLOW%^You lower your weapon too soon, and the shot skitters uselessly along the ground!\n");
        dest_effect();
        return;
    }
    /*if (sizeof(weapons) > 1 && weapons[0] != weapons[1]) {
        tell_object(caster, "%^YELLOW%^You lower your weapon too soon, and the shot skitters uselessly along the ground!\n");
        dest_effect();
        return;
       }*/
    if (caster->query_property("shapeshifted")) {
        tell_object(caster, "%^YELLOW%^You lower your weapon too soon, and the shot skitters uselessly along the ground!\n");
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using preciseshot"); // adding per-target tracking. -N, 9/10.
    if (!mapp(tempmap)) {
        tempmap = ([]);
    }
    if (tempmap[target]) {
        map_delete(tempmap, target);
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
    delay_subject_msg(target, FEATTIMER, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^preciseshot%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using preciseshot");
    caster->set_property("using preciseshot", newmap);

    if (!(res = thaco(target))) {
        tell_object(caster, "%^BOLD%^%^YELLOW%^You overextend your shot and fumble with your weapon!");
        tell_room(environment(caster), "%^BOLD%^%^YELLOW%^" + caster->QCN + " overextends " + caster->QP + " shot and fumbles with " + caster->QP + " weapon!", caster);
        caster->set_tripped(4, "You're still trying to recover from your fumbled shot!", 4);
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

    if(weapons[0]->is_lrweapon())
    {
      weapon = weapons[0];
    }
    else{
      weapon = weapons[1];
    }

    damage = roll_dice(clevel, 8); // up to d8 on a trial basis

    damage += weapon->query_damage();

    damage += "/daemon/bonus_d"->damage_bonus(caster->query_stats("dexterity"));
    damage += (int)caster->query_damage_bonus();
    if (target->query_property("weapon resistance")) {
        if ((int)weapon->query_property("enchantment") < (int)target->query_property("weapon resistance")) {
            damage = 0;
        }
    }

    tell_object(caster, "%^BOLD%^%^YELLOW%^Your shot flies true and thuds deep into " + target->QCN + ", the sheer force of it causing " + target->QO + " to stumble!");
    tell_room(environment(caster), "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s shot flies true and thuds deep into " + target->QCN + ", the sheer force of it causing " + target->QO + " to stumble!", ({ caster, target }));
    tell_object(target, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s shot flies true and thuds deep into you, the sheer force and pain of it causing you to stumble momentarily!");

    caster->cause_typed_damage(target, target->return_target_limb(), damage, weapon->query_damage_type());

    if (!objectp(target)) {
        dest_effect();
        return;
    }
    target->set_paralyzed(roll_dice(2, 6), "You're still recovering from such a painful shot.");

    if (target->is_npc() || userp(target)) {
        if (target->query_deaths_door() && (userp(caster) || caster->query_property("knock unconscious"))) {
            target->cease_all_attacks();
            target->remove_attacker(caster);
            caster->remove_attacker(target);
            tell_object(caster, "%^BOLD%^%^RED%^" + target->QCN + " falls unconscious " +
                        "from the force of your shot!");
            tell_room(environment(caster), "%^BOLD%^%^RED%^" + caster->QCN + "'s shot " +
                      "thuds into " + target->QCN + ", knocking " + target->QO + " completely " +
                      "unconscious due to wounds!", ({ target, caster }));
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + "'s shot thuds " +
                        "into you, with enough force to knock you unconscious.\n");
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
