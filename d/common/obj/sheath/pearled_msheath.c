#include <std.h>
inherit "/d/common/obj/sheath/sheath_medium.c";
//Made by Crystal for use in Aketon mostly, not for general stores, etc

void create()
{
   ::create();
   set_name("medium pearled sheath");
   set_short("%^BOLD%^%^WHITE%^A pearled medium sheath%^RESET%^");
   set_id(({"sheath","medium sheath","weapsheath","medium Sheath","pearled sheath","pearled medium sheath","medium pearled sheath"}));
   set_long("%^BOLD%^%^WHITE%^This is a medium weapons sheath that"+
   " has mother of pearl covering its exterior. There are adjustable"+
   " straps of white silk that can hold it to your body. In the"+
   " light the mother of pearl shines a beautiful, glossy white.%^RESET%^");
   set_value(1000);
}
