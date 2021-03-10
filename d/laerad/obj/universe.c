//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
int uses;
int count;
void create(){
    ::create();
    set_id(({"armor","armor of the universe","universe"}));
    set_name("armor of the universe");
    set_short("Armor of the Universe");
    set_long(
	"This is an ancient suit of armor.  It was rumored to have been forged "+
	"by one of the very Gods that rules over this realm.  Containing an "+
	"incredible power, this suit of armor has been passed down through "+
	"the generations for thousands of years.  Only the finest warriors "+
	"of Shadow have ever adorned this mystic relic.  There is an "+
	"inscription engraved into the armor."
    );
    set_type("armour");
    set_size(2);
    set_limbs(({"torso"}));
    set_ac(0);
    set_weight(50);
    set_value(35000);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
    uses = 7;
    set_heart_beat(1);
}
void init(){
    ::init();
    add_action("read","read");
    add_action("star","star");
}
void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "armor") return 0;
    write("This armor is covered in shiny stars.  You can remove them and use them "+
	"as throwing weapons.  To do so type <star (target name)>.  The stars will "+
	"replenish themselves over time.");
    if(uses == 0){
	write("There are no stars left.");
    }
    if(uses == 1){
	write("There is 1 star left.");
    }
    if(uses == 2){
	write("There are 2 stars left.");
    }
    if(uses == 3){
	write("There are 3 stars left.");
    }
    if(uses == 4){
	write("There are 4 stars left.");
    }
    if(uses == 5){
	write("There are 5 stars left.");
    }
    if(uses == 6){
	write("There are 6 stars left.");
    }
    if(uses == 7){
	write("There are 7 stars left.");
    }
    return 1;
}
void star(string str){
    string who;
    object ob;
    if(!str) return notify_fail("Throw the star at whom?\n");
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    ob = present(str, environment(TP));
    if(!ob) return notify_fail("That isn't here!\n");
    if(!this_player()->ok_to_kill(ob)){
	notify_fail("Supernatural forces prevent your attack.\n");
	return 0;
    }
    if(ETP->query_property("no kill")){
	notify_fail("Supernatural forces prevent your attack.\n");
	return 0;
    }
    if(uses < 1) return notify_fail("The armor doesn't have anymore stars to use.\n");
    tell_object(TP,"%^BOLD%^You remove a star from the armor and throw it at "+ob->query_cap_name()+"!");
    tell_object(ob,"%^BOLD%^"+TPQCN+" removes a star from "+TP->query_possessive()+" armor and throws it at you!");
    tell_room(ETP,"%^BOLD%^"+TPQCN+" removes a star from "+TP->query_possessive()+" armor and throws it at "+ob->query_cap_name()+"!",({TP,ob}));
    TP->kill_ob(ob,1);
    ob->kill_ob(TP,1);
    if((int)TP->Thaco(0,ob) <= roll_dice(1,20)){
	tell_object(ob,"The star cuts into you!");
	tell_object(TP,"You hit "+ob->query_cap_name()+" with your throwing star!");
	tell_room(ETP,""+TPQCN+" hits "+ob->query_cap_name()+" with the throwing star!",({TP,ob}));
	ob->do_damage(ob->return_target_limb(),roll_dice(2,6));
	uses -= 1;
	return 1;
    }
    tell_object(ob,"The star misses you!");
    tell_object(TP,"You miss "+ob->query_cap_name()+" with your throwing star!");
    tell_room(ETP,""+TPQCN+" misses "+ob->query_cap_name()+" with the throwing star!",({TP,ob}));
    uses -= 1;
    return 1;
}
void wear_me(){
    if((string)TP->query_level() < 11){
        remove_property("enchantment");
        set_property("enchantment",1);
    }
    if((string)TP->query_level() > 10 && (string)TP->query_level() < 21){
        remove_property("enchantment");
        set_property("enchantment",2);
    }
    if((string)TP->query_level() > 20 && (string)TP->query_level() < 31){
        remove_property("enchantment");
        set_property("enchantment",3);
    }
    if((string)TP->query_level() > 30 && (string)TP->query_level() < 41){
        remove_property("enchantment");
        set_property("enchantment",4);
    }
    if((string)TP->query_level() > 40){
        remove_property("enchantment");
        set_property("enchantment",5);
    }
    if(TP->is_class("mage")){
	write("The armor shifts its form to robes and tightens to your body.");
	if((string)TP->query_alignment() == 1 || (string)TP->query_alignment() == 4 || (string)TP->query_alignment() == 7){
	    set_short("White robes of the Universe");
	}
	if((string)TP->query_alignment() == 2 || (string)TP->query_alignment() == 5 || (string)TP->query_alignment() == 8){
	    set_short("Red robes of the Universe");
	}
	if((string)TP->query_alignment() == 3 || (string)TP->query_alignment() == 6 || (string)TP->query_alignment() == 9){
	    set_short("Black robes of the Universe");
	}
	set_name("robes of the universe");
	set_ac(2);
	set_type("clothing");
	return 1;
    }
    if(TP->is_class("thief") || TP->is_class("assassin") || TP->is_class("bard")){
	write("The armor shifts its form to a hide and tightens to your body.");
	if((string)TP->query_alignment() == 1 || (string)TP->query_alignment() == 4 || (string)TP->query_alignment() == 7){
	    set_short("White hide of the Universe");
	}
	if((string)TP->query_alignment() == 2 || (string)TP->query_alignment() == 5 || (string)TP->query_alignment() == 8){
	    set_short("Red hide of the Universe");
	}
	if((string)TP->query_alignment() == 3 || (string)TP->query_alignment() == 6 || (string)TP->query_alignment() == 9){
	    set_short("Black hide of the Universe");
	}
	set_name("hide of the universe");
	set_ac(3);
	set_type("leather");
	return 1;
    }
    if(TP->is_class("fighter") || TP->is_class("paladin") || TP->is_class("ranger") || TP->is_class("antipaladin") || TP->is_class("cleric")){
	write("The armor shifts its form to a plate armor and tightens to your body.");
	if((string)TP->query_alignment() == 1 || (string)TP->query_alignment() == 4 || (string)TP->query_alignment() == 7){
	    set_short("White plate of the Universe");
	}
	if((string)TP->query_alignment() == 2 || (string)TP->query_alignment() == 5 || (string)TP->query_alignment() == 8){
	    set_short("Red plate of the Universe");
	}
	if((string)TP->query_alignment() == 3 || (string)TP->query_alignment() == 6 || (string)TP->query_alignment() == 9){
	    set_short("Black plate of the Universe");
	}
	set_name("plate of the universe");
	set_ac(7);
	set_type("armour");
	return 1;
    }
    return 1;
}
void remove_me(){
    write("You feel the power of the Universe fade from you.");
    set_type("armour");
    remove_property("enchantment");
    set_short("Armor of the Universe");
    return 1;
}
void heart_beat()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    if(!objectp(ETP)) { return; }
    if(count > 100){
	if(uses < 7){
	    tell_room(ETP,"The armor of the universe gleams with the birth of a new star.");
	    uses += 1;
	    count = 0;
	}
    }
    count++;
    if(living(ETO) && (string)ETO->query_size() == 1){
	if((string)TO->query_size() != 1)
	tell_room(ETO,"The armor shifts its size.");
	set_size(1);
    }
    if(living(ETO) && (string)ETO->query_size() == 2){
	if((string)TO->query_size() != 2)
	tell_room(ETO,"The armor shifts its size.");
	set_size(2);
    }
    if(living(ETO) && (string)ETO->query_size() == 3){
	if((string)TO->query_size() != 3)
	tell_room(ETO,"The armor shifts its size.");
	set_size(3);
    }
    if(living(ETO) && (string)ETO->is_class("mage") || (string)ETO->is_class("bard")){
	TO->set_type("clothing");
    }
}
