//Added lore - Cythera 4/05
//Changed to use inherits & clean up code - Cythera 2/07
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/quarter_staff.c";
void create()
{
        ::create();
        set_name("dryad staff");
        set_id(({"staff","dryad staff","wooden staff"}));
        set_obvious_short("A wooden staff");
        set_short("%^RESET%^%^GREEN%^D%^BOLD%^r%^RESET%^%^ORANGE%^y"+
          "%^GREEN%^a%^BOLD%^d%^RESET%^%^GREEN%^'%^BOLD%^s %^GREEN%^Staff");
        set_obvious_short("A wooden staff");
        set_long(
        "%^GREEN%^This staff has been carefully carved"+
        " from the limb of some type of tree. It has been well"+
        " worn with love and care and is warm to your touch. The"+
        " wood itself is of multiple colors, ranging from an"+
        " %^RESET%^ashen white%^GREEN%^ to a "+
        "%^ORANGE%^dark walnut%^GREEN%^ shade. The colors blend"+
        " together smoothly and seem to almost be moving in some"+
        " sort of pattern.%^RESET%^\n"
        );
        set_size(2 + random(2));
        set_value(2500);
        //set_wc(1,8);
        //set_large_wc(1,10);
        //set_type("bludgeoning");
        //set_prof_type("staff");
        set_property("enchantment", 2 + random(2));
        set_wield((:TO,"wieldme":));
        set_unwield((:TO,"removeme":));
        set_hit((:TO,"hitme":));
        set_lore("The gentle and fair dryads have been force to"+
                " arm themselves to protect the valley they love "+
                "from the threats that surround it.  Thus came the "+
                "creations of the staves they wield which have been "+
                "dubbed the Dryad Staff.  Crafted with fey magic from"+
                " fallen branches they find in the valley, the dryads"+
                " infuse the essence of nature into their staves.  "+
                "Some claim they have seen the dryads call nature to "+
                "their aid as they fight with these staves.  Though "+
                "it is rumored that one must posses a devoted mind to"+
                " the gods to utilize the true power of the staff.");
        set_property("lore",9);
}

int wieldme()
{
    if (!ETO->query_property("silent_wield")) {
        if (ETO->is_class("cleric")) {
            tell_object(ETO, "%^BOLD%^%^GREEN%^You sense a power within the" +
                " staff.");
        }
        else {
            tell_object(ETO, "%^GREEN%^The staff feels pleasantly cool to your" +
                " touch.");
        }
    }
    return 1;
}

int removeme()
{
    if (!ETO->query_property("silent_wield")) {
        if (ETO->is_class("cleric")) {
            tell_object(ETO, "%^BOLD%^%^GREEN%^You sigh and set the staff to the" +
                " side for now.");
            tell_room(ETO, "%^BOLD%^%^GREN%^" + ETO->QCN + " sighs deeply.", ETO);
        }
    }
    return 1;
}

int hitme(object targ)
{
        int MAX, SET, place;

        if(!objectp(targ)) return 1;

        MAX = ETO->query_max_hp();
        SET = ETO->query_hp();
        place = environment(query_wielded());

        if(ETO->query_level() < 11 || !ETO->is_class("cleric")) {
                if(!random(10)) {
                        tell_object(ETO,"%^BOLD%^You strike "+targ->QCN+""+
                        " with great force.");
                        tell_object(targ,"%^BOLD%^"+ETO->QCN+" strikes"+
                        " you with great force.");
                        tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
                        " strikes "+targ->QCN+" with great force.",({ETO,targ}));
                        targ->do_damage("torso",random(5)+3);
                        return 1;
                }
                if(!random(20)) {
                        tell_object(ETO,"%^ORANGE%^You wack "+targ->QCN+""+
                        " strongly in the head with your staff.");
                        tell_object(targ,"%^ORANGE%^Your head rings as "+ETO->QCN+""+
                        " wacks you in the head with "+ETO->QP+""+
                        " staff.");
                        tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+""+
                        " wacks "+targ->QCN+" in the head with"+
                        " "+ETO->QP+" staff.",({ETO,targ}));
                        targ->do_damage("torso",random(6)+4);
                        return 1;
                }
        }
        else {
                if(!random(10)) {
                        tell_object(ETO,"%^BOLD%^%^GREEN%^You swing your staff with ease,"+
                        " slamming it into "+targ->QCN+"'s chest.");
                        tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" slams"+
                        " "+ETO->QP+" hard into your chest,"+
                        " knocking the wind out of you.");
                        tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
                        " slams "+ETO->QP+" staff hard into"+
                        " "+targ->QCN+"'s chest, knocking the"+
                        " wind out of "+targ->QO+".",({ETO,targ}));
                        targ->do_damage("torso",random(8)+3);
                        return 1;
                }
                if(!random(20)) {
                        tell_object(ETO,"%^BOLD%^%^CYAN%^Your staff glows blue"+
                        " as you strike "+targ->QCN+".");
                        tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s"+
                        " staff glows blue as "+ETO->QS+" strikes"+
                        " you and you feel as though you've been struck by the"+
                        " force of a tidal wave!");
                        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s"+
                        " staff glows blue as it strikes "+targ->QCN+".",({ETO,targ}));
                        targ->do_damage("torso",random(9)+8);
                        return 1;
                }
                if(SET < MAX/2) {
                        if(!random(30)) {
                                tell_object(ETO,"%^YELLOW%^The staff glows a golden color and"+
                                " you feel warm and happy.");
                                tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s"+
                                " staff glows with a golden light and "+ETO->QS+""+
                                " smiles.",ETO);
                                ETO->do_damage("torso",-(random(10)+15));
                                return 1;
                        }
                }
                if(!place->query_property("indoors")) {
                        if(!random(40)) {
                                tell_object(ETO,"%^GREEN%^The staff glows"+
                                " with a green light and nearby vines and weeds"+
                                " rise up to entangle "+targ->QCN+".");
                                tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+"'s"+
                                " staff glows green and nearby vegitation rises up"+
                                " and entangles "+targ->QCN+"!",({ETO,targ}));
                               if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
                                        tell_object(targ,"%^GREEN%^"+ETO->QCN+"'s"+
                                        " staff glows green and nearby vegitation rises"+
                                        " up to entangle you, snaking around your throat"+
                                        " to cut off your air!");
                                        targ->do_damage("torso",random(10)+15);
                                        targ->set_paralyzed(20,"%^GREEN%^You are entangled by vines"+
                                        " and cannot move!");
                                        return 1;
                                }
                                else {
                                        tell_object(targ,"%^GREEN%^"+ETO->QCN+"'s"+
                                        " staff glows green and nearby vegitation rises"+
                                        " up to entangle you!");
						    targ->do_damage("torso",random(10)+5);
                                        targ->set_paralyzed(10,"%^GREEN%^You are entangled by vines"+
                                        " and cannot move!");
                                        return 1;
                                }
                        }
                }
        }
}
