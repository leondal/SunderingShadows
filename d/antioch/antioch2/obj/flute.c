#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("flute");
   set_short("%^RESET%^A %^BOLD%^silver%^RESET%^ flute");
   set_id(({"flute","silver flute","instrument"}));
   set_long("This is a beautiful silver flute with twelve holes. Many"+
   " lovely melodies can be played on this instrument.");
   set_weight(1);
   set_value(600);
}
int is_instrument(){return 1;}