#include <std.h>
#include <new_exp_table.h>

inherit DAEMON;

int help();

int cmd_recognize(string str)
{
    string who, as;
    object ob, * usrs;
    int x;

    if (TP->query_blind()) {
        return notify_fail("You can't see a thing!\n");
    }
    if (!str) {
        return help();
    }
    if(str == "all"){
       if(!avatarp(TP) && !TP->query("test_character")){
          tell_object(TP,"Sorry, only immortals can use this command.");
          return 1;
       }
       usrs = users();
       for(x = 0;x < sizeof(usrs);x++) {
           TP->addRelationship(usrs[x],usrs[x]->query_name());
       }
       write("All players online have been recognized.");
       return 1;
   }
    if (sscanf(str, "%s as %s", who, as) != 2) {
        return help();
    }

    if (!TP->query_time_delay("last_move", 10) && !newbiep(TP)) {
        return notify_fail("You struggle to memorize anyone, as you just arrived here.\n");
    }

    ob = present(who, ETP);
    if (!objectp(ob) || wizardp(ob)) {
        return notify_fail("There is no " + who + " here.\n");
    }else {
        if (userp(ob)) {

            if (ob->query_property("inactive")) {
                return notify_fail("You can't recognize inactive players.\n");
            }

            if(((ob->query_hidden() && !this_player()->true_seeing())||
            (ob->query_magic_hidden() && !this_player()->detecting_invis())) &&
             ob != this_player() &&
             !avatarp(this_player()))
            {
                return notify_fail("You do not notice that here.\n");
            }

            write("You will recognize " + who + " as " + capitalize(as) + ".");

            if (!newbiep(TP) && !(TP->isKnown(ob->query_name())) && ob != TP) {
                int expdelta;
                int thelevel = TP->query_level();

                expdelta = abs(EXP_NEEDED[thelevel + 1] - EXP_NEEDED[thelevel]) / 9;

                TP->set_property("ignore tax", 1);
                TP->add_general_exp(TP->query_classes()[0], expdelta);
                TP->remove_property("ignore tax");
            }

            TP->addRelationship(ob, as);

        }else {
            write("You can only recognize other players at this time.");
        }
    }
    return 1;
}

int help()
{
    write(
"%^CYAN%^NAME%^RESET%^

recognize - recognize someone

%^CYAN%^SYNOPSIS%^RESET%^

recognize %^ORANGE%^%^ULINE%^WHO%^RESET%^ as %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Allows you to recognize another player by an id, such as race, and assign them a %^ORANGE%^%^ULINE%^NAME%^RESET%^.

Recognizing someone for the first time grants you a small amount of exp towards next level.

You can recall list of recognized people with <recall relationships>.

%^CYAN%^SEE ALSO%^RESET%^

recall, who, mail
"
        );
    return 1;
}
