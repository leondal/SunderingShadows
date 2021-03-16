#include <priest.h>
#include <magic.h>
#include <spell.h>
#include <terrain.h>
#include <daemons.h>

inherit SPELL;

object spikes,*old_ppl=({});
int timer;

void set_exit_stuff();

void create()
{
    ::create();
    set_spell_name("spike growth");
    set_spell_level(([ "druid" : 3, "ranger" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS spike growth");
    set_description("This spell causes roots or other vegetation in the area to become hard and razor sharp.  Anyone moving in the area, "
        "such as the movement in combat or passing through the room, will suffer piercing damage to his or her feet.  The spell may only "
        "be used in areas where some vegetation may be found.");
    set_property("magic",1);
    set_casting_time(1);
    traveling_spell(1); // To pull correct sdamage
}

//Please leave this as an example, if we ever return to this
/* int terrain_filter() */
/* { */
/*     string *valid_terrains; */
/*     valid_terrains = OUTSIDE - ({ "barren","desert rocks","old mounts","new mounts","snow","ice","shallow water","deep water","glacier","boats" }); */
/*     valid_terrains += ({ "village","cemetery","garden" }); */

/*     if(!objectp(place)) { return 0; } */

/*     if(member_array((string)place->query_terrain(),valid_terrains) == -1) { return 0; } */
/*     return 1; */
/* } */


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^GREEN%^You whisper a prayer to the wilderness, calling on the vegetation in the area!%^RESET%^");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" whisper's something under "+caster->QP+" breath and the vegetation begins to move!%^RESET%^",caster);
    return "display";
}


int preSpell()
{
    if (place->query_property("spike growth")) {
        tell_object(caster, "%^YELLOW%^The vegetation here has already been turned into spikes!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    return;
}


void set_exit_stuff()
{
    string *this_exits=({});
    int i;

    this_exits = (string*)place->query_exits();
    if(!sizeof(this_exits)) { return; }
    for(i=0;i<sizeof(this_exits);i++)
    {
        place->add_pre_exit_function(this_exits[i],"GoThroughDoor");
    }
    return;
}


void remove_exit_stuff()
{
    string *this_exits=({});
    int i;

    this_exits = (string*)place->query_exits();

    if(!sizeof(this_exits)) { return; }

    for(i=0;i<sizeof(this_exits);i++)
    {
        place->remove_pre_exit_function(this_exits[i]);
    }
    return;
}


int GoThroughDoor()
{
    if(!objectp(TP)) { return 1; }
    if((string)TP->query_true_name() == (string)caster->query_true_name()) { return 1; }

    if(!do_save(TP))
    {
        tell_object(TP,"%^RED%^You wince in pain as you step on one of the sharp spikes!");
        tell_room(ETP,"%^RED%^"+TP->QCN+" winces in pain as "+TP->QS+" steps on a sharp spike!",TP);
        TP->cause_typed_damage(TP,TP->return_target_limb(),sdamage,"piercing");
        return 1;
    }
    return 1;
}



void execute_attack()
{
    object *ppl=({}),*fighters=({}),*tmp=({});
    int i,j;

    if(!objectp(TO))            { dest_effect(); return; }
    if(!objectp(caster))        { dest_effect(); return; }
    if(!objectp(place))         { dest_effect(); return; }
    if(!present(caster,place))  { dest_effect(); return; }

    if(!timer)
    {
        tell_object(caster,"%^GREEN%^You can feel nature answering your call!  The roots and sprigs of "
            "vegetation in the area come to life and bend to your will, sharpening and twisting to "
            "damage anyone who opposes you!");
        tell_room(place,"%^GREEN%^You watch as the roots and sprigs of vegetation in the area "
            "begin to move!  They begin sharpening and twisting into jagged, dangerous spikes!");

        place->set_property("spike growth",1);

        spikes = new(OBJECT);
        spikes->set_name("Spike Growth.");
        spikes->set_short("%^RESET%^%^BOLD%^%^GREEN%^A twisted mass of pointed spikes");
        spikes->set_long("%^RESET%^%^BOLD%^%^GREEN%^The vegetation in this area has been twisted and formed into dangerous spikes "
            "that threaten to damage the feet of anyone who steps on them!%^RESET%^");
        spikes->set_id(({"spikes","spike growth spikes","spike growth"}));
        spikes->set_property("no animate",1);
        spikes->set_weight(1000000);
        spikes->move(place);
        set_exit_stuff();

        timer = time() + (ROUND_LENGTH * clevel * 3);

        caster->set_property("spelled",({TO}));
        addSpellToCaster();
        spell_successful();
    }

    if(time() > timer ) { dest_effect(); return; }


    ::execute_attack();

    ppl = all_living(place);
    ppl -= ({ caster });
    ppl = target_filter(ppl);

    // removes people from the old_ppl list if they leave the room
    // so they get damaged again when they walk back inside
    if(sizeof(old_ppl))
    {
        for(i=0;i<sizeof(old_ppl);i++)
        {
            if(!objectp(old_ppl[i])) { continue; }
            if(!present(old_ppl[i],place)) { continue; }
            tmp += ({ old_ppl[i] });
        }
        if(sizeof(tmp)) { old_ppl = tmp; }
        else { old_ppl = ({}); }
    }

    define_base_damage(0);
    if(sizeof(ppl))
    {
        for(i=0;i<sizeof(ppl);i++)
        {
            if(!objectp(ppl[i])) { continue; }

            // old_ppl used to check people who have been in the room more than 1 round
            // if they have not, and they are not in the caster's party, then damage them
            if(member_array(ppl[i],old_ppl) == -1)
            {
                old_ppl += ({ ppl[i] });
                tell_object(ppl[i],"%^RED%^You wince in pain as you step on one of the sharp spikes!");
                tell_room(place,"%^RED%^"+ppl[i]->QCN+" winces in pain as "+ppl[i]->QS+" steps on one of the sharp spikes!");
                ppl[i]->cause_typed_damage(ppl[i],ppl[i]->return_target_limb(),sdamage,"piercing");
                if(!interactive(ppl[i])) { spell_kill(ppl[i],caster); }
            }

            // they're not fighting, so they can move carefully and avoid the spikes
            if(!sizeof(ppl[i]->query_attackers())) { continue; }

            tell_object(ppl[i],"%^RED%^You wince in pain as you step on one of the sharp spikes!");
            tell_room(place,"%^RED%^"+ppl[i]->QCN+" winces in pain as "+ppl[i]->QS+" steps on one of the sharp spikes!");
            ppl[i]->cause_typed_damage(ppl[i],ppl[i]->return_target_limb(),sdamage,"piercing");
            if(!interactive(ppl[i])) { spell_kill(ppl[i],caster); }
        }
    }

    place->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place,"%^YELLOW%^The vegetation in the area loses its sharp edge and shrinks back to normal!");
        remove_exit_stuff();
        place->remove_property("spike growth");
    }

    if(objectp(spikes))
    {
        spikes->move("/d/shadowgate/void");
        destruct(spikes);
    }

    if(objectp(caster))
    {
        removeSpellFromCaster();
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
