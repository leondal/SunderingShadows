// Modified by Pator@Shadowgate
// August 25 1995
//Circe 7/23/05 - changed spell interrupted to spell interrupt - spell interrupted won't work
//Colors and helpfile updated by ~Circe~ 4/24/08
#include <daemons.h>
#include <spell.h>

inherit SPELL;

object *targets;
string lang;
mapping length;
int count;


void create()
{
    ::create();
    set_spell_name("forgotten melody");
    set_spell_level(([ "bard" : 4, "mage":4]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS forgotten melody on TARGET in LANGUAGE");
    set_description("This spell has the caster singing the beginning of a catchy tune.  The tune gets locked in the head "
        "of the target listeners.  This prevents them from doing anything involving concentration due to their infatuation with "
        "the song.  The caster does not have to continue singing, as the spell's effects are that the targets become lost in "
        "trying to figure out the tune.");
    mental_spell();
    splash_spell(2);
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_arg_needed();
}


int preSpell()
{
    string t;
    if(sscanf(arg,"%s in %s",t, lang) != 2)
    {
        tell_object(caster,"Chant forgotten melody on TARGET in LANGUAGE");
        return 0;
    }
    target = present(t,place);
    if (!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^MAGENTA%^The words to a familiar song fill "+
        "your mind as you start to hum.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" starts to hum.",caster);
    return "display";
}


void spell_effect(int prof)
{
    object *inven;
    int i;

    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" raises "+caster->QP+" "+
        "voice in a vaguely familiar song.",caster);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^You raise your voice in a strangely"+
        " familiar song.");
    spell_kill(target,caster);

    inven = target_selector();
    targets = ({});

    for (i=0;i<sizeof(inven);i++)
    {
        if ((int)inven[i]->query_lang(lang) < 50)
        {
            tell_object(inven[i],"%^BOLD%^%^MAGENTA%^You hear a song, but it's in"+
                " a strange language.");
            continue;
        }

        if(do_save(inven[i]))
        {
            tell_object(inven[i],"%^BOLD%^%^MAGENTA%^You hear the song and are momentarily"+
                " captivated by it, but it flees your mind.\n");
            continue;
        }

        if(mind_immunity_damage(inven[i], "default"))
        {
            continue;
        }

        targets += ({inven[i]});
    }

    length = ([]);

    for (i=0;i<sizeof(targets);i++)
    {
        tell_object(targets[i],"%^BOLD%^%^MAGENTA%^You hear the song, its refrain rolling"+
            " over in your head.  You begin to wonder about it...repeat it...but "+
            "you can't quite find the words.");
        tell_object(caster,"%^BOLD%^%^MAGENTA%^"+targets[i]->QCN+" has been "+
            "caught in your song's web.");
        if(interactive(target))
        {
            targets[i]->set_static("spell interrupt","%^BOLD%^%^CYAN%^You can't concentrate"+
                " on anything but this song that's stuck in your head.");
        }
        else
        {
            targets[i]->set_property("spell interrupt","%^BOLD%^%^CYAN%^You can't "+
                "concentrate on anything but this song that's stuck in your head.");
        }
    }
    call_out("next",8);
}


void next()
{
    int i;
    object *done;
    count++;
    done = ({});
    for (i=0;i<sizeof(targets);i++)
    {
        if (!objectp(targets[i]))
        {
            done += ({targets[i]});
            continue;
        }
        if (count > (int)targets[i]->query_stats("intelligence"))
        {
            tell_object(targets[i], "%^BOLD%^%^MAGENTA%^You finally get that song out of your head.");
            done += ({targets[i]});
            targets[i]->set_static("spell interrupt",0);
            targets[i]->remove_property("spell interrupt");
            continue;
        }
        tell_object(targets[i], "%^MAGENTA%^You continue to fight "+
            "with the song.  What %^BOLD%^are %^RESET%^%^MAGENTA%^its words?");
    }
    targets -= done;
    if (sizeof(targets) == 0)
    {
        dest_effect();
        return;
    }
    call_out("next",8);
}


void dest_effect()
{
    int i;
    remove_call_out("next");

    for (i=0;i<sizeof(targets);i++)
    {
        if(!objectp(targets[i])) { continue; }
        tell_object(targets[i], "%^BOLD%^%^MAGENTA%^You finally get that song out of your head.");
        targets[i]->set_static("spell interrupt",0);
        targets[i]->remove_property("spell interrupt");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
