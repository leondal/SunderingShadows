//cav_auppenser.c - reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
        ::create();
        set_name("lance of the probing mind");
        set_id(({ "lance", "auppenser lance","lance of the probing mind" }));
        set_short("%^RESET%^%^CYAN%^Lance of the %^BOLD%^%^BLUE%^Probing"+
		" %^CYAN%^Mind%^RESET%^");
        set_obvious_short("A large crystal lance");
        set_long(
@CYTHERA
%^CYAN%^The body of large lace has been crafted out of pure %^BOLD%^%^CYAN%^crystal%^RESET%^%^CYAN%^ that has been polished to a high sheen.  A %^ORANGE%^bronze%^CYAN%^ handle has been attached to the crystal lance, giving plenty of room for one to get a good grip.  The tip of the lance has been sharpened to a fine point.  Inside the crystal a mystrious %^BOLD%^%^CYAN%^cyan%^RESET%^%^CYAN%^ fog can be seen, swirling around in a soothing and tranquil way.
CYTHERA
        );
        set_lore(
@CYTHERA
This is a Holy Weapon of Auppenser used by his cavaliers and knights in battles
against the enemies of her church and faith. Only the most dedicated
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
       tell_object(ETO,"%^CYAN%^The fog within the lance swirls around faster"+
		" you can feel an invisible force pierce through "+targ->QCN+"'s mind.");
       tell_object(targ,"%^CYAN%^You snap your head back as you feel a force "+
		"tearing through your mind!");
       tell_room(EETO,"%^CYAN%"+targ->QCN+" snaps "+targ->QP+" head back and cries"+
		" out in pain!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
