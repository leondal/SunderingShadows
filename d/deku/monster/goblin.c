#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

void create() 
{
    ::create();
    set_name("goblin");
    set_id( ({"goblin",}) );
    set_race("goblin");
    set_gender("male");
    set_short("A goblin");
    set_long("%^RESET%^This small humanoid creature stands "+
    "about four feet tall, its body obviously unwashed and "+
    "unkept in any manner.  The face of this creature is flat, "+
    "with a wide nose and dull yellow eyes that seem almost "+
    "lifeless.  Its ears are slightly pointed, strangely like "+
    "those common to elves.  Its forehad slopes back, which only "+
    "adds to its already bizarre and unnatural appearance.  Even "+
    "more strange or perhaps freightening is the rows upon rows "+
    "of small and sharp teeth that are visible whenever its wide "+
    "mouth opens.");
    set_hd(18,1);
    set_hp(200 + random(20));
    //turning exp way down, too many of them - Saide, December 2016
    set_new_exp(15, "low");
    set("aggressive",14);
    set_alignment(6);
    set_stats("intelligence",6);
    set_stats("wisdom",4);
    set_stats("strength",13);
    set_stats("charisma",3);
    set_stats("dexterity",8);
    set_stats("constitution",7);
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    if(!random(8)) 
    {
        new("/d/common/obj/weapon/shortsword")->move(TO);
        command("wield sword");
    } 
    FENC->fix_nogo(TO);
}
