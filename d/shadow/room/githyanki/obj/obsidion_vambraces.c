
#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create() {
    ::create();
    set_id(({"vambraces","obsidian vambraces","Menagra's Guard", "bracers"}));
    set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^obsi%^RESET%^"+
"%^WHITE%^d%^RESET%^%^BOLD%^%^BLACK%^ian va%^RESET%^%^WHITE%^m"+
"%^RESET%^%^BOLD%^%^BLACK%^braces%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^M%^RESET%^%^WHITE%^e"+
"%^RESET%^%^BOLD%^%^BLACK%^n%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^"+
"%^BOLD%^%^BLACK%^gra's G%^RESET%^%^WHITE%^u%^RESET%^%^BOLD%^"+
"%^BLACK%^ard Va%^RESET%^%^WHITE%^m%^RESET%^%^BOLD%^%^BLACK%^"+
"brac%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^s%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^Formed from what looks"+
" like obsidian, on closer inspection these vambraces have been"+
" created from a dark glassy material that is %^RESET%^%^WHITE%^"+
"cloudy%^RESET%^%^BOLD%^%^BLACK%^. It almost looks like the "+
"%^RESET%^%^WHITE%^lig%^RESET%^%^BOLD%^%^WHITE%^h%^RESET%^%^WHITE%^"+
"ter color s%^RESET%^%^BOLD%^%^WHITE%^w%^RESET%^%^WHITE%^irls "+
"%^RESET%^%^BOLD%^%^BLACK%^just under the surface constantly. "+
"The vambraces attach to the lower arm with a single %^RESET%^"+
"%^ORANGE%^wide lea%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^"+
"her str%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^p %^RESET%^"+
"%^BOLD%^%^BLACK%^with iron buckles.%^RESET%^");
    set_property("enchantment",3);
    set_struck((:TO, "strike_func" :) );
    set_wield((:TO,"wear_func":));
    set_unwield((:TO,"unwear_func":));
    set_property("lore difficulty",15);
    set_lore("%^RESET%^%^RED%^The demi god Menagra was a lesser "+
"evil deity who named himself 'the lord of the banished', for "+
"collecting spirits, demons, and outsiders who had no force to "+
"follow. Menagra made many promises to a collection of powers "+
"known as the lords of Belkar which he reneged on. It is not known"+
" what happened after that, but Menagra's scattered followers found"+
" thier power drained shortly afterwards. Menagra's Guard was one "+
"of the last gifts given by Menagra to a promising general, a Tiefling"+
" named Dolkalak. %^RESET%^");
    set_value(3000);

}

int is_metal() { return 0; }

int wear_func(){
    tell_room(EETO,"%^RESET%^%^BOLD%^%^BLACK%^There is an audible "+
"sigh from somewhere as "+ETOQCN+"%^BLACK%^%^BOLD%^ ties on the "+
"vambraces%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You sense a legion of lost "+
"souls trapped in the vambraces as you slip them on%^RESET%^");
    return 1;
}

int remove_func(){
    tell_room(EETO,"%^RESET%^%^BOLD%^%^BLACK%^There is an audible"+
" sigh from somewhere as "+ETOQCN+" removes the vambraces%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You hear a thousand whispers"+
" fade as you remove the vambraces%^RESET%^");
    return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 100){
        tell_room(EETO,"%^BLACK%^%^BOLD%^Spirits and ghosts pour out"+
" of "+ETOQCN+"%^BLACK%^%^BOLD%^'s vambraces, enveloping "+who->QCN+"%^RESET%^"+
"%^BOLD%^.");
        tell_object(who,"%^BLACK%^%^BOLD%^The ghosts from "+ETOQCN+"'s "+
"vambraces envelop you!");
                who->set_paralyzed(random(2)+ 1);
       }
}