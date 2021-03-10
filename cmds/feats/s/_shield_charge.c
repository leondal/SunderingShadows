#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;


void create()
{
    ::create();
    feat_type("instant");
    feat_category("ImmortalDefender");
    feat_name("shield charge");
    feat_prereq("Immortal defender L4");
    feat_syntax("shield_charge [DIRECTION]");
    feat_desc("The immortal defender gets behind her shield and charges  her enemies, using the shield and her body as a battering ram. She is even  able to charge through some doors or to other rooms with her shield leading  the way.

This feat affects all attackers.");
    set_required_for(({ "shield master"}));
}


int allow_shifted() { return 0; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(ob->query_class_level("immortal_defender") < 4 || !FEATS_D->usable_feat(ob,"defenders presence"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_shield_charge(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


void execute_feat()
{
    ::execute_feat();

    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }

    place = environment(caster);

    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    if((int)caster->query_property("using shield charge") > time())
    {
        tell_object(caster,"You can't try to shield charge again so soon!");
        dest_effect();
        return;
    }

    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }

    if(!caster->is_wearing_type("shield"))
    {
        tell_object(caster, "You must be wearing a shield to use shield charge.");
        dest_effect();
        return;
    }

    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);

    return;
}


void execute_attack()
{
    object room, *followers, *attackers;
    string door;
    int i,open, locked,charging_direction,level, doing;

    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }

    if(place->query_exit(arg) != "/d/shadowgate/void")
    {
        place = environment(caster);

        room = find_object_or_load(place->query_exit(arg));

        if(!objectp(room) || room->query_property("no phase") || place->query_property("no phase")) // check for a door too
        {
            tell_object(caster,"You can't seem to shield charge to the "+arg+".");
            dest_effect();
            return;
        }

        if(door = place->query_door(arg))
        {
            open = place->query_open(door);
            if(!open)
            {
                locked = place->query_locked(door);
            }
            if(locked)
            {
                tell_object(caster,"You can't shield charge through that "+door+"!");
                dest_effect();
                return;
            }
        }

        followers = caster->query_followers();
        charging_direction = 1;
        doing = 1;

    }

    attackers = caster->query_attackers();

    if(sizeof(attackers))
    {
        level = caster->query_base_character_level();
        level += roll_dice(1,10); // might need adjustment

        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            if(attackers[i]->reflex_save(level))
            {
                tell_object(attackers[i],"%^MAGENTA%^"+caster->QCN+" charges around with "+caster->QP+" shield, but you manage "
                    "to get out of the way!");
                tell_room(place,"%^MAGENTA%^"+caster->QCN+" charges around with "+caster->QP+" shield leading the way, "
                    ""+attackers[i]->QCN+" manages to dodge out of the way!",({attackers[i],caster}) );
                continue;
            }
            if(attackers[i]->fort_save(level))
            {
                tell_object(attackers[i],"%^RED%^"+caster->QCN+" bowls into you with "+caster->QP+" shield, almost knocking you over!");
                tell_room(place, "%^RED%^"+caster->QCN+" bowls into "+attackers[i]->QCN+" with "+caster->QP+" shield, almost "
                    "knocking "+attackers[i]->QO+" over!",({attackers[i], caster}));
            }
            else
            {
                tell_object(attackers[i],"%^RESET%^%^BOLD%^%^BLUE%^"+caster->QCN+" slams into you brutally with "+caster->QP+" shield, almost "
                    "knocking your teeth loose!\n%^RESET%^%^GREEN%^You are sent sprawling to the ground!");
                tell_room(place,"%^RESET%^%^BOLD%^%^BLUE%^"+caster->QCN+" slams into "+attackers[i]->QCN+" with "+caster->QP+" shield, knocking "
                    ""+attackers[i]->QO+" flat on "+attackers[i]->QP+" back!",({attackers[i],caster}));
                attackers[i]->set_tripped(level / 10, "%^RESET%^%^GREEN%^You are trying to stand up again!");
            }
            doing = 1;
            attackers[i]->cause_typed_damage(attackers[i],attackers[i]->return_target_limb(), roll_dice(6, level), "bludgeoning");
        }

        tell_object(caster,"%^MAGENTA%^You charge through the area with your shield, sending opponents scattering!");
        caster->remove_property("using shield charge");
        caster->set_property("using shield charge", time() + 35 );
        delay_msg(35,"%^BOLD%^%^WHITE%^You can %^CYAN%^shield charge%^WHITE%^ again.%^RESET%^");
    }




    if(charging_direction)
    {
        caster->remove_property("using shield charge");
        caster->set_property("using shield charge", time() + 35 );
        if(door && !open)
        {
            tell_object(caster, "%^RED%^You smash open the "+door+" as you charge to the "+arg+" behind your shield!");
            place->set_open(door,1);
        }
        else
        {
            tell_object(caster,"%^YELLOW%^You CHARGE to the "+arg+" behind your shield!");
        }

        caster->clear_followers();
        caster->move(room);


        if(sizeof(followers))
        {
            for(i=0;i<sizeof(followers);i++)
            {
                if(!objectp(followers[i])) { continue; }
                if(followers[i] != caster)
                {
                    if(door && !open)
                    {
                        tell_object(followers[i],"%^YELLOW%^"+caster->QCN+" CHARGES THROUGH the "+door+", battering it open as "
                            ""+caster->QS+" moves to the "+arg+" leaving you to follow quickly in "+caster->QP+" wake!");
                    }
                    else
                    {
                        tell_object(followers[i],"%^YELLOW%^"+caster->QCN+" CHARGES to the "+arg+" behind "+caster->QP+" shield "
                            "and you follow quickly in "+caster->QP+" wake!");
                    }
                    followers[i]->move(room);
                    followers[i]->force_me("look");
                    caster->add_follower(followers[i]);
                }
            }
        }
        caster->force_me("look");
    }



    if(!doing)
    {
        tell_object(caster,"You really wish you had something to charge into with your shield");
        tell_room(place,""+caster->QCN+" looks over "+caster->QP+" shield and seems disappointed",caster);
    }

    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
