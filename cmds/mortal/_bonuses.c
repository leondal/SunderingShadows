//    Coded by Grayhawk@Shadowgate
//    July 15, 1995

#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_bonuses(string str) 
{
    object targ;
    if(!objectp(TP)) return 0;
    if(avatarp(TP)) 
    {
        if(!objectp(targ = find_player(str))) targ = TP;
    }
    else targ = TP;
    if(targ != TP)
    {
        tell_object(TP, "The bonuses for "+capitalize(targ->query_name())+ " from gear are as follows: \n");
    }
    TP->more(EQ_D->all_active_bonuses(targ));
    return 1;
}

void help() {
    
    write("
%^CYAN%^NAME%^RESET%^

bonuses - display bonuses that affect you

%^CYAN%^DESCRIPTION%^RESET%^

This command will show you all bonuses from any gear that you have equipped, your saving throws,and any resistances that you have which are not zero.

If the gear is identified it will show you the bonuses from the specific piece of gear.

%^CYAN%^SEE ALSO%^RESET%^

score, stats, enchant, spellcraft
");

    if(avatarp(TP))
        write("
%^CYAN%^IMMORTALS SYNOPSIS%^RESET%^

bonuses [%^ORANGE%^%^ULINE%^PLAYER%^RESET%^]

");
}
