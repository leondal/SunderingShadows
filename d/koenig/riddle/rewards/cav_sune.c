//cav_sune.c - reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
        ::create();
        set_name("lance of the ruby rose");
        set_id(({ "lance", "sune lance","lance of the ruby rose" }));
        set_short("%^BOLD%^%^WHITE%^Lance of the %^BOLD%^%^RED%^R"+
		"%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y "+
		"%^BOLD%^%^RED%^Rose%^RESET%^");
        set_obvious_short("A medium ivory lance");
        set_long(
@CYTHERA
%^BOLD%^%^WHITE%^The body of medium lace has been crafted out of pure ivory that has been polished to a high sheen.  A %^YELLOW%^golden%^BOLD%^%^WHITE%^ handle has been attached to the ivory lance, giving plenty of room for one to get a good grip.  The tip of the lance has been created out of a %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y%^BOLD%^%^WHITE%^ gem, sharpened to a fine point.  On opposite sides, at the base of the lance, twin %^RESET%^%^RED%^ruby red%^BOLD%^%^WHITE%^ roses have been painted on to the ivory lance.   In full bloom, the %^RESET%^%^RED%^deep crimson%^BOLD%^%^WHITE%^ petals of the roses unfold to display an aesthetically pleasing image.  A pure %^YELLOW%^gold band%^BOLD%^%^WHITE%^ wraps around the ivory base of the lance.
CYTHERA
        );
        set_lore(
@CYTHERA
This is a Holy Weapon of Sune used by her cavaliers and knights in battles
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
       tell_object(ETO,"%^RED%^The ruby tip of the lance starts to"+
		" glow with a fiery radiance just before you "+
		"pierce "+targ->QCN+"!");
       tell_object(targ,"%^RED%^The ruby tip of "+ETOQCN+"'s lance starts"+
		" to glow with a fiery radiance just before "+ETO->QS+" "+
		"pierces you!");
       tell_room(EETO,"%^RED%^The ruby tip of "+ETOQCN+"'s lance starts"+
		" to glow with a fiery radiance just before "+ETO->QS+" "+
		"pierces "+targ->QCN+".",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
