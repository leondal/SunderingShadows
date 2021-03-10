#include <std.h>
inherit "/d/common/obj/armour/field.c";

void create(){
	::create();
	set_name("eagle plate");
	set_id(({"field plate","plate","eagle plate","shiney plate","shiney field plate","shining field plate","shining plate","armor","set of full plate","set of plate","Full Plate","Plate","polished plate","polished full plate","set of polished full plate","a set of polished full plate"}));
set_short("%^BOLD%^%^WHITE%^Silver Eagle Plate%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A suit of polished field plate%^RESET%^");
	set_long(
	"%^BOLD%^%^WHITE%^This set of field plate has been brightly polished so that"+
	" it is spotless. On the breastplate the image of an eagle in"+
	" flight has been carved in silver. Its feathers are done in"+
	" intricate detail and it looks sharp and alert. It is a"+
	" truly magnificent animal. A tasset of polished steel edged with "+
        "%^YELLOW%^gold%^WHITE%^ is attached to the breastplate of the"+
        " armor, adding to the stunning workmanship.  Rounded blunt shoulders and"+
        " smooth even plates create the protective shell of this field armor.%^RESET%^"
	);
	set_lore("The Silver Eagles were once the guard force that "+
		"protected elder Antioch.  The ancient order of guards "+
		"was passed down from generation to generation, making it"+
		" nearly impossible for those born outside of Antioch to "+
		"even be given a position.  The guards were always lead"+
		" by a follower of Helm, this position as well was passed"+
		" down within a bloodline.  The Silver Eagles were seen as"+
		" heroes and well respected people in Old Antioch before "+
		"the curse consumed the city.");
	set_property("lore",9);
	//set_weight(50);
    //set_ac(7);
	set_value(625);
	set_size(2);
	//set_type("armour");
	//set_limbs(({"torso"}));
	set_property("enchantment",3);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"For a moment you think you hear the"+
		" angry screech of an eagle, but it must've been your"+
		" imagination.");
set_ac(7);
         ETO->set_property("good item",1);
		return 1;
	}
	else {
		tell_object(ETO,"Your heart swells with pride as you"+
		" put on the set of shining field plate.");
set_ac(8);
         ETO->set_property("good item",1);
		return 1;
	}
}

int removeme()
{
	if(ALIGN->is_evil(ETO)) {
      ETO->set_property("good item",-1);
		return 1;
	}
	else {
		tell_object(ETO,"You take great care as you remove the"+
		" suit of field plate.");
      ETO->set_property("good item",-1);
		return 1;
	}
}
