//change by Circe 4/11/04 to allow avs to add ids
// adapted to allow hms to use for high level crafting nwps *Styx* 12/05

int do_nwps(object ob);
int do_quality(object ob, int percent);

#include <std.h>
#include <objects.h>

int cmd_alterobj(string str) {
    object ob, invisobj;
    int percent;
    //if(!high_mortalp(TP) && !avatarp(TP) && !OB_ACCOUNT->is_high_mortal((string)TP->query_true_name()))
     //   return notify_fail("Sorry, only hms and above are allowed.\n");
    if(!str)
        return notify_fail("alterobj what?\n");
    if(!ob = present(str, TP))
	return notify_fail("The "+str+" must be in your possession.\n");
    if(!objectp(ob) || living(ob))
	return notify_fail("ERROR somthing went wrong here...\n");
    if(ob->query_worn() || ob->query_wielded())
	return notify_fail("You can't work effectively with that worn or wielded.\n");
    if(!avatarp(TP)) {
        if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
	   TP->send_paralyzed_message("info",TP);
           return 1;
        }
	if (TP->query_hidden()) {
	   if(objectp(invisobj=present("TSR80",TP)))
	      invisobj->force_cancel();
	}
	if (TP->query_magic_hidden()) {
	    return notify_fail("You can't see to work while invisible!\n");
  	}
	if (TP->query_property("working")) {
	    return notify_fail("You are already "+(string)TP->query_property("working")+".\n");
	}
    }
    if(!avatarp(TP)) {
       if(ob->query_property("no alter")) return notify_fail("The magic in that item prevents you from altering it.\n");
       if(!ob->is_armor() && !ob->is_weapon() && !ob->is_instrument() && !ob->is_carving() && !ob->is_container())
	 return notify_fail("You can only alter weapons, armor, clothing, jewelry, containers, or instruments.\n");
       percent = do_nwps(ob);
       if(!percent) {
         TP->remove_property("working");
         return notify_fail("For some reason alterobj has not picked up an appropriate craft skill. Please notify an imm and tell them this message.\n");
       }
//       tell_room(ETP,"Pulling up percentage of "+percent+".");
       tell_room(ETP, TPQCN+" begins adding embellishments to "+ob->query_short()+".", TP);
       write("You begin adding embellishments to "+ob->query_short()+".");
    }
    write("Please enter the new short description to replace >>>> "+ob->query_short()+" "
	"%^RESET%^<<<< and then hit <enter>.  Entering '**' will abort the process.\n"
	"Please! do not change the essential nature of the item - refer to "
	"the help file for examples.");
    input_to("enter_short", ob, percent);
    return 1;
}

void error() {
    write("There's been an error... You need to start over.");
    TP->remove_property("working");
    return;
}

void enter_short(string str, object ob, int percent){
    int baseweight, adjweight, basevalue, adjvalue;
    string quality;
    if(!str || str == "") {
      write("Please enter the new short description for the "+ob->query_short()+" "
	 "%^RESET%^and then hit <enter>.  Entering '**' will abort the process.\n"
	 "Please! do not change the essential nature of the item - refer to "
	 "the help file for examples.");
      input_to("enter_short",ob);
      return;
    }
    if(str == "**") {
      write("Alteration process halted, no changes made.");
      TP->remove_property("working");
      return;
    }
    if(!objectp(ob)){
      error();
      return;
    }
    if(!avatarp(TP)) {
        quality = do_quality(ob, percent);
        basevalue = ob->query_value();
        adjvalue = basevalue * percent/100;
        if(adjvalue < basevalue)
            ob->set_value(adjvalue);
    }
    if(!quality)  quality = "";
    ob->set("alterby", TPQN);
    ob->set_short(str);
    write("Please enter the new LONG description for the item and then "
          "<enter>.  The current long is: "
          "\n"+ob->query_long()+"%^RESET%^\n");
    input_to("enter_long",ob, quality);
    return;
}

