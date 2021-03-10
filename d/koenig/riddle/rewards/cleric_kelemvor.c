//cleric_kelemvor.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A medium rectangular shield");
   set_short("%^BOLD%^%^BLACK%^The Requiem Shield%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^Cold steel has been shaped into this convex rectangular shield. The steel has been tinted a dull neutral shade of gray, neither too dark nor too light. Molded on the front of the shield in %^RESET%^titanium%^BOLD%^%^BLACK%^ is a a celestial figure, a winged woman, more commonly known as a Deva. The woman is in a pose with her head bent down, a common image seen in graves. The outer border of the shield seems to be made of %^RESET%^titanium%^BOLD%^%^BLACK%^, and bears a repeating pattern of a skeletal hand clutching a balanced scale.
CIRCE
   );
   set_lore("This shield is a relic of the faith of Kelemvor.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^You whisper a prayer to Kelemvor as you put aside the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A low mournful wail "+
           "is heard and seems to put "+who->QCN+" off guard.",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLACK%^The shield emits a low mournful wail "+
           "that seems to unnerve "+who->QCN+".");
        tell_object(who,"%^BOLD%^%^BLACK%^A low mournful wail fills your ears "+
           "and chills you to your core.");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
