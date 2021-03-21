#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <magic.h>
#include <teleport.h>

inherit SPELL;
mixed endplace;

void create() {
    ::create();
    set_spell_name("greater teleport");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_domains("travel");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS greater teleport on LOCATION");
    set_description("This greater version of teleport allow mage to travel to her destination, without change to arrive off target, bringing all her followers with her.

%^BOLD%^%^RED%^See also:%^RESET%^ recall, remember, unremember");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
    set_peace_needed(1);
}

string query_cast_string()
{
    tell_room(place,"%^CYAN%^"+caster->QCN+" raises hand up in the air, blue light forms in it.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof)
{
    endplace = caster->query_rem_room(arg);

    spell_successful();

    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and it backfires.");
        damage_targ(caster, caster->return_target_limb(), sdamage / 4, "mental");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();

    }

    tell_room(endplace,"%^BOLD%^%^CYAN%^A %^WHITE%^bright%^BLUE%^ blue %^CYAN%^light grows in your vicinity.",caster);
    call_out("spell_effect_next",ROUND_LENGTH);
}

void spell_effect_next()
{

    object *party, *presentparty, *followers, endplace;
    int i, healed;

    presentparty = ({});
    followers = caster->query_followers();
    if(sizeof(followers))
    {
        for(i=0;i<sizeof(followers);i++)
        {
            if(!objectp(followers[i]))
                continue;
            if(!present(followers[i],environment(caster)))
                continue;
            presentparty += ({followers[i]});
        }
    }
    tell_object(caster,"%^CYAN%^You open your hand, blinding light forces you to close eyes, and when you open them you appear somewhere else.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" disappears in a flash of blinding light!%^RESET%^", caster);
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" engulfs "+caster->QP+" companions into blinding light!%^RESET%^", presentparty);
    tell_room(endplace,"%^BOLD%^%^WHITE%^A bright light flashes in your vicinity.%^RESET%^",caster);
    if(!(endplace=TELEPORT->teleport_object(caster,caster,arg,clevel)))
    {
        tell_object(caster,"You sense something blocking your "+
                    "passage and lose concentration on your power.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();
        return;
    }

    presentparty -= ({ caster });

    followers = caster->query_followers();
    if(sizeof(followers))
    {
        presentparty += followers;
        for(i=0;i<sizeof(followers);i++)
        {
            if(!objectp(followers[i]))
            {
                presentparty -= ({followers[i]});
                continue;
            }
            if(member_array(followers[i],presentparty) != -1)
                continue;
        }
    }
    presentparty->move_player(endplace);
    map_array(presentparty,(:caster->add_follower($1):));
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
