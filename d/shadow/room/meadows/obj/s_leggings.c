#include <std.h>

#define COLORS ({"light brown","light gray","dark brown","dark gray","dark black","black","gray","brown"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_leggings(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   obj->set_value(random(5)+10);
   obj->set_long("These leggings are made from wonderfully soft sheepskin."+
   " The outer part still has soft fur that has been dyed "+str+", while the"+
   " inside is smoothed sheepskin. They are great at keeping you warm.");
   obj->set_type("clothing");
   obj->set_limbs(({"right leg","left leg"}));
   obj->set_weight(2);
   obj->set_name("sheepskin leggings");
   obj->set_short(capitalize(str)+" sheepskin leggings");
   obj->set_id(({"leggings","sheepskin leggings","sheep skin leggings",""+str+" leggings",""+str+" sheepskin leggings"}));
}
