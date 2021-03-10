//cleric_selune.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A polished moonstone medium shield");
   set_short("%^BOLD%^%^WHITE%^Moonfire Shield%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^The largest moonstone you have ever seen has been rounded and shaped into this shield. The round gem has been set into a silver backing, to give added security to the shield, with a braided silver border along the outer rim. The moonstone is cut in a cabochon fashion, flat on one side, rounded on the other. A ghostly image of a pair of %^CYAN%^feminine eyes%^WHITE%^ almost seems to lay deep within the gem. A braided silver hand-grip rests on the underside of the shield.
CIRCE
   );
   set_lore("This shield is a relic of the faith of Selune.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^A cool sense of peace flows through you as you lower the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^"+ETOQCN+"'s "+
           "shield emits a beam of brilliant white light that strikes "+who->QCN+"!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^WHITE%^The shield emits an beam of brilliant "+
           "white light that strikes "+who->QCN+"!");
        tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s shield emits a beam "+
           "of brilliant white light that strikes you!");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
