#include <daemons.h>
#include "token_hunt.h"

inherit "/std/vendor.c";

#define INV INV_PATH"token_inventory"

mapping INVENTORY;
nosave string STORE_TYPE;
nosave object INV_OB;
void fill_storage_room();
void set_store_type(string type);
string query_store_type();
mapping raw_map();
string *query_items(string type);
// add_new_item("high","/path/file","1 gold")
int add_new_item(string type,string item,string cost);
string query_item_price(string type,object item);
int __Sell(string str);
int __Buy(string str);
int __Show(string str);
int __List(string str);
int __Value(string str);
int remove_me(string str);
int remove_item(string type,string item);


void create()
{
    if(!objectp(INV_OB=find_object(INV)))
    {
        INV_OB = find_object_or_load(INV);
    }

    INVENTORY = INV_OB->get_inventory();
    ::create();
    fill_storage_room();
}

int add_me(string str)
{
    string *info=({});
    object ob;

    if(!stringp(str)) { return 0; }
    if(!objectp(TP)) { return 0; }
    if(!avatarp(TP)) { return 0; }

    info = explode(str," ");
    if(sizeof(info) != 3) { return 0; }

    if(!objectp(ob=present(info[0],TP)))
    {
        tell_object(TP,"No "+info[0]+" in your inventory\n"
            "\tsyntax: add <item> 1 gold");
        return 1;
    }
    if(info[2] != "gold" && info[2] != "silver" && info[2] != "copper" && info[2] != "platinum")
    {
        tell_object(TP,"\tsyntax: add <item> 1 gold");
        return 1;
    }
    add_new_item(query_store_type(),base_name(ob),""+info[1]+" "+info[2]+"");
    tell_object(TP,""+ob->query_short()+" add to "+query_store_type()+" level stores for "+info[1]+" "
        ""+info[2]+" tokens.");
    return 1;
}

int remove_me(string str)
{
    string *info=({});
    object ob;

    if(!stringp(str)) { return 0; }
    if(!objectp(TP)) { return 0; }
    if(!avatarp(TP)) { return 0; }

    if(!objectp(ob=present(str,TP)))
    {
        tell_object(TP,"No "+str+" in your inventory\n"
            "\tsyntax: remove <item>");
        return 1;
    }

    remove_item(query_store_type(),base_name(ob));
    tell_object(TP,""+ob->query_short()+" removed from "+query_store_type()+" level stores.");
    return 1;
}

int do_immortal_display()
{
    if(!objectp(TP)) { return 1; }
    if(!avatarp(TP)) { return 1; }
    tell_object(TP,"%^YELLOW%^This is a special store that you can add items to, simply "
        "add <item> 1 gold  to add the item to the store.  The item must be in your "
        "inventory.  You can use this method to adjust the price of items that are "
        "already in the store.  Any item that you add to the store will be there permenantly.");
    tell_object(TP,"%^YELLOW%^You may also remove <item> to remove an item from the "
        "store's inventory.  You must have an item of the type you want to remove in "
        "your inventory.  When you remove the item it will be permenantly deleted "
        "from the token vendors unless someone adds it again.");
    return 1;
}

void init()
{
    ::init();
    add_action("add_me","add");
    add_action("remove_me","remove");
    do_immortal_display();
    return;
}

