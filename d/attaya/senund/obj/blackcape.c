#include <std.h>
inherit ARMOUR;
  int x; //moved here by Lujke, so that this variable is tracked, as that seemed to be the purpose

void create()
{
        ::create();
       x=1; //this line moved here by Lujke
        set_name("Black Cape");
        set_id(({"black cape","cape","Cape","Black Cape"}));
        set_short("%^BLUE%^Black cape%^RESET%^");
        set_long(
@BRUENOR
            This is a simple cape. It has an elaborate obsidian 
        skull-shaped clasp to connect it around ones neck.  It 
        is made from strands of black cloth woven together rather
        skillfully.  It seems rather resistant to average wear
        and tear.  The strength of the material is also a bit 
        surprising.

BRUENOR
        );
    set_weight(5);
    set_ac(0);
    set_value(300);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    set_property("enchantment",4);
}


int wearit() 
{
//   int x;  Lujke moved this variable to make it global, because it seemed to need to be tracked across different instances of wearit()
//   x=1;
   if(ALIGN->is_evil(ETO))
   {
     if((int)ETO->query_highest_level() < 20) 
     {    
         remove_property("enchantment");
         x = 2;
         tell_object(ETO,"The cape slips on and surrounds your form");
         tell_room(EETO,
             ETOQCN+" puts on a unimpressive looking cape.", ETO);
         return 0;
     }

     if((int)ETO->query_highest_level() > 19)
     {
         if(x == 2)
         {
           	set_property("enchantment",4);
           	x = 1;
         }
         tell_object(ETO,"%^BLUE%^"+
             "You clasp the cape around your neck and it begins waving "+
             "in the non-existent wind! You feel a tinge of power as you "+
             "put on the cape.");
         tell_room(EETO,
             "%^BLUE%^"+ETOQCN+" dons a simple black cape.",ETO);  
     }
   }
   else
   {
         tell_object(ETO,"You cannot manage to figure out how to get the "+
         "clasp to fasten.");
        return 0;
   }
    return 1;
}


int removeit() 
{

    if((int)ETO->query_highest_level() > 19)
    {
        tell_object(ETO,"%^BLUE%^"+
            "With only a little trouble you manage to unfasten the "+
            "clasp on the cape and take it off.");
        tell_room(EETO,
            "%^BLUE%^"+ETOQCN+" takes off their cape.",ETO);
    }
    return 1;
}
