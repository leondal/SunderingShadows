#include <std.h>
#include "../newbie.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Adresa");
	set_short("Adresa, the Offestry seamstress");
	set_id(({"Adresa","adresa","seamstress","shop keeper","shopkeeper"}));
	set_long(
	"Adresa is a charming young woman who has a tendency to hum while she works,"+
	" something that earned her shop the rather silly nickname it has. She is a"+
   " good seamstress, however, and everyone in Offestry comes to her for the"+
	" things they can't make themselves. She has pale blonde hair and warm brown"+
	" eyes and seems quite happy with her work here. If you want to have a closer"+
	" look at anything in the shop, she will be happy to show it to you."
	);
	set_race("human");
	set_gender("female");
	set_hd(19,4);
	set_alignment(2);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	remove_std_db();
	set_items_allowed("clothing");
    set_nwp("tailoring",4);
	set_storage_room(ROOMS"special/tailor_storage");
new("/d/newbie/obj/misc/lpouch.c")->move(TO);
}
