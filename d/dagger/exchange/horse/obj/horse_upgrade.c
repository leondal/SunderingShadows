//horse_upgrade LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJECT;

int value, type;

//This is the inherit used for items to upgrade the race horses. 
// type: 1. horse shoes for speed 2. spurs for acceleration 3. riding crops for jockey ability
// value: 1-5. This is the improvement to that horse's stat. Be VERY careful about this value as to not upset the balance of the races. 
// Remember to add lore to it so that players not familiar with the races know that the item has no real value in every day life, but could have an effect on a race horse
// see the pre-made items for examples 


void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade"}));
    set_short("%^RESET%^%^ORANGE%^horse_upgrade%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A horse racing upgrade.\n%^RESET%^\n\n");
    set_weight(1);
    set_value(1);

}

int check_value(){
    return value;
}

int check_type(){
    return type;
}