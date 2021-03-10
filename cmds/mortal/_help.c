/*    /cmds/mortal/_help.c
 *    from Nightmare IV
 *    the new help menu command interface
 *    created by Descartes of Borg 940420
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_help(string str) {
    string topic, category;
    int x;

    if(!str) str = "*player general";
    if((x = strsrch(str, "*")) != -1) {
        if(x < 2) topic = str;
        else {
            topic = str[0..x-2];
            category = str[x..strlen(str)-1];
	  }
      }
    else topic = str;
    topic = lower_case(topic);
    HELP_D->help(topic, category);
    return 1;
  }

void help() {
    write("
%^CYAN%^NAME%^RESET%^

help - get a helpfile to read

%^CYAN%^SYNOPSIS%^RESET%^

help [%^ULINE%^%^ORANGE%^TOPIC%^RESET%^] [%^ULINE%^%^ORANGE%^*CATEGORY%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Without arguments displays help menu.

If you pass a topic or topic with category you will be given help file on that topic within that category. Since come categories may have topics of the same name, you can specify both a topic and a category on the command line.

If you pass a category alone, you'll be given help menu on that category.

%^CYAN%^COMMAND SYNOPSIS%^RESET%^

When presented, a syntax %^ORANGE%^<>%^RESET%^ denotes a command is to be used within a paragraph of a help file, like %^ORANGE%^<help help>%^RESET%^ does in this very sentence.

Uppercase words represent words you need to replace in the command. For example, %^ORANGE%^<help %^ULINE%^TOPIC%^RESET%^%^ORANGE%^>%^RESET%^ means you'll need to replace %^ULINE%^TOPIC%^RESET%^ argument with your own. 

A brackets [%^ULINE%^%^RESET%^] are used to denote an optional argument. For example, %^ORANGE%^<help [%^ULINE%^TOPIC%^RESET%^%^ORANGE%^]>%^RESET%^ means you can run 'help' command with optional '%^ULINE%^TOPIC%^RESET%^' argument.

If you see | in a help file between two words, like in %^ORANGE%^<help feats>%^RESET%^, it means you must chose one of the two or several.

Multiple dots ... , like in %^ORANGE%^<help who>%^RESET%^, mean an argument of the type can be repeated multiple times.

%^CYAN%^EXAMPLES%^RESET%^

help
help help
help *player commands
help wake *player commands
");
}
