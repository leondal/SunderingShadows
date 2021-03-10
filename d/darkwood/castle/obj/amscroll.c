// anti-magic scroll

#include <std.h>;

inherit OBJECT;

void create(){
	::create();
	set_name("scroll");
	set_id(({"scroll"}));
	set_short("scroll");
	set_long("This scroll belongs to the Tower of Wizardry and is to be %^BOLD%^used%^RESET%^ only in case of an emergency within the tower.");
	set_weight(2);
	set_value(1);
}

void init(){
	::init();
	add_action("dispel","use");
}

int dispel(string str){
	if(!str) return notify_fail("What are you trying to use?\n");
	if(!id(str)) return notify_fail("You can't use that.\n");
	tell_object(TP,"%^BOLD%^As you read the strange words and the scroll disintegrates, you sense a change in the room.");
	tell_room(ETP,"%^BOLD%^You see "+TPQCN+" unroll a scroll and read something, then the scroll crumbles in "+TP->query_possessive()+" hands.",TP);
	if(ETP->query_light()>=2){
		tell_room(ETP,"%^BOLD%^%^BLUE%^The room suddenly goes dark.");
		ETP->set_light(-2);
	}
	("/cmds/wizard/_dispel_magic.c")->use_spell(TP,0,1000);
	TO->remove();
	return 1;
}
