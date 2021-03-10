//leatherring.c
#include <std.h>

inherit ARMOUR;

string cur_mood;
string old_min;
int notify;
string owner;

void create()   {
 ::create();
  set_name("leather cave ring");
  set_short("%^RESET%^%^ORANGE%^A braided leather ring%^RESET%^");
  set_id(({"ring","cave ring","leather ring"}));
  set_long("A few strands of tanned leather have been braided together "+
    "to make this simple leather ring.  The plait is intricate, made with "+
    "six strands, but the ring itself is very narrow.  A message has been "+
    "burned into the inside of the ring.");
  set("read",
    "Strong as the earth and natural as the wind are my colleagues.");
  set_weight(0);
  set_value(0);
  set_type("ring");
  set_limbs(({"right hand","left hand"}));
  set_ac(0);
  
}
