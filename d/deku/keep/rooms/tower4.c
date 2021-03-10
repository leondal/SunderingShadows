#include <std.h>
#include "../keep.h"
#define MIRROR_ITEMS ({"mirrors","mirror"})
inherit HTOWER;
object ob;

void create() {
	int x;
	::create();
	set_property("no teleport",1);
 set_long(TO->query_long() + "  Every wall of this chamber is lined with hundreds "+
		"of %^MAGENTA%^mirrors%^RESET%^ in every imaginable shape and size, constructed of "+
		"countless different materials.  A spiral, %^BOLD%^%^WHITE%^stone staircase%^RESET%^ "+
		"leads to the level below.%^RESET%^");	
	
	set_exits(([
		"down" : KEEPR + "tower3"
		] ));
 for(x = 0;x < sizeof(MIRROR_ITEMS);x++) {
	add_item(MIRROR_ITEMS[x], "The highly polished looking glasses gleam in their frames of marble, "+
		"rare woods, wrought iron, brass, silver, and even gold.  A rare %^BOLD%^%^WHITE%^"+
		"platinum%^RESET%^ framed mirror on the eastern wall catches your attention.  Maybe "+
		"you should look closer?");
	}

	add_item("platinum mirror", "%^BOLD%^%^WHITE%^This tall looking glass is framed in platinum.  "+
  "Its been kept in magnificent shape and the beauty of the reflected image is almost "+
		"entrancing.  If you could only touch it.%^RESET%^");
}

void init() {
	::init();
	add_action("touch_function","touch");
	add_action("enter_function","enter");
	
}

int enter_function(string str) {
	object *stuff;
	int i,j, flag;
	
	if(str == "mirror" || str == "Mirror") {
		write("There are hundreds, which one do you want to enter?");
		return 1;
	}
	if(str == "platinum mirror" || str == "Platinum Mirror") {
		stuff = TP->all_armour();
		j = sizeof(stuff);
		for(i=0;i<j;i++){
			if(!objectp(stuff[i])) continue;
			if((string)stuff[i]->query_type() == "ring"){
				if(member_array("bone key ring",stuff[i]->query_id()) != -1){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1) {
			write("You step through the %^BOLD%^%^WHITE%^platinum mirror!%^RESET%^");
			if(!TP->query_invis()) {
				tell_room(environment(TP),"You watch as " + TPQCN + " steps through the %^BOLD%^%^WHITE%^platinum mirror%^RESET%^!",TP);
			}
			TP->move_player(KEEPR + "dungeon1");
			return 1;
		}
		write("The mirror is quite solid... you cannot enter it.%^RESET%^");
		return 1;
	}
		write("Why not try to enter one of the mirrors?");
		return 1;
}


int touch_function(string str) {
	object *stuff;
	int i,j, flag;
	
	if(str == "mirror" || str == "Mirror") {
		write("There are hundreds, which do you want to touch?");
		return 1;
	}
	
	
	if(str == "Platinum Mirror" || str == "platinum mirror") {
		stuff = TP->all_armour();
		j = sizeof(stuff);
		for(i=0;i<j;i++){
			if(!objectp(stuff[i])) continue;
			if((string)stuff[i]->query_type() == "ring"){
				if(member_array("bone key ring",stuff[i]->query_id()) != -1){
					flag = 1;
					break;
				}
			}
		}
	if(flag == 1) {
			write("Entranced by the beautiful reflection you reach out and touch the %^BOLD%^%^WHITE%^platinum mirror%^RESET%^ and your hand slips through it!");
			if(!TP->query_invis()) {
				tell_room(environment(TP),"You watch as " + TPQCN + " sticks " + TP->query_possessive() + " hand through the %^BOLD%^%^WHITE%^platinum%^RESET%^ mirror!",TP);
			}
			return 1;
		}

                        write("Entranced by the beautiful reflection you reach out and touch the %^BOLD%^%^WHITE%^platinum mirror%^RESET%^.%^RESET%^");
			if(!TP->query_invis()) {
				tell_room(environment(TP),"You watch as " + TPQCN + " touches the %^BOLD%^%^WHITE%^platinum mirror%^RESET%^.%^RESET%^",TP);
			}
			return 1;
		}
	
		write("Why not try to touch one of the mirrors?");
		return 1;
	
	
}

void reset() {
	int x;
	::reset();
	
	if(!present("keep general") && random(12) >= 10) {
		new(KEEPM + "keep_general")->move(TO);
	}

	if(!present("kguard") && random(8) >= 6 && !present("keep general")) {
		for(x = 0;x < random(2) + 1;x++) {
			new(KEEPM + "keep_guard")->move(TO);
		}
	}
 
	if(!present("lord") && random(12) >= 3) {
 new(KEEPM+"lord")->move(TO);
	return;
	}
}
