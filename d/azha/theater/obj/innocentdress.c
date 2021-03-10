#include <std.h>
inherit "/std/armour";

void create(){
        ::create();
        set_name("innocent dress");
        set_id(({ "dress", "innocent dress","silk dress"}));
        set_short("%^BOLD%^%^CYAN%^Dress of %^RESET%^%^MAGENTA%^I%^BOLD%^%^CYAN%^n%^RESET%^%^MAGENTA%^n"+
"%^BOLD%^%^CYAN%^o%^RESET%^%^MAGENTA%^c%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^n%^BOLD%^%^CYAN%^c"+
"%^MAGENTA%^e %^RESET%^");
        set_obvious_short("%^BOLD%^%^CYAN%^A flowing silk %^RESET%^%^MAGENTA%^d%^BOLD%^%^CYAN%^"+
"r%^RESET%^%^MAGENTA%^e%^BOLD%^%^CYAN%^s%^RESET%^%^MAGENTA%^s %^RESET%^");
        set_long( "%^CYAN%^Crafted from lightweight silk this dress flows freely.  The bodice of the dress"+
" fits close to the body, but not to tight.  The smooth neckline fits flush with a lady's body, but not too"+
" tight.  From the hips the dress flares out to create a two tiered skirt.  The full skirt falls in gentle"+
" folds as it flares out.  A weighted chain is hidden in each tier of the dress, keeping the layers flowing"+
" smoothly.  The silk fabric has been dyed a %^BOLD%^bright soft blue%^RESET%^ %^CYAN%^color that gradates "+
"down to a %^MAGENTA%^light lavender shade%^CYAN%^.%^RESET%^");
        set_weight(4);
        set_value(700);
        set_lore( "What is known of Ixi Desterl's opera Hivetta's Harmony, is that it seemed to center around"+
" the life of young Hivetta.  The omens around Hivetta's birth destined her to become the savior of her "+
"village.  The townspeople worked together to create a dress for the young heroine that would protect her."+
"  The dress was suppose to bring out Hivetta's innocence as well as being enchanted to grow as the girl "+
"did.  Though how Hivetta's life played out in this opera is lost to time, because of the strange happening"+
" at The Desert Sun the night of it's premiere. - The Desert Sun: The Rising and Setting of a Legacy - Aisha Mydrid");
        set_property("lore difficulty",14);
        set_type("clothing");
        set_limbs(({ "torso" }));
        set_size(random(2)+1);
        set_property("enchantment",2);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
void init()
{
::init();
        add_action("smile","smile");
}
        int wear_func(){
if((string)ETO->query_gender() == "male") {
                tell_object(ETO,"%^BOLD%^%^CYAN%^You rip the dress to shreds"+
		    "as you try to squeeze into it.");
                tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
                " rips the dress to shreads as he tries to squeeze into it.",ETO);
		    TO->remove();
                return 0;
			}
        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" looks innocent and demure as she smooths"+
" out her dress.",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^You feel innocent and demure as you smooth out the fine silk of this dress.");
        return 1;
}
int remove_func(){
tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" turns her back to remove her dress.  Shame on"+
" you for trying to peek!",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^You turn your back and remove your dress.  After all a lady never"+
" reveals too much.");
        return 1;
}
int smile(string str)
{
        if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }

        if(query_worn() && !str) {
                tell_object(ETO,"%^BOLD%^%^CYAN%^You smile %^RESET%^%^MAGENTA%^demurley%^BOLD%^%^CYAN%^.");
                tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" bats her eyes innocently as she"+
" smiles %^RESET%^%^MAGENTA%^demurely%^RESET%^.",ETO);
                return 1;
        }
}