void fill_storage_room()
{
    object ob,*obs=({});
    string *files=({}),*tmp=({});
    int i;

    if(!__Eco["storage file"]) { return; }
    if(!__Eco["storage object"])
    {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    if(!objectp(__Eco["storage object"])) { return; }

    files = query_items(query_store_type());
    if(!sizeof(files)) { return; }
    obs = all_inventory(__Eco["storage object"]);
    if(sizeof(obs))
    {
        for(i=0;i<sizeof(obs);i++)
        {
            if(!objectp(obs[i])) { continue; }
            tmp += ({ base_name(obs[i]) });
        }
    }
    for(i=0;i<sizeof(files);i++)
    {
        if(member_array(files[i],tmp) != -1) { continue; }
        ob = new(files[i]);
        if(objectp(ob)) ob->move(__Eco["storage object"]);
        if(!objectp(ob))
        {
            log_file("token_vendors", "file "+files[i]+" failed to load at "+query_store_type()+"\n");
            continue;
        }
        continue;
    }
    return;
}

void set_store_type(string type)
{
    if(!stringp(type)) { STORE_TYPE = "high"; }
    STORE_TYPE = type;
    return;
}

string query_store_type()
{
    if(!STORE_TYPE) { STORE_TYPE = "high"; }
    return STORE_TYPE;
}

mapping raw_map() { return INVENTORY; }

string *query_items(string type)
{
    if(!sizeof(keys(INVENTORY))) { return ({}); }
    if(!sizeof(keys(INVENTORY[type]))) { return ({}); }
    return keys(INVENTORY[type]);
}

// add_new_item("high","/path/file","1 gold")
int add_new_item(string type,string item,string cost)
{
    string *tmp=({}),token;
    int price;
    if(!stringp(item)) { return 0; }
    item = replace_string(item,".c","");
    if(!file_exists(item+".c")) { return 0; }
    if(!stringp(cost)) { return 0; }
    tmp = explode(cost," ");
    if(sizeof(tmp != 2)) { return 0; }
    price = to_int(tmp[0]);
    token = tmp[1];
    if(member_array(token,({"copper","silver","gold","platinum"})) == -1) { return 0; }
    INVENTORY[type] += ([ item :([ "token" : token,"cost" : price ]), ]);
    fill_storage_room();
    INV_OB->set_inventory(INVENTORY);
    INV_OB->save_inventory();
    return 1;
}

// add_new_item("high","/path/file")
int remove_item(string type,string item)
{
    mapping new_inven;
    if(!stringp(item)) { return 0; }
    item = replace_string(item,".c","");
    if(!file_exists(item+".c")) { return 0; }
    map_delete(INVENTORY[type],item);
    fill_storage_room();
    INV_OB->set_inventory(INVENTORY);
    INV_OB->save_inventory();
    return 1;
}

string query_item_price(string type,object item)
{
    mapping tmp=([]),tmp2=([]);
    string token;
    int cost;
    if(!stringp(type)) { return "no type"; }
    if(!objectp(item)) { return "no item"; }
    tmp = INVENTORY[type];
    if(!mapp(tmp)) { return "no type"; }
    tmp2 = tmp[base_name(item)];
    if(!mapp(tmp2)) { return "no item"; }
    token = tmp2["token"];
    cost = tmp2["cost"];
    return ""+cost+" "+token+"";
}

int __Sell(string str)
{
    string response,gender,word;

    gender = TO->query_gender();
    switch(gender)
    {
    case "male":    word = "his";   break;
    case "female":  word = "hers";  break;
    default:        word = "its";   break;
    }

    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";

    tell_room(ETO,""+TOQCN+" shakes "+word+" head.");
    tell_room(ETO,response+" we don't buy things here, only sell.");
    return 1;
}

int __Buy(string str)
{
    object ob,box;
    string price,*tmp=({});
    int cost,x,lvl,enc;
    string cointype, *not_allowed, response;

    if (!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }
    not_allowed = ({ "bound", "disabled", "unconscious" });
    if(disabled(TP, not_allowed))
       return 1;
    if(disabled(TO, not_allowed)){
      write("Do you really expect someone who cannot move to sell you something?");
       return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
// removing the negative reaction to mycaused players; unnecessary.
/*    if (!should_interact(TP)) {
        force_me("glare "+TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }*/
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

    if(ob->query_property("levelrestrict")){
       lvl = ob->query_property("levelrestrict");
       if((int)TP->query_lowest_level() < lvl){
          tell_object(ETO,response+"I'm sorry.  You are not "+
             "experienced enough to buy that yet.");
          return 1;
       }
    }

    if(!objectp(box=present("token_obj9999",TP)))
    {
        tell_room(ETO,response+"You need a token box first.");
        return 1;
    }

    price = query_item_price(query_store_type(),ob);
    tmp = explode(price," ");
    if(!price || price == "no item" || price == "no type" || sizeof(tmp) != 2)
    {
        tell_room(ETO,response+"Uh.. I think I forgot the price for that, try again later.");
        return 1;
    }

    if(!box->spend_tokens(tmp[1],to_int(tmp[0])))
    {
        tell_room(ETO,response+TPQCN+", you don't have enough tokens for that.",TP);
        tell_object(TP,response+"You don't have enough tokens.");
        tell_room(ETO,response+"You need "+tmp[0]+" "+tmp[1]+" tokens.");
        return 1;
    }

    ob = new(base_name(ob));

    enc = (int)ob->query_property("enchantment");
    while(enc < 0) {
        ob->remove_property("enchantment");
        ob->set_property("enchantment",enc * -1);
        enc = (int)ob->query_property("enchantment");
    }

    tell_room(ETO, response+"Here is your "+str+" for "+tmp[0]+" "+tmp[1]+" tokens.");
    tell_room(ETO, TOQCN+" hands "+TPQCN+" "+(string)ob->query_short()+".", TP);
    tell_object(TP, TOQCN+" hands you "+(string)ob->query_short()+".");

    if (ob->move(TP))
    {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(ETO, TPQCN+" drops "+(string)ob->query_short()+".", TP);
        ob->move(ETO);
    }
    return 1;
}

int __Show(string str) {
    object ob;
    string what, whom, cost,price,*tmp=({}), bonus_string;
    mapping tmpmap;
    int x, val;
    if (!str) {
        write("Try 'show <object>'.");
        return 1;
    }
    if(disabled(TP, ({"disabled", "unconscious"})) )
       return 1;
    if(disabled(TO, ({"disabled", "unconscious", "bound"})) ){
      write("Get real.");
       return 1;
    }
    if(sscanf(str, "%s to %s",what, whom) == 2)
        return 0;   // to allow normal "show something to someone" to work *Styx* 4/14/03

    tell_room(ETO, TPQCN+" asks the vendor to see a "+str+".", TP);
    if (!__Eco["storage object"])
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if (!(ob = present(str, __Eco["storage object"])) &&
        !(ob = parse_objects(__Eco["storage object"]))) {
        tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I don't have a "+str+" to show you.");
        return 1;
    }
    tell_object(TP,TOQCN+" shows you "+(string)ob->query_short()+".");
    tell_room(ETO, TOQCN+" shows "+TPQCN+" "+(string)ob->query_short()+".", TP);
    message("info", (string)ob->query_long(), TP);
// added to have vendor tell them the skillneeded per requests *Styx*  2/13/03
    if(ob->is_weapon())
    {
           if(ob->is_lrweapon())
           {
               tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this as a ranged weapon, you'll need to have the "+ob->query_weapon_prof()+" weapon proficiency feat.");
        }
           else tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^To use this well, you'll need to have the "+ob->query_weapon_prof()+" weapon proficiency feat.");

    }

    if(ob->is_armor())
    {
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^This particular piece of armor is classed as "+ob->query_type()+".");
       if(ob->query_armor_prof())
       {
           tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:%^RESET%^ You will need the "+ob->query_armor_prof()+ " armor proficiency in order to use it.%^RESET%^");
       }
       tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says: %^RESET%^it will fit on your "+implode((string *)ob->query_limbs(), ", ")+".%^RESET%^");
    }
    price = query_item_price(query_store_type(),ob);
    tmp = explode(price," ");
    if(!price || price == "no item" || price == "no type" || sizeof(tmp) != 2)
    {
        return 1;
    }
    tell_room(ETO,"%^MAGENTA%^"+TOQCN+" says:  %^RESET%^This item "+
    "will cost you "+tmp[0]+" "+tmp[1]+" tokens%^RESET%^.");

    if(mapp(tmpmap = ob->query_item_bonuses()))
    {
        tmp = keys(tmpmap);
        if(sizeof(tmp))
        {
            bonus_string = "I know that it will grant you ";
            for(x = 0;x < sizeof(tmp);x++)
            {
                val = to_int(tmpmap[tmp[x]]);
                if(!intp(val)) continue;
                bonus_string += val + " "+tmp[x];
                if(x == (sizeof(tmp)-1)) bonus_string += ".";
                else if(x == (sizeof(tmp) - 2)) bonus_string += ", and ";
                else if(x < sizeof(tmp) && sizeof(tmp) > 1) bonus_string += ", ";
            }
        }
    }

    if(objectp(TP))
    {
        if(stringp(bonus_string)) TO->force_me("whisper "+TPQN+" "+bonus_string);
        if(intp(x = ob->query_property("enchantment")))
        {
            if(x > 0)
            {
                bonus_string = "It is enchanted %^BOLD%^%^CYAN%^"+consolidate_number(x);
                if(x == 1) bonus_string += " time.";
                else bonus_string += " times.";
                TO->force_me("whisper "+TPQN+" "+bonus_string);
            }
        }
    }

    return 1;
}


int __List(string str) {
    object *inv;
    string *tmp,price,*num=({});
    int i, x,j;
    if(disabled(TP, ({"disabled", "unconscious"})) )
       return 1;
    fill_storage_room();
    tell_room(ETO, TPQCN+" looks over the shop's inventory and price list.", TP);
    while (!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]), "filter_list", TO, str));
    if (!i) {
//__Eco["storage object"]->reset();
        i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]),"filter_list", TO, str));
        if (!i) {
            tell_room(ETO, "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^I have nothing on hand.");
            return 1;
        }
    }
    inv = sort_array(inv,"sort_items",TO);
    write("%^YELLOW%^ Description                        Cost                   Type");
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    for (x=0, tmp = ({}); x<i; x++) {
        price = query_item_price(query_store_type(),inv[x]);
        num = explode(price," ");
        if(!price || price == "no item" || price == "no type" || sizeof(num) != 2) { continue; }
        j = strlen("/daemon/filters_d.c"->filter_colors(inv[x]->query_short()));
        j = 39 - j;
        if (inv[x]->is_armour() || inv[x]->is_weapon()) {
            tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%-20s %-5s",
                        inv[x]->query_short()+""+arrange_string(" ",j),to_int(num[0]),num[1]+" tokens", types(inv[x]) ? types(inv[x]) : "")});
        } else {
            tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%s",
                inv[x]->query_short()+""+arrange_string(" ",j),to_int(num[0]),num[1]+" tokens") });
        }
        if (( ( x%17 ) == 0 ) && ( x > 15 ) ) {
            tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
            if (x == 17) tmp += ({" "});

            tmp += ({"%^YELLOW%^ Description                     Cost           Type"});
            tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
        }
    }
    tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
    TP->more(tmp);
    return 1;
}


int __Value(string str) {
    object ob;
    string tmp, cn, response;
    int value;

    if (!str) {
        write("Try 'value <object>'.");
        return 1;
    }
    if(disabled(TP, ({"disabled", "unconscious"})) )
       return 1;
    if(disabled(TO, ({"unconscious", "disabled"})) ){
      write("Do you really expect an unconscious person to give you an appraisal?");
       return 1;
    }
    tell_room(ETO,response+"We don't buy anything here.");
    return 1;
}
