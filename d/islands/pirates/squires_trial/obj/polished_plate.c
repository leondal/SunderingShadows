#include <std.h>
#include "../squires_trial.h"

inherit "/d/common/obj/armour/lfullplate";

void create(){
	::create();
	set_name("polished plate");
	set_id( ({"plate","fullplate","full plate","large plate"}) );
	set_short("%^BOLD%^%^WHITE%^Polished Fullplate%^RESET%^%^WHITE%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Polished Fullplate%^RESET%^%^WHITE%^");
  set_long(
      "%^BOLD%^%^WHITE%^" +
      "This shining suit of armor is immaculately polished.  The " +
      "plate's form is magnificent, and most intimidating.  Master " +
      "metalworking was used to build this armor, and the joints " +
      "seem to strike a balance between mobility and protection.  " +
      "The chestpiece is emblazoned with a stylized image of a" +
      " %^BOLD%^%^BLACK%^falcon%^WHITE%^, " +
      "adding decoration to the otherwise mirror quality steel.  While the" +
      " main body of the armor is plate, the backing is steel chainmail and " +
      "soft but sturdy bleached leather.  An armor such as this must be a " +
      "grand treasure, and is quite heavy."
  ); 
  set_lore("This armor was crafted for a firbolg long ago as reward for " +
           "service to The Order of Ten.  Most records of the order were " +
           "destroyed when the order fell, but legend speaks of the " +
           "firbolg wading into fray with a courage undaunted by any " +
           "number of foes."
  );
  //I figured a 15,000 gold plate was a bit too much for the area
	set_value(5000);
	set_property("enchantment",2);
	set_size(3);
	set_property("lore difficulty",19);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme(object obj){
  if(!objectp(EETO)) return 0;
  tell_object(EETO, ETO->QCN + " settles the armor into place rolling " + 
              ETO->QP + " shoulders, with a satisfied nod.");
  tell_object(ETO,"You feel satisfied as the armor settles in to place.");
  return 1;
}

int removeme(object obj){
  if(!objectp(EETO)) return 0;
  tell_object(EETO, ETO->QCN + " removes the armor with dissatisfaction apparent");
  tell_object(ETO,"You feel dissatisfied as the armor slips away.");
  return 1;
}
