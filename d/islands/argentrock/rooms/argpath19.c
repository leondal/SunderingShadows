#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

int blocked;

void create() {
    ::create();
    add_item("trunks","Some fallen %^GREEN%^trees%^RESET%^.");
    set_search("trunks","These dead trees block your sight. You need to "+
        "%^GREEN%^shove%^RESET%^ them aside.");
    set_exits( (["west":PATH+"argpath18"]) );
    blocked = 1;

    if(mobs) { make_creatures(); }
}

string query_long(string str){
    if (str == "trunks")
    {
        return ::query_long(str);
    }
    return ::query_long(str) + " There are some dead tree %^CYAN%^trunks%^RESET%^ laying to the east";
}

void init() {
    ::init();
    add_action("shove_trunks","shove");
}

int shove_trunks(string str) {
    if(!str) {
        notify_fail("You shove air across the empty space.\n");
        return 0;
    }
    if(str != "trunks") {
        notify_fail("You can't shove that!\n");
        return 0;
    }
    if(blocked != 1) {
        write("You shove the dead tree trunks aside.");
        say(TPQCN+" shoves the dead tree trunks aside.");
        return 1;
    }
    write("As you shove the dead tree trunks aside, you discover a "+
        "path behind them.");
    say("As "+TPQCN+" shoves the dead tree trunks aside, "+
        TP->query_subjective()+" discovers a path behind them.");
    add_exit(PATH+"argfoyer","south");
    blocked = 0;
    return 1;
}

void reset() {
    ::reset();
    if(blocked != 1) {
        remove_exit("path");
        blocked = 1;
    }
    if(mobs) { make_creatures(); }
    ::reset();
}

