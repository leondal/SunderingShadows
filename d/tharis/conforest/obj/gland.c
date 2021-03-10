#include <std.h>
#include "../defs.h"
inherit OBJECT;

void create()
{
  ::create();
  set_name("%^RED%^an ettercap poison gland%^RESET%^");
  set_id(({"gland","poison gland","ettercap poison gland"}));
  set_short("%^RESET%^%^GREEN%^an ettercap poison gland%^RESET%^");
  set_long("%^RED%^The poison gland is very small, containing "+
	"very little poison.  The poison of an ettercap is very "+
	"toxic, and you imagine it would catch a nice price, if "+
	"you could find the right place to sell it to.");
  set_weight(1);
  set_value(200);
}
