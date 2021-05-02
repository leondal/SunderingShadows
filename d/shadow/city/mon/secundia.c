#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
   set_name("secundia");
   set_id( ({ "secundia", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("%^YELLOW%^Secundia, The Scriber of Scrolls%^RESET%^");
   set("aggressive", 0);
   set_level(19);
   set_long("%^BOLD%^%^BLACK%^Three mysterious sisters tend to the needs of the guild. The triplets are identical in nearly every way. Dark of skin, Secundia moves effortlessly within the shadows of this dim place, unseen and unheard. Her cropped hair enhances the sharp angles of her statuesque face, and she has a dark, penetrating gaze that could intimidate even the proudest of warriors. When together, the triplets mirror each other's movements and words, lending credit to the rumor that they are three bodies sharing one mind.%^RESET%^");
   set_gender("female");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room("/d/shadow/city/storage/ass_scroll_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_items_allowed("misc");
   set_max_hp(query_hp());
}



int __Buy(string str)
{
    object ob;
    string tmp;
    int cost, x, lvl;
    string cointype, * not_allowed, response;
    if (!objectp(TO)) {
        return 0;
    }
    if (!str) {
        write("Try 'buy <item> [#]'!");
        return 1;
    }
    not_allowed = ({ "bound", "disabled", "unconscious" });
    if (disabled(TP, not_allowed)) {
        return 1;
    }
    if (disabled(TO, not_allowed)) {
        write("Do you really expect someone who cannot move to sell you something?");
        return 1;
    }
    response = "%^MAGENTA%^" + TOQCN + " says:  %^RESET%^";
    if (!should_interact(TP)) {
        force_me("glare " + TPQN);
        force_me("say Leave my shop, scum, I will not serve you.");
        return 1;
    }
    if(!TP->is_class("assassin") && !avatarp(TP)) {
       tell_room(ETO, TPQCN+" seems to be trying to make a deal with "+TOQCN+".", TP);
       tell_room(ETO, ""+TOQCN+" says:  I do not deal with your kind and suggest you should leave now, before you are noticed.");
       return 1;
    }
    if (!__Eco["storage object"]) {
        __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }
    if (!(ob = present(str, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
        tell_room(ETO, TPQCN + " asks the shopkeeper about an item.", TP);
        tell_room(ETO, response + "I don't have any " + str + "s to sell you!");
        return 1;
    }
    cost = (int)ob->query_value();

    if (ob->query_property("enchanted")) {
        cost = cost * query_property("enchantment");
    }
    cost = adjust_cost(cost);
    cointype = (string)ob->query_cointype();
    if ((int)this_player()->query_money(cointype) < cost) {
        convert_money(cointype, cost);
        if ((int)this_player()->query_money(cointype) < cost) {
            tell_room(ETO, response + TPQCN + ", you don't have enough money for that!", TP);
            tell_object(TP, response + "You don't have enough money.");
            tell_room(ETO, response + "You need " + cost + " " + ob->query_cointype() + ".");
            return 1;
        }
    }
    if (ob->is_plate()) {
        if ((int)TP->query_level() < 1) {
            tell_room(ETO, TPQCN + " seems to be trying to buy a suit of full plate.", TP);
            tell_room(ETO, response + "It took far too much time to make such plate to sell it to someone as inexperienced as yourself!");
            return 1;
        } else {
            ob->check_plate(TP, ob);
            write("The armor is fitted to your body size and shape.");
            tell_room(ETO, "The clerk fits the armor to " + TPQCN + "'s height and weight.", TP);
        }
    }
    if (ob->is_factionitem()) {
        myfaction = ob->query_factionitem();
        factionofficials = "/daemon/save_area_lists_d.c"->query_jailer_names(myfaction);
        if (member_array(TPQN, factionofficials) == -1) {
            tell_room(ETO, response + "I'm sorry.  I can only sell that to officials of " + myfaction + ".");
            return 1;
        }else {
            ob->check_factionitem(TP, ob);
            tell_room(ETO, response + "Here you are...fitted just for you!");
        }
    }
//added the above faction stuff to allow for faction-specific
//items.  ~Circe~ 11/24/07
/*Below stuff about levelrestrict is set up to allow restriction of items to certain levels ~Circe~ 1/19/08*/
    if (ob->query_property("levelrestrict")) {
        lvl = ob->query_property("levelrestrict");
        if ((int)TP->query_lowest_level() < lvl) {
            tell_object(ETO, response + "I'm sorry.  You are not " +
                        "experienced enough to buy that yet.");
            return 1;
        }
    }
    tell_room(ETO, response + "Here is your " + str + " for " + cost + " " + ob->query_cointype() + "!");
    tell_room(ETO, TOQCN + " hands " + TPQCN + " " + (string)ob->query_short() + ".", TP);
    tell_object(TP, TOQCN + " hands you " + (string)ob->query_short() + ".");
    TP->add_money(ob->query_cointype(), -cost);
    if (ob->move(TP)) {
        tell_object(TP, "You drop it as fast as you get it!");
        tell_room(ETO, TPQCN + " drops " + (string)ob->query_short() + ".", TP);
        ob->move(ETO);
    }
    return 1;
}


