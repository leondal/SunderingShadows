//watch.c
#include <std.h>
inherit DAEMON;

#define WATCH_CONST 2

int cmd_watch(string str)
{
    int watched;

    if (archp(TP) && stringp(str)) {
        return 0;
    }
    watched = TP->query_watched();
    if (TP->get_static("last_watched") + WATCH_CONST >= time()) {
        return 1;
    }else {
        TP->set_static("last_watched", time());
    }

    if (file_size("/d/save/watching") > 150000) {
        cp("/d/save/watching", "/d/save/watching.old");
        rm("/d/save/watching");
    }
    if (base_name(TP) == "/std/user") {
        write_file("/d/save/watching", arrange_string(TPQN, 20) + " .... " + ctime(time()) + " .... " + watched + ".\n");
        if (watched > 50) {
            return notify_fail("You are watching your back for now. Stabbing you will be difficult.\n");
        }
    }
    TP->set_watched(4 * ((int)TP->query_skill("perception") + roll_dice(1, 20)));
    write("You are watching your back for now. Stabbing you will be difficult.");
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

watch - watch your back

%^CYAN%^DESCRIPTION%^RESET%^

Watch activates passive perception. In addition to that, while watching your back you get bonus in intercepting thief stabs.

%^CYAN%^SEE ALSO%^RESET%^

spot, stab, thief, perception
"
        );
}
