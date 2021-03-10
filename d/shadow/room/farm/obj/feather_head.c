#include <std.h>
inherit ARMOUR;

void create(){
	::create();
      set_name("headdress");
     	set_id(({"headdress","feather headdress","feathers"}));
      set_short("%^GREEN%^f%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^"+
         "%^RED%^t%^GREEN%^h%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^"+
         "%^RED%^ headdress%^RESET%^");
      set_long("This headdress is crafted of long feathers "+
         "in shades of %^BOLD%^%^BLACK%^black%^RESET%^, "+
         "%^RED%^red%^RESET%^, and %^GREEN%^green%^RESET%^.  "+
         "It has an iridescent finish that causes it to glitter "+
         "darkly in the light.  The have been arranged to form a "+
         "tall crown of sorts that covers most of the wearer's "+
         "head, in the fashion of some ancient cultures.  A single "+
         "long feather hangs down from a lanyard on either side of "+
         "the face, completing the look.");
      set_lore("Made from the feathers of a tom turkey, this "+
         "headdress is made in the style of those often favored "+
         "by the tribal peoples of ancient times.  Not much is "+
         "known about them, but their style of dress is "+
         "carried on somewhat in modern times, and some small "+
         "amount has been discovered through artwork.");
      set_property("lore difficulty",7);
      set_type("clothing");
      set_limbs(({"head"}));
      set_weight(3);
	set_size(-1);
      set_value(25);
      set_ac(0);
	if(!random(3)) set_property("enchantment",1);
}