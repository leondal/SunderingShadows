//updated by Circe 6/15/04 with new desc, etc by Shar
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/club_lg";

void create()
{
	::create();
	set_name("club");
      set_obvious_short("a large gray club");
	set_short("%^BLUE%^Club of Sacrificial Possession%^RESET%^");
	set_id(({"club", "ogre club", "large club", "sacrificial club", "club of sacrificial possession", "Club of Sacrificial Possession", "gray club", "large gray club"}));
	set_long(
@CIRCE
Ghostly grey weathered driftwood is used to create this club.  The club is carved with great craftsmanship in the appearance of a %^RED%^screaming figure%^RESET%^.  A chilling look of %^MAGENTA%^terror %^RESET%^is brought to life in the carving as the figure's %^RED%^mouth %^RESET%^is stretched wide in a %^BLUE%^horrific scream%^RESET%^.  The club is marred with cuts and nicks, showing that its been used in battle often.  The grey wood you notice has been stained %^RED%^reddish brown %^RESET%^in some area
CIRCE
	);
      set_lore(
@CIRCE
The Club of Sacrificial Possession is rumored to have been made from a follower of Eldath that the Grey Claws, a tribe of orcs, sacrificed to their dark god.  The legend goes that Cyric was very pleased with his hunters that he transformed the Eldathians corpse into a club.  Each club is rumored to be different, bearing the image of the Eldathian sacrificed.  The victims soul is said to be housed within the club and forced to serve the needs of the orcs and the will of Cyric.  A chilling fate for anyone,
CIRCE
      );
      set_property("lore difficulty",12);
   //set_weight(3);
   //set_size(3);
   set_value(400);
   //set_wc(1,6);
   //set_large_wc(1,3);
   //set_type("bludgeoning");
   //set_prof_type("large club");
      set_property("enchantment",1+random(2));
      set_wield((:TO,"wieldme":));
      set_unwield((:TO,"unwieldme":));
      set_hit((:TO,"hitme":));
}

int wieldme(){
   if((int)ETO->query_lowest_level() < 10){
      tell_object(ETO,"You cannot heft the great ogre club!");
      return 0;
   }
   tell_object(ETO,"%^RED%^A ghostly scream howls from the club as you wield it.");
   tell_room(EETO,"%^RED%^A ghostly scream howls through the area.",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^With an uneasy feeling, you "+
      "finally manage to pry your hand off the club.");
   tell_room(EETO,"%^RESET%^%^ORANGE%^Looking uneasy, "+ETOQCN+" "+
      "manages to unwield "+ETO->QP+" club.",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(ETO)) return 0;
   if(!objectp(targ)) return 0;
   if(!random(12)){
      tell_object(ETO,"%^RED%^A ghostly presence rises out of the "+
         "club with a frightful scream.  The ghostly figure grabs "+
         "onto "+targ->QCN+", looking to attack "+targ->QP+" very "+
         "life-force!");
      tell_object(targ,"%^RED%^A ghostly presence rise out of "+
         ""+ETOQCN+"'s club and reaches out to grab you.  Its "+
         "scream echoes through your ears as it drains your very "+
         "life with its touch!");
      tell_room(EETO,"%^RED%^A ghostly presence rises out of "+
         ""+ETOQCN+"'s club with a frightful scream.  The ethereal "+
         "figure reaches out to grab "+targ->QCN+", as if to attack "+
         ""+targ->QP+" life force!",({ETO,targ}));
      set_property("magic",1);
      targ->do_damage("torso",random(6)+5);
      set_property("magic",-1);
      return random(3);
   }
   return 0;
}
