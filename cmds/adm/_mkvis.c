// /cmds/adm/_unvis.c
// Pator@ShadowGate, Feb 24th 1997
// This command will make all wizards visable in the present environment

#include <std.h>

int cmd_mkvis(int i) {
  object *whom;
  int size, count;

	// Only admins may use this command
  if (!archp(TP)) return 0;

  if (!i) i= -1;
  whom = all_inventory(environment(TP));
  size = sizeof(whom);
  for (count=0; count < size; count++) {
	if ( whom[count] == TP ) continue;
	if ( whom[count]->query_invis() ) {
		whom[count]->set_invis();
	if (i == -1)
	tell_player(whom[count], 
            "You have been made visable by an admin !");
	}
  }
 tell_object(TP, "Ok, made all the wizzes visable");
 return 1;
}
