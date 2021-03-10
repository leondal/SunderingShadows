//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"dagger","ice dagger"}));
    set_name("Ice Dagger");
    set_short("An ice dagger");
    set_long(
	"This is a finely shaped piece of ice that is used as a dagger. "+
	"Although it doesnt feel cold while wielding it, it's bite is "+
	"as chilly as the arctic winds!"
    );
    set_size(1);
    set_weight(5);
    set_value(5000);
    set_wc(1,4);
    set_large_wc(1,4)+1;
    set_property("enchantment",2);
    set_property("monsterweapon",1);
    set_type("piercing");
    set_hit( (:TO,"extra_hit":) );
}
int extra_hit(object ob){
    int roll, roll2, roll3;
    roll=random(100)+1;
    roll2=random(20)+1;
    roll3=random(10)+1;
    if(roll > 70){
	if(roll > 70 && roll < 80){
	    tell_object(ob,"%^BOLD%^BLUE%^The dagger glows a brilliant blue as it cuts into you!");
            tell_room(environment(query_wielded()),"%^BOLD%^BLUE%^The dagger glows a billiant blue as it cuts into "+ob->query_cap_name()+"!",ob);
	    ob->do_damage(ob->return_target_limb(),roll_dice(1,4));
	    return 1;
	}
	if(roll > 79 && roll < 90){
	    if(roll3 > 5){
	    tell_object(ob,"%^BOLD%^CYAN%^A terrible chill overcomes you as the dagger slices through you!");
            tell_room(environment(query_wielded()),"%^BOLD%^CYAN%^"+ob->query_cap_name()+" shivers terribly as the dagger slices through "+ob->query_objective()+"!",ob);
	    ob->set_paralyzed(20,"You are too cold to move.");
	    return 1;
	    }
	return 1;
	}
    	if(roll > 89){
	    if(roll2 > 19){
		tell_object(ob,"%^BOLD%^You are impaled by the ice dagger and it shatters!");
               tell_room(environment(query_wielded()),"%^BOLD%^"+ob->query_cap_name()+" is impaled by the ice dagger and it shatters!",ob);
		ob->do_damage(ob->return_target_limb(),(15));
		TO->remove();
		return 1;
	    }
	return 1;
	}
    return 0;
    }
}
