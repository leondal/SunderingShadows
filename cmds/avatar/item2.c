// edited to use new stat system. Nienne, 09/07.
#include <std.h>
#include "items.h"
#include <move.h>
#include <langs.h>


inherit OBJECT;

string FILE;
string type;
string name;
int emotes = 0;
int cur_emote = 0;

void finish();


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
    if(TEMP(TPQN))
    { 
         TEMP_REMOVE(TPQN);
    }
    WF(HEADER(VALID_TYPES[type]));
    WF(NAME(name));

    write("Please enter the identities of the object.");
    write("comma deliminate multiple id's < sword,longsword,long sword, death sword >");
    input_to("pref");

}



void pref(string str) {
    string * ids;
    if(!str) {
        write("Please enter the identities of the object.");
        write("comma deliminate multiple id's < sword,longsword,long sword, death sword >");
        input_to("pref");
        return 1;
    }
    if(str == "**") return exit();
    
    ids = explode(str,",");
    input_to("check_ids",ids);
    write("The ids for this object as you have entered them "+
    "are %^RED%^"+identify(ids)+"%^RESET%^.  Is this correct, yes or no?");

    return 1;
}

void check_ids(string str, string *ids) {
    if(str == "**") {
        return exit();
    }
    if(str == "yes" || str == "y") {
        WF(ID(identify(ids)));
        write("Please input the Short describe for this Object.");
        input_to("short");
        return 1;
    }
    write("Please enter the identities of the object.");
    write("comma deliminate multiple id's < sword,longsword,long sword, death sword >");
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
        write("Please input the obvious short for this item. This is the short that one would generally classify as.");
        write("For Example: the short might be \"Queens medallion\", the obvious short would be \"small medallion\"");
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
        write("The obvious short for this object is %^RED%^(%^RESET%^"+str+
        "%^RED%^)%^RESET%^ is this correct, yes or no?");
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
    write("Please input the Long describe >Note use ** to end the long describe don't quit in this field.");
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
        write("Please input weight of this object");
        input_to("weight");
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
    write("The language the writing on this object is %^RED%^"+
    str+"%^RESET%^ is this correct, yes or no?");
    input_to("check_language",str);
    return 1;
}

void check_language(string str, string lang) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF("     set(\"langage\",\""+lang+"\");");
        write("Please input the weight of this object");
        input_to("weight");   
        return 1;
    }
    write("Please input language the read of this object is in.");
    input_to("language");
    return 1;
}

void weight(string str) {
    if(!str) {
        write("Please input the weight for this weapon.");
        input_to("weight");
        return 1;
    }
    if(str == "**") return exit();
    write("The weight of this object is now %^RED%^"+str+"%^RESET%^ is this correct, "+
    "yes or no?");
    input_to("check_weight",str);
    return 1;
}

void check_weight(string str, string weight) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(WEIGHT(weight));
        write("Please input the value, note there is an assumption that the value is in gold.");
        write("If no value use 0.");
        input_to("value");
        return 1;
    }
    write("Please input the weight of this object");
    input_to("weight"); 
    return 1;
}

