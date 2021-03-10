#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
inherit "/std/riding_animal";

void create()
{
	::create();
	set_name("white charger");
	set_short("A white charger");
	set_id(({"horse","charger","white charger"}));
	set_long(
	"This beautiful white charger has been carefully groomed. His"+
	" mane and tail are a spotless white, and his forlock has been"+
	" carefully trimmed. His muzzle is a delicate pink, and he can't"+
	" quite seem to stand still, his tail is always twitching. He"+
	" looks like he's ready for action."
	);
	set_gender("male");
	set_race("horse");
	set_body_type("equine");
	set_size(2);
	set_hd(3,6);
	set_max_hp(150);
	set_hp(query_max_hp());
	set_value(200);
	set_max_distance(500);
	set_enter_room(" rides in on a white charger.");
	set_exit_room("leaves on a white charger.");
	set_vehicle_short("Charger");
	set_attack_limbs(({"right forehoof","left forehoof"}));
	set_attacks_num(1);
	set_damage(1,8);
      set_riding_level(15);
}
