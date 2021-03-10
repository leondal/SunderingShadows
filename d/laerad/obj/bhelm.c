//Coded by Bane//
#include <std.h>
inherit ARMOUR;

int flag, count, diamond, ruby, fopal, opal;
string owner;

int query_diamond(){return diamond;}
int query_ruby(){return ruby;}
int query_fopal(){return fopal;}
int query_opal(){return opal;}

void set_diamond(int x){ diamond = x; }
void set_ruby(int x){    ruby = x;  }
void set_fopal(int x){   fopal = x; }
void set_opal(int x){    opal = x;  }


void create(){
    ::create();
    set_id(({"helm","brilliance","helm of brilliance","shiny helm"}));
    set_name("helm of brilliance");
    set_obvious_short("A shiny helm");
    set_short("%^BOLD%^%^WHITE%^Helm of b%^YELLOW%^r%^RED%^i%^YELLOW%^"+
    "l%^RED%^l%^YELLOW%^i%^RED%^a%^YELLOW%^nc%^BOLD%^%^WHITE%^"+
    "e%^RESET%^");
    set_long("%^YELLOW%^This ornate helm is mostly made of polished "+
    "%^CYAN%^steel%^YELLOW%^, with veins of %^BOLD%^%^WHITE%^brilliant "+
    "mithril%^RESET%^%^YELLOW%^ to give an added majesty.  The open "+
    "face helm is smooth, though still quite graceful in design.  "+
    "Inlays of %^BOLD%^%^WHITE%^mithril%^RESET%^%^YELLOW%^ sunburst "+
    "designs are scattered across the surface of the helm.  Each "+
    "sunburst is encrusted with priceless gems, %^BOLD%^%^WHITE%^"+
    "diamonds%^YELLOW%^, %^RESET%^%^RED%^rubies%^YELLOW%^, and "+
    "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^CYAN%^l%^BOLD%^%^WHITE%^"+
    "s%^YELLOW%^, all cut with multiple facets.  When light "+
    "falls on the helm sci%^RED%^nt%^BOLD%^%^WHITE%^ill%^RED%^at"+
    "%^YELLOW%^ing rays reflect, providing a dazzling aura about "+
    "the wearer's head.  Almost like a halo of sorts.  There is "+
    "an %^MAGENTA%^inscription%^YELLOW%^ carved into the metal "+
    "inside the helm.%^RESET%^");
    set_weight(15);
//    set_size(random(3)+1);
    set_value(8000);
    set_type("helm");
    set_limbs(({"head"}));
    set_ac(1);
    set_property("enchantment",2);
    set_diamond(random(5) + 5);
    set_ruby(random(10) + 10);
    set_fopal(random(10) + 20);
    set_opal(random(20) + 20);
/*    diamond = random(5) + 5; // was 10
    ruby = random(10) + 10;  // was 20
    fopal = random(10) + 20; // was 30
    opal = random(20) + 20;  // was 40
*/
    count = 0;
    flag = 0;
    set_heart_beat(1);
/* I tried this but it won't work with the variables in it, so going back to the original read until we get function pointers to work with set_read *Styx*
    set_read("This is a helm of brilliance!  It has "+
	"the following functions:\n"
	"throw diamond at <name>:  sends a prismatic spray at target \n"
	"smash ruby <direction|me>:  creates a wall of fire around\n"
	"	                     yourself or the direction you specify \n"
	"throw fopal at <name>:  sends a fireball at a target \n"
	"smash opal:  creates a magic light \n"
    );
*/
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
}

void init(){
    ::init();
  if(!objectp(TP)) return;
  if (!objectp(ETO)) return;
  if (TP != ETO) return;
  if(interactive(TP) && !owner && !avatarp(TP)) {
	owner = TPQN;
// changing to fit the owner's size due to low frequency and being ownered to cut down on cycling to get one wearable, etc. *Styx*  11/26/03, last change 9/15/03 
  	tell_object(ETO, "The helm's magic shifts it to conform to fit your head.");
	set_size(TP->query_size());
   }
    add_action("read","read");
    add_action("throw","throw");
    add_action("smash","smash");
}

int wear_me(){
    if((int)ETO->query_lowest_level() < 25){
       tell_object(ETO,"The power of the helm is too great for one as "+
          "weak as you!");
       return 0;
    }
//added level check 4/22/04 by Circe to help stop low level AC problems
    write("The helm glows brightly.");
    TP->set_property("strength","fire");
    TP->add_sight_bonus(2);
    return 1;
}

int remove_me(){
    write("The helm dims.");
    ETO->remove_property("strength","fire");
    ETO->add_sight_bonus(-2);
    return 1;
}

void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "helm") return 0;
    write("This is a helm of brilliance!  It has "+
	"the following functions:\n"
	"throw diamond at <name>: sends a prismatic spray at target ("+query_diamond()+" diamonds)\n"
	"smash ruby <direction|me>: creates a wall of fire around\n"
	"	yourself or the direction you put ("+query_ruby()+" rubies)\n"
	"throw fopal at <name>: sends a fireball at a target ("+query_fopal()+
	" fire opals)\n"
	"smash opal: creates a magic light ("+query_opal()+" opals)\n"
    );
    return 1;
}

