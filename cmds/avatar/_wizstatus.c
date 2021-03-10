//  Created by Ignatius, for ShadowGate
//  Coded 12 February, 1995
//  Renew Command - will dest an object in the users environment,
//                  update the master object, and clone another into 
//                  the users environment.

#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>
inherit DAEMON;

int cmd_wizstatus(string str) {
 
  object ob;
  string objname;
  int oldstatus, percent = 100;

  if(!str) {
    notify_fail("Syntax: <wizstatus [object] {percent}>, where [object] is the"
		+"object in your environment to be renewed.\n");
    return 0;
  }

  if (sscanf(str,"%s %d",objname, percent) != 2) {
    ob = get_object(str);
  } else {
    ob=get_object(objname);
  }

  if(!ob) {
    notify_fail("Object is not in you environment.  Look before you ask "
                "next time!!\n");
    return 0;
  }
 
  if(interactive(ob)) {
    notify_fail("Object is a living thing!!  You can't alter the status of that!!\n");
    return 0;
  }
  if (!intp(percent))
    percent = 100;

  oldstatus = ob->query_overallStatus();
  ob->set_overallStatus(percent);
  write(ob->query_name()+" status modified from "+oldstatus+" to "+percent+".");

return 1;
}

int help() {

  message("help",
@GARRETT
    Syntax: <wizstatus [object] {percent}>
    This command changes the status of the object to percent. If no status
    is given, then it is changed to perfect condition.  Please don't abuse
    this.

GARRETT
          ,this_player());
  message("help",
          "See also:  clean, clone, dest, update.\n",
          this_player());
return 1;
}
