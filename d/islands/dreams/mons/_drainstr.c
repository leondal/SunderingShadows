#include <std.h>
#include "../defs.h"

int cmd_drainstr(string str)
{
  object targ;
  targ = present(str,ETP);
  if (!"daemon/saving_d"->saving_throw(targ,"spell"))
  {
    tell_object(targ,"%^BOLD%^%^CYAN%^You stumble as the shadow lands "+
        "a hit on you.  As you catch your balance, you notice your limbs "+
        "feel as if they are made of lead.");
    tell_room(ETO,"%^BOLD%^%^CYAN%^"+TQCN+" staggers beneath the blow of "+
        "the shadow, and it seems to take a great deal of effort for "+
        ""+targ->query_objective()+" to get moving again.",targ);
    targ->add_stat_bonus("strength",-1);
    call_out("restore_strength",30,targ);
    return 1;
  }
  else
  {
    tell_object(targ,"%^CYAN%^You feel a chill rush down your "+
        "back as the shadow hits you, but nothing seems to happen.");
    tell_room(ETO,"%^CYAN%^"+TQCN+" seems to look a little dazed "+
        "as the shadow hits "+targ->query_objective()+", but "+TQCN+" "+
        "manages to shrug it off.",targ);
    return 1;
  }
}

void restore_strength(object targ)
{
  targ->add_stat_bonus("strength",1);
  tell_object(targ,"It feels as if a burden has been lifted from "+
	"your shoulders.");
  return 1;
}
