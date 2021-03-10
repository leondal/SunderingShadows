#include <std.h>
#include <objects.h>

inherit DAEMON;

int cmd_background(string str) {
    object ob;
    string dir;
    //added by saide to permit easy removal and
    //backing up in the case of mistakes
    if(str == "remove") {
        dir = "/d/save/background/";
        write("Background removed.");
        //cp(dir+lower_case(TP->query_name())+".htm",dir+"bkups/"+lower_case(TP->query_name())+".bak");
        rm(dir+lower_case(TP->query_name())+".txt");
        return 1;
    }
    ob = new("/cmds/mortal/backobj");
    ob->move(this_player());
    return 1;
}

void help() {
    write("
%^CYAN%^%^NAME%^%^RESET%^

background - edit or remove your in character background

%^CYAN%^%^SYNOPSIS%^%^RESET%^

background
background remove

%^CYAN%^%^DESCRIPTION%^%^RESET%^

The background you add is in-character public info any other character can read in libraries.

This may be anything that could exist in-character, from detailed biography of ancient elven house to reports on sightings of raging minothaur, or mysterious note left to strangers from shady character.

To remove your background type %^ORANGE%^<background remove>%^RESET%^.

%^CYAN%^%^SEE ALSO%^%^RESET%^

gossip, chfn, set, colors, emote
");
}
