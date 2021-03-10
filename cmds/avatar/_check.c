#include <std.h>
#include <daemons.h>

inherit DAEMON;


int cmd_check(string str)
{
    object obj, player;
    string item, name;
    int num;
    
    if(!stringp(str))
    {
        tell_object(TP,"Syntax: check <item> || check <item on player>");
    }
    
    if(sscanf(str, "%s %d on %s", item, num, name) == 3)
    {
        player = find_player(name);
        if(!objectp(player))
        {
            tell_object(TP,"Can't find player: "+name+" online.");
            return 1;
        }
        obj = present(item+" "+num,player);
        if(!objectp(obj))
        {
            tell_object(TP,""+player->QCN+" doesn't seem to have an "+item+" "+num+".");
            return 1;
        }            
    }    
    else if(sscanf(str,"%s on %s",item, name) == 2)
    {
        player = find_player(name);
        if(!objectp(player))
        {
            tell_object(TP,"Can't find player: "+name+" online.");
            return 1;
        }
        obj = present(item,player);
        if(!objectp(obj))
        {
            tell_object(TP,""+player->QCN+" doesn't seem to have an "+item+".");
            return 1;
        }
    }   
    else
    {
        obj = present(str,TP);
        if(!objectp(obj)) { obj = present(str,ETP); }
        if(!objectp(obj))
        {
            tell_object(TP,"Can't seem to find a "+str);
            return 1;
        }
    }
    
    if(!objectp(obj))
    {
        tell_object(TP,"Can't find a "+str+" anywhere.");
        tell_object(TP,"Syntax: check <item> || check <item on player>");
        return 1;
    }

    CHECK_D->item_check(obj,TP);
    return 1;
}


int help()
{
    tell_object(TP,"Syntax: check <item> || check <item on player>\n\n"
        "This command will check the bonuses for an item and will determine "
        "if they are in line with the standards for items.  I wasn't able to "
        "determine a way to test specials and other functions with the way "
        "that things are implemented now with everyone writing unique functions "
        "for weapons specials, so right now this command only tests item bonuses.  "
        "Keep in mind that weapons/armor with exceptionally good specials should "
        "be treated as if the special were a bonus.  The general rule of thumb for "
        "items is:\n\n"
        "Enchantment * 5 for MINIMUM level to wield, usually Enchantment * 7 for area its found in\n"
        "1 bonus for \"trash items\", items found without much difficulty and which are common.\n"
        "2 bonuses for solo boss type monsters, nearly always with at least one bonus reduced from max.\n"
        "More than 2 bonuses for group boss monsters that require a party to get for at level people.\n\n"
        "%^RED%^This command is in the testing phase, some of the numbers are likely to be adjusted.");
}