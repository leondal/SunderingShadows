//Prismatic Spray coded by Bane//
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int flag, roll, theProf;


void create()
{
    ::create();
    set_spell_name("prismatic spray");
    set_spell_level(([ "mage" : 7,"oracle":7 ]));
    set_mystery("heavens");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS prismatic spray on TARGET");
    set_damage_desc("random chance to roll one of 8 rays");
    set_description("When the prismatic spray spell is cast, the wizard causes several shimmering rays of light to flash "
        "from his/her hand.  Each ray has a different purpose and power.  The creature struck will be touched by one or more "
        "rays and will be subject to a number of different attacks from the spell.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_target_required(1);
    set_save("varied");
}


void spell_effect(int prof)
{
    object *attackers,*targs=({}),tmp;
    int i,hits;

    theProf = prof;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if (!present(target, environment(caster)))
    {
        tell_object(caster,"Your target is no longer here.");
        dest_effect();
        return;
    }
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^YELLOW%^You chant a few words and point your hand at "+target->QCN+".");
    tell_object(target,"%^BOLD%^YELLOW%^"+caster->QCN+" chants a words and points "+caster->QP+" hand at you!");
    tell_room(place,"%^BOLD%^YELLOW%^"+caster->QCN+" chants a few words and points "+caster->QP+" hand at "+target->QCN+"!",({target,caster}));
    spell_kill(target, caster);

    hits = clevel / 11;

    attackers = target_selector();
    attackers = distinct_array(attackers);
    attackers -= ({ target });


    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) continue;
            if(sizeof(targs) < hits) targs += ({ attackers[i] });
        }
    }

    targs += ({ target });

    for(i=0;i<sizeof(targs);i++)
    {
        if(!objectp(targs[i])) { continue; }
        tell_object(caster,"%^BOLD%^A rainbow of colors flash from your hand striking "+targs[i]->QCN+"!");
        tell_object(targs[i],"%^BOLD%^A rainbow of colors flash from "+caster->QCN+"'s hand striking you!");
        tell_room(place,"%^BOLD%^A rainbow of colors flash from "+caster->QCN+"'s hand striking "+targs[i]->QCN+"!",({caster,targs[i]}));

        if(targs[i]->query_level() < 9) targs[i]->set_temporary_blinded(2);

        flash(targs[i],0);
    }

    spell_successful();
    dest_effect();
}


void flash(object targ, int iteration)
{
    if(!iteration) { roll = roll_dice(1,8); }
    else { roll = roll_dice(1,7); } // the '8' reroll should only opt from the normal rays, but run it twice.
    if(!present(targ,place)) return;

    switch (roll)
    {
    case(1): ray1(targ);    break;
    case(2): ray2(targ);    break;
    case(3): ray3(targ);    break;
    case(4): ray4(targ);    break;
    case(5): ray5(targ);    break;
    case(6): ray6(targ);    break;
    case(7): ray7(targ);    break;
    case(8): flash(targ,1); break;
    }
    if(iteration == 1) { flash(targ,2); } // run it a second time - two rays for the lucky roll of 8!
}


void ray1(object targ)
{
    if(!objectp(targ)) return;

    set_save("reflex");
    if(do_save(targ))
    {
        if(evade_splash(targ)) return;
        tell_object(targ,"%^BOLD%^%^RED%^A blinding red light grazes you!");
        tell_room(place,"%^BOLD%^%^RED%^A blinding red light grazes "+targ->QCN+"!",targ);
        damage_targ(targ, targ->return_target_limb(), sdamage/6,"fire");
        return;
    }

    tell_object(targ,"%^BOLD%^%^RED%^A blinding red light burns into you!");
    tell_room(place,"%^BOLD%^%^RED%^A blinding red light burns into "+targ->QCN+"!",targ);
    damage_targ(targ, targ->return_target_limb(), sdamage / 3,"fire");
}


void ray2(object targ)
{
    if(!objectp(targ)) return;

    set_save("reflex");
    if(do_save(targ))
    {
        if(evade_splash(targ)) return;
        tell_object(targ,"%^BOLD%^A blinding orange light grazes you!");
        tell_room(place,"%^BOLD%^A blinding orange light grazes "+targ->QCN+"!",targ);
        damage_targ(targ, targ->return_target_limb(), sdamage/6,"acid");
        return;
    }

    tell_object(targ,"%^BOLD%^A blinding orange light burns into you!");
    tell_room(place,"%^BOLD%^A blinding orange light burns into "+targ->QCN+"!",targ);
    damage_targ(targ, targ->return_target_limb(), sdamage / 3,"acid");
}


void ray3(object targ)
{
    if(!objectp(targ)) return;

    set_save("reflex");

    if(do_save(targ))
    {
        if(evade_splash(targ)) return;
        tell_object(targ,"%^BOLD%^%^YELLOW%^A blinding yellow light grazes you!");
        tell_room(place,"%^BOLD%^%^YELLOW%^A blinding yellow light grazes "+targ->QCN+"!",targ);
        damage_targ(targ, targ->return_target_limb(), sdamage/6,"electricity");
        return;
    }

    tell_object(targ,"%^BOLD%^%^YELLOW%^A blinding yellow light burns into you!");
    tell_room(place,"%^BOLD%^%^YELLOW%^A blinding yellow light burns into "+targ->QCN+"!",targ);
    damage_targ(targ, targ->return_target_limb(), sdamage / 3,"electricity");
}


