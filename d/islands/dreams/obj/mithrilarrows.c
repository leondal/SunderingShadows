#include <std.h>
inherit "/d/common/obj/lrweapon/flarrows.c";

void create()
{
   ::create();
   	set_name("bundle of flight arrows");
   	set_short("%^RESET%^%^BLUE%^A bundle of silver flight arrows%^RESET%^");
   	set_id(({"arrows","quiver","flight arrows","longbow arrow","leather quiver"}));
   	set_long("%^BLUE%^This bundle is full of %^BOLD%^%^WHITE%^"+
		"silver%^RESET%^%^BLUE%^ long bow flight arrows that are incredibly"+
   		" light. They all are tipped in "+
		"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l"+
		"%^RESET%^%^BLUE%^ and look as though they"+
   		" would fly straight and true. %^BOLD%^%^BLUE%^Bright blue"+
		"%^RESET%^%^BLUE%^ feathers are used for the fletching.");
        set_property("enchantment",1);   
        set_shots(-1);
}
int is_arrows(){return 1;}
