//      /bin/dev/_vis.c
//      from the Nightmare mudlib
//      created by Descartes of Borg october 1992

#include <std.h>

inherit DAEMON;

varargs int cmd_slay(string str)
{
  object targ;
  if (!objectp(TP)||!objectp(ETP)){return 0;}
  targ = present(str, ETP);
  if (!objectp(targ)){
    notify_fail("That isn't here to be slain\n");
    return 0;
  }
  if (!living(targ)){
    notify_fail("You can only slay living things\n");
    return 0;
  }
  if (avatarp(TP) && interactive(targ)){
    notify_fail("You can't slay players - only mobs & NPCs. You"
                    +" still you have to kill players by hand.\n");
    return 0;
  }
  if (avatarp(targ)) {
    notify_fail("You can't slay avatars or above with this command.");
    return 0;
  }
  
  targ->die(TP);
  tell_object(TP, "You slay " + str);
  return 1;
}


int help()
{
  write( @EndText
Syntax: slay <target>
Effect: Causes the target to die. Target must be alive, in the room with
        you and not a player or immortal.
       
        This is intended for use in plots and stuff when you need
        something to just keel over dead. Feel free to use your own
        echoes or whatever to explain the death.
EndText
  );
  return 1;
}
