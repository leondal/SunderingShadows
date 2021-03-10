#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("maracas");
   set_short("A pair of maracas");
   set_id(({"maracas","pair of maracas"}));
   set_long("These are an unusual pair of instruments from a distant"+
   " land. They consist of two fairly identical gords that have a"+
   " rounded base but thin neck, that are filled with tiny seeds."+
   " They have been painted in bright reds and yellows and can be"+
   " shaken to create a nice rhythm and sound.");
   set_weight(4);
   set_value(1500);
}
int is_instrument(){return 1;}