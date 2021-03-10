
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;

int guarded, attempted;

void reset(){
    ::reset();
    guarded = 1;
    attempted = 0;
}

void init(){
    ::init();
    add_action("summon_guardian","summon");
}

void create(){
    ::create();

    set_name("Lion Statue");
    set_id(({"lion","statue","lion statue","leo"}));
    set_short("A Lion Statue");
    set_long("You behold a trully magnificent marble statue of a lion.  "
      "It is 10 feet tall and is carved in astounding detail. ");
    set_weight(100000);
    set_value(100000);
}

int summon_guardian(string str){

    if (member_array("Stellar Quest",TP->query_quests()) >=0 ){ return 0;}

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

    if (str=="leo"){
	tell_object(TP,"\n%^BOLD%^As the name \"Leo\" is spoken, the air shimmers around "
	  "the lion statue.  \n"
	  "Then the lion appears to come to life!!\n\n"
	  "After a long feline stretch, Leo turns to you and inclines his "
	  "head in a regal salute.\n\n"
	  "Leo says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Leo says \"Here is a token of my appreciation of your assistance.\"\n");

	say("\n%^BOLD%^As the name \"Leo\" is spoken, the air shimmers around "
	  "the lion statue.  \n"
	  "Then the lion appears to come to life!!\n\n"
	  "After a long feline stretch, Leo turns to "+TPQCN+" and inclines his "
	  "head in a regal salute.\n\n"
	  "Leo says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Leo says \""+TPQCN+", here is a token of my appreciation of your "
	  "assistance.\"\n",TP);

	new(OPATH "leotoken.c")->move(TP);
	destruct(TO);
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}
