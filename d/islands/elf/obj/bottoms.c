#include <std.h>
inherit "/d/common/obj/clothing/breeches";

void create()
{
	::create();
   set_obvious_short("%^YELLOW%^A pair of tan leather leggings%^RESET%^");
	set_name("soggy bottoms");
	set_short("%^BLUE%^soggy bottoms%^RESET%^");
    set_obvious_short("%^BLUE%^Sea soaked trousers%^RESET%^");
    set_id(({"pants","soggy bottoms","bottoms","trousers"}));
 	set_long(
	"These trousers are made from frayed threads mixed "+
    "with a tangle of sea plant life.   They look horrible "+
    "like something a sea monster would wear."	);
	set_lore("The style of these pants is one from centuries "+
    "ago.  They should be dust by now.  Dark resentment became"+
    " magic and the pants just refused to pass on while the"+
    " wearers soul could not rest.");
	set_property("lore",32);  
	set_property("enchantment",4+random(2));
    set_item_bonus("cold resistance",-5);
    set_item_bonus("fire resistance",10);
	set_item_bonus("constitution",2);
    set_item_bonus("charisma",-1);
    set_item_bonus("dungeoneering",2);
	set_value(1000);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}
int wearme()
{
	tell_object(ETO,"You pull on the trousers and feel the wetness on your backside.");
	tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" pulls"+
	" on a pair of soggy trousers.",ETO);
	return 1;
}

int removeme()
{
	tell_object(ETO,"You remove your trousers and your"+
    " backside feels the cold air againsts the wetness.");
	return 1;
}
