#include <std.h>

inherit OBJECT;

#include <langs.h>
#include "items.h"
#include <move.h>

#include <crafting.h>

#define STATBONUSES (({ "constitution", "charisma", "dexterity", "strength", "intelligence", "wisdom" }))
#define SKILLBONUSES (({ "academics", "athletics", "craft, armorsmith", "craft, jeweller", "craft, leatherworker", "craft, tailor", "craft, weaponsmith", "craft, woodworker",\
 "disguise", "dungeoneering", "endurance", "healing", "influence", "perception", "rope use", "stealth", "spellcraft", "survival", "thievery" }))
#define MISCBONUSES (({ "magic resistance", "spell damage resistance", "damage resistance", "armor bonus", "attack bonus", "damage bonus", "sight bonus",\
 "will", "fortitude", "reflex", "caster level", "bonus spell slots", "spell penetration" }))

string FILE, type, name, subtype;
int emotes = 0;
int cur_emote = 0;
mapping datamap = ([]);
void startme(string str);
void finish();

int save_me(string file){ return 1;}
void set_file_name(string f) { FILE = f; }
void set_object_type(string t) { type=t; }
void set_name(string n) { name = n; }

void exit() {
    rm(FILE);
    if(TEMP(TPQN)) TEMP_REMOVE(TPQN);
    remove();
}

void init() {
    ::init();
    if(TEMP(TPQN)) TEMP_REMOVE(TPQN);
    if(type != "object") {
      write("Please enter the specific item type you are using as a base for mechanics.");
      write("For example, a +3 amulet would be 'cloak' under the tailor type.");
      write("See the helpfile for the appropriate craft skill if you are unsure.");
      write("Type ** to quit.");
      input_to("startme");
      return;
    }
    startme("object");
}

void startme(string str) {
    string *options;
    if(str == "**") return exit();
    if(!str) {
        write("Please enter the specific item type you are using as a base for mechanics");
        write("For example, a +3 amulet would be 'cloak' under the tailor type.");
        write("See the helpfile for the appropriate craft skill if you are unsure.");
        write("Type ** to quit.");
        input_to("startme");
        return 1;
    }
    switch(type) {
      case "armorsmith": datamap = ARMORSMITH; break;
      case "weaponsmith": datamap = WEAPONSMITH; break;
      case "tailor": datamap = TAILOR; break;
      case "jeweller": datamap = JEWEL; break;
      case "woodworker": datamap = WOODWORK; break;
      case "leatherworker": datamap = LEATHERWORK; break;
    }
    if(type != "object") options = keys(datamap);
    if(type != "object" && member_array(str,options) == -1) {
      write(""+str+" is not a valid item for the "+type+" craft skill.");
      write("Please enter the specific item type you are using as a base for mechanics");
      write("For example, a +3 amulet would be 'cloak' under the tailor type.");
      write("See the helpfile for the appropriate craft skill if you are unsure.");
      write("Type ** to quit.");
      input_to("startme");
      return 1;
    }
    if(type == "object") WF(HEADER("OBJECT"));
    else WF(HEADER2(datamap[str]["file"]));
    WF(NAME(name));
    if(type == "woodworker" || type == "leatherworker") subtype = datamap[str]["type"];

    write("Please enter the identities of the object.");
    write("Comma deliminate multiple id's < sword,longsword,long sword,death sword >");
    write("Type ** to quit.");
    input_to("pref");
}

void pref(string str) {
    string * ids;
    if(!str) {
        write("Please enter the identities of the object.");
        write("Comma deliminate multiple id's < sword,longsword,long sword,death sword >");
        write("Type ** to quit.");
        input_to("pref");
        return 1;
    }
    if(str == "**") return exit();
    ids = explode(str,",");
    write("The ids for this object as you have entered them are "+identify(ids)+".  Is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_ids",ids);
    return 1;
}

void check_ids(string str, string *ids) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        if(type == "flight arrows") ids += ({"longbow arrow"});
        if(type == "sheath arrows") ids += ({"shortbow arrow"});
        if(type == "bolts") ids += ({"heavy quarrels"});
        WF(ID(identify(ids)));
        write("Please input the short describe for this Object.");
        input_to("short");
        return 1;
    }
    write("Please enter the identities of the object.");
    write("Comma deliminate multiple id's < sword,longsword,long sword,death sword >");
    write("Type ** to quit.");
    input_to("pref");
    return 1;
}

