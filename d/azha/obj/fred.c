// Ring of Magic Protection
// Thorn@ShadowGate
// 970225
// ring_st.c

#include <std.h>

inherit "/std/armour";

int uses, old;
object protect;

int resist_magic();
int end_object();



create() {
  ::create();
  set_name("ring");
  set_id(({ 
  "ring", "ring of fred", 
  "golden ring", "gold ring" 
  }));
  set("short","a golden ring");
  set_long(
@AZHA
  This is a simple looking gold ring, worth a few gold pieces at
the market.  Looking carefully at it, you notice a few illegible
scratchings on the inside of the band, but nothing else.
AZHA
);
  set_type("ring");
  set_ac(0);
  set_weight(0);
  set("value", 25);
  set_limbs(({"right hand","left hand"}));
  set_wear((:TO,"do_wear":));
  uses = 4;
}

int do_wear()
{
	protect = TP;
	destruct(find_object("ring of magic protection"));
	return 1;
}

