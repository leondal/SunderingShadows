//	/bin/user/_follow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993

#include <std.h>

inherit DAEMON;



int cmd_follow(string str) {
    object ob,*ppl;
    string who;
    object ob2;
    int i;

    if (!str) {
        notify_fail("See <help follow>\n");
        return 0;
    }

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (sscanf(str, "allow %s", who) == 1) 
    {
        if(who == "all")
        {
            ppl = all_living(ETP);
            for(i=0;i<sizeof(ppl);i++)
            {
                if(!objectp(ppl[i])) { continue; }
                if(!ppl[i]->is_player()) { continue; }
                TP->follow_allow(lower_case(ppl[i]->query_name()));
                tell_object(ppl[i],"You have been invited to follow "+TP->QCN+".");
            }
            tell_object(TP,"Allowing everyone here to follow you.");
            return 1;
        }
        ob2 = present(who,ETP);
        if (!objectp(ob2) || ob2->query_invis()) {
            notify_fail("No "+capitalize(who)+" in our reality.\n");
            return 0;
        }
        if (interactive(ob2) && !TP->knownAs(ob2->query_name()) ) {
            return notify_fail("You need to recognize someone before you can allow them to follow you.\n");
        }
        write("You invite "+capitalize(who)+" to follow you.\n");
        this_player()->follow_allow(lower_case(who));
        if (avatarp(ob2)) TP->follow_allow(lower_case(ob2->query_name()));
        tell_object(ob2, "You have been invited to follow "+
                    this_player()->query_cap_name()+".\n");
        return 1;
    }
    ob = present(lower_case(str), ETP);
    if (!ob) {
        notify_fail("No one by that name around here.\n");
        return 0;
    }
    if (ob == TP) {
        notify_fail("You cannot follow yourself!\n");
        return 0;
    }
// added to prevent error if person trying to follow without permission isn't recognized *Styx*  12/24/02
    if (interactive(TP) && !(string)ob->knownAs((string)TPQN) )
        return notify_fail("You haven't been asked to follow "+capitalize(str)+"!\n");
    
    if (!interactive(TP)) {
        if (!ob->can_follow( TPQN )) {
            notify_fail("You cannot follow "+capitalize(str)+"!\n");
            return 0;
        }
    } else if (!ob->can_follow( lower_case( (string)ob->knownAs((string)TPQN) ) )) {
        notify_fail("You cannot follow "+capitalize(str)+"!\n");
        return 0;
    }
    if (!ob->add_follower(this_player())) {
        notify_fail("You cannot follow someone who is following you!\n");
        return 0;
    }
    write("You are now following "+capitalize(str)+".\n");
    tell_object(ob, this_player()->query_cap_name()+" is now following you.\n");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

follow - follow someone

%^CYAN%^SYNOPSIS%^RESET%^

follow %^ORANGE%^%^ULINE%^NAME%^RESET%^
follow allow [%^ORANGE%^%^ULINE%^NAME%^RESET%^|all]

%^CYAN%^DESCRIPTION%^RESET%^

This command will make you follow character %^ORANGE%^%^ULINE%^NAME%^RESET%^ that has allowed you to follow them. This means when they move to another room, so will you. You will be following in plain sight and not sneaking, so any traps %^ORANGE%^%^ULINE%^NAME%^RESET%^ bypasses won't be bypassed by you. You need to have %^ORANGE%^%^ULINE%^NAME%^RESET%^ %^ORANGE%^<recognize>%^RESET%^d to follow them.

Fo allow someone with name %^ORANGE%^%^ULINE%^NAME%^RESET%^ to follow you use %^ORANGE%^<follow allow %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^. The command keeps track of one invitation at a time, so you might want to use %^ORANGE%^<follow allow all>%^RESET%^ to form a larger group.

Though it is possible to form a follow chain, it might lag and move slower than party where everyone follows one leader. If that happens, try to follow just one leader.

If you want to loose someone, use %^ORANGE%^<ditch>%^RESET%^.

If you no longer want to follow your leader, use %^ORANGE%^<unfollow>%^RESET%^.

To list people following you type %^ORANGE%^<followers>%^RESET%^.

You might also want to form a %^ORANGE%^<party>%^RESET%^ as it will protect from harmful spells.

%^CYAN%^SEE ALSO%^RESET%^

unfollow, followers, ditch, party, recognize
"
         );
}
