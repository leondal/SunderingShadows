#include "/d/common/common.h"
#include "std.h"
#include <daemons.h>

inherit MONSTER;
void create() {
    ::create();
        set_name("sergeant");
        set_id( ({ "sergeant","patrol"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " city patrol sergeant");
        set("long", "This is one of the fighters who patrol the streets of the city.\n");
        set_level(4);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 8);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",13);
        set_stats("charisma",3);
        set_stats("dexterity",8);
        set_stats("constitution",7);
        set_hd(4, 1);
        set_max_hp(query_hp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(CWEAP"longsword")->move(TO);
        command("wield longsword in right hand");
        new(CARMOR"leather.c")->move(TO);
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
}
void init(){
	::init();
	add_action("respond_to","say");
}
int respond_to(string str){
	if((strsrch(str, "help"))!= -1) return 0;
	tell_room(ETO,TPQCN+" says "+str,TP);
	write("You say "+str);
	tell_room(ETO,TPQCN+" says "+str,TP);
	tell_room(ETO,"Well yes, the sergeant says, this officer will help you.");
	tell_room(ETO,"An officer seems to appear from nowhere when the "
	  "sergeant  called.");
	new("/d/tharis/monsters/fpatrol.c")->move(TO);
	return 1;
}
 
