#include <std.h>

void raise_ghosts(int clevel, int limit, object caster, object controller)
{
    object *temp, *targs, undead, target;
    int i, j, nummon, lvl, raised;
    string undeadtype, myrace;

    if(objectp(caster))
        nummon = (int)caster->query_property("raised");
    else
        nummon = 0;
    if (nummon >= 10)
        return 0;

    temp=({});

    if(!objectp(caster))
        return;

    if(!objectp(environment(caster)))
        return;
    targs=all_inventory(environment(caster));

    for(i=0;i<sizeof(targs);i++)
    {
        if (targs[i]->is_corpse())
            temp += ({ targs[i]});
    }

    targs=temp;

    if(!sizeof(targs))
        return;

    i = 0;
    foreach(target in targs)
    {
        if (i>limit)
            break;
        if(nummon>clevel)
            break;
        if(!objectp(target))
            continue;
        undead=new("/d/magic/obj/undead");

        lvl=target->make_new_body(undead);
        switch(random(5))
        {
        case 0: undeadtype = "ghost";   break;
        case 1: undeadtype = "spirit";  break;
        case 2: undeadtype = "wraith";  break;
        case 3: undeadtype = "shadow";  break;
        case 4: undeadtype = "spectre"; break;
        }
        myrace = (string)undead->query_race();
        undead->set_name(undeadtype+" "+myrace);
        undead->set_short("%^RESET%^%^BLUE%^a %^WHITE%^"+myrace+" %^BLUE%^"+undeadtype+"%^RESET%^");
        undead->set_id(({"creature","undead creature","undead",undeadtype,myrace+" "+undeadtype, myrace, undeadtype+" of "+myrace,"summoned monster"}));

        raised = 1;

        temp=({});
        temp=all_inventory(target);

        if(sizeof(temp))
            temp->move(undead);
        target->remove();

        lvl=clevel;
        nummon += lvl;
        undead->set_property("raised",1);
        undead->set_property("raised " + undead_to_raise(), 1);
        undead->set_property("minion",caster);
        undead->move(environment(caster));
        undead->serve(caster);
        undead->set_guild_level("fighter",clevel);
        undead->set_skill("athletics",clevel);
        undead->set_skill("perception",clevel);
        undead->set_level(clevel);
        undead->set_max_hp(clevel*12+50); //d12
        undead->set_hp(undead->query_max_hp());
        undead->set_overall_ac(5-clevel);
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("keep exp",1);
        undead->set_exp((int)undead->query_hd()*50);
        caster->set_property("raised", lvl/6);
        undead->set_property("raised " + undead_to_raise(), lvl / 6);
        controller->add_monster(undead);

        i++;
    }

    if(raised)
        tell_room(environment(caster),"%^BOLD%^%^BLUE%^The chilling energy ripples through the nearby corpses, drawing their spirits to "+caster->QCN+"'s defense!%^RESET%^",caster);
}

string undead_to_raise() {
    return "animus";
}