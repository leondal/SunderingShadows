#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
inherit "/std/riding_animal";

void create()
{
	::create();
	set_name("black stallion");
	set_short("A fiery black stallion");
	set_id(({"stallion","horse","black stallion","fiery stallion","fiery black stallion"}));
	set_long(
	"This high strung stallion is pure black. He is constantly prancing about,"+
	" shifting his weight impatiently from one leg to the next and eager to be"+
	" moving again. He holds his head high and is probably quite stubborn. He"+
	" snorts rather disdainfully at you and paws the ground."
	);
	set_gender("male");
	set_race("horse");
	set_body_type("equine");
	set_size(2);
	set_hd(2,6);
	set_max_hp(120);
	set_hp(query_max_hp());
	set_value(150);
	set_max_distance(500);
	set_enter_room(" gallops in on a fiery stallion.");
	set_exit_room("gallops out on a fiery stallion.");
	set_vehicle_short("Stallion");
	set_attack_limbs(({"right forehoof","left forehoof"}));
	set_attacks_num(1);
	set_damage(1,8);
      set_riding_level(12);
}
