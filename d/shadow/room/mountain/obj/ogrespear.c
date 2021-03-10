//updated by Circe 9/3/05 to inherit large spear
#include <std.h>
inherit "/d/common/obj/weapon/spear_lg";

void create() {
   ::create();
   set_id(({ "spear","large spear","ogre spear","scepter"}));
   set_name("ogre spear");
   set_obvious_short("A large spear");
   set_short("%^BOLD%^%^BLUE%^Scepter of the Ogres%^RESET%^");
   set_long(
      "This large spear must be wielded in two hands by most people.  "+
      "The haft is carved of %^BOLD%^%^BLACK%^shadow wood%^RESET%^, so "+
      "dark it is almost black.  The spear is well-kept and tipped with "+
      "a large, carved %^BOLD%^%^RED%^ruby %^RESET%^sharpened to a deadly "+
      "point.  The other end of the haft is fitted with the %^BOLD%^skull "+
      "%^RESET%^of a dwarf, the bone bleached and then stained with a "+
      "%^RED%^bloody %^RESET%^wound near the crown.  A few crude carvings "+
      "have been made along the haft you might be able to read.");
   set("read",
      "Me Ogre King.  You No Touch.");
   set_lore("This is the legendary Ogre King's Scepter - well, "+
      "legendary to the ogres anyway, which isn't saying much.  "+
      "The ogres invaded the lower levels of Echoes Mountains "+
      "several decades ago, and since then there has been a "+
      "constant battle between the ogres and the dwarves for the "+
      "mines in the lower levels.  At the time of the initial "+
      "conquest, Ingnarth was king of the ogres, but this scepter "+
      "seems to change hands almost monthly now.");
   set_property("lore difficulty",8);
   set_value(150);
   set_property("enchantment",1);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
}
int wield_func(string str) {
   tell_object(ETO,"%^ORANGE%^You heft the ogre spear and feel a raw energy coursing through you.%^RESET%^");
   tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" looks savage as "+ETO->query_subjective()+" "+
   "takes the spear in hand.%^RESET%^",ETO);
   return 1;
}
int unwield_func(string str) {
   tell_object(ETO,"%^ORANGE%^You grunt as you release the spear.%^RESET%^");
   tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" unwields "+
      "the spear with a grunt.%^RESET%^",ETO);
   return 1;
}
int extra_hit(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(10)) {
      tell_object(ETO,"%^RED%^You growl as you thrust the spear deeply into your victim!");
      tell_object(victim,"%^RED%^"+ETO->query_cap_name()+" growls as "+ETO->query_subjective()+" "+
         "guts you visciously with "+ETO->query_possessive()+" spear!");
      tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" drives "+
         ""+ETO->query_possessive()+" spear visciously into "+victim->query_cap_name()+", gutting "+
         ""+victim->query_objective()+"!", ({ETO,victim}));
      victim->cause_typed_damage(victim,0,roll_dice(1,10)+1,"piercing");
      return 0;
   }
   else return 0;
}
