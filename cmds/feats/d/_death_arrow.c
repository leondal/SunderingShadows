#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("ArcaneArcher");
    feat_name("death arrow");
    feat_syntax("death_arrow [TARGET]");
    feat_prereq("Arcane archer L7");
    feat_desc("The archer imbues one missile with power of negative energy, and shoots it. Upon release, such projectile can kill the target instantly, or cause severe damage if the target is warded against death effects. Such missile will never miss its target.

If used without an argument this feat will pick up a random attacker.");
    set_save("fort");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("arcane_archer") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_death_arrow(string str)
{
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int check_can_use()
{
    object *weapons;
    int x;
    if(!objectp(caster)) return 0;
    weapons = caster->query_wielded();
    if(!sizeof(weapons))
        return 0;
    if(!weapons[0]->is_lrweapon()) {
        tell_object(caster,"%^YELLOW%^You can't imbue projectile with death power without ranged weapon!%^RESET%^");
        dest_effect();
        return;
    }
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    object *weapons;
    int x;
    ::execute_feat();
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
    tempmap = caster->query_property("using death arrow");
    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to affect.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (!present(target, place)) {
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
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);

    tell_object(caster, "%^RESET%^%^BLUE%^You whisper few syllables in tongues of unlife and imbue arrow with fell power!%^RESET%^");
    tell_room(place, "%^RESET%^%^BLUE%^" + caster->QCN + " whispers a few fell syllables over " + caster->QP + "!%^RESET%^");
    return;
}

void execute_attack()
{
    int damage, timerz, i;
    int bonusdc;
    object* keyz, shape, * weapons, myweapon, qob;
    mapping tempmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if (!objectp(target)) {
        dest_effect();
        return;
    }
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

    tempmap = caster->query_property("using death arrow");
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
    timerz = time() + 120;
    delay_subject_msg(target, 120, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^death arrowed%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target:timerz ]);
    caster->remove_property("using death arrow");
    caster->set_property("using death arrow", tempmap);

    weapons = caster->query_wielded();
    if (sizeof(weapons)) {
        myweapon = weapons[0];
    }

    tell_object(caster, "%^BOLD%^%^BLUE%^Your deadly missile pierces into " + target->QCN + ", releasing %^BOLD%^%^BLACK%^fell powers%^BLUE%^!%^RESET%^");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + "'s %^BLACK%^fell missile%^BLUE%^ pierces into " + target->QCN + "!%^RESET%^", caster);

    bonusdc = BONUS_D->query_stat_bonus(caster, "dexterity");
    if ((string)target->query_property("no death") || do_save(target, bonusdc)) {
        tell_object(target, "%^BOLD%^The struggle for your soul is won, yet at a %^BOLD%^%^BLUE%^price%^WHITE%^.");
        tell_room(place, "%^BOLD%^The soul survives, yet the coil %^BLACK%^suffers%^WHITE%^!", target);
        target->cause_typed_damage(target, target->return_target_limb(), roll_dice(clevel, 8), myweapon->query_damage_type());
    } else {
        tell_room(place, "%^BOLD%^%^WHITE%^The soul is pushed beyond %^MAGENTA%^the veil%^WHITE%^ from its coil!");
        tell_room(place, "%^BOLD%^%^WHITE%^The lifeless husk of " + target->QCN + " drops to the ground!", target);
        tell_object(target, "%^BOLD%^%^MAGENTA%^Your soul is ripped from you body!\n");
        target->cause_typed_damage(target, target->return_target_limb(), target->query_max_hp() * 2, myweapon->query_damage_type());
    }

    spell_kill(target, caster);

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
