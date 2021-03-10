// Pator@ShadowGate
// Mei 8 1996
// Define if a player called name is 
// an allowed druid

#include <druids.h>
#include "/d/priest/mistletoe_allow.h"

int is_allowed(string name);
int is_allowed_wizard(string name);


int is_allowed(string name)
  { 
    if (is_allowed_wizard(name))
      { tell_player(this_player(),
            capitalize(name)+" is an allowed wizard\n");
      }
    else
      { tell_player(this_player(),
            capitalize(name)+" is not an allowed wizard\n");
      }
    return 1;
  }

int is_allowed_wizard(string name)
{    if ( member_array(name,ALLOWED_WIZ) != -1 ||
          member_array(DRUID_LEVELS[name],RESTRICTED_NAMES) != -1 )
            { return 1; }
        else
            { return 0; } }
