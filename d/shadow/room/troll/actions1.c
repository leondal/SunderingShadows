#include "/d/shadow/room/troll/short.h";
int AMNT = random(3);
int MOSS = random(5) + 5;
int CARVINGS,SECRET;
string CARVED;

int set_mine1_actions(string *items) {
    int num_of_items = sizeof(items);

    string item;
    int foo;
    for(foo = 0; foo < num_of_items; foo++) {
        item = items[foo];
	switch(item) {
	    case "sitrock": add_action ( "sit_fun", "sit" );
	        break;

	    case "touch": add_action ( "touch_fun", "touch" );
		break;

	    case "getbones": add_action ( "get_fun", "get" );
		break;
	
	    case "carving": add_action ( "carve_fun", "carve" );
			    add_action ( "wipe_fun", "wipe" );	
			    add_action ( "wipe_fun", "scrub" );	
		break;

            case "stream": add_action ( "swim_fun", "swim" );	
	 		   add_action ( "drink_fun", "drink" );
		break;

            case "mine": add_action ( "mine_fun", "mine" );	

		break;

            case "moss": add_action ( "eat_fun", "eat" );	

		break;

	 }
      }
      return 1;
}			 

int drink_fun(string str) { 
    object me = this_player();
    object here = environment ( me );
    if(((str != "water from stream") &&
	    (str != "from stream") && 
	    (str != "water at stream") &&
	    (str != "at stream") &&
	    (!(here->query_property("has pool")))) ||
	    ((here->query_property("has pool")) && 
	    ((str != "from pool") && 
	    (str != "water at pool") &&
	    (str != "water from pool") && 
	    (str != "at pool") &&
	    (str != "water from stream") &&
	    (str != "from stream") && 
	    (str != "water at stream") &&
	    (str != "at stream"))))
        return notify_fail ( "Drink what?\n" );
    if(!(me->add_quenched(1)))
	return notify_fail("You are too bloated as it is.\n"); 

        message("inf",
	    "%^BOLD%^%^BLUE%^"
	    "You drink up some water "
	    "from the stream."
	    "%^RESET%^\n%^BOLD%^%^CYAN%^"
	    "Refreshing!"
	    "%^RESET%^"
	,me);
        message("inf",
	    "%^BOLD%^%^BLUE%^"
	    +me->query_cap_name()+
            " wipes some water from "
	    +me->query_possessive()+
	    " mouth as "
	    +me->query_subjective()+
	    " gets up from the stream."
	,here,me);	
        return 1;
}

int swim_fun(string str) { 
    object me = this_player();
    object here = environment ( me );
    if(((str != "in stream") &&
      (str != "at stream") &&
      (str != "stream") &&
      (str != "water") &&
      (!(here->query_property("has pool")))) ||
      ((here->query_property("has pool")) &&
      ((str != "in pool") && 
      (str != "at pool") &&
      (str != "pool") &&
      (str != "in stream") &&
      (str != "at stream") &&
      (str != "stream") &&
      (str != "water"))))
	return notify_fail("Where do you wish to swim?\n");
     
	message("inf",
	    "%^BOLD%^%^BLUE%^"
	    "You frolic about playfully in the "
            "%^BOLD%^%^CYAN%^"
	    "fresh water "
	    "%^BOLD%^%^BLUE%^"
            "stream!"
	    "%^RESET%^"
	,me);
        message("inf",
	    "%^BOLD%^%^BLUE%^"
	    +me->query_cap_name()+
	    " frolics about playfully in the "
            "%^BOLD%^%^CYAN%^"
	    "fresh water "
	    "%^BOLD%^%^BLUE%^"
            "stream!"
	    "%^RESET%^"
	,here,me);
 
     return 1;
}

