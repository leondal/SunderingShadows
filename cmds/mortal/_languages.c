#include <std.h>
#include <daemons.h>
#include <clock.h>
inherit DAEMON;

int cmd_languages(string str)
{
    mapping skills;
    string* skillslist,
          skill,
          mylang;
    int freelang,
        usedlang,
        points,
        newtotal,
        grammar;
    int intbonus = BONUS_D->query_stat_bonus(TP, "intelligence");

    intbonus = intbonus < 1 ? 1 : intbonus;
    freelang = (TP->query_age() / 43200 + ((time() - TP->query_birthday()) / YEAR)) * intbonus;
    freelang = freelang > 500 ? 500 : freelang;
    usedlang = TP->query("used language points");
    skills = TP->query_all_langs();
    skillslist = sort_array(keys(skills), 1);

    if (!str) {
        tell_object(TP, "" + arrange_string("Language", 20) + arrange_string("prof. level", 15) + "\n");
        foreach(skill in skillslist)
        {
            tell_object(TP, "" + arrange_string(skill, 20) + arrange_string(skills[skill] + "(" + TP->query_grammar(skill) + ")", 15));
        }
        tell_object(TP, "%^GREEN%^You are currently speaking in %^BOLD%^" + TP->query_spoken() + ".\n");
        tell_object(TP, "%^ORANGE%^You have used %^BOLD%^" + usedlang + "%^RESET%^%^ORANGE%^ of your total %^BOLD%^" + freelang + "%^RESET%^%^ORANGE%^ language points.%^RESET%^");
        return 1;
    }
    str = lower_case(str);
    if (sscanf(str, "add %d to %s", points, mylang) != 2) {
        return notify_fail("See <help languages> for syntax.\n");
    }
    if (member_array(mylang, skillslist) == -1) {
        return notify_fail("You don't know " + mylang + ".\n");
    }
    if (points < 1) {
        return notify_fail("You can only add a positive number of points to a language.\n");
    }
    newtotal = skills[mylang] + points;
    if (newtotal > 100) {
        return notify_fail("There's no point taking a language above 100%.\n");
    }
    if ((usedlang + points) > freelang) {
        return notify_fail("You don't have that many free points to spend.\n");
    }
    grammar = (int)TP->query_grammar(mylang);
    TP->set_lang(mylang, newtotal);
    TP->set_grammar(mylang, grammar);
    TP->set("used language points", (usedlang + points));
    tell_object(TP, "%^BOLD%^%^WHITE%^You have increased your understanding of " + mylang + " by " + points + " points.%^RESET%^");
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

languages - manage your languages

%^CYAN%^SYNOPSIS%^RESET%^

languages add %^ORANGE%^%^ULINE%^NUM%^RESET%^ to %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will display languages you know.

With argument, you can add %^ORANGE%^%^ULINE%^NUM%^RESET%^ points you have accumulated to %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^ you already know.

You receive intelligence bonus of points (but no less than one point) of language points per eighteen hours of playtime and character age in years since the age you had at the time you have started playing. You are free to distrubute these points with 'add' subcommand, but someone must still give you basic understanding of the language, and there is no mechanical limit on the number of languages you can learn.

To choose a language you're currently using use %^ORANGE%^<speak>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

speak, teach, speech, line use, spoken languages
"
        );
}
