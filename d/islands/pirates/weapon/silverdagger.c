#include <std.h>
#include "../piratedefs.h"
inherit "/std/weapon";
create(){
    ::create();
set_id(({"silver","silver dagger","dagger"}));
    set_name("%^BOLD%^%^WHITE%^Silver Dagger%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Silver Dagger%^RESET%^");
set_long(
@FIZIE
%^BOLD%^%^WHITE%^This Dagger is about 3/4 of a foot long and its
blade is made entirely out of silver.
FIZIE
);
set_wc(1,3);
set_large_wc(1,3);
    set_weight(5);
set_size(1);
set_property("enchantment",1);
    set("value",1000);
set_type("piercing");
set_hit((: TO,"extra_hit" :));
    set_prof_type("small blades");
}
int extra_hit(object victem){
string victemrace;
if(!objectp(victem)) return 1;
victemrace = victem->query_race();
if(victemrace=="undead"||victemrace=="demon"||victemrace=="were-rat"){
tell_object(ETO,"Your %^BOLD%^silver dagger%^RESET%^ %^YELLOW%^flashes %^RESET%^as you strike your foe.");
tell_room(environment(ETO),"The silver dagger wielded by " +ETO->query_cap_name()+ " %^BOLD%^flashes %^RESET%^as it strikes "+victem->query_cap_name()+".",({ETO,victem}));
tell_object(victem,"The silver dagger wielded by "+ETO->query_cap_name()+" %^BOLD%^flashes%^RESET%^ as it strikes you.");
victem->do_damage("torso",roll_dice(4,5));
return 0;
}else 
return 0;
}
