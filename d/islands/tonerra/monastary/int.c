//dex.c

#include <std.h>

inherit OBJECT;

void create(){
    ::create();

    set_name("%^BLUE%^A blue crystal");
    set_short("%^BLUE%^A blue crystal");
    set_id(({"intelligence","crystal","blue crystal","intelligence crystal"}));
    set_long(
@OLI
   %^RESET%^%^BLUE%^This %^BOLD%^blue crystal%^RESET%^%^BLUE%^ has a dull interior light. The light
moves much as a %^BOLD%^slow%^RESET%^%^BLUE%^ molasses. Each movement seems well thought out
and understood.
OLI
   );

   set_value(3000);
   set_weight(10);
}

