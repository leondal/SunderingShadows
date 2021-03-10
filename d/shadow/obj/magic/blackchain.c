#include <std.h>;
inherit "/std/armour";

int done;
void create() {
    ::create();
    set_name("chain");
    set("id", ({ "chain", "armor", "chain mail","black chain mail" }) );
    set("short", "Black Chain Mail");
    set("long", 
		"This chain mail is Black. It seems to glow as you look at it. "
		"The armor is made from some light weight metal. On the chest is a symbol of a green serpent."
	);
    set_weight(40);
    set("value", 75);
   	set_type("chain");
    set_limbs( ({ "torso" }) );
    set_ac(5);
	set_property("enchantment",0);
    set_wear((:TO,"check_wear":));
    set_remove((:TO,"check_unwear":));

}
int check_wear(object ob){
    int align;
	write("You feel a strange sense of power as you put the chain mail on.");
	if(!done){
		if(TO->query_property("enchantment") != 0){
			if(TO->query_property("enchantment") < 0){
				call_out("age",120);	
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
			write("You can feel the Evil in the Black Chain Mail. \nYou sense you have made a grave mistake.");
			set_property("enchantment",-2);
			if(!done){ call_out("age",200); }
			return 1;
	   	}
	    case 2: case 5: case 8:{ 
			write(" You can feel the evil in the Black Chain Mail, but you can feel some protection emminating from it.");
			set_property("enchantment",0);
			return 1;
	    }	
	   	case 3: case 6: case 9:{
			set_property("enchantment",2);
			write(" You can feel the evil in the Black Chain Mail, and the protection it is providing you.");
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
			write("The Evil Black Chain Mail Laughs at you!!");
	    }
	    case 2: case 5: case 8: {
			write("The Evil Black Chain Mail tells you 'maybe later??'");
		}
	    case 3: case 6: case 9:{
			write("The Evil Black Chain Mail begs you to reconsider...");
		
		}
		default:{}
		
	}
	remove_call_out("age");
	return 1;	
}
void age(){
	int align;
	align = TP->query_alignment();
	write("%^RED%^The Black Chain Mail feels like it crawls into your skin!");
	switch(align){
	    case 1: case 4: case 7:{
            TP->add_align_adjust(-10);
            "daemon/killing_d"->check_align(TP);            
			write("The Evil Black Chain Mail glows for a minute, then fades");
			write("You can feel the Evil in the Black Chain Mail change your alignment a little.");
			if((int)TP->query_alignment() != 1 && (int)TP->query_alignment() != 4 && (int)TP->query_alignment() != 7){
				set_property("enchantment",2);
				write("The Chain Mail seems to lose it's magic.");
				return 1;
			}
			call_out("age",200);
			return 1;
	    }
	    case 3: case 6: case 9:{
			TP->add_exp(12000);
			done = 1;
			write("The Evil Black Chain Mail glows for a minute, then fades");
			write("You can feel the Evil in the Black Chain Mail give you experience");
			return 1;
		}
	    default: {
			write("The Evil Black Chain Mail glows for a minute, then fades");
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
	write("You can't seem to drop the Black Chain Mail! So you put it back into your inventory..");
	return 1;
}