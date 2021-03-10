
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"
inherit MONSTER;

int guarded, attempted;

void init(){
    ::init();
    add_action("summon_guardian","summon");
}

void reset(){
    ::reset();
    guarded = 1;
    attempted = 0;
}

create() {
    ::create();
    set_name("pony");
    set_id( ({ "pony" }) );
    set_gender("female");
    set_short("a small pony");
    set_long("This is a small, sad-looking pony");
    set_hd(8,9);
    set_level(13);
    set_hp(60);
    set_alignment(7);
    set_size(2);
    set_exp(1000);
    set_num_attacks(3);
    set_overall_ac(2);
    set_body_type("equine");
    set_race("horse");
    set_gender("female");
    set_emotes(20,({"The pony peers sadly at her shoulders.",
	"The pony jumps into the air and lands hard.",
	"The pony looks at you mournfully.",
	"The pony hangs her head and sighs."}),0);
}


int summon_guardian(string str){

    if (member_array("Stellar Quest",TP->query_quests()) >=0 ) {return 0;}

    if (present("mundanoid",ETP)){
	tell_object(TP,"The mundanoids attacks before you can finish speaking!");
	say("The mundanoid attacks before "+TPQCN+" can finish speaking!",TP);
	present("mundanoid",ETP)->force_me("kill "+TPQN);
	guarded = 0;
	return 1;
    }
    else if (guarded) {
	tell_object(TP,"A mundanoid appears and attacks before you can finish speaking!");
	say("A mundanoid appears and attacks before "+TPQCN+" can finish speaking!",TP);
	new(MPATH "mund_nw.c")->move(ETP);
	present("mundanoid",ETP)->force_me("kill "+TPQN);
	TP->set_disable(30);
	guarded = 0;
	return 1;
    }
    else if (attempted) {
	tell_object(TP,"You say the words, but somehow there seems to be no power in them!");
	return 1;
    }
    attempted = 1;

    if (str=="pegasus"){
	tell_object(TP,"\n%^BOLD%^As the name \"Pegasus\" is spoken, the air shimmers around "
	  "the little pony.  \n"
	  "The pony grows larger and sprouts wings from it's back!!\n\n"
	  "After inspecting her wings, Pegasus turns to you and nuzzles you "
	  "affectionately.\n\n"
	  "Pegasus says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Pegasus says \"Here is a token of my appreciation of your assistance.\"\n");

	say("\n%^BOLD%^As the name \"Pegasus\" is spoken, the air shimmers around "
	  "the little pony.  \n"
	  "The pony grows larger and sprouts wings from it's back!!\n\n"
	  "After inspecting her wings, Pegasus turns "+TPQCN+" you and nuzzles them "
	  "affectionately.\n\n"
	  "Pegasus says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Pegasus says \""+TPQCN+", here is a token of my appreciation of your "
	  "assistance.\"\n",TP);

	new(OPATH "pegtoken.c")->move(TP);
	destruct(TO);
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}
