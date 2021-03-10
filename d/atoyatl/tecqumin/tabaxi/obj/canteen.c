#include <std.h>
#include "../../tecqumin.h"

inherit "/std/drink";

void create(){
  ::create();
  set_canSave(1);
  set_short("A water canteen");
  set_long("A medium sized water canteen, covered in a khaki fabric suitable for camouflage in a forest or jungle. It has a tightly fitting cork stopper.");
  set_strength(70);
  set_type("soft drink");
  set_my_mess("You tip back the canteen and drain it.");
  set_your_mess( TPQCN + " tips back " + TP->QP + " canteen and drinks deeply");
  set_id(({"drink", "water", "canteen", "water canteen"}));
  set_weight(1);
}
