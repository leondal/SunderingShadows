// changes by Styx 4/27/03 to fix settings that bugged when MR or damage on wear was being set, cleaned up some typos, and added notes to indicate to use numbers for sizes and a few other clarifications.
// edited to use new stat system. Nienne, 09/07.

#include <std.h>
#include "items.h"
#include <move.h>

inherit OBJECT;

string FILE;
string type;
string name;

int unwield;
int wield;
int hit;

void finish(int step);

int save_me(string file){ return 1;}

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

    write("Please input the number type of weapon > ** will quit");
    write("1> slashing ------ fighter only sword/axe types");
    write("2> thiefslashing - Thief type of sword");
    write("3> piercing ------ rapier, poking types");
    write("4> thiefpiercing - thief pointy things");
    write("5> bludgeon ------ clubs hammers etc etc");
    write("6> magepiercing -- most daggers etc");
        write("7> magebludgeon -- small clubs magely stuff");
        write("8> lash ---------- whips and lashing stuff");
    input_to("type");
    return 1;
}

void type(string str) {
    string wtype;
    if(!str) {
        write("Please input the type for this weapon.");

        write("Please input the number type of weapon > ** will quit");
        write("1> slashing ------ fighter only sword/axe types");
        write("2> thiefslashing - Thief type of sword");
        write("3> piercing ------ rapier, poking types");
        write("4> thiefpiercing - thief pointy things");
        write("5> bludgeon ------ clubs hammers etc etc");
        write("6> magepiercing -- most daggers etc");
        write("7> magebludgeon -- small clubs magely stuff");
        input_to("type");
        return 1;
    }
    if(str == "**") return exit();

    switch(str) {
        case "1":
            wtype = "slashing";
            break;
        case "2":
            wtype = "thiefslashing";
            break;
        case "3":
            wtype = "piercing";
            break;
        case "4":
            wtype = "thiefpiercing";
            break;
        case "5":
            wtype = "bludgeon";
            break;
        case "6":
            wtype = "magepiercing";
            break;
        case "7":
            wtype = "magebludgeon";
            break;
        case "8":
            wtype = "lash";
            break;
        default:
            write("Please input the Number for the type for this weapon.");
            input_to("type");
            return 1;


    }
    WF(TYPE(wtype));
    write("Please input the proficiency type, Please note that blades, clublike, spear, axe, and hammer are sized.");
    input_to("prof");
    return;
}

void prof(string str) {
    if(!str) {
        write("Please input the proficiency type for this weapon.");
        input_to("prof");
        return 1;
    }
    if(str == "**") return exit();

    WF(PROF_TYPE(str));
    if(str == "lance") {
        WF(PROP("lance",1));
    }

    write("Please input size for this weapon.");
    input_to("size");
}

void size(string str) {
    if(!str) {
        write("Please input the size for this weapon.");
        write("%^BOLD%^1 for small,  2 for normal, 3 for large, 4 for giant (two handed for large races)%^RESET%^");
        input_to("size");
        return 1;
    }
    if(str == "**") return exit();
    WF(SIZE(str));
    write("Please input weapon class of this object. Please use the form #d#.");
    write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
    input_to("swc");
}


void swc(string str) {
    int num,dice;
    if(!str) {
        write("Please input weapon class of this object. Please use the form #d#.");
        write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
        input_to("swc");
        return 1;
    }
    if(str == "**") return exit();
    if(sscanf(str,"%dd%d",num,dice) != 2) {
        write("Please input weapon class of this object. Please use the form #d#.");
        write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
        input_to("swc");
        return 1;
    }
    WF(WC(num,dice));
    write("Please input large weapon class of this object. Please use the form #d#.");
    write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
    input_to("lwc");
    return;
}

void lwc(string str) {
    int num,dice;
    if(!str) {
        write("Please input large weapon class of this object. Please use the form #d#.");
        write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
        input_to("lwc");
        return 1;
    }
    if(str == "**") return exit();
    if(sscanf(str,"%dd%d",num,dice) != 2) {
        write("Please input large weapon class of this object. Please use the form #d#.");
        write("So if a two handed sword does 3 - 18 damage then it's 3d6,");
        input_to("lwc");
        return 1;
    }
    WF(LARGE_WC(num,dice));
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
    write("If this weapon offers an AC bonus enter it now.");
    write("That has balance implications so negative numbers are welcome.");
    input_to("ac");
}

