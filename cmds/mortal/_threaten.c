#include <daemons.h>
#include <std.h>
#include <security.h>
#include <levelcheck.h>
inherit DAEMON;

int cmd_threaten(string str)
{
    object targ;
    string player;

    if(!str)
    {
        notify_fail("You need to specify a player name.\n");
        return 0;
    }

    if(!(targ = find_player(TP->realNameVsProfile(str))))
    {
        notify_fail("No such player found.\n");
        return 0;
    }

    if(!userp(targ))
    {
        notify_fail("This is not a player.\n");
        return 0;
    }

    if(newbiep(TP))
    {
        tell_object(TP,"%^YELLOW%^You can't PK as a newbie!%^RESET%^");
        return 1;
    }

    if(newbiep(targ))
    {
        tell_object(TP,"%^YELLOW%^You can't PK newbies!%^RESET%^");
        return 1;
    }

    switch(LEVELCHECK->levelcheck(TP,targ))
    {
    case 0:
        player = (string)targ->query_name();
        tell_object(TP,"%^BOLD%^%^CYAN%^You gather your most impressive and frightening look about you, hinting them that they are pushing their luck.\n%^YELLOW%^Give the player the benefit of a moment or two to RP an appropriate reaction. If they continue to provoke your character, you are within rights to instigate a PK situation with them.%^RESET%^");

        tell_object(targ,"%^BOLD%^%^CYAN%^"+TP->query_name()+" takes on a very threatening air towards you.\n%^YELLOW%^You get the impression that you are pushing your luck in provoking this character (see %^WHITE%^<help threaten>%^YELLOW%^). If you wish to continue to do so, you must be prepared to enter a pkill situation. Otherwise you will need to roleplay appropriate respect or fear of the player, or find an appropriate way to extract yourself from the situation.%^RESET%^");
        seteuid(UID_LOG);
        log_file("player/threaten","%^BOLD%^%^CYAN%^"+ctime(time())+"%^RESET%^: Threaten "
                 "command used by "+TP->query_name()+" against "+player+".\n");
        seteuid(getuid());
        return 1;
    case 1:
        tell_object(TP,"%^BOLD%^%^GREEN%^Just kill them, you're allowed.%^RESET%^");
        return 1;
    default:
        tell_object(TP,"%^BOLD%^%^RED%^You can't engage in PK with your target due to flags set.%^RESET%^");
        return 1;
        break;
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

threaten - warn a lower player that they are provoking you to PK

%^CYAN%^SYNOPSIS%^RESET%^

threaten %^ULINE%^%^ORANGE%^PLAYER%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

The command will run levelcheck to identify validity of the threat first, then if you're threatening lower player they will recieve a warning that their next action might result in Player Kill.

If %^ULINE%^%^ORANGE%^PLAYER%^RESET%^ continues to provoke you, you're free to engage in Player Kill.

Failure to warn a much lower level character may result in retcon and punishing, depending on the current Player Kill policy.

%^CYAN%^SEE ALSO%^RESET%^

pkilling, who, rules

");
}
