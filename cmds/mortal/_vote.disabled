#include <std.h>

int cmd_vote(string str)
{
    write("%^GREEN%^-=%^BOLD%^< %^ORANGE%^Vote for Sundering Shadows%^GREEN%^ >%^RESET%^%^GREEN%^=-%^RESET%^");
    write(
"%^BOLD%^%^GREEN%^Please, consider voting for us to bring more people into the game:
 Top Mud Sites : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-tms%^RESET%^%^BOLD%^%^GREEN%^
You can view and follow us on the grapevine:
 Grapevine     : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/grapevine-sg%^RESET%^%^BOLD%^%^GREEN%^
"
        );
    if(str == "social")
    {
        write("%^GREEN%^-=%^BOLD%^< %^ORANGE%^Community sites%^GREEN%^ >%^RESET%^%^GREEN%^=-%^RESET%^");
        write("%^BOLD%^%^GREEN%^ This will need updating");
    }
    else
        write("%^BOLD%^%^GREEN%^Use %^RESET%^%^ORANGE%^<vote social>%^BOLD%^%^GREEN%^ to list social networks we are in.%^RESET%^");
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

vote - display voting information to help the game

%^CYAN%^SYNOPSIS%^RESET%^

vote [social]

%^CYAN%^DESCRIPTION%^RESET%^

This command will display ways for you to vote for the game on various listings to get the word out there and help to bring new players in!

Use <vote social> to list social networks Sundering Shadows is in.

%^CYAN%^SEE ALSO%^RESET%^

who, score, mail
"
        );
}
