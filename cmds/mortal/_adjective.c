//_adjective

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_adjective(string str)
{
    object desc;

    desc = new(DESC_D);

    if (!interactive(TP)) {
        if(!str) { }
        else {
            if (strsrch(str, "$N") == -1) {
                str = "$N, "+str;
            }
            str = replace_string(str,"$N",capitalize(TP->query_name()));
            TP->set_short(str);
        }
    }
    else {

        if(!str) {

            write("You will now be seen as "+TP->getWholeDescriptivePhrase()+".");
            return 1;
        }

        TP->setDescriptivePhrase(str);

        desc->set_profile_stuff(str,"adjective",TP);

        write("You will now be seen as "+TP->getWholeDescriptivePhrase()+".");
    }
    return 1;
}

int help(){

    write("
%^CYAN%^NAME%^RESET%^

adjective - set short description of your character

%^CYAN%^SYNOPSIS%^RESET%^

adjective [%^ULINE%^%^ORANGE%^TEXT%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command sets short description or your character, a phrase that precedes you to a stranger when they observe a room and a line you can see in who list.

You are required to use automatic racial substitutions %^CYAN%^$R%^RESET%^, for your race, or %^CYAN%^$SR%^RESET%^ in the adjective. If you won't, %^CYAN%^$R%^RESET%^ will be appended to the end of your description.

In addition to that, you can use %^CYAN%^$G%^RESET%^ to put in your gender.

Your adjective should be something appropriate that someone could tell almost immediately about your character. It should also be fairly short and succinct as well as stable over reasonable periods of time.

For summons that can be commanded, you can use %^CYAN%^$N%^RESET%^ to place their name in the adjective, otherwise it will be prepended to the beginning of their adjective.

%^CYAN%^EXAMPLES%^RESET%^

$R with long hair

    A human with long hair, if you are a human.

$SR with blue hair

    A water genasi with blue hair, if your subrace is water genasi.

%^CYAN%^SEE ALSO%^RESET%^

describe, who, colors
");
}
