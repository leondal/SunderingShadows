#include <std.h>
#include "/d/deku/keep/keep.h"
inherit DAEMON;

#define POTIONS ({ "cure_poison","heal","paralyze","poison","hurt","extra_heal","invisible",\
"det_invis","hurt","weaken", "cure_poison","heal","paralyze","poison","hurt","weaken","heal",\
 "poison","hurt","paralyze","poison","cure_poison","extra_heal","poison","hurt","raging_heal",\
"poison","hurt","paralyze","hurt","weaken","invisible" })

#define ARMOR_ST ({ "chain","robe","coif","scale" })

#define WEAPON_ST ({ "mspear","halberd","warhammer","scimitar","halberd","morningstar",\
"lance","longsword" })

#define SP_STUFF ({ "graniteclub","elazoshammer","frostbitesickle","os_boots",\
	"stonecrusherhammer","stonecutter","deep_red_boots","nalreathswhip","gloom_shield",\
"shieldoflight" })

#define SP_STUFFO ({"boots_of_twilight"})

void potions(object where) 
{
    object ob;
    int x;
    for(x = 0;x < random(2) + 1;x++) 
    {
        ob = new("/d/common/obj/potion/" + POTIONS[random(sizeof(POTIONS))]);
        ob->move(where);
    }
}

void norm_armors() 
{
    return new("/d/common/obj/armour/" + ARMOR_ST[random(sizeof(ARMOR_ST))]);
}

void norm_weapons() 
{
    return new("/d/common/obj/weapon/"+ WEAPON_ST[random(sizeof(WEAPON_ST))]);
}

void special_stuff() 
{
    switch(random(2)) 
    {
        case 0:
            return new(KEEPO + SP_STUFF[random(sizeof(SP_STUFF))]);
            break;
        case 1:
            return new("/d/deku/armours/"+SP_STUFFO[random(sizeof(SP_STUFFO))]);
            break;
    }
}


void scrolls(object where) 
{
    object ob;
    int x;
    switch(random(2)) 
    {
        case 0:
            ob = new("/d/magic/scroll");
            ob->set_spell(4 + random(2));
            ob->move(where);    
            break;
        case 1:
            for(x = 0;x < random(2) + 1;x++) 
            {
                ob = new("/d/magic/scroll");
                ob->set_spell(2 + random(2));
                ob->move(where);
            }
            break;
    }
}

void healing_potion()
{
    object ob;
    ob = new("/d/common/obj/potion/healing");
    ob->set_uses(random(7) + random(7) + 1);
    return ob;
}		

void do_treasure(object where, string str) 
{
    if(str == "A") 
    {
        if(random(101) >= 82) 
        {
            switch(random(3)) 
            {
                case 0:
                    healing_potion()->move(where);
                    break;
                case 1:
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    break;
            }
        }
        if(random(101) >= 65) 
        {
            switch(random(2)) 
            {
                case 0:
                    norm_weapons()->move(where);
                    break;
                case 1:
                    norm_armors()->move(where);
                    break;
            }
        }
    }
 
    if(str == "B") 
    {
        if(random(101) >= 75) 
        {
            switch(random(3)) 
            {
                case 0:
                    healing_potion()->move(where);
                    break;
                case 1:
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    break;
            }
        }
        if(random(101) >= 45) 
        {
            switch(random(2)) 
            {
                case 0:
                    norm_weapons()->move(where);
                    break;
                case 1:
                    norm_armors()->move(where);
                    break;
            }
        }
    }

    if(str == "C") 
    {
        if(random(101) >= 45) 
        {
            switch(random(3)) 
            {
                case 0:
                    healing_potion()->move(where);
                    break;
                case 1:
                    norm_armors()->move(where);
                    break;
                case 2:
                    norm_weapons()->move(where);
            }
        }

        if(random(101) >= 60) 
        {
            switch(random(3)) 
            {
                case 0:
                    scrolls(where);
                    break;
                case 1:
                    scrolls(where);
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    potions(where);
                    special_stuff()->move(where);	
                    break;
            }
        }
    }
}