void short(string str) {
    if(!str) {
        write("Please input the short describe for this Object.");
        write("Type ** to quit.");
        input_to("short");
        return 1;
    }

    if(str == "**") return exit();
    input_to("check_short",str);
    write("The identified short of this object is "+str+".  Is this correct, yes or no?");
    write("Type ** to quit.");
    return 1;
}

void check_short(string str, string short) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(SHORT(short));
        write("Please input the obvious short for this item. This is the short that one would generally classify as.");
        write("For Example: the short might be \"Queens medallion\", the obvious short would be \"small medallion\"");
        write("NOTE: a blank line will simply use the short describe by default.");
        write("Type ** to quit.");
        input_to("obv_short");
        return 1;
    }
    write("Please input the short describe for this Object.");
    write("Type ** to quit.");
    input_to("short");
    return 1;
}

void obv_short(string str){
    if(str == "**") return exit();
    if(str && str != "") {
        write("The obvious short for this object is ("+str+
        ").  Is this correct, yes or no?");
        write("Type ** to quit.");
        input_to("check_obv_short",str);
        return 1;
    }
    write("Please input the Long describe >Note use ** to end the long describe don't quit in this field.");
    input_to("long", "");
}

void check_obv_short(string str, string obv_short) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(OBVIOUS_SHORT(obv_short));
        write("Please input the Long describe >Note use ** to end the long describe don't quit in this field.");
        input_to("long", "");
        return 1;
    }
    write("Please input the obvious short for this item. This is the short that one would generally classify as.");
    write("For Example: the short might be \"Queens medallion\", the obvious short would be \"small medallion\"");
    write("NOTE: a blank line will simply use the short describe by default.");
    write("Type ** to quit.");
    input_to("obv_short");
    return 1;
}

void long(string str,  string longd) {
    if(!str) {
        write("Please input the Long describe >Note use ** to end the long describe don't quit in this field.");
        input_to("long",longd);
        return 1;
    }
    if(str != "**") {
        longd += str + "\n";
        input_to("long",longd);
        return;
    }
    write(longd+"\nIs this the correct long description?  yes or no?");
    write("Type ** to quit.");
    input_to("check_long",longd);
    return 1;
}

void check_long(string str, string longd) {
    string *desc_sections=({});
    int i,num,hops,extra;

    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        num = strlen(longd);
        if(num > 200) {
            hops = num/200;
            extra = num%200;
            for(i=0;i<hops;i++) desc_sections += ({ longd[(i*200)..((i*200)+199)] });
            if(extra) desc_sections += ({ longd[(hops*200)..num] });
        }
        if(pointerp(desc_sections) && desc_sections != ({})) {
            WF("\tset_long(\""+desc_sections[0]+"\"");
            for(i=1;i<sizeof(desc_sections);i++) WF("\n\t\""+desc_sections[i]+"\"");
            WF("\t);\n");
        }
        else WF("\tset_long(\""+longd+"\");\n");
        write("Please input the value, note there is an assumption that the value is in gold.");
        write("If no value use 0.");
        write("Type ** to quit.");
        input_to("value");
        return 1;
    }
    write("Please input the Long describe >Note use ** to end the long describe don't quit in this field.");
    input_to("long", "");
    return 1;
}

void value(string str) {
    if(!str) {
        write("Please input the value, note there is an assumption that the value is in gold.");
        write("If no value use 0.");
        write("Type ** to quit.");
        input_to("value");
        return 1;
    }
    if(str == "**") return exit();
    write("The value of this object is now "+str+" is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_value",str);
    return 1;
}

void check_value(string str, string value) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(VALUE(value));
        if(type == "object") {
          write("Please input the weight, if no weight use 0.");
          write("Type ** to quit.");
          input_to("weight");
          return 1;
        }
        write("Would you like to include lore or a legend on this item? yes or no");
        write("Type ** to quit.");
        input_to("make_lore","");
        return 1;
    }
    write("Please input the value, note there is an assumption that the value is in gold.");
    write("If no value use 0.");
    write("Type ** to quit.");
    input_to("value");
    return 1;
}

void weight(string str) {
    if(!str) {
        write("Please input the weight, if no weight use 0.");
        write("Type ** to quit.");
        input_to("weight");
        return 1;
    }
    if(str == "**") return exit();
    write("The weight of this object is now "+str+" is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_weight",str);
    return 1;
}

