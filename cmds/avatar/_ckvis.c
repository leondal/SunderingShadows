#include <std.h>

inherit DAEMON;
int cmd_ckvis(){
    if(TP->query_invis()) {
      tell_object(TP, "You %^RED%^%^BOLD%^ARE%^RESET%^ invisible.");
      if (TP->query_true_invis()) tell_object(TP, "%^ORANGE%^True invisibility.");
      if (TP->query_magic_hidden()) tell_object(TP, "%^GREEN%^Magic Invisibility.");
      if (TP->query_hidden()) tell_object(TP, "%^BLUE%^Hiding in Shadows.");
      return 1;
    } else {
      tell_object(TP, "You aren't invisible.");
      return 1;
    }
    return 1;
}

int help(){
    write("Syntax: ckvis \n\n  Tells you if you are currently invisible or not.");
    return 1;
}
