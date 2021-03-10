//updated by Circe 6/7/04 with new lore by Shar
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("muskrat pelt");
   set_short("A muskrat pelt");
   set_id(({"pelt","muskrat pelt","muskrat_pelt"}));
   set_long("This is the thick and shiny pelt of a large muskrat. An item like"+
   " this would probably be worth some money, tailors love to make"+
   " coats and hats out of such fine pelts.");
   set_lore(
@CIRCE
Muskrat has quickly become popular with many lower class people in Tabor.  The fur has a close resemblance to mink, a trim that is popping up on many garments of Tabors nobles.  Though it may look similar, there is clearly a world of difference.  
CIRCE
   );
   set_property("lore difficulty",5);
   set_value(50);
   set_cointype("silver");
   set_weight(2);
}