int carve_fun(string str) {
    int MESSAGE;
    object me = this_player();
    object here = environment(me);
    string what_to_write; 	

    if(!str) return notify_fail("Carve what?\n");

    if(present("troll"))
	return notify_fail("The troll will not let you do that.\n");

    if(here->query_property("no_carve"))
	return notify_fail("There is too much moss on the walls "
			     "to be able to carve here.\n");

    if((sscanf(str, "%s on wall", what_to_write ))!= 1)
	return notify_fail("Carve what on wall?\n");

    if(here->query_property("carving here"))
	return notify_fail("There is no room to carve something "
			     "here.\n");

    here->remove_property("carving here");
    if(CARVINGS > 2) here->set_property("carving here", what_to_write);
    here->remove_item("carving");

    if(CARVINGS == 0) CARVED = "%^BOLD%^%^ORANGE%^As you look closely "
			"at the rocky mine wall, you wipe the %^BOLD%^%^YELLOW%^"
			"dirt%^BOLD%^%^ORANGE%^ out of a "
			"carving. It reads:%^RESET%^\n";

    CARVED += "%^BOLD%^%^RED%^"+what_to_write+"\n%^RESET%^";

    CARVINGS += 1;
    if(random(5) < 1 && SECRET == 0) {
        SECRET = 1;
        CARVINGS += 1; 
	MESSAGE = random(5);
	if(MESSAGE == 0) CARVED += 
	    "%^BOLD%^%^RED%^"
	    "The first prism is rumoured to be buried in the walls "
	    "of the mine.%^RESET%^";

	if(MESSAGE == 1) CARVED += 
	    "%^BOLD%^%^RED%^"
	    "The first prism is rumoured to be buried in the walls "
	    "of the mine.%^RESET%^";

	if(MESSAGE == 2) CARVED += 
	    "%^BOLD%^%^RED%^"
	    "The first prism is rumoured to be buried in the walls "
	    "of the mine.%^RESET%^";
   
	if(MESSAGE == 3) CARVED += 
	    "%^BOLD%^%^RED%^"
	    "The first prism is rumoured to be buried in the walls "
	    "of the mine.%^RESET%^";

	if(MESSAGE == 4) CARVED += 
	    "%^BOLD%^%^RED%^"
	    "The first prism is rumoured to be buried in the walls "
	    "of the mine.%^RESET%^";
    }
    here->add_item("carving",CARVED);
     


    message("inf", "%^BOLD%^%^ORANGE%^You etch a carving into "
		       "the rocky mine wall.%^RESET%^",me);
    message("inf", "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
		       "%^BOLD%^%^ORANGE%^etches a carving into the "
		       "rocky mine wall.%^RESET%^",here,me);
    me->set_paralyzed(4,"%^BOLD%^%^ORANGE%^You are busy carving on the wall.");	
    return 1;	
}

int wipe_fun(string str) {
    object me = this_player();
    object here = environment ( me );
    string msg1, msg2;

    if(str!="carving from wall")
	return notify_fail("Wipe what from wall?\n");

    if(here->query_property("no wipe"))	{
	message("inf", "%^BOLD%^%^ORANGE%^You scrub at the "
			    "wall but can't see to remove the "
			    "carving.%^RESET%^",me);
        message("inf", "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
			    "scrubs the wall vigorously.%^RESET%^",here,me);
	return 1;
     }

     if(!(here->query_property("carving here")))
	return notify_fail("There nothing here to wipe.\n");

     here->remove_property("carving here");
     here->remove_item("carving");

     message("inf", "%^BOLD%^%^ORANGE%^You rub at the rock and "
		       "fill the carving in with some %^BOLD%^%^YELLOW%^"
		       "dirt%^BOLD%^%^ORANGE%^.%^RESET%^",me);
     message("inf", "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
		       "%^BOLD%^%^ORANGE%^rubs at the rocky mine wall."
		       "%^RESET%^",here,me);

     SECRET = 1;
     CARVINGS = 0;
     CARVED = "";
     return 1;	
}

