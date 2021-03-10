#include <std.h>
#include <magic.h>

inherit "/d/darkwood/room/road2";

string *events = ({
        "%^BOLD%^%^CYAN%^On the side of the road, a %^ORANGE%^cat-morph beaskin girl%^CYAN%^ is surrounded by a group of children, nagging at her.",
            "%^BOLD%^%^CYAN%^Half-elf girl says:%^RESET%^%^CYAN%^ I want to have wings! Make me a fey! Make me a fay!",
            "%^BOLD%^%^CYAN%^Human boy shouts:%^RESET%^%^CYAN%^ I want to be a mighty warrior, give me a sword! And magic!",
            "%^BOLD%^%^CYAN%^%^ORANGE%^Beaskin%^CYAN%^ girl screams:%^RESET%^%^ORANGE%^ Stay away or I'll stab you! I will!",
            "%^BOLD%^%^CYAN%^Shade boy demands:%^RESET%^%^CYAN%^ I want everyone to suffer! Make everyone weak! And a monk! Except me!",
            "%^BOLD%^%^CYAN%^Gloomy half-orc girl whines:%^RESET%^%^CYAN%^ I want zombie puppies, now!",
            "%^BOLD%^%^CYAN%^Odd pale boy:%^RESET%^%^CYAN%^ Tell me a story about the eldritch darkness!",
            "%^BOLD%^%^CYAN%^Gloomy half-orc girl stomps:%^RESET%^%^CYAN%^ I want a story about zombie puppies!",
            "%^BOLD%^%^CYAN%^Half-elf girl says:%^RESET%^%^CYAN%^ I want cookies! And some naughty stories!",
            "%^BOLD%^%^CYAN%^Human girl pouts:%^RESET%^%^CYAN%^ I want to have a lot of magic and to be a witch, make me a witch!",
            "%^BOLD%^%^CYAN%^%^ORANGE%^Beaskin%^CYAN%^ girl screams:%^RESET%^%^ORANGE%^ Help me! Aaaaargh!",
            "%^BOLD%^%^CYAN%^%^ORANGE%^Beaskin%^CYAN%^ screams and starts running.",
            "%^BOLD%^%^CYAN%^Shade boy shouts:%^RESET%^%^CYAN%^ Don't let her get away!",
            "%^BOLD%^%^CYAN%^Children run after the %^ORANGE%^beastkin%^CYAN%^.",
    });
int event_counter = 0;

void create()
{
    ::create();
    set_exits( ([
        "north" : "/d/darkwood/room/road2",
        "south" : "/d/darkwood/room/road4",
    ]) );
}

init()
{
    ::init();

    if (!userp(TP)) {
        return;
    }

    if (random(1024)) {
        return;
    }

    if (!(find_call_out("do_events") != -1)) {
        call_out("do_events", ROUND_LENGTH / 2);
    }
}

do_events()
{
    if (event_counter >= sizeof(events)) {
        event_counter = 0;
        return;
    }

    tell_room(TO, events[event_counter] + "\n");
    event_counter++;

    call_out("do_events",ROUND_LENGTH / 2);
}
