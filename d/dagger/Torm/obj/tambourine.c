#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("tambourine");
   set_short("A tambourine");
   set_id(({"tambourine"}));
   set_long("This is a rather uncommon instrument, but it is quite"+
   " useful, especially preferred by gypsies and is great to use"+
   " while dancing. It consists of a stretch of very thin dried hide"+
   " that has been pulled taut across a round circle of wood that has"+
   " been set with tiny pairs of steel symbols that clink together"+
   " to accompany the beating of the tambourine.");
   set_weight(3);
   set_value(2000);
}
int is_instrument(){return 1;}