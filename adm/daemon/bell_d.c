// bell_d.c daemon
// notify's admins that someone has rung one of the existing bells
// Pator@ShadowGate 
// Jan 13th 1997

#include <std.h>
#include <daemons.h>

inherit DAEMON;

void bell_notify(string str, object target) {
  int i,max,x;
  string s1,s2;

  object *who;
  who = filter_array(users(), "which_users", this_object(), target);
  max = sizeof(who);

    message("admin_bell",str+"\n",who);
  return;
  tell_object(target,"BOOH");
  if(max)
    for(i=0; i<max; i++) {
      tell_object(who[i],str+"\n");
    }
}

// Only arches will receive the admin_bell notify. If they are present they 
// will get the message anyway
int which_users(object who, object target) {
    if (!archp(who)) return 0;
    if(environment(target) == environment(who)) return 0;
    return 1;
}
