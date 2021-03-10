#include <std.h>
inherit "/std/riding_animal";

// changed race to pony & took out horse in ids for less confusion *Styx* 12/21/04

void create()
{
	::create();
	set_name("mountain pony");
	set_short("A shaggy mountain pony");
        set_id(({"pony","mountain pony","shaggy pony","shaggy mountain pony"}));
	set_long(
	"This is a rather shaggy mountain pony. He looks as though he's"+
	" in need of a grooming, but his coat is furry due to the cold"+
	" mountain climate to which he is accustomed. He is a dark brown"+
	" color with black mane and tail. Mountain ponies are known for"+
	" their sure footedness along rocky trails, but they are too"+
	" small for anyone larger than a child to ride and are mostly"+
	" used as pack animals."
	);
	set_gender("male");
	set_race("pony");
	set_body_type("equine");
	set_size(1);
	set_hd(4,3);
	set_max_hp(80);
	set_hp(query_max_hp());
	set_value(80);
	set_max_distance(500);
	set_enter_room(" trots in on a sure footed mountain pony.");
	set_exit_room("trots out on a sure footed mountain pony.");
	set_vehicle_short("Pony");
	set_attack_limbs(({"right forehoof","left forehoof"}));
	set_attacks_num(1);
	set_damage(1,4);
      set_riding_level(8);
}
