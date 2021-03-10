//dex.c

#include <std.h>

inherit OBJECT;

void create(){
    ::create();

    set_name("%^GREEN%^A green crystal");
    set_short("%^GREEN%^A green crystal");
    set_id(({"wisdom","crystal","green crystal","wisdom crystal"}));
    set_long(
@OLI
   %^RESET%^%^GREEN%^The %^BOLD%^green light%^RESET%^%^GREEN%^ in this crystal moves with a deep contemplation. Every move feels thought through with great care. %^BOLD%^Age%^RESET%^%^GREEN%^ seems to dominate and common sense seems to lead.
OLI
   );

   set_value(3000);
   set_weight(10);
}

