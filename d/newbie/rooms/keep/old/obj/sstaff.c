#include <std.h>
inherit WEAPON;

void create()
{
   ::create();
   set_name("staff");
   set_short("A bone staff");
   set_id(({"staff","small staff","bone staff"}));
   set_long("This is a small staff that has been made from the polished"+
   " leg bone of some incredibly large monster. The tip of the "+
   "staff is rather pointed"+
   " and the top has been rounded some to better bash opponents.");
   set_size(1);
   set_lore("This staff was crafted by a xvart, the small, blue "+
      "creatures that overran Keep Kilgore northeast of Offestry.  "+
      "From all you have been able to learn, a strange sickness "+
      "affected the Kilgore family in the year 596 SG.  The keep "+
      "lay abandoned for many decades before the xvarts moved into "+
      "the already-decaying stone structure.  This staff is often "+
      "wielded by a xvart shaman, the highest of their numbers.");
   set_property("lore difficulty",7);
   set_value(5);
   set_type("bludgeoning");
   set_weapon_speed(2);
   set_wc(1,4);
   set_large_wc(1,4);
   set_weight(2);
   set_prof_type("staff");
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme()
{
   if(ALIGN->is_good(TP)) {
      tell_object(TP,"You get a sense of wrongness as you wield the
staff.");
      return 1;
   }
   tell_object(TP,"You feel wicked as you wield the evil weapon.");
   return 1;
}

int removeme() {
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"You feel better as you release the staff.");
      return 1;
   }
   tell_object(ETO,"You set aside the ghastly staff.");
   return 1;
}
