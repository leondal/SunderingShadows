#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("tin whistle");
   set_short("%^RESET%^A tin whistle");
   set_id(({"whistle","tin whistle"}));
   set_long("This is a simple whistle made out of tin. There is a"+
   " spot on one end where you can blow through, and there are several"+
   " holes along the length of the instrument. It can be used to"+
   " create simple melodies and is good in accompaniment with another"+
   " instrument.");
   set_weight(2);
   set_value(300);
}

int is_instrument(){return 1;}