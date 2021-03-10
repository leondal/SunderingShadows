//Many thanks to Shar for creating this item :)
// updated dex and con bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("jerkin");
        set_id(({ "jerkin", "jerkin of the earth" }));
        set_short("%^ORANGE%^Jerkin %^GREEN%^of the %^ORANGE%^Earth%^RESET%^");
        set_obvious_short("A suede jerkin");
        set_long(
@AVATAR
%^GREEN%^The jerkin is two tones of suede.  The top is a darker olive.  The lower is a lighter olive/spring green.  The upper part of the jerkin is heavily decorated with swirled vine patterns burned into the suede.  The jerkin edge is longer in front and back than the sides, coming to a point.  The sleeves are made of two slightly overlapping pieces shaped like leaves. The leaf wrap in the lighter color wraps around the inside arm, and overlaps on top.
AVATAR
        );
        set_weight(4);
        set_value(1000);
        set_lore(
@AVATAR
The Jerkin of the Earth was first crafted by a group of druids devoted to Silvanus, to honor those that have done a great service to the Oak Father, and his followers.  Despite the withdrawal of Silvanus from this realm, those who adhere to his teachings or to nature itself still often wear the jerkin as a sign of their faith in the natural world.
AVATAR
        );
        set_property("lore difficulty",8);
        set_type("clothing");
        set_limbs(({ "torso" }));
        set_size(2);
        set_property("enchantment",1);
set_ac(0);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_item_bonus("constitution",1);
        set_item_bonus("dexterity",-1);
}
int wear_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^ORANGE%^You slip on the jerkin, feeling as if you are connected
to the earth.%^RESET%^");
        return 1;
}
int remove_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^GREEN%^You slip off the jerkin.%^RESET%^");
        return 1;
}

