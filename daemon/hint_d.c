#include <std.h>
#include <security.h>

#define HFILE "/doc/help/user/hints"
#define FREQ 1260

inherit DAEMON;


void create()
{
    ::create();
    seteuid(getuid());
    display_hint();
}

int clean_up()
{
    return 1;
}

/**
 * Display random hint to everyone
 */
void display_hint()
{
    object* people, peep;
    people = filter_array(users(), (: !$1->query("no hints") :));
    if (sizeof(people)) {
        string* hints;
        string hint;
        if (!file_exists(HFILE)) {
            return;
        }
        hints = explode(read_file(HFILE), "\n"); // If hint file grows too big replace this one with line-by line read like in _grep
        hint = hints[random(sizeof(hints))];
        foreach(peep in people)
        {
            message("hint", "%^CYAN%^[%^GREEN%^Hint%^CYAN%^]%^RESET%^" + hint + "%^RESET%^", peep);
        }
    }
    call_out("display_hint", FREQ);
}