int get_fun(string str) {
    object me = this_player();
    object here = environment ( me );
    string msg1, msg2;

    if((str == "bones from pile") ||
	(str == "bone from pile") ||
	(str == "bones from skeleton") ||
	(str == "bone from skeleton")) {
	   msg1 = "%^BOLD%^%^ORANGE%^As you reach down to pick up a "
		  "%^WHITE%^bone%^ORANGE%^ a %^BOLD%^%^BLUE%^s%^RESET%^"
		  "%^BLUE%^h%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^v"
		  "%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^r "
		  "%^BOLD%^%^ORANGE%^runs up your spine and you "
		  "quickly drop it!%^RESET%^";
	   msg2 = "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
		  "%^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^h%^BOLD%^"
		  "%^BLUE%^i%^RESET%^%^BLUE%^v%^BOLD%^%^BLUE%^"
		  "e%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^s "
		  "%^BOLD%^%^ORANGE%^as "+me->query_subjective()+" "
		  "touches the %^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^"
		  ".%^RESET%^";

	} else if ((str == "clothing from pile") ||
  	           (str == "clothing from skeleton")) {
	   msg1 = "%^BOLD%^%^ORANGE%^The clothing is so stained with "
		  "%^RESET%^%^RED%^blood%^BOLD%^%^ORANGE%^ that it is "
		  "very hard and crusty. You decide you have no use "
		  "for it and put it back down.%^RESET%^";
	   msg2 = "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
		  "picks up some clothing from the pile of "
		  "%^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^ "
		  "but decides it's not worth keeping.%^RESET%^";
     	   message("inf", msg1, me);	
     	   message("inf", msg2, here, me);	
	   return 1;	
	}

        else return notify_fail ( "Get what?\n" ); 	

        message("inf", msg1, me);	
        message("inf", msg2, here, me);	

     me->do_damage("torso",(- 11 - random(5)));

     return 1;
   }

int touch_fun(string str) {
    object me = this_player();
    object here = environment ( me );
    string msg1, msg2;

    if((str == "rock") ||
       (str == "rocky wall") ||
       (str == "wall"))	{
	   msg1 = "%^BOLD%^%^ORANGE%^As you touch the rocky mine wall "
		  "you can feel its %^RESET%^%^BLUE%^cool%^BOLD%^"
		  "%^ORANGE%^, smooth surface.%^RESET%^";
	   msg2 = "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" %^BOLD%^"
		  "%^ORANGE%^touches the rocky mine wall.%^RESET%^";
	} else if(str == "moss") {
	   msg1 = "%^BOLD%^%^GREEN%^The moss is %^RESET%^%^BLUE%^cool"
		  "%^BOLD%^%^GREEN%^ and %^RESET%^%^GREEN%^slimy%^BOLD%^"
		  " to the touch.%^RESET%^";
	   msg2 = "%^BOLD%^%^GREEN%^"+me->query_cap_name()+" %^BOLD%^"
		  "%^GREEN%^touches the moss.%^RESET%^";
	}

        else return notify_fail("Touch what?\n"); 	

    message("info", msg1, me);	
    message("info", msg2, here, me);	

    return 1;
}

int sit_fun(string str) {
    object me = this_player();
    if(!me) return 1;
 
    if((member_array(str, ({ "on large rock", 
				   "on awkward rock", 
				   "on rock chair", 
				   "on chair",
				   "on rock", 
				   "large rock", 
				   "awkward rock",
				   "rock chair", 
				   "chair",
				   "rock" }))) == -1)
    return notify_fail("Sit where?\n");

    message("inf", "%^BOLD%^%^ORANGE%^You sit down on the rock, "
		       "but the %^RESET%^%^BLUE%^wet%^BOLD%^%^ORANGE%^ "
		       "surface is quite uncomfortable so you "
		       "decide to stand up.%^RESET%^",me);
    message("inf", "%^BOLD%^%^ORANGE%^"+me->query_cap_name()+" "
		       "sits in the rocky chair, but quicky "
		       "stands up and looks at "+me->query_possessive()+" "
		       "bum.%^RESET%^",environment(me),me);
	
    return 1;
}

