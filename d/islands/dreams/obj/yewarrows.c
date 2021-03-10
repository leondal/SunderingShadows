#include <std.h>
inherit "/d/common/obj/lrweapon/farrows.c";

void create()
{
   ::create();
   	set_name("bundle of flight arrows");
   	set_short("%^RESET%^%^ORANGE%^A bundle of flight arrows%^RESET%^");
   	set_id(({"arrows","shortbow arrow","flight arrows"}));
   	set_long("%^ORANGE%^This bundle of %^YELLOW%^"+
		"yew wood%^RESET%^%^ORANGE%^ short bow flight arrows are incredibly"+
   		" light. They all are tipped in "+
		"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l"+
		"%^RESET%^%^ORANGE%^ and look as though they"+
   		" would fly straight and true. %^GREEN%^Dark green%^ORANGE%^ "+
		"feathers are used for the fletching.");
       set_property("enchantment",1);
       set_shots(-1);
}
int is_arrows(){return 1;}
