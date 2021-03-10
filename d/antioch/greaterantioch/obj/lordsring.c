#include <std.h>
#include "../gantioch.h"
inherit ARMOUR;

create(){
   ::create();
   set_id(({"ring","lordsring","band","gold band"}));
   set_name("lordsring");
   set_obvious_short("%^BOLD%^%^YELLOW%^A slight gold band%^RESET%^");
   set_short("%^BOLD%^%^YELLOW%^Zathon's %^BOLD%^%^WHITE%^Band of %^BOLD%^%^GREEN%^Lesser %^BOLD%^%^MAGENTA%^Persuasion%^RESET%^");
   set_long(
      "%^BOLD%^%^WHITE%^This beautiful %^BOLD%^%^YELLOW%^gold band %^BOLD%^%^WHITE%^is"+
	  " finely crafted. It has three small %^BOLD%^%^RED%^rubies %^BOLD%^%^WHITE%^that are evenly"+
	  " spread out around the band. It looks to be worth a small fortune.%^RESET%^");
   set_weight(1);
   set_value(1500);
   set_type("ring");
   set_limbs(({ "right hand","left hand" }));
   set_size(1);
   set_property("enchantment",0);
   set_item_bonus("charisma",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" %^BOLD%^%^MAGENTA%^looks confident as "+ETO->query_possessive()+" eyes %^BOLD%^%^CYAN%^glisten %^BOLD%^%^MAGENTA%^a moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You feel more confident as you wear this ring.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" %^RED%^looks hesitant as the ring slides off of "+ETO->query_possessive()+" finger.",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You feel far less confident as you wear this ring.");
	return 1;}
