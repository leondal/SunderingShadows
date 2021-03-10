#include <std.h>

 inherit "std/quest_ob";

 void create() {
   set_name("Treasury Quest");
   set_id( ({ "spoke","quest_object","Treasury Quest"}) );
   set_short("%^BOLD%^%^BLACK%^Spoke the %^RED%^tongue%^BOLD%^%^BLACK%^"
            +" of the D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i"
            +"%^BOLD%^%^BLACK%^ls");
   set_long("Spoke in the %^BOLD%^%^RED%^infernal%^RESET%^ language of"
           +" the D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i"
            +"%^BOLD%^%^BLACK%^ls %^RESET%^from the seventh Hell, in"
            +" order to gain access to the Archmagi's treasury");
   set_quest_points(10);
 }
