//      /bin/dev/_banish.c
//      from the Nightmare Mudlib
//      prevents a name being used by a new player
//      created by Descartes of Borg ???

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <daemons.h>

inherit DAEMON;

int cmd_banish(string str) {
   int flag;
   if (!str) {
      return TO->help();
   }
   if (str[0..0] == "*") {
      str= str[1..strlen(str)-1];
      flag = 1;
   }
   if(!user_exists(str = lower_case(str))) {
      seteuid(UID_BANISH);
      if (flag) {
         BANISH_D->set_illegal_substring(str);
         write(capitalize(str)+" is now a banished substring.\n");
      } else {
         catch(call_other(BANISH_D, "banish_name", str));
         write(capitalize(str)+" is now banished.\n");
      }
      seteuid(getuid());
   }
   else {
      write("A player by that name already exists.\n");
      write((string)FINGER_D->user_finger_display(str));
   }
   return 1;
}

void help() {
   write("Syntax: <banish [name]>\n\n"
         "Protects a name from being used by a new player.\n"
         "For example, if you have created a monster named Cassandra, in order\n"
         "to avoid problems with player complaining \"I typed 'kill\n"
         "cassandra' meaning to kill the evil enchantress, but Cassandra\n"
         "walked in and I accidentally killed here.\"  It is also to be\n"
         "used to keep people from using offensive names.\n"
        );
}
