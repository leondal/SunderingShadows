#include <std.h>
#include "../elf.h"
inherit "/d/common/obj/clothing/gloves";

void create()
{
    ::create();
    set_name("Gloves of the Vampire");
    set_short("%^BOLD%^%^BLACK%^Gloves of The Vampire%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^A pair of black lace gloves%^RESET%^");
    set_id(({ "gloves", "gloves of the vampire", "black gloves" }));
    set_long(
        "These gloves have been made from the finest of silk.  Several "+
        "red runes have woven into the palm.  They glow with a powerful"+
        " aura of negative energy."
        );
    set_lore("A creation from the enchanters long lost to time.  "+
    "These gloves likely were made for someone that fancies "+
    "themselves a powerful necromancer.");
    set_property("lore", 35);
    set_value(2500);
    set_property("enchantment", 4+random(3));
    set_item_bonus("dungeoneering", 2);
    set_wear((: TO, "wearme" :));
    set_remove((: TO, "removeme" :));
    set_struck((:TO,"strike_func":));
}

int wearme()
{
    if (ALIGN->is_good(ETO)) {
        tell_object(ETO, "You can't bring yourself to wear the evil gloves.");
        return 0;
    }
    if (ETO->query_property("good item")) {
        tell_object(ETO, "The gloves refused to be worn while you are using such goodly items!");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^BLACK%^The gloves fit perfectly, you can hardly feel that they're there.");
    ETO->set_property("evil item", 1);
    return 1;
}

int removeme()
{
    tell_object(ETO, "%^MAGENTA%^You slowly remove your hands from the dark safety of the gloves.");
    ETO->set_property("evil item", -1);
    return 1;
}
int strike_func(int damage, object what, object who){
        if(!objectp(ETO)) return 1;
		if(!random(5)){
        tell_room(environment(query_worn()),"%^BOLD%^"+
            ""+who->QCN+"'s blow strikes"
            +ETO->QCN+" and their hands form into a spell.",({ETO,who}));
        tell_object(ETO,"%^BOLD%^As the blow lands against your hands you strike back on your own.");
        tell_object(who,"%^BOLD%^You strike the hands of "+ETO-QCN+"and their gloves begin to glow.");
        new("/cmds/spells/v/_vampiric_touch")->use_spell(ETO, who, 50, 100, "mage");
        return (damage);
       }
}