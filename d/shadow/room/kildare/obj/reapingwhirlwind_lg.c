//Circe 7/7/04
#include <std.h>
inherit "/d/common/obj/weapon/two_hand_scythe";

void create(){
        ::create();
        set_name("greater reaping whirlwind");
        set_id(({"scythe","reaping whirlwind","whirlwind","greater reaping whirlwind","greater whirlwind"}));
        set_short("%^RESET%^%^CYAN%^Greater %^YELLOW%^Reaping "+
           "%^RESET%^%^CYAN%^Whirlwind%^RESET%^");
        set_obvious_short("A large iron scythe");
        set_long(
           "%^RESET%^%^CYAN%^This simple tool is made of an %^YELLOW%^"+
           "oaken handle %^RESET%^%^CYAN%^fitted with a long, curving "+
           "%^BOLD%^%^BLACK%^iron blade%^RESET%^%^CYAN%^.  The blade "+
           "is razor-sharp and ends with a piercing tip that strangely "+
           "looks as though it could be used to puncture armor.  Of "+
           "course, these implements are most often used to harvest "+
           "grain instead."
        );
        set_value(850);
        set_lore(
@CIRCE
The Reaping Whirlwind is named after an age-old legend 
of Drogheda that showed the futility of trying to outrun 
one's past.  No matter what you may do, you can never 
escape who you are...or what you have done.  The oppressive 
lord of Drogheda learned this lesson when his serfs revolted, 
killing him and taking his lands for themselves.  The 
community of Kildare Glen is said to have ties with these 
peasants.
CIRCE
        );
        set_property("lore difficulty",9);
        set_property("enchantment",1);
	set_item_bonus("attack bonus",1);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}
int wield_func(){
        tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" looks grim "+
           "as "+ETO->QS+" takes up the scythe.",ETO);
        tell_object(ETO,"%^RESET%^%^ORANGE%^A feeling of loss settles "+
           "upon you as you take up the scythe.%^RESET%^");
        return 1;
}
int unwield_func(){
        tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" seems to relax as "+
           ""+ETO->QS+" sets aside the scythe.",ETO);
        tell_object(ETO,"%^RESET%^%^ORANGE%^A great weight lifts from "+
           "your shoulders as you set aside the scythe.");
        return 1;
}
int hit_func(object targ){
        if(random(1000) < 250){
        tell_room(environment(query_wielded()),"%^CYAN%^"+ETOQCN+" "+
           "seems to move with the winds as "+ETO->QS+" strikes "+
           ""+targ->QCN+"!",({ETO,targ}));
        tell_object(ETO,"%^CYAN%^The winds pick up, guiding your "+
           "scythe as you strike "+targ->QCN+" quickly!");
        tell_object(targ,"%^CYAN%^You feel a great force driven "+
           "by a strong wind as "+ETOQCN+"'s scythe sinks into you!");
                return roll_dice(2,4)+2;        }
        else if(random(1000) > 900){
         set_property("magic",1);
         tell_room(environment(query_wielded()),"%^YELLOW%^"+
            ""+ETOQCN+"'s scythe pulses %^BLUE%^blue%^YELLOW%^, and "+
            ""+ETO->QS+" suddenly looks refreshed.",ETO);
         tell_object(ETO,"%^YELLOW%^Your scythe glows %^BLUE%^"+
            "blue,%^YELLOW%^ and you feel strength coursing through "+
            "your veins.");
         ETO->do_damage("torso",(-1)*(random(5)+1));
         remove_property("magic");
         return 1;
   }
   else return 0;
}
