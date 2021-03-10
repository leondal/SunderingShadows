#include <std.h>

int cmd_vote(string str)
{
    write("%^GREEN%^-=%^BOLD%^< %^ORANGE%^Vote for ShadowGate%^GREEN%^ >%^RESET%^%^GREEN%^=-%^RESET%^");
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
        write(
"%^BOLD%^%^GREEN%^ Discord     : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/discord-sg%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ Forum       : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://shadowgate.org/forum%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ Wiki        : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://shadowgate.org/wiki%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ Git         : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://shadowgate.org/git%^RESET%^%^BOLD%^%^GREEN%^");
        write("%^GREEN%^-=%^BOLD%^< %^ORANGE%^Social networks%^GREEN%^ >%^RESET%^%^GREEN%^=-%^RESET%^");
        write(
"%^BOLD%^%^GREEN%^ Mastodon    : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/toot-sg%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ Github      : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/github-sg%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ FaceBook    : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/fbook-sg%^RESET%^%^BOLD%^%^GREEN%^
%^GREEN%^-=%^BOLD%^< %^ORANGE%^Other Mudlistings%^GREEN%^ >%^RESET%^%^GREEN%^=-%^RESET%^
%^BOLD%^%^GREEN%^ Mudlistings : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-ml%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ TMC         : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-tmc%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^ Mudiverse   : %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-mv%^RESET%^%^BOLD%^%^GREEN%^
"            );
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

Use <vote social> to list social networks shadowgate is in.

%^CYAN%^SEE ALSO%^RESET%^

who, score, mail
"
        );
}
