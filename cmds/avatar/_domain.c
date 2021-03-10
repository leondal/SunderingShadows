#include <std.h>
#include <spell_domains.h>

int help();

int cmd_domain(string str)
{
    object target,symbol;
    string *domains,*info;
    
    if(!stringp(str)) { return help(); }
    info = explode(str," ");
    if(!sizeof(info)) { return help(); }
    if(!objectp(target = find_player(lower_case(info[0]))))
    {
        tell_object(TP,"Unable to find a player online named "+capitalize(info[0])+".");
        return 1;
    }
    if(sizeof(info) == 1)
    {
        tell_object(TP,"Possible domains for "+capitalize(info[0])+" are as "
            "follows: "+implode(SPELL_DOMAINS[(string)target->query_diety()]," ")+"\n");
        return 1;
    }
    if(info[1] != "clear") { return help(); }
    tell_object(TP,"Clearing domains for "+capitalize(info[0])+"");
    target->set_divine_domain(({}));
    if(symbol=present("holy symbol",target)) { symbol->refresh(); }

    return 1;
}

int help()
{
    write("\tSyntax <domain> <player_name> || <domain> <player_name> <clear> \n"
        "\t  When given only a player name as an argument, this command will \n"
        "\t  return a list of all the domains possible for their faith.  It  \n"
        "\t  does not take into account the ranger, paladin or antipaladin   \n"
        "\t  classes who have static domains however.  When used with the    \n"
        "\t  third parameter <clear>, it will remove all of the target's     \n"
        "\t  domains.  They can then pick them normally from their temple.   \n");
    return 1;
}