void enter_long(string str, object ob, string quality){
    if(!str || str == ""){
      write("Please enter the new LONG description for the item and then "
	"<enter>.  You must enter a new long description even if it is "
	"essentially the same as the old so the quality effect will show "
	"correctly.  The current long is: \n"+ob->query_long()+"%^RESET%^\n");
      input_to("enter_long",ob);
      return;
    }
    if(!objectp(ob)){
      error();
      return;
    }
    ob->set_long(str + quality);
    if(ob->query_possible_to_close())
    {
        write("You are altering a container that can open and close. "+
        "Please input the OPEN LONG description for it and then <enter>. Make "+
        "SURE to include some way of knowing that the item is open. Such as '"+
        "it is open'. The current "+
        "OPEN LONG description is: \n"+ob->query_open_long_desc()+"%^RESET%^\n");
        input_to("enter_open_long", ob, quality);
        return;
    }

    write("The obvious short is what is seen if the item is not identified.");
    if(ob->query_obvious_short()) {
        write("Please enter the new obvious short to replace the current one "
	  "of "+ob->query_obvious_short()+" and then <enter> or just <enter> "
	  "to leave it as is.");
        input_to("enter_obvious_short",ob);
        return;
    }
    write("You may enter an obvious short for this item or just <enter> to skip.");
    input_to("enter_obvious_short",ob);
    return;
}

void enter_open_long(string str, object ob, string quality)
{
    if(!str || str == "")
    {
        write("You are altering a container that can open and close. "+
        "Please input the OPEN LONG description for it and then <enter>. Make "+
        "SURE to include some way of knowing that the item is open. Such as '"+
        "it is open'. The current "+
        "OPEN LONG description is: \n"+ob->query_open_long_desc()+"%^RESET%^\n");
        input_to("enter_open_long", ob, quality);
        return;
    }
    if(!objectp(ob))
    {
        error();
        return;
    }
    ob->set_open_long(str + quality);
    write("You are altering a container that can open and close. Please input "+
    "the CLOSED LONG description for it and then <enter>. Make "+
    "SURE to include some way of knowing that it is closed. Such as '"+
    "it is closed'. The current CLOSED LONG description is: \n"+
    ob->query_closed_long_desc()+"%^RESET%^\n");
    input_to("enter_closed_long", ob, quality);
    return;
}

void enter_closed_long(string str, object ob, string quality)
{
    if(!str || str == "")
    {
        write("You are altering a container that can open and close. Please input "+
        "the CLOSED LONG description for it and then <enter>. Make "+
        "SURE to include some way of knowing that it is closed. Such as '"+
        "it is closed'. The current CLOSED LONG description is: \n"+
        ob->query_closed_long_desc()+"%^RESET%^\n");
        input_to("enter_closed_long", ob, quality);
        return;
    }
    if(!objectp(ob))
    {
        error();
        return;
    }

    ob->set_closed_long(str + quality);

    write("The obvious short is what is seen if the item is not identified.");
    if(ob->query_obvious_short()) {
        write("Please enter the new obvious short to replace the current one "
        "of "+ob->query_obvious_short()+" and then <enter> or just <enter> "
        "to leave it as is.");
        input_to("enter_obvious_short",ob);
        return;
    }
    write("You may enter an obvious short for this item or just <enter> to skip.");
    input_to("enter_obvious_short",ob);
    return;

}



void enter_obvious_short(string str, object ob) {
    if(!objectp(ob)) {
        error();
        return;
    }
    if(!str || str == "") {
        write("If needed, please enter an ID to be added and <enter> next.  "
	   "If the original ids are fine, just <enter>.\n  The current "
	   "IDs of "+identify(ob->query_id())+" will continue to work.  Do not "
	   "use color codes in an id and note that they are case sensitive.");
        input_to("enter_id",ob);
        return;
    }
    ob->set_obvious_short(str);
    write("If needed, please enter an ID to be added and <enter> next.  "
	   "If the original ids are fine, just <enter>.\n  The current "
	   "IDs of "+identify(ob->query_id())+" will continue to work.  Do not "
	   "use color codes in an id and note that they are case sensitive.");
    input_to("enter_id",ob);
    return;
}

