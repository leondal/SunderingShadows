int set_mine1_items(string *items) {
    object to = this_object();
    int num_of_items = sizeof(items);
    string item;
    int foo;
    for (foo = 0; foo < num_of_items; foo++) {
        item = items [foo];
	switch(item) {
	    case "dead end":
	        to->add_items( ({ "dead end", "end" }),
		   "%^BOLD%^%^ORANGE%^The mine here reaches a "
		   "dead end.%^RESET%^" );
	    break;

	    case "entrance":
	        to->add_items ( ({ item , "mine "+item }), 
		   "%^BOLD%^%^ORANGE%^The mine entrance is "
		   "back a ways through the tunnels from here. "
		   "You can remember the %^BOLD%^%^YELLOW%^"
		   "sunlight%^BOLD%^%^ORANGE%^ that shined "
		   "there.%^RESET%^" );
	    break; 	

	    case "mines":
	    case "mine":	
                to->add_items ( ({ item , "abandoned "+item }), 
		   "%^BOLD%^%^ORANGE%^The mine here is %^RESET%^"
		   "%^BLUE%^cold%^BOLD%^%^ORANGE%^ and damp. More than "
		   "likely, they have been carved out of the rock by "
		   "some long forgotten %^BOLD%^%^BLUE%^workers%^BOLD%^"
		   "%^ORANGE%^. The %^BOLD%^%^GREEN%^moss "
		   "%^BOLD%^%^ORANGE%^growing on the walls gives "
		   "off a faint light.%^RESET%^" );
	    break;

	    case "moss":
                to->add_items ( ({ item, "glowing "+item }), 
		   "%^BOLD%^%^ORANGE%^The %^GREEN%^moss%^ORANGE%^ gives a "
		   "faint %^RESET%^%^CYAN%^glow%^BOLD%^%^ORANGE%^ "
		   "throughout the room.%^RESET%^" ); 
	    break;

	    case "tracks":
                to->add_item (item, 
		   "%^BOLD%^%^ORANGE%^The %^GREEN%^tracks%^ORANGE%^ lead deeper into "
		   "the mine as well as leading back towards the entrance.%^RESET%^"); 
	    break;
 
            case "beams": 
	    case "beam":
	        to->add_items ( ({ item, "support "+item, "wooden "+item,
			 "wooden support "+item }),
		"%^BOLD%^%^ORANGE%^The old rickety wooden support beams line the ceiling "
	        "and walls of the mine. They apeear to have rotted over the years making "
		"you feel very nervous.%^RESET%^");
	    break; 

	    case "tunnel":
	        to->add_items ( ({ "passage","passageway","tunnels", item, "rocky "+item, 
				"mine "+item }),
		"%^BOLD%^%^ORANGE%^The mines are quite extensive. They "
		"seem to stretch on forever and make you long for "
		"the %^BOLD%^%^YELLOW%^light%^BOLD%^%^ORANGE%^.%^RESET%^" );
	    break; 

	    case "glow":
	    case "light":
	        to->add_items ( ({ item, "eerie "+item, "strange "+item }),
		   "%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^h"	
		   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r"	
		   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ i"	
		   "%^BOLD%^%^GREEN%^s %^RESET%^%^GREEN%^a "	
 		   "%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t"	
	  	   "%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a"	
		   "%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^g"	
		   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ a"	
		   "%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^d "	
		   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e"	
		   "%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^i"	
		   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ "	
		   "%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^l"	
		   "%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^w "
		   "%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^h"	
		   "%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^o"	
		   "%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^g"	
		   "%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o"
		   "%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^t "	
		   "%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^h"	
		   "%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^r"	
		   "%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^o"	
		   "%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^."
		   "%^RESET%^" );	
            break;
	
	    case "area":
	    case "here":
	    case "room":	    
	        to->add_item ( item,
		   "%^BOLD%^%^ORANGE%^You are in some sort of "
	  	   "mine.%^RESET%^" );
            break;
		
	    case "wall":
	    case "walls":
	        to->add_items ( ({ item, "mine "+item, "rocky "+item }),
		  "%^BOLD%^%^ORANGE%^The mine walls are made of "
		  "%^RESET%^%^BLUE%^cold%^BOLD%^%^ORANGE%^ rock. "
		  "They are smooth to the touch. They have a circular "
		  "cut to them. There is evidence of recent mining "
		  "activity here.%^RESET%^" );
	    break;

	    case "floor":
	    case "ground":
	        if((member_array("stalagmites", items))!= -1) {
	            to->add_items ( ({ item, "rocky "+item, "cavern "+item }),
		        "%^BOLD%^%^ORANGE%^The "+item+" is made of solid rock. "
		        "There are stalagmites stretching up from the "+item+" "
		        "and pointing towards the ceiling. %^BOLD%^%^GREEN%^Moss"
		        "%^BOLD%^%^ORANGE%^ that has grown on the stalagmites "
		        "gives a %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t"	
		        "%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a"	
		        "%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^g"	
		        "%^BOLD%^%^GREEN%^e%^BOLD%^%^ORANGE%^ glow to the room. "
		        "Regardless, the remainder of the "+item+" has been "
		        "worn smooth by the elements of %^BOLD%^%^CYAN%^air"
		        "%^BOLD%^%^ORANGE%^ and %^RESET%^%^BLUE%^decay"
		        "%^BOLD%^%^ORANGE%^.%^RESET%^");
	        } else {				
	            to->add_items(({ item, "rocky "+item, "mine "+item }), 
		        "%^BOLD%^%^ORANGE%^The "+item+" is made of solid "
		        "rock. It has been worn smooth by the elements of "
		        "%^BOLD%^%^CYAN%^air%^BOLD%^%^ORANGE%^ and %^RESET%^"
		        "%^BLUE%^decay%^BOLD%^%^ORANGE%^.%^RESET%^");
	        }
	    break;
	
	    case "ceiling":	
	        if((member_array("stalactites", items))!= -1) {
   	            to->add_items(({ item, "rocky "+item, "mine "+item }),
		        "%^BOLD%^%^ORANGE%^Hanging from the ceiling above "
		        "you are stalactites. Other than that the rocky "
		        "ceiling has been worn to a smooth finish by the "
		        "passing of time and workings of the miners. "
			"It is covered with a strange "
		        "%^BOLD%^%^GREEN%^glowing moss%^BOLD%^%^ORANGE%^."
		        "%^RESET%^"); 
	        } else {
   	            to->add_items(({ item, "rocky "+item, "mine "+item }),
  		        "%^BOLD%^%^ORANGE%^The rocky ceiling above you has "
		        "been worn down to a smooth finish by the passing of "
		        "time. It is covered with %^BOLD%^%^GREEN%^moss"
		        "%^BOLD%^%^ORANGE%^.");
	        }
	    break;

	    case "dampness":
	    case "fog":
	    case "air":
                to->add_item ( item,
	            "%^RESET%^%^BLUE%^The dampness hangs in the "
		    "air creating a strange kind of fog.%^RESET%^");
	    break;	

	    case "stalagmites":
	    case "stalagmite":
	        to->add_item(item,
		    "%^BOLD%^%^ORANGE%^There are stalagmites that have "
		    "formed over the eons on the ground before you. "
		    "There is %^BOLD%^%^GREEN%^moss %^BOLD%^%^ORANGE%^"
		    "growing on the "+item+".%^RESET%^");
	    break;

	    case "stalactites":
	    case "stalactite":
 	        to->add_item ( item,
		    "%^BOLD%^%^ORANGE%^There are stalactites that have "
		    "formed over the eons on the ceiling above you. "
		    "There is %^BOLD%^%^GREEN%^moss %^BOLD%^%^ORANGE%^"
		    "growing on the "+item+".%^RESET%^");
	    break;

	    case "rock":
	        to->add_item(item,
	            "%^BOLD%^%^ORANGE%^The rock is smooth and %^RESET%^"
		    "%^BLUE%^cool%^BOLD%^%^ORANGE%^ to the touch."
		    "%^RESET%^");
	    break;

            case "rubble":
	        to->add_item(item,
	            "%^BOLD%^%^ORANGE%^The rubble lays scattered about the entire mine and "
		    "has likely been the result of recent mining efforts."
		    "%^RESET%^");
	    break;

	    case "stream":
	        to->add_items(({ item, "mine "+item, "tunnel "+item }), 
		    "%^BOLD%^%^BLUE%^Along the "
		    ""+to->query_property ( "stream location" )+" "
		    "side of the tunnel is a stream, calmly flowing in "
		    ""+to->query_property ( "stream direction" )+"ern "
		    "direction. The %^BOLD%^%^CYAN%^water%^BOLD%^%^BLUE%^ "
		    "looks quite fresh and clean.%^RESET%^");		  
	    break; 

	    case "firelogs":
	        to->add_items(({ item, "smouldering "+item, "logs","log" }), 
		    "%^BOLD%^%^YELLOW%^In the center of the tunnel a couple of "
		    "smouldering firelogs lay in a shallow pit.%^RESET%^");		  
	    break; 


	    case "pit":
	        to->add_items( ({ item, "shallow "+item, "fire"+item }), 
		    "%^BOLD%^%^CYAN%^In the center of the tunnel a firepit has been "
		    "dug. A couple of %^YELLOW%^smouldering logs%^CYAN%^ lay "
		    "in the pit.%^RESET%^");		  
	    break;

	    case "water":
	        to->add_item ( item, 
		    "%^BOLD%^%^CYAN%^The water is %^RESET%^%^CYAN%^"
		    "crystal%^BOLD%^%^CYAN%^ clear, and looks very "
		    "clean and refreshing.%^RESET%^");
	        to->set_property ("water hole",1); 
	    break; 

	    case "skeletons":
	        to->add_items(({ "skeleton", item, "pile of "+item  }), 
		    "%^BOLD%^%^ORANGE%^There is a pile of "
		    "%^BOLD%^%^WHITE%^skeletons%^BOLD%^%^ORANGE%^ "
		    "against the wall. The %^BOLD%^%^WHITE%^"
		    "bones%^BOLD%^%^ORANGE%^ are bleached pure "
		    "%^BOLD%^%^WHITE%^white%^BOLD%^%^ORANGE%^. "
		    "There are tattered clothes mixed in with the pile. "
		    "As you examine the pile more closely, you see stains "
		    "of %^RESET%^%^RED%^blood%^BOLD%^%^ORANGE%^ on the "
		    "%^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^ and "
		    "clothes. Whatever died there, died horribly."
		    "%^RESET%^"); 	
	    break;
	
	    case "intersection":
	        to->add_items(({ "intersection", "tunnel intersection" }), 
		    "%^BOLD%^%^ORANGE%^The tunnel meets and forms a sort "
		    "of intersection here.%^RESET%^");
	    break;
	    
	    case "middle":
	        to->add_items ( ({ "middle", "middle of mines", "middle of mine" }), 
		    "%^BOLD%^%^ORANGE%^You are in the middle of a "
		    "vast system of underground mining tunnels.%^RESET%^" );
	    break;

	    case "clothes":
	        to->add_items(({ item, "clothing", "old clothing",
			       "pile of clothing", "pile of "+item , 
			       "pile of old clothing", "pile of old "+item }),
		   "%^BOLD%^%^ORANGE%^Scattered amongst the pile of "
		   "%^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^ are "
		   "old tattered clothes. They are stained with "
		   "%^RESET%^%^RED%^blood%^BOLD%^%^ORANGE%^. As "
		   "you examine the clothes more closely, they "
		   "appear as though they were not the clothes of "
		   "commoners, but very fine indeed.%^RESET%^"); 
	    break; 	

	    case "bones":
	        to->add_items(({ item, "pile of "+item }), 
		    "%^BOLD%^%^ORANGE%^There is a large pile "
		    "of %^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^ "
		    "scattered amongst old clothing nestled against "
		    "the wall. The %^BOLD%^%^WHITE%^bones%^BOLD%^%^ORANGE%^ "
		    "are nearly pure %^BOLD%^%^WHITE%^white"
		    "%^BOLD%^%^ORANGE%^ except for the %^RESET%^%^RED%^"
		    "deep %^BOLD%^red%^RESET%^%^RED%^ blood"
		    "%^BOLD%^%^ORANGE%^ stains. Whatever happened to these "
		    "poor souls, it wasn't pleasant.%^RESET%^");
	    break;

	    case "blood":
	        to->add_items(({ item, item+" stains", item+" stain", 
			       "stain", "stains" }),
		   "%^BOLD%^%^ORANGE%^The %^RESET%^%^RED%^blood "
		   "%^BOLD%^%^ORANGE%^stains on the %^BOLD%^%^WHITE%^"
		   "bones%^BOLD%^%^ORANGE%^ and clothing look to be "
		   "very old. You hope that whatever spilled the "
		   "%^RESET%^%^RED%^blood%^BOLD%^%^ORANGE%^ has long "
		   "since vanished.%^RESET%^");
	    break;	

	    case "dirt":
	        to->add_item(item,
		    "%^BOLD%^%^ORANGE%^There is some %^YELLOW%^"
		    "dirt%^BOLD%^%^ORANGE%^ scattered at the base "
		    "of the wall.%^RESET%^");
	    break;

	    case "darkness":
	        to->add_item(item,
		    "%^BOLD%^%^BLACK%^The darkness engulfs the entire "
		    "area.%^RESET%^");
	    break;

	    case "bone":
	        to->add_item(item,
		    "%^BOLD%^%^ORANGE%^The %^BOLD%^%^WHITE%^bone"
		    "%^BOLD%^%^ORANGE%^ is stained with "
		    "%^RESET%^%^RED%^blood%^BOLD%^%^ORANGE%^.");
	    break;				

	    case "pile":
	        to->add_item(item, 
		    "%^BOLD%^%^ORANGE%^There is a pile of %^BOLD%^%^WHITE%^"
		    "skeletons%^BOLD%^%^ORANGE%^ that has %^BOLD%^%^WHITE%^"
		    "bones%^BOLD%^%^ORANGE%^ and clothing scattered amongst "
		    "it.%^RESET%^");
	    break;

	    case "pentagram":
	        to->add_items(({ item, "painted "+item }), 
		    "%^BOLD%^%^RED%^There is a large pentagram painted "
		    "on the %^BOLD%^%^WHITE%^floor%^BOLD%^%^ORANGE%^. "
		    "The pentagram is about three feet in diameter and "
		    "is of perfect geometrical pattern." 
		    "%^RESET%^");
	    break;	

	    case "pattern":
	        to->add_items(({ item, "geometrical "+item, 
			"perfect geometrical "+item, "perfect "+item }), 
		    "%^BOLD%^%^RED%^Upon examining the pattern closer "
		    "you notice there is a two inch hole in the exact "
		    "center of the pentagram." 
		    "%^RESET%^");
	    break;	
	    case "hole":	
	    case "center":
	        to->add_items(({ item, "pentagram "+item }), 
		    "%^BOLD%^%^RED%^The hole appears to have been used "
		    "to insert a pole or stick directly into the floor. "
		    "The purpose of this is a complete mystery." 
		    "%^RESET%^");
	    break;	
	 }  
   }
   return 1;
}			 

		
      
      			
