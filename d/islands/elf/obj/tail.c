#include <std.h>
inherit "/d/common/obj/clothing/belt.c";

void create(){
   ::create();
   set_name("Cat Tail");
   set_id(({ "belt", "tail", "cat","cat tail" }));
   set_short("%^RESET%^%^CYAN%^C%^WHITE%^a%^CYAN%^t T%^WHITE%^a%^CYAN%^il");
   set_obvious_short("%^RESET%^%^CYAN%^a belt with a tail%^RESET%^");
   set_long("This is an odd looking belt. "+
   " There are several white cat paws engraved"+
   " along the length.  Oddly, out of the back "+
   "of it is a white furry tail.");
   set_value(1000);
   set_lore("There is a certain sect of elves"+
   " who worship felines.  This is one of their"+
   " creations.   The feline friends created this "+
   "item with the magic of love for kittens.  By "+
   "having a tail like a cat they can deepen their"+
   " love for cats.");
   set_size(-1);
   TO->set_property("enchantment",4+random(2));
   set_item_bonus("stealth",2);
   set_item_bonus("thievery",2);
   set_item_bonus("wisdom",-1);
   set_item_bonus("slashing resistance",5);
   set_struck((:TO,"strikeme":));
   set_wear((:TO,"wearme":));
}
int strikeme(int damage, object what, object who){
    if(!random(4)){
  	tell_object(ETO,"%^BOLD%^%^BLUE%^Your cat tail lunghes"+
		" "+who->QCN+", rying to trip them!");
   	tell_object(who,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s tail "+
		"lunges at you and tries to trip you");
    tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s tail tries to trip "+who->QCN+" with"+
		" a quick motion!",({who,ETO}));
    if(!"/daemon/saving_throw_d.c"->reflex_save(who,-30))
     	who->set_tripped(1,"%^BOLD%^You feel over from a tail trip!");
  }
  return damage;
}
int wearme(){
  	write("%^BOLD%^%^BLUE%^You fasten the tail belt around you and go 'Nyah'.");
   	say("%^BOLD%^%^BLUE%^The tail "+TPQCN+"'s belt flicks back and forth"+
		" like it is alive.");
  return 1;
}