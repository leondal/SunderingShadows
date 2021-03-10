#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_from(string str) {
  int i, j, found;
  mixed *coms;
  string *ret;

  if(!str || str == "?") {
    notify_fail("Usage: from <command>\n");
    return 0;
  }
    seteuid(UID_USERACCESS);
  coms = (mixed)this_player()-> local_commands();
  for(i = 0; i < sizeof(coms); i++) {
  if(coms[i][0] == str) {
    write(coms[i][0] + " is found in file: " + identify( coms[i][2] ) + "\n");
    ++found;
    return 1;
  }
  else if(coms[i][1] == "bincmd") {
    ret = (string *)this_player()->bincmd(str, 1);
    if(ret) {
      for(j = 0; j < sizeof(ret); j++) {
        write(ret[j] + "\n");
        found++;
      }
    }
  }
  }
  if(found) return 1;
  notify_fail(str + " not found.\n");
  return 0;
}

int help()
{
  write( @EndText
Syntax: from <command>
Effect: Gives the object in which added action <command> is defined in.
See man: commands
See also: localcmd
EndText
  );
  return 1;
}
