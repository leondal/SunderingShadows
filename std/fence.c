//fence

/*  added disabled checks to preclude actions if bound, unconscious, paralyzed, gagged, etc.
    allowed strings are "bound", "blind", "disabled" (for unconscious or paralyzed)
Did it as a function to pass arguments to toward a goal of having a global daemon for all add_actions and a default of nothing being set disallowing them all.

Also made it force step for thief hidden because they would have given away their location by getting the vendor's attention.  That also solves the problem of the response from TPQCN calling them "Someone" and giving away that they are hidden.

*Styx*  1/4/03
*/
// 5/25/03 Fixed so they won't deal with non-thief/bard types  *Styx*


#include <std.h>

#define STORE "/std/obj/fence_store.c"
#define LF(X) log_file("player/fencing",X)

#define FENCE_D "/daemon/fence_d"

inherit "/std/vendor.c";


void create() {
    ::create();
    set_is_fence(1);
// The following line exempts the retired players directory from the auto-create room function, since that directory gets fed into the wholist wholesale.
// garrett, Feb 21, 2008.
      if (base_name(TO)[0..9] == "/d/retired" ) return;
    if(base_name(TO) != "/std/fence") {
        if(!file_exists(base_name(TO)+"_storage.c")) {
            cp(STORE, base_name(TO)+"_storage.c");
        }
        set_storage_room(base_name(TO)+"_storage.c");
    }
}

void init() {
    ::init();

    remove_action("__Sell", "sell");
    add_action("__Fence","fence");
    add_action("__Launder","launder");
    add_action("__Account","account");
}

int __Sell(string str){
    return 0;
}

int adjust_cost(object ob) {
    int ench, cost;

    if(!objectp(ob)) { return 0; }
    cost = (int)ob->query_value();

    ench = ob->query_property("enchantment");

    if(ench < 0) {
        ench = ench*(-1);
    }

    ench /= 2;

    if(!ench) { ench = 1; } //changed to make enchantment 1 if it's
                            //less
    cost *= ench;
// bumping thieves guilds to amplify cost of credit items from selling price. As most items fall extremely short of a real value when bought from the fence. N, 10/15.
    cost *= 3;

    return ::adjust_cost(cost);   // uses the /std/npc function for charisma factor
}

int __Buy(string str) {
    object ob;
    string tmp;
    int cost, x;
    string cointype;
    string *not_allowed;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be trying to make a deal with "+TOQCN+".", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^:  I'm sorry, but I don't deal with your kind and think you should leave now.");
       return 1;
    }

    if(!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }

    if(!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    if(!(ob = present(str, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I don't have any "+str+"s to sell you!");
        return 1;
    }
    /*I'm going to override the adjust cost function
    here so we can use it instead of another one to
    get the modified fence price using the
    formula that the fence uses - cause we need
    to get the same price in a few different places
    IE - Show/List - Saide*/

    cost = adjust_cost(ob);

    if(!TP->query("thief account") || (int)TP->query("thief account") < cost) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^You don't have enough money in your thief account!");
        write("You need "+cost+".");
        return 1;
    }

    if(ob->is_plate()) {
        ob->check_plate(TP,ob);
        write("The armor is fitted to your body size and shape.");
    }
    write("Here is your "+str+" for "+cost+" credits!");
    message("other_action", query_cap_name()+" hands "+TPQCN+" "+(string)ob->query_short()+".", ETO, ({ TP,TO}));
    message("other_action", query_cap_name()+" hands you "+(string)ob->query_short()+".", TP);
    TP->set("thief account",(int)TP->query("thief account") - cost);
   if(FENCE_D->fence_item(ob)) log_file("player/fencing",ob->query_short()+" was fenced to "+TPQN+" for "+cost+" on "+ctime(time())+"\n"); // let's only log non-generic daemon stuff
    if(ob->move(TP)) {
        message("my_action", "You drop it as fast as you get it!", TP);
        message("other_action", TPQCN+" drops "+(string)ob->query_short()+".", ETO,({ TP}));
        ob->move(ETO);
    }
    return 1;
}

int __Value(string str) {
    object ob;
    string tmp, cn;
    int value1;
    string *not_allowed;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" asks "+TOQCN+" for an appraisal on an item.", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^: I'm sorry, but I don't make a habit of appraising items.  Maybe you should try a local vendor for that.");
       if(!random(4))
          tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^:  Maybe I'll see if someone will aquire that for me though.");
       return 1;
    }

    if(!str) {
        write("Try 'value <object>'.");
        return 1;
    }

    if(!(ob = present(str, TP))) {
        write("You don't have a "+str+"!");
        return 1;
    }
    message("other_action", TPQCN+" asks for an appraisal.", ETO, ({TO,TP}));
    value1 = FENCE_D->value(TO,TP,ob);
    if(!value1) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^That "+str+" is worthless!");
        return 1;
    }
    //value = value - (value/5);
    tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I would estimate the value of that at "+value1+" credits."); //changed to use the fence credit system - Saide "+ob->query_cointype()+".");
    return 1;
}

