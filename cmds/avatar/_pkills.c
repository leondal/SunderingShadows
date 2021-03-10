#include <std.h>
#include <daemons.h>


int cmd_pkills(string str)
{
    int i,*kills;
    string *names=({}),name;
    object player;
    
    if(!avatarp(TP)) { return 0; }
    if(!stringp(str) || !strlen(str)) { return 0; }
    
    if(!objectp(player = find_player(str)))
    {
        tell_object(TP,"Can't find a player named "+str+" online.");
        return 1;
    }
    
    kills = player->query_kills();
    
    if(!sizeof(kills))
    {
        tell_object(TP,player->QCN+" doesn't seem to have killed anything yet, the slacker.");
        return 1;
    }
    
    for(i=0;sizeof(kills),i<sizeof(kills);i++)
    {
        name = PLAYER_D->query_monster(kills[i]);
        if(!name || !stringp(name) || !strlen(name)) { continue; }
        if(!user_exists(lower_case(name))) { continue; }
        names += ({ name });
    }
    
    if(!sizeof(names))
    {
        tell_object(TP,player->QCN+" either has never pkilled anyone, or "+player->QP+" victims are no longer in the game.");
        return 1;
    }
    
    tell_object(TP,player->QCN+" has killed the following players: \n");
    
    for(i=0;i<sizeof(names);i++)
    {
        tell_object(TP,"    %^RED%^"+capitalize(names[i]));
    }
    
    return 1;
}



int help()
{
    tell_object(TP,"Syntax: <pkills player>\n"
        "Will return a list of any players that <player> has killed.  "
        "This will only show players who still exist, and not old players "
        "who's character files no longer exist.");
    return 1;
}
