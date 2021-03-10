#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("boy");
   set_id(({"boy","human","young man"}));
   set_short("A young man");
   set_long(
      "This young man seems to be no more than thirteen years "+
      "old.  He is thin but fairly strong for his age, and he "+
      "seems willing to do his share of the work around the village.  "+
      "He has long black hair worn tied back with a leather cord, "+
      "and his hazel eyes reveal a wisdom beyond his years.  He has "+
      "seen much hardship in his time."
      );
   set_gender("male");
   set_race("human");
   set_body_type("humanoid");
   set_hd(6,1);
   set_stats("strength",12);
   set_exp(1);
   set_emotes(5,({
      "The young man stokes the fire with an iron poker.",
      "The young man straightens the clothes on the shelf."
      }),0);
}
