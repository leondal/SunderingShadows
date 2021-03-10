//Barding
inherit "/d/common/obj/armour/barding" ;
/******************************************* Use common!

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();

    set_name("horse barding");
    set_id(({"barding","horse barding"}));
    set_short("Steel horse barding, covering the head, neck body and legs");
    set_long(
@OLI
    This heavy plate and chain barding covers a horse quite well. The
head is covered thoroughly. The body has ample protection, with carefully
shaped plates covering the flanks and rear. From the plates hang
protective chain linking. The neck is protected with a heavy and flexible
chain mail. The upper legs are covered with small plates linked with thick 
leather. The bottum of the legs are still unprotected.
OLI
    );
    set_weight(200);
    set_size(2);
    set_ac(15);
    set_limbs(({"torso","right foreleg","left foreleg","right rear leg","left rear leg","head"}));
    set_value(2000);
}
****************************************************/