int mine_fun(string str) {
    object me = this_player();
    object here = environment(me);
    int SUCCESS,BONUS,MINEROLL;	

    if(!str) return notify_fail("Mine what?\n");

    if(AMNT < 1) here->set_property("nomine",1);

    if(here->query_property("nomine"))
	return notify_fail("The area has been exhausted of gems and gold.\n");

    if(str != "wall" && str != "walls" && str != "ceiling" &&
	str != "floor")
	return notify_fail("Mine what?\n");

    if(this_player()->query_current_attacker()) 
	return notify_fail("You are too busy to mine right now!");

    if(present("troll"))
	return notify_fail("The troll will not let you mine anything.\n");

    if(!present("mining tools",this_player()) && !present("pick axe",this_player())
	&& !present("shovel",this_player()))
	return notify_fail("You have no implement to mine with.\n");

    if(present("mining tools",this_player())) {
	BONUS += 15;
    } else if(present("pick axe",this_player())) {
	BONUS += 5;
    } else if(present("shovel",this_player())) {
	BONUS -= 15;
    }

    if(str == "wall") {
	BONUS += 3;
    } else if(str == "walls") {
	BONUS += 7;

    } else if(str == "floor") {
	BONUS -= 7;

    } else if(str == "walls") {
	BONUS -= 3;
    }

    message("inf",
	"%^BOLD%^%^BLUE%^"	
	"You begin mining the tunnel "+str+" causing a fair bit of "
	"rocks and rubble to come loose.%^RESET%^"
    ,this_player());
    message("env",
	"%^BOLD%^%^BLUE%^"	
	+this_player()->query_cap_name()+
	" begins mining the tunnel "+str+" causing a fair bit of "
	"rocks and rubble to come loose.%^RESET%^"
    ,environment(this_player()),this_player());
    this_player()->set_paralyzed(4,"%^BOLD%^%^BLUE%^You are busy mining.%^RESET%^");

    SUCCESS = random(20) + 20 + BONUS + (int)this_player()->query_stats("wisdom");

    if(random(100) < SUCCESS) {
	MINEROLL = random(95) + (SUCCESS/5);
	if(MINEROLL == 100) new(OPATH "prisma")->move(here);
	if(MINEROLL == 99) new(OPATH "gem1")->move(here);
	if(MINEROLL == 98) new(OPATH "gem2")->move(here);
	if(MINEROLL == 97) new(OPATH "gem3")->move(here);
	if(MINEROLL == 96) new(OPATH "gem4")->move(here);
	if(MINEROLL == 95) new(OPATH "gem5")->move(here);	
	if(MINEROLL < 95 && MINEROLL >= 90) new(OPATH "gem6")->move(here);
	if(MINEROLL < 90 && MINEROLL >= 80) new(OPATH "gem7")->move(here);
	if(MINEROLL < 80 && MINEROLL >= 70) new(OPATH "gem8")->move(here);
	if(MINEROLL < 70 && MINEROLL >= 60) new(OPATH "gem9")->move(here);
	if(MINEROLL < 60 && MINEROLL >= 50) new(OPATH "lnugg")->move(here);
	if(MINEROLL < 50) new(OPATH "nugg")->move(here);
        AMNT =- 1;

    }
    return 1;
}

