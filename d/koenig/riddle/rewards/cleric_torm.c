//cleric_torm.c - Cleric reward for Riddle Quest.  Circe 1/31/04
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
   set_obvious_short("A large metal kite shield");
   set_short("%^YELLOW%^Shield of the%^BLUE%^ Valiant%^RED%^ Heart%^RESET%^");
   set_long(
@CIRCE
%^YELLOW%^This golden shield is cut in the shape of a convex kite. Kite shields features a rounded top and a tapered pointed bottom. The golden color of the shield has been polished to a high gloss, giving it a spectacular awe-inspiring feeling. The image of a rampart lion in %^WHITE%^ivory%^YELLOW%^ rests in the middle of the shield. The lion is perched on his hind legs and faces the right. A %^BLUE%^blue sapphire%^YELLOW%^ is set into the lion's eye-socket, and almost seems to shimmer with life. 
CIRCE
   );
   set_lore("This shield is a relic of the faith of Torm.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^YELLOW%^The lion's roar fills your mind as you set aside the shield.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^YELLOW%^The lion on "+ETOQCN+"'s "+
           "shield suddenly comes to life and takes a swipe at "+who->QCN+" while roaring!",({ETO,who}));
        tell_object(ETO,"%^YELLOW%^A lion's roar is emitted from the shield, "+
           "filling you with courage!");
        tell_object(who,"%^YELLOW%^The lion on "+ETOQCN+"'s shield comes to "+
           "life and tears its claws through your flesh while roaring!");
        who->do_damage("torso",random(8)+1);
        return damage;  }
}