void check_weight(string str, string weight) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(WEIGHT(weight));
        write("Would you like to include lore or a legend on this item? yes or no");
        write("Type ** to quit.");
        input_to("make_lore","");
        return 1;
    }
    write("Please input the weight, if no weight use 0.");
    write("Type ** to quit.");
    input_to("weight");
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
        write("Please input any magical bonuses or negatives on this "+
        "item. This should be given in the form of charisma, wisdom, "+
        "stealth, healing, magic resistance, damage resistance, caster "+
        "level, etc. Use 0 if there are no stat bonuses on this item.\n");
        write("Type ** to quit.");
        input_to("stat_add");
        return;
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
    write(dlore+"\nThe above is the lore on the object now, is it correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_lore",dlore);
    return 1;
}

void check_lore(string str, string lore) {
    string *lore_sections=({});
    int i,num,hops,extra;

    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        num = strlen(lore);
        if(num > 200) {
            hops = num/200;
            extra = num%200;
            for(i=0;i<hops;i++) lore_sections += ({ lore[(i*200)..((i*200)+199)] });
            if(extra) lore_sections += ({ lore[(hops*200)..num] });
        }
        if(pointerp(lore_sections) && lore_sections != ({})) {
            WF("\tset_lore(\""+lore_sections[0]+"\"");
            for(i=1;i<sizeof(lore_sections);i++) WF("\n\t\""+lore_sections[i]+"\"");
            WF("\t);\n");
        }
        else WF("\tset_lore(\""+lore+"\");\n");
        write("Please input the difficulty of discovering the lore on "+
        "this item.  Remember that this is based on the academics skill "+
        "and should roughly reflect the level of the character it is "+
        "designed for.  Use 0 if there is no difficulty.\n");
        write("Type ** to quit.");
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
        write("Type ** to quit.");
        input_to("lore_diff");
        return;
    }
    write("The lore difficulty for this item is now "+str+", is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_lore_diff",str);
    return 1;
}

void check_lore_diff(string str, string diff) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF("\tset_property(\"lore difficulty\","+diff+");\n");
        write("Please input any magical bonuses or negatives on this "+
        "item. This should be given in the form of charisma, wisdom, "+
        "stealth, healing, magic resistance, damage resistance, caster "+
        "level, etc. Use 0 if there are no stat bonuses on this item.\n");
        write("Type ** to quit.");
        input_to("stat_add");
        return;
    }
    write("Please input the difficulty of discovering the lore on "+
    "this item.  Remember that this is based on the academics skill "+
    "and should roughly reflect the level of the character it is "+
    "designed for.  Use 0 if there is no difficulty.\n");
    write("Type ** to quit.");
    input_to("lore_diff");
    return 1;
}

void stat_add(string str) {
    if(str == "**") return exit();
    if(str == "0") {
        write("Do you wish for this item to have a heartbeat?  (This will "+
        "allow the item to have emotes that happen over time - similiar to "+
        "the way the storm robes work).\n"+
        "Yes or No?");
        write("Type ** to quit.");
        input_to("check_heart_beat", str);
        return 1;
    }
    if((member_array(str,STATBONUSES) != -1) || (member_array(str,SKILLBONUSES) != -1) || (member_array(str,MISCBONUSES) != -1)) {
        write("You have specified "+str+". Please input the bonus or "
        "negative to this attribute. This shound be given as a standard "
        "number, eg/ 1, -2. Use 0 to cancel this bonus.\n");
        write("Type ** to quit.");
        input_to("check_stat_add",str);
        return 1;
    }
    write("The "+str+" is not a valid type of item bonus. "+
    "Please input any further magical bonuses or negatives on this "+
    "item. This should be given in the form of charisma, wisdom, "+
    "stealth, healing, magic resistance, damage resistance, caster "+
    "level, etc. Use 0 if there are no more stat bonuses on this item.\n");
    write("Type ** to quit.");
    input_to("stat_add");
    return 1;
}