void value(string str) {
    if(!str) {
        write("Please input the value for this weapon.");
        input_to("value");
        return 1;
    }
    if(str == "**") return 1;
    write("The value of this object is now %^RED%^"+str+"%^RESET%^ is this correct, "+
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
       write("Please input any stat bonuses or negatives on this "+
        "item. This should be given in the form of conbonus, chabonus "+
        "etc. Use 0 if there are no stat bonuses on this item.\n");
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
        write("Please input any stat bonuses or negatives on this "+
        "item. This should be given in the form of conbonus, chabonus "+
        "etc. Use 0 if there are no stat bonuses on this item.\n");
        input_to("stat_add");
        return;
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

void stat_add(string str) 
{
    	if(str == "0") 
	{
      	write("Do you wish for this item to have a heartbeat?  (This will allow the item "+
	  	"to have emotes that happen over time - similiar to the way the storm robes work).\n"+
	  	"Yes or No?");
	  	input_to("check_heart_beat", str);
        	return 1;
	}
    	if(str == "conbonus" || str == "chabonus" || str == "dexbonus" || 
	str == "strbonus" || str == "intbonus" || str == "wisbonus") 
	{
      	write("You have specified "+str+". Please input the bonus or "
          	"negative to this stat. This shound be given as a standard "
          	"number, eg/ 1, -2. Use 0 to cancel this bonus.\n");
        	input_to("check_stat_add",str);
        	return 1;
    	}
    	write("Please input any stat bonuses or negatives on this "+
      	"item. This should be given in the form of conbonus, chabonus "+
        	"etc. Use 0 if there are no more stat bonuses on this item.\n");
    	input_to("stat_add");
    	return 1;
}

void check_stat_add(int mybonus, string str) {
    if(mybonus != "0") {
        WF("	set(\""+str+"\","+mybonus+");\n");
        write("File: "+str+" of "+mybonus+" added to your item. "+
          "Please input any further stat bonuses or negatives on this "+
        "item. This should be given in the form of conbonus, chabonus "+
        "etc. Use 0 if there are no more stat bonuses on this item.\n");
        input_to("stat_add");
        return 1;
    }
    write("Please input any stat bonuses or negatives on this "+
      "item. This should be given in the form of conbonus, chabonus "+
      "etc. Use 0 if there are no more stat bonuses on this item.\n");
      input_to("stat_add");
    return 1;
}

void check_heart_beat(string str)
{
	if(str == "**") return exit(); 
	if(str == "n" || str == "N" || str == "No" || str == "no") 
	{
		finish();
		return 1;
	}
	if(str == "y" || str == "Yes" || str == "yes" || str == "Y")
	{
		WF(HEART_BEAT);
		write("How many different emotes do you want this item to have?  Enter a "+
		"number between 1 and 10.\n");
		input_to("number_of_emotes", str);
		return 1;
	}
	write("Do you wish for this item to have a heartbeat?  (This will allow the item "+
	"to have emotes that happen over time - similiar to the way the storm robes work).\n"+
	"Yes or No?\n");
	input_to("check_heart_beat", str);
      return 1;
}
		
void number_of_emotes(string str)
{
	if(str == "**") return exit();
	if(to_int(str) < 1 || to_int(str) > 10) 
	{
		write("You must enter a number between 1 and 10.  Please try again.\n");
		input_to("number_of_emotes", str);
		return 1;
	}
	TEMP_WRITE(TPQN, TEMP_HEADER);
	TEMP_WRITE(TPQN, TEMP_SWITCH(to_int(str)));
	emotes = to_int(str);
	cur_emote++;
	write("Input the message that possessor of this item will see for emote "+cur_emote + 
	".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
	"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
	"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of the item possessor).\n"+
	"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of the item possessor).\n");
	input_to("grab_personal_emote", str);	
	return 1;
}

void grab_personal_emote(string str, string emote)
{
	if(str == "**") return exit();
	if(!str)
	{
		write("Input the message that possessor of this item will see for emote "+cur_emote + 
		".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
		"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
		"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of "+
		"the item possessor).\n"+
		"Use %^YELLOW%^$SUB%^RESET%^ to display he/she "+
		"(the subjective of the item possessor).\n");
		input_to("grab_personal_emote", str);	
		return 1;
	}
	emote = str;
	write(str+"\nYou entered the above for what the item possessor sees for the emote "+
	cur_emote+".\n  Is this correct, yes or no?");
	input_to("check_personal_emote", str, emote);
	return 1;
}

void grab_room_emote(string str, string emote)
{
	if(str == "**") return exit();
	if(!str)
	{
		write("Input the message that the people in the room see for the emote "+cur_emote+
		".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
		"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
		"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive "+
		"of the item possessor).\n"+
		"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of "+
		"the item possessor).\n");
		input_to("grab_room_emote", str);
		return 1;	
	}
	emote = str;
	write(str+"\nYou entered the above for what the room sees for the emote "+
	cur_emote+".\n  Is this correct, yes or no?");
	input_to("check_room_emote", str, emote);
	return 1;
}

void check_personal_emote(string str, string emote)
{
	if(str == "**") return exit();
	if(str == "n" || str == "No" || str == "no" || str == "N")
	{
		write("Input the message that possessor of this item will see for emote "+
		cur_emote + ".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
		"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
		"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of the "+
		"item possessor).\n"+
		"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of the item "+
		"possessor).\n");
		input_to("grab_personal_emote", str);	
		return 1;
	}
	if(str == "Y" || str == "yes" || str == "y" || str == "Yes")
	{
		emote = replace_string(emote, "$O", "\"+query_short()+\"");
		emote = replace_string(emote, "$N", "\"+ETOQCN+\"");
		emote = replace_string(emote, "$POSS", "\"+ETO->QP+\"");
		emote = replace_string(emote, "$SUB", "\"+ETO->QS+\"");
		TEMP_WRITE(TPQN, TEMP_CASE((cur_emote-1)));
		TEMP_WRITE(TPQN, TEMP_IP_EMOTE(emote));
		write("Input the message that the people in the room see for the emote "+cur_emote+
		".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
		"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
		"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of "+
		"the item possessor).\n"+
		"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of the "+
		"item possessor).\n");
		input_to("grab_room_emote", str);
		return 1;		
	}
	write(emote+"\nYou entered the above for what the item possessor sees for the emote "+
	cur_emote+".\n  Is this correct, yes or no?");
	input_to("check_personal_emote", str, emote);
	return 1;
}

void check_room_emote(string str, string emote)
{
	if(str == "**") return exit();
	if(str == "n" || str == "No" || str == "no" || str == "N")
	{	
		write("Input the message that the people in the room see for the emote "+cur_emote+
		".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
		"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
		"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of "+
		"the item possessor).\n"+
		"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of the "+
		"item possessor).\n");
		input_to("grab_room_emote", str);
		return 1;	
	}
	if(str == "y" || str == "Y" || str == "yes" || str == "Yes")
	{
		emote = replace_string(emote, "$O", "\"+query_short()+\"");
		emote = replace_string(emote, "$N", "\"+ETOQCN+\"");
		emote = replace_string(emote, "$POSS", "\"+ETO->QP+\"");
		emote = replace_string(emote, "$SUB", "\"+ETO->QS+\"");
		TEMP_WRITE(TPQN, TEMP_ROOM_EMOTE(emote));
		TEMP_WRITE(TPQN, TEMP_CASE_CLOSE);
		if(cur_emote != emotes)
		{
			cur_emote++;
			write("Input the message that possessor of this item will see for "+
			"emote "+cur_emote + 
			".\nUse %^YELLOW%^$O%^RESET%^ to display the short of the object."+
			"\nUse %^YELLOW%^$N%^RESET%^ to display the item possessor.\n"+
			"Use %^YELLOW%^$POSS%^RESET%^ to display his/her (the possessive of "+
			"the item possessor).\n"+
			"Use %^YELLOW%^$SUB%^RESET%^ to display he/she (the subjective of "+
			"the item possessor).\n");
			input_to("grab_personal_emote", str);	
			return 1;
		}
		else
		{
			TEMP_WRITE(TPQN, TEMP_SWITCH_CLOSE);
			TEMP_WRITE(TPQN, TEMP_HEADER_CLOSE);
			TEMP_WRITE(TPQN, TEMP_CLOSE);
			finish();
			return 1;
		}
	}
	write(emote+"\nYou entered the above for what the room sees for the emote "+
	cur_emote+".\n  Is this correct, yes or no?");
	input_to("check_room_emote", str, emote);
	return 1;
}

void finish(){
    object ob;
    if(type == "object") {
        WF(CLOSE);
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
    } else
    if( type == "armor"){
        ob = new("/cmds/avatar/armor2");
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);

        ob->move(TP);
    } else if(type == "weapon") {

        ob = new("/cmds/avatar/weapon2");
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);

        ob->move(TP);
    } else if(type == "pocketarmor") {

        ob = new("/cmds/avatar/pocketarmor2");
        ob->set_object_type(type);
        ob->set_file_name(FILE);
        ob->set_name(name);

        ob->move(TP);
    }

    remove();

}



