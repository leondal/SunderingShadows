#include <std.h>
#include "../tharis.h"

inherit VENDOR;

void create() {
    ::create();
    set_gender("male");//not a typo
    set_name("Lialesh");
    set_race("half-drow");
    set_hd(50,8);
    set_hp(8000);
    set_alignment(5);
    set_class("mage");
    set_mlevel("mage",70);
    set_guild_level("mage",70);
    set_stats("intelligence",28);
    set_stats("wisdom",26);
    set_stats("strength",26);
    set_stats("charisma",20);
    set_stats("dexterity",16);
    set_stats("constitution",20);
    set_new_exp(60,"boss");
    set_mob_magic_resistance("average");
    set_spells(({"greater shout",
                    "greater shout",                    
                    "greater dispel magic",
                    "powerword kill",
                    "powerword stun"}));
    set_id(({ "Lialesh", "lialesh", "vendor","tailor","dealer","cloth dealer"}));
    set_short("%^RESET%^%^CYAN%^Lialesh,%^ORANGE%^ a cloth dealer%^RESET%^");
    set_long("%^CYAN%^She is humble femenine figre dressed head-to-toe, hiding her face, in various fabrics that hardly constitute any fashion, yet her feminine grace and manners can be considered alluring by themselves. She has her stall full of various exotic fabrics and line of customers always in front of her. Use %^ORANGE%^<list>%^CYAN%^ to view her wares and %^ORANGE%^<help shop>%^RED%^ to learn how to buy.");
    set_storage_room(STORAGE"cloth_vendor");    
}
    
