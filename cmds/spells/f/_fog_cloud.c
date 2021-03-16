#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int duration;
object cloud,*blind=({});

void create()
{
    ::create();
    set_spell_name("fog cloud");
    set_spell_level(([ "druid" : 2, "mage" : 2, "assassin": 1, "oracle" : 2, "magus" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_mystery(({"battle","apocalypse","waves"}));
    set_syntax("cast CLASS fog cloud");
    set_description("When fog cloud is cast, a bank of dense fog moves into the area, making it impossible for anyone, "
        "including the caster, to see more than a few inches from his or her face.  The cloud will linger in the area "
        "for a few minutes and then it will disipate on its own.");
    set_verbal_comp();
    set_target_required(0);
}

int preSpell()
{
    if(place->query_property("fog cloud"))
    {
        tell_object(caster,"%^RESET%^%^YELLOW%^There's already a fog cloud here!");
        return 0;
    }
    if(place->query_property("indoors"))
    {
        tell_object(caster,"%^RESET%^%^YELLOW%^This place is too enclosed to gather a fog cloud.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    tell_object(caster,"%^RESET%^%^BOLD%^You hold your hands in the air and close your eyes, calling on nature itself!");
    tell_room(place,"%^RESET%^%^BOLD%^"+caster->QCN+" holds "+caster->QP+" hands in the air and closes "+caster->QP+"eyes!",caster);

//    duration = (60 + (ROUND_LENGTH * clevel)) + time();
    duration = (ROUND_LENGTH + (ROUND_LENGTH * ((clevel+9)/10))) + time();

    cloud = new(OBJECT);
    cloud->set_name("A bank of dense fog.");
    cloud->set_short("%^RESET%^%^BOLD%^A bank of dense fog");
    cloud->set_long("%^RESET%^%^BOLD%^This bank of fog blankets the area in an haze that's so thick, noone can see anything more than "
        "a few inches in front of their face!%^RESET%^");
    cloud->set_id(({"fog","fog bank"}));
    cloud->set_property("no animate",1);
    cloud->set_weight(1000000);
    call_out("cloud_blindness",5);
    return;
}

void cloud_blindness()
{
    object *ppl,tp;
    int i;

    if((time() > duration) || !objectp(place))
    {
        dest_effect();
        return;
    }

    if(!place->query_property("fog cloud"))
    {
        tell_room(place,"%^RESET%^%^BOLD%^A dense cloud of fog pours into the area, making it impossible to see!%^RESET%^");
        cloud->move(place);
        place->set_property("fog cloud",1);
    }

    if(sizeof(blind))
    {
        for(i=0;i<sizeof(blind);i++)
        {
            if(!objectp(tp = blind[i])) { continue; }
            if(present(tp,place)) { continue; }

            tell_object(tp,"%^CYAN%^You leave the dense fog bank and your sight returns!");
            tp->set_blind(0);
        }
    }

    blind = ({});

    ppl = all_living(place);

    for(i=0;i<sizeof(ppl);i++)
    {
        if(!objectp( tp = ppl[i])) { continue; }
        if(avatarp(tp)) { continue; }

        if(!tp->query_blind()) { tell_object(tp,"%^RESET%^%^BOLD%^The fog makes it impossible to see!"); }
        tp->set_blind(1);
        blind += ({ tp });
    }

    call_out("cloud_blindness",1);
    return;
}

void dest_effect()
{
    object tp;
    int i;

    if(objectp(place))
    {
        tell_room(place,"%^CYAN%^The dense bank of fog slowly disipates!");
        place->remove_property("fog cloud");
    }
    if(objectp(cloud))
    {
        cloud->move("/d/shadowgate/void");
        destruct(cloud);
    }

    if(sizeof(blind))
    {
        for(i=0;i<sizeof(blind);i++)
        {
            if(!objectp( tp = blind[i])) { continue; }
            tell_object(tp,"%^BLUE%^The fog clears and you can see again!");
            tp->set_blind(0);
        }
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
