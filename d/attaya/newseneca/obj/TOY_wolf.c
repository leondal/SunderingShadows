#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed wolf toy");
	set_id(({ "toy", "wolf", "stuffed wolf", "stuffed wolf toy", "wolf toy", "toy wolf" }));
	set_short("%^BOLD%^%^WHITE%^a %^BLACK%^wolf shaped %^WHITE%^stuffed animal%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^BLACK%^wolf shaped %^WHITE%^stuffed animal%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This stuffed animal is in the shape of a muscular wolf covered in a thick, bushy coat of %^BOLD%^%^BLACK%^gray %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^white %^RESET%^%^CYAN%^fur.  The %^BOLD%^%^BLACK%^deep gray %^RESET%^%^CYAN%^runs along the top of his head, over his upright ears and down along the spine to his bristly tail.  %^YELLOW%^Amber buttons%^RESET%^%^CYAN%^ have been used as eyes for this plush toy while a %^BOLD%^%^BLACK%^black button%^RESET%^%^CYAN%^ has been used for his nose and %^BOLD%^%^BLACK%^black yarn%^RESET%^%^CYAN%^ has been stitched to form his mouth.  Soft and snuggly, he would make a %^BOLD%^%^WHITE%^fierce%^RESET%^%^CYAN%^ protector of any small child.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(200+random(16));
}