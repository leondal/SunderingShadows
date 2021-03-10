#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

void create()
{
    ::create();
    set_nwp("forage", 10, 500);
    set_name("Deladrenia");
    set_short("Deladrenia, the herbalist");
    set_id(({ "Deladrenia", "deladrenia", "herbalist" }));
    set_long("Deladrenia wears a long, dark brown robe.  " +
             "The robe's hood lays pulled back, revealing an elderly " +
             "voadkyn woman.  Small bags hang from various loops " +
             "around the robe.  There is a slight smell of spices " +
             "that drifts from around her.");
    set_gender("female");
    set_race("voadkyn");
    set_body_type("human");
    set_hd(19, 2);
    set_alignment(7);
    set_max_hp(200 + random(50));
    set_hp(query_max_hp());
    set_level(19);
    set_overall_ac(0);
    set_class("ranger");
    set_mlevel("ranger", 19);
    set_hd(19, 2);
    set_exp(10);
    set_items_allowed("misc");
    set("aggressive", 0);
    set_storage_room(INC + "flowers");
    if (query_night() == 1) {
        set_emotes(5, ({
            "Deladrenia says:  %^CYAN%^I usually don't work much " +
            "after dark, but if you really need something, I'll " +
            "help you out, for a bit more of course.%^RESET%^",
            "Deladrenia looks very peaceful as she gazes across the lake.",
            "Deladrenia says:  %^CYAN%^If you come across any poison " +
            "glands from the ettercaps, bring them to me.  I can turn " +
            "them into potions."
        }), 0);
    }else {
        set_emotes(5, ({
            "Deladrenia says:  %^CYAN%^I can help you if you are " +
            "in need of any healing.%^RESET%^",
            "Deladrenia tends to her garden.",
            "Deladrenia says:  %^CYAN%^As you can see, I have " +
            "many beautiful flowers.  Would you like to buy any?.%^RESET%^",
            "Deladrenia says:  %^CYAN%^If you come across any poison " +
            "glands from the ettercaps, bring them to me.  I can turn " +
            "them into potions."
        }), 0);
    }
}

void receive_given_item(object obj)
{
    if (!objectp(obj)) {
        return;
    }
    if ((string)obj->query_name() == "%^RED%^an ettercap poison gland%^RESET%^") {
        force_me("say Thank you for bringing me the gland!  I know it " +
                 "is worth alot on the market, so in return I will give you " +
                 "a few vials of the antidote.");
        obj->remove();
        new("/d/common/obj/potion/cure_poison")->move(TP);
//    force_me("give potion to "+TPQN);
        new("/d/common/obj/potion/cure_poison")->move(TP);
//    force_me("give potion to "+TPQN);
        force_me("emoteat " + TPQN + " gives $N a few vials.");
//minor change by Circe - give was bugging with her. 2/14/04
        return;
    }
}
