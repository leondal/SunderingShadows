//

#include <std.h>

inherit ARMOUR;

void create(){
   ::create();
   set_name("Signet Ring");
   set_id(({"alliance ring","ring","signet ring", "alliance monster ring"}));
   set_short("Silver Signet Ring");

   set_long(
@OLI
   This is a small silver signet ring. Its sealing mark is one of a
pair of gauntlets shaking hands. This ring represents the agreement 
that various factions of knights and warriors and magicians dedicated
to good have to fight for good. This symbol represents the strength in
this collaboration.
OLI
   );
   set_type("ring");
   set_limbs(({"right hand"}));

   set_weight(1);


}

