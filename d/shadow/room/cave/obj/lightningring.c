//lightningring.c
#include <std.h>

inherit ARMOUR;

string cur_mood;
string old_min;
int notify;
string owner;

void create()   {
 ::create();
  set_name("lightning cave ring");
  set_short("%^YELLOW%^A band of energy%^RESET%^");
  set_id(({"ring","cave ring","lightning ring","band"}));
  set_long("This band of yellow energy crackles and swirls, its "+
    "shades changing swiftly.  The energy seems to be encased in "+
    "some sort of smooth glass.  Tiny bolts streak across its surface, "+
    "seeming to spell out words.");
  set("read",
    "Boundless energy binds my friends to me.");
  set_weight(0);
  set_value(0);
  set_type("ring");
  set_limbs(({"right hand","left hand"}));
  set_ac(0);
  
}
