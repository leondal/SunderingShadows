#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("thunder wave");
    set_spell_level(([ "monk" : 5 ]));
    set_monk_way("way of the elements");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS thunder wave");
    set_description("This spell creates a wave of thunderous force, all creatures around the "+
    "caster must make a fortitude save or be damaged and knocked to the ground. Furthemore, all "+
    "inanimate objects not attached and on the ground may be knocked away.\n\nNOTE: The damage of this "+
    "spell is 1d6 per caster level.%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    //set_target_required(1);
    set_save("fort");
    set_components(([
    ]));
}

string query_cast_string()
{
    return caster->QCN+"%^BOLD%^%^CYAN%^ raises "+caster->QP+
    " hands in the air and begins focusing intently!%^RESET%^";
}

void spell_effect(int prof)
{
    int dam, i;
    object *foes, *obs;
    string *myExits, myExit, myPlace, myFrom, myWhere;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    foes = ({});
    tell_object(caster, "%^BOLD%^%^WHITE%^You focus your inner ki, "+
    "releasing it with a %^BOLD%^%^YELLOW%^THUNDEROUS%^BOLD%^%^WHITE%^ "+
    "boom!%^RESET%^");

    tell_object(caster, "%^BOLD%^%^CYAN%^A thunderous %^BOLD%^%^BLACK%^wave %^BOLD%^%^WHITE%^"+
    "of %^BOLD%^%^RED%^force%^BOLD%^%^CYAN%^ rolls out from you in all directions!%^RESET%^");

    tell_room(place, "%^BOLD%^%^WHITE%^With a %^BOLD%^%^YELLOW%^THUNDEROUS%^BOLD%^"+
    "%^WHITE%^ boom a %^BOLD%^%^BLACK%^wave %^BOLD%^%^WHITE%^"+
    "of %^BOLD%^%^RED%^force%^BOLD%^%^WHITE%^ rolls out from "+caster->QCN+
    "%^BOLD%^%^WHITE%^ going in all directions!%^RESET%^", caster);

    foes += target_selector();
    if(!sizeof(foes))
    {
        if(objectp(environment(environment(caster)))) foes += all_living(environment(caster));
    }
    if(member_array(caster,foes) != -1) foes -= ({caster});

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }
    for(i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i]->id(""+caster->query_name()+" summoned")) continue;
        if(foes[i]->id(""+(string)caster->query_name()+" retainer")) continue;
        if(evade_splash(foes[i])) continue; //evasion
        tell_object(foes[i], "%^BOLD%^%^CYAN%^The %^BOLD%^%^BLACK%^wave "+
        "%^BOLD%^%^CYAN%^of %^BOLD%^%^RED%^force%^BOLD%^%^BLACK%^ slams into "+
        "you!%^RESET%^");

        tell_room(place, "%^BOLD%^%^CYAN%^The %^BOLD%^%^BLACK%^wave "+
        "%^BOLD%^%^CYAN%^of %^BOLD%^%^RED%^force%^BOLD%^%^CYAN%^ slams into "+
        foes[i]->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", foes[i]);
        define_base_damage(0);
        dam = sdamage;

        if(!do_save(foes[i]))
        {
            tell_object(foes[i], "%^BOLD%^%^CYAN%^You are thrown violently to the ground!%^RESET%^");
            foes[i]->set_tripped(1, "%^BOLD%^%^BLACK%^You are struggling to get back to your feet!%^RESET%^");
            tell_room(place, foes[i]->QCN+"%^BOLD%^%^CYAN%^ is thrown violently to the "+
            "ground!%^RESET%^", foes[i]);
        }
        else dam /= 2;
        damage_targ(foes[i],foes[i]->return_target_limb(),dam,"force");
        continue;
    }
    if(objectp(place))
    {
        myExits = place->query_exits();
        if(sizeof(myExits))
        {
            myFrom = base_name(place);
            if(living(caster)) obs = all_inventory(place);
            obs = filter_array(obs, "is_nonliving", FILTERS_D);
            for(i = 0;i < sizeof(obs);i++)
            {
                if(!objectp(obs[i])) continue;
                if(obs[i]->query_property("no animate")) continue;
                if(obs[i]->query_property("no get")) continue;
                if((int)obs[i]->query_weight() > clevel) continue;
                if(!stringp(obs[i]->query_short())) continue;
                if(random(5)) continue;

                myExit = myExits[random(sizeof(myExits))];
                if(!place->query_open(myExit) && place->is_vault())
                {
                    myExits -= ({myExit});
                    if(!sizeof(myExits)) break;
                    myExit = myExits[random(sizeof(myExits))];
                    if(!place->query_open(myExit) && place->is_vault())
                    {
                        myExits -= ({myExit});
                        continue;
                    }
                }
                tell_room(place, obs[i]->query_short()+ "%^BOLD%^%^CYAN%^ is thrown "+
                myExit+"%^BOLD%^%^CYAN%^ by the powerful %^BOLD%^%^RED%^"+
                "wave%^BOLD%^%^CYAN%^ of force!%^RESET%^");
                myPlace = place->query_exit(myExit);
                obs[i]->move(myPlace);
                if(!objectp(environment(obs[i]))) continue;
                if(stringp(myWhere = environment(obs[i])->query_direction(myFrom)))
                {
                    tell_room(environment(obs[i]), obs[i]->query_short()+"%^BOLD%^%^CYAN%^ "+
                    "is suddenly thrown into the area from the "+myWhere+"!%^RESET%^");
                }
                else
                {
                    tell_room(environment(obs[i]), obs[i]->query_short()+"%^BOLD%^%^CYAN%^ "+
                    "is suddenly thrown into the area!%^RESET%^");
                }
                continue;
            }
        }
    }
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
