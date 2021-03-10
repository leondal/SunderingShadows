#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

int if_night();
void create()
{
    ::create();
    set_name("Threndil");
    set_short("Threndil, the provisioner");
    set_id(({ "Threndil", "threndil", "provisioner" }));
    set_long("Threndil is a large, well muscled voadkyn.  " +
             "He seems to be spending much of his time polishing " +
             "the various armors and weapons that he sells, before " +
             "returning them to the sacks at his feet.  A large " +
             "winesack dangles from his belt.");
    set_gender("male");
    set_race("voadkyn");
    set_body_type("human");
    set_hd(19, 2);
    set_alignment(7);
    set_max_hp(200 + random(50));
    set_hp(query_max_hp());
    set_level(19);
    set_overall_ac(0);
    set_class("ranger");
    set_mlevel("ranger", 19);
    set_hd(19, 2);
    set_exp(10);
    set("aggressive", 0);
    set_storage_room(INC + "shop");
    if (query_night() == 1) {
        set_emotes(7, ({
            "Threndil says:  %^CYAN%^Nothing like a good drink " +
            "after a long day.%^RESET%^",
            "Threndil lays down upon his mat, stretching tiredly.",
            "Threndil takes a long drink from his wineskin."
        }), 0);
    }else {
        set_emotes(7, ({
            "Threndil says:  %^CYAN%^I've collected several " +
            "nice pieces of equipment in my day.  Care to take a " +
            "look at any?%^RESET%^",
            "Threndil idly polishes a very large sword.",
            "Threndil sorts through a few of the sacks, searching " +
            "for something."
        }), 0);
    }
}

__List(str)
{
    if (!if_night()) {
        return 1;
    }
    return ::__List(str);
}
__Buy(str)
{
    if (!if_night()) {
        return 1;
    }
    return ::__Buy(str);
}
__Sell(str)
{
    if (!if_night()) {
        return 1;
    }
    return ::__Sell(str);
}
__Show(str)
{
    if (!if_night()) {
        return 1;
    }
    return ::__Show(str);
}
__Value(str)
{
    if (!if_night()) {
        return 1;
    }
    return ::__Value(str);
}
int if_night()
{
    if (query_night() == 1) {
        command("say Listen, I don't know where yer from...\n");
        command("say But around here, we don't work all day " +
                "just to work the whole night through.\n");
        command("say Why don't ya do what I'm gonna do..." +
                "drink until I pass out, then we can talk in the " +
                "morning.\n");
        return 0;
    }
    return 1;
}
