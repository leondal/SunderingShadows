//adapted from /cmds/avatar/item2.c for use with tattoos
//in new Seneca ~Circe~ 12/15/07
#include <std.h>
#include "tattoo.h"
#include <move.h>
#include <security.h>
#include <langs.h>


inherit OBJECT;

string FILE,name,mysize;

void finish();

int save_me(string file){ return 1;}

void exit() {
    rm(FILE);
    write("You opt not to have a tattoo applied, and your "+
       "money is returned.");
    TP->add_money("gold",20000);
    remove();
}

void set_file_name(string f) {
    FILE = f;
}

void set_name(string n) {
    name = n;
}

void init() {
    ::init();
    seteuid(UID_RESTORE);

    WF(HEADER);
    WF(MOREHEADER);
    WF(NAME(name));
    WF(MEDVALUE);
    write("%^RESET%^%^CYAN%^You will now begin the creation "+
       "of your tattoo.  You may use %^BOLD%^**%^RESET%^"+
       "%^CYAN%^ on a blank line at any time to quit.%^RESET%^");
    write("Please enter the identities of the object.");
    write("Use a comma between each identity < tattoo,dragon tattoo,purple dragon tattoo,small tattoo >");
    write("Please make sure 'tattoo' is one of the IDs.");
    input_to("pref");

}

void pref(string str) {
    string * ids;
    if(!str) {
        write("Please enter the identities of the object.");
        write("Use a comma between each identity < tattoo,dragon tattoo,purple dragon tattoo,small tattoo >");
        write("Please make sure 'tattoo' is one of the IDs.");
        input_to("pref");
        return 1;
    }
    if(str == "**") return exit();
    
    ids = explode(str,",");
    input_to("check_ids",ids);
    write("The ids for this tattoo as you have entered them "+
    "are "+identify(ids)+".  Is this correct, yes or no?");

    return 1;
}

void check_ids(string str, string *ids) {
    if(str == "**") {
        return exit();
    }
    if(str == "yes" || str == "y") {
        WF(ID(identify(ids)));
        write("Please input the short description for this tattoo.");
        write("The short description is the item as it appears "+
           "in your inventory list.  Use %^BOLD%^$T%^RESET%^ for the "+
           "size of the tattoo.  It %^BOLD%^%^RED%^must %^RESET%^be "+
           "included, or it will appear at the end.");
        input_to("short");
        return 1;
    }
    write("Please enter the identities of the object.");
    write("Use a comma between each identity < tattoo,dragon tattoo,purple dragon tattoo,small tattoo >");
    write("Please make sure 'tattoo' is one of the IDs.");
    input_to("pref");
    return 1;
}    

void short(string shrt) {
    if(!shrt) {
        write("Please input the short description for this tattoo.");
        write("The short description is the item as it appears "+
           "in your inventory list.  Use %^BOLD%^$T%^RESET%^ for the "+
           "size of the tattoo.  It %^BOLD%^%^RED%^must %^RESET%^be "+
           "included, or it will appear at the end.");
        if (strsrch(shrt,"$T") == -1) {
           shrt += " $T";
        }
        shrt = replace_string(shrt,"$T","medium");
        input_to("short");
        return 1;
    }

    if(shrt == "**") return exit();
    input_to("check_short",shrt);
    if (strsrch(shrt,"$T") == -1) {
       shrt += " $T";
    }
    shrt = replace_string(shrt,"$T","medium");
    write("The short description of this tattoo is \n"+shrt+"");
    write("Is this correct, yes or no?");
    return 1;
}

void check_short(string str, string shrt) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        shrt = replace_string(shrt,"$T","medium");
        WF(SHORT(shrt));
        write("Please input the long description for this tattoo.  This "+
           "will be the description you see when you <look tattoo>.\n");
        write("%^BOLD%^%^RED%^Please note: If your description runs "+
           "longer than 1000 characters (every things counts as a "+
           "character, even spaces, enters, and color codes), your "+
           "description will likely be cut off.%^RESET%^");
        write("%^BOLD%^Please keep in mind the size of the tattoo "+
           "you are buying as well when it comes to level of detail.%^RESET%^");
        write("To be safe, make sure you have no more than 15 "+
           "lines of this length:");
        write("%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
        write("%^YELLOW%^Use ** on a blank line to end the long description.%^RESET%^");
        input_to("long", "");
        return 1;
    }
    write("Okay, then please input the short description you would like for this tattoo.");
    write("The short description is the item as it appears "+
       "in your inventory list.  Use %^BOLD%^$T%^RESET%^ for the "+
       "size of the tattoo.  It %^BOLD%^%^RED%^must %^RESET%^be "+
       "included, or it will appear at the end.");
    if (strsrch(shrt,"$T") == -1) {
       shrt += " $T";
    }
    shrt = replace_string(shrt,"$T","medium");
    input_to("short");
    return 1;
}

