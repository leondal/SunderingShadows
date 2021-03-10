#include <std.h>

#define COLORS ({"light brown","light gray","dark brown","dark gray","dark black","black","gray","brown"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_gloves(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   obj->set_value(random(3)+2);
   obj->set_long("These gloves are made from delicate sheepskin that has been"+
   " finely crafted and dyed "+str+". They are quite supple and conform"+
   " perfectly to your hands, helping to keep them warm but not hindering"+
   " you in any way.");
   obj->set_wear("You slip on the soft sheepskin gloves.");
   obj->set_type("clothing");
   obj->set_limbs(({"right arm","left arm"}));
   obj->set_weight(1);
   obj->set_name("sheepskin gloves");
   obj->set_short(capitalize(str)+" sheepskin gloves");
   obj->set_id(({"gloves","sheepskin gloves","sheep skin gloves",""+str+" gloves",""+str+" sheepskin gloves"}));
}
