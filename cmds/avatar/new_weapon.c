#include <std.h>
#include "items.h"
#include <move.h>
#include <langs.h>

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
    string *valid_weaps, tmp;
    int i;
    ::init();
    write("Please choose the weapon type from the following list.  "+
       "You will need to type the choice just as it appears.");
    tmp = "";
    valid_weaps = get_dir("/d/common/obj/weapon/");
    for(i=0;i<sizeof(valid_weaps);i++){
       if(i > 200) break;
       if(valid_weaps[i] == "mithril") continue;
	 if (!(i % 4)) {
	    tell_object(TP,tmp);
	    tmp = "";
	 } else {
          tmp += ", ";
	 }
       tmp += ""+valid_weaps[i]+"";
    }
    write(tmp);
    input_to("weapon_choice");
    return;
}

void weapon_choice(string str){
    string *valid_weaps, tmp;
    int i;
    if(member_array(str,get_dir("/d/common/obj/weapon/")) == -1){
       write("That is not a valid choice!  Choose from the list below.  "+
       "You must type it exactly as it appears, including the .c.");
       tmp = "";
       valid_weaps = get_dir("/d/common/obj/weapon/");
       for(i=0;i<sizeof(valid_weaps);i++){
          if(i > 200) break;
          if(valid_weaps[i] == "mithril") continue;
    	    if (!(i % 4)) {
	       tell_object(TP,tmp);
	       tmp = "";
  	    } else {
             tmp += ", ";
 	    }
          tmp += ""+valid_weaps[i]+"";
       }
       write(tmp);
       input_to("weapon_choice");
       return;
    }
    WF(WEAPHEAD(str));
    WF(NAME(name));

    write("Please enter additional identities to the weapon.  "+
       "\n%^BOLD%^NOTE: %^RESET%^The standard ids for an "+
       "object of this type will already be there (like sword, "+
       "long sword, etc).  These are just others you want to add "+
       "in case you have unusual shorts or obvious shorts.\n"+
       "Separate ids with a comma - winter's chill, chill");
    input_to("pref");
}
//Pick up here.  Remember to use add_id to not erase the others


void pref(string str) {
    string * ids;
    if(!str) {
       write("Please enter additional identities to the weapon.  "+
          "\n%^BOLD%^NOTE: %^RESET%^The standard ids for an "+
          "object of this type will already be there (like sword, "+
          "long sword, etc).  These are just others you want to add "+
          "in case you have unusual shorts or obvious shorts.\n"+
          "Separate ids with a comma - winter's chill, chill");
        input_to("pref");
        return 1;
    }
    if(str == "**") return exit();
    ids = explode(str,",");
    input_to("check_ids",ids);
    write("The ids for this object as you have entered them "+
    "are "+identify(ids)+".  Is this correct, yes or no?");

    return 1;
}

void check_ids(string str, string *ids) {
    if(str == "**") {
        return exit();
    }
    if(str == "yes" || str == "y") {
        WF(ADDID(identify(ids)));
        write("Please input the Short describe for this Object.");
        input_to("short");
        return 1;
    }
    write("Please enter additional identities to the weapon.  "+
       "\n%^BOLD%^NOTE: %^RESET%^The standard ids for an "+
       "object of this type will already be there (like sword, "+
       "long sword, etc).  These are just others you want to add "+
       "in case you have unusual shorts or obvious shorts.\n"+
       "Separate ids with a comma - winter's chill, chill");
    input_to("pref");
    return 1;
}    

void short(string str) {
    if(!str) {
        write("Please input the Short describe for this Object.");
        input_to("short");
        return 1;
    }

    if(str == "**") return 1;
    input_to("check_short",str);
    write("The identified short of this object is "+str+
    " is this correct, yes or no?");
    return 1;
}

void check_short(string str, string short) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(SHORT(short));
        write("Please input the obvious short for this item.  This is "+
           "the short that one would generally classify as.");
        write("For Example: the short might be \"Queens medallion\", "+
           "the obvious short would be \"small medallion\"");
        write("NOTE: blank line is permitted");
        input_to("obv_short");
        return 1;
    }
    write("Please input the Short describe for this Object.");
    input_to("short");
    return 1;
}


void obv_short(string str){

    if(str == "**") return exit();
    if(str && str != "") {
        write("The obvious short for this object is "+str+
        " is this correct, yes or no?");
        input_to("check_obv_short",str);
        return 1;
    }
    write("Please input the Long describe >Note use ** to end "+
       "the long describe.  %^BOLD%^Don't quit in this field.%^RESET%^");
    input_to("long", "");
}

void check_obv_short(string str, string obv_short) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(OBVIOUS_SHORT(obv_short));
        write("Please input the Long describe >Note use ** to end "+
           "the long describe.  %^BOLD%^Don't quit in this field.%^RESET%^");
        input_to("long", "");
        return 1;
    }
    write("Please input the obvious short for this item.  This is "+
        "the short that one would generally classify as.");
    write("For Example: the short might be \"Queens medallion\", "+
        "the obvious short would be \"small medallion\"");
    write("NOTE: blank line is permitted");
    input_to("obv_short");
    return 1;
}


void long(string str,  string longd) {
    if(!str) {
        write("Please input the Long describe for this Object.");
        input_to("long",longd);
        return 1;
    }
    if(str != "**") {
        longd += str + "\n";
        input_to("long",longd);
        return;
    }
    write(longd+"\n Is this the correct long description?  yes "+
    "or no?");
    input_to("check_long",longd);
    return 1;
}

