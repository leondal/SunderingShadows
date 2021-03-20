//      Wall of fire

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, hpcount;
string tempstr;
object endplace, outside, wall, wall2;

string *dir_listing(string tempfil);

void create()
{
    ::create();
    set_spell_name("wall of thorns");
    set_spell_level(([ "druid" : 5, "oracle":5, "cleric" : 5 ]));
    set_domains("plant");
    set_mystery("nature");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS wall of thorns [on <exit>] | cast <classname> wall of thorns");

    set_description("The spell wall of thorns will create a massive wall of tangled thorn bushes that will "
        "damage anyone going through an exit, or optionally, damage anyone who attacks the caster.  If "
        "no arguments are given to the spell, the wall of thorns will surround the caster and damage anyone "
        "who attacks him or her.  The caster may type <remove wall> to end the wall of thorns spell early.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^GREEN%^"+caster->QCN+" flings a handfull of seeds into the air and where they land "
        "a massive wall of twisted, razor-sharp thorns sprouts up!";
}


void spell_effect(int prof)
{
    string *outs, *ins, *limbs, arg;
    object *exits, *inexits, *burned;
    int i, j;
    ::spell_effect();
    //caster=CASTER;
    hpcount=caster->query_hp();
    //place=PLACE;
    if(arg && arg != "" && arg != " ") { arg=lower_case(arg); }
    if (member_array(arg,place->query_exits()) < 0)
    {
        tell_object(caster,"%^GREEN%^A thick wall of tangled thorns sprouts up around you!");
        tell_room(place,"%^GREEN%^A thick wall of tangled thorns sprouts up around "+caster->QCN+"!",caster);
        wall=new("/d/magic/obj/thornwall.c");
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster);
        return;
    }
    wall=new("/d/magic/obj/thornwall.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg);
    if (objectp(wall))
        wall->move(place);
    else
        return;

    tell_room(place,"%^GREEN%^A wall of tangled thorns sprouts up, blocking the "+arg+"!");

    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();

    for (i=0;i<sizeof(ins);i++)
    {
        if ( base_name(place) == (string)outside->query_exit(ins[i]) || base_name(place)+".c" == (string)outside->query_exit(ins[i]) || base_name(place) == (string)outside->query_exit(ins[i])+".c")
        {
            wall2=new("/d/magic/obj/thornwall.c");
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i]);
            wall2->move(outside);

            tell_room(outside,"%^GREEN%^A wall of tangled thorns sprouts up, blocking the "+ins[i]+"!  The tangled mass grows so fast that you are caught up in it!");

            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++)
            {
                if ( living(burned[j]) )
                {
                    if ( burned[j]->query_property("strength") && strsrch(burned[j]->query_property("strength"), "thorns") != -1 )
                    {
                        tell_object(burned[j],"%^GREEN%^The thorns part around you, leaving you unharmed!");
                        tell_room(outside,"%^GREEN%^The thorns part around "+burned[j]->QCN+" leaving "+burned[j]->QO+" unharmed.",burned[j]);
                    }
                    else
                    {
                        tell_object(burned[j],"%^GREEN%^The thorns tear into your body!");
                        tell_room(outside,"%^GREEN%^The thorns tear into "+burned[j]->QCN+"'s body!",burned[j]);
                        limbs = burned[j]->query_limbs();
                        if ( !burned[j]->query_property("undead") )
                            damage_targ(burned[j],limbs[random(sizeof(limbs))],(4+random(13)),"piercing" );
                        else
                            damage_targ(burned[j],limbs[random(sizeof(limbs))],(2+random(7)),"piercing" );
                    }
                }
            }
            break;
        }
    }
    call_out("concentration",4);
    return;
}


void concentration() {
    int flag = 0;
    if ( caster->query_paralyzed() || !objectp(wall) || !objectp(wall2))
        flag = 1;
    if ((int)caster->query_hp() != hpcount)
    {
        if ((int)caster->query_hp() < hpcount - 30 )
        {
            tell_room(environment(caster),"%^ORANGE%^"+caster->QCN+" looks as though "+caster->QS+" just lost "+caster->QP+" concentration!",caster);
            tell_object(caster,"%^YELLOW%^You lose your concentration on maintaining the wall of thorns!");
            flag = 1;
        }
        else
            hpcount = caster->query_hp();
    }
    if (flag)
        call_out("dest_effect",clevel*3);
    else
        call_out("concentration",4);
    return;
}


void dest_effect()
{
    if (objectp(wall))
        wall->remove_wall();
    if (objectp(wall2))
        wall2->remove_wall();

    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
