#include <std.h>;
inherit "/std/armour";

int done;

void create() {
    ::create();
      set_name("robe");
    set("id", ({ "robe","cloak", "armor" }) );
    set("short", "A Black Robe");
    set("long", 
	"This appears to be a normal black robe. However there is an embroidered symbol "
	"of a green serpent on the back of the robe that appears to coil out of thhe sun "
	"underneath it. The material is light-weight and soft."
       );
    set_weight(3);
    set("value", -1200);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
	set_property("enchantment",0);
    set_wear((:TO,"check_wear":));
    set_remove((:TO,"check_unwear":));

}
int check_wear(object ob){
    int align;
	write("You feel a strange sence of power as you put the robe on.");
	if(!done){
		if(TO->query_property("enchantment") != 0){
			if(TO->query_property("enchantment") < 0){
				call_out("age",210);	
			}
			if(TO->query_property("enchantment") > 0){
				call_out("age",1120);
			}
			return 1;
		} 
	}
	align = TP->query_alignment();
	switch(align){
	    case 1: case 4: case 7:{
			write("You can feel the Evil in the Black Robe.");
			set_property("enchantment",-2);
			if(!done){ call_out("age",220); }
			return 1;
	   	}
	    case 2: case 5: case 8:{ 
			write(" You can feel the evil in the Black Robe, but you can feel some protection emminating from it.");
			set_property("enchantment",0);
			return 1;
	    }	
	   	case 3: case 6: case 9:{
			set_property("enchantment",2);
			write(" You can feel the evil in the Black Robe, and the protection it is providing you.");
			if(!done){ call_out("age",2020); }
			return 1;
	    }
	    default: {
			write ("ERROR!!!");
			return 1;
		}
	}
	return 1;
}
int check_unwear(object ob){
	int align;
	align = TP->query_alignment();
	switch(align){
	    case 1: case 4: case 7:{
			write("The Evil Black Robe Laughs at you!!");
	    }
	    case 3: case 6: case 9:{
			write("The Evil Black Robe begs you to reconsider...");
		
		}
	    default: {
			write("The Evil Black Robe tells you 'maybe later??'");
		}
	}
	remove_call_out("age");
	return 1;	
}

void age(){
	int align;
	align = TP->query_alignment();
	write("%^RED%^The Black  Robe feels like it crawls into your skin!");
	switch(align){
	    case 1: case 4: case 7:{
            TP->add_align_adjust(-10);
            "daemon/killing_d"->check_align(TP);            
			write("The Evil Black  Robe glows for a minute, then fades");
			write("You can feel the Evil in the Black  Robe change your alignment a little.");
			if((int)TP->query_alignment() != 1 && (int)TP->query_alignment() != 4 && (int)TP->query_alignment() != 7){
				set_property("enchantment",2);
				write("The  Robe seems to lose it's magic.");
				return 1;
			}
			call_out("age",200);
			return 1;
	    }
	    case 3: case 6: case 9:{
			TP->add_exp(12000);
			done = 1;
			write("The Evil Black  Robe glows for a minute, then fades");
			write("You can feel the Evil in the Black  Robe give you experience");
			return 1;
		}
	    default: {
			write("The Evil Black  Robe glows for a minute, then fades");
			if(TO->query_property("enchantment") != 0){
				if(TO->query_property("enchantment") < 0){
					set_property("enchantment",2);
				}
				return 1;
			}
			return 1;				
		}
	}
	remove_call_out("age");
	return 1;	

}
int drop(){
	write("You can't seem to drop the Black Robe! So you put it back into your inventory..");
	return 1;
}