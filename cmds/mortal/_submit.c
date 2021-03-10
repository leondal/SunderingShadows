// adapted from /cmds/mortal/_follow by Styx 10/2002

#include <std.h>

inherit DAEMON;

int cmd_submit(string str) {
   object ob;
   string what, who, syntax;
   string *pkills;
   object ob2;
   syntax = "Correct syntax is:  <submit to [binding | attack] by [whom]>\n";
   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str || (sscanf(str, "to %s by %s",what,who) != 2) )
      return notify_fail(syntax);
   if(what != "binding" && what != "attack")
      return notify_fail(syntax);

   ob2 = present(who,ETP);

   if(ob2 == TP) {        //need to exclude if who is them
      if(what == "binding")
         write("You can't bind yourself silly.");
      if(what == "attack")
         write("You don't need permission to attack yourself silly.");
      return 1;
   }

   if(!objectp(ob2))
      return notify_fail("You don't see "+capitalize(who)+" here.\n");
   if(ob2->query_true_invis() ||
      (ob2->query_invis() && !TP->detecting_invis()) )
         return notify_fail("You don't see that person here now do you?\n");


   if (!userp(ob2))
      return notify_fail("You can only submit to other PC's.\n");

   if((ob2->query_invis() && !TP->detecting_invis()) || ob2->query_true_invis())
      return notify_fail("You don't see "+capitalize(who)+" here.\n");

   switch(what) {
      case "binding":
         write("You submit to binding by "+capitalize(who)+".\n");
         TP->set_property("submit_bind",lower_case(who));
         tell_object(ob2, TPQCN+" has submitted to allow you to "
              "bind "+TP->query_objective()+".\n");
	 break;
      case "attack":
	 write("You have consented to allow "+capitalize(who)+" to attack you "
               "with no penalty to his/her alignment.  This is at your own "
	       "risk and will last until you die, log out, or a reboot.");
         tell_object(ob2, TPQCN+" has submitted to allow you to "
              "attack "+TP->query_objective()+".\n");
         TP->set_property("submitted_to",({ob2}) ); // added to prevent guards from protecting people who are sparring -Ares 09/13/05
// this is borrowed from stealing
//        if (interactive(TP)) { this is assumed for this
         pkills = TP->query_pkilled();
         if(member_array(ob2->query_name(),pkills) == -1) {
            pkills += ({ob2->query_name()});
            TP->set_pkilled(pkills);
         }
	 break;
   }
   log_file("player/kills", TPQN+" submitted to "+what+" by "+ob2->query_name()+
	    " on "+ctime(time())+"\n");
   return 1;
}

void help() {
   write(
"
%^CYAN%^NAME%^RESET%^

submit - allow someone to do something to you

%^CYAN%^SYNOPSIS%^RESET%^

submit to binding by %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

The bind option will allow the named person to bind you while you are still conscious.

%^CYAN%^SEE ALSO%^RESET%^

bind, unbing, gag, pkilling, rules, rope use
"
   );
}
