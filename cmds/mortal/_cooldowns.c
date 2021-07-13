/*
  cooldowns.c
  
  Shows your current cooldowns and time left.
  
  -- Tlaloc --
*/

#include <std.h>
#include <ansi.h>
#include <daemons.h>

//#define LINE sprintf("%s[ Cooldowns ]%s\n", "*=*=*=*=*=*", "*=*=*=*=*=*")
#define LINE "%^BOLD%^============[ %^CYAN%^Cooldowns%^WHITE%^ ]============%^RESET%^\n"

inherit DAEMON;

mixed cmd_cooldowns(string args)
{
    object who = this_player();
    mapping cooldowns;
    string *keys;
    int width;
    
    cooldowns = who->query_cooldowns();
    keys = keys(cooldowns);
    
    write("\n");
    write(LINE);
    
    if(sizeof(keys))
    {
        foreach(string str in keys)
        {
            tell_object(who, sprintf("   %s%-13s%s : %s%6d%s sec\n",YEL,capitalize(str),NOR,HIN,(cooldowns[str] - time()),NOR));
        }
    }
    else
        write("                %^BOLD%^None%^RESET%^\n");
    
    write(LINE);
    return 1;
}
    
    
    