void check_long(string str, string longd) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(LONG(longd));
        write("Please input the (if any) result to the read <item> command.");
        write("Note this can be blank, use ** to end the read text");
        input_to("read","");
        return 1;
    }
    write("Please input the Long describe >Note use ** to end the "+
       "long describe.  %^BOLD%^Don't quit in this field.%^RESET%^");
    input_to("long", "");   
    return 1;
}

void read(string str, string longd) {
    if(str != "**") {
        longd += str + "\n";
        input_to("read",longd);
        return;
    }
    if(longd != "") {
        write(longd+"\nThe above is the writing on the object, "+
        "is it correct, yes or no?");
        input_to("check_read",longd);
        return;
    } else {
        write("Please input value of this object");
        input_to("value");
    }
}

void check_read(string str, string writing) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(READ(writing));
        write("Please input language the read of this object is in.");
        input_to("language");
        return 1;
    }
    write("Please input the (if any) result to the read <item> command.");
    write("Note this can be blank, use ** to end the read text");
    input_to("read","");
    return 1;
}

void language(string str){
    if (!str) {
        write("Please input language the read of this object is in.");
        input_to("language");
        return;
    }
    if (member_array(str,ALL_LANGS) == -1) {
        write("That is not a valid language.");
        write("Please input language the read of this object is in.");
        input_to("language");
        return;
    }
    write("The language the writing on this object is "+
    str+" is this correct, yes or no?");
    input_to("check_language",str);
    return 1;
}

void check_language(string str, string lang) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF("     set(\"langage\",\""+lang+"\");");
        write("Please input the value of this weapon.");
        input_to("value");   
        return 1;
    }
    write("Please input language the read of this object is in.");
    input_to("language");
    return 1;
}

void value(string str) {
    if(!str) {
        write("Please input the value for this weapon.");
        input_to("value");
        return 1;
    }
    if(str == "**") return exit();
    write("The value of this object is now "+str+" is this correct, "+
    "yes or no?");
    input_to("check_value",str);
    return 1;
}

void check_value(string str, string value) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(VALUE(value));
//        write("Please input any lore or legend for this item. Use ** to finish.");
        write("Would you like to include lore or a legend on this item? yes or no");
//        input_to("lore","");
        input_to("make_lore","");
        return 1;
    }
    write("Please input the value, note there is an assumption that the value is in gold.");
    write("If no value use 0.");
    input_to("value");
    return 1;
}

void make_lore(string str){
    if(str == "**") return exit();
    if(str == "yes" || str == "y"){
       write("Please input the lore or legend for this item.  Use ** to finish.");
       input_to("lore","");
       return 1;
    }
    if(str == "no" || str == "n"){
       write("Please input the enchantment for this weapon.");
       input_to("enchant");
       return 1;
    }
    write("Would you like to include lore or a legend on this item? yes or no");
    input_to("make_lore","");
    return 1;
}

void lore(string str, string dlore){

    if(str != "**") {
        dlore += str + "\n";
        input_to("lore",dlore);
        return;
    }
    if(dlore != "") {
        write(dlore+"\nThe above is the lore on the object "+
        "now, is it correct, yes or no?");
        input_to("check_lore",dlore);
        return 1;
    }
}

void check_lore(string str, string lore) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(LORE(lore));
        write("Please input the difficulty of discovering the lore on "+
        "this item.  Remember that this is an NWP and bards gain it "+
        "for free.  Lore difficulty can be any number, and the "+
        "character's studying NWP plus a random roll must be greater "+
        "than the lore difficulty for the character to see the lore.  "+
        "Use 0 if there is no difficulty.\n");
        input_to("lore_diff");
        return 1;
    }
    write("Please input any lore or legend for this item. Use ** to finish.");
    input_to("lore","");
    return 1;
}

void lore_diff(string str){
    if(!str) {
        write("Please input the lore difficulty for this item.\n");
        input_to("lore_diff");
        return;
    }
    write("The lore difficulty for this item is now "+str+" is "+
    "this correct, yes or no?");
    input_to("check_lore_diff",str);
    return 1;
}

void check_lore_diff(string str, string diff) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF("	set_property(\"lore difficulty\","+diff+");\n");
        write("Please input the enchantment for this weapon.");
        input_to("enchant");
        return 1;
    }
    write("Please input the difficulty of discovering the lore on "+
    "this item.  Remember that this is an NWP and bards gain it "+
    "for free.  Lore difficulty can be any number, and the "+
    "character's studying NWP plus a random roll must be greater "+
    "than the lore difficulty for the character to see the lore.  "+
    "Use 0 if there is no difficulty.\n");
    input_to("lore_diff");
    return 1;
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
    write("1> stat bonus");
    write("2> attack bonus");
    write("3> damage bonus");
    write("4> damage wielder");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that adds 1 to both attack and damage bonus would appear as:");
    write("    2/1,3/1");
    write(" Stat bonus would appear as 1/1/dexterity");
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
                case 4:
                    WF("\tETO->do_damage(\"torso\",random("+stuff[1]+"));\n");
                    break;
                case 3:
                    WF("\tETO->add_damage_bonus("+stuff[1]+");\n");
                    break;
                case 2:
                    WF("\tETO->add_attack_bonus("+stuff[1]+");\n");
                    break;
                case 1:
                    WF("\tETO->add_stat_bonus(\""+stuff[2]+"\","+stuff[1]+");\n");
                    break;

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
    write("1> stat bonus");
    write("2> attack bonus");
    write("3> damage bonus");
    write("4> damage wielder");
    write(" Enter in the form type/amount,type/amount");
    write(" So a sword that added 1 to both attack and damage bonus when wielded would need to be:");
    write("    2/-1,3/-1");
    write(" Stat bonus would appear as 1/-1/dexterity");
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