#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Barkan");
    set_short("Barkan the leathersmith");
    set_id( ({"barkan", "leathersmith"}) );
    set_long(
      "Barkan is an old man, and one of the great old members of the guild.  Instead of moving on with his life, he decided to stay here and work his power into the power of all of the guild."
    );
    set_gender("male");
    set_race("human");
    set_hd(6,1);
    set_exp(1);
    set_hp(20);
    set_max_hp(20);
    set_alignment(6);
    set("aggressive", 0);
}

void init(){
    ::init();
    add_action("order", "order");
}

int order(string str){
    if(!str) return notify_fail("Order what?");
    if(str != "gloves") return notify_fail("Order what?");

    if(present("gloves", TP)) {
	return notify_fail("You already have a pair of gloves.");
    }

    if( member_array("Legion of Lost Soul",TP->query_guild()) < 0) {
	return notify_fail("Barkan looks at you stonily, and refuses to give you a pair of gloves.\n");
    }

    tell_object(TP, "%^BOLD%^%^CYAN%^Barkan smiles at you and hands you a pair of gloves.");
    tell_room(ETP, "%^ORANGE%^Barkan hands "+TPQCN+" a pair of gloves.", TP);
    new("/d/guilds/legion/gloves.c")->move(TP);
    return 1;
}
