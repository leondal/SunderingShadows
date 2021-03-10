//cleric_tyr.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A medium kite shield");
   set_short("%^BOLD%^%^BLUE%^Shield %^WHITE%^of %^RESET%^%^MAGENTA%^Justice%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLUE%^This electrum shield is cut into the shape of a convex kite shield.  Kite shields features a rounded top and a tapered pointed bottom.  The normal blue sheen of electrum has been further deepened into a rich azure shade.  A %^RESET%^%^MAGENTA%^dusky purple%^BOLD%^%^BLUE%^ stripe travels diagonally across the center portion of the shield.  Set in %^WHITE%^white gold%^BLUE%^ in front of the boarder is the image of Tyr's holy symbol, a pair of balanced scales resting on an upright war hammer.
CIRCE
   );
   set_lore("This shield is a relic of the faith of Tyr.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^%^CYAN%^You feel confident in your judgement as you set aside the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^MAGENTA%^The symbol on "+ETOQCN+"'s "+
           "shield glows brilliantly right before it releases a jolt of electricity "+
           "into "+who->QCN+"!",({ETO,who}));
        tell_object(ETO,"%^MAGENTA%^You feel the shield vibrate slightly as a jolt "+
           "of electricity is discharged into "+who->QCN+"!");
        tell_object(who,"%^MAGENTA%^The symbol on "+ETOQCN+"'s shield glows "+
           "brilliantly right before an electrical charge is discharged into "+
           "you, almost as if it is judging your guilty of your past crimes!");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
