#include <std.h>
#include "../../nereid.h"
inherit CALMLIGHT;

void create()
{
   ::create();
   "/d/koenig/riddle/rewards/b_bard.c"->create_instrument(TO);
}