void ac(string str) {

    if(str && str != "0") {
        WF(AC(str));
    }
    write("Will this weapon have a wield special? [y/n] [n]");
    write("Remember if you add a bonus to the player you will need to remove it in the unwield.");
    input_to("wieldq");
    return;
}

void wieldq(string str) {
    if(str == "y") {
        wield = 1;
        WF(WIELD);
    }

    write("Will this weapon have an unwield special? [y/n] [n]");
    write("Remember if you added a bonus(or penalty) to the player you will need to remove it here (negative numbers to remove a bonus).");
    input_to("unwieldq");
    return;
}


void unwieldq(string str) {
    if(str == "y") {
        unwield = 1;
        WF(UNWIELD);
    }

    write("Will this weapon have an hit special? [y/n] [n]");
    input_to("hitq");
    return;
}


void hitq(string str) {
    if(str == "y") {
        hit = 1;
        WF(HIT);
    }
    finish(0);
    return;
}


void finish(int step) {
    object ob;
    if(step == 0) {
        WF(CLOSE);

        WF("\n");
        if(wield) {
            WF(WIELD_FUNC);
            write("Please enter the message sent to the wielder of this weapon when it's wielded.");
            write("Please note $O will be replaced with the short of this weapon.");
            input_to("uwielder");
            return 1;

        }
        else {
            finish(1);
        }
    }
    else if(step == 1) {
        WF("\n");
        if(unwield) {
            WF(UNWIELD_FUNC);
            write("Please enter the message sent to the wielder of this weapon when it's unwielded.");
            write("Please note $O will be replaced with the short of this weapon.");
            input_to("uunwielder");
            return 1;

        }
        else {
            finish(2);
        }
    }
    else if(step == 2) {
        WF("\n");
        if(hit) {

            WF(HIT_FUNC);
            write("Please enter the message sent to the wielder of this weapon when it hits something.");
            write("Please note $O will be replaced with the short of this weapon.");
            write("Please note $T will be replaced with the target.");
            input_to("uhit");
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
            remove();
        }
        write("Object finished, code saved, object cloned.");
        remove();
    }
}


