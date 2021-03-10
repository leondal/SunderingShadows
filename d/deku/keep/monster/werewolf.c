#include <std.h>
#include "/d/deku/inherits/forest.h"
#include "../keep.h"

inherit WEREWOLF;

void create()
{
    ::create();

    set_name("Werewolf");
    set_short("%^BOLD%^%^BLACK%^Werewolf%^RESET%^");
    set_id(({"Werewolf","werewolf"}));
   
    set_long("%^BOLD%^%^WHITE%^This creature stands over six feet "+
    "tall, the unnatural hybrid of humanoid and wolf.  Its body is "+
    "covered with a thick and dark fur.  The legs of this creature "+
    "are that of a powerful wolf and each of its arms end in clawed "+
    "appendages.  The face of this creature resembles a strange "+
    "mixture of humanoid and wolf, something not only unnatural "+
    "but fear inspiring.%^RESET%^");

    set_hd(22,1);
    set_hp(425 + random(31));
    set_overall_ac(-3 - random(4));
    set_size(2);
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    set_stats("intelligence", 14);
    set_stats("charisma", 6);
    set_stats("wisdom", 12);
    set_funcs( ({"bite"}) );
    set_damage(4,4);
    set_attacks_num(4);
    MOB_TR_D->do_treasure(TO,"A");
    set_moving(1);
    set_speed(40);
    set_new_exp(20, "normal");
    set_nogo( ({NO, NO2, NO3, NO4, NO5, NO6, NO7, NO8, NO9, NO10, NO11, NO12, NO13, NO14}) );
    FENC->fix_nogo(TO);
}




