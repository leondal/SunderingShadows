#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string YOU, HIM, element;


void create()
{
    ::create();
    set_spell_name("delayed fireball");
    set_spell_level(([ "mage" : 7,]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS delayed fireball on TARGET");
    set_damage_desc("delayed fire");
    set_description("This spell functions much like fireball, but at a greater potency. As such, it takes more time to build its blast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
}


string query_cast_string()
{
    tell_room(place, "%^RED%^"+caster->QCN+" mutters some syllables while raising a hand, and an orb of fire begins to grow in it.");
    return "display";
}


void spell_effect(int prof)
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    YOU = caster->QCN;
    HIM = target->QCN;

    element = "fire";
    tell_object(caster, "%^RED%^Slowly the orb grows bigger.%^RESET%^");
    tell_room(place, "%^RED%^Slowly the orb in "+YOU+"'s hands grows bigger.%^RESET%^", ({caster}) );
    call_out("zapper",ROUND_LENGTH);
}


void zapper()
{
    string before, after, size;
    object *inven, *hits = ({});
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(target) || !objectp(place) || !present(target, place))
    {
        tell_object(caster, "%^BLUE%^With the lack of a target the orb dissipates.");
        tell_room(place, "%^BLUE%^With the lack of a target, the orb in "+YOU+"'s hands dissipates.",({caster}));
        dest_effect();
        return;
    }

    spell_successful();

    size = "avalanche";
    if (clevel < 15) size = "gush";
    if (clevel < 20) size = "flood";

    tell_room(place,"%^BOLD%^%^RED%^A blazing maelstrom of %^RESET%^%^RED%^flame %^BOLD%^%^RED%^bursts forth from the orb toward "+HIM+"!%^RESET%^",target);
    tell_object(target,"%^BOLD%^%^RED%^A blazing maelstrom of %^RESET%^%^RED%^flame %^BOLD%^%^RED%^bursts forth from
m "+YOU+"'s orb toward you!%^RESET%^");

    inven = all_living(environment(caster));
    inven = target_filter(inven);

    if(sizeof(inven))
    {
        for(i=0;i<sizeof(inven);i++)
        {
            if(!objectp(inven[i])) { continue; }
            if(inven[i] == caster) { continue; }
            if(inven[i] == target) { continue; }
            if(random(100) < clevel)
            {
                hits += ({ inven[i] });
                continue;
            }
            if(random(500) < clevel)
            {
                hits += ({ inven[i] });
                continue;
            }
        }
    }

    if(sizeof(hits))
    {
        for (i = 0;i < sizeof(hits);i++)
        {
            if(!objectp(hits[i])) { continue; }

            tell_object(hits[i],"%^CYAN%^You are singed by the edge of the fiery maelstrom!%^RESET%^");
            tell_room(place,"%^CYAN%^"+hits[i]->QCN+" is singed by the edge of the fiery maelstrom!%^RESET%^",hits[i]);

            if(do_save(hits[i]))
                damage_targ(hits[i],"torso",sdamage/2,element);
            else
                damage_targ(hits[i],"torso",sdamage,element);
        }
    }

    tell_object(target,"%^BOLD%^%^RED%^The maelstrom of fire hits you directly, its unbearable heat searing into your skin!%^RESET%^");
    tell_room(place,"%^BOLD%^%^RED%^"+HIM+" is %^BOLD%^%^WHITE%^blasted %^BOLD%^%^RED%^with the full force of the fiery maelstrom!%^RESET%^",target);

    if(do_save(target)) { sdamage = sdamage/2; }
    damage_targ(target, "torso", sdamage, element);
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