void enter_id(string str, object ob){
    if(!str || str == ""){ // copied the finish stuff here, was leaving people stuck if they didn't change an id - Ares
      TP->remove_property("working");
      tell_room(ETP, TPQCN+" %^RESET%^finishes the work on "+ob->query_short()+".", TP);
      write("Your changes are complete.");
      return;
    }
    if(!objectp(ob)){
      error();
      return;
    }
    ob->add_id(str);
    write("Your changes to the "+ob->query_short()+" are complete.");
    TP->remove_property("working");
    tell_room(ETP, TPQCN+" %^RESET%^finishes the work on "+ob->query_short()+".", TP);
    return;
}

int do_nwps(object ob) {
/**********************************************
    int prof, percent, *altered, i;
    string type, msg;
    prof = 0;
    if(ob->is_weapon()) {
      prof = (int)TP->query_nwp("weaponsmithing");
      msg = "weaponsmith";
    }
    else {
      if (!ob->query_property("repairtype")) {
        if(ob->is_armor()) type = ob->query_type();
        switch(type) {
          case "clothing" :
	      prof = (int)TP->query_nwp("tailoring");
	      msg = "tailor";				   break;
          case "ring" :
            prof = (int)TP->query_nwp("jewelling");
            msg = "jewel";				   break;
          default:
	      prof = (int)TP->query_nwp("armorsmithing");
	      msg = "armorsmith";			   break;
        }
      }
      else {
        altered = ob->query_property("repairtype");
        if (member_array("tailor",altered) != -1)
          prof = (int)TP->query_nwp("tailoring");
        if ((member_array("jewel",altered) != -1) && (int)TP->query_nwp("jewelling") > prof)
	    prof = (int)TP->query_nwp("jewelling");
        if ((member_array("armorsmith",altered) != -1) && (int)TP->query_nwp("armorsmithing") > prof)
	    prof = (int)TP->query_nwp("armorsmithing");
        msg = altered[0];
        if(sizeof(altered) > 1) {
          for(i = 1;i>sizeof(altered);i++) msg = msg+" or "+altered[i];
        }
      }
    }
    if(!prof) {
	write("You need to be able to "+msg+", to be able to alter that.");
	return 0;
    }
    percent = roll_dice(prof+1, 5) + (prof*5);
    TP->set_property("working", msg);
    return percent;

// all of the above is the old code, which works to spit out a number from 0 (poor) to 200 (flawless).
// With this in mind, looking to use the new system to spit out 100 (average) on the specified DC.
// Every point beyond this will give an extra 10 (5% quality), to a maximum of 200 (perfect).
// Every point below this will give an extra -10, down to 0.
// This should effectively replicate the old system, and have the usual 20 points equal 100% total quality.
// Code below commences the new numbers system.
******************************************************/
    int myskill, percent, i, diff;
    string *oldtype, type;

    myskill = 0;
    if(sizeof(ob->query_property("repairtype"))) {
      oldtype = ({});
      oldtype += (string *)ob->query_property("repairtype");
      for(i = 0;i<sizeof(oldtype);i++) {
        switch(oldtype[i]) {
          case "armorsmith":
          if(myskill < TP->query_skill("craft, armorsmith")) {
            myskill = TP->query_skill("craft, armorsmith");
            type = "armorsmith";
          }
          break;
          case "jewel":
          if(myskill < TP->query_skill("craft, jeweller")) {
            myskill = TP->query_skill("craft, jeweller");
            type = "jewel";
          }
          break;
          case "tailor":
          if(myskill < TP->query_skill("craft, tailor")) {
            myskill = TP->query_skill("craft, tailor");
            type = "tailor";
          }
          break;
          case "weaponsmith":
          if(myskill < TP->query_skill("craft, weaponsmith")) {
            myskill = TP->query_skill("craft, weaponsmith");
            type = "weaponsmith";
          }
          break;
          case "woodwork":
          if(myskill < TP->query_skill("craft, woodworker")) {
            myskill = TP->query_skill("craft, woodworker");
            type = "woodwork";
          }
          break;
          case "leatherwork":
          if(myskill < TP->query_skill("craft, leatherworker")) {
            myskill = TP->query_skill("craft, leatherworker");
            type = "leatherwork";
          }
          break;
        }
      }
    }
// if it doesn't have an array, just grab the appropriate skill
    else {
      if(ob->is_instrument()) {
        myskill = TP->query_skill("craft, woodworker");
        type = "woodwork";
      }
      if(ob->is_weapon()) { //weaponsmith or woodwork, figure a split
        myskill = TP->query_skill("craft, weaponsmith");
        type = "weaponsmith";
      }
      if(ob->is_container()) { //defaulting to tailoring
        myskill = TP->query_skill("craft, tailor");
        type = "tailor";
      }
      if(ob->is_armor()) {
        switch(ob->query_type()) {
          case "ring": case "jewelry":
          myskill = TP->query_skill("craft, jeweller");
          type = "jewel";
          break;
          case "clothing":
          myskill = TP->query_skill("craft, tailor");
          type = "tailor";
          break;
          case "leather": case "thiefshield":
          myskill = TP->query_skill("craft, leatherworker");
          type = "leatherwork";
          break;
          case "chain": case "armor": case "armour": case "shield":
          myskill = TP->query_skill("craft, armorsmith");
          type = "armorsmith";
          break;
          default:
          tell_object(TP,"You have an invalid-type wearable, please contact a wiz with this message.");
          return 1;
          break;
        }
      }
    }
    myskill += roll_dice(1,20);
    diff = (int)ob->query_property("enchantment")*3;
    if(diff < 0) diff = diff*(-1);
    diff += 10;
    percent = (myskill - diff)*10; // to convert to current 0-200 system below
    if(percent > 100) percent = 100;
    if(percent < -100) percent = -100;
    percent += 100; // setting the centrepoint of the DC at "average" quality.

    TP->set_property("working", type);
    return percent;
}

