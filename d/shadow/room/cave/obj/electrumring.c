//electrumring.c
#include <std.h>

inherit ARMOUR;

string cur_mood;
string old_min;
int notify;
string owner;

void create()   {
 ::create();
  set_name("electrum cave ring");
  set_short("%^BOLD%^%^WHITE%^An %^CYAN%^electrum %^WHITE%^ring%^RESET%^");
  set_id(({"ring","cave ring","electrum ring"}));
  set_long("This ring is a simple electrum band that shimmers blue-white "+
    "in the light.  The outside is perfectly smooth, but inside, there seem "+
    "to be a few scratch marks of some kind.  Looking closer, you realize "+
    "it is a faded script you might be able to read.");
  set("read",
    "Smooth and shimmering my companions must be.");
  set_weight(0);
  set_value(0);
  set_type("ring");
  set_limbs(({"right hand","left hand"}));
  set_ac(0);
  
}
