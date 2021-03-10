#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("boy doll");
	set_id(({ "boy doll", "fabric doll", "fabric toy", "cloth doll", "cloth boy doll", "cloth toy", "doll", "toy" }));
	set_short("%^RESET%^%^CYAN%^a cloth doll in the shape of a little boy%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a cloth doll in the shape of a little boy%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This little doll is made entirely out of cloth.  His face, arms and hands are all sewn from soft %^ORANGE%^tan cotton %^CYAN%^while his clothing is made out of a coarser %^BOLD%^%^BLACK%^burlap %^RESET%^%^CYAN%^material.  %^YELLOW%^Yellow yarn %^RESET%^%^CYAN%^extends from the top of his head under a small %^BOLD%^blue cap%^RESET%^%^CYAN%^.  A matching %^BOLD%^blue vest %^RESET%^%^CYAN%^with %^YELLOW%^yellow trim%^RESET%^%^CYAN%^ is fitted over a %^GREEN%^light green shirt %^CYAN%^that is tucked into %^ORANGE%^brown pants%^CYAN%^.  A set of %^BOLD%^%^BLACK%^cloth shoes %^RESET%^%^CYAN%^and a %^RESET%^braided belt %^CYAN%^finish out his outfit.  Two small %^BLUE%^blue buttons %^CYAN%^have been used for eyes while a %^BOLD%^%^BLACK%^black button %^RESET%^%^CYAN%^creates a nose.  %^RED%^Red yarn %^CYAN%^has been sewn into a smile to complete the face.  Soft lambs wool has been used to stuff the body, making the doll perfect for cuddling and playing with.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(120);
}