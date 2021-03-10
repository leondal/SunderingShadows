#include <std.h>
inherit POTION;


int uses;

void create() {
    ::create();
    set_name("blue vial");
	set_short("A kit of blue healing vials");
	set_id(({"blue","vial","potion","kit"}));
    set_long(
@OLI
	The pale blue liquid contained in this kit's vials
	is smooth but bitter. The case can hold many vials.
OLI
	);
    set("color", "blue");
    set("effect_time", (random(4) * 60));
    uses = 1;
    set_weight(2);
}
int do_effect() {
    tell_object(drinker, "The potion seems to cool your body.");
 	drinker->add_hp(roll_dice(2,4)+2);
    return 1;
}

int do_wear_off() { return 0;}


int wear_off() {
        if(!uses){
        	do_wear_off() ;
        	destruct(this_object());
        }
        	return 1;
}

int quaff_potion(string str) {

    object vial;
    int temp ;

    if (!uses) {return 0; }
    if( id(str)){
        if(closed==1) {
            write("Perhaps you should open the potion vial first.\n");
            return 1;
        }

        write("You quickly quaff the draught from the "+query("color")+" potion.\n");
        say(this_player()->query_cap_name() +" drinks from a small vial.\n");
        seteuid(getuid());
        drinker = this_player() ;
        uses--;
        set_weight(query_weight() - 1);
        delay=5+(random(5));
        call_out("potion_effect",delay, drinker);

// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.

        make_empty(TP);
        return 1;
    }
    return 0;
}

void add_use(){
	uses += 1;
	}

int query_uses() { return uses;}

void set_uses(int num){
	uses = num;
	set_weight(2 * num);
}
	

void move(mixed dest){
	object ob;
	int hold;

	if(objectp(dest)){
		if(living(dest)) {
			while((ob=present("blue",dest)) ){

				if((hold = ob->query_uses())){
					uses += hold; 
					TO->set_weight(query_weight() + (2 * hold));
				} else {
					uses += 1;
					TO->set_weight(query_weight() + 2 );
				}	
				ob->remove();
		
			}
		}
	}
	::move(dest);

}

string query_short(){
	string holder;
	
	holder = ::query_short();
	
	holder += " ["+uses+" left]";
	return holder;
}

string query_long(string str){
	string holder;
	
	holder = ::query_long(str);
	
	holder += "/n["+uses+" left]";
	return holder;
}
		
