#include <spell.h>
#include <magic.h>
#include <security.h>
#include <daemons.h>

inherit SPELL;

#define RESTRICTED_NAMES ({ "cleric", "fighter", "ranger", "mage", "paladin", "antipaladin", "thief", "bard", "assassin", "druid", "cavalier", "psion", "inform", "shout", "hm", "newbie", "wiz", "gwiz", "builder", "avatar", "discuss", "petition", "ambassador", "builder", "dev", "over", "law","arch","admin","elder" })

object *immortals;
string line_name;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("mindnet");
    set_spell_level(([ "psion" : 8 ]));
    set_discipline("telepath");
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS mindnet to TARGET");
    set_description("This power is otherwise known as mass telepathy. It will allow the psion to open a telepathy spell "
        "with more than one target at the same time.  Each target will be able to 'hear' the thoughts of the other targets in the "
        "mindnet.  The mindnet takes the game mechanic form of a line in the name that the caster has themselves recognized as."
        "\n\nThe actual name of the line is not considered to be IC information, but rather a mechanical method by which to "
        "facilitate the spell. The caster must cast the spell multiple times to add more targets to the spell, and each time they "
        "cast the spell on a new target, that target is added to the existing mind link.  It is possible for a person to be in "
        "two or more mindnets at the same time, but it is not possible for one caster to have two seperate mindnet spells under "
        "their control at the same time. The caster may remove a person from the mindnet at any time by using <mindnet remove "
        "target>.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
    seteuid(UID_SYSTEM);
    set_helpful_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^MAGENTA%^%^Touching your fingertips to "+
        "your temples, you lean your head back as you focus.");
    tell_room(place,"%^MAGENTA%^Touching "+caster->QP+" fingertips to "+
        ""+caster->QP+" temples, "+caster->QCN+" leans "+caster->QP+" head back.",caster);
    return "display";
}


int preSpell()
{
    object *net,*linked,mindnet;
    string *ignored;

    if(!arg)
    {
        dest_effect();
        return;
    }

    target = find_player(caster->realName(lower_case(arg)));

    if(!objectp(target))
    {
        tell_object(caster,"You can't make a connection with anyone named "+capitalize(arg)+".");
        return 0;
    }

    if(target->query_true_invis())
    {
        tell_object(caster,"You can't reach anyone named "+capitalize(arg)+".");
        return 0;
    }

    if(target->query_ghost())
    {
        tell_object(caster, "You can't reach anyone named "+capitalize(arg)+
        ".");
        return 0;
    }

    ignored = target->query_ignored();
    if (!ignored)
    {
        target->reset_ignored();
        ignored = target->query_ignored();
        if((member_array(caster->query_name(),ignored) != -1))
        {
            tell_object(caster,""+capitalize(arg)+" is ignoring you.\n");
            return 0;
        }
    }

    if(target == caster)
    {
        tell_object(caster,"You can't target yourself!");
        return 0;
    }

    if(target->query_property("mindnet"))
    {
        net = (object *)target->query_property("mindnet");
        if(member_array(caster,net) != -1)
        {
            tell_object(caster,"%^BOLD%^That target is already in your mindnet.");
            return 0;
        }
    }

    if(target->query_property("shapeshifted"))
    {
        if(!FEATS_D->usable_feat(target,"wild speech"))
        {
            tell_object(caster,"%^BOLD%^That target doesn't appear to be able to communicate with you.");
            return 0;
        }
    }

    mindnet = (object)caster->query_property("mindnetobj");
    if(objectp(mindnet)) { linked = mindnet->query_linked(); }
    else { linked = ({}); }

    if(member_array(target,linked) != -1)
    {
        tell_object(caster,"%^BOLD%^That target is alread in your mindnet.");
        return 0;
    }
    return 1;
}


int immortal_filter(object obj)
{
    if(!objectp(obj))                           { return 0; }
    if(!avatarp(obj))                           { return 0; }
    if(!obj->query("listen mindnet"))  { return 0; }
    return 1;
}


