// castleA1.c
// Pator@ShadowGate
// 06/27/95

#include <castle.h>

inherit ROOM;

int found = 0;

int search_it(string str) {
	object ob;
	if (!str) { 
	  notify_fail("You look at your hands wondering what you wanted to do\n");
	  return 0;
 	} else	{
	if(!(str == "cupboard")) { 
	   notify_fail("You search for something that isn't there !\n");
	  return 0;
	} else  {
	if (!(present("practice sword")))
	     { ob = new("/d/common/obj/weapon/knife");
	       ob->set_name("practice sword");
	       ob->set_id(({"practice sword","sword"}));
	       ob->set_short("A practice sword");
	       ob->set_long("This sword is used by knaves to learn how to handle real swords.");	
	       ob->move(this_object());
		write("You find a practice sword !");
		if( (int)this_player()->query_level() < 6 )
			this_player()->add_exp(3);
	        return 1;
	     }
	}
    }
		return 0;
}	

int get_it(string str)
{	int x;
	if ( present("practice sword") )
	    {   if (str == "sword" || str == "practice sword")
		{
		   x = (int)this_player()->query_level();
	           if ( x > 5 && found == 0 )
		      {
		       notify_fail("You can't pick up that silly sword !\n");
		       return 0;
		     }
	          else
		     { 
			found = 1;
			return 1; 
		     }  
	      }
	    }
	else 	
	    { return 0; }
}
	

reset() {	
	::reset();
	found = 0;
}

init() {
	::init();
	add_action("search_it","search");
	add_action("get_it","get");
}

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(3);
    set_indoors(1);
    set_short("Inside the armoury");
    set_long(
@PATOR
You stand inside the Marleen castle armoury. There are many torches burning
here so you can see more than enough. But what you see is not that
terrific. There are some old pedestals and a cupboard with the words
'PRACTICE SWORDS' on it. There are no other weapons here, but that isn't odd while there are no knights left!
PATOR
    );
set_items((["pedestal" : "Very old wood in the shap of a pedestal",
	    "cupboard" : "You wonder how old the wood is. The cupboard just hangs together !",
	   "torches" : "Just torches but many !!" ]));
set_smell("default","The smell of blood and sweat is here !! *yucky yucky*");
set_smell("blood","You quickly reconsider !!! *uugh*");
set_smell("sweat","Tried the blood yet ???");
   set_listen("default","You hear sounds coming from the yard.");
   set_exits(([
       "east" : CASTLE+"castleW6" ]));
}
