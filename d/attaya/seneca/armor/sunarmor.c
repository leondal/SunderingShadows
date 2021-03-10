#include <std.h>
inherit "/std/plate";
 void init() {
     ::init();
    add_action("curse","open");
   add_action("curse","drop");
   add_action("curse","sell");
    add_action("curse","drink");
   add_action("curse","offer");
   add_action("curse","hide");
   add_action("curse","cast");
   add_action("curse","rush");
   add_action("curse","charge");
   add_action("curse","give");
   add_action("curse","throw");
   add_action("curse","remove");
}
 
void create() {
    ::create();
    set_name("battle armor");
    set("id", ({ "battle armor of the midnight sun", "armour", "armour of the midnight sun","battle armor",
		"armor","midnight sun",
		"midnight" }) );
    set("short", "%^BLUE%^Battle armor of the Midnight Sun%^RESET%^");
    set_long("
    %^BLUE%^This is a thick iron cast body armor with polished edges and shiny etchings on a deep blue metallic field.  In the center of the breastplate is a round sphere surrounded by raised triangles symbolizing a star of darkness.
");
    set_weight(40);
    set("value", 2);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(8);
        set_property("enchantment",5);
        set_wear((:this_object(), "extra_wear":));
   set_remove("%^BOLD%^%^BLUE%^Your spirit is once again freed.");
}
int curse(string str){
   object targ;
    targ = this_player();
    if((object)TO->query_worn()==TP){
    tell_object(targ,"%^BOLD%^%^CYAN%^You are cursed!\n\n\n");
    tell_object(targ,"%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You are of no use to me alive.");
   return 1;
}
   return 0;
}
int extra_wear() {
    if((int)TP->query_level() < 25) {
    notify_fail("You are not ready for this armor.");
    return 0;
    }
   if((int)TP->query_alignment() < 3) {
    notify_fail("Intruder has no use of your worthless spirit.");
    return 0;
    }
    write("%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You shall do my bidding...  Or face my wrath..");
    return 1;
}
