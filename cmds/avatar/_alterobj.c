//change by Circe 4/11/04 to allow avs to add ids
#include <std.h>

int cmd_alterobj(string str){
    object ob;

    if(!str) return notify_fail("alterobj what?\n");
    if(!ob = present(str, TP)) return notify_fail("The "+str+" must be in your possession.\n");
    if(!objectp(ob) || living(ob)) return notify_fail("ERROR somthing went wrong here...\n");
    
    write("Please enter the new short description for the item.");
    input_to("enter_short", ob);
    return 1;
}

void error() {
    write("There's been an error... You need to start over.");
    return;
}

void enter_short(string str, object ob){
    if(!str || str == ""){
      write("Please enter the SHORT description for the item.");
      input_to("enter_short",ob);
    }
    if(!objectp(ob)){
      error();
      return;
    }
    ob->set("alterby", TPQN);
    ob->set_short(str);
    if(ob->query_obvious_short()) {
        write("Please enter the new obvious short for the item.");
        input_to("enter_obvious_short",ob);
        return;
    }
    write("You may enter an obvious short for this item.");
    input_to("enter_obvious_short",ob);
    return;
}

void enter_obvious_short(string str, object ob) {
    if(!objectp(ob)) {
        error();
        return;
    }
    if(!str || str == "") {
        write("Obvious short not modified.");
        write("Please enter the new long description.");
        input_to("enter_long",ob);
        return;
    }
    ob->set_obvious_short(str);
    write("Please enter the new long description.");
    input_to("enter_long",ob);
    return;
}

void enter_long(string str, object ob){
    if(!str || str == ""){
      write("Please enter the LONG description for the item.");
      input_to("enter_long",ob);
    }
    if(!objectp(ob)){
      error();
      return;
    }
    ob->set_long(str);
    write("Please enter a new ID, if needed, for this item.  "+
       "Note that players will have to type it exactly as you enter it.");
    input_to("enter_id",ob);
    return;
}

void enter_id(string str, object ob){
    if(!str || str == ""){
      write("Please enter the LORE description for the item.  "
         "Leave blank if there is no lore to add.");
      input_to("enter_lore",ob);
    }
    if(!objectp(ob)){
      error();
      return;
    }
    ob->add_id(str);
    write("Please enter the LORE description for the item.  "
       "Leave blank if there is no lore to add.");
    input_to("enter_lore",ob);
    return;
}

void enter_lore(string str, object ob){
    if(!str || str == ""){
      write("Finished.");
      return;
    }
    if(!objectp(ob)){
      error();
      return;
    }
    if(ob->query("lore")) ob->delete("lore");
    ob->set_lore(str);
    write("Please enter the LORE skill for the item.  "
      "This should be a number from 1 to 20 in difficulty.");
    input_to("enter_loreskill",ob);
    return;
}

void enter_loreskill(int myval, object ob){
    if(!myval || myval == ""){
      write("Please enter the LORE skill for the item.  "
        "This should be a number from 1 to 20 in difficulty.");
      input_to("enter_loreskill",ob);
      return;
    }
    if(!objectp(ob)){
      error();
      return;
    }
    if(ob->query_property("lore difficulty")) ob->remove_property("lore difficulty");
    ob->set_property("lore difficulty",myval);
    write("Finished.");
    return;
}

int help(){
    write(
      "This command will allow you to change the long and short/identified
descriptions of any item, as well as adding an ID and lore, but ONLY 
those attributes...  how it acts, its specials...  EVERYTHING else will 
remain EXACTLY the same.  Now, you can also add an id to the object (so 
if you change 'a silk cloak' to 'a satin cape', you can add 'cape' as an 
ID so they may look at it).  It is a cosmetic change ONLY."
    );
   write("See also: weapon, armor, item");
    return 1;
}
