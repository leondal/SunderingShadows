// Yves - 7/2/19

#include <std.h>
inherit DAEMON;

int confirm_remove(string str, object ob, string bonus, string *bonus_names) {
  if(!objectp(ob)) return 0;
  if(!stringp(bonus)) return 0;
  if(!arrayp(bonus_names)) return 0;

  if(str != "yes"){
    tell_object(TP,"Aborting...");
    return 1;
  }

  if(bonus == "all"){
    for(int i = 0;i < sizeof(bonus_names);i++){
      string bonus_name = bonus_names[i];
      if(bonus_name == "special") {
        if(ob->query_property("hit")) ob->remove_property("hit");
        if(ob->query_property("struck")) ob->remove_property("struck");
      }
      else ob->set_item_bonus(bonus_name, 0);
    }
    if(ob->query_property("invalidate time")) ob->remove_property("invalidate time");
    tell_object(TP,"All item bonuses have been removed from your item.\n");
    return 1;
  }

  if(bonus == "special") {
    if(ob->query_property("hit")) ob->remove_property("hit");
    if(ob->query_property("struck")) ob->remove_property("struck");
  }
  else ob->set_item_bonus(bonus, 0);
  if(ob->query_property("invalidate time")) ob->remove_property("invalidate time");
  tell_object(TP,capitalize(bonus)+" has been removed from your item.\n");
  return 1;
}


string *get_bonus_names(object ob) {
  mapping bonuses;
  if(!objectp(ob)) return;

  bonuses = copy(ob->query_item_bonuses());
  if(ob->query_property("hit") || ob->query_property("struck")) {
    bonuses += ([ "special" : 0 ]);
  }
  return keys(bonuses);
}

int print_item_bonuses(object ob) {
  string *bonus_names;

  if(!objectp(ob)) {
    tell_object(TP,"That is not an item!\n");
    return 1;
  }

  bonus_names = get_bonus_names(ob);
  if(sizeof(bonus_names) < 3) {
    tell_object(TP,"That is not a valid item to fix!\n");
    return 1;
  }

  tell_object(TP, "That item has the following valid bonuses: "+implode(bonus_names, ", "));
  return 1;
}

int remove_item_bonus(object ob, string bonus) {
  string *bonus_names;

  if(!objectp(ob)) {
    tell_object(TP,"That is not an item!\n");
    return 1;
  }

  if(!stringp(bonus) || !sizeof(bonus)) {
    tell_object(TP,"You must specify a bonus!\n");
    return 1;
  }

  bonus_names = get_bonus_names(ob);
  if(sizeof(bonus_names) < 3) {
    tell_object(TP,"That is not a valid item to fix!\n");
    return 1;
  }

  if(!~member_array(bonus,bonus_names) && bonus != "all") {
    tell_object(TP,"That item doesn't have that bonus!\n");
    return 1;
  }

  tell_object(TP,"Enter <yes> to confirm removal of %^BOLD%^%^RED%^"+bonus+"%^RESET%^, anything else to abort.\n");
  return input_to("confirm_remove", ob, bonus, bonus_names);
}

int cmd_fixitem(string str) {
  string item, bonus;
  object ob;

  if(!stringp(str) || !strlen(str)) {
    tell_object(TP, "See <help fixitem> for syntax.\n");
    return 1;
  }

  if(regexp(str,".* with .*"))
      sscanf(str,"%s with %s",item,bonus);
  else
      item=str;

  ob = present(item, ETP);
  if(!objectp(ob)) ob = present(item,TP);
  if(!objectp(ob)) {
    tell_object(TP,"That is not an item!\n");
    return 1;
  }

  if(!ob->query_property("player enchanted")) {
    tell_object(TP,"That is not a valid item to fix!\n");
    return 1;
  }

  //one arguments - print out item bonuses
  if(!bonus) return print_item_bonuses(ob);

  //two or more arguments - remove bonus
  return remove_item_bonus(ob, bonus);
}

void help() {
  write("
%^CYAN%^NAME%^RESET%^

fixitem - remove extra bonuses from crafted legacy items

%^CYAN%^SYNOPSIS%^RESET%^

fixitem %^ORANGE%^%^ULINE%^ITEM%^RESET%^
fixitem %^ORANGE%^%^ULINE%^ITEM%^RESET%^ with %^ORANGE%^%^ULINE%^BONUS%^RESET%^|all

%^CYAN%^DESCRIPTION%^RESET%^

This command is used to remove an item bonus from legacy player crafted items. It cannot be used on monster dropped items or on player crafted items that are already within the item bonus limits.

If no bonus is specified it will list the bonuses available for removal.

If 'all' is specififed as the bonus it will remove all item bonuses. This is to allow redistribution of item bonuses and there will be no mats refunded so use at your own peril.

%^CYAN%^SEE ALSO%^RESET%^

craft, craft magical equipment
  ");
}
