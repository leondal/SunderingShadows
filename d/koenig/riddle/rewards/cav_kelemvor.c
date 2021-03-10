//cav_kelemvor.c - reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
        ::create();
        set_name("lance of the jade scarab");
        set_id(({ "lance", "kelemvor lance","lance of the jade scarab" }));
        set_short("%^BOLD%^%^WHITE%^Lance of the %^BOLD%^%^GREEN%^J"+
		"%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^e "+
		"%^BOLD%^%^GREEN%^Scarab%^RESET%^");
        set_obvious_short("A medium silver lance");
        set_long(
@CYTHERA
%^BOLD%^%^WHITE%^The body of this medium lance has been crafted out of pure silver that has been polished to a high sheen.  A sculpted silver handle has been attached to the silver lance, giving plenty of room for one to get a good grip.  The tip of the lance has been created out of a %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^ gem, sharpened to a fine point.  On opposite sides, at the base of the lance, twin %^RESET%^%^GREEN%^scarab beetles%^BOLD%^%^WHITE%^ have been inlaid into the silver lance.  %^RESET%^%^ORANGE%^Tomb jade%^BOLD%^%^WHITE%^ and %^GREEN%^jade%^BOLD%^%^WHITE%^ has been set into the body of the scarab beetle.
CYTHERA
        );
        set_lore(
@CYTHERA
This is a Holy Weapon of Kelemvor used by his cavaliers and knights in battles
against the enemies of his church and faith. Only the most dedicated
knights can ever hope to wield such a fine weapon, and those that do are
proclaimed as heroes of the faith.
CYTHERA

        );
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^GREEN%^The jade tip of the lance starts to"+
		" glow with a vibrant light just before you "+
		"pierce "+targ->QCN+"!");
       tell_object(targ,"%^GREEN%^The jade tip of "+ETOQCN+"'s lance starts"+
		" to glow with a vibrant light just before "+ETO->QS+" "+
		"pierces you!");
       tell_room(EETO,"%^GREEN%^The jade tip of "+ETOQCN+"'s lance starts"+
		" to glow with a vibrant light just before "+ETO->QS+" "+
		"pierces "+targ->QCN+".",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
