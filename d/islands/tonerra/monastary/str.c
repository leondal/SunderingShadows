//dex.c

#include <std.h>

inherit OBJECT;

void create(){
    ::create();

    set_name("%^RED%^A red crystal");
    set_short("%^RED%^A red crystal");
    set_id(({"strength","crystal","red crystal","strength crystal"}));
    set_long(
@OLI
   %^RESET%^%^RED%^The light from within this %^BOLD%^red crystal%^RESET%^%^RED%^ is dense, knotted.
It fights through each movement. It's
as if an internal struggle is %^BOLD%^burning%^RESET%^%^RED%^ against it.%^RESET%^
OLI
   );

   set_value(3000);
   set_weight(10);
}