void check_stat_add(int mybonus, string str) {
    if(str == "**") return exit();
    if(mybonus != "0") {
        WF("\tset_item_bonus(\""+str+"\","+mybonus+");\n");
        write("File: "+str+" of "+mybonus+" added to your item. "+
        "Please input any further magical bonuses or negatives on this "+
        "item. This should be given in the form of charisma, wisdom, "+
        "stealth, healing, magic resistance, damage resistance, caster "+
        "level, etc. Use 0 if there are no more stat bonuses on this item.\n");
        write("Type ** to quit.");
        input_to("stat_add");
        return 1;
    }
    write("Please input any magical bonuses or negatives on this "+
    "item. This should be given in the form of charisma, wisdom, "+
    "stealth, healing, magic resistance, damage resistance, caster "+
    "level, etc. Use 0 if there are no more stat bonuses on this item.\n");
    write("Type ** to quit.");
    input_to("stat_add");
    return 1;
}

void check_heart_beat(string str) {
    if(str == "**") return exit();
    if(str == "n" || str == "N" || str == "No" || str == "no") {
        finish();
        return 1;
    }
    if(str == "y" || str == "Yes" || str == "yes" || str == "Y") {
        WF(HEART_BEAT);
        write("How many different emotes do you want this item to have?  Enter "+
        "a number between 1 and 10.\n");
        write("Type ** to quit.");
        input_to("number_of_emotes", str);
        return 1;
    }
    write("Do you wish for this item to have a heartbeat?  (This will allow "+
    "the item to have emotes that happen over time - similiar to the way the "+
    "storm robes work).\n"+
    "Yes or No?\n");
    write("Type ** to quit.");
    input_to("check_heart_beat", str);
    return 1;
}

void number_of_emotes(string str) {
    if(str == "**") return exit();
    if(to_int(str) < 1 || to_int(str) > 10) {
        write("You must enter a number between 1 and 10.  Please try again.\n");
        write("Type ** to quit.");
        input_to("number_of_emotes", str);
        return 1;
    }
    TEMP_WRITE(TPQN, TEMP_HEADER);
    TEMP_WRITE(TPQN, TEMP_SWITCH(to_int(str)));
    emotes = to_int(str);
    cur_emote++;
    write("Input the message that possessor of this item will see for emote "+
    cur_emote+".\nUse $O to display the short of the object."+
    "\nUse $N to display the item possessor.\n"+
    "Use $POSS to display his/her (the possessive of the item possessor).\n"+
    "Use $SUB to display he/she (the subjective of the item possessor).\n");
    write("Type ** to quit.");
    input_to("grab_personal_emote", str);
    return 1;
}

void grab_personal_emote(string str, string emote) {
    if(str == "**") return exit();
    if(!str) {
        write("Input the message that possessor of this item will see for "
        "emote "+cur_emote+".\nUse $O to display the short of the object."+
        "\nUse $N to display the item possessor.\n"+
        "Use $POSS to display his/her (the possessive of "+
        "the item possessor).\n"+
        "Use $SUB to display he/she "+
        "(the subjective of the item possessor).\n");
        write("Type ** to quit.");
        input_to("grab_personal_emote", str);
        return 1;
    }
    emote = str;
    write(str+"\nYou entered the above for what the item possessor sees for "+
"the emote "+cur_emote+".\n  Is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_personal_emote", str, emote);
    return 1;
}

void grab_room_emote(string str, string emote) {
    if(str == "**") return exit();
    if(!str) {
        write("Input the message that the people in the room see for the "+
        "emote "+cur_emote+".\nUse $O to display the short of the object."+
        "\nUse $N to display the item possessor.\n"+
        "Use $POSS to display his/her (the possessive "+
        "of the item possessor).\n"+
        "Use $SUB to display he/she (the subjective of "+
        "the item possessor).\n");
        write("Type ** to quit.");
        input_to("grab_room_emote", str);
        return 1;
    }
    emote = str;
    write(str+"\nYou entered the above for what the room sees for the emote "+
    cur_emote+".\n  Is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_room_emote", str, emote);
    return 1;
}