int do_quality(object ob, int percent) {
   string quality;
   switch(percent) {
      case 0..49:       quality = "\nVery poor quality";
        break;
      case 50..75:      quality =  "\nLow quality";
        break;
      case 76..90:      quality =  "\nBelow average quality";
        break;
      case 91..109:     quality =  "\nAverage quality";
        break;
      case 110..124:    quality =  "\nAbove average quality";
        break;
      case 125..151:    quality =  "\nHigh quality";
        break;
      default:          quality =  "\nMastercrafted";
        break;
    }
    return quality;
}

void help(){

    write( "
%^CYAN%^NAME%^RESET%^

alterobj - change long and short description of an item

%^CYAN%^SYNOPSIS%^RESET%^

alterobj %^ORANGE%^%^ULINE%^ITEM%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to change the long and short descriptions of an item if you are skilled enough in the appropriate crafting skill.

This is considered an %^CYAN%^in character action%^RESET%^ and it is highly inadvisable to change item material and describe item you won't normally see in that limb slot. For example:
 %^RED%^*%^RESET%^ Making wooden crown golden is illegal.
 %^RED%^*%^RESET%^ Altering pants to be hat isn't legal, as such a hat would be worn in legs slots.
 %^GREEN%^*%^RESET%^ Making glasses from a circlet, skirt from breeches, handbands from gloves considered to be legal.

Be wary about what you change. Some items have their descriptions edged in their special abilities, so these should be changed with special care.

%^CYAN%^SEE ALSO%^RESET%^
discern, skills, craft, repair");
}
