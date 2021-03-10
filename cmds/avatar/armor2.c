// changes by Styx 4/27/03 to fix settings that bugged when MR or damage on wear was being set, cleaned up some typos, and added notes to indicate to use numbers for sizes and a few other clarifications.
// edited to use new stat system. Nienne, 09/07.

#include <std.h>
#include "items.h"
#include <move.h>

inherit OBJECT;

string FILE;
string type;
string name;

int remove;
int wear;
int struck;

void finish(int step);

int save_me(string file) {return 1;}

void exit() {
    	rm(FILE);
	if(TEMP(TPQN)) 
	{
		TEMP_REMOVE(TPQN);
	}
    	remove();
}


void set_file_name(string f) {
    FILE = f;
}

void set_object_type(string t) {
    type=t;
}

void set_name(string n) {
    name = n;
}

void init() {
    ::init();

    write("Please input the number type of armor > ** will quit");
    write("1> clothing ------ Anyone can wear (robe/cloak/belt)");
    write("2> leather ------- Thief armor(leather/hide)");
    write("3> chain --------- Bards fighter clerics (chainmail stuff) ");
    write("4> armor --------- straight armor");
    write("5> ring ---------- ring/bracelets (please don't use these for true rings balance issue here)");
    write("6> bracer -------- bracers mage/thief specific");
    write("7> shield -------- shields (note always use right hand)");
    input_to("type");
    return 1;
}

void type(string str) {
    string atype;
    if(!str) {
        write("Please input the number type of armor > ** will quit");
        write("1> clothing ------ Anyone can wear (robe/cloak/belt)");
        write("2> leather ------- Thief armor(leather/hide)");
        write("3> chain --------- Bards fighter clerics (chainmail stuff) ");
        write("4> armor --------- straight armor");
        write("5> ring ---------- ring/bracelets (please don't use these for true rings balance issue here)");
        write("6> bracer -------- bracers mage/thief specific");
        write("7> shield -------- shields (note always use right hand)");
        input_to("type");
        return 1;
    }
    if(str == "**") return exit();

    switch(str) {
        case "1":
            atype = "clothing";
            break;
        case "2":
            atype = "leather";
            break;
        case "3":
            atype = "chain";
            break;
        case "4":
            atype = "armor";
            break;
        case "5":
            atype = "ring";
            break;
        case "6":
            atype = "bracer";
            break;
         case "7":
            atype = "shield";
            break;
        default:
            write("Please input the number type of armor > ** will quit");
            write("1> clothing ------ Anyone can wear (robe/cloak/belt)");
            write("2> leather ------- Thief armor(leather/hide)");
            write("3> chain --------- Bards fighter clerics (chainmail stuff) ");
            write("4> armor --------- straight armor");
            write("5> ring ---------- ring/bracelets (please don't use these for true rings balance issue here)");
            write("6> bracer -------- bracers mage/thief specific");
            write("7> shield -------- shields (note always use right hand)");
            input_to("type");
            return 1;


    }
    WF(TYPE(atype));
    write("Please input the limbs for this armor.\n"+
          "Up to two limbs maximum for each armor.\n"+
          "comma separate different limbs (right arm,right hand)");
    input_to("limb");
}

void limb(string str) {
    string *limbs;
    int i;
    if(!str) {
        write("Please input the limbs for this armor.\n"+
              "Up to two limbs maximum for each armor.\n"+
              "comma separate different limbs (right arm,right hand)");
        input_to("limb");
        return 1;
    }
    if(str == "**") return exit();
    limbs = explode(str,",");
    for(i=0;i<sizeof(limbs);i++) {

        if(member_array(limbs[i], ETO->query_limbs()) == -1) {
            write("The limb "+limbs[i]+" is not valid.");
            write("Please input the limbs for this armor.\n"+
                  "Up to two limbs maximum for each armor.\n"+
                  "comma separate different limbs (right arm,right hand)");

            input_to("limb");
            return 1;
        }
    }
    WF(LIMBS(identify(limbs)));
    write("Please enter the size of this armor using numeric values.");
    write("%^BOLD%^1 for small,  2 for normal, 3 for large%^RESET%^");
    input_to("size");
    return;
}

void size(string str) {
// moved this check up so I could validate on available sizes *Styx*  
    if(str == "**") return exit();
    if(!str) {
//    if(!str || (str != "1" || str != "2" || str != "3")) {  // didn't work *mutter*
        write("Please input the size for this armor.  Use numeric values:");
        write("1 for small,  2 for normal, 3 for large");
        input_to("size");
        return;
    }
    WF(SIZE(str));
    write("Please input the enchantment for this weapon.");
    input_to("enchant");
    return;
}

void enchant(string str) {

    if(!str) {
        write("Please input the enchantment for this weapon.");
        input_to("enchant");
        return 1;
    }
    if(str == "**") return exit();

    WF(ENCHANTMENT(str));
    write("Please enter an AC for this armor.");
    write("This has balance implications, negative numbers are welcome");
    input_to("ac");
}

