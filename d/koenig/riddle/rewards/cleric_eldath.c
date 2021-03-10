//cleric_eldath.c - Cleric reward for Riddle Quest.  Circe 1/2/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A blue small shield");
   set_short("%^BOLD%^%^BLUE%^Shield of S%^GREEN%^o%^BLUE%^lace%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This small blue round shield is "+
      "edged with a %^WHITE%^silver border%^BLUE%^.  The blue "+
      "enamel used to color the metal takes on a lustrous quality, "+
      "causing the color to shift shades.  A relief of %^BOLD%^%^WHITE%^"+
      "silver serpents%^BLUE%^ intertwined is prominent in the center of "+
      "the shield.  The straps of the shield are made of leather, dyed blue.");
   set_lore("This shield is a relic of the faith of Eldath.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^%^BLUE%^You feel at peace as you put aside the weariness of battle.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^GREEN%^"+ETOQCN+"'s blue "+
           "shield rings out a soothing tone as "+who->QCN+" strikes it.",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLUE%^The shield rings a soothing tone as "+
           ""+who->QCN+" strikes it, bringing an inner peace to your soul.");
        tell_object(who,"%^BOLD%^%^GREEN%^"+ETOQCN+"'s shield rings out a "+
           "soothing tone as you strike it.");
        ETO->do_damage("torso",(random(8)+1)*-1);
        return damage;  }
}
