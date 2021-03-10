//Coded by bane//
//new desc, lore, color to messages and updated some of the older code - Cythera 3/27/05
#include <std.h>
#include <magic.h>
inherit ARMOUR;

int waiting;

int uses;
void create() {
    	::create();
    	set_id(({"glove","glove of magic missiles"}));
    	set_name("glove of magic missiles");
    	set_obvious_short("%^BOLD%^%^BLACK%^A black leather glove%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Glove of %^RED%^M%^YELLOW%^a"+
		"%^BLUE%^g%^RED%^i%^YELLOW%^c%^BLUE%^ M%^RED%^i"+
		"%^YELLOW%^s%^BLUE%^s%^RED%^i%^YELLOW%^l%^BLUE%^e"+
		"%^RED%^s%^RESET%^");
    	set_long("%^BOLD%^%^BLACK%^This short black leather glove"+
		" is covered with a multitude of %^RED%^r%^RESET%^"+
		"%^RED%^e%^BOLD%^d%^BLACK%^, %^BLUE%^b%^RESET%^"+
		"%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^"+
		"%^BLACK%^, and %^YELLOW%^y%^RESET%^%^ORANGE%^e"+
		"%^YELLOW%^ll%^RESET%^%^ORANGE%^o%^YELLOW%^w"+
		"%^BLACK%^ dots.  The single glove was made to be"+
		" worn on the right hand.  Quilted sections of "+
		"leather line the inside of the glove's palm, "+
		"giving some comfort and protection to the hand."+
		"  The stitched dots across the surface of the "+
		"glove add a splash of color to the otherwise "+
		"dull and dreary black leather.%^RESET%^\n");
	set_lore("Crafted by Igador the Flashy, a gaudy mage,"+
		" the Gloves of Magic Missiles offered Igador's"+
		" traveling companions a way to utilize some "+
		"rudimentary magic when needed.  As soon as the"+
		" rumors of the glove began to circulate, Igador"+
		" found his gloves where very popular for adventure"+
		" folk.  They say that one only needs to think "+
		"%^YELLOW%^missile%^RESET%^ to activate the power"+
		" of the glove.");
	set_property("lore difficulty",4);
	set_type("clothing");
	set_ac(0);
    	set_limbs(({"right hand"}));
    	set_weight(5);
    	set_value(500);
}
void init() {
    ::init();
    add_action("missile_me","missile");
}
int missile_me(string str) {
    string who;
    object ob;
    int roll;
    if(TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    roll = random(100)+1;
    if(!TO->query_worn()) {
        write("You have to wear this first.");
        return 1;
    }
    if(uses > 4) {
        write("%^RED%^The glove is out of missiles.");
        return 1;
    }
    if(!str) {
        notify_fail("Missile who?\n");
        return 0;
    }

    if(waiting) {
        tell_object(TP, "%^BLUE%^The glove is recharging.");
        return 1;
    }
    if(sscanf(str,"%s",who) != 1) return notify_fail("Wrong syntax.\n");
    if(!(ob = present(who,environment(TP)))) return notify_fail("That isn't here!\n");
    tell_object(TP,"%^YELLOW%^You aim the glove at "+ob->QCN+".");
    tell_object(ob,"%^RED%^"+TP->QCN+" aims "+TP->QP+" hand at you.");
    tell_room(ETO,"%^BLUE%^"+TP->QCN+" aims "+TP->QP+" hand at "+ob->QCN+".",({ob,TP}));
    tell_object(ob,"%^BOLD%^RED%^A burst of missiles shoot out of the"+
		" glove slamming into you!");
    tell_room(ETO,"%^BOLD%^RED%^A burst of missiles shoot out of the "+
		"glove slamming into "+ob->QCN+"!",ob);
    if(!TP->kill_ob(ob,0)) return 1;
    uses += 1;
    if(ob->query_property("magic resistance") >= roll) {
        tell_room(ob,"%^YELLOW%^The missiles disperse around you futilely.");
        tell_room(ETO,"%^YELLOW%^The missiles disperse around "+ob->query_cap_name()+" futiley.",ob);
        return 1;
    }
    ob->do_damage(ob->return_target_limb(),roll_dice(5,4)+5);
    waiting = 2;
    set_heart_beat(1);
    return 1;
}

void heart_beat() {
    if(waiting) waiting--;
}
int isMagic(){
 	int x;
 	x = ::isMagic();
 	x = x+1;
 	return x;
}
