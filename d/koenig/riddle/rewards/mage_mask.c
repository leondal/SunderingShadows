//mage_mask.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of concealment");
	set_id(({ "robe", "Robe of Concealment" }));
	set_short("%^BOLD%^%^BLACK%^Robe of %^CYAN%^C%^GREEN%^o%^MAGENTA%^n%^GREEN%^c%^CYAN%^e%^MAGENTA%^a%^GREEN%^l%^CYAN%^m%^GREEN%^e%^MAGENTA%^n%^CYAN%^t%^RESET%^");
	set_obvious_short("A diamond patterned robe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These robes are quite %^CYAN%^c%^GREEN%^o%^MAGENTA%^l%^CYAN%^o%^GREEN%^r%^MAGENTA%^f%^CYAN%^u%^GREEN%^l%^BLACK%^, if anything.  An overrobe made of a soft gray cotton hangs about the wearer's shoulders with a strip of fabric that falls down to about knee length.  Underneath the gray mantle-like piece, a motley robe of %^GREEN%^lime green%^BLACK%^, %^CYAN%^robin's egg blue%^BLACK%^ and %^MAGENTA%^mauve%^BLACK%^ hangs.  The colors are arranged in a diamond pattern, similar to what one might see on a jester or a flamboyant entertainer.  The long-sleeved underrobes features large puffy sleeves that droop over one's knuckles.  The robe is cut short, though, falling a tad below the knees.  You have to wonder who would ever design such a gaudy type of clothing.

AVATAR
	);
	set_lore(
@AVATAR
The Robes of Concealment, some might say, are a cursed item.  For how can something so bright and gaudy conceal one?  Everyone knows that dark clothing works better to conceal and hide in the shadows.  The only thing something like this could do is attract attention!

AVATAR
	);
      set_property("lore difficulty",12);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func()
{
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The clothing refuses to fit to your form!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries to put on the clothing.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
	tell_object(ETO,"%^BOLD%^%^BLACK%^Slipping on the robes, you find some pockets hidden in the diamond pattern of the underrobe.  Suddenly you understand that the robes are meant to conceal your faith from others!  For who would expect a Maskarran in bright clothing!");
	return 1;
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You smirk as you remove the robes, knowing their true meaning.");
	return 1;
}
