#include <std.h>
#include "../keep.h"
inherit WEREWOLF;

void create()
{
    ::create();

    set_name("massive werewolf");
    set_short("%^BOLD%^%^BLACK%^Massive Werewolf%^RESET%^");
    set_id(({"Werewolf","werewolf","massive werewolf","Massive Werewolf"}));
   
    set_long("%^BOLD%^%^WHITE%^This creature towers nearly ten feet "+
    "tall, a hybrid of some massive wolf and an ugly ogre.  "+
    "Its body is covered with a thick and dark fur.  The legs of "+
    "this creature are those of a powerful wolf and each of its arms "+
    "end in clawed appendages.  The face of this creature "+
    "resembles a strange mixture between wolf and ogre, something "+
    "both unnatural and fear inspiring.%^RESET%^");
	   
    set_hd(25,1);
    set_hp(670 + random(41));
    set_overall_ac(-7);
    set_size(3);
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    set_stats("intelligence", 14);
    set_stats("charisma", 6);
    set_stats("wisdom", 12);
    set_funcs( ({"bite","maim"}) );
    set_damage(2,6);
    set_attacks_num(4);
    MOB_TR_D->do_treasure(TO,"B");    
    set_new_exp(25, "high");
}
