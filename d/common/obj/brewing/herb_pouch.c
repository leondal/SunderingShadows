//herb pouch for new Seneca ~Circe~ 6/3/08
// moved to general inherit for herbalism. N, 12/11.
#include <std.h>
#include <move.h>
inherit PARMOUR;

void create()
{
    ::create();
    set_name("herb pouch");
    set_short("%^RESET%^%^ORANGE%^leather herb pouch%^RESET%^");
    set_long("This pouch is designed to be worn on a belt at the " +
             "waist.  Upon looking inside, you see that what is a " +
             "simple design from the outside is actually a complicated " +
             "series of pouches and slots on the inside.  It looks as " +
             "though three hundred separate packets of herbs or other alchemical " +
             "additives could be held inside this one pouch.");
    set_id(({ "pouch", "leather pouch", "herb pouch", "leather herb pouch" }));
    //set_max_internal_encumbrance(300); //sextupling this 4/5/2020, Odin - removing encumbrance on herbs to be in line with components bags
    set_limbs(({ "waist" })); //was set to torso. 12 Dec 19, Uriel
    set_type("ring");
    set_weight(4);
    set_value(250);
    set_property("repairtype", ({ "leatherwork", "tailor" }));
    set_wear((: TO, "wear_fun" :));
}

int item_allowed(object item)
{
    if (item->is_herb()) {
        return 1;
    }
    write("This is meant for herbs and alchemical materials only.");
    return 0;
}

int wear_fun()
{
    object ob;
    int i = 1;
    string currently = "pouch";
    while (ob = present(currently, ETO)) {
        if ((base_name(ob) == "/d/common/obj/brewing/herb_pouch" || base_name(ob) == "/d/attaya/newseneca/obj/herb_pouch") && ob != TO && ob->query_worn()) {
            tell_object(ETO, "You can only fit one of those on your belt!");
            return 0;
        }
        i++;
        currently = "pouch " + i;
    }
    return 1;
}

string query_long(string str)
{
    string desc, tmp, * true_inv;
    object* inv;
    mapping myInv;
    int j, i;
    desc = ::query_long();
    inv = all_inventory(TO);
    if (!sizeof(inv)) {
        return desc;
    }
    myInv = ([]);
    for (i = 0; i < sizeof(inv); i++) {
        if (inv[i]->is_disease()) {
            continue;
        }
        tmp = (string)inv[i]->query_short();
        if (member_array(tmp, keys(myInv)) != -1) {
            myInv[tmp]["quantity"]++;
        }else {
            myInv += ([tmp:(["quantity" : 1, "short" : tmp]), ]);
        }
        continue;
    }

    if (!sizeof(keys(myInv))) {
        return desc;
    }
    if (stringp(desc)) {
        desc += arrange_string("It contains:", 50) + "Amount\n";
    }else {
        desc = "  It contains: \n";
    }
    true_inv = sort_array(keys(myInv), 1);
    for (i = 0; i < sizeof(true_inv); i++) {
        j = 55 - strlen("/daemon/filters_d.c"->filter_colors(myInv[true_inv[i]]["short"]));
        desc += myInv[true_inv[i]]["short"] + arrange_string(" ", j) + myInv[true_inv[i]]["quantity"] + "\n";
    }

    return desc;
}

int is_sortable_container()
{
    return 1;
}

void init()
{
    ::init(); //installed to update existing pouches
    set_wear((: TO, "wear_fun" :));
}
