#include <std.h>
#include <daemons.h>
#include <teleport.h>

inherit FEAT;


void create()
{
    ::create();
    feat_type("instant");
    feat_category("Shadowdancer");
    feat_name("shadow jump");
    feat_syntax("shadow_jump DESTINATION");
    feat_prereq("Shadowdancer L7");
    feat_desc("A shadowdancer is able to jump into the shadows at one location in the world and reappear at another location in a completely different part of the world. He is able to travel flawlessly through the shadows and needs only a very short time to recover before he can jump again. These jumps are almost effortless and require no concentration, thus can be made in combat.

%^BOLD%^See also:%^RESET%^ remember, recall");
    set_arg_required(1);
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(avatarp(TP)) { return 1; }

    if(ob->query_class_level("shadowdancer") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


int cmd_shadow_jump(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


string color_me(string str) { return  str = CRAYON_D->color_string(str, "very black"); }


void execute_feat()
{
    string destination, *destination_names = ({}), destination_file;
    mapping locations = ([]);
    object destination_room;
    int power, bonus;


    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!arg)
    {
        tell_object(caster,"You need to specify a destination");
        dest_effect();
        return;
    }

    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }

    ::execute_feat();

    locations = caster->query_rem_rooms();
    if(!mapp(locations) || !sizeof(keys(locations)))
    {
        tell_object(caster,"You don't seem to have any locations remembered");
        dest_effect();
        return;
    }

    destination_names = keys(locations);
    destination = arg;

    if(member_array(destination, destination_names) == -1)
    {
        tell_object(caster,"You don't have a location named "+destination+" remembered");
        dest_effect();
        return;
    }

    destination_file = locations[destination];

    if(catch(call_other(destination_file,"??")))
    {
        tell_object(caster,"There seems to be an error with the destination room.");
        dest_effect();
        return;
    }

    destination_room = find_object_or_load(destination_file);

    if(!objectp(destination_room) || !destination_room->is_room())
    {
        tell_object(caster, "Your destination doesn't seem to be a room.");
        dest_effect();
        return;
    }

    if(!TELEPORT->object_can_be_teleported(caster,destination_room,clevel + roll_dice(1, 20)))
    {
        tell_object(caster,"You notice some kind of interference preventing you from shadow jumping.");
        dest_effect();
        return;
    }

    caster->clear_followers();
    caster->setAdminBlock();

    tell_object(caster,color_me("You step into the shadows and feel the inky embrace of darkness worming its "
        "way into your very soul."));
    tell_object(caster,color_me("The shadows whisper soothing words of comfort and reassurance to you as your "
        "physical form is torn asunder without pain or sound and you become one with the shadows."));

    tell_room(destination_room,"There's a faint flicker of the shadows.",caster);

    call_out("move_caster",1, destination_room);
    return;

}


void move_caster(object dest)
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(dest))
    {
        tell_object(caster,color_me("Something has gone wrong with the destination.."));
        tell_object(caster,color_me("You can feel a rush of sensation as your physical form is reconstituted."));
        tell_object(caster,color_me("You remain where you were standing."));
        tell_room(place,"There's a faint flicker of the shadows.",caster);
        dest_effect();
        return;
    }

    if(!caster->query_invis()) { caster->set_hidden(1); }
    caster->move(dest);
    caster->removeAdminBlock();
    caster->force_me("look");
    tell_object(caster,color_me("You can feel a rush of sensation as your physical form is reconstituted."));
    tell_object(caster,color_me("You step silently from the shadows."));
    tell_object(caster,color_me("You have arrived at your destination."));

    dest_effect();
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        if(caster->queryAdminBlock())
        {
            caster->removeAdminBlock();
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
