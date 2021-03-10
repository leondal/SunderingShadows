//cleric_kossuth.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("An intricate red large shield");
   set_short("%^BOLD%^%^RED%^Sh%^RESET%^%^ORANGE%^ie%^BOLD%^%^RED%^ld of Fl%^YELLOW%^a%^RED%^mes%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^RED%^This large metal shield is cut to look like a blazing fire. The tendrils of flames are cut in a uniform patter, giving the shield a symmetrical feeling. The edges of the flame tendrils have been rounded out, as to avoid one cutting themselves. Veins of %^RESET%^%^ORANGE%^orange%^BOLD%^%^RED%^ and %^YELLOW%^yellow%^RED%^ blend in with the metal giving the flames an almost three dimensional feeling. A large flamedance gem is set in the center of the shield, in a %^YELLOW%^brass%^RED%^ setting. %^YELLOW%^Brass%^RED%^ hand-straps allows one to secure the shield in place.
CIRCE
   );
   set_lore("This shield is a relic of the faith of Kossuth.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^YELLOW%^You feel a wave of %^RED%^heat %^YELLOW%^as you release the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+ETOQCN+"'s shield "+
           "emits a fiery eruption, right at "+who->QCN+"!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^RED%^A fiery eruption spews forth from the "+
           "shield, right into "+who->QCN+"!");
        tell_object(who,"%^BOLD%^%^RED%^"+ETOQCN+"'s shield emits a fiery "+
           "eruption that spews all over you!");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
