#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

void create()
{
   ::create();
   remove_property("can_hold");
set_property("can_hold", ({"staff","spear","polearm","long bow","short bow","recurved bow"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",3);
   set_property("original_weight",4);
   set_name("large weapon sleeve");
   set_short("%^WHITE%^%^BOLD%^A jeweled large weapon sleeve%^RESET%^");
   set_id(({"sleeve","large weapon sleeve","large sleeve","weapon sleeve","jeweled sleeve","jeweled weapon sleeve","large jeweled sleeve","large jeweled weapon sleeve"}));
   set_long("This is a sleeve-type casing suitable for long weapons"+
   " such as staves, large spears, polearms, and scythes. It is a"+
   " long tube made of sturdy tanned leather with a closed bottom that"+
   " has been gilded with brass to prevent the weapon from sliding out."+
   " It has adjustable straps to hold it on your body. Several"+
   " semi-precious stones have been added onto the leather tube, held"+
   " in place by silver or brass settings. You notice a few large"+
   " %^BOLD%^opals%^RESET%^ held in silver, along with some inch long"+
   " %^MAGENTA%^amethyst crystals%^RESET%^, and a few circular rings"+
   " of a %^BLUE%^dark blue geod%^RESET%^. There are also several smaller"+
   " pieces of polished %^BOLD%^%^GREEN%^olivine%^RESET%^. Set in brass"+
   " are a few larger, rectangularly cut pieces of %^YELLOW%^yellow"+
   " topaz%^RESET%^, some cats-eye shaped pieces of %^ORANGE%^tigers"+
   " eye%^RESET%^, and some large pieces of round and polished"+
   " %^BOLD%^%^RED%^orangish-red garnet%^RESET%^. Sprinkled throughout"+
   " the pattern are some %^BOLD%^%^MAGENTA%^lavender pearls%^RESET%^"+
   " that compliment the stones nicely. The entire effect is dazzling.");
   set_value(2375);
   set_max_internal_encumbrance(20);
}

int will_work(object ths, object tht) {
   string trash;
   string *allowed;

   allowed = tht->query_property("can_hold");
   if(member_array(ths->query_prof_type(),allowed) != -1) return 1;
   if(member_array(ths->query_lr_prof_type(),allowed) != -1) return 1;
   if(member_array(ths->query_basic_prof_type(),allowed) == -1) return 0;
   if(sscanf(ths->query_prof_type(),"%s axe",trash) == 1) {
      if((member_array("bludgeoning", allowed) != -1) || (member_array("bludgeoning", allowed) != -1))
         return 1;
      else return 0;
   }
   else if(((string)ths->query_prof_type() == "whip") || (string)ths->query_prof_type() == "drider whip")
         return 0;
   return 1;
}
