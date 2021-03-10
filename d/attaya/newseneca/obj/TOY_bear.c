#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("toy bear");
	set_id(({ "toy bear", "toy", "bear", "stuffed bear", "stuffed bear toy", "stuffed animal","stuffed animalz"})); //stuffed animalz is the id needed for loading into the store
	set_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a bear%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a bear%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Padded with plenty of soft cotton, this little stuffed animal is shaped like a bear. Durable light brown wool has been used to make the body of this stuffed animal with the curly strands of lambs fur cut short. Small %^BOLD%^%^BLACK%^black buttons %^RESET%^%^ORANGE%^and one larger %^BOLD%^%^BLACK%^black button %^RESET%^%^ORANGE%^have been used for the eyes and nose of this toy, while a %^GREEN%^small green vest %^ORANGE%^with %^YELLOW%^yellow buttons %^RESET%^%^ORANGE%^has been fitted around his body to give contrast. %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(200);
}