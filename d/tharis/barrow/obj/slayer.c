// Finally added lore, sick of players bugging me (bah). Nienne, 10/04 //
// Added a better and more fitting description - Saide 11/04/03
// failure message changed on wield from notify_fail to tell_object, so they can see it.  Circe 12/9/03
// changed to inherit /d/common sword when putting in *Styx* 12/12/03
#include <std.h>
#include "/d/tharis/barrow/short1.h"

inherit "/d/common/obj/weapon/longsword.c";

void create() {
  ::create();
  set_name("slayer");
  set_id(({"sword", "sword of slaying", "slayer"}));
  set_obvious_short("A long sword");
  set_short("%^RED%^Sword of sla%^BOLD%^%^BLACK%^y%^RESET%^%^RED%^ing%^RESET%^");
  set_long("%^BOLD%^%^RED%^The blade of this weapon is approximately three foot long and "+
   "is made from a rusty red metal of unknown origin that is covered with strange %^BLUE%^"+
   "runes%^RED%^.  The blade meets a %^BLACK%^dull black%^RED%^ hilt "+
    "that ends in a %^WHITE%^silver%^RED%^ pommel.  The pommel is made from "+
    "a %^WHITE%^silver alloy%^RED%^ that is completely rounded with several "+
    "bumps interfering with its otherwise smooth surface.  The entire weapon gives off "+
    "an %^YELLOW%^eerie glow%^RED%^.%^RESET%^");
  set_value(150);
/*  let this all default in from the inherit now
  set_weight(7);
  set_wc(1,8);
  set_large_wc(1,12);
  set_size(2);
  set_type("slashing");
*/
  set_property("enchantment",2);
  set_hit((: TO, "extra_hit":));
  set_wield((: TO, "extra_wield":));
  set_unwield((:TO,"removeme":));
  set_prof_type("slayer");
  set_prof_level(18);  // I'm not sure this actually does anything *Styx* 12/12/03
  set_lore("%^WHITE%^%^BOLD%^Only faint rumours remain concerning the origins of this powerful artifact.  "
"They tell of a Tyrran paladin, who was once a guardian of the temple within Azha.  Upon a holy quest, he "
"was sent to purge the evil from a graveyard outside the city, but never returned.  It is said that the "
"power of the Dark Sun consumed him there, warping his mind and body, and taking possession of the holy "
"sword he once carried proudly.  This blade is thought by some to be the same sword, twisted by evil into "
"an instrument of strife and murder.%^RESET%^");
  set_property("lore difficulty",15);
}

int extra_hit(object ob) {
  //changed to use tell_object() && tell_room() - cleaner this way - Saide 11/04/03
  int dam;
  if(!objectp(ob)) return 1;
  //dam = random(2) + 1;
  //damage sucks currently - updating - Saide June 2017
  dam = roll_dice(2,4);
  if(random(3) > 1) return 0;
  tell_object(ETO,"%^RED%^The sword glows %^BOLD%^%^WHITE%^brightly%^RESET%^%^RED%^ as it "+
    "cuts into the flesh of your foe!%^RESET%^");
  tell_room(EETO,"%^RED%^The sword wielded by "+ETO->QCN+" glows "+
    "as it cuts "+ob->QCN+"'s flesh!%^RESET%^",(({ETO, ob})));
  tell_object(ob,"%^RED%^The sword wielded by "+ETO->QCN+" glows as it cuts "+
    "into your flesh!%^RESET%^");
  ob->do_damage(ob->return_target_limb(),dam);

  if(random(6) < 2) {
    tell_object(ETO,"%^BLUE%^Your sword %^YELLOW%^cackles%^RESET%^%^BLUE%^ in an evil and "+
    	"low manner and seems to lash out at your foe by its own accord!!%^RESET%^");      
    tell_room(EETO,"%^BLUE%^The sword wielded by "+ETO->QCN+
    	" cackles as it lashes yet again into "+ob->QCN+"'s flesh!"+
    	"%^RESET%^",(({ETO, ob})));       
    tell_object(ob,"%^BLUE%^The sword wielded by "+ETO->QCN+" cackles as it "+
    	"lashes yet again into your flesh!%^RESET%^");
    ob->do_damage(ob->return_target_limb(),random(dam) + 3);
  }
  return 1;
}

int extra_wield() {
  if(!ETO) return 0;
  if((int)ETO->query_level() < 15) {
      tell_object(ETO,"The weapon refuses your hand!");
      return 0;
  }
  tell_object(ETO,"%^RED%^Evil laughter echoes within your mind as the glow of the "+
    "sword becomes more brilliant!%^RESET%^");
  tell_room(EETO,"%^RED%^"+ETO->QCN+" wields a glowing sword.%^RESET%^",ETO);
  ETO->set_property("evil item",1);
  return 1;
}

int removeme() {
    ETO->set_property("evil item",-1);
    return 1;
}
