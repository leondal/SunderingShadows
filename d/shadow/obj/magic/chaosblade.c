#include <std.h>

inherit "/std/weapon";

object owner,env,obj;
int align,hp,name;

void create() {
    ::create();
   	set_id(({ "sword", "bastard sword", "black sword", "chaos blade" }));
   	set_name("Chaos Blade");
   	set_short("Chaos Blade");
   	set_long("Chaos Blade\n"
		"This is a black bladed bastard sword. There are strange looking runes "
		"along both sides of the blade. The handle is also black, with black "
		"jewels embedded in it. The blade appears to be made of some strange "
		"light weight material."
   	);
   	set_weight(2);
   	set_size(2);
   	set("value",0);
   	set_wc(2,8);
   	set_large_wc(2,5);
   	set_type("slash");
   	set_property("enchantment",1);
    set_wield((: TO, "check_wield":));
   	set_hit((: TO, "to_hit":));
   	set_heart_beat(1);
}
void init(){
	::init();
	env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env)) {
        owner = env;
        env = environment(owner);
    }
}
void heart_beat() {
   if(!(TO->query_wielded())) {
        return;
    } else {
	   if( obj = present("corpse",environment(owner))) {
    		align = obj->query_old_alignment();     
			hp = obj->query_old_hp();
			name = obj->query_name();
			message("other_action",
				"%^BOLD%^%^GREEN%^"
		        "The Black Sword wielded by "
        		+owner->query_cap_name()+
				", dives into the corpse of the "
				+obj->query_name()+
				" and the corpse vanishes!"
        		"%^RESET%^"
			,environment(obj),(({environment(TO), obj})));
			 tell_object(owner,
                "\n%^RED%^The %^BOLD%^%^YELLOW%^Black Sword %^RESET%^%^RED%^plunges itself into the heart of the "+name+"\n"
		        "and you can feel the soul of the "+name+" drawn into your soul.\n"
		        "As it pulls back out, the corpse turns into dust.\n %^RESET%^"
            );
				
			switch(align){
		    	case 1: case 4: case 7:{
					tell_object(owner,"%^GREEN%^You Feel Invigorated!!%^RESET%^");
					owner->add_hp(hp);
			    }
			    case 2: case 5: case 8:{ 
					tell_object(owner,"%^GREEN%^You Feel a little better!!%^RESET%^");
					owner->add_hp(hp/2);
						    }	
			    case 3: case 6: case 9:{
					tell_object(owner,"%^GREEN%^You Feel Weaker!!%^RESET%^");
					owner->add_hp(-hp);					
			    }
			    default: {
					tell_object(owner,"%^GREEN%^You Feel a little better!!%^RESET%^");
					owner->add_hp(hp/2);
				}
			}
	
			obj->remove();
			return 1;
        }
    }
}

int to_hit(object ob) {

	message("other_action",
		"%^BOLD%^%^GREEN%^"
        "The Black Sword wielded by "
        +owner->query_cap_name()+
		", sings as it cuts into the "
		+ob->query_name()+
		"!"
        "%^RESET%^"
	,environment(ob),(({environment(TO), ob})));
		
	tell_object(environment(TO),
         "%^BOLD%^%^GREEN%^You hear the Black Sword sing as it cuts into the "
		+ob->query_name()+
		"!"
        "%^RESET%^"
	);

	return 1;
}
int check_wield(object ob){
		
	tell_object(owner,
        "%^BOLD%^%^GREEN%^You wield the Black Sword. "
        "%^RESET%^"
	);

	message("other_action",
		"%^BOLD%^%^GREEN%^"
        +owner->query_cap_name()+
            " takes "+owner->query_possessive()+" Black Sword in hand and gets ready for battle."
		"%^RESET%^",environment(owner),owner
	);
	return 1;

}
