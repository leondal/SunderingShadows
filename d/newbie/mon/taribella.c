//Taribella - gnome scroll vendor for Offestry
//Circe 6/6/07 - meant to relieve the pain for low-level mages ;)

#include <std.h>
#include <money.h>
#include <daemons.h>
#include <move.h>

inherit VENDOR;

void create(){
   ::create();
  set_name("taribella");
  set_short("Taribella, collector of scrolls");
  set_id(({"taribella","Taribella","gnome","scroll collector","vendor","shopkeeper","shop keeper"}));
  set_property("no attack",1);
  set_property("no bump", 1);
  set_property("strength","spells");
  set("aggressive", 0);
  set_level(16);
  set_long(
     "%^RESET%^%^CYAN%^Teribella is a young gnome with %^ORANGE%^"+
     "deep brown skin %^CYAN%^and inquisitive %^BOLD%^azure eyes"+
     "%^RESET%^%^CYAN%^.  She has %^BOLD%^%^RED%^vibrant red "+
     "hair%^RESET%^%^CYAN%^, unusual for a gnome until you "+
     "notice that it seems to have been dyed that way...or "+
     "perhaps is the result of some magical accident.  She has "+
     "a %^RESET%^feathered quill %^CYAN%^stuck behind one ear, "+
     "and several others peek out from the pocket of her "+
     "apron.  She is an avid collector of scrolls, and she "+
     "never seems to be without one or two of them.%^RESET%^\n\n"+
     "<help shop> will get you a list of shop commands."
  );
  set_gender("female");
  set_alignment(2);
  set_race("gnome");
  set_class("mage");
  set_hd(16,1);
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",8);
  set_stats("charisma",13);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_guild_level("mage",16);
  set_mlevel("mage",16);
  set_overall_ac(0);
  set_storage_room("/d/newbie/rooms/special/scroll_shop");
}

int __Sell_here(string str){
   object ob;
   
   if(!str) return 0;
   if(!ob = present(str,TP)) return notify_fail("You don't have that item.\n");
   if(!ob->is_newbie_scroll()) return notify_fail("I only buy my scrolls.\n");
   TP->add_money("gold",20);
   ob->remove();
   write(query_cap_name()+" takes the scroll and hands you some money.");
   tell_room(ETO,query_cap_name()+" takes a scroll from "+TPQCN+" and hands
"+TP->query_objective()+" some money.",TP);
   return 1;
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return __Sell_here(str);
    else {
      force_me("say Go talk to Zabeth upstairs, I don't buy scrolls.");
      return 1;
    }
}

int __Buy_here(string str) {
    object ob;
    string tmp;
    int cost, x;
    string cointype, *not_allowed, response;

    if (!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }
    not_allowed = ({ "bound", "disabled", "unconscious" });
    if(disabled(TP, not_allowed)) return 1;
    if(disabled(TO, not_allowed)){
      write("Do you really expect someone who cannot move to sell you something?");  
	return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    if (!TP->is_player() && member_array(TP->query_race(),RACE_D->query_races())== -1) {
        force_me("say We don't serve your kind around here.");
        return 1;
    }
    if (!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    if (!(ob = present(str, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
	tell_room(ETO, TPQCN+" asks the shopkeeper about an item.", TP);
        tell_room(ETO, response+"I don't have any "+str+"s to sell you!");
        return 1;
    }
     cost = (int)ob->query_value();

    if (ob->query_property("enchanted"))
        cost = cost * query_property("enchantment");
    cost = adjust_cost(cost);
    cointype = (string)ob->query_cointype();
    if ((int)this_player()->query_money(cointype) < cost) {
        convert_money(cointype,cost);
        if ((int)this_player()->query_money(cointype) < cost) {
            tell_room(ETO, response+TPQCN+", you don't have enough money for that!", TP);
	    tell_object(TP, response+"You don't have enough money.");
            tell_room(ETO, response+"You need "+cost+" "+ob->query_cointype()+".");
            return 1;
        }
    }
    tell_room(ETO, response+"Here is your "+str+" for "+cost+" "+ob->query_cointype()+"!");
    tell_room(ETO, TOQCN+" hands "+TPQCN+" "+(string)ob->query_short()+".", TP);
    tell_object(TP, TOQCN+" hands you "+(string)ob->query_short()+".");
    TP->add_money(ob->query_cointype(), -cost);
    if (ob->move(TP)) {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(ETO, TPQCN+" drops "+(string)ob->query_short()+".", TP);
        ob->move(ETO);
    }
    return 1;
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return __Buy_here(str);
    else {
      force_me("say You? I couldn't let you have one");
      return 1;
    }
}

