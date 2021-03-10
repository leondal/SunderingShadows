#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Sword Care Kit");
	set_id(({ "box", "wooden box", "decorative wooden box", "decorative box" }));
	set_short("%^RESET%^%^ORANGE%^A De%^RED%^c%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^a%^RED%^t%^RED%^ive%^ORANGE%^ Wooden Box%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is an elaborately decorated wooden box.  It has %^BOLD%^%^WHITE%^a small silver catch%^RESET%^%^ORANGE%^ with a tiny keyhole so that the box can be securely fastened.  Inside the box is everything a %^CYAN%^master swordsmith%^RESET%^%^ORANGE%^ would need to take proper care of an important blade.  There is a small jar of %^MAGENTA%^uchiko powder%^ORANGE%^, a sheet of high-quality %^GREEN%^wiping paper%^ORANGE%^, a bottle of %^YELLOW%^camellia oil%^RESET%^%^ORANGE%^ and a piece of %^

AVATAR
	);
	set_weight(3);
	set_value(250);
	set_lore(
@AVATAR
This is a very fine example of a kit used by master swordsmiths and swordsmen to care for very important blades.  Traditionally these items are used for the proper care of exquisite katana.  It is a mark of one who is very well versed in the traditions of katana to own a kit such as this.  The uchiko powder is formed with great care from dried polishing liquid and stone that has been very finely ground.  The paper has been made from the inner bark of a mulberry tree.

AVATAR
	);
	set_property("lore difficulty",10);
         set_item_bonus("craft, weaponsmith",2);
}
