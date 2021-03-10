//cleric_mystra.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("sapphire staff");
	set_id(({ "staff", "sapphire staff", "staff of the holy star" }));
	set_short("%^RESET%^%^BLUE%^Staff of the %^RED%^Holy %^BOLD%^%^WHITE%^Star%^RESET%^");
	set_obvious_short("A sapphire staff");
	set_long(
@AVATAR
%^BLUE%^This five foot long staff is made from one solid sapphire gem, which has been polished to a smooth finish.  A %^BOLD%^%^WHITE%^glittering mesh%^RESET%^%^BLUE%^ wraps itself around the staff.  The mesh is unlike anything you have ever seen before, it almost seems to look like molten silver, but has an etheral property to it.  Motes of light flicker and twinkle along the mesh, and reflect off the sapphire staff.  The crown of the staff is set with a %^BOLD%^%^WHITE%^mithril%^RESET%^%^BLUE%^ six pointed star, with inlays of %^RED%^ruby%^BLUE%^ gems on both sides.

AVATAR
	);
	set_weight(5);
	set_lore(
         "The Staff of the Holy Star is attibuted to a cleric of the Lady "+
         "of Mysteries' faith, Iphoginia Gurtelthaze.  Iphoginia is credited "+
         "by many, inside and outside of the faith, for being the sole reason "+
         "why Mystra's faith took off as fast as it did.  With her "+
         "understanding of negotiations, politics and her dedication to The "+
         "Mother of All Magic, Iphoginia was able to spread the teachings of "+
         "Mystra to the mages of the lands.  She is also acredited to the "+
         "founding of the Tabor Mage Tower, providing the needed funds from "+
         "her crusades to the constrution and winning over the leaders of Tabor "+
         "with her grace and wise words.  The Mother of All Magic was so pleased "+
         "with Iphoginia's work and dedication that some claim she blessed the "+
         "young cleric with a staff made of the art itself.  Iphoginia, like "+
         "most Mystraians, had a special loathing for followers of the Dark Sun, "+
         "Cyric.  Her involvement in Tabor is what lead to the ousting of a cell "+
         "of Cyristis that were looking to gain a foothold in the city.  After a "+
         "brutal attack on the city of Tabor and the acolytes of Mystra in the "+
         "city, Iphoginia made it her personal goal to hunt down the Cyrists "+
         "responsable for this act. There are rumors saying though that "+
         "Iphoginia was unable to fullfill this last goal of hers, and met her "+
         "end along the road between Azha and Tharis."
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(1,6);
	set_large_wc(1,6);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BLUE%^You unwield the staff, but keep it close by.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The staff held by "+ETOQCN+" glows with a bright %^BLUE%^blue%^WHITE%^-white glow and discharges seven whirling stars of energy into "+targ->QCN+"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The staff glows with a bright %^BLUE%^blue%^WHITE%^-white glow and discharges seven whirling stars of energy into "+targ->QCN+"");
	tell_object(targ,"%^BOLD%^%^WHITE%^The staff held by "+ETOQCN+" glows with a bright %^BLUE%^blue%^WHITE%^-white glow and discharges seven whirling stars of energy into you!");
		return roll_dice(3,4)+-1;	}
}