int eat_fun(string str) {
    object me = this_player();
    object here = environment ( me );    

    if(!str) return 0;

    if(str != "moss") return 0;

    if(MOSS < 1) { 
        here->remove_item("moss");        
        here->remove_item("glow");     
        here->remove_item("light");
        here->set_property("light",1);     
                this_object()->add_items ( ({ "mine","mines", "abandoned mine",
			"abandoned mines" }), 
		   "%^BOLD%^%^ORANGE%^The mine here is %^RESET%^"
		   "%^BLUE%^cold%^BOLD%^%^ORANGE%^ and damp. More than "
		   "likely, they have been carved out of the rock by "
		   "some long forgotten %^BOLD%^%^BLUE%^workers%^BOLD%^"
		   "%^ORANGE%^. It is darker here than other parts "
		   "of the mine.%^RESET%^" );

        notify_fail("There is no more moss here to eat!\n");
	return 0;
    }

    if(!(me->add_stuffed(1)))
	return notify_fail("You are too full to eat anything.\n"); 

        message("inf",
	    "%^BOLD%^%^GREEN%^"
	    "Y"
	    "%^RESET%^%^GREEN%^"
	    "o"
	    "%^BOLD%^%^GREEN%^"
	    "u "
	    "%^RESET%^%^GREEN%^"
	    "s"
	    "%^BOLD%^%^GREEN%^"
	    "c"
	    "%^RESET%^%^GREEN%^"
	    "o"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "p "
	    "%^BOLD%^%^GREEN%^"
	    "u"
	    "%^RESET%^%^GREEN%^"
	    "p "
	    "%^BOLD%^%^GREEN%^"
	    "a "
	    "%^RESET%^%^GREEN%^"
	    "h"
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "d"
	    "%^RESET%^%^GREEN%^"
	    "f"
	    "%^BOLD%^%^GREEN%^"
	    "u"
	    "%^RESET%^%^GREEN%^"
	    "l "
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "f "
	    "%^BOLD%^%^GREEN%^"
	    "t"
	    "%^RESET%^%^GREEN%^"
	    "h"
	    "%^BOLD%^%^GREEN%^"
	    "e "
	    "%^RESET%^%^GREEN%^"
	    "s"
	    "%^BOLD%^%^GREEN%^"
	    "t"
	    "%^RESET%^%^GREEN%^"
	    "r"
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "g"
	    "%^RESET%^%^GREEN%^"
	    "e "
	    "%^BOLD%^%^GREEN%^"
	    "m"
	    "%^RESET%^%^GREEN%^"
	    "o"
	    "%^BOLD%^%^GREEN%^"
	    "s"
	    "%^RESET%^%^GREEN%^"
	    "s "
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "d "
	    "%^RESET%^%^GREEN%^"
	    "w"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "l"
	    "%^BOLD%^%^GREEN%^"
	    "f "
	    "%^RESET%^%^GREEN%^"
	    "i"
	    "%^BOLD%^%^GREEN%^"
	    "t "
	    "%^RESET%^%^GREEN%^"
	    "d"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "w"
	    "%^BOLD%^%^GREEN%^"
	    "n"
	    "%^RESET%^%^GREEN%^"
	    "!"	
	    "%^RESET%^"
	,me);
        message("inf",
	    "%^BOLD%^%^GREEN%^"
	    +this_player()->query_cap_name()+" "
	    "%^RESET%^%^GREEN%^"
	    "s"
	    "%^BOLD%^%^GREEN%^"
	    "c"
	    "%^RESET%^%^GREEN%^"
	    "o"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "p "
	    "%^BOLD%^%^GREEN%^"
	    "s "
	    "%^RESET%^%^GREEN%^"
	    "up "
	    "%^BOLD%^%^GREEN%^"
	    "a "
	    "%^RESET%^%^GREEN%^"
	    "h"
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "d"
	    "%^RESET%^%^GREEN%^"
	    "f"
	    "%^BOLD%^%^GREEN%^"
	    "u"
	    "%^RESET%^%^GREEN%^"
	    "l "
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "f "
	    "%^BOLD%^%^GREEN%^"
	    "t"
	    "%^RESET%^%^GREEN%^"
	    "h"
	    "%^BOLD%^%^GREEN%^"
	    "e "
	    "%^RESET%^%^GREEN%^"
	    "s"
	    "%^BOLD%^%^GREEN%^"
	    "t"
	    "%^RESET%^%^GREEN%^"
	    "r"
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "g"
	    "%^RESET%^%^GREEN%^"
	    "e "
	    "%^BOLD%^%^GREEN%^"
	    "m"
	    "%^RESET%^%^GREEN%^"
	    "o"
	    "%^BOLD%^%^GREEN%^"
	    "s"
	    "%^RESET%^%^GREEN%^"
	    "s "
	    "%^BOLD%^%^GREEN%^"
	    "a"
	    "%^RESET%^%^GREEN%^"
	    "n"
	    "%^BOLD%^%^GREEN%^"
	    "d "
	    "%^RESET%^%^GREEN%^"
	    "w"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "l"
	    "%^BOLD%^%^GREEN%^"
	    "f"
	    "%^RESET%^%^GREEN%^"
	    "s "
	    "%^BOLD%^%^GREEN%^"
	    "it "
	    "%^RESET%^%^GREEN%^"
	    "d"
	    "%^BOLD%^%^GREEN%^"
	    "o"
	    "%^RESET%^%^GREEN%^"
	    "w"
	    "%^BOLD%^%^GREEN%^"
	    "n"
	    "%^RESET%^%^GREEN%^"
	    "!"	
	    "%^RESET%^"
	,here,me);	
        MOSS =- 1;
        return 1;
}
