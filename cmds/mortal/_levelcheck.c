/*
#include <std.h>
#include <levelcheck.h>

int cmd_levelcheck(string str)
{
    object targ;

    if (!objectp(TP)) {
        return 0;
    }

    if (!str) {
        object * inv;
        object peep;
        string * output = ({});
        int i;

        inv = all_inventory(ETP);

        for (i = 0; i < sizeof(inv); i++) {
            peep = inv[i];

            if (!ETP->query_living_visibility(peep, TP)) {
                continue;
            }

            output += ({LEVELCHECK->levelcheck_string(TP, peep) + " " + peep->query_title()});
        }

        tell_object(TP,auto_format_page(output, TP, 34));

        return 1;
    }

    if (!(targ = find_player(TP->realNameVsProfile(str)))) {
        if (!(targ = present(str, ETP))) {
            return notify_fail("That person is not available for levelcheck.\n");
        }
    }

    if (avatarp(targ)) {
        return notify_fail("That person is not available for levelcheck.\n");
    }

    if (targ == TP) {
        write("%^BOLD%^%^WHITE%^You can use <kill " + TP->query_name() + "> to suicide freely.%^RESET%^");
        return 1;
    }

    switch (LEVELCHECK->levelcheck(TP, targ)) {
    case 1:
        write("%^BOLD%^%^ORANGE%^You can engage in adventuring with them, but can't player kill them.%^RESET%^");
        break;
    case 2:
        write("%^BOLD%^%^BLUE%^You can engage in player kill with them, but can't adventure with them.%^RESET%^");
        break;
    case 3:
        write("%^BOLD%^%^GREEN%^You can engage in adventuring and player kill with them.%^RESET%^");
        break;
    default:
        write("%^BOLD%^%^RED%^You can't engage in adventuring and player kill with them.%^RESET%^");
        break;
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

levelcheck - check if you're within level range

%^CYAN%^SYNOPSIS%^RESET%^

levelcheck [%^ULINE%^%^ORANGE%^TARGET%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This will run a levelcheck on %^ULINE%^%^ORANGE%^TARGET%^RESET%^ and will output the result in human readable form. Three outcomes are possible and should be self-explanatory, allowing you to engage in both player kill and adventuring, adventuring only, or disallowing you both types of activities with %^ULINE%^%^ORANGE%^TARGET%^RESET%^. Please refer to %^ORANGE%^<help pkilling>%^RESET%^ and %^ORANGE%^<help rules>%^RESET%^.

Without an argument this will display levelcheck info for everyone visible in current room. First levelcheck status will be displayed, followed then by character's name and description.

%^CYAN%^LEVEL CHECK FLAGS%^RESET%^

 %^RESET%^%^BOLD%^%^GREEN%^K%^RESET%^ in the end of the line indicates you're free to engage in player %^BOLD%^%^GREEN%^kill%^RESET%^ or adventures with that player.

 %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^ means you're free to %^YELLOW%^adventure%^RESET%^ only and are forbidden to engage in player kill due to recent death or flag changes.

 %^RESET%^%^BOLD%^%^BLUE%^P%^RESET%^ in the end of the line indicates you're free to engage in %^BOLD%^%^BLUE%^player kill%^RESET%^ with that player, but can't adventure with them.

 %^RESET%^%^BOLD%^%^RED%^F%^RESET%^ means you're %^BOLD%^%^RED%^forbidden%^RESET%^ to adventure and engage in unrestricted player kill with the player due to difference in levels.

The difference in power is defined by the weakest character. To engage in adventures and PK the difference must be less than 5 levels for characters below level 30 and 10 levels for characters above.

%^CYAN%^OTHER FLAGS%^RESET%^

 %^BOLD%^%^CYAN%^Q%^RESET%^ - quietness - before the name means this staff member is not accepting direct tells and is probably ignoring the lines.

 %^BOLD%^%^CYAN%^I%^RESET%^ - invisibility - before the name means this staff member is truly invisible. Players usually don't see this flag.

%^CYAN%^SEE ALSO%^RESET%^

rules, pkilling, who, threaten, flag
");
}
*/