//changed this ray to half dmg, blue is already instakill with a save so they don't need two!
void ray4(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^A blinding green light burns into you!");
    tell_room(place, "%^BOLD%^%^GREEN%^A blinding green light burns into " + targ->QCN + "!", targ);
    set_save("fort");

    if (!do_save(targ)) {
        // Disadvantage should be the same as in FOD.
        if (combat_death_save(targ, 6)) {
            tell_object(caster, "" + targ->QCN + " seems to struggle for a minute but recovers quickly.");
            tell_object(targ, "You struggle for a minute but recover quickly.");
            tell_room(place, "" + targ->QCN + " struggles for a minute but recovers quickly.", ({ targ, caster }));
            return;
        }
        POISON_D->ApplyPoison(targ, "deathblade", caster, "injury");
        return;
    }
    POISON_D->ApplyPoison(targ, "black adder venom", caster, "injury");
}


void ray5(object targ)
{
    int i;
    object corpse,*inv;

    if(!objectp(targ)) return;
    tell_object(targ,"%^BOLD%^%^BLUE%^A blinding blue light burns into you!");
    tell_room(place,"%^BOLD%^%^BLUE%^A blinding blue light burns into "+targ->QCN+"!",targ);

    set_save("fort");
    if(!do_save(targ))
    {
        if (targ->query_property("no death") || userp(caster))
        {
            tell_object(caster,""+targ->QCN+" looks pale for a second but recovers quickly.");
            tell_object(targ,"You feel faint for a second but recover quickly.");
            tell_room(place,""+targ->QCN+" looks pale for a second but recovers quickly.",({targ,caster}));
            return;
        }

        tell_object(targ,"You feel very cold as your body starts to turn to stone.");
        tell_room(place,""+targ->QCN+" slowly stops moving as "+targ->QP+" body starts to turn to stone.",targ);

        if(userp(caster)) //let this KO in PK, rather than instakill
        {
            damage_targ(targ, targ->return_target_limb(), ((int)targ->query_hp() +50),"untyped");
        }
        else
        {
            damage_targ(targ, targ->return_target_limb(), ((int)targ->query_max_hp()*5),"untyped");
        }

        corpse = present("corpse",place);
        if (!present("corpse",place)) return;

        else
        {
            inv = all_inventory(corpse);
            for(i=0;i<sizeof(inv);i++)
            {
                if(!objectp(inv[i])) continue;
                inv[i]->move(place);
            }
            corpse->remove();
            new("/d/magic/obj/pstatue")->move(place);
        }
        return;
    }

    tell_object(caster,""+targ->QCN+" looks pale for a second but recovers quickly.");
    tell_object(targ,"You feel faint for a second but recover quickly.");
    tell_room(place,""+targ->QCN+" looks pale for a second but recovers quickly.",({targ,caster}));
}


void ray6(object targ)
{
    if(!objectp(targ)) return;
    tell_object(targ,"%^BOLD%^%^CYAN%^A blinding indigo light burns into you!");
    tell_room(place,"%^BOLD%^%^CYAN%^A blinding indigo light burns into "+targ->QCN+"!",targ);

    set_save("will");
    if(!do_save(targ))
    {
        targ->set_paralyzed(ROUND_LENGTH * roll_dice(1,4),"You are still shaking after being hit by the flash of light!");
        return;
    }

    tell_object(targ,"You concentrate and fight off the ray's effects.");
    tell_room(place,""+targ->QCN+" concentrates for a moment and shakes off the ray's effects.",targ);
}


void ray7(object targ)
{
    if(!objectp(targ)) { return; }
    tell_object(targ,"%^BOLD%^%^MAGENTA%^A blinding violet light burns into you!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^A blinding violet light burns into "+targ->QCN+"!",targ);

    if (targ->is_monster())
    {
        ray5(targ);
        return;
    }

    set_save("will");
    if(!do_save(targ))
    {
        call_out("move_me",1,targ);
        return;
    }

    tell_object(targ,"You concentrate and fight off the ray's effects.");
    tell_room(place,""+targ->QCN+" concentrates for a moment and shakes off the ray's effects.",targ);
}


void move_me(object targ)
{
    if(!objectp(targ)) return;

    if(targ == caster)
    {
        ray2(targ);
        return;
    }

    switch (random(6))
    {
    case(0):
        targ->move("/d/shadow/city/room/southcross");
        targ->describe_current_room(1);
        break;
    case(1):
        targ->move("/d/laerad/wasteland/waste1");
        targ->describe_current_room(1);
        break;
    case(2):
        targ->move("/d/antioch/ruins/rooms/gates");
        targ->describe_current_room(1);
        break;
    case(3):
        targ->move("/d/tharis/newtharis/rooms/north5");
        targ->describe_current_room(1);
        break;
    case(4):
        targ->move("/d/deku/hhouse/hall1i");
        targ->describe_current_room(1);
        break;
    case(5):
        targ->move("/d/azha/town/south3");
        targ->describe_current_room(1);
        break;
    }
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
