//

#include <std.h>

inherit ARMOUR;

object owner;

void create(){
   ::create();
   set_name("key");
   set_id(({"alliance dungeon key", "key" }));
   set_short("a key on a steel hoop");

   set_long(
@OLI
This is a fairly complex looking key on a steel hoop which can be used to
suspend the key from someone's belt.  
OLI
   );
   set_type("clothing");
   set_limbs(({"torso"}));

   set_weight(1);
}

void set_owner(object ob) {
  owner = ob;
}

void init(){
    ::init();
    add_action("standdown", "standdown");
    add_action("makereport", "makereport");
    add_action("stopblocking", "stopblocking");
    add_action("unlockdungeon", "unlockdungeon");
    add_action("lockdungeon", "lockdungeon");

}

int standdown(string str) {
	if(ETO != owner) return 1;
	owner->stand_down(find_player(lower_case(str)));
	return 1;
}

int makereport(string str) {
	if(ETO != owner) return 1;
	owner->start_report();
	return 1;
}

int stopblocking(string str) {
	if(ETO != owner) return 1;
	owner->stop_blocking(find_player(lower_case(str)));
	return 1;
}

int unlockdungeon(string str) {
	if(ETO != owner) return 1;
	owner->unlock_dungeon(find_player(lower_case(str)));
	return 1;
}

int lockdungeon(string str) {
	if(ETO != owner) return 1;
	owner->lock_dungeon(find_player(lower_case(str)));
	return 1;
}

void save_me(string file){return 1;}
