//Updated to inherit standard two-handed sword - Octothorpe 7/15/09
//updated to current code by Circe 12/24/03 in response to 
//bug reports about its healing breaking stoneskin
#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit "/d/common/obj/weapon/two_hand_sword.c";
void create() {
    ::create();
    set_name("tyrelk");
    set_id(({"sword","two handed sword","sword of tyrelk","tyrelk",
            "tyrelk sword"}));
    set_obvious_short("two-handed sword");
    set_short("%^RED%^sword of Ty'relk%^RESET%^");
    set_long(
            "This is an ornate Two handed sword. Its hilt and pommel are decorated with what "
            "look to be ancient runes. There is a breath taking level of detail to the decorations "
            "and runes inset in the sword. The six foot long blade shines as if polished with care "
            "and diligence."
            );
    set_lore(
        "%^RED%^%^BOLD%^The sword of Ty'relk is a weapon lost ages ago "
        "when the people of Shanarie were vanquished in the undead "
        "wars. It is a two-handed sword of breathtaking detail and is "
        "covered in glowing red runes.%^RESET%^"
       );
    //set_weight(10);
    set_value(250);
    //set_wc(1,10);
    //set_large_wc(1,18);
    //set_size(3);
    //set_prof_type("tyrelk");
    //set_prof_level(26);
    //set_type("slashing");
    set_property("enchantment",2);
    set_hit((:TO, "extra_hit":));
    set_wield((:TO, "extra_wield":));
}

int extra_hit(object ob) {
    int dam;
    dam = random(2) + 1;
    if(random(3) < 1) return 0;
    if(!objectp(ob)) return 0;
    set_property("magic",1);
    tell_object(ETO,"%^RED%^The sword glows brightly and you feel refreshed as the "+
            "sword smites your foe!%^RESET%^");
    tell_room(environment(ETO),"%^RED%^The sword wielded by "+ETOQCN+" glows brightly as it smites "+
            ""+ob->query_cap_name()+"'s flesh!%^RESET%^",(({ETO, ob})));
    tell_object(ob,"%^RED%^The sword wielded by "+ETO->query_cap_name()+" glows as it smites "+
            "you!%^RESET%^");
    ETO->do_damage("torso",(-1)*(dam));
    ob->do_damage("torso",(dam));
    remove_property("magic");
    return 1;
}
int extra_wield() {
    if((int)ETO->query_level() < 12) {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }
    if((string)ETO->query_name() == "knight")return 1;
    tell_object(ETO,"%^RED%^You wield the sword, and it begins to "+
         "glow!%^RESET%^");
    tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" wields a glowing sword.%^RESET%^",ETO);
    return 1;
}

