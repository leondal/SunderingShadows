// Ring of Greater Magic Protection (for Wizzes only)
// Thorn@ShadowGate
// 000925
// agmr_ring.c

#include <std.h>

inherit "/std/armour";

int uses, old;
object protect;

int resist_magic();



create() {
  ::create();
  set_property("ring of magic protection", 1);
  set_name("ring");
  set_id(({
    "band", "ring of greater magic protection",
    "metal band", "tarnished band",
    "platinum ring", "ring", "glowing platinum ring"
  }));
  set("short","a tarnished band of metal");
  set_long(
@AZHA
  This band of metal looks like it was used for the ring to
a beggar's bed curtains.  It is tarnished and nicked in a 
few places and seems to have a greasy look to it.  This looks
like the sort of thing that mothers warn their children about
bringing in the house.
AZHA
);
  set_type("ring");
  set_ac(0);
  set_weight(0);
  set("value", 0);
  set_limbs(({"right hand","left hand"}));
  set_wear((:TO,"do_wear":));
  set_remove((:TO,"takeoff":));
}

int do_wear() {
  object *stuff, onering;
  int i,j, flag;
  
  if(!avatarp(TP)) {
    write("This band sputters and disappears as you try to wear it.");
    TO->remove();
  }
  protect = TP;
  old = protect->query_property("magic resistance");
  protect->remove_property("magic resistance");
  protect->set_property("magic resistance", 70);
  tell_object(TP, "%^BOLD%^The ring flashes brightly for a brief instant "+
    "%^BOLD%^on your finger and then fades to a steady glow.%^RESET%^");
  TO->set_short("a %^BOLD%^WHITE%^glowing%^RESET%^ platinum ring");
  TO->set_long(
@AZHA
  On your finger is revealed a glowing platinum ring pulsing with
a field of magic that seems to charge even the air around it.  Runes
of power glow on the surface where you originally saw what you thought
were nicks.
AZHA
  );
  return 1;
}

int takeoff()
{
  protect->remove_property("magic resistance");
  if(old) protect->set_property("magic resistance", old);
  TO->set("short","a tarnished band of metal");
  TO->set_long(
@AZHA
  This band of metal looks like it was used for the ring to
a beggar's bed curtains.  It is tarnished and nicked in a 
few places and seems to have a greasy look to it.  This looks
like the sort of thing that mothers warn their children about
bringing in the house.
AZHA
  );
  protect = 0;
  return 1;
}
