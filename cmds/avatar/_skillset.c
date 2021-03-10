#include <std.h>
inherit DAEMON;

int cmd_skillset(string str){
   string which, what;
   int how;

   if(!str) return notify_fail("Usage: skillset <skills/language> <amount> <skill>\n");
   if(sscanf(str,"%s %d %s",which, how, what) != 3)
      return notify_fail("Usage: skillset <skills/language> <amount> <skill>\n");

   switch (which) {
   case "skills":
      TP->set_skill(what,how);
      tell_object(TP,"%^BOLD%^Your proficiency in "+what+" is set to "+how+".");
      break;
   case "language":
      TP->set_lang(what,how);
      tell_object(TP,"%^BOLD%^Your knowledge of "+what+" is now about "+how+".");
      break;
   default:
      return notify_fail("Usage: skillset <thief/profs/language> <amount> <skill>\n");
   }
   return 1;
}


int help(){
   write(
@OLI
      Usage: skillset <skills/language> <amount> <skill>

      Use this skill to set your non-combat skills or
      languages. Please be careful when using this. If you have
      questions concerning spelling or terms, ask.
OLI
   );
   return 1;
}