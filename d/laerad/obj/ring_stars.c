//Coded by Bane//
//modified a bit by Diego to make use of obvious short and set read//
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 50
int uses;
nosave int flag;
string place;
void create(){
    ::create();
    flag=1;
   set_id(({"ring","cyan ring","ring of shooting stars"}));
    set_name("ring of shooting stars");
    set_obvious_short("%^BOLD%^%^WHITE%^A silver ring with a %^RESET%^%^CYAN%^cyan"+
         "%^BOLD%^%^WHITE%^ stone%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Ring of %^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^"+
         "o%^CYAN%^o%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^i%^CYAN%^n%^RESET%^%^CYAN%^g"+
         " %^BOLD%^S%^RESET%^%^CYAN%^t%^BOLD%^a%^RESET%^%^CYAN%^r%^BOLD%^s%^RESET%^");
   set_lore("When first crafted in the year 369, the Ring of the Shooting"+
         " Stars was hailed as celebration of magic and magical artisry. Crafted by a"+
         " wizard of the name Paldiex Y'altran for his devotion to Kismet and to his "+
         "Art this ring became quite popular with all types of people.  Paldiex, being a human, "+
         "often times had trouble in seeing in the dark even with his magic.  Thus "+
         "the ring started out being only something that would help him to see better "+
         "at night.  During the enchantment process though, Paldiex lays claims that his"+
         " mind was flooded with complex gestures and words that he had never learned "+
         "before.  Feeling the pull of something greater, he gave into the thoughts he "+
         "had and in the end something more than a simple ring of light was created.  "+
         "Paldiex's fame grew in the wizard community as he started to produce more rings"+
         " for his fellow magi and friends.  It was said that he traveled to Laerad some "+
         "six years later to discuss the creation of the ring with a young mage who was an "+
         "admirer of his Art.  Paldiex was never seen or heard from again.  When exploring"+
         " the caves of Laerad though, adventures came back with countless numbers of the "+
         "famed rings of Paldiex, even to this day.");
   set_property("lore",9);
   set_long("%^RESET%^%^BLUE%^Shaped from %^BOLD%^%^WHITE%^silver%^RESET%^%^BLUE%^, this ring"+
         " is neither to thick, nor too slender.  Instead it seems to be a perfect balance "+
         "between the two.  The %^BOLD%^%^WHITE%^silver band%^RESET%^%^BLUE%^ of the ring "+
         "has been polished to a high sheen.  A large flat cut opaque stone of %^CYAN%^deep"+
         " cyan%^BLUE%^ is set into the center of the ring.  The stone is a most unusual one,"+
         " unlike any stone or gem anyone has seen before.  Deep within the stone flecks of "+
         "%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^i%^BOLD%^ght%^RESET%^%^CYAN%^e%^BOLD%^r cyan "+
         "%^RESET%^%^BLUE%^rest, giving a subtle %^RESET%^s%^CYAN%^p%^BOLD%^a%^RESET%^r%^CYAN%^k"+
         "%^BOLD%^l%^RESET%^e%^BLUE%^ to the gem.  Twin lengths of %^BOLD%^%^WHITE%^silver"+
         "%^RESET%^%^BLUE%^ wrap over the stone, helping to secure it in place.  At the ends"+
         " of each %^BOLD%^%^WHITE%^silver%^RESET%^%^BLUE%^ length an open cut five sided "+
         "miniature %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BLUE%^ rests on the "+
         "%^CYAN%^cyan%^BLUE%^ field.  Looking closer at the ring, the %^BOLD%^%^WHITE%^silver"+
         " %^RESET%^%^BLUE%^lengths look more like the %^BOLD%^%^CYAN%^glittering%^RESET%^%^BLUE%^"+
         " trail of a %^BOLD%^%^CYAN%^s%^WHITE%^h%^RESET%^%^CYAN%^o%^BOLD%^o%^WHITE%^t%^RESET%^%^CYAN%^"+
         "i%^BOLD%^n%^WHITE%^g%^RESET%^%^CYAN%^ s%^BOLD%^t%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^BLUE%^"+
         ", creating a pleasing shape and form.  Delicate script is written across the band.%^RESET%^\n");
    set_type("ring");
    set_ac(0);
    set_weight(1);
    set_value(1500);
    set_limbs( ({"right hand","left hand"}) );
    set("read","%^CYAN%^This is a Ring of Shooting Stars. It's abilities include: "+
	"\n%^BOLD%^CYAN%^Light %^RESET%^%^CYAN%^: Functions like a light spell. "+
	"\n%^BOLD%^CYAN%^Lightning %^RESET%^%^CYAN%^: Fires a random number of "+
	"lightning balls at your opponent. \n%^BOLD%^CYAN%^Stars "+
	"%^RESET%^%^CYAN%^: Fires glowing missiles at your opponent. \n"+
	"%^BOLD%^CYAN%^Sparks %^RESET%^%^CYAN%^: This ability can be used "+
	"only indoors, it releases a flying cloud of sizzling purple "+
	"sparks at your opponent. \nEach use of the ring uses up a number "+
	"of charges. When the charges run out the ring becomes useless.");
}
void init(){
    ::init();
    add_action("light","light");
    add_action("lightning","lightning");
    add_action("stars","stars");
    add_action("sparks","sparks");
    if(uses > 49){
	set_value(0);
    }
}
int light(string str){
    if(str) return 0;
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
   	if(uses < MAXUSES){
	    if(!place->query_property("indoors",1)){
		if(flag != 0){
		    tell_room(ETO,"%^BOLD%^YELLOW%^The cyan ring lights up the room.");
                    new("/cmds/spells/l/_light.c")->use_spell(TO,TP,10,100,"mage");
		    flag=0;
		    call_out("reset_flag",100,TO);
		    uses += 1;
		    return 1;
		}
		write("The ring must regain its energy.");
		return 1;
	    }
	    write("It must be outdoors to use this ability.");
	    return 1;
	}
	write("The ring is out of charges.");
	return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
int lightning(string str){
    int roll;
    object ob;
    roll=random(4)+1;
    place = environment(TP);
    if(query_worn()){
	if(uses < MAXUSES){
	    if(uses > 49){flag=1;}
	    if(!place->query_property("indoors",1)){
		if(flag != 0){
		    if(!str) return notify_fail("You must designate a target.\n");
                     if(!(ob = present(str, environment(TP)))) return notify_fail("That is not here!\n");
		    if(!TP->kill_ob(ob,0)) return 1;
		    if(roll == 1){
			tell_object(ob,"%^BOLD%^YELLOW%^A massive ball of lightning is fired from "+TP->query_cap_name()+"'s ring and it slams into you!");
			tell_room(ETO,"%^BOLD%^YELLOW%^A massive ball of lightning is fired from "+TP->query_cap_name()+"'s ring and it slams into "+ob->query_cap_name()+"!",({ob,TP}));
			tell_object(TP,"%^BOLD%^YELLOW%^A massive ball of lightning is fired from your ring and it slams into "+ob->query_cap_name()+"!");
			ob->do_damage(ob->return_target_limb(),roll_dice(8,4));
			flag=0;
			uses += 1;
			call_out("reset_flag",100,TO);
			return 1;
		    }
		    if(roll == 2){
			tell_object(ob,"%^BOLD%^YELLOW%^Two massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into you!");
			tell_room(ETO,"%^BOLD%^YELLOW%^Two massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into "+ob->query_cap_name()+"!",({ob,TP}));
			tell_object(TP,"%^BOLD%^YELLOW%^Two massive balls of lightning are fired from your ring and they slam into "+ob->query_cap_name()+"!");
			ob->do_damage(ob->return_target_limb(),roll_dice(6,6));
			flag=0;
			uses += 2;
			call_out("reset_flag",100,TO);
			return 1;
		    }
		    if(roll == 3){
			tell_object(ob,"%^BOLD%^YELLOW%^Three massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into you!");
			tell_room(ETO,"%^BOLD%^YELLOW%^Three massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into "+ob->query_cap_name()+"!",({ob,TP}));
			tell_object(TP,"%^BOLD%^YELLOW%^Three massive balls of lightning are fired from your ring and they slam into "+ob->query_cap_name()+"!");
			ob->do_damage(ob->return_target_limb(),roll_dice(10,4));
			flag=0;
			uses += 3;
			call_out("reset_flag",100,TO);
			return 1;
		   }
		   if(roll == 4){
			tell_object(ob,"%^BOLD%^YELLOW%^Four massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into you!");
			tell_room(ETO,"%^BOLD%^YELLOW%^Four massive balls of lightning are fired from "+TP->query_cap_name()+"'s ring and they slam into "+ob->query_cap_name()+"!",({ob,TP}));
			tell_object(TP,"%^BOLD%^YELLOW%^Four massive balls of lightning are fired from your ring and they slam into "+ob->query_cap_name()+"!");
			ob->do_damage(ob->return_target_limb(),roll_dice(12,4));
			flag=0;
			uses += 4;
			call_out("reset_flag",100,TO);
			return 1;
		   }
		return 1;
		}
		write("The ring must regain its energy.");
		return 1;
	    }
	    write("It must be outdoors to use this ability.");
	    return 1;
	}
	write("The ring is out of charges.");
	return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
int stars(string str){
    object ob;
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
	if(uses < MAXUSES){
	    if(uses > 49){flag=1;}
	    if(!place->query_property("indoors",1)){
		if(flag != 0){
		    if(!str) return notify_fail("You must designate a target.\n");
		    if(!(ob = present(str,environment(TP)))) return notify_fail("That is not here!\n");
		    if(!TP->kill_ob(ob,0)) return 1;
		    tell_object(ob,"%^BOLD%^A swarm of shooting stars is released from "+TP->query_cap_name()+"'s ring and they shower down upon you!");
		    tell_room(ETO,"%^BOLD%^A swarm of shooting stars is released from "+TP->query_cap_name()+"'s ring and they shower down upon "+ob->query_cap_name()+"!",({ob,TP}));
		    tell_object(TP,"%^BOLD%^A swarm of shooting stars is released from your ring and they shower down upon "+ob->query_cap_name()+"!");
		    ob->do_damage(ob->return_target_limb(),(12));
		    flag=0;
		    uses += 3;
		    call_out("explode",5,ob);
		    call_out("reset_flag",100,TO);
		    return 1;
		}
		write("The ring must regain its energy.");
		return 1;
	    }
	    write("It must be outdoors to use this ability.");
	    return 1;
	}
	write("The ring is out of charges.");
	return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
int sparks(string str){
    object *vars;
    int i;
    vars = all_living(ETP);
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
	if(uses < MAXUSES){
	    if(uses > 49){flag=1;}
	    if(place->query_property("indoors",1)){
		if(flag != 0){
		    for(i=0;i<sizeof(vars);i++){
			if(vars[i] == TP) continue;
			tell_object(vars[i],"%^BOLD%^MAGENTA%^A sizzling cloud of sparks is released from "+TP->query_cap_name()+"'s ring bursting across the room!",TP);
			vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(2,8));
                        TP->force_me("kill "+vars[i]->query_name());
			flag=0;
			uses += 3;
			call_out("reset_flag",100,TO);
		    }
		    tell_object(TP,"%^BOLD%^MAGENTA%^A sizzling cloud of sparks is released from your ring bursting across the room!");
		    return 1;
		}
		write("The ring must regain its energy.");
		return 1;
	    }
	    write("You must be indoors to use this ability.");
	    return 1;
	}
	write("The ring is out of charges.");
	return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
void explode(object targ){
    if(objectp(targ)){
   	tell_object(targ,"%^BOLD%^RED%^The swarm of stars explodes engulfing you in flame!");
	tell_room(ETO,"%^BOLD%^RED%^The swarm of stars explodes engulfing "+targ->query_cap_name()+" in flames!",targ);
	targ->do_damage(targ->return_target_limb(),(24));
	return 1;
    }
    tell_room(ETO,"%^BOLD%^RED%^The swarm of stars fizzles away.");
    return 1;
}
void reset_flag(){flag=1;}
int isMagic() { return 1; }
