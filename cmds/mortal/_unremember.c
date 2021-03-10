#include <std.h>
#define SYNOPSIS "Syntax:  unremember <location|object|monster> <remembered label>\n"

inherit DAEMON;

int cmd_unremember(string str){
    string what, where;
    int monster;
    mapping remmap;
    string *remsort;

    if(!str)
        return notify_fail("Unremember what?\n");
    if(sscanf(str, "%s %s", what, where) != 2)
        return notify_fail(SYNOPSIS);
    if(what != "location" && what != "object" && what != "monster")
        return notify_fail(SYNOPSIS);
    if(what == "location"){
       if(!remmap = TP->query_rem_rooms())
           remmap = ([ ]);
       if(!remsort = TP->query_rem_rooms_sort())
           remsort = ({ });

       if(member_array(where, remsort) == -1) {
           tell_object(TP, "You don't have that location memorized.");
           return 1;
       }

       remsort = distinct_array( (remsort - ({where})) );
       map_delete(remmap, where);
       TP->set_rem_rooms(remmap, remsort);
       tell_object(TP, "You concentrate and forget the location " + where + ".");
    }

    if (what == "monster") {
        if (sscanf(str, "monster %d", monster) != 1)
            return notify_fail(SYNOPSIS);
        if (!remmap = TP->query_study_mons())
            remmap = ([]);
        if (!remsort = TP->query_study_mons_sort())
            remsort = ({ });

        if (monster >= 0 && monster < sizeof(remsort)) {
            remsort = sort_array(remsort, 1);
            where = remsort[monster];
            remsort = distinct_array((remsort - ({ where })));
            map_delete(remmap, where);
            TP->set_study_mons(remmap, remsort);
            tell_object(TP, "You concentrate and forget about the creature " + where->query_short() + ".");
        }else {
            return notify_fail("That's not a valid option. " + SYNOPSIS);
        }
    }

    if(what == "object"){
        if(!remmap = TP->query_rem_obs())
           remmap = ([ ]);
       if(!remsort = TP->query_rem_obs_sort())
           remsort = ({ });

       if(member_array(where, remsort) == -1) {
           tell_object(TP, "You don't have that object memorized.");
           return 1;
       }

       remsort = distinct_array( (remsort - ({where})) );
       map_delete(remmap, where);
       TP->set_rem_obs(remmap, remsort);
       tell_object(TP, "You concentrate and forget the object "+where+".");

    }

    return 1;
}

void help() {
     write(
"
%^CYAN%^NAME%^RESET%^

unremember - forget something

%^CYAN%^SYNOPSIS%^RESET%^

unremember location|object|monster %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to forget locations, objects and monsters you have previvously remembered or studied.

If you're looking to how to forget preared spell check %^ORANGE%^<help forget>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

remember, recall, forget, nickname, study
"
          );
}
