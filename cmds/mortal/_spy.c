//Adjusted by Circe 6/4/07 so you cannot use blind
#include <move.h>
#include <std.h>
inherit DAEMON;

int cmd_spy(string str) {
    int check,silly;
    object ob;

    if(!str) {
    	notify_fail("Spy who?\n");
    	return 0;
    }

    if(TP->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }

    if (TP->query_blind()) {
        notify_fail("You are blind and cannot see anything.\n");
        return 0;
    }
    if (silly=TP->light_blind(0)) {
        notify_fail(TP->light_blind_fail_message(silly)+"\n");
        return 0;
    }

    if(ETP->query_property("no steal")) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0;
    }

    if(TP->query_current_attacker()) {
        notify_fail("You can't do that while in combat!\n");
        return 0;
    }

    ob = present(str, ETP);

    if(!ob) ob = parse_objects(ETP, str);

    if(!ob) {
        notify_fail("No "+str+" here!\n");
        return 0;
    }

    if((ob->query_hidden() || ob->query_magic_hidden()) && !TP->detecting_invis()) {
        return notify_fail("No "+str+" here!\n");
    }

    if(!living(ob)) {
	    notify_fail("Don't you feel silly?!?\n");
	    return 0;
    }

    if(wizardp(ob) && ob->query_invis()){
        notify_fail("No "+str+" here!\n");
        return 0;
    }

    if(ob->is_player() && !interactive(ob)) return 0;

    if(ob==TP) {
        notify_fail("You stubborn fool, that is stupid to do!\n");
        return 0;
    }

    if(!TP->is_class("thief") && !TP->is_class("bard")){
        notify_fail("You are not trained in such stealthy ways.\n");
        return 0;
    }

    check = TP->query_skill("stealth") - ob->query_skill("perception") - 10 + roll_dice(1,20);

    if(check < 0) {
	    message("mine",
	        "%^BOLD%^%^CYAN%^You fail to view "+ob->query_cap_name()+"'s "
	        "possessions.%^RESET%^"
	    ,this_player());

        message("ob",
	        "%^BOLD%^%^CYAN%^You notice "+this_player()->query_cap_name()+" admiring "
	        "your shiny possessions.%^RESET%^"
	    ,ob);

        message("env",
	        "%^BOLD%^%^CYAN%^You notice "+this_player()->query_cap_name()+" admiring "
	        +ob->query_cap_name()+"'s possessions.%^RESET%^"
	    ,environment(this_player()),({this_player(),ob}));
        return 1;
    }

	message("mine",
	    "%^BOLD%^%^CYAN%^Unknown to "+ob->query_cap_name()+", "
	    "you survey "+ob->query_possessive()+" possessions.%^RESET%^"
	,this_player());

    /*if(ob->id(str)) {
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
            write((string)ob->query_long(str));
        return 1;
    }*/

    //Less code and should do exactly the same thing.... Saide

    if(ob = present(str,ob) || ob = present(str,TP)
    || ob = present(str,ETP) || ob->id(str)) {
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
          write((string)ob->query_long(str));
          return 1;
    }

    write("%^BOLD%^%^RED%^You fail to glimpse anything!%^RESET%^");
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

spy - alternative to looking

%^CYAN%^SYNOPSIS%^RESET%^

spy TARGET

%^CYAN%^DESCRIPTION%^RESET%^

This will allow to survey TARGET's inventory. Without notifying them. Your success depends on your stealth and target's perception.

%^CYAN%^SEE ALSO%^RESET%^

steal, stealth, perception, pp, thief
");
}
