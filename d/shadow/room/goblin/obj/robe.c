//updated by Circe 6/1/04 with new desc, lore, etc by Shar
//removed AC, in line with standard robes. Nienne, 07/07.
#include <std.h>
inherit ARMOUR;

nosave int flag;

void create() {
    ::create();
    set_name("robe");
    set_id(({"robe","mystic robe"}));
    set_short("%^RESET%^%^MAGENTA%^Mystic %^BLUE%^Robe%^RESET%^");
    set_obvious_short("%^RESET%^%^MAGENTA%^a small %^BLUE%^rune-covered%^MAGENTA%^ robe%^RESET%^");
    set_long(
       "This dark %^MAGENTA%^purple%^RESET%^ robe is extremely "+
       "lightweight.  The material is hard to describe, while it "+
       "possess some similarities to silk, it does not have silk's "+
       "famed smoothness and cool feeling.  Instead this robe has "+
       "a fine%^CYAN%^ nubby%^RESET%^ texture to it.  The long sleeves "+
       "and dragging hem on the robe seem to suggest it has an arcane "+
       "background.  With%^BOLD%^%^BLUE%^ brilliant blue%^RESET%^ runes "+
       "on the hem of the sleeves and along the back of the robe, this "+
       "only confirms the guess that it's an arcane item."
    );
    set_lore("The Mystic Robe is actually a gnomish garment, not goblin."+
       "  Though goblins are scavengers by nature and take what they "+
       "can when they can.  No doubt that some poor gnomish wizard who "+
       "was wearing this robe met his or hear end at the hands of a "+
       "beastial goblin.  The runes, in gnomish, read sun, moon, "+
       "heavens, astrology, and stars - common arcane and mystical "+
       "symbols.");
    set_property("lore difficulty",7);
    set_weight(5);
    set_value(100);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    flag = 0;
}
int wearit() {
   if((int)ETO->query_stats("intelligence") > 17) {
     set_item_bonus("intelligence",0);
     return 1;
   }
   else set_item_bonus("intelligence",1);
   flag = 1;
   tell_object(ETO,"%^MAGENTA%^The air sparkles with %^RED%^mystical %^MAGENTA%^energy.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^The air around "+ETOQCN+" sparkles with %^RED%^mystical%^MAGENTA%^ energy.%^RESET%^",ETO);
   return 1;
}
int removeit() {
   if(flag) {
     flag = 0;
     tell_object(ETO,"%^MAGENTA%^You feel a strange power leave your body.%^RESET%^");
   }
   return 1;
}
