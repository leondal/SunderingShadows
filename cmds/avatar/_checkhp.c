#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_checkhp(string str)
{
    object targ;
    int i,tmp,*rolls,level,x,y,z;

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"Syntax: checkhp <name>");
        return 1;
    }
    if(!objectp(targ=find_player(str)))
    {
        tell_object(TP,"checkhp only works on players who are currently online.");
        return 1;
    }
    if(avatarp(targ))
    {
        tell_object(TP,"checkhp works on mortals only.");
        return 1;
    }
    if(!pointerp(rolls = (int*)targ->query("hp_array")))
    {
        tell_object(TP,"This player hasn't rerolled new hitpoints yet.");
        return 1;
    }

    level = (int)targ->query_base_character_level();

    str = "Rolls: ";
    x = 30;
    for(i=1;i<level+1;i++)
    {
        x += rolls[i];
        str += (string)rolls[i];
        if (1 < i < (level+1) ) str += " [" + i + "], ";

    }

    tell_object(TP,"%^MAGENTA%^"+str[0..strlen(str)-3]+".");
    tell_object(TP,"%^MAGENTA%^Base rolls before mods: %^RESET%^"+x+"");

    tmp = (int)targ->query_stats("constitution");
    tmp = tmp - 10;
    tmp = tmp / 2;
    tmp = tmp * level;

    tell_object(TP,"%^MAGENTA%^Hitpoints from con: "+tmp+"");

    if(FEATS_D->usable_feat(targ,"toughness")) { y = level/2; }
    if(FEATS_D->usable_feat(targ,"improved toughness")) { y += level; }

    tell_object(TP,"%^MAGENTA%^Hitpoints from feats: "+y+"");

    z = y + x + tmp;

    tell_object(TP,"%^RED%^Total hitpoints: "+z+"");

    return 1;
}

int help()
{
    tell_object(TP,"Syntax: checkhp <name>\n"
        "  This command will calculate what a player's hitpoints should be before "
        "and after modifiers from constitution and feats.  This is the number "
        "that they should really have.");
    return 1;
}



    

    
