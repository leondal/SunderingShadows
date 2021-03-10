
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

    set_name("Swan Fountain");
    set_id(({"swan","fountain","swan fountain","cygnus"}));
    set_short("Fountain");
    set_long("This is a beautiful fountain made from rose marble.  "
      "In the middle stands a finely shaped swan with water "
      "streaming from it's mouth. ");
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

    if (str=="cygnus"){
	tell_object(TP,"\n%^BOLD%^As the name \"Cygnus\" is spoken, the air shimmers around "
	  "the swan fountain.  \n"
	  "The swan wavers before your eyes and then steps from the foutain!!\n\n"
	  "After settling her wings, Cygnus turns to you and bows her head respectfully.\n\n"
	  "Cygnus says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Cygnus says \"Here is a token of my appreciation of your assistance.\"\n");

	say("\n%^BOLD%^As the name \"Cygnus\" is spoken, the air shimmers around "
	  "the swan fountain.  \n"
	  "The swan wavers before your eyes and then steps from the foutain!!\n\n"
	  "After settling her wings, Cygnus turns to "+TPQCN+" and bows her head "
	  "respectfully.\n\n"
	  "Cygnus says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Cygnus says \""+TPQCN+", here is a token of my appreciation of your "
	  "assistance.\"\n",TP);

	new(OPATH "cygtoken.c")->move(TP);
	destruct(TO);
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}

