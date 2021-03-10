#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;
   ::create();
    set_name("cooshee");
    set_id(({"cooshee","elven dog","dog"}));
    set_short("%^GREEN%^A cooshee%^RESET%^");
set_long("%^RESET%^%^GREEN%^This little guy is incredibly cute,"+
	" in a roly-poly, waddling sort of way. Covered in %^BOLD%^soft"+
	" green fur %^RESET%^%^GREEN%^edged with %^BOLD%^%^WHITE%^white "+
	"guard hairs%^RESET%^%^GREEN%^, he has huge feet and a very long"+
	" %^BOLD%^%^MAGENTA%^pink tongue %^RESET%^%^GREEN%^that curls up "
	"and touches his %^BOLD%^%^BLACK%^black button nose %^RESET%^"+
	"%^GREEN%^as he pants.  Two long ears stick up from the sides of"+
	" his head, flopping over about over half way up, giving him a "+
	"perpetual look of perked curiosity.  Silvery%^BOLD%^%^CYAN%^ blue"+
	" eyes %^RESET%^%^GREEN%^hold a look of constant interest, especially"+
	"when there appears to be a %^ORANGE%^treat %^GREEN%^nearby.%^RESET%^");
    set_hd(12,1);
 set_hp(query_hd()*8);
    set_exp(1);
    set_stats("strength",18);
    set_stats("intelligence",10);
    set_stats("dexterity",22);
    set_race("cooshee");
    set_body_type("quadreped");
    set_damage(2,3);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_gender("male");
}
