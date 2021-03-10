#include <std.h>
#include <materials.h>

inherit DAEMON;

void make_newwood(string type, int quality, int quantity)
{
    object obj;

    obj = new("/std/obj/wood.c");

    if(type && type != "random")            { obj->set_wood_type(type); }
    if(type && type == "random")            { obj->set_wood_type(WOOD_TYPES[random(sizeof(WOOD_TYPES))]); }
    obj->set_wood_quality(quality); 
    obj->set_wood_quantity(quantity); 

    obj->move(TP);
    write("Done.\n");
    return;
}

void cmd_newwood(string str) 
{
    object obj;
    string type;
    int i,quality,quantity;

    if(!str) 
    { 
        obj = new("/std/obj/wood.c"); 
        obj->move(TP); 
        write("Done.\n"); 
        return 1; 
    }

    if(sscanf(str,"%s %d %d",type,quality,quantity) == 3) {}
    else if(sscanf(str,"%s %d",type,quality) == 2) {}
    else if(sscanf(str,"%s",type) == 1) {}
   
    if(type == "wood?")
    {   
        for(i=0;i<sizeof(WOOD_TYPES);i++)
        {
            if(!i) { write("Listing valid wood types:  %^CYAN%^"+WOOD_TYPES[i]+"%^RESET%^"); }
            else if(i) { write("                           %^CYAN%^"+WOOD_TYPES[i]+"%^RESET%^"); }
            if(1>1000) { error("loop"); break; }
        }
        return 1;
    } 

    if(type != "random")
    {
        if(member_array(type, WOOD_TYPES) == -1)
        {
        write("You must enter a valid wood type or 'random'.\n");
        return 1;
        }
    }
           
    if(type && !quality && !quantity)
    {
        make_newwood(type,random(10)+1,random(10)+1);
        return 1;
    }
    if(type && quality && !quantity)
    {
        make_newwood(type,quality,random(10)+1);
        return 1;
    }
    if(type && quality && quantity)
    {
        make_newwood(type,quality,quantity);
        return 1;
    }
    return 1;
}


int help()
{
   write(
@ARES
    syntax: newwood <type> <quality> <quantity>

    This command allows the creation of a new wood of the type,
    quality, and quantity desired.  If type is not included a random
    wood will be made.  Quality and quantity may also be specified 
    as random by leaving them blank. newwood wood? can be used 
    for a list of valid wood types.

    Examples: newwood               - all three fields are random
              newwood random, 10    - quantity and type are random
              newwood oak           - quality and quantity are random
              newwood wood?         - lists valid types of wood
    
    Quality 1 = lowest, 10 = highest

ARES
    );
    return 1;
}

