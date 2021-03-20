#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("fear");
    set_spell_level(([ "bard" : 3, "mage" : 4, "psion" : 6, "inquisitor":4, "oracle":5, "cleric" : 4 ]));
    set_spell_sphere("necromancy");
    set_domains("evil");
    set_mystery("dragon");
    set_syntax("cast CLASS fear");
    set_description("Fear sends a wave of horrid thoughts and images out toward the foes around the caster, possibly terrifying them. An invisible cone of terror causes each living creature in the area to become panicked unless it succeeds on a Will save. If cornered, a panicked creature begins cowering. If the Will save succeeds, the creature is shaken for 1 round.");
    mental_spell();
    splash_spell(3);
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

string query_cast_string(){
    return "%^BLUE%^"+caster->QCN+" reaches into your very soul to search out your fears.";
}

void spell_effect(int prof)
{
    object *inven, *newinven, cur;
    int i,j, percent, x, hits,bonus;
    string *ids, MyType;
    object *weapons;

    tell_object(caster,"%^BLUE%^You send a cone of dark images and "+
                "deep-seeded fears forth from your hand.");

    inven = target_selector();
    inven -= ({caster});

    hits = clevel / 5;
    if(hits < 1) hits = 1;
    if(hits > 10) hits = 10;
    newinven = ({});

    if(hits < sizeof(inven))
    {
        while(hits > 0)
        {
            if(!sizeof(inven)) break;
            cur = inven[random(sizeof(inven))];
            inven -= ({cur});
            newinven += ({cur});
            hits--;
        }
        inven = newinven;
    }

    if(!sizeof(inven))
    {
        dest_effect();
        return;
    }

    for (i=0;i<sizeof(inven);i++)
    {
        if (!objectp(inven[i])) continue;
        if (wizardp(inven[i])) continue;

        MyType = (string)TO->query_spell_type();
        switch (MyType)
        {
        case "cleric":  bonus = (int)caster->query_stats("wisdom");         break;
        case "bard":    bonus = (int)caster->query_stats("charisma");       break;
        default:        bonus = (int)caster->query_stats("intelligence");   break;
        }

        bonus = (bonus - 10) / 2;
        if(bonus < 0) bonus = 0;
        bonus = bonus*(-1);

        if(race_immunity_check(inven[i], "fear"))
        {
            spell_kill(target, caster);
            continue;
        }

        //No need to check for undead after this
        if(mind_immunity_damage(inven[i], "default"))
        {
            continue;
        }

        if(do_save(inven[i],bonus))
        {
            tell_object(inven[i], "%^BLUE%^You fight back some "+
                        "horrid images magically placed in your mind.");
            tell_room(place,"%^BLUE%^You see "+inven[i]->QCN+" wince and shudder, "
                      "before regaining composure.",inven[i]);

            "/std/effect/status/shaken"->apply_effect(inven[i],2);

        }
        else
        {
            tell_object(inven[i],"%^BLUE%^Images of horror and terror "+
                        "flood your mind. You fight them all, but finally they "+
                        "grip your mind and you tremble.");
            tell_room(place, "%^BLUE%^Sheer horror contorts "+
                      ""+inven[i]->QCN+"'s face. "+inven[i]->QS+" breaks in "+
                      "fear and trembles.",inven[i]);
            "/std/effect/status/panicked"->apply_effect(inven[i],roll_dice(1,6));
        }

    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
