#include <std.h>
#include "../tharis.h"

inherit VENDOR;

void create() {
    ::create();
    set_gender("female");
    set_name("Raadrash");
    set_race("demon");
    set_hd(30,3);
    set_hp(query_hp());
    set_stats("strength",20);
    set_stats("dexterity",14);
    set_stats("constitution",20);
    set_stats("wisdom",16);
    set_stats("intelligence",12);
    set_stats("charisma",16);
    set_id(({ "Raadrash", "raadrash", "vendor","smith","dealer","metal dealer"}));
    set_short("%^RESET%^%^RED%^Raadrash,%^ORANGE%^ metal dealer%^RESET%^");
    set_long("%^RED%^Before you stands copper-skinned proud creature with wings covered in metal feathers. It is dressed in simple leather jacket and leather pants. A tail with poison-tipped sting dangerously tosses about behind her. Her features are beautiful, figure is slim, but she holds a stance of seasoned warrior unfit for her occupationb. She holds a tray with assortment of ingots with inhuman ease and stands in front of a cart. Use %^ORANGE%^<list>%^RED%^ to view her wares and %^ORANGE%^<help shop>%^CYAN%^ to learn how to buy.");
  set_storage_room(STORAGE"met_vendor");    
}
    
