#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_kill(string str)
{
    object victim;
    int retvalue;   /* return value * / /* ORLY? */ /* YRLY! */
    int i;

    if (this_player()->query_ghost()) {
        notify_fail("You're already dead!\n");
        return 0;
    }

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (!str) {
        victim = TP->query_property("last_attacker");
        if (!(objectp(victim) && objectp(present(victim, ETP)))) {
            object* livings;

            livings = all_living(ETP);

            if (TP->query_party()) {
                object* party;

                party = PARTY_D->query_party_members(TP->query_party());
                livings -= party;
                livings -= collapse_array(party->query_followers());
            }

            livings -= (TP->query_followers() - TP->query_attackers());
            livings -= ({ TP });
            livings = filter_array(livings, (: !$1->query_true_invis() :));

            if (sizeof(livings)) {
                victim = livings[random(sizeof(livings))];
            }
        }
    } else {
        str = lower_case(str);
        victim = present(str, environment(this_player()));
    }

    if (!victim) {
        notify_fail("You don't see that here.\n");
        return 0;
    }

    if (victim == this_player()) {
        write("%^BOLD%^%^RED%^You pick up a knife and press it against own heart... The death will be swift and painless, if you choose to %^ORANGE%^<die>%^RED%^...%^RESET%^");
        input_to("choose_death");
        return 1;
    }

    if (!living(victim)) {
        notify_fail("That is not a living foe.\n");
        return 0;
    }
    /* check for an okay hit before we actually continue, Val */
    if (!(retvalue = (int)this_player()->kill_ob(victim))) {
        return 1;
    }

    if (!objectp(victim)) {
        return 1;
    }
    if(this_player()->is_deva())
    {
        //Cannot initiate combat against a non-evil enemy unless they are attacking a non-evil character themselves
        if(victim->query_true_align() % 3 &&
          (victim->query_current_attacker())->query_true_align() % 3)
        {
            tell_object(this_player(), "Your very nature resists causing harm to that being.");
            return 1;
        }
    }
    write("%^RED%^%^BOLD%^You attack " + (string)victim->query_cap_name() + "!");
    tell_room(ETP, this_player()->query_cap_name() + " attacks " +
              victim->query_cap_name() + "!", ({ victim, TP }));
    return retvalue;
}

void choose_death(string str)
{
    if (str == "die") {
        write("%^BOLD%^%^RED%^The choice have been made, may the gods forgive you...%^RESET%^");
        TP->add_death(capitalize(TP->query_name()));
        TP->die();
    } else {
        write("%^BOLD%^Alas! The life yet has some meaning. You put your pocket knife away.%^RESET%^");
    }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

kill - turn combat on

%^CYAN%^SYNOPSIS%^RESET%^

kill [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This sommand turns combat on for you and %^ORANGE%^%^ULINE%^TARGET%^RESET%^.

To kill yourself just use %^ORANGE%^<kill %^ORANGE%^%^ULINE%^YOURNAME%^RESET%^%^ORANGE%^>%^RESET%^.

Without an argument this command will start combat with random non-hostile non-ally.

%^CYAN%^SEE ALSO%^RESET%^

flee, score, hp, hit
");
}
