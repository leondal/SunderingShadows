
#include <std.h>
inherit "/std/weapon";

void create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long" }));
   set_name("long sword");
   set_short("A long sword");
   set_long(
        "This is a shiney, well kept long sword.\n "
        "This long sword is of great quality.\n"
        "The balance is astounding.\n"
        "It is extremely light.\n"
   );
   set_weight(2);
   set_size(2);
   set_value(750);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slashing");
   set_wield( (: TO, "state_so" :) );
   set_unwield( (: TO, "state_what" :) );
   set_hit((:TO,"make_magic":));
   set_property("enchantment",1);
}
int state_so(){
        write("The sword conforms to the contours of you hand");
        write("%^BOLD%^%^YELLOW%^A dim glow eminates from the sword");
        tell_room(environment(TP),"%^BOLD%^%^YELLOW%^The sword lights up, as it settles comfortably in "+TPQCN+"'s hand.",TP);
        set_property("light",2);
        return 1;
        }
        
int state_what(){
        tell_room(environment(TP),"%^BOLD%^%^CYAN%^The light of the sword dies quickly.");
        remove_property("light");
        return 1;
        }
        
int make_magic(object targ){
        int num;
        int damage;
        int count;
        
        
        num = random(4);
        damage = random(5);
        switch (num){
			case 0:
                tell_room(environment(targ),"BOLD%^%^YELLOW%^Light illumnates the entire room as the sword swings");
                count = 1;
                break;
			case 1:
                tell_room(environment(targ),"%^BOLD%^%^RED%^The sword screams with violent rage as it slices through "+targ->query_cap_name()+".",targ);
                tell_object(targ,"%^BOLD%^%^RED%^As this sword slices through you, it screams with a violent rage!\n");
                break;
			case 2:
                tell_room(environment(targ),"%^BOLD%^%^YELLOW%^A jolt of electricity runs from the sword sending "+targ->query_cap_name()+" hopping.",targ);
                tell_object(targ,"%^BOLD%^%^YELLOW%^You feel a strong shock as a jolt of electricity runs through you!\n");
                damage = 15;
                break;
			case 3:
				tell_room(environment(targ),"The sword dances a little and slices effectively through the "+targ->query_cap_name()+".",targ);
				tell_object(targ,"The sword dances as it slices through you!\n");
                break;

        }
        return damage;
}
