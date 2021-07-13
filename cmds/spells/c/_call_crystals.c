#include <std.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object *crystals=({});
int end_time;

void create() {
    ::create();
    set_spell_name("call crystals");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS call crystals");
    set_description("This power will summon a certain number of crystals based on the shaper's skill.  The crystals are "
"animated matter from the Astral Plane, drawn here by the shaper's abilities.  The crystals are non-intelligent beings "
"who will defend the shaper until they are dispelled or have used up their energy (effectively 'dying').");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^ORANGE%^"+caster->QCN+" closes "+caster->QP+" eyes and "+
       "tosses a striated gem upon the ground!";
}

int preSpell()
{
    if (present(caster->query_name()+" summoned 2", place))
    {
        tell_object(caster,"You have crystals under your control already.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    object ob,*attackers=({});
    int i,j,num_crystals,mylevel;

    mylevel = clevel;
    num_crystals = mylevel/4;
    if(num_crystals < 2) { num_crystals = 2; }
    if(num_crystals > 8) { num_crystals = 8; }

    attackers = (object *)caster->query_attackers();

    for(i=0;i<num_crystals;i++)
    {
        ob = new("/d/magic/mon/called_crystal");
        if(!objectp(ob)) { continue; }
        if(!objectp(place)) { continue; }
        if(!objectp(caster)) { continue; }
        crystals += ({ ob });
        ob->add_id(""+(string)caster->query_name()+" summoned");
        ob->set_property("spelled",({TO}));
        ob->set_property("spell",TO);
        ob->set_property("spell_creature",TO);
        ob->set_property("minion", caster);
        ob->setup_crystal(caster);

        ob->set_max_hp((query_spell_level(spell_type)*2+clevel)*20+20);
        ob->set_hp(ob->query_max_hp());

        ob->move(place);
        caster->add_protector(ob);
        caster->add_follower(ob);

        if(!objectp(ob)) { continue; }
        if(!objectp(place)) { continue; }
        if(!objectp(caster)) { continue; }
        if(environment(caster) != place) { continue; }

        tell_room(place,""+ob->query_short()+" appears near "+caster->QCN+"!",caster);
        tell_object(caster,""+ob->query_short()+" appears near you!");

        if(sizeof(attackers))
        {
            for(j=0;j<sizeof(attackers);j++)
            {
                if(!objectp(attackers[j])) { continue; }
                spell_kill(ob,attackers[j]);
                tell_object(attackers[j],""+ob->query_short()+" attacks you!");
            }
        }
    }

    end_time = time() + 120 + ((ROUND_LENGTH * 2) * mylevel);

    call_out("check",5);
    spell_successful();
    addSpellToCaster();
}

void check()
{
    object *attackers=({}),*tmp=({});
    int i,j;

    if(!objectp(TO) || !objectp(caster) || ( time() > end_time ))
    {
        dest_effect();
        return;
    }

    attackers = caster->query_attackers();
    if(sizeof(crystals))
    {
        for(i=0;i<sizeof(crystals);i++)
        {
            if(!objectp(crystals[i])) { continue; }
            tmp += ({ crystals[i] });
            if(environment(crystals[i]) != environment(caster))
            {
                if(!objectp(environment(crystals[i]))) { continue; }
                tell_room(environment(crystals[i]),""+crystals[i]->query_short()+" shimmers and disappears.");
                caster->remove_protector(crystals[i]);
                caster->remove_follower(crystals[i]);
                crystals[i]->remove();
            }
            if(sizeof(attackers))
            {
                for(j=0;j<sizeof(attackers);j++)
                {
                    if(!objectp(attackers[j])) { continue; }
                    spell_kill(crystals[i],attackers[j]);
                }
            }
        }
    }

   tmp = distinct_array(tmp);
   if(!sizeof(tmp))
   {
       dest_effect();
       return;
   }

   call_out("check",5);
   return;
}


void dest_effect()
{
    int i;

    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    if(sizeof(crystals))
    {
        for(i=0;i<sizeof(crystals);i++)
        {
            if(!objectp(crystals[i])) { continue; }
            crystals[i]->move("/d/shadowgate/void");
            if(objectp(crystals[i])) crystals[i]->remove();
        }
        tell_object(caster,"%^YELLOW%^The summoned crystals vanish...%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
