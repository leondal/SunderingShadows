#include <std.h>
inherit "/d/common/obj/armour/shield";


void create(){
   ::create();
   set_name("shell shield");
   set_id(({"shield","shell shield"}));
   set_short("%^MAGENTA%^s%^BLUE%^h%^MAGENTA%^ell s%^BLUE%^h%^MAGENTA%^ield%^RESET%^");
   set_obvious_short("%^MAGENTA%^sea stained shield%^RESET%^");
   set_long("This is a shield made from "+
   "a large sea shell with some straps on it."+
   "  The shell has %^BOLD%^%^BLACK%^blackened barnicles%^RESET%^ growing"+
   " on it.  They pulse with a %^GREEN%^toxic %^RESET%^pressure.");
   set_lore("This might have just been a regular"+
   " shell at one point.  But the resentment of "+
   "the person who died caused it to turn into an"+
   " item of dark magic over the course of centuries.");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_value(1500);
   set_property("enchantment",4+random(2));
   
   set_item_bonus("spell damage resistance",10);
   set_item_bonus("athletics",2);
   set_item_bonus("constitution",2);
   set_struck((:TO,"struck_fun":));
}
int struck_fun(int damage,object what,object who){
   if(!random(3)){
     tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" raises "+ETO->QP+" shield to deflect
"+who->QCN+"'s attack, and the barnicles spray %^RESET%^%^GREEN%^acid back!",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^BLUE%^You raise your shield to deflect "+who->QCN+"'s
attack, and the shield sprays %^RESET%^%^GREEN%^acid%^BOLD%^%^BLUE%^ at them from the barnicles!");
     tell_object(who,""+ETO->QCN+" raises "+ETO->QP+" shield to deflect
your attack, and the the barnicles from the shield spray %^RESET%^%^GREEN%^acid at you!");
     who->cause_typed_damage(who,0,roll_dice(10,10),"acid");
     return 0;
   }
   return damage;
}
