#include <std.h>

inherit DAEMON;


int cmd_mats(string str)
{
    object player,*inv;
    int i, count;
    
    if(!objectp(TP) || !avatarp(TP)) { return 1; }
    
    if(!stringp(str) || !strlen(str))
    {
        tell_object(TP,"Syntax: mats <player>");
        return 1;
    }
    
    if(!objectp(player = find_player(str)))
    {
        tell_object(TP,"Can't find a player named "+str+" online.");
        return;
    }
    
    inv = deep_inventory(player);
    
    for(i=0;sizeof(inv),i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(!inv[i]->is_enchanting_material()) { continue; }
        count += inv[i]->query_count();
    }
    
    if(!count)
    {
        tell_object(TP, capitalize(str)+" doesn't seem to have any crafting materials.");
        return 1;
    }
    
    tell_object(TP, capitalize(str)+" has "+count+" crafting materials.");
    return 1;
}


int help()
{
    if(!avatarp(TP)) { return 0; }
    
    tell_object(TP,"Syntax: mats <player>\n"
        "Simple command to tell you how many crafting mats a player has.");
    return 1;
}