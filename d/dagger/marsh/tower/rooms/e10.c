#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
object DRAGON,FLUTE,TABLET,STONE,GOLD;
void init() {
    ::init();
    add_action("loot_fun","loot");
    add_action("grab_fun","grab");
    add_action("look_fun","look");
}
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^RESET%^%^RED%^Large Tower Chamber%^RESET%^");
    set_long( (:TO,"lng_fun" :) );
    set_listen("default",
        "You hear your blood pumping."
    );
    set_smell("default",
        "You smell death and decay within the chamber...and GOLD!"
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
    ]));
    set_exits(([
        "north": RPATH "e11",
        "south": RPATH "e7",
   ]));
    new( MPATH "dragon.c" )->move(TO);
    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
}
string lng_fun(string str) {
    str =
        "%^RED%^"
	"The incredibly large room is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. The room is filled with %^YELLOW%^gold%^RESET%^%^RED%^ "
	"and an assortment of %^MAGENTA%^treasure%^RED%^. There is an "
	"exit on the south wall leading into the darkness. Many %^WHITE%^old bones%^RED%^ "
	"lay about the room as well. ";
    if(DRAGON = present("snarl")) {
	if((int)DRAGON->query_property("awake") > 0) {
	    str += "\n%^BOLD%^%^RED%^There is a large ancient "
	           "red dragon awake and glaring at you!%^RESET%^";
	} else {
 	    str += "\n%^BOLD%^%^RED%^There is a large ancient "
		   "red dragon asleep blocking the exit to the south here!%^RESET%^"; 
	}
    }
    return str;
}
int look_fun(string str) {
    if(!str) {
	notify_fail("Look what?\n");
	return 0;
    }
    if(str != "treasure" && str != "gold" && str != "flute" && str != "tablet" && str != "stone") {
	notify_fail("Look what?\n");
	return 0;
    }
    if(str == "treasure") {
	write("%^MAGENTA%^There is much treasure laying about.%^RESET%^");
        if(GOLD != 1) {
	    write("%^YELLOW%^There is a hell of a pile of gold here.%^RESET%^");
	    write("Perhaps you should grab it.");
	}
	if(FLUTE != 1) {
 	    write("%^CYAN%^There is a lovely flute here.%^RESET%^");
	    write("Perhaps you should grab it.");	
        }
	if(TABLET != 1) {
	    write("%^ORANGE%^There is an interesting looking tablet here.%^RESET%^");
	    write("Perhaps you should grab it.");
	}
	if(STONE != 1)  {
	    write("%^BLUE%^There is a charcoal stone here.%^RESET%^");
	    write("Perhaps you should grab it.");
	}
	return 1;
    }
    if(str == "flute") {
      if(FLUTE != 1) {
	write("%^CYAN%^The silver flute glows and seems like it would be valued highly.%^RESET%^");
	    write("Perhaps you should grab it.");
        return 1;
      } else {
 	return 0;
      }
    }
    if(str == "stone") {
      if(STONE != 1) {
	write("%^BLUE%^The charcoal stone is small and interesting looking. Maybe it "
	      "would be of use to someone.%^RESET%^");
	    write("Perhaps you should grab it.");
        return 1;
      } else {
 	return 0;
      }
    }
    if(str == "tablet") {
      if(TABLET != 1) {
	write("%^ORANGE%^The tablet is covered in writing and looks valuable.%^RESET%^");
	    write("Perhaps you should grab it.");
        return 1;
      } else {
 	return 0;
      }
    }
    if(str == "gold") {
      if(GOLD != 1) {
	write("%^YELLOW%^The gold is piled high and there is a motherload of it!\nPerhaps you should loot it.%^RESET%^");
        return 1;
      } else {
 	return 0;
      }
    }
}		
int loot_fun(string str) {
    if(!str) {
  	notify_fail("Loot what?\n");
	return 0;
    }
    if(str != "treasure" && str != "gold") {
	notify_fail("Loot what?\n");
	return 0;
    }
    if(GOLD == 1) {
	notify_fail("The rest of the treasure here is one big illusion!\n");
	return 1;
    }
    if(DRAGON = present("snarl")) {
      if((int)DRAGON->query_property("awake") != 1) { 	
	write("%^YELLOW%^You begin to grab the gold like a greedy fool and make much clinking noise!"
	      "\n%^RED%^The sleeping dragon awakes!%^RESET%^"
	);
 	DRAGON->set_property("awake",1);
 	DRAGON->set("aggressive",100);
	DRAGON->force_me("say HOW DARE YOU TRY TO STEAL MY GOLD!!!");
	DRAGON->force_me("kill "+TP->query_name());
	return 1;
      } else {
	write("%^RED%^The dragon won't let you loot anything!\n");
	return 1;
      }
    }
    write("%^YELLOW%^You grab a ton of gold!%^RESET%^");
    TP->add_money("gold",random(10000)+5000);
    GOLD = 1;
    return 1;
}
int grab_fun(string str) {
    if(!str) {
	notify_fail("Grab what?\n");
	return 0;
    }
    if(str != "flute" && str != "tablet" && str != "stone") {
	notify_fail("Grab what?\n");
	return 0;
    }
    if(str == "flute") {
	if(FLUTE != 1) {
	    if(DRAGON = present("snarl")) {
		if((int)DRAGON->query_property("awake") != 1) {
	            if(!(TP->query_invis())) {
		        write("%^RED%^As you try to grab that, the dragon sees you through "
			      "his one slightly open eye and attacks!%^RESET%^"
			);
                	DRAGON->set_property("awake",1);
 	                DRAGON->set("aggressive",100);
	                DRAGON->force_me("say HOW DARE YOU TRY TO STEAL MY TREASURE!!!");
	                DRAGON->force_me("kill "+TP->query_name());
	                return 1;
		    } else {
		        write("You grab the flute!");
			new( OPATH "flute.c" )->move(TP);
		        FLUTE = 1;
		        return 1;
		    }
		} else {
		    write("The dragon won't let you touch that!");
		    return 1;
	  	}
	    } else {			
	        write("You grab the flute!");
		new( OPATH "flute.c" )->move(TP);
		FLUTE = 1;
		return 1;
	    }
	} else {
	    notify_fail("Grab what?\n");
	    return 0;
        }
    }
    if(str == "tablet") {
	if(TABLET != 1) {
	    if(DRAGON = present("snarl")) {
		if((int)DRAGON->query_property("awake") != 1) {
	            if(!(TP->query_invis())) {
		        write("%^RED%^As you try to grab that, the dragon sees you through "
			      "his one slightly open eye and attacks!%^RESET%^"
			);
                	DRAGON->set_property("awake",1);
 	                DRAGON->set("aggressive",100);
	                DRAGON->force_me("say HOW DARE YOU TRY TO STEAL MY TREASURE!!!");
	                DRAGON->force_me("kill "+TP->query_name());
	                return 1;
		    } else {
		        write("You grab the tablet!");
			new( OPATH "tablet.c" )->move(TP);
		        TABLET = 1;
		        return 1;
		    }
		} else {
		    write("The dragon won't let you touch that!");
		    return 1;
	  	}
	    } else {			
	        write("You grab the tablet!");
		new( OPATH "tablet.c" )->move(TP);
		TABLET = 1;
		return 1;
	    }
	} else {
	    notify_fail("Grab what?\n");
	    return 0;
        }
    }
    if(str == "stone") {
	if(STONE != 1) {
	    if(DRAGON = present("snarl")) {
		if((int)DRAGON->query_property("awake") != 1) {
	            if(!(TP->query_invis())) {
		        write("%^RED%^As you try to grab that, the dragon sees you through "
			      "his one slightly open eye and attacks!%^RESET%^"
			);
                	DRAGON->set_property("awake",1);
 	                DRAGON->set("aggressive",100);
	                DRAGON->force_me("say HOW DARE YOU TRY TO STEAL MY TREASURE!!!");
	                DRAGON->force_me("kill "+TP->query_name());
	                return 1;
		    } else {
		        write("You grab the stone!");
			new( OPATH "stone.c" )->move(TP);
		        STONE = 1;
		        return 1;
		    }
		} else {
		    write("The dragon won't let you touch that!");
		    return 1;
	  	}
	    } else {			
	        write("You grab the stone!");
		new( OPATH "stone.c" )->move(TP);
		STONE = 1;
		return 1;
	    }
	} else {
	    notify_fail("Grab what?\n");
	    return 0;
        }
    }
} 
int exitb_fun() {
    if(DRAGON = present("snarl")) {
	if((int)DRAGON->query_property("awake") != 1) {
	    write("%^RED%^The sleeping dragons body blocks the way "
	          "south!%^RESET%^");
	    return 0;
        } else {
	    write("%^RED%^The dragon blocks your way!%^RESET%^");
	    return 0;
        }
    }
    if((int)TP->query_property("demongate flying") < 1) {
	write(
	    "%^BLUE%^You head south through the darkness..."
        );
        say(
	    "%^BLUE%^"+TPQCN+" heads south and you hear a shout of surprise followed by a loud painful scream!%^RESET%^"
        ,TP);
	TP->move_player( RPATH "e7" );
	write("%^BLUE%^"
	    "Suddenly you are falling due to the lack of a floor "
	    "beneath your feet!\n%^GREEN%^You fall through the darkness!%^RESET%^"
        );
	TP->move_player( RPATH "d6","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
	TP->move_player( RPATH "c5","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
	TP->move_player( RPATH "b8","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
        TP->move_player( RPATH "a7","falling from above!");
        write(
	    "%^RED%^You smack into a hard surface and are impaled by many sharp spikes!%^RESET%^"
	);
        TP->do_damage("torso",random(60)+60);
 	return 0;
    } else {
	write(
	    "%^BLUE%^You head south through the darkness and the floor vanishes beneath your feet!\n"
	    "%^CYAN%^However, your body remains floating and you find you can fly about the room with ease.%^RESET%^"
        );
	say(
	    "%^BLUE%^"+TPQCN+" heads south into the darkness.%^RESET%^"
        ,TP);
        return 1;
    }
}
void reset() {
    ::reset();
    if(DRAGON = present("snarl")) {
        DRAGON->set_property("awake",0);
//        say("%^RED%^The dragon falls asleep.%^RESET%^"); // say bugs in a reset
        tell_room(TO,"%^RED%^The dragon falls asleep.%^RESET%^"); // *Styx* 1/14/06
	DRAGON->set("aggressive",0);
    }
}
