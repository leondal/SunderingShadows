#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create()
{
        ::create();
        set_name("Plate of the Lion");
        set_id(({"plate","armour","full plate","fullplate",
		"plate of the lion","Plate of the Lion","lion plate","lion's plate"}));
        set_short("%^YELLOW%^Plate of the Lion%^RESET%^");
        set_obvious_short("%^YELLOW%^A suit of golden fullplate%^RESET%^");
        set_long(
        "%^YELLOW%^This full suit of golden plate shines with a golden"+
        " radiance. The image of a proud lion's head is magically"+
        " imprinted onto the armor, vivid in color, strength, and"+
        " glory. The rest of the plate is spotless and there are no"+
        " dents to tell of past battles. This plate has withstood"+
        " the ravages of time and shall loyally serve any master"+
        " it deems worthy. %^RESET%^\n");
        set_lore("Crafted by the elves of house Agrashalva, the Plate of"+
                " the Lion was a treasured suit of armor for the royal"+
                " guards of the forest kingdom of Selu'havessthor.  Only "+
                "the finest of the elven warriors were given the honor"+
                " of wearing one of these suits.  The Golden Lions of "+
                "Agrashalva were as humankind would think of cavaliers"+
                ".  Riding on hippogriffons and wielding lances and long"+
                " spears, they patrolled the forests as well as serving "+
                "as the personal bodyguards to the royal family of "+
                "Selu'havessthor.  This, however, was their downfall.  When "+
                "Heasirretyn's scions were accused of responsibility for the "+
                "elven crown wars, their participation in the purge all but "+
                "wiped their house from existence.");
        set_property("lore",22);
        set_property("enchantment",4);
		set_item_bonus("negative energy resistance",2);
		set_item_bonus("damage resistance",2);
        set_size(-1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
        set_value(5000);
}

int wearme(){
     if((int)ETO->query_highest_level() < 25) {
        tell_object(ETO,"The armor doesn't fit you!");
        return 0;
     }
        if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"%^YELLOW%^The Plate of the Lion roars"+
                " proudly.");
                tell_room(EETO,"%^YELLOW%^"+ETO->QCN+"'s"+
                " Plate of the Lion roars proudly.",ETO);
                        ETO->set_property("good item",1);
                return 1;
        }
        if(ALIGN->is_evil(ETO)) {
                tell_object(ETO,"%^YELLOW%^The Plate of the Lion growls"+
                " and refuses to be worn by one such as you.");
                tell_room(EETO,"%^YELLOW%^The Plate of the"+
                " lion growls angrily at "+ETO->QCN+" as"+
                " "+ETO->QS+" tries to wear it.",ETO);
                return 0;
        }else {
                tell_object(ETO,"%^YELLOW%^The Plate of the Lion seems"+
                " content to be worn by you for now.");
                set_ac(8);
                return 1;
        }
}

int removeme(){
        if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"%^YELLOW%^The Plate of the Lion roars"+
                        " out triumphantly as you remove it to relax after a"+
                        " long day of battle.");
                tell_room(EETO,"%^YELLOW%^The Plate of the"+
                        " Lion roars out triumphantly as "+ETO->QCN+" removes"+
                        " it.",ETO);
                return 1;
        }else {
                tell_object(ETO,"%^YELLOW%^The Plate of the Lions makes no "+
                        "sound as you remove it.");
                return 1;
        }
}
