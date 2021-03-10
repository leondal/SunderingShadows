#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int FEATTIMER = 25;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("countersong");
    feat_syntax("countersong [TARGET]");
    feat_prereq("Bard L1");
    feat_classes("bard");
    feat_desc("With this feat you can try to countersong any inspiration or performance another bard is doing. In the case of inspiration the target can be any one affected by the song.");
    set_target_required(0);
    allow_blind(1);
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
    if (ob->query_class_level("bard") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_countersong(string args)
{
    object feat;
    if (!objectp(TP)) {
        dest_effect();
        return 0;
    }

    feat = new(base_name(TO));
    feat->setup_feat(TP, args);
    return 1;
}

void execute_feat()
{
    int rtime;

    ::execute_feat();

    if(!objectp(target))
    {
        object * attackers = caster->query_attackers();
        if(sizeof(attackers))
        {
            attackers = filter_array(attackers,(:objectp($1):));
            attackers = filter_array(attackers,(:$1->query_property("countersong at")+FEATTIMER < time():));
            attackers = filter_array(attackers, (:objectp($1->query_property("inspiration")):));
            attackers = filter_array(attackers, (:($1->query_property("inspiration"))->query_caster() != caster:));

            if(!sizeof(attackers))
            {
                tell_object(caster,"%^BOLD%^Nobody to countersong.%^RESET%^");
                dest_effect();
                return;
            }
            target = attackers[random(sizeof(attackers))];
        }
    }

    if(!objectp(target))
    {
        tell_object(caster,"%^RESET%^That is not here!");
        return;
    }

    rtime = (int)target->query_property("countersong at");
    if(rtime + FEATTIMER > time())
    {
        tell_object(caster,"That target is still wary of such an attack!");
        dest_effect();
        return;
    }

    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if (!objectp(target->query_property("inspiration"))) {
        dest_effect();
        return;
    }

    if (!objectp((target->query_property("inspiration"))->query_caster())) {
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^BLACK%^You tr%^RESET%^y %^BOLD%^%^BLACK%^to %^RESET%^i%^BOLD%^%^BLACK%^nvoke %^RESET%^u%^BOLD%^%^BLACK%^t%^WHITE%^t%^RESET%^e%^BOLD%^%^BLACK%^r d%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^at " +target->QCN+"'s songs with your m%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^lodies.%^RESET%^");
    tell_room(ENV(caster), "%^BOLD%^%^BLACK%^" +caster->QCN+"pl%^RESET%^a%^BOLD%^%^BLACK%^y%^WHITE%^s %^BLACK%^in h%^WHITE%^o%^BLACK%^r%^WHITE%^r%^BLACK%^ible d%^RESET%^%^ORANGE%^i%^GREEN%^s%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^ar%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^o%^WHITE%^n%^BOLD%^%^BLACK%^y to " +((target->query_property("inspiration"))->query_caster())->QCN+"'s m%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^o%^BOLD%^d%^BLACK%^ies.%^RESET%^", caster);

    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
}

void execute_attack()
{
    ::execute_attack();

    caster->remove_property("using instant feat");


    delay_subject_msg(target,FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^countersong%^WHITE%^ at again.%^RESET%^");

    {
        object inspiration;

        inspiration = target->query_property("inspiration");

        if (!objectp(inspiration)) {
            tell_object(caster,"%^BOLD%^%^WHITE%^There is no melody to disrupt!");
            return;
        }

        inspiration->countersong(flevel);

        target->remove_property("countersong at");
        target->set_property("countersong at",time());
    }

    caster->use_stamina(roll_dice(1,6));

    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
