#include <std.h>

inherit "/std/comp_vend.c";

void create(){
    	::create();
    	set_name("luchien");
    	set_id( ({ "monster","luchien","Luchien","clerk", "shop keeper", "shopkeeper"}) );
    	set_short("Luchien the drow");
    	set("aggressive", 0);
    	set_long(
    		"Luchien is a drow, but seems to have found a place here to "+
    		"make some coins.  As drow go he looks rather old, but he is "+
    		"very neat and clean.  His clothes are of the finest variety and "+
    		"his appearance is well-groomed.  He would look rather pleasant "+
    		"when helping you if his smile did not so closely resemble a sneer.\n"+
		"<help shop> will get you a list of shop commands.\n");
    	set_gender("male");
    	set_alignment(9);
    	set("race", "drow");
    	set_class("mage");
    	set_hd(25,2);
    	set_level(25);
    	set_guild_level("mage",25);
    	set_body_type("humanoid");
    	set_stats("charisma",15);
    	set_property("no bump", 1);
    	set_wielding_limbs( ({ "right hand","left hand" }) );
  	set_size(2);
   	set_exp(1000);
    	set_emotes(0,({
    		"%^CYAN%^Luchien says%^RESET%^: If you got enough money, "+
    			"I sell you my store, eh?.",
        	"%^CYAN%^Luchien says%^RESET%^: Look around my shop as you "+
        		"wish, but if you break it or corrupt it.....you bought it.",
		"Luchien smiles at you hungrily.",
		"Luchien chants an incantation under his breath and then "+
			"looks at you expectantly.",
        	"Luchien watches you as you wander the store.",
        	"%^CYAN%^Luchien says%^RESET%^: If you need help then you are lost.",
        	"%^CYAN%^Luchien says%^RESET%^: Come on now...buy or go."
 	}), 0);
    	set_components(100);
    	set_spell_chance(100);
    	set_spells(({
    		"fireball",
    		"lightning bolt",
    		"powerword stun",
    		"chill touch",
    		"web"
    	}));
    	set_property("strength","spells");
     	set_spoken("wizish");
}

void init(){
    	::init();
    	command("cast stoneskin on luchien");
}