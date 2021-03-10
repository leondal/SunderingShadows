#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("silk dress");
   set_short("%^BOLD%^%^BLUE%^An ocean blue dress%^RESET%^");
   set_id(({"dress","silk dress","blue dress","ocean blue dress"}));
   set_long("%^BOLD%^%^BLUE%^The dress is made out of fine silk and has"+
   " been dyed in a pattern to fit the ocean. The top of the dress has"+
   " ripples of %^WHITE%^white%^BLUE%^ running through it to represent"+
   " white caps of waves, the center of the dress has ripples of"+
   " %^GREEN%^aquamarine%^BLUE%^ and the bottom of the dress has ripples"+
   " of %^RESET%^%^BLUE%^dark blue%^BOLD%^ for the depths of the sea. The"+
   " hem of the dress and the sleeves are scalloped and lay in graceful"+
   " folds that move in the breeze like undulating waves.");
   set_weight(1);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_wear("%^BOLD%^%^BLUE%^The silk dress feels wonderfully against your skin.%^RESET%^");
   set_remove("%^BLUE%^You reluctantly slip out of the silky dress.%^RESET%^");
   set_value(150);
}
