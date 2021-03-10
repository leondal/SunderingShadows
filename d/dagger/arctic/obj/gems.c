#include <std.h>
#include "../arctic.h"

inherit OBJECT;

void create()
{
    int i,j, val;
    string *gems,str;

    gems = ({"bloodstone","diamond","sapphire","emerald",
             "citrine","jasper","moonstone","onyx","azurite",
             "fire opal","quartz","malchite","zircon",
             "opal","alexandrite","amethyst","aquamarine","chrysoberyl",
             "coral","garnet","jade","pearl","red spinel","blue spinel",
             "topaz","ruby"});

    ::create();
    j=random(sizeof(gems));
    str= gems[j];
    val = random(600);
    switch(val) 
    {
    case 0..200:
        set_long("This is a small "+str+". The light catches"+
            " in the gem and it looks like it would sell for a"+
            " nice price.");
        set_short("Small "+str+"");
        break;
    case 201..400:
        set_long("This is a "+str+" of a nice size. From the"+
            " way the light catches within the gem, it could"+
            " probably be sold for a fair sum.");
        set_short("Medium "+str+"");
        break;
    case 401..600:
        set_long("This is a fairly nice sized "+str+". The"+
            " light twinkles within the gem very prettily and"+
            " it is obviously worth a fair bit of gold.");
            set_short("Large "+str+"");
            break;
    }
    if(val < 50) 
    {
        set_value(50);
    }
    else 
    {
    set_value(val);
    }
    set_id(({"gem",str}));
    set_name("gem");
    set_weight(5);
}

int is_gem() {return 1;}