void uwielder(string str) {
    if(!str) {
        write("Please enter the message sent to the wielder of this weapon when it's wielded.");
        write("Please note $O will be replaced with the short of this weapon.");
        input_to("uwielder");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");

    write("Please enter the message sent to the room of this weapon when it's wielded.");
    write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective.");
    input_to("rwielder", str);
    return 1;
}


void rwielder(string str, string str1) {
    if(!str) {
        write("Please enter the message sent to the room of this weapon when it's wielded.");
        write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective.");
        input_to("rwielder");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    WF(DO_MESSAGE_BLOCK(str, str1));

    write("Please enter effect on wielder while wielding.");
//    write("1> stat bonus");
    write("1> attack bonus");
    write("2> damage bonus");
    write("3> damage wielder");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that adds 1 to both attack and damage bonus would appear as:");
    write("    2/1,3/1");
//    write(" Stat bonus would appear as 1/1/dexterity");
    write("Note:  No entry means no effect.");
    input_to("wield_effect");
}

void do_effects(string str) {
    int i;
    string *effects, *stuff;
    effects = explode(str,",");
    for(i=0;i<sizeof(effects);i++) {
        stuff = explode(effects[i],"/");
        if(sizeof(stuff) >= 2) {
            switch(atoi(stuff[0])) {
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

void wield_effect(string str) {
    int i;
    if(str) {
        do_effects(str);
    }
    WF("\treturn 1;\n");
    WF(CLOSE);

    finish(1);
}


void uunwielder(string str) {
    if(!str) {
        write("Please enter the message sent to the wielder of this weapon when it's unwielded.");
        write("Please note $O will be replaced with the short of this weapon.");
        input_to("uunwielder");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");

    write("Please enter the message sent to the room of this weapon when it's unwielded.");
    write("Please note $O will be replaced with the short of this weapon. $N will be replaced with the wielder's  name/adjective.");
    input_to("runwielder", str);
    return 1;
}


void runwielder(string str, string str1) {
    if(!str) {
        write("Please enter the message sent to the room of this weapon when it's unwielded.");
        write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective.");
        input_to("runwielder");
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    WF(DO_MESSAGE_BLOCK(str, str1));

    write("Please enter effect on wielder when unwielding.");
    write("If you added bonus/penalties such as attack/damage/stat bonuses, you need to remove them here.  If you added a damage bonus of 1, here you need to do a damage bonus of -1.");
//    write("1> stat bonus");
    write("1> attack bonus");
    write("2> damage bonus");
    write("3> damage wielder");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that added 1 to both attack and damage bonus when wielded would need to be:");
    write("    2/-1,3/-1");
//    write(" Stat bonus would appear as 1/-1/dexterity");
    write("Note:  no entry means no effect.");
    input_to("unwield_effect");
}


void unwield_effect(string str) {
    int i;
    if(str) {
        do_effects(str);
    }
    WF("\treturn 1;\n");
    WF(CLOSE);

    finish(2);
}

void uhit(string str) {

    if(!str) {
        write("Please enter the message sent to the wielder of this weapon when it hits something.");
        write("Please note $O will be replaced with the short of this weapon.");
        write("Please note $T will be replaced with the target.");
        input_to("uhit");
        return;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$T","\"+targ->QCN+\"");

    write("Please enter the message sent to the room of this weapon when it hits.");
    write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective. $T will be the target.");
    input_to("rhit", str);
    return 1;
}

void rhit(string str, string str1) {

    if(!str) {
        write("Please enter the message sent to the room of this weapon when it hits.");
        write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective. $T will be the target.");
        input_to("rhit");
        return;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$T","\"+targ->QCN+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    write("Please enter the message sent to the target of this weapon when it hits.");
    write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective.");
    input_to("thit", str, str1);
    return 1;
}

void thit(string str, string str1, string str2) {

    if(!str) {
        write("Please enter the message sent to the target of this weapon when it hits.");
        write("Please note $O will be replaced with the short of this weapon.  $N will be replaced with the wielder's name/adjective.");
        input_to("thit", str, str1);
        return 1;
    }
    str = replace_string(str,"$O","\"+query_short()+\"");
    str = replace_string(str,"$N","\"+ETOQCN+\"");

    write("Please enter the odds (out of 1000) that this special will go off when the weapon hits the target.\nCaution:  Keep in mind that higher levels may get several hits in per round, so a 300 (approximately 1/3) may special pretty much every round for a level 15 or 20 fighter/ranger/knight that is hitting regularly.");
    input_to("odds", str, str1, str2);
    return 1;
}

void odds(string str,string str1, string str2, string str3) {
    if(str) {
        WF("\tif(random(1000) < "+str+"){\n");
    }else {
        WF("\t{\n");
    }
    WF(HIT_MESSAGE_BLOCK(str2,str1,str3));
    write("Please enter the type of effect this will have.");
    write("0> none");
    write("1> extra damage");
    write("2> paralyze");
    write("Note only one type of effect is allowed.");
    write("Enter in form #/#d#mod   eg 1/3d4-1");
    write("All amounts will be randomized.  Paralyze is for how long the paralyze will last.");
    input_to("effect");
}

void effect(string str){
    string amount;
    int dice1,dice2,mod;
    if(str == "") {
        str = 0;
    }
    if(str){
      if(str[0] == '0'){ 
         WF("\t"+CLOSE+"\n");
           WF(CLOSE);
           finish(3);
      }
        amount = str[2..(strlen(str)-1)];

        if(!amount) amount = "";
        sscanf(amount,"%dd%d%d",dice1,dice2,mod);
        if(str[0] == '1') {
            WF("\t\treturn roll_dice("+dice1+","+dice2+")+"+mod+";");

        } else if(str[0] == '2') {
            WF("\t\ttarg->set_paralyzed(roll_dice("+dice1+","+dice2+")+"+mod+");\n");
            WF("return 0;");
        }
    }
    WF("\t"+CLOSE+"\n");
    WF(CLOSE);
    finish(3);
}
