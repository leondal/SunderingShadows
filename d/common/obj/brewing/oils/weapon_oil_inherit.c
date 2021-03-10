//all oils used to enhance weapons should go off of this inherit to keep from having stacking bonuses.  -tsera

#include <std.h>
inherit OBJECT;

int reversed;

void create() {
    ::create();
    set_name("weapon oil");
    set_id(({"jar","liquid","oil","weapon oil"}));
    set_obvious_short("%^RESET%^A clear jar of liquid");
    set_short("%^RESET%^A clear jar of liquid");
    set_long("%^RESET%^%^BOLD%^This jar is nearly as large as a small human head.  It is a "
        "square shape with a narrow neck that tapers up to a corked top.%^RESET%^");
    set_weight(10);
    set_value(15000);
    reversed = 0;
}

void init() 
{
    ::init();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(living(ETO)) add_action("apply","apply");
}

int apply(string str, int x) 
{
    object target;
    if(!objectp(TO) || !objectp(ETO)) return 0;
    if(!stringp(str)) 
    {
        tell_object(ETO,"You must pick something to apply the oil to.");
        return 1;
    }
    str = replace_string(str,"to ","");

    if(!objectp(target=present(str,ETO))) {
        tell_object(ETO,"You aren't carrying a "+str+"");
        return 1;
    }
    if(!target->is_weapon() && x) {
        tell_object(ETO,"The magic of the oil will only work on a weapon.");
        return 1;
    }
    
    /*if(target->query_property("oiled")){
       target->remove_property("oiled");
       target->remove_property_value("added short",(string)target->query_property("added short string"));
    }*/

    return target;
}

void set_reversed(int mystatus) { reversed = mystatus; }