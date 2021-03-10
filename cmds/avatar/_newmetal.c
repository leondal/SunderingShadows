#include <std.h>
#include <materials.h>

inherit DAEMON;

void make_newmetal(string type, int quality, int quantity)
{
    object obj;

    obj = new("/std/obj/metal.c");

    if(type && type != "random")            { obj->set_metal_type(type); }
    if(type && type == "random")            { obj->set_metal_type(METAL_TYPES[random(sizeof(METAL_TYPES))]); }
    obj->set_metal_quality(quality); 
    obj->set_metal_quantity(quantity); 

    obj->move(TP);
    write("Done.\n");
    return;
}

void cmd_newmetal(string str) 
{
    object obj;
    string type;
    int quality,quantity;

    if(!str) 
    { 
        obj = new("/std/obj/metal.c"); 
        obj->move(TP); 
        write("Done.\n"); 
        return 1; 
    }

    if(sscanf(str,"%s %d %d",type,quality,quantity) == 3) {}
    else if(sscanf(str,"%s %d",type,quality) == 2) {}
    else if(sscanf(str,"%s",type) == 1) {}
    
    if(type != "random")
    {
        if(member_array(type, METAL_TYPES) == -1)
        {
        write("You must enter a valid metal type or 'random'.\n");
        return 1;
        }
    }
           
    if(type && !quality && !quantity)
    {
        make_newmetal(type,random(10)+1,random(10)+1);
        return 1;
    }
    if(type && quality && !quantity)
    {
        make_newmetal(type,quality,random(10)+1);
        return 1;
    }
    if(type && quality && quantity)
    {
        make_newmetal(type,quality,quantity);
        return 1;
    }
    return 1;
}


int help()
{
   write(
@ARES
    syntax: newmetal <type> <quality> <quantity>

    This command allows the creation of a new metal of the type,
    quality, and quantity desired.  If type is not included a random
    metal will be made.  Quality and quantity may also be specified 
    as random by leaving them blank.

    Examples: newmetal              - all three fields are random
              newmetal random, 10   - quantity and type are random
              newmetal gold         - quality and quantity are random
    
    Quality 1 = lowest, 10 = highest

    List of metals: titanium, iron, steel, bronze, copper, mithril,
                    gold, platinum, electrum, adamantium, silver
ARES
    );
    return 1;
}