void throw(string str){
    string tmp;
    object ob;
    if(!str) return notify_fail("Throw what?\n");
    if(sscanf(str,"diamond at %s",tmp)){
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

	if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
	if(!(ob = present(tmp, ETP))) return notify_fail("That isn't here!\n");
	if(diamond < 1) return notify_fail("The helm has no diamonds left.\n");
	tell_object(ETO,"You pull a diamond from your helm and throw "+
	    "it at "+ob->QCN+"!");
	tell_object(ob,TPQCN+" pulls a diamond from "+
	    TPQP+" helm and throws it at you!");
	tell_room(ETP,TPQCN+" pulls a diamond from "+
	    TPQP+" helm and throws it at "+
	    ob->QCN+"!",({TP,ob}));
	new("/cmds/wizard/_prismatic_spray")->use_spell(TP,ob,14);
        TP->set_paralyzed(7,"Your hands are full at the moment.");
	diamond -= 1;
	return 1;
    }
    if(sscanf(str,"fopal at %s",tmp)){
     if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
     }
	if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
	if(!(ob = present(tmp, ETP))) return notify_fail("That isn't here!\n");
	if(fopal < 1) return notify_fail("The helm has no fire opals left.\n");
	tell_object(TP,"You pull a fire opal from your helm and "+
	    "throw it at "+ob->QCN+"!");
	tell_object(ob,TPQCN+" pulls a fire opal from "+
	    TPQP+" helm and throws it at you!");
	tell_room(ETP,TPQCN+" pulls a fire opal from "+
	    TPQP+" helm and throws it at "+
	    ob->QCN+"!",({TP,ob}));
	new("/cmds/wizard/_fireball")->use_spell(TP,ob,6);
        TP->set_paralyzed(7,"Your hands are full at the moment.");
	fopal -= 1;
	return 1;
    }
    return 0;
}
void smash(string str){
    string tmp;
    if(!str) return notify_fail("Smash what?\n");
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(str == "opal"){
	if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
	if(opal < 1) return notify_fail("The helm has no opals left.\n");
	tell_object(TP,"You pull an opal from the helm and smash it!");
	tell_room(ETP,TPQCN+" pulls an opal from "+
	    TPQP+" helm and smashes it!",TP);
	new("/cmds/priest/_light")->use_spell(TP,TP,6);
        TP->set_paralyzed(7,"Your hands are full at the moment.");
	opal -= 1;
	return 1;
    }
    if(sscanf(str,"ruby %s",tmp)){
	if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
	if(ruby < 1) return notify_fail("The helm has no rubies left.\n");
	tell_object(TP,"You pull a ruby from the helm and smash it!");
	tell_room(ETP,TPQCN+" pulls a ruby from "+
	    TPQP+" helm and smashes it!",TP);
	new("/cmds/wizard/_wall_of_fire")->use_spell(TP,tmp,10);
        TP->set_paralyzed(7,"Your hands are full at the moment.");
	ruby -= 1;
	return 1;
    }
    return 0;
}
void heart_beat(){
    object ob, holder, env, helm;
    env = ETO;
    if(!objectp(ETO)) return;
    if((helm = present("helm of brilliance",ETO)) && living(ETO) && helm != TO){
	tell_object(ETO,"The helm seems to overpower in close proximity to another of its kind!");
	ETO->do_damage(ETO->return_target_limb(),roll_dice(15,15));
	ETO->add_attacker(TO);
	ETO->continue_attack();
	if(TO->query_worn()){
	    ETO->force_me("remove helm of brilliance");
	}
	TO->remove();
	return 1;
    }
    if(diamond == 0 && ruby == 0 && fopal == 0 && opal == 0){
	tell_room(environment(ETO),"The helm crumbles to dust.");
	if(TO->query_worn()){
	    ETO->force_me("remove helm of brilliance");
	}
	TO->remove();
	return 1;
    }
    if(objectp(environment(ETO))) {
    if(ob = present("ghoul",environment(ETO)) ||
	ob = present("ghast",environment(ETO)) ||
	ob = present("wight",environment(ETO)) ||
	ob = present("wraith",environment(ETO)) ||
	ob = present("specter",environment(ETO)) ||
	ob = present("skuz",environment(ETO)) ||
	ob = present("mummy",environment(ETO)) ||
	ob = present("vampyre",environment(ETO)) ||
	ob = present("lich",environment(ETO)) ||
	ob = present("vampire",environment(ETO))){
	    if(TO->query_worn()){
		if(!flag){
//added to avoid hitting invis imms who might be one of these races Circe 12/21/03
              if(!ob->query_true_invis()){ 
  		   tell_room(environment(ETO),"The helm glows brilliantly burning "+
		       ob->QCN+" badly!",ob);
		   tell_object(ob,ETO->QCN+"'s helm glows "+
		       "brilliantly burning you badly!");
		   ob->do_damage(ob->return_target_limb(),roll_dice(1,6));
		   flag = 1;
		   ob->add_attacker(ETO);
		   ob->continue_attack();
             }
	    }
	}
    }
    }
    if(count > 2){
	flag = 0;
	count = 0;
    }
    count++;
    if(objectp(env) && living(env) && interactive(env)){
	holder = env->query_name();
	} else {
	return;
    }
    if(holder != owner && !wizardp(ETO)){
	tell_object(ETO,"The helm realizes you aren't its owner and disappears!");
	TO->remove();
	} else {
	return;
    }
}

