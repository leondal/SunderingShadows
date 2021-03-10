#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("KiOffense");
    feat_name("stunning strike");
    feat_prereq("Monk L5");
    feat_syntax("stunning_strike [TARGET]");
    feat_desc("A monk that is unarmored and unarmed, or wielding small weapons, may attempt a stunning strike on a target. In order for the attempt to be successful the monk must have at least 1 available Ki, must land a touch attack on the target, and the target must fail a fortitude save with a DC of the Monk's level.

If used without an argument this feat will pick up a random attacker.");
    set_save("fort");
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("monk") < 5 || (int)ob->query_alignment() > 3)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_stunning_strike(string str)
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
    for(x = 0;x < sizeof(weapons);x++)
    {
        if(!objectp(weapons[x])) continue;
        if((int)weapons[x]->query_size() > 1)
        {
            tell_object(caster, "%^BOLD%^%^GREEN%^Your "+weapons[x]->query_short()+
            " interferes with your stunning strike attempt!%^RESET%^");
            return 0;
        }
        continue;
    }
    if(!caster->is_ok_armour("barb"))
    {
        tell_object(caster, "%^BOLD%^%^GREEN%^Your armor interferes "+
        "with your stunning strike attempt!%^RESET%^");
        return 0;
    }
    if(caster->query_in_vehicle())
    {
        tell_object(caster,"You cannot use stunning strike while mounted!");
        return 0;
    }
    if(!(int)USER_D->can_spend_ki(caster, 1))
    {
        tell_object(caster, "%^CYAN%^You lack the needed ki to attempt "+
        "a stunning strike!%^RESET%^");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    object *weapons;
    int x;
    ::execute_feat();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if(target == caster)
    {
        tell_object(caster,"You cannot use stunning strike on yourself!");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using stunning strike");

    if(!objectp(target))
    {
        object * attackers = caster->query_attackers();
        if(mapp(tempmap))
        {
            attackers = filter_array(attackers,(:$2[$1] < time():),tempmap);
        }
        if(!sizeof(attackers))
        {
            tell_object(caster,"%^BOLD%^Nobody to strike.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }

    if (!objectp(target)) {
        tell_object(caster,"%^BOLD%^Nobody to strike.%^RESET%^");
        dest_effect();
        return;
    }

    if(!present(target, place))
    {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if(mapp(tempmap))
    {
        if(tempmap[target] > time())
        {
            tell_object(caster,"That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    if(!check_can_use())
    {
        dest_effect();
        return;
    }
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);

    tell_object(caster, "%^BOLD%^%^CYAN%^You focus intently on manipulating the ki in "+
    target->QCN+"%^BOLD%^%^CYAN%^'s body!%^RESET%^");

    tell_object(target, caster->QCN+"%^BOLD%^%^CYAN%^ begins focusing intently on "+
    "you!%^RESET%^");

    if(objectp(place))
    {
        tell_room(place, caster->QCN+"%^BOLD%^%^CYAN%^ begins focusing intently "+
        "on "+target->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", ({caster, target}));
    }
    return;
}

void execute_attack()
{
    int damage, timerz, i, DC;
    object *keyz, shape, *weapons, myweapon;
    mapping tempmap;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_unconscious())
    {
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target has eluded you!");
        dest_effect();
        return;
    }
    if(!check_can_use())
    {
        dest_effect();
        return;
    }

    if(!caster->spend_ki(2))
    {
        tell_object(caster, "%^CYAN%^You lack the needed ki to attempt "+
        "a stunning strike!%^RESET%^");
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using stunning strike"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    keyz = keys(tempmap);
    for(i=0;i<sizeof(keyz);i++)
    {
        if(!objectp(keyz[i])) map_delete(tempmap, keyz[i]);
        continue;
    }
    timerz = time() + 60;
    tempmap += ([ target : timerz ]);
    delay_subject_msg(target,60,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^sunning striken%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using stunning strike");
    caster->set_property("using stunning strike",tempmap);

    weapons = caster->query_wielded();
    if(sizeof(weapons)) myweapon = weapons[0];

    if(!thaco(target, 0, 1))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^You miss your stunning strike on "+target->QCN+
        "%^BOLD%^%^CYAN%^!%^RESET%^");
        tell_object(target, caster->QCN+"%^BOLD%^%^CYAN%^ launches a focused strike at you, "+
        "but you manage to avoid it just in time!%^RESET%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches a focused "+
            "strike at "+target->QCN+"%^BOLD%^%^CYAN%^ but "+target->QS+" manages to avoid it, "+
            "just in time!%^RESET%^", ({caster, target}));
        }
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^CYAN%^Your stunning strike slams into "+target->QCN+
    "!%^RESET%^");

    tell_object(target, caster->QCN+"%^BOLD%^%^CYAN%^ launches a focused strike, "+
    "connecting squarely with you!%^RESET%^");

    if(objectp(environment(caster)))
    {
        tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches a focused strike "+
        "on "+target->QCN+"%^BOLD%^%^CYAN%^ connecting squarely with "+target->QO+
        "!%^RESET%^", ({caster, target}));
    }
    DC = (int)caster->query_class_level("monk");
    DC += (int)"/daemon/bonus_d.c"->query_stat_bonus(caster, "wisdom");
    DC += 10;
    if(do_save(target, DC) || target->query_property("no paralyze") || target->query_property("no death"))
    {
        tell_object(target, "%^BOLD%^%^WHITE%^You feel your body shudder momentarily but "+
        "quickly shake off the impact of the strike!%^RESET%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), target->QCN+"%^BOLD%^%^WHITE%^ seems unaffected "+
            "by the impact of the strike!%^RESET%^", target);
        }
        dest_effect();
        return;
    }
    tell_object(target, "%^BOLD%^%^RED%^Your entire body shudders violently for a brief "+
    "instant and suddenly you are completely unable to move!%^RESET%^");

    target->set_paralyzed((ROUND_LENGTH * 2), "%^BOLD%^%^RED%^The impact of "+
    "the strike has left you unable to move!%^RESET%^");

    if(objectp(environment(caster)))
    {
        tell_room(environment(caster), target->QCN+"%^BOLD%^%^WHITE%^'s "+
        "entire body shudders violently for a brief instant and suddenly "+
        target->QS+" seems frozen in place!%^RESET%^");
    }
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
