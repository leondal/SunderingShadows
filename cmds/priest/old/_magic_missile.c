// --==** /cmds/wizard/_magic_missile.c **==--

// Magic Missile

#include <std.h>
#include <spell.h>

inherit SPELL;
void dest_effect();

create()
{
    ::create();
    set_spell_name("magic missile");
    set_spell_level(1);
    set_spell_type("wizard");
    set_spell_sphere("invocation_evocation");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect()
{
    int num, numdarts, damage;
    string hardness;
    object caster, target;
    ::spell_effect();
    caster=CASTER;
    target=TARGET;
    if(interactive(caster))
    {
        tell_object(caster,"You point the palm of your"+
            " hand at "+target->query_short()+"!");
        tell_object(target,""+caster->query_short()+
            " points the palm of "+caster->query_possessive()+
            " hand at you!");
        tell_room(environment(caster),""+
            caster->query_short()+" points the palm of "+
            caster->query_possessive()+" hand at "+
            target->query_short()+"!", ({caster, target}) );
    }
    if(CLEVEL)
        numdarts=to_int((CLEVEL+1)/2);
    else
        numdarts=to_int(((int)caster->query_guild_level("mage")+1)
            /2);
    damage=0;
    for(num=1;num<=numdarts;num++)
    {
        damage += 2+random(4);
    }
    switch(1+to_int(damage/numdarts))
    {
        case 2:
            hardness="sting";
        break;
        case 3:
            hardness="shock";
        break;
        case 4:
            hardness="zap";

        break;
    case 5..6:
            hardness="blast";
    break;
    }
    if(interactive(caster))
    {
        if(numdarts > 1)
        {
            tell_object(caster,""+numdarts+" darts of "+
                "energy shoot from your hand and "+hardness+" "+
                target->query_objective()+"!");
            tell_object(target,""+numdarts+" darts "+
                "of energy shoot from "+caster->query_short()+"'s "+
                "hand and "+hardness+" you!");
            tell_room(environment(caster),""+numdarts+
                " darts of energy shoot from "+caster->query_short()+
                "'s hand and "+hardness+" "+target->query_objective()+
                "!",({caster, target}) );
        }
        else
        {
            tell_object(caster,"A dart of energy shoots "+
                "from your hand and "+hardness+"s "+
            target->query_objective()+"!");
            tell_object(target,"A dart of energy shoots "+
                "from "+caster->query_short()+"'s hand and "+hardness+
                "s you!");
            tell_room(environment(caster),"A dart of "+
                "energy shoots from "+caster->query_short()+"'s "+
                "hand and "+hardness+"s "+target->query_objective()+"!",
                ({caster, target}) );
        }
    }
    else
    {
        if(numdarts > 1)
        {
            tell_object(target,""+numdarts+" darts "+
                "of energy shoot from "+caster->query_short()+" "+
                "and "+hardness+" you!");
            tell_room(environment(caster),""+numdarts+
                " darts of energy shoot from "+caster->query_short()+
                " and "+hardness+" "+target->query_short()+
                "!",({target}) );
        }
        else
        {
            tell_object(target,"A dart of energy shoots "+
                "from "+caster->query_short()+"'s hand and "+hardness+
                "s you!");
            tell_room(environment(caster),"A dart of "+
                "energy shoots from "+caster->query_short()+" "+
                "and "+hardness+"s "+target->query_short()+"!",
                ({target}) );
        }
    }
    caster->kill_ob(target);
    target->add_hp(-damage);
}


void dest_effect()
{
    destruct(TO);
}

int help()
{
    write(
@EndText
Syntax: cast magic missile on <target>

     Magic missile will shoot darts of magical energy from your hand
and they will fly towards your target with the unfailing ability to
hit it.  The damage it causes increases by level.

Material component required:

None

EndText
    );
    return 1;
}
