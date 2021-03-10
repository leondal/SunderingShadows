
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;

void init(){
	::init();
	call_other(TO,"supernova");
	}
	
void create(){
	::create();
	
	set_name("SuperNova");
	set_id(({"star","nova"}));
        set_short("%^YELLOW%^A Strange Star%^RESET%^");
        set_long("You notice a nearby %^YELLOW%^%^BOLD%^star "
		 "%^RESET%^that seems to be behaving oddly.  "
		 "It seems to be collapsing in on itself!!  ");
	set_weight(100000);
	set_value(100000);
	}


int supernova(){
    call_out("sn1", 1, ETO);
    call_out("sn2", 10, ETO);
    call_out("sn3", 16, ETO);
    call_out("boom", 20, ETO);
    return 1;
}

void boom (object ob) {
    int wisdom, intel, i, max, number, main_number;
    string hit_limb;
    object here,*inv;
    main_number = 8;
    here = ob;
       tell_room(ETO,"%^WHITE%^%^BOLD%^"
            "OH NO!!!  Too Late!  The Star is going supernova!  "
            "The Star explodes in a blinding flash of intense light.  "
            "You slammed by an immense shock wave as the outer shell "
            "of the star is propelled away from the star in an expanding "
            "sphere.%^RESET%^"
       );
   for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++) {
        number = random(main_number)+5;
         if(!living(inv[i])) continue;
         while(number > 0) {
            hit_limb=inv[i]->return_target_limb();
            tell_room(ETO, 
                "%^BOLD%^%^RED%^"
                +inv[i]->query_cap_name()+" recoils in pain "
                "as "+inv[i]->query_possessive()+
                " "+hit_limb+" is damaged by the explosion!"
            ,inv[i]);
            tell_object(inv[i], 
                "%^BOLD%^%^RED%^Your "+hit_limb+" screams with "
                "pain from the explosion!"
            );
            inv[i]->do_damage(hit_limb, random(20) + 10);
           number--;
        }
    }
    new(OPATH "remnant.c")->move(ETO);
    TO->remove();
    return;
}

void sn1(object ob) {
    tell_room(ob,"%^RED%^%^BOLD%^"
        "The star appears to be slowly getting smaller!"
        "%^RESET%^" 
    );
    return;
}

void sn2(object ob) {
    tell_room(ob,"%^ORANGE%^%^BOLD%^"
        "The star begins to collapse faster!"
        "%^RESET%^" 
    );
    return;
}

void sn3(object ob) {
    tell_room(ob,"%^YELLOW%^%^BOLD%^"
        "The star seems to be imploding!"
        "%^RESET%^" 
    );
    return;
}