void ac(string str) {

    if(str && str != "0") {
        WF(AC(str));
    }
    write("Will this armor have a wear special? [y/n] [n]");
    input_to("wearq");
    return;
}

void wearq(string str) {
    if(str == "y") {
        wear = 1;
        WF(WEAR);
    }

    write("Will this armor have an remove special? [y/n] [n]");
    write("Remember if you added a bonus to the player on wear you will need to remove it with the opposite number (normally negative) here.");
    input_to("removeq");
    return;
}


void removeq(string str) {
    if(str == "y") {
        remove = 1;
        WF(UNWEAR);
    }

    write("Will this armor have an struck special? [y/n] [n]");
    input_to("struckq");
    return;
}


void struckq(string str) {
    if(str == "y") {
        struck = 1;
        WF(STRUCK);
    }

    finish(0);
    return;
}


void finish(int step) {
    object ob;
    if(step == 0) {
        WF(CLOSE);

        WF("\n");
        if(wear) {
            WF(WEAR_FUNC);
            write("Please enter the message sent to the wearer of this armor when it's worn.");
            write("Use $O where the short of this armor should be filled in.");
            input_to("uwear");
            return 1;

        }
        else {
            finish(1);
        }
    }
    else if(step == 1) {
        WF("\n");
        if(remove) {
            WF(REMOVE_FUNC);
            write("Please enter the message sent to the wearer of this armor when it's removed.");
            write("Please note $O will be replaced with the short of this armor.");
            input_to("uremove");
            return 1;

        }
        else {
            finish(2);
        }
    }
    else if(step == 2) {
        WF("\n");
        if(struck) {

            WF(STRUCK_FUNC);
            write("Please enter the message sent to the wearer of this armor when it is hit by something.");
            write("Please note $O will be replaced with the short of this armor.");
            write("Please note $N will be replaced with the name of the opponent hitting the armor");
            input_to("ustruck");
            return 1;

        }
        else {
            finish(3);
        }
    }
    else if(step == 3) {
	  if(TEMP(TPQN)) 
	  {
	  	WF(TEMP(TPQN));
		TEMP_REMOVE(TPQN);
	  }
        ob = new(FILE);

        if(ob->move(TP) != MOVE_OK) {
            ob->move(ETP);
          write("Object finished, code saved, object cloned.");
            remove();
        }
        write("Object finished, code saved, object cloned.");
        remove();
    }
}