void check_personal_emote(string str, string emote) {
    if(str == "**") return exit();
    if(str == "n" || str == "No" || str == "no" || str == "N") {
        write("Input the message that possessor of this item will see for "+
        "emote "+cur_emote + ".\nUse $O to display the short of the object."+
        "\nUse $N to display the item possessor.\n"+
        "Use $POSS to display his/her (the possessive of the "+
        "item possessor).\n"+
        "Use $SUB to display he/she (the subjective of the item "+
        "possessor).\n");
        write("Type ** to quit.");
        input_to("grab_personal_emote", str);
        return 1;
    }
    if(str == "Y" || str == "yes" || str == "y" || str == "Yes") {
        emote = replace_string(emote, "$O", "\"+query_short()+\"");
        emote = replace_string(emote, "$N", "\"+ETOQCN+\"");
        emote = replace_string(emote, "$POSS", "\"+ETO->QP+\"");
        emote = replace_string(emote, "$SUB", "\"+ETOQS+\"");
        TEMP_WRITE(TPQN, TEMP_CASE((cur_emote-1)));
        TEMP_WRITE(TPQN, TEMP_IP_EMOTE(emote));
        write("Input the message that the people in the room see for the "+
        "emote "+cur_emote+".\nUse $O to display the short of the object."+
        "\nUse $N to display the item possessor.\n"+
        "Use $POSS to display his/her (the possessive of "+
        "the item possessor).\n"+
        "Use $SUB to display he/she (the subjective of the "+
        "item possessor).\n");
        write("Type ** to quit.");
        input_to("grab_room_emote", str);
        return 1;
    }
    write(emote+"\nYou entered the above for what the item possessor sees for "+
    "the emote "+cur_emote+".\n  Is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_personal_emote", str, emote);
    return 1;
}

void check_room_emote(string str, string emote) {
    if(str == "**") return exit();
    if(str == "n" || str == "No" || str == "no" || str == "N") {
        write("Input the message that the people in the room see for the "+
        "emote "+cur_emote+".\nUse $O to display the short of the object."+
        "\nUse $N to display the item possessor.\n"+
        "Use $POSS to display his/her (the possessive of "+
        "the item possessor).\n"+
        "Use $SUB to display he/she (the subjective of the "+
        "item possessor).\n");
        write("Type ** to quit.");
        input_to("grab_room_emote", str);
        return 1;
    }
    if(str == "y" || str == "Y" || str == "yes" || str == "Yes") {
        emote = replace_string(emote, "$O", "\"+query_short()+\"");
        emote = replace_string(emote, "$N", "\"+ETOQCN+\"");
        emote = replace_string(emote, "$POSS", "\"+ETO->QP+\"");
        emote = replace_string(emote, "$SUB", "\"+ETOQS+\"");
        TEMP_WRITE(TPQN, TEMP_ROOM_EMOTE(emote));
        TEMP_WRITE(TPQN, TEMP_CASE_CLOSE);
        if(cur_emote != emotes) {
            cur_emote++;
            write("Input the message that possessor of this item will see for "+
            "emote "+cur_emote+".\nUse $O to display the short of the object."+
            "\nUse $N to display the item possessor.\n"+
            "Use $POSS to display his/her (the possessive of "+
            "the item possessor).\n"+
            "Use $SUB to display he/she (the subjective of "+
            "the item possessor).\n");
            write("Type ** to quit.");
            input_to("grab_personal_emote", str);
            return 1;
        }
        else {
            TEMP_WRITE(TPQN, TEMP_SWITCH_CLOSE);
            TEMP_WRITE(TPQN, TEMP_HEADER_CLOSE);
            TEMP_WRITE(TPQN, TEMP_CLOSE);
            finish();
            return 1;
        }
    }
    write(emote+"\nYou entered the above for what the room sees for the emote "+
    cur_emote+".\n  Is this correct, yes or no?");
    write("Type ** to quit.");
    input_to("check_room_emote", str, emote);
    return 1;
}

void finish(){
    object ob;
    if(type == "armorsmith" || type == "tailor" || type == "jeweller" || subtype == "armor"){
        ob = new("/cmds/avatar/armor3");
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);
        ob->move(TP);
        remove();
        return;
    }
    if(subtype == "lrweapon"){
        ob = new("/cmds/avatar/weapon3"); //add specialty details to longranged later
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);
        ob->move(TP);
        remove();
        return;
    }
    if(type == "weaponsmith" || subtype == "weapon"){
        ob = new("/cmds/avatar/weapon3");
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);
        ob->move(TP);
        remove();
        return;
    }
    WF(CLOSE);
    if(TEMP(TPQN)) {
        WF(TEMP(TPQN));
        TEMP_REMOVE(TPQN);
    }
    ob = new(FILE);
    if(ob->move(TP) != MOVE_OK) ob->move(ETP);
    write("Object finished, code saved, object cloned.");
    remove();
    return;
}
