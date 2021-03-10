//thief_oghma.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 4/13/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("harlequin's mask");
	set_id(({ "mask", "harlequin's mask","half-mask" }));
	set_short("%^RESET%^%^RED%^H%^MAGENTA%^a%^RED%^r%^MAGENTA%^l%^RED%^e%^MAGENTA%^q%^RED%^u%^MAGENTA%^i%^RED%^n%^MAGENTA%^'%^RED%^s %^BOLD%^%^WHITE%^Mask%^RESET%^");
	set_obvious_short("A colorful half-mask");
	set_long(
@AVATAR
%^RED%^This half-mask is made out of the lightest and softest leather you have ever seen or felt.  The half-mask is shaped to rest flush against the face.  The nose of the mask is left open, though it does rise up over the brows and dips down to the cheek bones.  The leather has been tinted a deep red shade.   A diamond pattern of %^MAGENTA%^purple%^RESET%^ %^RED%^int%^MAGENTA%^e%^RED%^rs%^MAGENTA%^e%^RED%^cts the red leather, creating the harlequin's check.  %^YELLOW%^Yellow gold%^RESET%^%^RED%^ paint trims the eyes of the mask and the outer edges.  The mask can be tied into place with the use of a %^MAGENTA%^t%^BOLD%^%^BLACK%^w%^RESET%^%^RED%^i%^BOLD%^%^WHITE%^s%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d length of leather cording.%^RESET%^

AVATAR
	);
	set_lore(
@AVATAR
The Harlequin's Mask is commonly used in the Binder's faith to the south, invoking his role as the Patron of Bards and Lord of Music and Song.  Each follower is encouraged to create and personalize their own mask.  Some claim that the shape that the mask is intended to take comes to them via Oghma in their dreams.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" unties the colorful half-mask and pulls it very slowly from "+ETO->QP+" face.",ETO);
	tell_object(ETO,"%^MAGENTA%^You untie the mask and remove it very slowly, catching a brief %^RED%^unearthly%^MAGENTA%^ melody.");
	return 1;
}
