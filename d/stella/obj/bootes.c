
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;

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

void create(){
    ::create();

    set_name("A Regal Statue");
    set_id(({"statue","regal statue","king","bootes"}));
    set_short("A Regal Statue");
    set_long("You behold a proud, regal statue of what must be a great king.  "
      "It is 10 feet tall and is carved in astounding detail. ");
    set_weight(100000);
    set_value(100000);
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

    if (str=="bootes"){
	tell_object(TP,"\n%^BOLD%^As the name \"Bootes\" is spoken, the air shimmers around "
	  "the regal statue.  \n"
	  "The statue comes to life!!\n\n"
	  "The King turns to you and inclines his head in a regal salute.\n\n"
	  "Bootes says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Bootes says \"Here is a token of my appreciation of your assistance.\"\n");

	say("\n%^BOLD%^As the name \"Bootes\" is spoken, the air shimmers around "
	  "the regal statue.  \n"
	  "The statue comes to life!!\n\n"
	  "The King turns to "+TPQCN+" and inclines his head in a regal salute.\n\n"
	  "Bootes says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Bootes says \""+TPQCN+", here is a token of my appreciation of your "
	  "assistance.\"\n",TP);

	new(OPATH "bootoken.c")->move(TP);
	destruct(TO);
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}