void long(string str,  string longd) {
    if(!str) {
        write("Please input the long description for this tattoo.  This "+
           "will be the description you see when you <look tattoo>.\n");
        write("%^BOLD%^%^RED%^Please note: If your description runs "+
           "longer than 1000 characters (every things counts as a "+
           "character, even spaces, enters, and color codes), your "+
           "description will likely be cut off.%^RESET%^");
        write("%^BOLD%^Please keep in mind the size of the tattoo "+
           "you are buying as well when it comes to level of detail.%^RESET%^");
        write("To be safe, make sure you have no more than 15 "+
           "lines of this length:");
        write("%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
        write("%^YELLOW%^Use ** on a blank line to end the long description.%^RESET%^");
        input_to("long",longd);
        return 1;
    }
    if(str != "**") {
        longd += str + "\n";
        input_to("long",longd);
        return;
    }
    write("The description you have entered is:\n"+longd+"\nIs this the correct long description?  Yes "+
    "or no?");
    input_to("check_long",longd);
    return 1;
}

void check_long(string str, string longd) {
string *mylimbs;
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(LONG(longd));
        mylimbs = ETO->query_limbs();
        write("Please choose the part of your body where this tattoo "+
           "will be applied.");
        ETO->force_me("limbs");
        input_to("limbs");
        return 1;
    }
    write("Please input the long description for this tattoo.  This "+
       "will be the description you see when you <look tattoo>.\n");
    write("%^BOLD%^%^RED%^Please note: If your description runs "+
       "longer than 1000 characters (every things counts as a "+
       "character, even spaces, enters, and color codes), your "+
       "description will likely be cut off.%^RESET%^");
    write("%^BOLD%^Please keep in mind the size of the tattoo "+
       "you are buying as well when it comes to level of detail.%^RESET%^");
    write("To be safe, make sure you have no more than 15 "+
       "lines of this length:");
    write("%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
    write("%^YELLOW%^Use ** on a blank line to end the long description.%^RESET%^");
    input_to("long", "");
    return 1;
}

void limbs(string str){
string *mylimbs;
mylimbs = ETO->query_limbs();
   if(!str){
      write("Please choose the part of your body where this tattoo "+
         "will be applied.");
      ETO->force_me("limbs");
      input_to("limbs");
      return 1;
   }
   if(str == "**") return exit();
   if(member_array(str,mylimbs) == -1){
      write("That is not a valid limb!");
      write("Please choose the part of your body where this tattoo "+
         "will be applied.");
      input_to("limbs");
      return 1;
   }
   write("You have chosen for this tattoo to be applied on your "+
      ""+str+".  Is this correct? Yes or no.");
   input_to("check_limbs",str);
   return 1;
}

void check_limbs(string str, string limbs) {
string *mylimbs;
mylimbs = ETO->query_limbs();
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(LIMBS(limbs));
        write("Is this tattoo in a place where it will normally be hidden from sight? Yes or no?");
        input_to("hideme");
        return 1;
    }
    write("Please choose the part of your body where this tattoo "+
       "will be applied.");
    ETO->force_me("limbs");
    input_to("limbs");
    return 1;
}

void hideme(string str) {
    if(str == "**") return exit();
    if(str == "yes" || str == "y") {
        WF(MYWEAR);
        finish();
        return 1;
    }
    finish();
    return 1;
}

void finish(){
    object ob;
    string *myids;
    WF(CLOSE);
    WF(NODROP);
    WF(MED);
    WF(ISTATTOO);
    WF(WEARME);
    ob = new(FILE);
    if(ob->move(TP) != MOVE_OK) {
        ob->move(ETP);
        remove();
    }
    myids = ob->query_id();
    TP->force_me("wear "+myids[0]+"");
    write("%^BOLD%^Your tattoo is finally finished, the marks of the "+
       "needles leaving you in %^RED%^pain%^WHITE%^.%^RESET%^");
    tell_room(EETO,"The artist finishes work on "+ETOQCN+"'s tattoo.",ETO);
    remove();
}