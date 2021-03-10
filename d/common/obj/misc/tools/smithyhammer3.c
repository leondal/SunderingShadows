#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("smithy hammer");
	set_id(({ "hammer", "smithy's hammer" }));
	set_short("%^RESET%^A %^GREEN%^sleek %^BOLD%^%^BLUE%^steel %^BLACK%^smithy's hammer %^RESET%^with a %^RESET%^%^MAGENTA%^mahogany handle%^RESET%^");
	set_obvious_short("%^RESET%^A %^GREEN%^sleek %^BOLD%^%^BLUE%^steel %^BLACK%^smithy's hammer %^RESET%^with a %^RESET%^%^MAGENTA%^mahogany handle%^RESET%^");
	set_long(
@AVATAR
This is a sleek smithy's hammer.  The %^BOLD%^%^BLUE%^steel %^RESET%^head is about five inches long and two inches thick and has been forged with a flat facing on one side and a round ball peen on the other.  The handle is carved out of sleek %^RESET%^%^MAGENTA%^mahogany %^RESET%^and is a little over a foot long.  A %^BOLD%^%^GREEN%^sleek %^RESET%^leather grip has been fastened midshaft on the handle to allow for a firmer grip.
AVATAR
	);
	set_weight(5);
	set_value(250);
}