void uwear(string str) {
    if(!str) {
        write("Please enter the message sent to the wearer of this armor when it's worn.");
        write("Please note $O will be replaced with the short of this aror.");
        input_to("uwear");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");

    write("Please enter the message sent to the room of this armor when it's worn.");
    write("Please note $O will be replaced with the short of this armor. $N will be replaced with the name of the player wearing it.");
    input_to("rwear", str);
    return 1;
}


void rwear(string str, string str1) {
    if(!str) {
        write("Please enter the message sent to the room of this armor when it's worn.");
        write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the name of the player wearing it.");
        input_to("rwear");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    WF(DO_MESSAGE_BLOCK(str, str1));

    write("Please enter effect on player when wearing.");
//    write("1> stat bonus");
    write("1> attack bonus");
    write("2> damage bonus");
    write("3> damage wearer");
    write("     use a number to be max and it will be random of that, i.e. 10 for a random of 10 damage");
    write("4> magic resistance");
    write("     use a number for % resistance, i.e. 10 for 10%");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that adds 1 to both attack and damage bonus would appear as:");
    write("    2/1,3/1");
//    write(" Stat bonus would appear as 1/1/dexterity");
    write(" Be sure to reverse any bonus/penalty (damage is not a penalty) that you add here in the remove.");
    write("Note:  No entry means no effect.");
    input_to("wear_effect");
}

void do_effects(string str) {
    int i;
    string *effects, *stuff;
    effects = explode(str,",");
    for(i=0;i<sizeof(effects);i++) {
        stuff = explode(effects[i],"/");
        if(sizeof(stuff) >= 2) {
            switch(atoi(stuff[0])) {
                case 4:
                    WF("\tETO->set_property(\"magic resistance\","+stuff[1]+");\n");
                    break;
                case 3:
                    WF("\tETO->do_damage(\"torso\",random("+stuff[1]+"));\n");
                    break;
                case 2:
                    WF("\tETO->add_damage_bonus("+stuff[1]+");\n");
                    break;
                case 1:
                    WF("\tETO->add_attack_bonus("+stuff[1]+");\n");
                    break;
//                case 1:
//                    WF("\tETO->add_stat_bonus(\""+stuff[2]+"\","+stuff[1]+");\n");
//                    break;

            }
        }
    }
}

void wear_effect(string str) {
    int i;
    if(str) {
        do_effects(str);
    }

    WF("\treturn 1;\n");
    WF(CLOSE);

    finish(1);

}


void uremove(string str) {
    if(!str) {
        write("Please enter the message sent to the wearer of this armor when it's removed.");
        write("Please note $O will be replaced with the short of this armor.");
        input_to("uremove");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");

    write("Please enter the message sent to the room of this armor when it's removed.");
    write("Please note $O will be replace with the short of this armor.  $N will be replaced with the name of the wearer when it's removed.");
    input_to("rremove", str);
    return 1;
}


void rremove(string str, string str1) {
    if(!str) {
        write("Please enter the message sent to the room of this armor when it's removed.");
        write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the player's name.");
        input_to("rremove");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    WF(DO_MESSAGE_BLOCK(str, str1));

    write("Please enter effect on player when removing.");
//    write("1> stat bonus");
    write("1> attack bonus");
    write("2> damage bonus");
    write("3> damage wear");
    write("4> magic resistance");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that adds 1 to both attack and damage bonus would need to be reversed here as:");
    write("    2/-1,3/-1");
//    write(" Removing a (positive) stat bonus would need to be 1/-1/dexterity");
    write("Note; empty string means no effect.");
    input_to("remove_effect");
}


void remove_effect(string str) {
    int i;
    if(str) {
        do_effects(str);
    }
    WF("\treturn 1;\n");
    WF(CLOSE);

    finish(2);
}

void ustruck(string str) {
    if(!str) {
        write("Please enter the message sent to the wearer of this armor when it is hit by something.");
        write("Please note $O will be replaced with the short of this armor.");
        write("Please note $N will be replaced with the opponent hitting the armor.");
        input_to("ustruck");
        return;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+who->QCN+\"");

    write("Please enter the message sent to the room  when this armor is hit by something.");
    write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the wearer's name.  $T will be the hitter.");
    input_to("rstruck", str);
    return 1;
}

void rstruck(string str, string str1) {

    if(!str) {
        write("Please enter the message sent to the room when this armor is hit by something.");
        write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the wearer's name.  $T will be the hitter.");
        input_to("rstruck", str);
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$T","\"+who->QCN+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    write("Please enter the message sent to the person hittng this armor.");
    write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the wearer's name.");
    input_to("tremove", str, str1);
    return 1;
}

void tremove(string str, string str1, string str2) {

    if(!str) {
        write("Please enter the message sent to the person hittng this armor.");
        write("Please note $O will be replaced with the short of this armor.  $N will be replaced with the wearer's name.");
        input_to("tremove", str, str1);
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    write("Please enter the odds (out of 1000) that this special will go off.");
    input_to("odds", str, str1, str2);
    return 1;
}

void odds(string str,string str1, string str2, string str3) {
    if(str) {
        WF("\tif(random(1000) < "+str+"){\n");
    }
    else {
        WF("\t{\n");
    }
    WF(STRUCK_MESSAGE_BLOCK(str2,str1,str3));
    write("Please enter the type of effect this special will have.");
    write("0> none");
    write("1> adjust damage  <1/%>");
	write("2> paralyze wearer <2/#d#>");
	write("3> paralyze hitter <3/#d#>");
	write("4> damage hitter <4/#d#>");
    write("Note only one type of effect is allowed.");
    write("All amounts will be randomized.");
    write("Note:  For #1 the new damage will be (damage*%)/100");
    input_to("effect");
}

void effect(string str) {
    string amount,temp;
	int num,dice;
    if(str == "") {
        str = 0;
    }
    if(str) {
        amount = str[2..(strlen(str)-1)];
        if(!amount) 
		{
			input_to("odds");
			return;
		}

        if(str[0] == '1') {
	    WF("return (damage*"+amount+")/100;");

// was this but bugged in creation, trying above for a fix *Styx*  4/27/03
//          WF("\t\treturn (damage*"+amount+")/100;\n");

        }
        else if(str[0] == '2') {
			if(sscanf(amount,"%dd%d",num,dice) != 2)
			{
				write("Please input weapon class of this object. Please use the form #d#.");
				write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
				input_to("odds");
				return 1;
			}
            WF("\t\tETO->set_paralyzed(roll_dice("+num+","+dice+"));\n");
            WF("return damage;");
        }
        else if(str[0] == '3') {
			if(sscanf(amount,"%dd%d",num,dice) != 2)
			{
				write("Please input weapon class of this object. Please use the form #d#.");
				write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
				input_to("odds");
				return 1;
			}
            WF("\t\twho->set_paralyzed(roll_dice("+num+","+dice+"));\n");
            WF("return damage;");
        }
        else if(str[0] == '4') {
			if(sscanf(amount,"%dd%d",num,dice) != 2)
			{
				write("Please input weapon class of this object. Please use the form #d#.");
				write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
				input_to("odds");
				return 1;
			}
            WF("\t\twho->do_damage(\"torso\",roll_dice("+num+","+dice+"));\n");
            WF("return damage;");
        }
    }
    WF("\t"+CLOSE+"\n");
    WF(CLOSE);
    finish(3);
}