#include <std.h>
inherit "/std/riding_animal";

void create()
{
	::create();
	set_name("a rugged camel");
	set_short("%^BOLD%^%^YELLOW%^rugged camel%^RESET%^");
    set_id(({"camel", "rugged camel"}));
	set_long("%^BOLD%^%^YELLOW%^This camel looks fairly young. "+
    "His body is covered in a thick but very short fur. Save for around "+
    "his neck where it is much longer and shaggier. There are two large "+
    "humps on his powerful back, which provide a valley of sorts between them "+
    "for a rider to sit. His body is muscular and rugged looking, as if he "+
    "has worked very hard in his so far short life. He has big brown eyes "+
    "which looks intelligent and his ears stick straight up to the sides."+
    "%^RESET%^");
	set_gender("male");
	set_race("camel");
	set_body_type("equine");
	set_size(1);
	set_hd(20,3);
	set_max_hp(245 + random(25));
	set_hp(query_max_hp());
	set_value(5000);
	set_max_distance(1000);
	set_enter_room(" rides in on a rugged camel.");
	set_exit_room("rides out on a rugged camel.");
	set_vehicle_short("camel");
	set_attack_limbs(({"right forehoof","left forehoof"}));
	set_attacks_num(1);
	set_damage(1,4);
    set_riding_level(18);
}
