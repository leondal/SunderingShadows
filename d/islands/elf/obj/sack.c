#include "../elf.h"

inherit "/d/common/obj/misc/sack.c";

void create(){
  ::create();
  set_id(({"sack","leaf sack"}));
  set_name("leaf sack");
  set_short("%^RESET%^%^GREEN%^leaf sack%^RESET%^");
  set_long("%^GREEN%^This is a large sack that is made"+
  " from thick leaves sewn together.  The "+
  "threading is very small so things will "+
  "not be able to fall out between the "+
  "leaves.  The sack is %^BOLD%^green%^RESET%^%^GREEN%^ with a %^ORANGE%^gold dyed "+
  "%^GREEN%^threading.  It smells like a fresh plant.  %^RESET%^ ");
  set_value(100);
  set_cointype("gold");
  set_max_internal_encumbrance(35);
}
