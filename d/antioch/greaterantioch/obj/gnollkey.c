#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"key","gnoll key"}));
   set_name("gnollkey");
   set_obvious_short("%^RESET%^%^ORANGE%^A strong copper key%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^This average looking key seems well-used but still sturdy."
   );
   set_weight(1);
   set_value(5);
}
