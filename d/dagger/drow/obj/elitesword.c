#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";
int uses,xx,yy,FLAG;
void create() {
    ::create();
    set_name("sword of rage");
    set_id(({
        "sword","two handed sword","sword of rage","rage","ragesword"
    }));
    set_short("%^RED%^%^BOLD%^Sword of rage%^RESET%^");
    set_long(
   	"%^RED%^%^BOLD%^The sword of rage glistens as blood seems "
   "to magically seep from its long blade. As you hold it close to "
	"you, it begins to hum a scream of RAGE causing you to feel "
	"immense anger.%^RESET%^"
    );
    set("value",75);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((: TO, "extra_unwield" :));	
    set_property("enchantment",2);
    set_heart_beat(1);
    uses = random(75)+50;
}
void heart_beat() {
    int align,i;
    object owner,env,obj,*inv;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env)) {
        owner = env;
        env = environment(owner);
        align = (int)owner->query_alignment();
    }
    if(!(TO->query_wielded())) {
        return;
    } else {
       if(!objectp(env)) return;
        if( obj = present("corpse",env)) {
            uses = uses + random(2)+1;
            if(uses > 150) uses = 150;
            tell_object(owner,"%^RED%^%^BOLD%^"
                "The sword glows with an inner rage as it satisfys "
                 "its hunger for power on the essence of the corpse."
                "%^RESET%^"
            );
            owner->heal(random(2)+1);
            obj->remove();
            return;
        } else {
            if(env->query_property("no attack")) return;
            inv = all_inventory(env);
            for(i=0; i<sizeof(inv); i++) {
                if(living(inv[i]) 
		   && inv[i] != owner 
		   && (int)inv[i]->query_level() < 200 
		   && !inv[i]->query_ghost()
		   && !inv[i]->query_invis()
             && (string)inv[i]->query_race() != "Drow"
             && (string)inv[i]->query_race() != "drow"
		   && (int)inv[i]->query_alignment() != align) {
		       if(!(owner->query_current_attacker())) {
			   owner->force_me("kill "+inv[i]->query_name());
		       } 	
		}
	    }		
	    xx = random(500);
            yy = random(10)+1;
            if(xx < 1) {
                if(yy == 1) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "I am hungry fool! FEED ME!!!"
                    );
                }
                if(yy == 2) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Are we killing or what?!?"
                    );
                }
                if(yy == 3) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Grrr...*grumble*...what the hell..."
                    );
                }
                if(yy == 4) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Uhhh...not that it matters but...How high is your "
                        "strength?"
                    );
                }
                if(yy == 5) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "You sure take your time don't you?"
                    );
                }
                if(yy == 6) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "The best things to kill are wizards. I *REALLY* "
                        "hate wizards!"
                    );
                }
                if(yy == 7) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "By the way...Are planning on pulling your wieght? "
                        "Seems during combat I do all the work!"
                    );
                }
                if(yy == 8) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Hmmm...I just can't seem to penetrate your "
                        "cranium."
                    );
                }
                if(yy == 9) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Must you carry this worthless other junk around with "
                        "you?!?"
                    );
                }
                if(yy == 10) {
                    if(uses < 50) {
                        tell_object(owner,"%^RED%^%^BOLD%^"
                            "The sword tells you: %^RESET%^"
                            "GET ME CORPSES!!!"
                        );
                    } else {
                        tell_object(owner,"%^RED%^%^BOLD%^"
                             "The sword tells you: %^RESET%^"
                            "Well well well! What do ya know...I am actually "
                            "full."
                        );
                    }
                }
            }
            return;
        }
    }
}
int extra_hit(object ob) {
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if(random(6) < 3) return 1;
    if (uses < 1) {
        dam = random(1)+1;	    
    } else {  
	if(random(30) > 1) { 
	    message("my_action",
	        "%^RED%^%^BOLD%^The %^YELLOW%^sword%^RED%^ screams out "
	        "in %^WHITE%^RAGE%^RED%^ as it sinks into your targets "
	        "flesh!%^RESET%^"
      ,ETO);
            message("other_action",
      "%^RED%^%^BOLD%^The %^YELLOW%^sword%^RED%^ wielded by "+ETO->query_cap_name()+
	        " screams out in %^WHITE%^RAGE%^RED%^ as it sinks into "
	        +vic->query_cap_name()+"'s flesh!"
        ,environment(vic),(({ETO, vic})));
            message("my_action",
        "%^RED%^%^BOLD%^The %^YELLOW%^sword%^RED%^ wielded by "+ETO->query_cap_name()+
	        " screams out in %^WHITE%^RAGE%^RED%^ as it sinks into your "
	        "flesh!%^RESET%^"
            ,vic);
            uses = uses - 1;
            dam = random(5) + 2;
	} else {
            message("my_action",
	        "%^RED%^%^BOLD%^With a %^YELLOW%^snarl%^RED%^ of anger "
	        "you %^WHITE%^headbutt%^RED%^ your opponent!%^RESET%^"
        ,ETO);
            message("other_action",
	        "%^RED%^%^BOLD%^With a %^YELLOW%^snarl%^RED%^ of anger "
        +ETO->query_cap_name()+
	        " %^WHITE%^headbutts%^RED%^ "
	        +vic->query_cap_name()+"!"
        ,environment(vic),(({ETO, vic})));
            message("my_action",
                "%^RED%^%^BOLD%^With a %^YELLOW%^snarl%^RED%^ of anger "
        +ETO->query_cap_name()+
	        " %^WHITE%^headbutts%^RED%^ you!%^RESET%^"
            ,vic);
	    vic->do_damage("head",random(7)+3);
	    dam = random(1)+1;
	    uses = uses - 10;
	}	 
    }
    return dam;
}
int extra_wield() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if((int)tp->query_level() < 10) {
	notify_fail("You could not control the inner rage caused by this "
	"weapon!");
	return 0;
    }
    if(uses > 0) {
        write(
	    "%^BOLD%^%^RED%^You wield the sword and feel an intense "
	    "building RAGE grow within you!%^RESET%^"
	    "\n%^RED%^Suddenly you howl in anger and slice your chest with "
	    "the sword!%^RESET%^"
        );
        say(
        "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" wields a sword and begins to "
	    "howl in anger.%^RESET%^"
	    "%^RED%^Suddenly "+TPQCN+" draws the sword across "
	    +TP->query_possessive()+" chest!%^RESET%^"
        );
        TP->do_damage("torso",10);
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
    }
    return 1;
}
int extra_unwield() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if(uses > 0) {
        write(
	    "%^BOLD%^%^RED%^You unwield the sword and feel the intense "
	    "RAGE within you dwindle away.%^RESET%^"
	);
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" unwields a sword and begins to "
	    "calm down.%^RESET%^"
	);
    }
    return 1;
}
