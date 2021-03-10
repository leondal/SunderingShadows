#include <std.h>
inherit OBJECT;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create(){
  ::create();
  set_name("gold crown");
  set_id(({"crown","gold crown","tiny gold crown",
    "crownriin"}));
  
  set_short("%^YELLOW%^tiny golden crown%^RESET%^");
  set_long("%^YELLOW%^This tiny golden crown would "+
"make a fairly good sized child's ring, but would look "+
"very silly on someone's head.  Unless they were only a "+
"foot or so tall.  Maybe this belonged to some sort of "+
"sprite or fairy.  If you could find them, you might get "+
"a reward for returning it!%^RESET%^");
  
  set_weight(1);
  set_value(100);
}
