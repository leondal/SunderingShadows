//Coded by Bane//
#include <std.h>
inherit WEAPON;
int uses;
void create(){
    ::create();
   set_id(({"staff","ash staff","staff of thunder","staff of lightning","staff of thunder and lightning","quarter staff"}));
    set_name("Staff of Thunder and Lightning");
   set_obvious_short("A wooden quarter staff");
   set_short("An ash staff");
   set("lore",
	"This is a staff of Thunder and Lightning. The shaft is made of "+
	"ash and the ends are bound in silver rivets. A constant humming "+
	"noise is emitted from the staff. You can see an inscription "+
	"on the shaft."
    );
   set_long("This is a sturdy six foot long ash quarter staff. It has bands of metal"+
   " tightened around its far edges and along its length to afford it more support.");
    set_size(3);
    set_weight(20);
    set_value(1000);
    set_wc(1,6);
    set_large_wc(1,6);
    set_property("enchantment",1);
    set_type("bludgeoning");
    set_prof_type("staff");
    uses = 25;
    set_hit( (:TO,"extra_hit":) );
}
void init(){
    ::init();
    add_action("read","read");
    add_action("thunderclap","thunderclap");
    add_action("lightning_stroke","bolt");
    add_action("thunder_lightning","storm");
}
int extra_hit(object ob){
    int roll, roll2;
    if(!objectp(ob)) return 0;
    roll=random(100)+1;
    roll2=random(20)+1;
    if(uses < 1){
        set_value(100);
	return 1;
    }
    if(roll > 90){
   	if(roll > 90 && roll < 96){
	    tell_object(ob,"%^BOLD%^YELLOW%^A stroke of lightning arcs from the staff slamming into you!");
            tell_room(environment(ETO),"%^BOLD%^YELLOW%^A stroke of lightning arcs from the staff towards "+ob->query_cap_name()+", slamming into "+ob->query_objective()+"!",ob);
	    ob->do_damage(ob->return_target_limb(),roll_dice(2,6));
	    return 1;
	}
	if(roll > 95){
	    if(!"daemon/saving_d"->saving_throw(ob,"rod_staff_wand")){
		tell_object(ob,"%^BOLD%^A clap of thunder stuns you as the staff smashes into you!");
                tell_room(environment(ETO),"%^BOLD%^A clap of thunder stuns "+ob->query_cap_name()+" as it smashes into "+ob->query_objective()+"!",ob);
		ob->set_paralyzed(10,"You are stunned from the clap of thunder.");
		return 1;
		} else {
		return 0;
	    }
	    return 1;
	}
    	return 1;
    }
}
int read(string str){
    if(uses < 1){
	return 1;
    }
    if(!str) return notify_fail("Read what?\n");
    if(str != "staff") return 0;
    write("This is a staff of Thunder and Lightning. It's awesome "+
	"capabilities are as follows: \n%^BOLD%^YELLOW%^Thunderclap: "+
	"%^RESET%^Sends forth a cone of deafening noise. \n%^BOLD%^YELLOW%^"+
	"Bolt: %^RESET%^Fires a lightning bolt at target. \n%^BOLD%^"+
	"YELLOW%^Storm: %^RESET%^Combines the powers of the thunderclap "+
	"and the lightning bolt for a devastating effect. \nRemember "+
	"that the staff has a VERY limited number of charges and is "+
	"useless when they run out.");
    return 1;
}
int thunderclap(string str){
    object ob;
    if(TP->query_paralyzed()) return 0;
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_wielded()){
    if(uses < 1){
	write("The staff is out of charges.");
	return 1;
    }
    if(!str) return notify_fail("Thunderclap who?\n");
    if(!(ob = present(str,environment(TP)))) return notify_fail("That isn't here!\n");
    tell_object(ob,"%^BOLD%^"+TP->query_cap_name()+" points "+TP->query_possessive()+" staff at you and it releases a deafening cone of thunder!");
    tell_object(TP,"%^BOLD%^You point your staff at "+ob->query_cap_name()+" and it releases a deafening cone of thunder!");
    tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" points "+TP->query_possessive()+" staff at "+ob->query_cap_name()+" and it releases a deafening cone of thunder!",({ob,TP}));
    uses -= 1;
    if(!TP->kill_ob(ob,0)) return 1;
    TP->set_paralyzed(7,"You are busy.");
    if(!"daemon/saving_d"->saving_throw(ob,"paralyzation_poison_death")){
	tell_object(ob,"%^BOLD%^RED%^The clap of the thunder stuns you momentarily!");
	tell_room(ETP,"%^BOLD%^RED%^The clap of the thunder stuns "+ob->query_cap_name()+" momentarily!",ob);
	ob->set_paralyzed(15,"You are stunned from the thunderclap.");
	return 1;
	} else {
	tell_object(ob,"%^BOLD%^RED%^The clap of thunder rings through your ears!");
	tell_room(ETP,"%^BOLD%^RED%^"+ob->query_cap_name()+" reels back from the blast of the thunder!",ob);
	return 1;
    }
    write("You must wield the staff first.");
    return 1;
    }
}
int lightning_stroke(string str){
    object ob;
    if(TP->query_paralyzed()) return 0;
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_wielded()){
	if(uses < 1){
	    write("The staff is out of charges.");
	    return 1;
	}
	    if(!str) return notify_fail("Bolt who?\n");
	    if(!(ob = present(str,environment(TP)))) return notify_fail("That isn't here!\n");
	    tell_object(ob,"%^BOLD%^YELLOW%^"+TP->query_cap_name()+" lowers "+TP->query_possessive()+" staff at you and it fires a bolt of lightning!");
	    tell_object(TP,"%^BOLD%^YELLOW%^You lower your staff at "+ob->query_cap_name()+" at it fires a bolt of lightning!");
	    tell_room(ETP,"%^BOLD%^YELLOW%^"+TP->query_cap_name()+" lowers "+TP->query_possessive()+" staff at "+ob->query_cap_name()+" at it fires a bolt of lightning!",({ob,TP}));
	    uses -= 1;
	    if(!TP->kill_ob(ob,0)) return 1;
	    TP->set_paralyzed(7,"You are busy.");
	    if(!"daemon/saving_d"->saving_throw(ob,"spell")){
		tell_object(ob,"%^BOLD%^The bolt of lightning slams into you!");
		tell_room(ETP,"%^BOLD%^The bolt of lightning slams into "+ob->query_cap_name()+"!",ob);
		ob->do_damage(ob->return_target_limb(),roll_dice(8,6));
		return 1;
		} else {
		tell_object(ob,"%^BOLD%^The lightning bolt strikes you lightly!");
		tell_room(ETP,"%^BOLD%^The lightning bolt strikes "+ob->query_cap_name()+" lightly!",ob);
		ob->do_damage(ob->return_target_limb(),roll_dice(4,6));
		return 1;
	    }
	}
    write("You must wield the staff first.");
    return 1;
}
int thunder_lightning(string str){
    object ob;
    if(TP->query_paralyzed()) return 0;
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_wielded()){
	if(uses < 1){
	    write("The staff is out of charges.");
	    return 1;
	}
	if(!str) return notify_fail("Storm who?\n");
	if(!(ob = present(str,environment(TP)))) return notify_fail("That isn't here!\n");
	tell_object(ob,"%^BOLD%^RED%^"+TP->query_cap_name()+" points "+TP->query_possessive()+" staff at you and releases a massive attack of thunder and lightning!");
 	tell_object(TP,"%^BOLD%^RED%^You point your staff at "+ob->query_cap_name()+" and release a massive attack of thunder and lightning!");
	tell_room(ETP,"%^BOLD%^RED%^"+TP->query_cap_name()+" points "+TP->query_possessive()+" staff at "+ob->query_cap_name()+" and releases a massive attack of thunder and lightning!",({ob,TP}));
	uses -= 2;
	if(!TP->kill_ob(ob,0)) return 1;
	TP->set_paralyzed(7,"You are busy.");
	if(!"daemon/saving_d"->saving_throw(ob,"spell")){
	    tell_object(ob,"%^BOLD%^BLACK%^A bolt of lighting slams into your chest and a crack of thunder stuns you momentarily!");
	    tell_room(ETP,"%^BOLD%^BLACK%^"+ob->query_cap_name()+" is assaulted by a flurry of thunder and lightning!",ob);
	    ob->do_damage(ob->return_target_limb(),roll_dice(8,6));
	    ob->set_paralyzed(15,"You are stunned by the thunderclap.");
	    return 1;
	    } else {
	    tell_object(ob,"%^BOLD%^BLACK%^Thunder and lightning crash all around you barely nicking you!");
	    tell_room(ETP,"%^BOLD%^BLACK%^Thunder and lightning crash all around "+ob->query_cap_name()+" barely nipping "+ob->query_objective()+"!",ob);
	    ob->do_damage(ob->return_target_limb(),roll_dice(4,6));
	    return 1;
    	}
    }
    write("You must wield the staff first.");
    return 1;
}
