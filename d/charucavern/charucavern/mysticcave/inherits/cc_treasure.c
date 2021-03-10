#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
#define RAND "/d/common/obj/rand/"
#define POTS "/d/common/obj/potion/"
#define JOBS "/d/common/obj/misc/"


#define RAND_FILES ({"cloak", "epants", "mage_robes", "menshirt", "r_helm", "r_shoes",\
"rand_chain", "rand_leath_head", "rand_shirts", "randrobe", "s_curiass", "skirts",\
"steelshield"})

#define POTIONS ({"cure_blindness", "cure_poison", "det_invis", "invisible", "paralyze", "weaken"})

#define JUNK ({"lantern", "backpack", "sack", "ssack", "paper", "bullseye", "pouch", "spouch"})

inherit DAEMON;

void find_stuff()
{
    object myOb, coins;
    switch(random(100))
    {
        case 1..25:
             myOb = new(JOBS + JUNK[random(sizeof(JUNK))]);
             if(myOb->is_container())
             {
                 coins = new("/std/money");
                 coins->add_money("gold", 300 + random(701));
                 coins->move(myOb);
             }
             break;
        case 26..35:
             switch(random(3)) 
             { 
                 case 0: myOb = POISON_D->QueryPoisonObject("any", "injury", 18);
                         break;
                 case 1: myOb = POISON_D->QueryPoisonObject("any", "contact", 18);
                         break;
                 case 2: myOb = POISON_D->QueryPoisonObject("any", "ingested", 18);
                         break;
             }
             break;
        case 36..49:
             myOb = new(JOBS + JUNK[random(sizeof(JUNK))]);
             if(myOb->is_container())
             {
                 coins = new("/std/money");
                 coins->add_money("gold", 700 + random(301));
                 coins->move(myOb);
             }
             break;
        case 50..60:
             myOb = new("/d/magic/scroll");
             myOb->set_spell_level(4 + random(5));
             break;
        case 61..75:
             myOb = new(RAND + RAND_FILES[random(sizeof(RAND_FILES))]);
             if(myOb->query_property("enchantment") < 2) 
             {
                 myOb->remove_property("enchantment");
                 myOb->set_property("enchantment", 2);
             }
             break;
        case 76..79:
             myOb = new("/d/deku/armours/ring_p");
             myOb->set_property("enchantment", 2);
             break;
        case 80..90:
             myOb = new(POTS + POTIONS[random(sizeof(POTIONS))]);
             break;
        case 91..94:
             myOb = new(CROB+"crater_weapon");
             break;
        case 95..99:
             myOb = new(RAND + RAND_FILES[random(sizeof(RAND_FILES))]);
             if(myOb->query_property("enchantment") < 2) 
             {
                 myOb->remove_property("enchantment");
                 myOb->set_property("enchantment", 2);
             }
             break;
    }
    if(!objectp(myOb)) myOb = new(JOBS + "fish");
    return myOb;
}

