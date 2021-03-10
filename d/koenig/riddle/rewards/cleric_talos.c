//cleric_talos.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A twisted metal buckler");
   add_id(({"buckler"}));
   set_short("%^RESET%^%^BLUE%^Tornado%^BOLD%^ %^BLACK%^Buckler%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^This dark gray buckler was once crafted out of steel. The buckler though looks as if it has been twisted in a counter-clockwise fashion, warping the metal in the process. The odd metal spiral has been inlaid with a %^RESET%^ %^BLUE%^storm blue%^BOLD%^%^BLACK%^ metal in a chaotic manner, further adding to the twisted odd look of the buckler. A leather strap is attacked to the underside of the buckler.
CIRCE
   );
   set_lore("This shield is a relic of the faith of Talos.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^%^BLACK%^You hear the echo of %^YELLOW%^thunder %^BLACK%^as you lower the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BLUE%^A strange wind picks up suddenly, "+
           "scattering the debris in the area towards "+who->QCN+", then the "+
           "breeze quickly dissipates!",({ETO,who}));
        tell_object(ETO,"%^BLUE%^The buckler literally begins to spin on your arm, "+
           "creating a quick burst of wind that scatters debris at "+who->QCN+"!");
        tell_object(who,"%^BLUE%^A strange quick breeze brings the debris in the "+
           "area crashing into you!");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
