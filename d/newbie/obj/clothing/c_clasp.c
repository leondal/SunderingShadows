#include <std.h>
#include "../../newbie.h"
inherit ARMOUR;

#include <std.h>

#define DESIGNS ({"%^RED%^rose%^RESET%^",\
"%^YELLOW%^flowery%^RESET%^",\
"%^BOLD%^%^GREEN%^leaf%^RESET%^",\
"%^BOLD%^%^WHITE%^daisy%^RESET%^",\
"%^MAGENTA%^circular%^RESET%^",\
"%^CYAN%^geometric%^RESET%^",\
"%^BOLD%^%^CYAN%^triangular%^RESET%^",\
"%^BOLD%^%^BLUE%^square%^RESET%^",\
"%^ORANGE%^rectangular%^RESET%^",\
"%^BOLD%^%^MAGENTA%^butterfly%^RESET%^",\
"%^GREEN%^dragonfly%^RESET%^"})

int i, j, val;
string DESIGN;
void create_clasp()
{
   j = random(11);
   DESIGN = DESIGNS[j];
   val = random(5)+5;
   set_value(val+1);
   set_cointype("silver");
   set_type("ring");
   set_limbs(({"head"}));
   set_weight(1);
   set_name("hair clasp");
   set_id(({"hair clasp","clasp",""+DESIGN+" clasp",""+DESIGN+" hair clasp", 
	"silver hair clasp","silver clasp"}));
   set_short("%^BOLD%^%^WHITE%^silver hair clasp%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^The hair clasp is made out of solid sterling silver"+
   " that is highly polished and seems strong enough to hold even the"+
   " thickest of hair. The top has been crafted in a%^RESET%^ "+
   DESIGN+" %^BOLD%^%^WHITE%^design and"+
   " the underside is a clip that fastens on one end.");
   set_wear("You pull your hair back and carefully secure it with the clasp.");
   set_remove("You undo the clasp and your hair comes tumbling back down in your face.");
}


void create()
{
   	::create();
	create_clasp();	
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
