#include <std.h>

#define COLORS ({"black","brown","gray"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_fur(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   obj->set_type("clothing");
   val = random(13);
   switch(val) {
      case 0..1:
         obj->set_long("These are a pair of fur boots that have been dyed"+
         " "+str+". The outside of the boots are the hide of some animal,"+
         " while the inside is lined with soft fur. They reach to just past"+
         " the ankle with a top lining that turns down to show the fur.");
         obj->set_limbs(({"left foot","right foot"}));
         obj->set_weight(1);
         obj->set_name("fur boots");
         obj->set_short("A pair of "+str+" fur boots");
         obj->set_id(({"boots","fur boots","pair of boots","pair of fur boots",""+str+" boots",""+str+" fur boots","pair of "+str+" fur boots","fur"}));
         break;
      case 2..3:
         obj->set_long("This is a nice "+str+" fur hat that fits snuggly"+
         " on the head. There are ear flaps that can be turned down to"+
         " help protect you from the wind. It is very warm.");
         obj->set_limbs(({"head"}));
         obj->set_weight(1);
         obj->set_name("fur hat");
         obj->set_short("A "+str+" fur hat");
         obj->set_id(({"hat","fur hat",""+str+" fur hat",""+str+" hat","fur"}));
         break;
      case 4..5:
         obj->set_long("This is a lovely fur vest that has been dyed "+str+"."+
         " It is a bit large and is obviously meant to be worn over layers"+
         " of other clothing. It laces up the front and looks as though it"+
         " would help keep you warm but allow your arms to be free.");
         obj->set_limbs(({"torso"}));
         obj->set_weight(2);
         obj->set_name("fur vest");
         obj->set_short("A "+str+" fur vest");
         obj->set_id(({"fur vest","vest",""+str+" fur vest",""+str+" vest","fur"}));
         break;
      case 6..8:
         obj->set_long("This is an elegant fur jacket that is of a very fine"+
         " quality. It has been dyed "+str+" and tailored to closely fit"+
         " your body. There is a collar around the neck that can be turned"+
         " up to help protect your neck if the wind is too chill.");
         obj->set_limbs(({"torso"}));
         obj->set_weight(3);
         obj->set_name("fur jacket");
         obj->set_short("A "+str+" fur jacket");
         obj->set_id(({"jacket","fur jacket",""+str+" fur jacket",""+str+" jacket","fur"}));
         break;
      case 9..12:
         obj->set_long("This is a warm fur coat that has been dyed "+str+"."+
         " The fur is quite soft and the inside of the coat has been lined"+
         " with "+str+" satin. This will keep you warm in the coldest of"+
         " climates.");
         obj->set_limbs(({"torso"}));
         obj->set_weight(5);
         obj->set_name("fur coat");
         obj->set_short("A "+str+" fur coat");
         obj->set_id(({"coat","fur coat",""+str+" fur coat",""+str+" coat","fur"}));
         break;
   }
   obj->set_value(val+1);
}