int __Launder(string str){
    int amount;
    string *not_allowed;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be trying to make a deal with "+TOQCN+".", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^: I'm sorry, but I think you're confused and should leave before I take offense.");
       return 1;
    }

    if(!str) {
        force_me("say You currently can launder "+TP->query("stolen money")+" gold,");
        return 1;
    }

    if(sscanf(str, "%d gold", amount) != 1) {
        return notify_fail("launder <amount> gold.\n");
    }

    FENCE_D->launder(TO,TP,amount);
    return 1;
}

int __Fence(string str){
//    string sobj;    doesn't seem to be used
    object ob;
    object *obs;
    string *not_allowed;
    int x;
    mapping stolen;

    if(!str) {
        return notify_fail("fence <item>\n");
    }
    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be trying to make a deal with "+TOQCN+".", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^: I don't think I should be dealing with you.  In fact, you being here is probably bad for business, so please leave.");
       if(!random(4))
          tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^:  Maybe I'll see if one of them will aquire that for me though.");
       return 1;
    }

    ob = present(str, TP);
    if(!objectp(ob)) {
        force_me("say You don't have a "+str+".");
        return 1;
    }
    if(ob->query_property("no_profit") || ob->query_property("plot_item") || ob->query_property("soulbound")) {
      force_me("say I don't want that "+ob->query_name()+".");
      return 1;
    }
    if(ob->is_container()) {

        obs = deep_inventory(ob);
        for(x = 0;x < sizeof(obs);x++) {
            stolen = (mapping)obs[x]->query_property("stolen");
            if(!stolen || !stolen[TP->query_name()]) {
                force_me("emote looks through the "+ob->query_name()+
                " and shakes "+ob->QP+" head.");
                force_me("say you didn't steal something in there, "
                "I don't want it.");
                return 1;
            }
        }
    }

    FENCE_D->fence(TO,ob,TP);
    return 1;
}

int __Account(string str) {
    string *not_allowed;

    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be trying to ask "+TOQCN+" about something.", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^:  I'm sorry, but I don't think you and I have any business to discuss and you should probably just leave.");
       return 1;
    }

    if(!TP->query("thief account")) {
        force_me("say Get out of here you slacker, you have done no business for the guild.");
        return 1;
    }
    force_me("whisper "+TP->query_name()+" You've brought in business, you've "+TP->query("thief account")+" credit.");
    return 1;
}

int __Help(string str) {
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP))
       return 0;
    if(!str) {
        TP->force_me("help fencing");
        return 1;
    }
    return 0;
}

int inventory() {
    return 0;
}

int __List(string str) {
   object *inv;
   string *tmp;
   int i, x;
   string *not_allowed;
   not_allowed = ({ "bound", "disabled" });
   if(disabled(TP, not_allowed))
	return 1;
    if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be asking "+TOQCN+" about something.", TP);
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says%^RESET%^:  Do I look like a common vendor or something?  I don't think your kind is exactly welcome here either, so please leave.");
       return 1;
    }

   while(!__Eco["storage object"]) {
      __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
   }
   i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]), "filter_list", TO, str));
   if(!i) {
//__Eco["storage object"]->reset();
      i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]),"filter_list", TO, str));
      if(!i) {
         write("I have nothing like that to sell.");
         return 1;
      }
   }
   inv = sort_array(inv,"sort_items",TO);
   write("%^YELLOW%^ Description			  Cost			 Type");
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
   for(x=0, tmp = ({}); x<i; x++) {
      if(inv[x]->is_armour() || inv[x]->is_weapon()) {
         tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%-20s %-5s",
                         inv[x]->query_short(),adjust_cost(to_object(inv[x])),"credit", types(inv[x]))});
      } else {
         tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%s",
                         inv[x]->query_short(),adjust_cost(to_object(inv[x])),"credit")});
      }
      if(( ( x%17 ) == 0 ) && ( x > 15 ) ) {
         tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
         if(x == 17) tmp += ({" "});
         tmp += ({"%^YELLOW%^ Description			  Cost			 Type"});
         tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
      }
   }
   tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
   TP->more(tmp);
   return 1;
}

int __Repair(string str) { //overriding this as it's bugging. No need for it anyway. N, 8/12.
    force_me("say Do I look like a craftsman? Take that to someone that knows what to do with it.");
    return 1;
}

int __Resize(string str) { //overriding this as it's unnecessary here as well. N, 8/12.
    force_me("say Do I look like a craftsman? Take that to someone that knows what to do with it.");
    return 1;
}