void spell_effect(int prof)
{
    object mindnet,*linked;
    int duration,i;

    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        dest_effect();
        return;
    }

    duration  = (ROUND_LENGTH * 5) * clevel;
    line_name = caster->knownAs(caster->query_true_name());

    immortals = children("/std/user.c");
    immortals = filter_array(immortals,"immortal_filter",TO);

    tell_object(caster,"%^CYAN%^You concentrate carefully on "+target->QCN+", allowing "
        ""+target->QO+" into your mind.");
    tell_object(target,"%^CYAN%^"+caster->QCN+"'s mind touches yours, opening a pathway "
        "for your thoughts.");

    if(!caster->query_property("mindnet host"))
    {
        if(member_array(lower_case(line_name),RESTRICTED_NAMES) != -1)
        {
            tell_object(caster,"That is a restricted line name, you can't create "
                "a mindnet with the name "+line_name+".");
            dest_effect();
            return;
        }
        if(sizeof(immortals))
        {
            for(i=0;i<sizeof(immortals);i++)
            {
                if(!objectp(immortals[i])) { continue; }
                if(!interactive(immortals[i])) { continue; }
                tell_object(immortals[i],"%^BOLD%^"+caster->QCN+" opens a new mindnet.");
                immortals[i]->unrestrict_channel(line_name);
                tell_object(immortals[i],"%^BOLD%^You can now use the "+line_name+" line.");
            }
        }
        mindnet = new("/cmds/priest/obj/mindnet_obj.c");
        caster->set_property("mindnetobj",mindnet);
        mindnet->move(caster);
        mindnet->add_linked(caster);
        mindnet->add_linked(target);
        mindnet->set_casting_spell(TO);
        mindnet->set_caster(caster);
        mindnet->set_line_name(line_name);
        caster->set_property("mindnet",({caster}));
        caster->set_property("mindnet host",1);
        target->set_property("mindnet",({caster}));
        addSpellToCaster();
        caster->unrestrict_channel(line_name);
        target->unrestrict_channel(line_name);
        tell_object(caster,"You can now use the "+line_name+" line.\n"
            "%^B_RED%^%^BOLD%^%^WHITE%^Please note that this is an IC line that represents a telepathy "
            "spell between multiple people.  Please RP accordingly.");
        tell_object(target,"You can now use the "+line_name+" line.\n"
            "%^B_RED%^%^BOLD%^%^WHITE%^Please note that this is an IC line that represents a telepathy "
            "spell between multiple people.  Please RP accordingly.");
        call_out("dest_effect",duration);
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
    else
    {
        mindnet = (object)caster->query_property("mindnetobj");
        target->set_property("mindnet",({caster}));
        mindnet->add_linked(target);
        target->unrestrict_channel(line_name);
        tell_object(target,"You can now use the "+line_name+" line.\n"
            "%^B_RED%^%^BOLD%^%^WHITE%^Please note that this is an IC line that represents a telepathy "
            "spell between multiple people.  Please RP accordingly.");
        linked = mindnet->query_linked();
        for(i=0;i<sizeof(linked);i++)
        {
            if(!objectp(linked[i])) { continue; }
            if(linked[i] == target) { continue; }
            if(linked[i] == caster) { continue; }
            tell_object(linked[i],"%^MAGENTA%^You can feel a slight change in the mindnet as "
                " another person joins.");
        }
    }
    spell_successful();
    return;
}


void dest_effect()
{
    object mindnet,*linked;
    int i;

    mindnet   = (object)caster->query_property("mindnetobj");

    if(!objectp(mindnet))
    {
        ::dest_effect();
        if(objectp(TO)) TO->remove();
    }

    linked    = mindnet->query_linked();
    line_name = mindnet->query_line_name();

    if(sizeof(linked))
    {
        for(i=0;i<sizeof(linked);i++)
        {
            if(!objectp(linked[i])) { continue; }
            if(linked[i] == caster) { continue; }
            tell_object(linked[i],"%^MAGENTA%^You feel a strange sensation as the "
                "mindnet collapses.");
            linked[i]->restrict_channel(line_name);
            tell_object(linked[i],"You can no longer use the "+line_name+" line.");
            linked[i]->remove_property_value("mindnet",({caster}));
        }
        tell_object(caster,"%^MAGENTA%^As your concentration is released, you "
            "can feel the mindnet collapse.");
        caster->remove_property("mindnet host");
        caster->restrict_channel(line_name);
        tell_object(caster,"You can no longer use the "+line_name+" line.");
        caster->remove_property_value("mindnet",({caster}));
    }

    if(sizeof(immortals))
    {
        for(i=0;i<sizeof(immortals);i++)
        {
            if(!objectp(immortals[i])) { continue; }
            if(!interactive(immortals[i])) { continue; }
            tell_object(immortals[i],"The "+line_name+" mindnet expires.");
            tell_object(immortals[i],"You can no longer use the "+line_name+" line.");
            immortals[i]->restrict_channel(line_name);
        }
    }

    if(objectp(mindnet)) mindnet->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
