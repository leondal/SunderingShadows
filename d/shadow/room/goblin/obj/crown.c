// str bonus changed to work on new stat system. Nienne, 09/07.
#include <std.h>
inherit "/std/armour";

nosave int flag;

create() {
    ::create();
    set_name("royal goblin crown");
    set_id(({"crown","goblin crown","king's crown"}));
    set_short("%^BOLD%^%^BLACK%^Iron crown%^RESET%^");
    set_property("repairtype",({ "jewel" }));
    set_long("This twisted pronged crown has clearly seen better days.  The crown looked as if at one time it might have been a dazzling thing.  The skeletal remains of where the jewels and decorations of the crown is all "
"that remains on the rusting and weather beaten iron surface.  The crown is set onto a padded silken cap, more for comfort than anything.  Though even this silk is flea and scum infested.  %^GREEN%^Ick%^RESET%^!");
    set_lore("The crown once belonged to the fame gnomish king of Grustenrvard Estevanre Kermitest Alliwishes Greenwolf Badgerlord Sparklesilver, the 12th.  King Gek, as he was known to his subjects as a "
"mirthful and joyful king.  In fact the king fashioned himself as a bard of sorts, more than a ruler.  He liked to compete in musical competitions far and wide, "
"and usually walked away the winner.  Sadly King Gek vanished from gnomish culture around the year 438, when he was returning from a musical competition held at the Temple of Lathander.");
    set_property("lore difficulty",10);
    set_weight(5);
    set_value(150);
    set_type("clothing");
    set_limbs(({"head"}));
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    flag = 0;
}
int wearit() {
   if((int)ETO->query_stats("strength") > 17) {
     set_item_bonus("strength",0);
     return 1;
   }
   else set_item_bonus("strength",1);
   flag = 1;
   tell_object(ETO,"%^RED%^You wear the crown and feel your might grow.%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETOQCN+" wears a crown and seems to grow stronger.%^RESET%^",ETO);
   return 1;
}
int removeit() {
   if(flag) {
     flag = 0;
     tell_object(ETO,"%^RED%^You remove the crown and don't feel quite as mighty anymore.%^RESET%^");
     tell_room(EETO,"%^RED%^"+ETOQCN+" removes a crown and seems to grow weaker.%^RESET%^",ETO);
   }
   return 1;
}
