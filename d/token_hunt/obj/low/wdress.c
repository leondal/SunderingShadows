#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
      set_name("%^BOLD%^%^WHITE%^Windblown%^RESET%^");
      set_short("%^BOLD%^%^WHITE%^A flowing white gown%^RESET%^");
      set_id(({"gown","wind gown","flowing gown","dress", "long gown","long dress"}));
      set_long("%^BOLD%^%^WHITE%^While very clearly highlighting the females figure nicely, this long flowing"
" gown manages to have an almost tangible %^CYAN%^a%^WHITE%^u%^CYAN%^ra %^WHITE%^of freedom surrounding it."
"  Worn off the right shoulder, it loosely hugs the wearers torso and hips until it seperates into many small"
" whispy trails of tr%^RESET%^a%^BOLD%^%^WHITE%^nsl%^RESET%^u%^BOLD%^%^WHITE%^cent fabric that flow freely in"
" the wind.\n");
      set_weight(6);
	set_value(0);
      set_ac(0);
      set_type("clothing");
      set_limbs(({"torso"}));
      set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
      set_wear((:this_object(),"wearme":));
      set_remove((:this_object(),"unwearme":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The whispy fabric of "+ETOQCN+"'s dress blows softly in the wind.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^The whispy fabric of the dress blows softly in the wind, leaving you with the refreshing feeling of freedom.%^RESET%^");
   return 1;
}
int unwearme(string str){
   tell_object(ETO,"%^BOLD%^%^WHITE%^The thin fabric of the dress slips easily away from you.%^RESET%^");
   return 1;
}