#include <std.h>

#define YUCK_D "/daemon/yuck_d.c"

int cmd_restore(string str)
{
    object player;

    if(!avatarp(TP)) { return 1; }    

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"Syntax:  restore <player>");
        return 1;
    }
    
    str = lower_case(str);

    if(!objectp(player = find_player(str)))
    {
        tell_object(TP,"Can't find a player named "+str+" online, please "
            "check your spelling.");
        return 1;
    }

    if(!get_dir("/inv/backup_inv/"+player->query_name()[0..0]+"/"+player->query_name()+"/"))
    {
        tell_object(TP,"No backup currently exists for the player "+str+"");
        return 1;
    }

    tell_object(TP,"Attempting to restore "+str+"'s inventory...");
    YUCK_D->load_inventory(player,"/inv/backup_inv/"+player->query_name()[0..0]+"/"+player->query_name());
    tell_object(TP,"Done.");
    return 1;
}

int help()
{
    tell_object(TP,"Syntax:  restore <player>\n"
        "    This command will attempt to restore a player's inventory from the most recent "
        "backup.  Inventory is saved to the backup file once every 12 hours if they player "
        "logs in within the 12 hour period, else it saves whenever their inventory is next "
        "saved.  In the case of gear loss on crashes, it will usually have a copy of their "
        "equipment from the last 12 hours if they don't wait longer than that to ask for it.");
    return 1;
}