#include <std.h>
inherit LRWEAPON;

void create()
{
   ::create();
   set_name("long bow");
   set_short("A finely crafted long bow");
   set_id(({"bow","long bow","longbow","finely crafted long bow","fine long bow","fine longbow","finely crafted longbow","crafted long bow","crafted longbow","crafted bow","fine bow","finely crafted bow"}));
   set_long("This is a finely crafted long bow that has been carved from"+
   " the branch of a chestnut tree. It is both flexible and highly durable."+
   " It has been lovingly polished and varnished to help protect it from"+
   " the weather, as well as maintain the beauty of the dark wood.");
   set_weight(2);
   set_size(3);
   set_value(80);
   set_prof_type("staff");
   set_lr_prof_type("long bow");
   set_two_handed();
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("bludgeoning");
   set_rate_of_fire(2);
   set_range(7,15,21);
   set_ammo("longbow arrow");
   set_decay_rate(200);
}
