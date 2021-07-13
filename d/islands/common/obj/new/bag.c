#include <std.h>
inherit "/d/common/obj/misc/sack.c";

void create()
{
    ::create();
    set_id(({ "bag", "sack", "bag of holding" }));
    set_name("bag");
    set_short("%^BLUE%^Bag of permanent holding%^RESET%^");
    set_obvious_short("%^BLUE%^%^BOLD%^A blue bag decorated with %^YELLOW%^r%^WHITE%^u%^YELLOW%^nes%^RESET%^");
    set_weight(5);
    set_long((: TO, "long_desc" :));

    set_lore("%^WHITE%^%^BOLD%^The great archmage Arkhiesan Korr is claimed to have been the first to have "
             "found the means by which to make a bag of holding permanent.  Part of the original Brotherhood of the Sixteen "
             "Sigils, he continued his research in secret after their group was disbanded.  His completed research, "
             "however, was never found or disclosed, as very shortly after the discovery, he was reputed to have been eaten "
             "by a great red wyrm.%^RESET%^");

    set_property("lore difficulty", 14);
    set_value(100000);
    set_property("no animate", 1);
    set_max_internal_encumbrance(100);
}

string long_desc()
{
    return "%^WHITE%^%^BOLD%^This is a small bag that you can put things in, made of some unknown, but quite "
             "resiliant, %^BLUE%^cobalt-blue cloth%^WHITE%^.  Around the opening of the bag appear %^YELLOW%^orn%^WHITE%^a"
             "%^YELLOW%^te ru%^WHITE%^n%^YELLOW%^es%^WHITE%^ within the cloth, perhaps dyed there.  As you reach you notice "
             "there is a lot more space in here than a normal bag of this size.%^RESET%^\n";
}

string query_long(string str)
{
    string desc, tmp, * true_inv;
    object* inv;
    mapping myInv;
    int j, i;

    desc = long_desc();
    inv = all_inventory(TO);
    if (!sizeof(inv)) {
        return desc;
    }
    myInv = ([]);
    for (i = 0; i < sizeof(inv); i++) {
        if (inv[i]->is_disease()) {
            continue;
        }
        tmp = inv[i]->query_short();
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
    true_inv = sort_array(keys(myInv), (: strcmp("/daemon/filters_d.c"->filter_colors($1),"/daemon/filters_d.c"->filter_colors($2)) :));
    for (i = 0; i < sizeof(true_inv); i++) {
        j = 55 - strlen("/daemon/filters_d.c"->filter_colors(myInv[true_inv[i]]["short"]));
        desc += myInv[true_inv[i]]["short"] + arrange_string(" ", j) + myInv[true_inv[i]]["quantity"] + "\n";
    }

    return desc;
}

int isMagic()
{
    return 1;
}
