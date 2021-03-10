//      /bin/user/_divorce.c
//      from the Nightmare mudlib
//      allows a high mortal to divorce people
//      created by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_divorce(string str) {
    string a, b;
    object alpha, beta;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!avatarp(this_player())) return 0;

     if(!str) {
        notify_fail("Divorce whom from whom?\n");
        return 0;
    }
    if(sscanf(str, "%s from %s", a, b) != 2) {
        notify_fail("Divorce whom from whom?\n");
        return 0;
    }
    alpha = present(lower_case(a), environment(this_player()));
    beta = present(lower_case(b), environment(this_player()));
    if(!alpha && beta) alpha = find_player(lower_case(a));
    else if(!beta && alpha) beta = find_player(lower_case(b));
    if(!alpha || !beta) {
        notify_fail("Both parties must be online, with at least one present.\n");
        return 0;
    }
    if(a != (string)beta->query_married()) {
        notify_fail(capitalize(b)+" is not married to "+capitalize(a)+".\n");
        return 0;
    }
    if(b != (string)alpha->query_married()) {
        notify_fail(capitalize(a)+" is not married to "+capitalize(b)+".\n");
        return 0;
    }
    write("You legally divorce "+capitalize(a)+" from "+capitalize(b)+".\n");
    say(capitalize(a)+" and "+capitalize(b)+" are no longer joined in marriage.\n");
    alpha->divorce_me();
    beta->divorce_me();
    if(present("band", alpha)) present("band", alpha)->remove();
    if(present("band", beta)) present("band", beta)->remove();
    return 1;
}

void help() {
    write("Syntax: <divorce [player] from [player]>\n\n"
      "Performs a legal divorce of the first player from the second.\n"
      "This requires that at least one of the parties be present, and\n"
      "that both be online.\n"
    );
}
