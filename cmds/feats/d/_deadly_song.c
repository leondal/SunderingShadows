#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("deadly song");
    feat_syntax("deadly_song [TARGET]");
    feat_prereq("Bard L20");
    feat_desc("At 20th level, a bard can use her performance to cause one enemy to die from joy or sorrow.

If used without an argument this feat will pick up a random attacker.");
    set_save("will");
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
    if ((int)ob->query_class_level("bard") < 20) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_deadly_song(string str)
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
    object* weapons;
    int x;
    ::execute_feat();
    tempmap = caster->query_property("using deadly song");
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
    if (target == caster) {
        tell_object(caster, "There are better ways to kill yourself.");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
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

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    caster->set_property("using instant feat", 1);

    tell_room(ENV(target), "%^BOLD%^%^BLUE%^" + caster->QCN + " invokes a s%^CYAN%^i%^WHITE%^nister%^BLUE%^ tune.", caster);
    tell_room(ENV(target),"%^BLUE%^D%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^df%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^l melody %^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^e%^BOLD%^a%^BLACK%^v%^RESET%^%^BLUE%^es the %^BOLD%^%^BLACK%^death %^RESET%^%^BLUE%^itself around " +target->QCN+".%^WHITE%^", caster);
    tell_object(target,"%^BOLD%^%^BLUE%^You feel your soul slipping away!");

    tell_object(caster,"%^BLUE%^You w%^BOLD%^e%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^v%^RESET%^%^BLUE%^e the %^BOLD%^%^BLACK%^death %^RESET%^%^BLUE%^itself around " +target->QCN+" with your m%^BOLD%^u%^RESET%^s%^BLUE%^ic.%^WHITE%^");

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

    tempmap = caster->query_property("using deadly song");
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
    timerz = time() + 300;
    delay_subject_msg(target, 300, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^deadly sang%^WHITE%^ at again.%^RESET%^");
    tempmap += ([ target:timerz ]);
    caster->remove_property("using deadly song");
    caster->set_property("using deadly song", tempmap);

    tell_object(caster, "%^BLUE%^The deadly melody coils and collapses at " + target->QCN + "!");
    tell_room(place, "%^BLUE%^The deadly melody coils and collapses at " + target->QCN + "!", caster);

    bonusdc = clevel;
    bonusdc += BONUS_D->query_stat_bonus(caster, "charisma");
    spell_kill(target, caster);
    if ((string)target->query_property("no death") || do_save(target, -bonusdc)) {
        tell_room(place, "%^BOLD%^%^BLUE%^" + target->QCN + " is utterly unaffected by the melody!", target);
        tell_object(target, "%^BOLD%^%^BLUE%^You are utterly unaffected by the melody!");
    } else {
        tell_room(place, "%^BOLD%^%^MAGENTA%^The soul is pushed beyond %^MAGENTA%^the veil%^MAGENTA%^ from its coil!");
        tell_room(place, "%^BOLD%^%^MAGENTA%^The lifeless husk of " + target->QCN + " drops to the ground!", target);
        tell_object(target, "%^BOLD%^%^MAGENTA%^Your soul is ripped from you body! Bye bye!\n");
        target->cause_typed_damage(target, target->return_target_limb(), target->query_max_hp() * 2, "untyped");
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
