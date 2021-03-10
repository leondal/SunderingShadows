//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"dagger","assassin dagger","black dagger","black blade"}));
    set_name("assassins dagger");
    set_short("Black-bladed dagger");
    set_long(
	"This is a small black-bladed assassins dagger.  It is EXTREMELY sharp "+
	"and deadly.  This is the primary weapon of the assassins guild.  It is "+
	"easily concealable as it is very small and is completely black in color."
    );
    set_weight(1);
    set_size(1);
    set_value(1500);
    set_wc(1,12);
    set_large_wc(1,12);
    set_type("piercing");
    set_wield((:TO,"extra_wield":));
    set_property("monsterweapon",1);
}

void extra_wield(){
    if(!(string)TP->is_class("assassin")){  // wasn't wielding, added the ! *Styx*
        write("You cannot wield this weapon.");
	return 0;
    }
    write("The weapon balances easy in your grasp.");
    return 1;
}
