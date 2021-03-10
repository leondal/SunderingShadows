//      /bin/user/_wimpy.c
//      from the Nightmare mudlib
//      for wimping out, easy to change to set specific percents
//      but I do not believe in that, so this just toggles on or off
//      created by Descartes of Borg 10 may 1993
//  setting max due to abuses and fixing up help file *Styx*  11/14/04

#include <std.h>

inherit DAEMON;

int max;

int cmd_wimpy(string arg) {
    string toggle;
    int percent, max, setting;
    max = 50;  // setting one variable to be used for easier maintenance *Styx*

    if(!arg){
	setting = TP->query_wimpy();
       if (setting > max) {
	  write("Due to varieties of abuse, setting higher than "+max+" % is "
		"no longer allowed.\n  Continued abuse even with the lower max "
		"may result in severe punishment for the offender.");
	  "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" had wimpy set at "+setting+
		", auto. set to "+max+".  Watch for abuse.");
          this_player()->set_wimpy(max);
        }
	write("Wimpy = "+TP->query_wimpy());
        return 1;
    }
    if (sscanf(arg, "%s %d", toggle, percent) != 2) {
        toggle = arg;
    }
    if (toggle != "on" && toggle != "off") {
        notify_fail("Syntax: <wimpy [on|off] <percent>>\n");
        return 0;
    }
    if (toggle == "off") {
        write("Brave mode.\n");
        this_player()->set_wimpy(0);
    } else {
       if (!percent)   percent = 25;

 //      if (percent > 95 &&(int)TP->query_hp() < (int)TP->query_max_hp()) percent = 95;
       if (percent > 50) {
	  write("Due to varieties of abuse, setting higher than "+max+" % is "
		"no longer allowed.\n  Continued abuse even with the lower max "
		"may result in severe punishment for the offender.");
	  "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" deliberately tried to set wimpy "
              "at "+percent+" %.  Watch for abuse.");
	    percent = max;
       }
       TP->set_wimpy(percent);
       write("Wimpy mode on at "+percent+" %.\n");
    }
    return 1;
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

wimpy - manage automatic fleeing

%^CYAN%^SYNOPSIS%^RESET%^

wimpy [on [%^ORANGE%^%^ULINE%^PERCENT%^RESET%^]]
wimpy off

%^CYAN%^DESCRIPTION%^RESET%^

Wimpy allows you to automatically flee from combat when your hit points are reduced below the % of your total you have specified with the command. Of course, some combat circumstances make it possible to lose more than that % in one shot, so this is not fail safe.

Without an argument, this command will display direction to run to.

To choose where to flee by default use %^ORANGE%^<wimpydir>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

wimpydir, flee, kill
");
}
