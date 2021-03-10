#include <std.h>
#include <move.h>
inherit PARMOUR;

void create()
{
   ::create();
   set_name("gem pouch");
   set_short("A velvet pouch");
   set_id(({"gem pouch","pouch","velvet pouch"}));
   set_long("This is a black velvet pouch that is best used for"+
   " carrying gems. The velvet helps protect the gems somewhat"+
   " from scratching and chipping.");
   set_lore("This black velvet pouch is quite fragile and "+
     "was obviously made for a noble.  The faint outline of a "+
     "letter 'K' can be seen still within the fabric, though "+
     "the stitching has long been pulled out.  You recall that "+
     "the family name belonging to the keep northeast of "+
     "Offestry was 'Kilgore' and surmise that the purse probably "+
     "belonged to a member of the noble family.");
   set_property("lore difficulty",7);
   set_weight(5);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_value(10);
   set_max_internal_encumbrance(8);
}

int query_size()
{
   if(!userp(ETO)) return 2;
   return ETO->query_size();
}
